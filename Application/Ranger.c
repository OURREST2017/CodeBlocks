#include "ranger.h"

extern WHEEL dateTimeWheels[6], screenLockWheels[4];

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
    WM_HideWindow(homeWin);
    WM_ShowWindow(idleWin);
}
static void GUIThread(void const * argument)
#else
static void lockTimer(GUI_TIMER_MESSAGE * pTM)
{
    WM_HideWindow(homeWin);
    WM_ShowWindow(idleWin);
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

    homeWin = CreateHomeWin();
    idleWin = CreateIdleWin();
    dateTimeWin = CreateDateTime();
    screenLockoutWin = CreateScreenLockout();
    settingsWin = CreateSettings();
    settingsScheduleWin = CreateSettingsSchedule();
    preferencesWin = CreatePreferences();
    systemSetupWin = CreateSystemSetup();

    //saveConfig();

    if (testing)
    {
        screenState = 99;
    }
    else if (firstTime)
    {
        lockTimer_h = GUI_TIMER_Create(lockTimer, idleTimeOut, 0, 0);
        screenState = 2;
    }
    else
    {
        lockTimer_h = GUI_TIMER_Create(lockTimer, idleTimeOut, 0, 0);
        screenState = 1;
    }
    screenState = 1;
    int counter;
    while(1)
    {
        switch (screenState)
        {
        case 0:
            break;
        case 99:
            // CreateTriacPanelWin();
            screenState = 0;
            break;
        case 1:
            GUI_TIMER_SetPeriod(lockTimer_h, idleTimeOut);
            GUI_TIMER_Restart(lockTimer_h);
            WM_ShowWindow(homeWin);
            screenState = 0;
            break;
        case 4:
            WM_ShowWindow(settingsWin);
            screenState = 0;
            break;
        case 10:
            WM_HideWindow(settingsWin);
            CreateMobilePair();
            screenState = 0;
            break;
        case 11:
            WM_HideWindow(settingsWin);
            setCurrentTime();
            LISTWHEEL_SetPos(dateTimeWheels[0].hWin, current_hour-1);
            LISTWHEEL_SetPos(dateTimeWheels[1].hWin, current_minute);
            LISTWHEEL_SetPos(dateTimeWheels[2].hWin, current_ampm);
            LISTWHEEL_SetPos(dateTimeWheels[3].hWin, current_month);
            LISTWHEEL_SetPos(dateTimeWheels[4].hWin, current_day-1);
            LISTWHEEL_SetPos(dateTimeWheels[5].hWin, current_year-2010);
            WM_ShowWindow(dateTimeWin);
            screenState = 0;
            break;
        case 12:
            LISTWHEEL_SetPos(screenLockWheels[0].hWin, lockCode[0] - 48);
            LISTWHEEL_SetPos(screenLockWheels[1].hWin, lockCode[1] - 48);
            LISTWHEEL_SetPos(screenLockWheels[2].hWin, lockCode[2] - 48);
            LISTWHEEL_SetPos(screenLockWheels[3].hWin, lockCode[3] - 48);
            WM_HideWindow(settingsWin);
            WM_ShowWindow(screenLockoutWin);
            screenState = 0;
            break;
        case 13:
            WM_HideWindow(settingsWin);
            WM_ShowWindow(settingsScheduleWin);
            screenState = 0;
            break;
        case 14:
            WM_HideWindow(settingsWin);
            CreateLanguages();
            screenState = 0;
            break;
        case 15:
            CreateProfile(0, "");
            screenState = 0;
            break;
        case 16:
            WM_HideWindow(settingsWin);
            WM_ShowWindow(preferencesWin);
            //CreatePreferences();
            screenState = 0;
            break;
        case 17:
            WM_HideWindow(settingsWin);
            WM_ShowWindow(systemSetupWin);
            screenState = 0;
            break;
        case 20:
            WM_HideWindow(settingsScheduleWin);
            CreateEditSchedule();
            screenState = 0;
            break;
        case 21:
            WM_HideWindow(editScheduleWin);
            WM_ShowWindow(settingsScheduleWin);
            screenState = 0;
            break;
        case 22:
            WM_HideWindow(settingsScheduleWin);
            CreateEachDay();
            screenState = 0;
            break;
        case 23:
            WM_HideWindow(eachDayWin);
            WM_ShowWindow(settingsScheduleWin);
            screenState = 0;
            break;
        case 24:
            WM_HideWindow(eachDayWin);
            WM_ShowWindow(editScheduleWin);
            screenState = 0;
            break;
        }
        GUI_Exec();
        GUI_Delay(40);
//#ifdef CODEBLOCK
//        if (counter > 3000)
//        {
//            hvacControlCode();
//            counter = 0;
//        }
//        counter++;
//#endif
    }
}

#ifndef CODEBLOCK
void BSP_GUI_Init(void)
{

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
