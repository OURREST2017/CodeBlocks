#include "ranger.h"

#define ID_WINDOW_0 (GUI_ID_USER + 0x02)
#define ID_TEXT_HEADER (GUI_ID_USER + 0x08)
#define ID_BUTTON_CANCEL (GUI_ID_USER + 0x11)
#define ID_BUTTON_DISCONNECT (GUI_ID_USER + 0x14)
#define ID_BUTTON_DONE (GUI_ID_USER + 0x15)
#define ID_TEXT_1 (GUI_ID_USER + 0x17)
#define ID_TEXT_2 (GUI_ID_USER + 0x18)
#define ID_TEXT_3 (GUI_ID_USER + 0x19)
#define ID_TEXT_4 (GUI_ID_USER + 0x1A)
#define ID_TEXT_5 (GUI_ID_USER + 0x1B)
#define ID_TEXT_6 (GUI_ID_USER + 0x1C)
#define ID_TEXT_7 (GUI_ID_USER + 0x1D)
#define ID_TEXT_8 (GUI_ID_USER + 0x1E)
#define ID_TEXT_9 (GUI_ID_USER + 0x1F)
#define ID_TEXT_10 (GUI_ID_USER + 0x20)
#define ID_TEXT_11 (GUI_ID_USER + 0x21)
#define ID_TEXT_12 (GUI_ID_USER + 0x22)
#define ID_TEXT_13 (GUI_ID_USER + 0x23)
#define ID_TEXT_14 (GUI_ID_USER + 0x24)

/*********************************************************************
*
*       _aDialogCreate
*/
static const GUI_WIDGET_CREATE_INFO _aDialogCreate[] =
{
    { WINDOW_CreateIndirect, "Window", ID_WINDOW_0, 0, 0, 480, 272, 0, 0x0, 0 },
    { TEXT_CreateIndirect, "WIFI SETUP", ID_TEXT_HEADER, 0, 0, 480, 50, 0, 0x64, 0 },
    { TEXT_CreateIndirect, "Text", ID_TEXT_1, 0, 60, 180, 20, 0, 0x64, 0 },
    { TEXT_CreateIndirect, "Text", ID_TEXT_2, 186, 60, 260, 20, 0, 0x64, 0 },
    { TEXT_CreateIndirect, "Text", ID_TEXT_3, 0, 82, 180, 20, 0, 0x64, 0 },
    { TEXT_CreateIndirect, "Text", ID_TEXT_4, 186, 82, 260, 20, 0, 0x64, 0 },
    { TEXT_CreateIndirect, "Text", ID_TEXT_5, 0, 104, 180, 20, 0, 0x64, 0 },
    { TEXT_CreateIndirect, "Text", ID_TEXT_6, 186, 104, 260, 20, 0, 0x64, 0 },
    { TEXT_CreateIndirect, "Text", ID_TEXT_7, 0, 126, 180, 20, 0, 0x64, 0 },
    { TEXT_CreateIndirect, "Text", ID_TEXT_8, 186, 126, 260, 20, 0, 0x64, 0 },
    { TEXT_CreateIndirect, "Text", ID_TEXT_9, 0, 148, 180, 20, 0, 0x64, 0 },
    { TEXT_CreateIndirect, "Text", ID_TEXT_10, 186, 148, 260, 20, 0, 0x64, 0 },
    { TEXT_CreateIndirect, "Text", ID_TEXT_11, 68, 172, 74, 20, 0, 0x64, 0 },
    { TEXT_CreateIndirect, "Text", ID_TEXT_12, 145, 172, 175, 20, 0, 0x64, 0 },
    { TEXT_CreateIndirect, "Text", ID_TEXT_13, 321, 172, 87, 20, 0, 0x64, 0 },
    { TEXT_CreateIndirect, "Text", ID_TEXT_14, 106, 188, 232, 20, 0, 0x64, 0 },
    { BUTTON_CreateIndirect, "CANCEL", ID_BUTTON_CANCEL, 20, 230, 80, BUTHEIGHT, 0, 0x0, 0 },
    { BUTTON_CreateIndirect, "Select WIFI Network", ID_BUTTON_DISCONNECT, 128, 230, 222, BUTHEIGHT, 0, 0x0, 0 },
    { BUTTON_CreateIndirect, "DONE", ID_BUTTON_DONE, 378, 230, 80, BUTHEIGHT, 0, 0x0, 0 },
};

WM_HWIN wifiSetupWin;

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
        TEXT_SetFont(hItem, HEADER_FONT_BOLD);
        TEXT_SetTextAlign(hItem, GUI_TA_HCENTER | GUI_TA_VCENTER);
        TEXT_SetTextColor(hItem, GUI_MAKE_COLOR(0x00FFFFFF));
        //
        hItem = WM_GetDialogItem(pMsg->hWin, ID_TEXT_1);
        TEXT_SetFont(hItem, GUI_FONT_20_ASCII);
        TEXT_SetText(hItem, "Wifi Network:");
        TEXT_SetTextAlign(hItem, GUI_TA_RIGHT | GUI_TA_VCENTER);
        TEXT_SetTextColor(hItem, GUI_MAKE_COLOR(0x808080));
        //
        hItem = WM_GetDialogItem(pMsg->hWin, ID_TEXT_2);
        TEXT_SetText(hItem, myWifiNetwork);
        TEXT_SetFont(hItem, &FontBig20B);
        TEXT_SetTextAlign(hItem, GUI_TA_LEFT | GUI_TA_VCENTER);
        //
        hItem = WM_GetDialogItem(pMsg->hWin, ID_TEXT_3);
        TEXT_SetText(hItem, "Status:");
        TEXT_SetTextAlign(hItem, GUI_TA_RIGHT | GUI_TA_VCENTER);
        TEXT_SetFont(hItem, GUI_FONT_20_ASCII);
        TEXT_SetTextColor(hItem, GUI_MAKE_COLOR(0x808080));
        //
        hItem = WM_GetDialogItem(pMsg->hWin, ID_TEXT_4);
        TEXT_SetFont(hItem, &FontBig20B);
        TEXT_SetText(hItem, "Working");
        TEXT_SetTextAlign(hItem, GUI_TA_LEFT | GUI_TA_VCENTER);
        //
        hItem = WM_GetDialogItem(pMsg->hWin, ID_TEXT_5);
        TEXT_SetFont(hItem, GUI_FONT_20_ASCII);
        TEXT_SetTextAlign(hItem, GUI_TA_RIGHT | GUI_TA_VCENTER);
        TEXT_SetText(hItem, "IPAddress:");
        TEXT_SetTextColor(hItem, GUI_MAKE_COLOR(0x808080));
        //
        hItem = WM_GetDialogItem(pMsg->hWin, ID_TEXT_6);
        TEXT_SetTextAlign(hItem, GUI_TA_LEFT | GUI_TA_VCENTER);
        TEXT_SetText(hItem, "192.168.1.30");
        TEXT_SetFont(hItem, &FontBig20B);
        //
        hItem = WM_GetDialogItem(pMsg->hWin, ID_TEXT_7);
        TEXT_SetFont(hItem, GUI_FONT_20_ASCII);
        TEXT_SetTextAlign(hItem, GUI_TA_RIGHT | GUI_TA_VCENTER);
        TEXT_SetText(hItem, "Thermostat MAC:");
        TEXT_SetTextColor(hItem, GUI_MAKE_COLOR(0x808080));
        //
        hItem = WM_GetDialogItem(pMsg->hWin, ID_TEXT_8);
        TEXT_SetFont(hItem, &FontBig20B);
        TEXT_SetText(hItem, "00:50:56:8A:E3:C5");
        //
        hItem = WM_GetDialogItem(pMsg->hWin, ID_TEXT_9);
        TEXT_SetTextAlign(hItem, GUI_TA_RIGHT | GUI_TA_VCENTER);
        TEXT_SetFont(hItem, GUI_FONT_20_ASCII);
        TEXT_SetText(hItem, "Thermostat CRC:");
        TEXT_SetTextColor(hItem, GUI_MAKE_COLOR(0x808080));
        //
        hItem = WM_GetDialogItem(pMsg->hWin, ID_TEXT_10);
        TEXT_SetTextAlign(hItem, GUI_TA_LEFT | GUI_TA_VCENTER);
        TEXT_SetText(hItem, "3453");
        TEXT_SetFont(hItem, &FontBig20B);
        //
        hItem = WM_GetDialogItem(pMsg->hWin, ID_TEXT_11);
        TEXT_SetText(hItem, "Please visit");
        TEXT_SetTextAlign(hItem, GUI_TA_RIGHT | GUI_TA_VCENTER);
        TEXT_SetFont(hItem, GUI_FONT_16_1);
        //
        hItem = WM_GetDialogItem(pMsg->hWin, ID_TEXT_12);
        TEXT_SetTextAlign(hItem, GUI_TA_LEFT | GUI_TA_VCENTER);
        TEXT_SetText(hItem, "http://www.restranger.com");
        TEXT_SetFont(hItem, &GUI_FontRounded16);
        //
        hItem = WM_GetDialogItem(pMsg->hWin, ID_TEXT_13);
        TEXT_SetTextAlign(hItem, GUI_TA_LEFT | GUI_TA_VCENTER);
        TEXT_SetText(hItem, "to setup your");
        TEXT_SetFont(hItem, GUI_FONT_16_1);
        //
        hItem = WM_GetDialogItem(pMsg->hWin, ID_TEXT_14);
        TEXT_SetText(hItem, "thermostat for remote access");
        TEXT_SetTextAlign(hItem, GUI_TA_HCENTER | GUI_TA_VCENTER);
        TEXT_SetFont(hItem, GUI_FONT_16_1);
        //
        hItem = WM_GetDialogItem(pMsg->hWin, ID_BUTTON_CANCEL);
        WM_SetCallback(hItem, buttonOn16_cb);
        //
        hItem = WM_GetDialogItem(pMsg->hWin, ID_BUTTON_DISCONNECT);
        WM_SetCallback(hItem, buttonOn16_cb);
        //
        hItem = WM_GetDialogItem(pMsg->hWin, ID_BUTTON_DONE);
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
                WM_DeleteWindow(wifiSetupWin);
                screenState = 17;
                break;
            }
            break;
        case ID_BUTTON_DISCONNECT:
            switch(NCode)
            {
            case WM_NOTIFICATION_RELEASED:
                WM_HideWindow(systemSetupWin);
                WM_DeleteWindow(wifiSetupWin);
                GUI_Delay(100);
                CreateWifiConnect();
                break;
            }
            break;
        case ID_BUTTON_DONE:
            switch(NCode)
            {
            case WM_NOTIFICATION_CLICKED:
                hItem = WM_GetDialogItem(pMsg->hWin, ID_BUTTON_DONE);
                WM_SetCallback(hItem, buttonPush16_cb);
                break;
            case WM_NOTIFICATION_RELEASED:
                GUI_Delay(100);
                WM_DeleteWindow(wifiSetupWin);
                if (firstTime)
                {
                    screenState = 1;
                }
                else
                {
                    screenState = 17;
                }
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
WM_HWIN CreateWifiSetup(void);
WM_HWIN CreateWifiSetup(void)
{
    wifiSetupWin = GUI_CreateDialogBox(_aDialogCreate, GUI_COUNTOF(_aDialogCreate), _cbDialog, WM_HBKWIN, 0, 0);
    return wifiSetupWin;
}

/*************************** End of file ****************************/
