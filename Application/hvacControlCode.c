#include "ranger.h"
#ifndef CODEBLOCK
#include "stm324x9i_REST_HWv2_hvac.h"
#endif // CODEBLOCK

static int fan_delay = 0;//60*60*5;
static int compressor_delay = 0;//30*1*1000;
static int compressor_state;
static int heating_state;
static int compressor_off_time;

static char buf[60];
static float inside_temp;
static int schedule_temp;
static GUI_TIMER_HANDLE fan_timer;
extern WM_HWIN textDebug;
extern int  scheduleTempurature(char * tm, char *day);
extern WM_HWIN hvacHeat, hvacCool, hvacFan;

void fanOff()
{
    if (strcmp(fanMode, "on") == 0) return;
    fan_control = 0;
    WM_HideWindow(hvacFan);
    GUI_ErrorOut("FO");
#ifndef CODEBLOCK
    BSP_HVAC_request_fan_G(HVAC_FUNCTION_RESET);
#endif // CODEBLOCK
}

void fanOn()
{
    fan_control = 1;
    WM_ShowWindow(hvacFan);

#ifndef CODEBLOCK
    BSP_HVAC_request_fan_G(HVAC_FUNCTION_SET);
#endif // CODEBLOCK
}

static void fanTimer(GUI_TIMER_MESSAGE * pTM)
{
    fanOff();
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
        if (strcmp(fanMode, "auto") == 0)
        {
            fan_timer = GUI_TIMER_Create(fanTimer, fan_delay, 0, 0);
            GUI_TIMER_SetPeriod(fan_timer, fan_delay);
            GUI_TIMER_Restart(fan_timer);
        }
        compressor_off_time = GUI_GetTime();
#ifndef CODEBLOCK
        BSP_HVAC_request_cool_Y(HVAC_FUNCTION_RESET);
#endif
        cool_control = 0;
        WM_HideWindow(hvacCool);
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
        compressor_off_time = 0;
    }
}

void heatingOff()
{
    if (heating_state)
    {
        if (strcmp(fanMode, "auto") == 0)
        {
            fan_timer = GUI_TIMER_Create(fanTimer, fan_delay, 0, 0);
            GUI_TIMER_SetPeriod(fan_timer, fan_delay);
            GUI_TIMER_Restart(fan_timer);
        }
        compressor_off_time = GUI_GetTime();
#ifndef CODEBLOCK
        BSP_HVAC_request_heat_W(HVAC_FUNCTION_RESET);
#endif // CODEBLOCK
        heat_control = 0;
        WM_HideWindow(hvacHeat);
    }
    heating_state = 0;
}

static char * getTime()
{
    static char time_buf[10];
#ifdef CODEBLOCK
    time_t now = time(NULL);
    if (clockFormat == 24)
    {
        strftime(time_buf, 20, "%H:%M", localtime(&now));
    }
    else
    {
        strftime(time_buf, 20, "%I:%M%p", localtime(&now));
        strcpy(time_buf, tolow(time_buf));
    }
#else
    RTC_TimeTypeDef tm;
    BSP_RTC_GetTime(&tm);

    if (clockFormat == 24)
    {
        sprintf(time_buf, "%d:%02d", tm.Hours, tm.Minutes);
    }
    else
    {
        sprintf(time_buf, "%d:%02dpm", tm.Hours, tm.Minutes);
    }
#endif
    return time_buf;
}

void hvacControlCode()
{
    inside_temp = (float)insideTemp;

    if (holdMode)
    {
    	schedule_temp = scheduleTempurature(getTime(), currentSchedule);
        sprintf(buf,"%d, %s",schedule_temp, getTime());
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
        return;
    }

    if (strcmp(hvacMode, "cool") == 0)
    {
        if (inside_temp > (float)coolToDegrees)
        {
            compressorOn();
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
