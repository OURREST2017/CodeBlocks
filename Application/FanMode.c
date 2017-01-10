/*********************************************************************
*                                                                    *
*                SEGGER Microcontroller GmbH & Co. KG                *
*        Solutions for real time microcontroller applications        *
*                                                                    *
**********************************************************************
*                                                                    *
* C-file generated by:                                               *
*                                                                    *
*        GUI_Builder for emWin version 5.28                          *
*        Compiled Jan 30 2015, 16:41:06                              *
*        (c) 2015 Segger Microcontroller GmbH & Co. KG               *
*                                                                    *
**********************************************************************
*                                                                    *
*        Internet: www.segger.com  Support: support@segger.com       *
*                                                                    *
**********************************************************************
*/

#include "main.h"

#define ID_WINDOW_0     (GUI_ID_USER + 0x0A)
#define ID_HEADER_0     (GUI_ID_USER + 0x0B)
#define ID_TEXT_HEADER     (GUI_ID_USER + 0x0C)
#define ID_BUTTON_AUTO     (GUI_ID_USER + 0x0D)
#define ID_BUTTON_ON     (GUI_ID_USER + 0x0E)
#define ID_BUTTON_CANCEL     (GUI_ID_USER + 0x0F)
#define ID_BUTTON_DONE     (GUI_ID_USER + 0x10)

/*********************************************************************
*
*       _aDialogCreate
*/
static const GUI_WIDGET_CREATE_INFO _aDialogCreate[] =
{
    { WINDOW_CreateIndirect, "FAN", ID_WINDOW_0, 0, 0, 480, 272, 0, 0x0, 0 },
    { HEADER_CreateIndirect, "Header", ID_HEADER_0, -1, 0, 480, 50, 0, 0x0, 0 },
    { TEXT_CreateIndirect, "FAN MODE", ID_TEXT_HEADER, 146, 9, 480, 50, 0, 0x64, 0 },
    { BUTTON_CreateIndirect, "AUTO", ID_BUTTON_AUTO, 129, 130, 80, 30, 0, 0x0, 0 },
    { BUTTON_CreateIndirect, "ON", ID_BUTTON_ON, 260, 130, 80, 30, 0, 0x0, 0 },
    { BUTTON_CreateIndirect, "CANCEL", ID_BUTTON_CANCEL, 21, 225, 80, 30, 0, 0x0, 0 },
    { BUTTON_CreateIndirect, "DONE", ID_BUTTON_DONE, 375, 225, 80, 30, 0, 0x0, 0 },
};

static int auto_mode, on_mode;
static void auto_cb(WM_MESSAGE * pMsg)
{
    switch (pMsg->MsgId)
    {
    case WM_PAINT:
        drawButton16("AUTO", 80, 30, auto_mode);
        break;
    default:
        BUTTON_Callback(pMsg);
        break;
    }
}
static void on_cb(WM_MESSAGE * pMsg)
{
    switch (pMsg->MsgId)
    {
    case WM_PAINT:
        drawButton16("ON", 80, 30, on_mode);
        break;
    default:
        BUTTON_Callback(pMsg);
        break;
    }
}
static WM_HWIN auto_but, on_but;
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
    case WM_INIT_DIALOG:
        hItem = WM_GetDialogItem(pMsg->hWin, ID_TEXT_HEADER);
        TEXT_SetFont(hItem, GUI_FONT_32B_1);
        TEXT_SetTextColor(hItem, 0x00FFFFFF);
        //
        auto_but = WM_GetDialogItem(pMsg->hWin, ID_BUTTON_AUTO);
        WM_SetCallback(auto_but, auto_cb);
        //
        on_but = WM_GetDialogItem(pMsg->hWin, ID_BUTTON_ON);
        WM_SetCallback(on_but, on_cb);
        //
        hItem = WM_GetDialogItem(pMsg->hWin, ID_BUTTON_CANCEL);
        WM_SetCallback(hItem, cancel_cb);
        //
        hItem = WM_GetDialogItem(pMsg->hWin, ID_BUTTON_DONE);
        WM_SetCallback(hItem, done_cb);
        break;
    case WM_NOTIFY_PARENT:
        Id    = WM_GetId(pMsg->hWinSrc);
        NCode = pMsg->Data.v;
        switch(Id)
        {
        case ID_BUTTON_AUTO:
            switch(NCode)
            {
            case WM_NOTIFICATION_RELEASED:
                auto_mode = 1;
                on_mode  = 0;
                WM_InvalidateWindow(auto_but);
                WM_InvalidateWindow(on_but);
                break;
            }
            break;
        case ID_BUTTON_ON:
            switch(NCode)
            {
            case WM_NOTIFICATION_RELEASED:
                auto_mode = 0;
                on_mode  = 1;
                WM_InvalidateWindow(auto_but);
                WM_InvalidateWindow(on_but);
                break;
            }
            break;
        case ID_BUTTON_CANCEL:
            switch(NCode)
            {
            case WM_NOTIFICATION_RELEASED:
                state=1;
                break;
            }
            break;
        case ID_BUTTON_DONE:
            switch(NCode)
            {
            case WM_NOTIFICATION_RELEASED:
                state=1;
                if (auto_mode) strcpy(selectedFanMode, "auto");
                if (on_mode) strcpy(selectedFanMode, "on");
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
*       CreateFAN
*/
WM_HWIN CreateFanMode(void);
WM_HWIN CreateFanMode(void)
{
    WM_HWIN hWin;

    auto_mode = 0;
    on_mode = 0;
    if (strcmp(selectedFanMode, "auto") == 0) auto_mode = 1;
    if (strcmp(selectedFanMode, "on") == 0) on_mode = 1;

    hWin = GUI_CreateDialogBox(_aDialogCreate, GUI_COUNTOF(_aDialogCreate), _cbDialog, WM_HBKWIN, 0, 0);
    return hWin;
}


/*************************** End of file ****************************/