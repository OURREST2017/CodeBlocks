#include "ranger.h"
#ifndef CODEBLOCK
#include "stm324x9i_REST_HWv2_hvac.h"
#endif // CODEBLOCK

int fan_delay = 0;//60*60*5;
int compressor_delay = 0;//30*1*1000;
int compressor_state;
int heating_state;
int compressor_off_time;

char buf[60];
float inside_temp;
float schedule_temp;
GUI_TIMER_HANDLE fan_timer;

void fanOff()
{
    if (strcmp(fanMode, "on") == 0) return;
    fan_control = 0;
#ifdef CODEBLOCK
    //GUI_ErrorOut("Fan Off");
#else
    BSP_HVAC_request_fan_G(HVAC_FUNCTION_RESET);
#endif // CODEBLOCK
}

void fanOn()
{
    fan_control = 1;
#ifdef CODEBLOCK
    //GUI_ErrorOut("Fan On");
#else
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
#ifdef CODEBLOCK
            //GUI_ErrorOut("AC On");
#else
            BSP_HVAC_request_cool_Y(HVAC_FUNCTION_SET);
#endif
            fanOn();
            cool_control = 1;
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
#ifdef CODEBLOCK
        //GUI_ErrorOut("AC Off");
#else
        BSP_HVAC_request_cool_Y(HVAC_FUNCTION_RESET);
#endif
        cool_control = 0;
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
#ifdef CODEBLOCK
            //GUI_ErrorOut("Heat On");
#else
            BSP_HVAC_request_heat_W(HVAC_FUNCTION_SET);
#endif // CODEBLOCK
            fanOn();
            heat_control = 1;
        }
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
#ifdef CODEBLOCK
        //GUI_ErrorOut("Heat Off");;
#else
        BSP_HVAC_request_heat_W(HVAC_FUNCTION_RESET);
#endif // CODEBLOCK
        heat_control = 0;
    }
    heating_state = 0;
}

float getScheduleTemp()
{
    if (strcmp(hvacMode, "cool") == 0)
    {
        return 72;
    }
    else
    {
        return 76;
    }
}

void hvacControlCode()
{
    sprintf(buf,"%s, %s",hvacMode, fanMode);
    //GUI_ErrorOut(buf);
    inside_temp = (float)insideTemp;
    schedule_temp = getScheduleTemp();
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
    else if (strcmp(hvacMode, "auto") == 0 )
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
    if (strcmp(fanMode, "auto") == 0 && !heat_control && !cool_control)
    {
        fanOff();
    }
}
