#include "ranger.h"

#define ID_WINDOW_0 (GUI_ID_USER + 0x02)
#define ID_TEXT_HEADER (GUI_ID_USER + 0x08)
#define ID_BUTTON_THERMO_LOCATION (GUI_ID_USER + 0x0E)
#define ID_BUTTON_SYSTEM_TYPE (GUI_ID_USER + 0x0F)
#define ID_BUTTON_THERMO_CONTROLS (GUI_ID_USER + 0x10)
#define ID_BUTTON_FAN_CONTROLS (GUI_ID_USER + 0x11)
#define ID_BUTTON_WIFI_SETUP (GUI_ID_USER + 0x12)
#define ID_BUTTON_BACKUP_HEAT (GUI_ID_USER + 0x13)
#define ID_BUTTON_COOLING_STAGES (GUI_ID_USER + 0x14)
#define ID_BUTTON_HEATING_STAGES (GUI_ID_USER + 0x15)
#define ID_BUTTON_RETURN (GUI_ID_USER + 0x16)
#define ID_BUTTON_NEXT (GUI_ID_USER + 0x17)
#define ID_BUTTON_BACK (GUI_ID_USER + 0x18)

#define BUT_X 66
#define BUT_HEIGHT 34
#define BUT_WIDTH 350
#define BUT_SPACING 40
#define BUTTON_Y_OFFSET 65

#define BUTTON_Y_POS(x)  BUTTON_Y_OFFSET + (x * BUT_SPACING)

static const GUI_WIDGET_CREATE_INFO _aDialogCreate[] =
{
    { WINDOW_CreateIndirect, "Window", ID_WINDOW_0, 0, 0, 480, 272, 0, 0x0, 0 },
    { TEXT_CreateIndirect,   "SYSTEM SETUP", ID_TEXT_HEADER, 0, 0, 480, 50, 0, 0x64, 0 },
    { BUTTON_CreateIndirect, "Thermostat Location", ID_BUTTON_THERMO_LOCATION, BUT_X, BUTTON_Y_POS(0), BUT_WIDTH, BUT_HEIGHT, 0, 0x0, 0 },
    { BUTTON_CreateIndirect, "System Type", ID_BUTTON_SYSTEM_TYPE, BUT_X,  BUTTON_Y_POS(1), BUT_WIDTH, BUT_HEIGHT, 0, 0x0, 0 },
    { BUTTON_CreateIndirect, "Thermostat Controls", ID_BUTTON_THERMO_CONTROLS, BUT_X,  BUTTON_Y_POS(2), BUT_WIDTH, BUT_HEIGHT, 0, 0x0, 0 },
    { BUTTON_CreateIndirect, "Fan Control", ID_BUTTON_FAN_CONTROLS, BUT_X,  BUTTON_Y_POS(3), BUT_WIDTH, BUT_HEIGHT, 0, 0x0, 0 },
    { BUTTON_CreateIndirect, "WIFI Setup", ID_BUTTON_WIFI_SETUP, BUT_X,  BUTTON_Y_POS(0), BUT_WIDTH, BUT_HEIGHT, 0, 0x0, 0 },
    { BUTTON_CreateIndirect, "Backup Heat", ID_BUTTON_BACKUP_HEAT, BUT_X,  BUTTON_Y_POS(1), BUT_WIDTH, BUT_HEIGHT, 0, 0x0, 0 },
    { BUTTON_CreateIndirect, "Cooling Stages", ID_BUTTON_COOLING_STAGES, BUT_X,  BUTTON_Y_POS(2), BUT_WIDTH, BUT_HEIGHT, 0, 0x0, 0 },
    { BUTTON_CreateIndirect, "Heating Stages", ID_BUTTON_HEATING_STAGES, BUT_X,  BUTTON_Y_POS(3), BUT_WIDTH, BUT_HEIGHT, 0, 0x0, 0 },
    { BUTTON_CreateIndirect, "", ID_BUTTON_RETURN, 15, 0, 150, 50, 0, 0x0, 0 },

    { BUTTON_CreateIndirect, "BACK", ID_BUTTON_BACK, 200, 230, 110, BUT_HEIGHT, 0, 0x0, 0 },
    { BUTTON_CreateIndirect, "NEXT", ID_BUTTON_NEXT, 200, 230, 110, BUT_HEIGHT, 0, 0x0, 0 },
};

static int page_number;
static WM_HWIN win1,win2,win3, win4, win5, win6, win7, win8, next, back;

static void showWindows()
{
    if (page_number == 1)
    {
        WM_HideWindow(win5);
        WM_HideWindow(win6);
        WM_HideWindow(win7);
        WM_HideWindow(win8);
        WM_ShowWindow(win1);
        WM_ShowWindow(win2);
        WM_ShowWindow(win3);
        WM_ShowWindow(win4);
        WM_HideWindow(back);
        WM_ShowWindow(next);
    }
    else
    {
        WM_HideWindow(win1);
        WM_HideWindow(win2);
        WM_HideWindow(win3);
        WM_HideWindow(win4);
        WM_ShowWindow(win5);
        WM_ShowWindow(win6);
        WM_ShowWindow(win7);
        WM_ShowWindow(win8);
        WM_HideWindow(next);
        WM_ShowWindow(back);
    }
}
static void _cbDialog(WM_MESSAGE * pMsg)
{
    const void * pData;
    WM_HWIN      hItem;
    U32          FileSize;
    int          NCode;
    int          Id;

    switch (pMsg->MsgId)
    {
    case WM_PAINT:
        GUI_DrawGradientV(0, 0, 480, 50, color_map[0].stop, color_map[0].start);
        GUI_DrawBitmap(&bmwatermark,45,52);
        break;
    case WM_INIT_DIALOG:
        hItem = WM_GetDialogItem(pMsg->hWin, ID_BUTTON_RETURN);
        BUTTON_SetSkin(hItem, returnSkin);

        hItem = WM_GetDialogItem(pMsg->hWin, ID_TEXT_HEADER);
        TEXT_SetFont(hItem, HEADER_FONT_BOLD);
        TEXT_SetTextAlign(hItem, GUI_TA_HCENTER | GUI_TA_VCENTER);
        TEXT_SetTextColor(hItem, GUI_MAKE_COLOR(0x00FFFFFF));
        TEXT_SetText(hItem, LANG("SYSTEM SETUP"));
        //
        win1 = WM_GetDialogItem(pMsg->hWin, ID_BUTTON_THERMO_LOCATION);
        WM_SetCallback(win1, button22_cb);
        //
        win2 = WM_GetDialogItem(pMsg->hWin, ID_BUTTON_SYSTEM_TYPE);
        WM_SetCallback(win2, button22_cb);
        //
        win3 = WM_GetDialogItem(pMsg->hWin, ID_BUTTON_THERMO_CONTROLS);
        WM_SetCallback(win3, button22_cb);
        //
        win4 = WM_GetDialogItem(pMsg->hWin, ID_BUTTON_FAN_CONTROLS);
        WM_SetCallback(win4, button22_cb);
        //
        win5 = WM_GetDialogItem(pMsg->hWin, ID_BUTTON_WIFI_SETUP);
        WM_SetCallback(win5, button22_cb);
        //
        win6 = WM_GetDialogItem(pMsg->hWin, ID_BUTTON_BACKUP_HEAT);
        WM_SetCallback(win6, button22_cb);
        //
        win7 = WM_GetDialogItem(pMsg->hWin, ID_BUTTON_COOLING_STAGES);
        WM_SetCallback(win7, button22_cb);
        //
        win8 = WM_GetDialogItem(pMsg->hWin, ID_BUTTON_HEATING_STAGES);
        WM_SetCallback(win8, button22_cb);

        next = WM_GetDialogItem(pMsg->hWin, ID_BUTTON_NEXT);
        WM_SetCallback(next, buttonOn_cb);

        back = WM_GetDialogItem(pMsg->hWin, ID_BUTTON_BACK);
        WM_SetCallback(back, buttonOn_cb);

        showWindows();
       break;
    case WM_NOTIFY_PARENT:
        Id    = WM_GetId(pMsg->hWinSrc);
        NCode = pMsg->Data.v;
        switch(Id)
        {
        case ID_BUTTON_NEXT:
            switch(NCode)
            {
            case WM_NOTIFICATION_RELEASED:
                page_number = 2;
                showWindows();
            }
            break;
        case ID_BUTTON_BACK:
            switch(NCode)
            {
            case WM_NOTIFICATION_RELEASED:
                page_number = 1;
                showWindows();
            }
            break;
        case ID_BUTTON_RETURN:
            switch(NCode)
            {
            case WM_NOTIFICATION_RELEASED:
                GUI_Delay(100);
                WM_HideWindow(systemSetupWin);
                screenState = SETTINGSWIN;
            }
            break;
        case ID_BUTTON_THERMO_LOCATION:
            switch(NCode)
            {
            case WM_NOTIFICATION_RELEASED:
                GUI_Delay(100);
                CreateThermostatLocations();
                //state=20;
            }
            break;
        case ID_BUTTON_SYSTEM_TYPE:
            switch(NCode)
            {
            case WM_NOTIFICATION_RELEASED:
                GUI_Delay(100);
                CreateHvacType();
                ///state=21;
            }
            break;
        case ID_BUTTON_THERMO_CONTROLS:
            switch(NCode)
            {
            case WM_NOTIFICATION_RELEASED:
                GUI_Delay(100);
                CreateThermostatControls();
                // state=22;
            }
            break;
        case ID_BUTTON_FAN_CONTROLS:
            switch(NCode)
            {
            case WM_NOTIFICATION_CLICKED:
                hItem = WM_GetDialogItem(pMsg->hWin, ID_BUTTON_FAN_CONTROLS);
                WM_SetCallback(hItem, buttonPush22_cb);
                break;
            case WM_NOTIFICATION_RELEASED:
                GUI_Delay(100);
                CreateFanControl();
                //state=23;
            }
            break;
        case ID_BUTTON_WIFI_SETUP:
            switch(NCode)
            {
            case WM_NOTIFICATION_CLICKED:
                hItem = WM_GetDialogItem(pMsg->hWin, ID_BUTTON_WIFI_SETUP);
                WM_SetCallback(hItem, buttonPush22_cb);
                break;
            case WM_NOTIFICATION_RELEASED:
                GUI_Delay(100);
                CreateWifiSetup();
                //state=24;
            }
            break;
        case ID_BUTTON_BACKUP_HEAT:
            switch(NCode)
            {
            case WM_NOTIFICATION_CLICKED:
                hItem = WM_GetDialogItem(pMsg->hWin, ID_BUTTON_BACKUP_HEAT);
                WM_SetCallback(hItem, buttonPush22_cb);
                break;
            case WM_NOTIFICATION_RELEASED:
                GUI_Delay(100);
                CreateBackupHeat();
                //state=25;
            }
            break;
        case ID_BUTTON_COOLING_STAGES:
            switch(NCode)
            {
            case WM_NOTIFICATION_CLICKED:
                hItem = WM_GetDialogItem(pMsg->hWin, ID_BUTTON_COOLING_STAGES);
                WM_SetCallback(hItem, buttonPush22_cb);
                break;
            case WM_NOTIFICATION_RELEASED:
                GUI_Delay(100);
                CreateCoolingStages();
                //state=26;
            }
            break;
        case ID_BUTTON_HEATING_STAGES:
            switch(NCode)
            {
            case WM_NOTIFICATION_CLICKED:
                hItem = WM_GetDialogItem(pMsg->hWin, ID_BUTTON_HEATING_STAGES);
                WM_SetCallback(hItem, buttonPush22_cb);
                break;
            case WM_NOTIFICATION_RELEASED:
                GUI_Delay(100);
                CreateHeatingStages();
                //state=27;
            }
            break;
        }
        break;
    default:
        WM_DefaultProc(pMsg);
        break;
    }
}

WM_HWIN CreateSystemSetup(void);
WM_HWIN CreateSystemSetup(void)
{
    WM_HWIN hWin;

    page_number = 1;

    hWin = GUI_CreateDialogBox(_aDialogCreate, GUI_COUNTOF(_aDialogCreate), _cbDialog, WM_HBKWIN, 0, 0);
    WM_HideWindow(hWin);
    return hWin;
}
