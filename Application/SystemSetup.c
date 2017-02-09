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

/*********************************************************************
*
*       _aDialogCreate
*/
static const GUI_WIDGET_CREATE_INFO _aDialogCreate[] =
{
    { WINDOW_CreateIndirect, "Window", ID_WINDOW_0, 0, 0, 480, 272, 0, 0x0, 0 },
    { TEXT_CreateIndirect, "SYSTEM SETUP", ID_TEXT_HEADER, 140, 0, 300, 50, 0, 0x64, 0 },
    { BUTTON_CreateIndirect, "Thermostat Location", ID_BUTTON_THERMO_LOCATION, 10, 70, 220, 36, 0, 0x0, 0 },
    { BUTTON_CreateIndirect, "System Type", ID_BUTTON_SYSTEM_TYPE, 10, 115, 220, 36, 0, 0x0, 0 },
    { BUTTON_CreateIndirect, "Thermostat Controls", ID_BUTTON_THERMO_CONTROLS, 10, 160, 220, 36, 0, 0x0, 0 },
    { BUTTON_CreateIndirect, "Fan Control", ID_BUTTON_FAN_CONTROLS, 10, 205, 220, 36, 0, 0x0, 0 },
    { BUTTON_CreateIndirect, "WIFI Setup", ID_BUTTON_WIFI_SETUP, 242, 70, 220, 36, 0, 0x0, 0 },
    { BUTTON_CreateIndirect, "Backup Heat", ID_BUTTON_BACKUP_HEAT, 242, 115, 220, 36, 0, 0x0, 0 },
    { BUTTON_CreateIndirect, "Cooling Stages", ID_BUTTON_COOLING_STAGES, 242, 160, 220, 36, 0, 0x0, 0 },
    { BUTTON_CreateIndirect, "Heating Stages", ID_BUTTON_HEATING_STAGES, 242, 205, 220, 36, 0, 0x0, 0 },
    { BUTTON_CreateIndirect, "", ID_BUTTON_RETURN, 15, 0, 100, 50, 0, 0x0, 0 },
};

/*********************************************************************
*
*       _cbDialog
*/
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
        GUI_DrawGradientV(0, 0, 480, 50, 0x63b39b, 0x48866c);
        GUI_DrawBitmap(&bmwatermark,45,52);
        break;
    case WM_INIT_DIALOG:
        hItem = WM_GetDialogItem(pMsg->hWin, ID_BUTTON_RETURN);
        BUTTON_SetSkin(hItem, returnSkin);

        hItem = WM_GetDialogItem(pMsg->hWin, ID_TEXT_HEADER);
        TEXT_SetFont(hItem, GUI_FONT_32B_1);
        TEXT_SetTextAlign(hItem, GUI_TA_LEFT | GUI_TA_VCENTER);
        TEXT_SetTextColor(hItem, GUI_MAKE_COLOR(0x00FFFFFF));
        //
        hItem = WM_GetDialogItem(pMsg->hWin, ID_BUTTON_THERMO_LOCATION);
        WM_SetCallback(hItem, button22_cb);
        //
        hItem = WM_GetDialogItem(pMsg->hWin, ID_BUTTON_SYSTEM_TYPE);
        WM_SetCallback(hItem, button22_cb);
        //
        hItem = WM_GetDialogItem(pMsg->hWin, ID_BUTTON_THERMO_CONTROLS);
        WM_SetCallback(hItem, button22_cb);
        //
        hItem = WM_GetDialogItem(pMsg->hWin, ID_BUTTON_FAN_CONTROLS);
        WM_SetCallback(hItem, button22_cb);
        //
        hItem = WM_GetDialogItem(pMsg->hWin, ID_BUTTON_WIFI_SETUP);
        WM_SetCallback(hItem, button22_cb);
        //
        hItem = WM_GetDialogItem(pMsg->hWin, ID_BUTTON_BACKUP_HEAT);
        WM_SetCallback(hItem, button22_cb);
        //
        hItem = WM_GetDialogItem(pMsg->hWin, ID_BUTTON_COOLING_STAGES);
        WM_SetCallback(hItem, button22_cb);
        //
        hItem = WM_GetDialogItem(pMsg->hWin, ID_BUTTON_HEATING_STAGES);
        WM_SetCallback(hItem, button22_cb);
        break;
    case WM_NOTIFY_PARENT:
        Id    = WM_GetId(pMsg->hWinSrc);
        NCode = pMsg->Data.v;
        switch(Id)
        {
        case ID_BUTTON_RETURN:
            switch(NCode)
            {
            case WM_NOTIFICATION_RELEASED:
                GUI_Delay(100);
                CreateSettings();
                //state=4;
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

/*********************************************************************
*
*       CreateWindow
*/
WM_HWIN CreateSystemSetup(void);
WM_HWIN CreateSystemSetup(void)
{
    WM_HWIN hWin;

    hWin = GUI_CreateDialogBox(_aDialogCreate, GUI_COUNTOF(_aDialogCreate), _cbDialog, WM_HBKWIN, 0, 0);
    return hWin;
}

/*************************** End of file ****************************/
