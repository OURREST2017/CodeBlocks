#include "ranger.h"

extern WHEEL dateTimeWheels[6], screenLockWheels[4];
static GUI_TIMER_HANDLE hvac_timer;

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

static void hvacTimer(GUI_TIMER_MESSAGE * pTM)
{
    hvacControlCode();
    GUI_TIMER_SetPeriod(pTM->hTimer, 4000);
    GUI_TIMER_Restart(pTM->hTimer);
}

static void lockTimer(GUI_TIMER_MESSAGE * pTM)
{
    WM_HideWindow(homeWin);
    WM_ShowWindow(idleWin);
}
static void GUIThread(void const * argument)
#else

float sensor_temperature, sensor_humidity;

static void hvacTimer(GUI_TIMER_MESSAGE * pTM)
{
    hvacControlCode();
    GUI_TIMER_SetPeriod(pTM->hTimer, 4000);
    GUI_TIMER_Restart(pTM->hTimer);
}

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
//    RTC_TimeTypeDef tm;
//    RTC_DateTypeDef dt;
//
//    tm.Hours = 4;
//    tm.Minutes = 43;
//    tm.DayLightSaving = 1;
//    tm.TimeFormat = 64;
//
//    dt.Date = 9;
//    dt.Month = 2;
//    dt.Year = 17;
//    dt.WeekDay = 4;
//
//    BSP_RTC_SetTime(&tm);
//    BSP_RTC_SetDate(&dt);
//
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
    saveStats();

    homeWin = CreateHomeWin();
    idleWin = CreateIdleWin();
    screenLockoutWin = CreateScreenLockout();
    settingsWin = CreateSettings();
    settingsScheduleWin = CreateSettingsSchedule();
    preferencesWin = CreatePreferences();
    systemSetupWin = CreateSystemSetup();
    //firstTime = 0;
    if (testing)
    {
        screenState = 99;
    }
    else if (firstTime)
    {
        //lockTimer_h = GUI_TIMER_Create(lockTimer, idleTimeOut, 0, 0);
        screenState = LANGUAGESWIN;
    }
    else
    {
        //lockTimer_h = GUI_TIMER_Create(lockTimer, idleTimeOut, 0, 0);
        screenState = HOMEWIN;
    }
    //screenState = HOMEWIN;
    int counter;

#ifdef DEBUG_MODE
    sensor_temperature = 22.8f;
    sensor_humidity = 39.0f;
    hvac_timer = GUI_TIMER_Create(hvacTimer, 4000, 0, 0);
    //hvacControlCode();
#endif

    while(1)
    {
        switch (screenState)
        {
        case 0:
            break;
        case SPLASHWIN:
            CreateSplashWin();
            screenState = NOWIN;
            break;
        case HOMEWIN:
//            GUI_TIMER_SetPeriod(lockTimer_h, idleTimeOut);
//            GUI_TIMER_Restart(lockTimer_h);
            hvacControlCode();
            WM_ShowWindow(homeWin);
            screenState = NOWIN;
            break;
        case IDLEWIN:
            WM_ShowWindow(idleWin);
            screenState = NOWIN;
            break;
        case SETTINGSWIN:
            WM_ShowWindow(settingsWin);
            screenState = NOWIN;
            break;
        case MOBILEPAREWIN:
            WM_HideWindow(settingsWin);
            CreateMobilePair();
            screenState = NOWIN;
            break;
        case DATETIMEWIN:
            WM_HideWindow(settingsWin);
            getCurrentTime();
            dateTimeWin = CreateDateTime();
            screenState = NOWIN;
            break;
        case LOCKWIN:
            WM_HideWindow(settingsWin);
            WM_ShowWindow(screenLockoutWin);
            screenState = NOWIN;
            break;
        case SETTINGSCHEDULEWIN:
            WM_HideWindow(settingsWin);
            WM_ShowWindow(settingsScheduleWin);
            screenState = NOWIN;
            break;
        case LANGUAGESWIN:
            WM_HideWindow(settingsWin);
            CreateLanguages();
            screenState = NOWIN;
            break;
        case PROFILEWIN:
            CreateProfile(0, "");
            screenState = NOWIN;
            break;
        case PREFERENCESWIN:
            WM_HideWindow(settingsWin);
            WM_ShowWindow(preferencesWin);
            screenState = NOWIN;
            break;
        case SYSTEMSETUPWIN:
            WM_HideWindow(settingsWin);
            WM_ShowWindow(systemSetupWin);
            screenState = NOWIN;
            break;
        case EDITSCHEDULEWIN:
            WM_HideWindow(settingsScheduleWin);
            CreateEditSchedule();
            screenState = NOWIN;
            break;
		Default:
			break;
        }
        GUI_Exec();
        GUI_Delay(40);
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
