#include "ranger.h"

#define ID_WINDOW_0 (GUI_ID_USER + 0x02)
#define ID_BUTTON_BACK (GUI_ID_USER + 0x05)
#define ID_BUTTON_DONE (GUI_ID_USER + 0x06)
#define ID_TEXT_HEADER (GUI_ID_USER + 0x08)
#define ID_BUTTON_ROOM1 (GUI_ID_USER + 0x09)
#define ID_BUTTON_ROOM2 (GUI_ID_USER + 0x0A)
#define ID_BUTTON_ROOM3 (GUI_ID_USER + 0x0B)
#define ID_BUTTON_ROOM4 (GUI_ID_USER + 0x0C)
#define ID_BUTTON_ROOM5 (GUI_ID_USER + 0x0D)
#define ID_BUTTON_ROOM6 (GUI_ID_USER + 0x0E)

/*********************************************************************
*
*       _aDialogCreate
*/

static const GUI_WIDGET_CREATE_INFO _aDialogCreate[] =
{
    { WINDOW_CreateIndirect, "Window", ID_WINDOW_0, 0, 0, 480, 272, 0, 0x0, 0 },
    { TEXT_CreateIndirect, "THERMOSTAT LOCATIONS", ID_TEXT_HEADER, 0, 0, 480, 50, 0, 0x64, 0 },
    { BUTTON_CreateIndirect, "", ID_BUTTON_ROOM1, 30, 70, 200, 34, 0, 0x0, 0 },
    { BUTTON_CreateIndirect, "", ID_BUTTON_ROOM2, 30, 120, 200, 34, 0, 0x0, 0 },
    { BUTTON_CreateIndirect, "", ID_BUTTON_ROOM3, 30, 170, 200, 34, 0, 0x0, 0 },
    { BUTTON_CreateIndirect, "", ID_BUTTON_ROOM4, 250, 70, 200, 34, 0, 0x0, 0 },
    { BUTTON_CreateIndirect, "", ID_BUTTON_ROOM5, 250, 120, 200, 34, 0, 0x0, 0 },
    { BUTTON_CreateIndirect, "", ID_BUTTON_ROOM6, 250, 170, 200, 34, 0, 0x0, 0 },
    { BUTTON_CreateIndirect, "DONE", ID_BUTTON_DONE, 375, 230, 80, BUTHEIGHT, 0, 0x0, 0 },
    { BUTTON_CreateIndirect, "BACK", ID_BUTTON_BACK, 20, 230, 80, BUTHEIGHT, 0, 0x0, 0 },
};
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
        hItem = WM_GetDialogItem(pMsg->hWin, ID_BUTTON_ROOM1);
        BUTTON_SetText(hItem, thermo_rooms[0]);
        WM_SetCallback(hItem, button20_cb);
        //
        hItem = WM_GetDialogItem(pMsg->hWin, ID_BUTTON_ROOM2);
        BUTTON_SetText(hItem, thermo_rooms[1]);
        WM_SetCallback(hItem, button20_cb);
        //
        hItem = WM_GetDialogItem(pMsg->hWin, ID_BUTTON_ROOM3);
        BUTTON_SetText(hItem, thermo_rooms[2]);
        WM_SetCallback(hItem, button20_cb);

        hItem = WM_GetDialogItem(pMsg->hWin, ID_BUTTON_ROOM4);
        BUTTON_SetText(hItem, thermo_rooms[3]);
        WM_SetCallback(hItem, button20_cb);
        //
        hItem = WM_GetDialogItem(pMsg->hWin, ID_BUTTON_ROOM5);
        BUTTON_SetText(hItem, thermo_rooms[4]);
        WM_SetCallback(hItem, button20_cb);
        //
        hItem = WM_GetDialogItem(pMsg->hWin, ID_BUTTON_ROOM6);
        BUTTON_SetText(hItem, thermo_rooms[5]);
        WM_SetCallback(hItem, button20_cb);

        hItem = WM_GetDialogItem(pMsg->hWin, ID_BUTTON_BACK);
        WM_SetCallback(hItem, buttonOn16_cb);
        if (!firstTime) WM_HideWin(hItem);
        //
        hItem = WM_GetDialogItem(pMsg->hWin, ID_BUTTON_DONE);
        WM_SetCallback(hItem, buttonOn16_cb);
        if (firstTime) {
            BUTTON_SetText(hItem, "NEXT");
        } else {
            BUTTON_SetText(hItem, "DONE");
        }

        break;
    case WM_NOTIFY_PARENT:
        Id    = WM_GetId(pMsg->hWinSrc);
        NCode = pMsg->Data.v;
        char room[30];
        switch(Id)
        {
        case ID_BUTTON_ROOM1:
            switch(NCode)
            {
            case WM_NOTIFICATION_RELEASED:
                CreateEditRoom(0);
                break;
            }
            break;
        case ID_BUTTON_ROOM2:
            switch(NCode)
            {
            case WM_NOTIFICATION_RELEASED:
                CreateEditRoom(1);
                break;
            }
            break;
        case ID_BUTTON_ROOM3:
            switch(NCode)
            {
            case WM_NOTIFICATION_RELEASED:
                CreateEditRoom(2);
                break;
            }
            break;
        case ID_BUTTON_ROOM4:
            switch(NCode)
            {
            case WM_NOTIFICATION_RELEASED:
                CreateEditRoom(3);
                break;
            }
            break;
        case ID_BUTTON_ROOM5:
            switch(NCode)
            {
            case WM_NOTIFICATION_RELEASED:
                CreateEditRoom(4);
                break;
            }
            break;
        case ID_BUTTON_ROOM6:
            switch(NCode)
            {
            case WM_NOTIFICATION_RELEASED:
                CreateEditRoom(5);
                break;
            }
            break;
        case ID_BUTTON_BACK:
            switch(NCode)
            {
            case WM_NOTIFICATION_RELEASED:
                GUI_Delay(100);
                CreateLanguages();
            }
            break;
        case ID_BUTTON_DONE:
            switch(NCode)
            {
            case WM_NOTIFICATION_RELEASED:
                GUI_Delay(100);
                if (firstTime) {
                    CreateHvacType();
                } else {
            CreateSystemSetup();
                  //state=17;
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

/*********************************************************************
*
*       CreateWindow
*/
WM_HWIN CreateThermostatLocations(void);
WM_HWIN CreateThermostatLocations(void)
{
    WM_HWIN hWin;

    hWin = GUI_CreateDialogBox(_aDialogCreate, GUI_COUNTOF(_aDialogCreate), _cbDialog, WM_HBKWIN, 0, 0);
    return hWin;
}

/*************************** End of file ****************************/
