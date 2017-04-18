#include "ranger.h"

#define ID_WINDOW_0  (GUI_ID_USER + 0x00)
#define ID_TEXT_HEADER  (GUI_ID_USER + 0x02)
#define ID_TEXT_1  (GUI_ID_USER + 0x03)
#define ID_TEXT_2  (GUI_ID_USER + 0x04)
#define ID_TEXT_3  (GUI_ID_USER + 0x05)
#define ID_TEXT_4  (GUI_ID_USER + 0x06)
#define ID_BUTTON_DONE  (GUI_ID_USER + 0x0C)
#define ID_BUTTON_RESET  (GUI_ID_USER + 0x0D)

static const GUI_WIDGET_CREATE_INFO _aDialogCreate[] =
{
    { WINDOW_CreateIndirect, "Window", ID_WINDOW_0, 0, 0, 480, 272, 0, 0x0, 0 },
    { TEXT_CreateIndirect, "PEAR STATUS", ID_TEXT_HEADER, 0, 0, 480, 50, 0, 0x64, 0 },
    { TEXT_CreateIndirect, "Text", ID_TEXT_1, 0, 94, 200, 30, 0, 0x64, 0 },
    { TEXT_CreateIndirect, "Text", ID_TEXT_2, 0, 129, 200, 30, 0, 0x64, 0 },
    { TEXT_CreateIndirect, "Text", ID_TEXT_3, 206, 94, 168, 30, 0, 0x64, 0 },
    { TEXT_CreateIndirect, "Text", ID_TEXT_4, 206, 129, 178, 30, 0, 0x64, 0 },
    { BUTTON_CreateIndirect, "RESET", ID_BUTTON_RESET, 20, 230, BUT_WIDTH, BUT_HEIGHT, 0, 0x0, 0 },
    { BUTTON_CreateIndirect, "DONE", ID_BUTTON_DONE, 375, 230, BUT_WIDTH, BUT_HEIGHT, 0, 0x0, 0 },
};

static char wifiPassword[20];

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
        hItem = WM_GetDialogItem(pMsg->hWin, ID_BUTTON_DONE);
        WM_SetCallback(hItem, buttonOn_cb);

         hItem = WM_GetDialogItem(pMsg->hWin, ID_BUTTON_RESET);
        WM_SetCallback(hItem, buttonOn_cb);
       break;
    case WM_NOTIFY_PARENT:
        Id    = WM_GetId(pMsg->hWinSrc);
        NCode = pMsg->Data.v;
        switch(Id)
        {
        case ID_BUTTON_DONE:
            switch(NCode)
            {
            case WM_NOTIFICATION_RELEASED:
                GUI_Delay(100);
                WM_HideWindow(wifiPasswordWin);
                screenState = SETTINGSWIN;
                break;
            }
            break;
        case ID_BUTTON_RESET:
            switch(NCode)
            {
            case WM_NOTIFICATION_RELEASED:
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

WM_HWIN CreateWifiPassword(char *wifi);
WM_HWIN CreateWifiPassword(char *wifi)
{
    WM_HWIN hWin;

//    strcpy(wifiNetwork, wifi);
    wifiPasswordWin = GUI_CreateDialogBox(_aDialogCreate, GUI_COUNTOF(_aDialogCreate), _cbDialog, WM_HBKWIN, 0, 0);
    return hWin;
}
