#include "ranger.h"

#define ID_WINDOW_0  (GUI_ID_USER + 0x00)
#define ID_BUTTON_CHANGE  (GUI_ID_USER + 0x01)
#define ID_BUTTON_DELETE  (GUI_ID_USER + 0x02)
#define ID_BUTTON_CANCEL  (GUI_ID_USER + 0x06)
#define ID_BUTTON_DONE  (GUI_ID_USER + 0x07)
#define ID_TEXT_HEADER  (GUI_ID_USER + 0x09)

/*********************************************************************
*
*       _aDialogCreate
*/
static const GUI_WIDGET_CREATE_INFO _aDialogCreate[] =
{
    { WINDOW_CreateIndirect, "Window", ID_WINDOW_0,0, 0, 480, 272, 0, 0x0, 0 },
    { BUTTON_CreateIndirect, "CHANGE\nNAME", ID_BUTTON_CHANGE, 60, 105, 145, 70, 0, 0x0, 0 },
    { BUTTON_CreateIndirect, "DELETE\nTHERMOSTAT", ID_BUTTON_DELETE, 250, 105, 145, 70, 0, 0x0, 0 },
    { BUTTON_CreateIndirect, "CANCEL", ID_BUTTON_CANCEL, 20, 230, 80, 28, 0, 0x0, 0 },
    { BUTTON_CreateIndirect, "DONE", ID_BUTTON_DONE, 375, 230, 80, 28, 0, 0x0, 0 },
    { TEXT_CreateIndirect, "EDIT ROOM", ID_TEXT_HEADER, 0, 0, 480, 50, 0, 0x64, 0 },
};

static int cool, room_number;
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
        GUI_DrawGradientV(0, 0, 480, 50, 0x63b39b, 0x48866c);
        GUI_DrawBitmap(&bmwatermark,45,52);
        break;
    case WM_INIT_DIALOG:
        hItem = WM_GetDialogItem(pMsg->hWin, ID_TEXT_HEADER);
        TEXT_SetTextColor(hItem, 0x00FFFFFF);
        TEXT_SetTextAlign(hItem, GUI_TA_HCENTER | GUI_TA_VCENTER);
        TEXT_SetFont(hItem, GUI_FONT_32B_1);
        TEXT_SetText(hItem, thermo_rooms[room_number]);

        hItem = WM_GetDialogItem(pMsg->hWin, ID_BUTTON_CHANGE);
        WM_SetCallback(hItem, button20_cb);
        //
        hItem = WM_GetDialogItem(pMsg->hWin, ID_BUTTON_DELETE);
        WM_SetCallback(hItem, button20_cb);
        //
        hItem = WM_GetDialogItem(pMsg->hWin, ID_BUTTON_CANCEL);
        WM_SetCallback(hItem, buttonOn16_cb);
        //
        hItem = WM_GetDialogItem(pMsg->hWin, ID_BUTTON_DONE);
        WM_SetCallback(hItem, buttonOn16_cb);
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
                CreateAlphaKeyboard(room_number, thermo_rooms[room_number],
                                    thermo_rooms[room_number], "Edit Room");
                break;
            }
            break;
        case ID_BUTTON_DELETE:
            switch(NCode)
            {
            case WM_NOTIFICATION_RELEASED:
                CreateDeleteThermo(room_number);
                break;
            }
            break;
        case ID_BUTTON_CANCEL:
            switch(NCode)
            {
            case WM_NOTIFICATION_RELEASED:
                GUI_Delay(100);
                CreateThermostatLocations();
                break;
            }
            break;
        case ID_BUTTON_DONE:
            switch(NCode)
            {
            case WM_NOTIFICATION_RELEASED:
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
/*********************************************************************
*
*       CreateMode
*/
WM_HWIN CreateEditRoom(int room);
WM_HWIN CreateEditRoom(int room)
{
    WM_HWIN hWin;

    room_number = room;
    hWin = GUI_CreateDialogBox(_aDialogCreate, GUI_COUNTOF(_aDialogCreate), _cbDialog, WM_HBKWIN, 0, 0);
    return hWin;
}

/*************************** End of file ****************************/
