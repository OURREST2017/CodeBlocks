#include "ranger.h"

#define ID_WINDOW_0  (GUI_ID_USER + 0x00)
#define ID_BUTTON_CHANGE  (GUI_ID_USER + 0x01)
#define ID_BUTTON_DELETE  (GUI_ID_USER + 0x02)
#define ID_BUTTON_CANCEL  (GUI_ID_USER + 0x06)
#define ID_BUTTON_DONE  (GUI_ID_USER + 0x07)
#define ID_TEXT_HEADER  (GUI_ID_USER + 0x09)

static const GUI_WIDGET_CREATE_INFO _aDialogCreate[] =
{
    { WINDOW_CreateIndirect, "Window", ID_WINDOW_0,0, 0, 480, 272, 0, 0x0, 0 },
    { TEXT_CreateIndirect, "EDIT ROOM", ID_TEXT_HEADER, 0, 0, 480, 50, 0, 0x64, 0 },
    { BUTTON_CreateIndirect, "CHANGE NAME", ID_BUTTON_CHANGE, 110, 80, 250, 50, 0, 0x0, 0 },
    { BUTTON_CreateIndirect, "DELETE THERMOSTAT", ID_BUTTON_DELETE, 110, 150, 250, 50, 0, 0x0, 0 },
    { BUTTON_CreateIndirect, "CANCEL", ID_BUTTON_CANCEL, 20, 230, BUT_WIDTH, BUT_HEIGHT, 0, 0x0, 0 },
    { BUTTON_CreateIndirect, "DONE", ID_BUTTON_DONE, 350, 230, BUT_WIDTH, BUT_HEIGHT, 0, 0x0, 0 },
};

static int room_number;
static WM_HWIN editRoomWin;

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
        WM_HideWindow(systemSetupWin);
        hItem = WM_GetDialogItem(pMsg->hWin, ID_TEXT_HEADER);
        TEXT_SetTextColor(hItem, 0x00FFFFFF);
        TEXT_SetTextAlign(hItem, GUI_TA_HCENTER | GUI_TA_VCENTER);
        TEXT_SetFont(hItem, HEADER_FONT_BOLD);
        TEXT_SetText(hItem, thermo_rooms[room_number]);

        hItem = WM_GetDialogItem(pMsg->hWin, ID_BUTTON_CHANGE);
        WM_SetCallback(hItem, buttonOn_cb);
        //
        hItem = WM_GetDialogItem(pMsg->hWin, ID_BUTTON_DELETE);
        WM_SetCallback(hItem, buttonOn_cb);
        //
        hItem = WM_GetDialogItem(pMsg->hWin, ID_BUTTON_CANCEL);
        WM_SetCallback(hItem, buttonOn_cb);
        //
        hItem = WM_GetDialogItem(pMsg->hWin, ID_BUTTON_DONE);
        WM_SetCallback(hItem, buttonOn_cb);
        //
        break;
    case WM_NOTIFY_PARENT:
        Id    = WM_GetId(pMsg->hWinSrc);
        NCode = pMsg->Data.v;
        switch(Id)
        {
        case ID_BUTTON_CHANGE:
            switch(NCode)
            {
            case WM_NOTIFICATION_RELEASED:
               WM_DeleteWindow(editRoomWin);
               CreateKeyboardWin(room_number, thermo_rooms[room_number],
                                    thermo_rooms[room_number], LANG("Edit Room"));
                break;
            }
            break;
        case ID_BUTTON_DELETE:
            switch(NCode)
            {
            case WM_NOTIFICATION_RELEASED:
                  WM_DeleteWindow(editRoomWin);
              CreateDeleteThermo(room_number);
                break;
            }
            break;
        case ID_BUTTON_CANCEL:
            switch(NCode)
            {
            case WM_NOTIFICATION_RELEASED:
                WM_DeleteWindow(editRoomWin);
                GUI_Delay(100);
                CreateThermostatLocations();
                break;
            }
            break;
        case ID_BUTTON_DONE:
            switch(NCode)
            {
            case WM_NOTIFICATION_RELEASED:
                WM_DeleteWindow(editRoomWin);
                GUI_Delay(100);
                CreateThermostatLocations();
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

WM_HWIN CreateEditRoom(int room);
WM_HWIN CreateEditRoom(int room)
{
    WM_HWIN hWin;

    room_number = room;
    editRoomWin = GUI_CreateDialogBox(_aDialogCreate, GUI_COUNTOF(_aDialogCreate), _cbDialog, WM_HBKWIN, 0, 0);
    return hWin;
}
