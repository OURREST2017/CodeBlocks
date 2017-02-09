#include "ranger.h"

#ifndef WIN32
#include "main.h"
#include "stm32f4xx_hal.h"
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

#ifndef WIN32
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
    while(1)
    {
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
        GUI_Delay(50);
    }
}

#ifndef WIN32
void BSP_GUI_Init(void) {

GUI_Thread_ThreadId = osThreadCreate(osThread(GUI_Thread), NULL);
	/* TODO: add error check */
}
#endif
