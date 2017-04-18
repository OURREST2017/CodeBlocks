#include "ranger.h"

#define ID_WINDOW_0 (GUI_ID_USER + 0x02)
#define ID_BUTTON_BACK (GUI_ID_USER + 0x05)
#define ID_BUTTON_DONE (GUI_ID_USER + 0x06)
#define ID_TEXT_HEADER (GUI_ID_USER + 0x08)
#define ID_BUTTON_LOCATION (GUI_ID_USER + 0x09)
#define ID_BUTTON_ROOM2 (GUI_ID_USER + 0x0A)
#define ID_BUTTON_ROOM3 (GUI_ID_USER + 0x0B)
#define ID_BUTTON_ROOM4 (GUI_ID_USER + 0x0C)
#define ID_BUTTON_ROOM5 (GUI_ID_USER + 0x0D)
#define ID_BUTTON_ROOM6 (GUI_ID_USER + 0x0E)
#define ID_BUTTON_NEXT (GUI_ID_USER + 0x0F)

static const GUI_WIDGET_CREATE_INFO _aDialogCreate[] =
{
    { WINDOW_CreateIndirect, "Window", ID_WINDOW_0, 0, 0, 480, 272, 0, 0x0, 0 },
    { TEXT_CreateIndirect, "THERMOSTAT LOCATION", ID_TEXT_HEADER, 0, 0, 480, 50, 0, 0x64, 0 },
    { BUTTON_CreateIndirect, "", ID_BUTTON_LOCATION, 140, 120, 220, 34, 0, 0x0, 0 },
    { BUTTON_CreateIndirect, "DONE", ID_BUTTON_DONE, 350, 230, BUT_WIDTH, BUT_HEIGHT, 0, 0x0, 0 },
    { BUTTON_CreateIndirect, "BACK", ID_BUTTON_BACK, 20, 230, BUT_WIDTH, BUT_HEIGHT, 0, 0x0, 0 },
    { BUTTON_CreateIndirect, "NEXT", ID_BUTTON_NEXT, 350, 230, BUT_WIDTH, BUT_HEIGHT, 0, 0x0, 0 },
};

static WM_HWIN thermostatLocationsWin;

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
        WM_HideWindow(systemSetupWin);
        hItem = WM_GetDialogItem(pMsg->hWin, ID_TEXT_HEADER);
        TEXT_SetFont(hItem, HEADER_FONT_BOLD);
        TEXT_SetTextAlign(hItem, GUI_TA_HCENTER | GUI_TA_VCENTER);
        TEXT_SetTextColor(hItem, GUI_MAKE_COLOR(0x00FFFFFF));
        TEXT_SetText(hItem, LANG("THERMOSTAT LOCATION"));
        //
        hItem = WM_GetDialogItem(pMsg->hWin, ID_BUTTON_LOCATION);
        BUTTON_SetText(hItem, thermo_rooms[0]);
        WM_SetCallback(hItem, button20_cb);
        //
        hItem = WM_GetDialogItem(pMsg->hWin, ID_BUTTON_BACK);
        WM_SetCallback(hItem, buttonOn_cb);
        if (!firstTime) WM_HideWin(hItem);
        //
        hItem = WM_GetDialogItem(pMsg->hWin, ID_BUTTON_NEXT);
        WM_SetCallback(hItem, buttonOn_cb);
        if (!firstTime) WM_HideWin(hItem);
        //
        hItem = WM_GetDialogItem(pMsg->hWin, ID_BUTTON_DONE);
        WM_SetCallback(hItem, buttonOn_cb);
        if (firstTime) WM_HideWin(hItem);
        break;
    case WM_NOTIFY_PARENT:
        Id    = WM_GetId(pMsg->hWinSrc);
        NCode = pMsg->Data.v;
        char room[30];
        switch(Id)
        {
        case ID_BUTTON_LOCATION:
            switch(NCode)
            {
            case WM_NOTIFICATION_RELEASED:
                WM_DeleteWindow(thermostatLocationsWin);
                CreateKeyboardWin(0, thermo_rooms[0],
                                    thermo_rooms[0], LANG("Edit Room"));
                break;
            }
            break;
        case ID_BUTTON_BACK:
            switch(NCode)
            {
            case WM_NOTIFICATION_RELEASED:
                WM_DeleteWindow(thermostatLocationsWin);
                GUI_Delay(100);
                CreateLanguages();
            }
            break;
        case ID_BUTTON_DONE:
        case ID_BUTTON_NEXT:
            switch(NCode)
            {
            case WM_NOTIFICATION_RELEASED:
                WM_DeleteWindow(thermostatLocationsWin);
                GUI_Delay(100);
                if (firstTime)
                {
                    CreateThermostatControls();
                }
                else
                {
                    screenState = SYSTEMSETUPWIN;
                }
            }
            break;
        }
        break;
    default:
        WM_DefaultProc(pMsg);
        break;
    }
}

WM_HWIN CreateThermostatLocations(void);
WM_HWIN CreateThermostatLocations(void)
{
    WM_HWIN hWin;

    thermostatLocationsWin = GUI_CreateDialogBox(_aDialogCreate, GUI_COUNTOF(_aDialogCreate), _cbDialog, WM_HBKWIN, 0, 0);
    return thermostatLocationsWin;
}
