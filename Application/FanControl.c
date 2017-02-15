#include "ranger.h"

#define ID_WINDOW_0 (GUI_ID_USER + 0x02)
#define ID_BUTTON_CANCEL (GUI_ID_USER + 0x05)
#define ID_BUTTON_SAVE (GUI_ID_USER + 0x06)
#define ID_TEXT_HEADER (GUI_ID_USER + 0x08)
#define ID_BUTTON_THERMOSTAT (GUI_ID_USER + 0x0E)
#define ID_BUTTON_HEATING (GUI_ID_USER + 0x0F)

/*********************************************************************
*
*       _aDialogCreate
*/
static const GUI_WIDGET_CREATE_INFO _aDialogCreate[] =
{
    { WINDOW_CreateIndirect, "Window", ID_WINDOW_0, 0, 0, 480, 272, 0, 0x0, 0 },
    { TEXT_CreateIndirect, "FAN CONTROL", ID_TEXT_HEADER, 0, 0, 480, 50, 0, 0x64, 0 },
    { BUTTON_CreateIndirect, "Thermostat", ID_BUTTON_THERMOSTAT, 120, 90, 240, 40, 0, 0x0, 0 },
    { BUTTON_CreateIndirect, "Heating", ID_BUTTON_HEATING, 120, 145, 240, 40, 0, 0x0, 0 },
    { BUTTON_CreateIndirect, "CANCEL", ID_BUTTON_CANCEL, 20, 230, 80, BUTHEIGHT, 0, 0x0, 0 },
    { BUTTON_CreateIndirect, "SAVE", ID_BUTTON_SAVE, 375, 230, 80, BUTHEIGHT, 0, 0x0, 0 },
};

static int thermo_mode;
static WM_HWIN thermoButton, heatingButton;
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
        //
        hItem = WM_GetDialogItem(pMsg->hWin, ID_TEXT_HEADER);
        TEXT_SetFont(hItem, GUI_FONT_32B_1);
        TEXT_SetTextAlign(hItem, GUI_TA_HCENTER | GUI_TA_VCENTER);
        TEXT_SetTextColor(hItem, GUI_MAKE_COLOR(0x00FFFFFF));
        //
        thermoButton = WM_GetDialogItem(pMsg->hWin, ID_BUTTON_THERMOSTAT);
        //
        heatingButton = WM_GetDialogItem(pMsg->hWin, ID_BUTTON_HEATING);
        if (thermo_mode)
        {
            WM_SetCallback(thermoButton, buttonOn22_cb);
            WM_SetCallback(heatingButton, buttonOff22_cb);
        }
        else
        {
            WM_SetCallback(heatingButton, buttonOn22_cb);
            WM_SetCallback(thermoButton, buttonOff22_cb);
        }

        hItem = WM_GetDialogItem(pMsg->hWin, ID_BUTTON_CANCEL);
        WM_SetCallback(hItem, buttonOn16_cb);
        //
        hItem = WM_GetDialogItem(pMsg->hWin, ID_BUTTON_SAVE);
        WM_SetCallback(hItem, buttonOn16_cb);
        break;
    case WM_NOTIFY_PARENT:
        Id    = WM_GetId(pMsg->hWinSrc);
        NCode = pMsg->Data.v;
        switch(Id)
        {
        case ID_BUTTON_CANCEL:
            switch(NCode)
            {
            case WM_NOTIFICATION_RELEASED:
                GUI_Delay(100);
                CreateSystemSetup();
                //state=17;
            }
            break;
        case ID_BUTTON_SAVE:
            switch(NCode)
            {
            case WM_NOTIFICATION_RELEASED:
                if (thermo_mode)
                {
                    strcpy(fanControl, "thermostat");
                }
                else
                {
                    strcpy(fanControl, "heating");
                }
                GUI_Delay(100);
                CreateSystemSetup();
                //state=17;
            }
            break;
        case ID_BUTTON_THERMOSTAT:
            switch(NCode)
            {
            case WM_NOTIFICATION_CLICKED:
                thermo_mode = 1;

                WM_SetCallback(heatingButton, buttonOff22_cb);
                WM_SetCallback(thermoButton, buttonOn22_cb);
                break;
            }
            break;
        case ID_BUTTON_HEATING:
            switch(NCode)
            {
            case WM_NOTIFICATION_CLICKED:
                thermo_mode = 0;

                WM_SetCallback(heatingButton, buttonOn22_cb);
                WM_SetCallback(thermoButton, buttonOff22_cb);
                break;
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
WM_HWIN CreateFanControl(void);
WM_HWIN CreateFanControl(void)
{
    WM_HWIN hWin;

    if (strcmp(fanControl, "heating") == 0)
    {
        thermo_mode = 0;
    }
    else
    {
        thermo_mode = 1;
    }

    hWin = GUI_CreateDialogBox(_aDialogCreate, GUI_COUNTOF(_aDialogCreate), _cbDialog, WM_HBKWIN, 0, 0);
    return hWin;
}

/*************************** End of file ****************************/
