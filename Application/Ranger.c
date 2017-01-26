#include "main.h"

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
    saveConfig();
    holdMode = 0;

    if (testing)
    {
        state = 99;
    }
    else if (firstTime)
    {
        state = 14;
    }
    else
    {
        state = 1;
    }
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
//           win = MESSAGEBOX_Create("BLOWME","CAPTION",GUI_MESSAGEBOX_CF_MODAL | GUI_MESSAGEBOX_CF_MOVEABLE);
//            WM_SetSize(win, 200,150);
//           WM_HWIN twin =  WM_GetDialogItem(win, GUI_ID_TEXT0);
//             WM_SetSize(twin, 180,50);
//          TEXT_SetFont(twin, GUI_FONT_24_ASCII);
//           WM_HWIN but =  WM_GetDialogItem(win, GUI_ID_OK);
//            WM_MoveTo(but, 220,180);
            // GUI_Delay(100);
            CreateHomeWin();
            state=0;
            break;
        case 2:
            CreateEachDay();
            state=0;
            break;
        case 3:
            //CreateMode();
            //GUI_Delay(100);
            state=0;
            break;
        case 4:
            CreateSettings();
            GUI_Delay(100);
            state=0;
            break;
        case 5:
            CreateFanMode();
            GUI_Delay(100);
            state=0;
            break;
        case 6:
            state=0;
            break;
        case 7:
            GUI_Delay(100);
            CreateSchedule();
            state=0;
            break;
        case 8:
            // not used
            state=0;
            break;
        case 10:
            // not used;
            state=0;
            break;
        case 11:
            CreateDateTime();
            state=0;
            break;
        case 12:
            CreateScreenLockout();
            state=0;
            break;
        case 13:
            CreateSettingsSchedule();
            state=0;
            break;
        case 14:
            CreateLanguages();
            state=0;
            break;
        case 15:
            CreateProfile(0, "");
            state=0;
            break;
        case 16:
            CreatePreferences();
            state=0;
            break;
        case 17:
            CreateSystemSetup();
            state=0;
            break;
        case 20:
            CreateThermostatLocations();
            state=0;
            break;
        case 21:
            CreateHvacType();
            state=0;
            break;
        case 22:
            CreateThermostatControls();
            state=0;
            break;
        case 23:
            CreateFanControl();
            state=0;
            break;
        case 24:
            CreateWifiSetup();
            state=0;
            break;
        case 25:
            CreateBackupHeat();
            state=0;
            break;
        case 26:
            CreateCoolingStages();
            state=0;
            break;
        case 27:
            CreateHeatingStages();
            state=0;
            break;
        case 30:
            // not used
            state=0;
            break;
        case 31:
            // not used
            state=0;
            break;
        case 32:
            // not used
            state=0;
            break;
        case 33:
            // not used
            state=0;
            break;
        case 34:
            state=0;
            break;
        case 40:
            CreateSchedulingOptions();
            state=0;
            break;
        case 41:
            CreateTempuratureScale();
            state=0;
            break;
        case 42:
            CreateClockFormat();
            state=0;
            break;
        case 43:
            CreateDaylightSavingTime();
            state=0;
            break;
        case 44:
            CreateSystemsChangeOver();
            state=0;
            break;
        case 45:
            // not used
            state=0;
            break;
        case 46:
            CreateKeyboardLockout();
            state=0;
            break;
        case 47:
            CreateSchedulePeriods();
            state=0;
            break;
        }
        GUI_Exec();
        GUI_Delay(50);
    }
}
