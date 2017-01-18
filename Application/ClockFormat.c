/*********************************************************************
*                                                                    *
*                SEGGER Microcontroller GmbH & Co. KG                *
*        Solutions for real time microcontroller applications        *
*                                                                    *
**********************************************************************
*                                                                    *
* C-file generated by:                                               *
*                                                                    *
*        GUI_Builder for emWin version 5.32                          *
*        Compiled Oct  8 2015, 11:59:02                              *
*        (c) 2015 Segger Microcontroller GmbH & Co. KG               *
*                                                                    *
**********************************************************************
*                                                                    *
*        Internet: www.segger.com  Support: support@segger.com       *
*                                                                    *
**********************************************************************
*/

#include "main.h"

#define ID_WINDOW_0  (GUI_ID_USER + 0x00)
#define ID_HEADER_0  (GUI_ID_USER + 0x01)
#define ID_TEXT_0  (GUI_ID_USER + 0x02)
#define ID_BUTTON_12HOUR  (GUI_ID_USER + 0x03)
#define ID_BUTTON_24HOUR  (GUI_ID_USER + 0x04)
#define ID_BUTTON_CANCEL  (GUI_ID_USER + 0x05)
#define ID_BUTTON_SAVE  (GUI_ID_USER + 0x06)

/*********************************************************************
*
*       _aDialogCreate
*/
static const GUI_WIDGET_CREATE_INFO _aDialogCreate[] =
{
    { WINDOW_CreateIndirect, "Window", ID_WINDOW_0, 1, 0, 480, 272, 0, 0x0, 0 },
    { HEADER_CreateIndirect, "Header", ID_HEADER_0, 0, 0, 480, 50, 0, 0x0, 0 },
    { TEXT_CreateIndirect, "Text", ID_TEXT_0, 0, 0, 480, 50, 0, 0x64, 0 },
    { BUTTON_CreateIndirect, "12 Hour", ID_BUTTON_12HOUR, 120, 90, 240, 40, 0, 0x0, 0 },
    { BUTTON_CreateIndirect, "24 Hour", ID_BUTTON_24HOUR, 120, 145, 240, 40, 0, 0x0, 0 },
    { BUTTON_CreateIndirect, "CANCEL", ID_BUTTON_CANCEL, 20, 230, 80, 28, 0, 0x0, 0 },
    { BUTTON_CreateIndirect, "SAVE", ID_BUTTON_SAVE, 375, 230, 80, 28, 0, 0x0, 0 },
};

static int hour12_mode;
static WM_HWIN hour12Button, hour24Button;

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
        GUI_DrawBitmap(&bmwatermark, 0,50);
        break;
    case WM_INIT_DIALOG:
        hItem = WM_GetDialogItem(pMsg->hWin, ID_TEXT_0);
        TEXT_SetTextAlign(hItem, GUI_TA_HCENTER | GUI_TA_VCENTER);
        TEXT_SetFont(hItem, GUI_FONT_32B_1);
        TEXT_SetText(hItem, "CLOCK FORMAT");
        TEXT_SetTextColor(hItem,GUI_MAKE_COLOR(0x00FFFFFF));
        //
        hour12Button = WM_GetDialogItem(pMsg->hWin, ID_BUTTON_12HOUR);
        //
        hour24Button = WM_GetDialogItem(pMsg->hWin, ID_BUTTON_24HOUR);
        //
        if (hour12_mode)
        {
            WM_SetCallback(hour12Button, buttonOn22_cb);
            WM_SetCallback(hour24Button, buttonOff22_cb);
        }
        else
        {
            WM_SetCallback(hour12Button, buttonOff22_cb);
            WM_SetCallback(hour24Button, buttonOn22_cb);
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
        case ID_BUTTON_12HOUR:
            switch(NCode)
            {
            case WM_NOTIFICATION_RELEASED:
                hour12_mode = 1;
                WM_SetCallback(hour12Button, buttonOn22_cb);
                WM_SetCallback(hour24Button, buttonOff22_cb);
                break;
            }
            break;
        case ID_BUTTON_24HOUR:
            switch(NCode)
            {
            case WM_NOTIFICATION_RELEASED:
                hour12_mode = 0;
                WM_SetCallback(hour12Button, buttonOff22_cb);
                WM_SetCallback(hour24Button, buttonOn22_cb);
                break;
            }
            break;
        case ID_BUTTON_CANCEL:
            switch(NCode)
            {
            case WM_NOTIFICATION_CLICKED:
                break;
            case WM_NOTIFICATION_RELEASED:
                state = 16;
                break;
            }
            break;
        case ID_BUTTON_SAVE:
            switch(NCode)
            {
            case WM_NOTIFICATION_CLICKED:
                break;
            case WM_NOTIFICATION_RELEASED:
                clockFormat = (hour12_mode == 1) ? 12 : 24;
                state = 16;
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
WM_HWIN CreateClockFormat(void);
WM_HWIN CreateClockFormat(void)
{
    WM_HWIN hWin;

    hour12_mode = (clockFormat == 12);

    hWin = GUI_CreateDialogBox(_aDialogCreate, GUI_COUNTOF(_aDialogCreate), _cbDialog, WM_HBKWIN, 0, 0);
    return hWin;
}

/*************************** End of file ****************************/
