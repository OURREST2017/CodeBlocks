#include "ranger.h"

#define ID_WINDOW_0  (GUI_ID_USER + 0x00)
#define ID_TEXT_HEADER  (GUI_ID_USER + 0x02)
#define ID_TEXT_1  (GUI_ID_USER + 0x03)
#define ID_TEXT_2  (GUI_ID_USER + 0x04)
#define ID_TEXT_3  (GUI_ID_USER + 0x05)
#define ID_TEXT_4  (GUI_ID_USER + 0x06)
#define ID_BUTTON_DONE  (GUI_ID_USER + 0x0C)
#define ID_BUTTON_RESET  (GUI_ID_USER + 0x0D)

/*********************************************************************
*
*       _aDialogCreate
*/
static const GUI_WIDGET_CREATE_INFO _aDialogCreate[] =
{
    { WINDOW_CreateIndirect, "Window", ID_WINDOW_0, 0, 0, 480, 272, 0, 0x0, 0 },
    { TEXT_CreateIndirect, "PEAR STATUS", ID_TEXT_HEADER, 0, 0, 480, 50, 0, 0x64, 0 },
    { TEXT_CreateIndirect, "Text", ID_TEXT_1, 0, 94, 200, 30, 0, 0x64, 0 },
    { TEXT_CreateIndirect, "Text", ID_TEXT_2, 0, 129, 200, 30, 0, 0x64, 0 },
    { TEXT_CreateIndirect, "Text", ID_TEXT_3, 206, 94, 168, 30, 0, 0x64, 0 },
    { TEXT_CreateIndirect, "Text", ID_TEXT_4, 206, 129, 178, 30, 0, 0x64, 0 },
    { BUTTON_CreateIndirect, "RESET", ID_BUTTON_RESET, 20, 230, 80, BUTHEIGHT, 0, 0x0, 0 },
    { BUTTON_CreateIndirect, "DONE", ID_BUTTON_DONE, 375, 230, 80, BUTHEIGHT, 0, 0x0, 0 },
};

static char customer_text[30], mac_text[30], zip_text[12], crc_text[10], keyboard_text[50];
static char wifiPassword[20];

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
        TEXT_SetTextAlign(hItem, GUI_TA_HCENTER | GUI_TA_VCENTER);
        TEXT_SetFont(hItem, GUI_FONT_32B_ASCII);
        TEXT_SetTextColor(hItem, GUI_MAKE_COLOR(0x00FFFFFF));
        //
        hItem = WM_GetDialogItem(pMsg->hWin, ID_TEXT_1);
        TEXT_SetTextAlign(hItem, GUI_TA_RIGHT | GUI_TA_VCENTER);
        TEXT_SetFont(hItem, &GUI_FontRounded22);
        TEXT_SetText(hItem, "REST Id:");
        TEXT_SetTextColor(hItem, GUI_MAKE_COLOR(0x00008080));
        //
        hItem = WM_GetDialogItem(pMsg->hWin, ID_TEXT_2);
        TEXT_SetTextAlign(hItem, GUI_TA_RIGHT | GUI_TA_VCENTER);
        TEXT_SetFont(hItem, &GUI_FontRounded22);
        TEXT_SetText(hItem, "Expiration Date:");
        TEXT_SetTextColor(hItem, GUI_MAKE_COLOR(0x00008080));
        //
        hItem = WM_GetDialogItem(pMsg->hWin, ID_TEXT_3);
        TEXT_SetTextAlign(hItem, GUI_TA_LEFT | GUI_TA_VCENTER);
        TEXT_SetFont(hItem, &GUI_FontRounded22);
        TEXT_SetText(hItem, "1234");
        TEXT_SetTextColor(hItem, GUI_BLACK);
        //
        hItem = WM_GetDialogItem(pMsg->hWin, ID_TEXT_4);
        TEXT_SetTextAlign(hItem, GUI_TA_LEFT | GUI_TA_VCENTER);
        TEXT_SetFont(hItem, &GUI_FontRounded22);
        TEXT_SetText(hItem, "12/12/2012 5:03 PM");
        TEXT_SetTextColor(hItem, GUI_BLACK);
        //
        hItem = WM_GetDialogItem(pMsg->hWin, ID_BUTTON_DONE);
        WM_SetCallback(hItem, buttonOn16_cb);

         hItem = WM_GetDialogItem(pMsg->hWin, ID_BUTTON_RESET);
        WM_SetCallback(hItem, buttonOn16_cb);
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
                CreateSettings();
                //state = 4;
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

/*********************************************************************
*
*       CreateWindow
*/
WM_HWIN CreateWifiPassword(char *wifi);
WM_HWIN CreateWifiPassword(char *wifi)
{
    WM_HWIN hWin;

//    strcpy(wifiNetwork, wifi);
    hWin = GUI_CreateDialogBox(_aDialogCreate, GUI_COUNTOF(_aDialogCreate), _cbDialog, WM_HBKWIN, 0, 0);
    return hWin;
}

/*************************** End of file ****************************/
