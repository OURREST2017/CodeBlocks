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

#define ID_WINDOW_0 (GUI_ID_USER + 0x02)
#define ID_BUTTON_CANCEL (GUI_ID_USER + 0x05)
#define ID_BUTTON_SAVE (GUI_ID_USER + 0x06)
#define ID_HEADER_0 (GUI_ID_USER + 0x07)
#define ID_TEXT_HEADER (GUI_ID_USER + 0x08)
#define ID_BUTTON_MANUAL (GUI_ID_USER + 0x0E)
#define ID_BUTTON_AUTOMATIC (GUI_ID_USER + 0x0F)

/*********************************************************************
*
*       _aDialogCreate
*/
static const GUI_WIDGET_CREATE_INFO _aDialogCreate[] =
{
    { WINDOW_CreateIndirect, "Window", ID_WINDOW_0, 3, -1, 480, 272, 0, 0x0, 0 },
    { BUTTON_CreateIndirect, "CANCEL", ID_BUTTON_CANCEL, 20, 230, 80, 25, 0, 0x0, 0 },
    { BUTTON_CreateIndirect, "SAVE", ID_BUTTON_SAVE, 375, 230, 80, 25, 0, 0x0, 0 },
    { HEADER_CreateIndirect, "Header", ID_HEADER_0, 0, 0, 480, 50, 0, 0x0, 0 },
    { TEXT_CreateIndirect, "SYSTEMS CHANGE OVER", ID_TEXT_HEADER, 0, 0, 480, 50, 0, 0x64, 0 },
    { BUTTON_CreateIndirect, "Manual", ID_BUTTON_MANUAL, 120, 80, 240, 40, 0, 0x0, 0 },
    { BUTTON_CreateIndirect, "Automatic", ID_BUTTON_AUTOMATIC, 120, 151, 240, 40, 0, 0x0, 0 },
};

static int manual_mode, auto_mode;

static void manual_cb(WM_MESSAGE * pMsg)
{
    switch (pMsg->MsgId)
    {
    case WM_PAINT:
        drawButton22("Manual", 240, 40, manual_mode);
        break;
    default:
        BUTTON_Callback(pMsg);
        break;
    }
}
static void auto_cb(WM_MESSAGE * pMsg)
{
    switch (pMsg->MsgId)
    {
    case WM_PAINT:
        drawButton22("Automatic", 240, 40, auto_mode);
        break;
    default:
        BUTTON_Callback(pMsg);
        break;
    }
}
static WM_HWIN manualButton, autoButton;

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
        hItem = WM_GetDialogItem(pMsg->hWin, ID_BUTTON_CANCEL);
        WM_SetCallback(hItem, cancel_cb);
        //
        hItem = WM_GetDialogItem(pMsg->hWin, ID_BUTTON_SAVE);
        WM_SetCallback(hItem, save_cb);
        //
        hItem = WM_GetDialogItem(pMsg->hWin, ID_TEXT_HEADER);
        TEXT_SetFont(hItem, GUI_FONT_32B_1);
        TEXT_SetTextAlign(hItem, GUI_TA_HCENTER | GUI_TA_VCENTER);
        TEXT_SetTextColor(hItem, GUI_MAKE_COLOR(0x00FFFFFF));
        //
        manualButton = WM_GetDialogItem(pMsg->hWin, ID_BUTTON_MANUAL);
        WM_SetCallback(manualButton, manual_cb);
        //
        autoButton = WM_GetDialogItem(pMsg->hWin, ID_BUTTON_AUTOMATIC);
        WM_SetCallback(autoButton, auto_cb);
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
                state = 16;
                break;
            }
            break;
        case ID_BUTTON_SAVE:
            switch(NCode)
            {
            case WM_NOTIFICATION_RELEASED:
                if (manual_mode)
                {
                    strcpy(systemsChangeOver, "manual");
                }
                else
                {
                    strcpy(systemsChangeOver, "automatic");
                }
                state = 16;
                break;
            }
            break;
        case ID_BUTTON_MANUAL:
            switch(NCode)
            {
            case WM_NOTIFICATION_RELEASED:
                manual_mode = 1;
                auto_mode = 0;
                WM_InvalidateWindow(manualButton);
                WM_InvalidateWindow(autoButton);
                break;
            }
            break;
        case ID_BUTTON_AUTOMATIC:
            switch(NCode)
            {
            case WM_NOTIFICATION_RELEASED:
                manual_mode = 0;
                auto_mode = 1;
                WM_InvalidateWindow(manualButton);
                WM_InvalidateWindow(autoButton);
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
WM_HWIN CreateSystemsChangeOver(void);
WM_HWIN CreateSystemsChangeOver(void)
{
    WM_HWIN hWin;

    if (strcmp(systemsChangeOver, "manual") == 0)
    {
        manual_mode = 1;
        auto_mode = 0;
    }
    else
    {
        manual_mode =0;
        auto_mode = 1;
    }

    hWin = GUI_CreateDialogBox(_aDialogCreate, GUI_COUNTOF(_aDialogCreate), _cbDialog, WM_HBKWIN, 0, 0);
    return hWin;
}

/*************************** End of file ****************************/
