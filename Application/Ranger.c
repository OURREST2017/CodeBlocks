#include "main.h"
void MainTask(void)
{
    GUI_Init();

    color_scheme = 0;
    initColors();
    loadConfig();
    holdMode = 0;

    state = 1;
    if (testing) state = 99;

    while(1)
    {
        switch (state)
        {
        case 0:
            break;
         case 99:
            CreateTriacPanelWin();
            state = 0;
            break;
       case 1:
            CreateHomeWin();
            state=0;
            break;
        case 2:
            //CreateNumericKeyboard();
            state=0;
            break;
        case 3:
            CreateMode();
            GUI_Delay(100);
            state=0;
            break;
        case 4:
            CreateSettings();
            state=0;
            break;
        case 5:
            CreateFanMode();
            state=0;
            break;
        case 6:
            state=0;
            break;
        case 7:
            CreateSchedule();
            state=0;
            break;
        case 8:
            //CreateAlphaKeyboard();
            state=0;
            break;
        case 10:
            CreateColors();
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
            CreateAllDays();
            state=0;
            break;
        case 31:
            CreateWeekendSchedule();
            state=0;
            break;
        case 32:
            CreateEachDay();
            state=0;
            break;
        case 33:
            CreateVacation();
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
            //
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
