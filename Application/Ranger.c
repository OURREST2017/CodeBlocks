#include "main.h"

static void lockTimer(GUI_TIMER_MESSAGE * pTM)
{
    CreateIdleWin();
}

int getInsideTemp() {
    return insideTemp;
}

int getInsideHumidity() {
    return insideHumidity;
}

void compressorOn(int mode) {

}

void fanOn(int mode) {

}

void MainTask(void)
{
    GUI_Init();
    WM_HWIN       win;
    WM_HWIN       hBkWheel;

    WM_SetCreateFlags(WM_CF_MEMDEV);
    WM_SetBkWindowColor(GUI_WHITE);
    color_scheme = 0;
    initColors();
    loadConfig();
    //saveConfig();
    holdMode = 0;
    state = 1;

//    if (testing)
//    {
//        state = 99;
//    }
//    else if (firstTime)
//    {
//        state = 2;
//        lockTimer_h = GUI_TIMER_Create(lockTimer, idleTimeOut, 0, 0);
//    }
//    else
//    {
//        state = 1;
//        lockTimer_h = GUI_TIMER_Create(lockTimer, idleTimeOut, 0, 0);
//    }
//
//    int compressorRunTime, fanRunTime;
//    int timeToDesiredTemp, timeToDesiredTempSave;
//    counter = 0;

    while(1)
    {
//        if (counter == 600) // 30 seconds
//        {
//            counter = 0;
//            insideTemp++;
//            insideHumidity++;
//
//            if (getInsideTemp() == tempSetPoint) {
//                compressorOn(false);
//            } else {
//                compressorOn(true);
//            }
//
//            if (getInsideHumidity() == humiditySetPoint) {
//                fanOn(false);
//            } else {
//                fanOn(true);
//            }
//        }
//
        switch (state)
        {
        case 0:
            break;
        case 1:
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
        case 99:
            CreateTriacPanel();
            state = 0;
            break;
        }
        GUI_Exec();
        GUI_Delay(50);
        //counter++;
    }
}
