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
#define ID_HEADER_0 (GUI_ID_USER + 0x07)
#define ID_TEXT_0 (GUI_ID_USER + 0x08)
#define ID_BUTTON_YES (GUI_ID_USER + 0x0E)
#define ID_BUTTON_NO (GUI_ID_USER + 0x0F)

/*********************************************************************
*
*       _aDialogCreate
*/
static const GUI_WIDGET_CREATE_INFO _aDialogCreate[] =
{
    { WINDOW_CreateIndirect, "Window", ID_WINDOW_0, 3, -1, 480, 272, 0, 0x0, 0 },
    { HEADER_CreateIndirect, "Header", ID_HEADER_0, 0, 0, 480, 50, 0, 0x0, 0 },
    { TEXT_CreateIndirect, "Text", ID_TEXT_0, 0, 0, 480, 50, 0, 0x64, 0 },
    { BUTTON_CreateIndirect, "Yes", ID_BUTTON_YES, 100, 125, 125,50, 0, 0x0, 0 },
    { BUTTON_CreateIndirect, "No", ID_BUTTON_NO, 270, 125, 125, 50, 0, 0x0, 0 },
};
static char gpioPin[10];
/*********************************************************************
*
*       _cbDialog
*/
static void _cbDialog(WM_MESSAGE * pMsg)
{
    WM_HWIN hItem;
    int     NCode;
    int     Id;
    char buf[30];

    switch (pMsg->MsgId)
    {
    case WM_INIT_DIALOG:
        hItem = pMsg->hWin;
        WINDOW_SetBkColor(hItem, 0x0FFee0C0);

        hItem = WM_GetDialogItem(pMsg->hWin, ID_TEXT_0);
        TEXT_SetFont(hItem, GUI_FONT_32B_1);
        TEXT_SetTextAlign(hItem, GUI_TA_HCENTER | GUI_TA_VCENTER);
        TEXT_SetTextColor(hItem, GUI_MAKE_COLOR(0x00FFFFFF));
        sprintf(buf, "PASS/FAIL: %s", gpioPin);
        TEXT_SetText(hItem, buf);
        //
        hItem = WM_GetDialogItem(pMsg->hWin, ID_BUTTON_YES);
        WM_SetCallback(hItem, buttonOn22_cb);

        hItem = WM_GetDialogItem(pMsg->hWin, ID_BUTTON_NO);
        WM_SetCallback(hItem, buttonOn22_cb);

        break;
    case WM_NOTIFY_PARENT:
        Id    = WM_GetId(pMsg->hWinSrc);
        NCode = pMsg->Data.v;
        switch(Id)
        {
        case ID_BUTTON_YES:
            switch(NCode)
            {
            case WM_NOTIFICATION_RELEASED:
                CreateTriacPanelWin();
                break;
            }
            break;
        case ID_BUTTON_NO:
            switch(NCode)
            {
            case WM_NOTIFICATION_RELEASED:
                CreateTriacPanelWin();
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
WM_HWIN CreatePassFail(char * pin);
WM_HWIN CreatePassFail(char * pin)
{
    WM_HWIN hWin;

    strcpy(gpioPin, pin);

    hWin = GUI_CreateDialogBox(_aDialogCreate, GUI_COUNTOF(_aDialogCreate), _cbDialog, WM_HBKWIN, 0, 0);
    return hWin;
}

/*************************** End of file ****************************/
