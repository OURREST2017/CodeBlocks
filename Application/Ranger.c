#include "ranger.h"

#ifndef CODEBLOCK
#include "main.h"
#include "cmsis_os.h"
#include "calibration.h"

static void GUIThread(void const * argument);
osThreadDef(GUI_Thread, GUIThread, osPriorityNormal, 0, 2048);
osThreadId GUI_Thread_ThreadId;

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
    //rtc_configuration();
    RTC_TimeTypeDef tm;
    RTC_DateTypeDef dt;

    BSP_RTC_GetDate(&dt);

    if (dt.Year == 0) {
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
    }

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
        //lockTimer_h = GUI_TIMER_Create(lockTimer, idleTimeOut, 0, 0);
        state = 1;
    }
    state = 1;
    int counter = 0;
    while(1)
    {
        switch (state)
        {
        case 0:
            break;
        case 99:
            CreateTriacPanel();
            state = 0;
            break;
        case 1:
            //GUI_TIMER_SetPeriod(lockTimer_h, idleTimeOut);
            //GUI_TIMER_Restart(lockTimer_h);
            GUI_Delay(100);
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
        GUI_Delay(50);
#ifdef CODEBLOCK
        if (counter++ > 100) {
            controlCode();
            counter = 0;
        }
#endif
    }
}

#ifndef CODEBLOCK
void BSP_GUI_Init(void) {
    GUI_Thread_ThreadId = osThreadCreate(osThread(GUI_Thread), NULL);
	/* TODO: add error check */
}
#endif
