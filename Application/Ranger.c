#include "ranger.h"

#ifndef CODEBLOCK
#include "main.h"
#include "cmsis_os.h"
#include "calibration.h"
#include "stm324x9i_REST_HWv2_ts.h"

static void TS_Process(void const *n);
static void GUIThread(void const * argument);

osThreadDef(GUI_Thread, GUIThread, osPriorityNormal, 0, 4096);
osThreadId GUI_Thread_ThreadId;
osTimerId lcd_timer;

uint32_t GUI_FreeMem = 0;

static void lockTimer(GUI_TIMER_MESSAGE * pTM)
{
    CreateIdleWin();
}
static void GUIThread(void const * argument)
#else
static void lockTimer(GUI_TIMER_MESSAGE * pTM)
{
    CreateIdleWin();
}
void MainTask(void)
#endif
{
	GUI_Init();

#ifndef CODEBLOCK
    WM_MULTIBUF_Enable(1);
    RTC_TimeTypeDef tm;
    RTC_DateTypeDef dt;

    tm.Hours = 4;
    tm.Minutes = 43;
    tm.DayLightSaving = 1;
    tm.TimeFormat = 64;

    dt.Date = 9;
    dt.Month = 2;
    dt.Year = 17;
    dt.WeekDay = 4;

    BSP_RTC_SetTime(&tm);
    BSP_RTC_SetDate(&dt);

	/* Check for calibration */
    if (CalibrationIsDone() == 0)
    {
       CalibrationInit();
    }

#endif

    WM_SetCreateFlags(WM_CF_MEMDEV);
    color_scheme = 0;
    initColors();
    loadConfig();
    //saveConfig();
    holdMode = 0;

    if (testing)
    {
        state = 99;
    }
    else if (firstTime)
    {
         lockTimer_h = GUI_TIMER_Create(lockTimer, idleTimeOut, 0, 0);
       state = 2;
    }
    else
    {
        lockTimer_h = GUI_TIMER_Create(lockTimer, idleTimeOut, 0, 0);
        state = 1;
    }
    state = 1;
    int counter;
    while(1)
    {
        counter++;
        switch (state)
        {
        case 0:
            break;
        case 99:
           // CreateTriacPanelWin();
            state = 0;
            break;
        case 1:
            // GUI_Delay(100);
            GUI_TIMER_SetPeriod(lockTimer_h, idleTimeOut);
            GUI_TIMER_Restart(lockTimer_h);
            CreateHomeWin();
            state=0;
            break;
         case 2:
            GUI_TIMER_SetPeriod(lockTimer_h, 9999999);
            CreateLanguages();
            state=0;
            break;
       }
        GUI_Exec();
        GUI_Delay(40);
#ifdef CODEBLOCK
        if (counter++ > 100) {
            hvacControlCode();
            counter = 0;
        }
#endif

    }
}

#ifndef CODEBLOCK
void BSP_GUI_Init(void) {

GUI_Thread_ThreadId = osThreadCreate(osThread(GUI_Thread), NULL);
	/* TODO: add error check */

/* Create Touch screen Timer */
  osTimerDef(TS_Timer, TS_Process);
  lcd_timer =  osTimerCreate(osTimer(TS_Timer), osTimerPeriodic, (void *)0);
  /* Start the TS Timer */
  osTimerStart(lcd_timer, 40);
}

/* TODO: this needs to be interrupt based!!!!! */
static void TS_Process(void const *n)
{
	GUI_PID_STATE TS_State;
	static TS_StateTypeDef prev_state;
	__IO TS_StateTypeDef  ts;
	uint16_t xDiff, yDiff;

	BSP_TS_GetState((TS_StateTypeDef *)&ts);

	TS_State.Pressed = ts.TouchDetected;

	xDiff = (prev_state.x > ts.x) ? (prev_state.x - ts.x) : (ts.x - prev_state.x);
	yDiff = (prev_state.y > ts.y) ? (prev_state.y - ts.y) : (ts.y - prev_state.y);

	if((prev_state.TouchDetected != ts.TouchDetected ) || (xDiff > 3 ) || (yDiff > 3))
	{
		prev_state.TouchDetected = ts.TouchDetected;

		if((ts.x != 0) &&  (ts.y != 0))
		{
			prev_state.x = ts.x;
			prev_state.y = ts.y;
		}

		if(CalibrationIsDone())
		{
			TS_State.Layer = 0;
			TS_State.x = CalibrationGetX (prev_state.x);
			TS_State.y = CalibrationGetY (prev_state.y);
		}
		else
		{
			TS_State.Layer = 0;
			TS_State.x = prev_state.x;
			TS_State.y = prev_state.y;
		}

		GUI_TOUCH_StoreStateEx(&TS_State);
	}
}
#endif
