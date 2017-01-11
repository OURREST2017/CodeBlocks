#include "main.h"

extern void CreateHomeWin(void);
extern void CreateMode(void);
extern void CreateSettings(void);
extern void CreateFAN(void);
extern void CreateSchedule(void);
extern void CreateAlphaKeyboard(void);
extern void CreateColors(void);
extern void CreateDateTime(void);
extern void CreateScreenLockout(void);
extern void CreateSettingsSchedule(void);
extern void CreateLanguages(void);
extern void CreateProfile(void);
extern void CreatePreferences(void);
extern void CreateSystemSetup(void);
extern void CreateThermostatLocations(void);
extern void CreateSystemType(void);
extern void CreateThermostatControls(void);
extern void CreateFanControl(void);
extern void CreateWifiSetup(void);
extern void CreateBackupHeat(void);
extern void CreateCoolingStages(void);
extern void CreateHeatingStages(void);
extern void CreateEachDay(void);
extern void CreateSchedulingOptions(void);
extern void CreateTempuratureScale(void);
extern void CreateClockFormat(void);
extern void CreateDaylightSavingTime(void);
extern void CreateSystemsChangeOver(void);
extern void CreateKeyboardLockout(void);
extern void CreateSchedulePeriods(void);
extern void CreateNumericKeyboard(void);

char blowme[50];
BUTTON_Handle hButton;

static void _cbBkWin(WM_MESSAGE * pMsg)
{
    int                 NCode;
    int                 Id;

    switch (pMsg->MsgId)
    {
    case WM_NOTIFY_PARENT:
        Id    = WM_GetId(pMsg->hWinSrc);    // Id of widget
        NCode = pMsg->Data.v;               // Notification code
        switch (NCode)
        {
        case WM_NOTIFICATION_RELEASED:      // React only if released
            switch (Id)
            {
            case GUI_ID_BUTTON0:
                strcpy(blowme, "blowme");
                WM_InvalidateWindow(hButton);
                //GUI_ErrorOut(blowme);
                break;
            case GUI_ID_BUTTON1:
                break;
            }
            break;
        }
        break;
    case WM_PAINT:
//       GUI_DrawGradientV(0, 0, 300, 200, GUI_BLUE, GUI_BLACK);
//        GUI_SetTextMode(GUI_TM_TRANS);
//        GUI_SetColor(0xcecece);
//        GUI_AA_FillRoundedRect(100, 100, 300, 200, 5);
//              GUI_SetColor(GUI_DARKGRAY);
//        GUI_DispStringHCenterAt("BLOWME", 150,150);
        break;
    }
}

extern void initColors(void);

void edit_text(WM_MESSAGE * pMsg)
{
    switch (pMsg->MsgId)
    {
    case WM_PAINT:
        GUI_SetTextMode(GUI_TM_TRANS);
          GUI_SetPenSize(3);
        GUI_SetColor(0xbbbbbb);
        GUI_AA_FillRoundedRect(4,4,46,48,4);
        GUI_SetColor(0x00f0f0f0);
        GUI_AA_DrawRoundedRect(2,2,48,48, 8);
        GUI_SetColor(GUI_DARKGRAY);
        GUI_DispStringHCenterAt(blowme, 40,50);
        break;
    default:
        BUTTON_Callback(pMsg);
        break;
    }
}



void MainTask(void)
{
    GUI_Init();
    temperature=60;
    state=1;
    char buffer[10];

    color_scheme = 0;
    initColors();
    loadConfig();
    holdMode = 0;

    GUI_RECT rect;
    rect.x0 = 00;
    rect.x1 = 00;
    rect.y0 = 200;
    rect.y1 = 200;
    WM_SetDesktopColor(GUI_WHITE);
    WM_SetCallback(WM_HBKWIN, _cbBkWin);
    strcpy(blowme, "BLOWU");
    //WM_SetScreenSize(480,272);
    //GUI_TIMER_Create(_OnTimer, 1000, 0, 0);
    while(1)
    {
        switch (state)
        {
        case 0:
            break;
        case 1:
            CreateHomeWin();

             //hButton = TEXT_Create(100, 100, 50,50, 0, WM_CF_SHOW, "", 0);
             //WM_SetCallback(hButton, edit_text);

            // BUTTON_CreateUser(200, 50, 80, 25, 0, WM_CF_SHOW, 0, GUI_ID_BUTTON0, 3);
//            BUTTON_SetText(hButton, "BLOWME");
//            BUTTON_SetUserData(hButton,"DAT", 3);
//            WM_SetCallback(hButton, blowme);
//
//            hButton = BUTTON_CreateUser(130, 100, 100, 100, 0, WM_CF_SHOW, 0, GUI_ID_BUTTON0, 0);
//            WM_SetCallback(hButton, dn_button);
//     hButton = _CreateButton(100, 100, 170, 150, 5, 25, "Dashboard" ,
//                                  0   , GUI_ID_BUTTON0);
//
            //BUTTON_SetDefaultBkColor( GUI_YELLOW, BUTTON_CI_UNPRESSED);
            //hButton = BUTTON_CreateUser(100,100,200,100,0,WM_CF_SHOW,0,0,0);
//               WM_SetCallback(hButton, blowme);
            //BUTTON_SetBitmapEx(hButton, 0,   &bm_1bpp_1, 10, 2);
            // BUTTON_SetSkin(hButton,BUTTON_SKIN_FLEX);
            // _DrawGradientRoundBar(100,100,200,200,0x0064B49C,0x0048856A);
            //GUI_AA_FillPolygon(aPoints, countof(aPoints), 100, 150);
            //GUI_AA_DrawArc(x0 + r, y0_ + r, r - 2, r - 2,  0, 360);
            //GUI_AA_FillRoundedRect(100, 100, 200, 200, 5);
            state=0;
            break;
        case 2:
            CreateNumericKeyboard();
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
            CreateAlphaKeyboard();
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
            CreateProfile();
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
            CreateSystemType();
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
            //CreateTempuratureScale();
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
