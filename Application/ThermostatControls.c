#include "ranger.h"

#define ID_WINDOW_0 (GUI_ID_USER + 0x02)
#define ID_BUTTON_COOLING (GUI_ID_USER + 0x03)
#define ID_BUTTON_HEATING (GUI_ID_USER + 0x04)
#define ID_BUTTON_CANCEL (GUI_ID_USER + 0x05)
#define ID_BUTTON_SAVE (GUI_ID_USER + 0x06)
#define ID_TEXT_HEADER (GUI_ID_USER + 0x08)

/*********************************************************************
*
*       _aDialogCreate
*/
static const GUI_WIDGET_CREATE_INFO _aDialogCreate[] =
{
    { WINDOW_CreateIndirect, "Window", ID_WINDOW_0, 0, 0, 480, 272, 0, 0x0, 0 },
    { TEXT_CreateIndirect, "THERMOSTAT CONTROLS", ID_TEXT_HEADER, 0, 0, 480, 50, 0, 0x64, 0 },
    { BUTTON_CreateIndirect, "Cooling", ID_BUTTON_COOLING, 175, 103, 160, 32, 0, 0x0, 0 },
    { BUTTON_CreateIndirect, "Heating", ID_BUTTON_HEATING, 175, 152, 160, 32, 0, 0x0, 0 },
    { BUTTON_CreateIndirect, "CANCEL", ID_BUTTON_CANCEL, 20, 230, 80, BUTHEIGHT, 0, 0x0, 0 },
    { BUTTON_CreateIndirect, "SAVE", ID_BUTTON_SAVE, 380, 230, 80, BUTHEIGHT, 0, 0x0, 0 },
};

static int coolOn, heatOn;
static WM_HWIN cooling, heating;

/*********************************************************************
*
*       _cbDialog
*/
static void _cbDialog(WM_MESSAGE * pMsg)
{
    WM_HWIN hItem;
    int     NCode;
    int     Id;

    switch (pMsg->MsgId)
    {
    case WM_PAINT:
        GUI_DrawGradientV(0, 0, 480, 50, color_map[0].stop, color_map[0].start);
        GUI_DrawBitmap(&bmwatermark,45,52);
        break;
    case WM_INIT_DIALOG:
        hItem = WM_GetDialogItem(pMsg->hWin, ID_TEXT_HEADER);
        TEXT_SetFont(hItem, GUI_FONT_32B_ASCII);
        TEXT_SetTextAlign(hItem, GUI_TA_HCENTER | GUI_TA_VCENTER);
        TEXT_SetTextColor(hItem, GUI_MAKE_COLOR(0x00FFFFFF));

        cooling = WM_GetDialogItem(pMsg->hWin, ID_BUTTON_COOLING);
        if (coolOn) {
            WM_SetCallback(cooling, buttonOn22_cb);
        } else {
            WM_SetCallback(cooling, buttonOff22_cb);
        }
        //
        heating = WM_GetDialogItem(pMsg->hWin, ID_BUTTON_HEATING);
        if (heatOn) {
            WM_SetCallback(heating, buttonOn22_cb);
        } else {
            WM_SetCallback(heating, buttonOff22_cb);
        }

        hItem = WM_GetDialogItem(pMsg->hWin, ID_BUTTON_CANCEL);
        WM_SetCallback(hItem, buttonOn16_cb);
        //
        hItem = WM_GetDialogItem(pMsg->hWin, ID_BUTTON_SAVE);
        WM_SetCallback(hItem, buttonOn16_cb);
        //
        break;
    case WM_NOTIFY_PARENT:
        Id    = WM_GetId(pMsg->hWinSrc);
        NCode = pMsg->Data.v;
        int c,h;
        switch(Id)
        {
        case ID_BUTTON_COOLING:
            switch(NCode)
            {
            case WM_NOTIFICATION_CLICKED:
                coolOn = !coolOn;
                if (coolOn) {
                    WM_SetCallback(cooling, buttonOn22_cb);
                } else {
                    WM_SetCallback(cooling, buttonOff22_cb);
                }
                break;
            }
            break;
        case ID_BUTTON_HEATING:
            switch(NCode)
            {
            case WM_NOTIFICATION_CLICKED:
                heatOn = !heatOn;
                if (heatOn) {
                    WM_SetCallback(heating, buttonOn22_cb);
                } else {
                    WM_SetCallback(heating, buttonOff22_cb);
                }
                break;
            }
            break;
        case ID_BUTTON_CANCEL:
            switch(NCode)
            {
            case WM_NOTIFICATION_RELEASED:
                GUI_Delay(100);
                CreateSystemSetup();
            }
            break;
        case ID_BUTTON_SAVE:
            switch(NCode)
            {
            case WM_NOTIFICATION_RELEASED:
                if (coolOn == 0 && heatOn == 0) thermostatControls = 0;
                if (coolOn == 1 && heatOn == 0) thermostatControls = 1;
                if (coolOn == 0 && heatOn == 1) thermostatControls = 2;
                if (coolOn == 1 && heatOn == 1) thermostatControls = 3;
                GUI_Delay(100);
                CreateSystemSetup();
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
WM_HWIN CreateThermostatControls(void);
WM_HWIN CreateThermostatControls(void)
{
    WM_HWIN hWin;
    coolOn = heatOn = 0;
    if (thermostatControls == 1) coolOn = 1;
    if (thermostatControls == 2) heatOn = 1;
    if (thermostatControls == 3) coolOn = heatOn = 1;

    hWin = GUI_CreateDialogBox(_aDialogCreate, GUI_COUNTOF(_aDialogCreate), _cbDialog, WM_HBKWIN, 0, 0);
    return hWin;
}

/*************************** End of file ****************************/
