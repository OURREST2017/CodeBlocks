#include "ranger.h"
#ifndef CODEBLOCK
#include "stm324x9i_REST_HWv2_hvac.h"
#endif

static int fan_delay = 0;//60*60*5;
static int compressor_delay = 0;//30*1*1000;
static int compressor_state;
static int heating_state;
static int compressor_off_time, heating_off_time;

static char buf[60];
static GUI_TIMER_HANDLE fan_timer;

extern float scheduleTemperature(int tod, char *day, char *mode), hide_debug;
extern float sensor_temperature, sensor_humidity;

extern WM_HWIN hvacHeat, hvacCool, hvacFan, textDebug;

int comp_run_start = 0, blower_run_start = 0;

static void fanTimer(GUI_TIMER_MESSAGE * pTM)
{
    WM_HideWindow(hvacFan);
#ifndef CODEBLOCK
    BSP_HVAC_request_fan_G(HVAC_FUNCTION_RESET);
#endif

    int t =  GUI_GetTime() - blower_run_start;
    blowerLongestRuntime = GUI_MAX(blowerLongestRuntime, t);
    blowerShortestRuntime = GUI_MIN(blowerShortestRuntime, t);
    blowerTotalRuntime += t;
    blowerRunCount++;
}

void fanOff()
{
    if (strcmp(fanMode, "on") == 0) return;
    if (cool_control || heat_control) return;
    fan_control = 0;

    fan_timer = GUI_TIMER_Create(fanTimer, fan_delay, 0, 0);
}

void fanOn()
{
    fan_control = 1;
    if (!hide_debug) WM_ShowWindow(hvacFan);
#ifndef CODEBLOCK
    BSP_HVAC_request_fan_G(HVAC_FUNCTION_SET);
#endif
    blower_run_start = GUI_GetTime();
}

void compressorOn()
{
    int gui_time = GUI_GetTime();
    if ((gui_time - compressor_off_time) > compressor_delay || compressor_off_time == 0)
    {
        if (!compressor_state)
        {
#ifndef CODEBLOCK
            BSP_HVAC_request_cool_Y(HVAC_FUNCTION_SET);
            BSP_HVAC_request_xxx_O(HVAC_FUNCTION_SET);
#endif
            fanOn();
            cool_control = 1;
            if (!hide_debug) WM_ShowWindow(hvacCool);
            comp_run_start = gui_time;
        }
        compressor_state = 1;
        compressor_off_time = 0;
    }
}

void compressorOff()
{
    if (compressor_state)
    {
        compressor_off_time = GUI_GetTime();
#ifndef CODEBLOCK
        BSP_HVAC_request_cool_Y(HVAC_FUNCTION_RESET);
        BSP_HVAC_request_xxx_O(HVAC_FUNCTION_RESET);
#endif
        cool_control = 0;
        WM_HideWindow(hvacCool);
        fanOff();

        int t =  GUI_GetTime() - comp_run_start;
        compressorLongestRuntime = GUI_MAX(compressorLongestRuntime, t);
        compressorShortestRuntime = GUI_MIN(compressorShortestRuntime, t);
        compressorTotalRuntime += t;
        compressorRunCount++;
    }
    compressor_state = 0;
}

void heatingOn()
{
    int gui_time = GUI_GetTime();
    if ((gui_time - compressor_off_time) > compressor_delay || compressor_off_time == 0)
    {
        if (!heating_state)
        {
#ifndef CODEBLOCK
            BSP_HVAC_request_heat_W(HVAC_FUNCTION_SET);
            BSP_HVAC_request_xxx_B(HVAC_FUNCTION_SET);
#endif
            fanOn();
            heat_control = 1;
        }
        if (!hide_debug) WM_ShowWindow(hvacHeat);
        heating_state = 1;
        heating_off_time = 0;
        comp_run_start = gui_time;
    }
}

void heatingOff()
{
    if (heating_state)
    {
        heating_off_time = GUI_GetTime();
#ifndef CODEBLOCK
        BSP_HVAC_request_heat_W(HVAC_FUNCTION_RESET);
        BSP_HVAC_request_xxx_B(HVAC_FUNCTION_RESET);
#endif
        heat_control = 0;
        WM_HideWindow(hvacHeat);
        fanOff();

        int t =  GUI_GetTime() - comp_run_start;
        compressorLongestRuntime = GUI_MAX(compressorLongestRuntime, t);
        compressorShortestRuntime = GUI_MIN(compressorShortestRuntime, t);
        compressorTotalRuntime += t;
        compressorRunCount++;
    }
    heating_state = 0;
}

updateStats()
{
    if (getScheduleTime() >= 2358 && getScheduleTime() <= 2)
    {
        saveStats();

        tempHighOutside = 0;
        tempLowOutside = 999999;

        tempHighInside = 0;
        tempLowInside = 999999;

        tempHighSetPoint = 0;
        tempLowSetPoint = 999999;

        humidityHighOutside = 0;
        humidityLowOutside = 999999;

        humidityHighInside = 0;
        humidityLowInside = 999999;

        compressorTotalRuntime = 0;
        compressorLongestRuntime = 0;
        compressorShortestRuntime = 999999;
        compressorRunCount = 0;

        blowerTotalRuntime = 0;
        blowerLongestRuntime = 0;
        blowerShortestRuntime  = 999999;
        blowerRunCount = 0;
    }

    tempHighOutside = GUI_MAX(tempHighOutside, localTemperature);
    tempLowOutside = GUI_MIN(tempLowOutside, localTemperature);

    tempHighInside = GUI_MAX(tempHighInside, (int)insideTemperature);
    tempLowInside = GUI_MIN(tempLowInside, (int)insideTemperature);

    tempHighSetPoint = GUI_MAX(tempHighSetPoint, temperatureSetPoint);
    tempLowSetPoint = GUI_MIN(tempLowSetPoint, temperatureSetPoint);

    humidityHighOutside = GUI_MAX(humidityHighOutside, localHumidity);
    humidityLowOutside = GUI_MIN(humidityLowOutside, localHumidity);

    humidityHighInside = GUI_MAX(humidityHighInside, insideHumidity);
    humidityLowInside = GUI_MIN(humidityLowInside, insideHumidity);
}

void hvacControlCode()
{
    float inside_temp, schedule_temp;

    inside_temp = 1.8 * sensor_temperature + 32.;
    if (inside_temp - (int)inside_temp < .5) {
        inside_temp = (int)inside_temp;
    } else if (inside_temp - (int)inside_temp >= .5) {
        inside_temp = (float)((int)inside_temp) + .5;
    }
    insideHumidity = sensor_humidity;
    schedule_temp = scheduleTemperature(getScheduleTime(), currentSchedule, hvacMode);

    updateStats();

    if (holdMode)
    {
        float sp = temperatureSetPoint;

#ifdef DEBUG_MODE
        float inside = inside_temp;
        float spi = sp;
        float sinside = schedule_temp;

        if (metric)
        {
            inside = (inside_temp - 32.) * 5./9.;
            spi = (sp - 32.) * 5./9.;
            sinside = (schedule_temp - 32.) * 5./9.;
        }
        sprintf(buf,"ST=%2d.%02d\nIT=%2d.%02d",
                (int)sinside, (int)((sinside - (int)sinside) * 100),
                (int)inside,(int)((inside - (int)inside) * 100));
        TEXT_SetText(textDebug, buf);
#endif

        if (strcmp(hvacMode, "cool") == 0)
        {
            if (inside_temp > sp)
            {
                compressorOn();
                heatingOff();
            }
            else if (inside_temp <= sp)
            {
                compressorOff();
            }
        }
        else if (strcmp(hvacMode, "heat") == 0)
        {
            if (inside_temp < sp)
            {
                heatingOn();
                compressorOff();
            }
            else if (inside_temp >= sp)
            {
                heatingOff();
            }
        }
        insideTemperature = inside_temp;

        if (strcmp(fanMode, "on") == 0)
        {
            fanOn();
        }
        return;
    }
    else if (!holdMode)
    {
        float heat_to = heatToDegrees;
        float cool_to = coolToDegrees;


#ifdef DEBUG_MODE
        float inside = inside_temp;
        float sinside = schedule_temp;
        if (metric)
        {
            inside = (inside_temp - 32.) * 5./9.;
            sinside = (schedule_temp - 32.) * 5./9.;
        }
        sprintf(buf,"SC=%s\nST=%2d.%02d\nIT=%2d.%02d",
                currentSchedule,
                (int)sinside, (int)((sinside - (int)sinside) * 100),
                (int)inside, (int)((inside - (int)inside) * 100));
        TEXT_SetText(textDebug, buf);
#endif

        if (strcmp(hvacMode, "cool") == 0)
        {
            if (inside_temp - schedule_temp  >= 1.5)
            {
                compressorOn();
                heatingOff();
            }
            else if (inside_temp - schedule_temp <= 0)
            {
                compressorOff();
            }

            if (inside_temp - schedule_temp > 1.5 && cool_control)
            {
                insideTemperature = inside_temp;
            }
            else if (inside_temp < schedule_temp )
            {
                insideTemperature = inside_temp;
            }
            else if (insideTemperature > inside_temp )
            {
                insideTemperature = inside_temp;
            }
        }
        else if (strcmp(hvacMode, "heat") == 0)
        {
            if (schedule_temp - inside_temp >= 1.5)
            {
                compressorOff();
                heatingOn();
            }
            else if (schedule_temp - inside_temp <= 0)
            {
                heatingOff();
            }

            if (schedule_temp - inside_temp > 1.5 && heat_control)
            {
                insideTemperature = inside_temp;
            }

            if (inside_temp >= schedule_temp)
            {
                insideTemperature = inside_temp;
            }
//            if (schedule_temp - inside_temp <= 0)
//            {
//                insideTemperature = inside_temp;
//            }
//            else if (schedule_temp - inside_temp <= 1.5 )
//            {
//                insideTemperature = schedule_temp;
//            }
        }
        else if (strcmp(hvacMode, "auto") == 0)
        {
            if (inside_temp >= heat_to && inside_temp <= cool_to)
            {
                compressorOff();
                heatingOff();
            }
            else if (inside_temp < heat_to)
            {
                heatingOn();
                compressorOff();
                return;
            }
            else if (inside_temp > cool_to)
            {
                compressorOn();
                heatingOff();
            }
        }

        if (strcmp(fanMode, "on") == 0)
        {
            fanOn();
        }
        return;
    }
    else if (strcmp(hvacMode, "off") == 0)
    {
        compressorOff();
        heatingOff();
    }

    if (strcmp(fanMode, "on") == 0)
    {
        fanOn();
    }

    if (strcmp(fanMode, "auto") == 0 && !heat_control && !cool_control && fan_control)
    {
        fanOff();
    }
}
