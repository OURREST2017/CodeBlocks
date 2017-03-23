#include "ranger.h"
#ifndef CODEBLOCK
#include "stm324x9i_REST_HWv2_hvac.h"
#endif // CODEBLOCK

static int fan_delay = 0;//60*60*5;
static int compressor_delay = 0;//30*1*1000;
static int compressor_state;
static int heating_state;
static int compressor_off_time, heating_off_time;

static char buf[60];
static float inside_temp;
static int schedule_temp;
static GUI_TIMER_HANDLE fan_timer;
extern WM_HWIN textDebug;
extern int  scheduleTempurature(int tod, char *day);
extern WM_HWIN hvacHeat, hvacCool, hvacFan;

static void fanTimer(GUI_TIMER_MESSAGE * pTM)
{
    fan_control = 0;
    WM_HideWindow(hvacFan);
#ifndef CODEBLOCK
    BSP_HVAC_request_fan_G(HVAC_FUNCTION_RESET);
#endif // CODEBLOCK
}

void fanOff()
{
    if (strcmp(fanMode, "on") == 0) return;
    if (cool_control || heat_control) return;

    fan_timer = GUI_TIMER_Create(fanTimer, fan_delay, 0, 0);
    GUI_TIMER_SetPeriod(fan_timer, fan_delay);
    GUI_TIMER_Restart(fan_timer);
}

void fanOn()
{
    fan_control = 1;
    WM_ShowWindow(hvacFan);
#ifndef CODEBLOCK
    BSP_HVAC_request_fan_G(HVAC_FUNCTION_SET);
#endif // CODEBLOCK
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
#endif
            fanOn();
            cool_control = 1;
            WM_ShowWindow(hvacCool);
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
#endif
        cool_control = 0;
        WM_HideWindow(hvacCool);
        fanOff();
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
#endif // CODEBLOCK
            fanOn();
            heat_control = 1;
        }
        WM_ShowWindow(hvacHeat);
        heating_state = 1;
        heating_off_time = 0;
    }
}

void heatingOff()
{
    if (heating_state)
    {
        heating_off_time = GUI_GetTime();
#ifndef CODEBLOCK
        BSP_HVAC_request_heat_W(HVAC_FUNCTION_RESET);
#endif // CODEBLOCK
        heat_control = 0;
        WM_HideWindow(hvacHeat);
        fanOff();
    }
    heating_state = 0;
}

static int getTime()
{
#ifdef CODEBLOCK
    time_t now = time(NULL);
    struct tm *info;

    time( &now );
    info = localtime( &now );
    int h = info->tm_hour * 60 + info->tm_min;
#else
    RTC_TimeTypeDef tm;
    BSP_RTC_GetTime(&tm);
    int h = tm.Hours * 60 + tm.Minutes;;
#endif
    return h;
}

void hvacControlCode(int itemp, int ihum)
{
#ifdef DEBUG_MODE
    inside_temp = (float)insideTemp;
#else
    inside_temp = (float)itemp;
    insideTemp = itemp;
#endif

    if (!holdMode) {
        insideHumidity = ihum;
        sprintf(buf,"TM=%3d, H=%d, C=%d, F=%d", (GUI_GetTime()/1000),
                 heat_control, cool_control, fan_control);
        TEXT_SetText(textDebug, buf);
    }

    if (holdMode)
    {
        schedule_temp = scheduleTempurature(getTime(), currentSchedule);
        sprintf(buf,"ST=%d, IT=%d, TM=%d", schedule_temp, insideTemp, getTime());
        TEXT_SetText(textDebug, buf);
        if (inside_temp > (float)schedule_temp)
        {
            compressorOn();
        }
        else
        {
            compressorOff();
        }
        if (inside_temp < (float)schedule_temp)
        {
            heatingOn();
        }
        else
        {
            heatingOff();
        }
        if (strcmp(fanMode, "on") == 0)
        {
            fanOn();
        }
        return;
    }

    if (strcmp(hvacMode, "auto") == 0 )
    {
        if (inside_temp > (float)upperDegreeLimit)
        {
            compressorOn();
        }
        else
        {
            compressorOff();
        }
        if (inside_temp < (float)lowerDegreeLimit)
        {
            heatingOn();
        }
        else
        {
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
        return;
    }

    if (strcmp(hvacMode, "cool") == 0)
    {
        if (inside_temp > (float)coolToDegrees)
        {
            compressorOn();
            heatingOff();
       }
        else
        {
            compressorOff();
        }
    }
    else if (strcmp(hvacMode, "heat") == 0)
    {
        if (inside_temp < (float)heatToDegrees)
        {
            heatingOn();
            compressorOff();
        }
        else
        {
            heatingOff();
        }
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
