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
#define ID_CHECKBOX_COOLING (GUI_ID_USER + 0x03)
#define ID_CHECKBOX_HEATING (GUI_ID_USER + 0x04)
#define ID_BUTTON_CANCEL (GUI_ID_USER + 0x05)
#define ID_BUTTON_SAVE (GUI_ID_USER + 0x06)
#define ID_HEADER_0 (GUI_ID_USER + 0x07)
#define ID_TEXT_HEADER (GUI_ID_USER + 0x08)

/*********************************************************************
*
*       _aDialogCreate
*/
static const GUI_WIDGET_CREATE_INFO _aDialogCreate[] =
{
    { WINDOW_CreateIndirect, "Window", ID_WINDOW_0, 0, 0, 480, 272, 0, 0x0, 0 },
    { CHECKBOX_CreateIndirect, "Cooling", ID_CHECKBOX_COOLING, 175, 103, 128, 26, 0, 0x0, 0 },
    { CHECKBOX_CreateIndirect, "Heating", ID_CHECKBOX_HEATING, 175, 152, 126, 29, 0, 0x0, 0 },
    { BUTTON_CreateIndirect, "CANCEL", ID_BUTTON_CANCEL, 20, 230, 75, 24, 0, 0x0, 0 },
    { BUTTON_CreateIndirect, "SAVE", ID_BUTTON_SAVE, 390, 230, 75, 24, 0, 0x0, 0 },
    { HEADER_CreateIndirect, "Header", ID_HEADER_0, 0, 0, 480, 50, 0, 0x0, 0 },
    { TEXT_CreateIndirect, "THERMOSTAT CONTROLS", ID_TEXT_HEADER, 0, 0, 480, 50, 0, 0x64, 0 },
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
    case WM_INIT_DIALOG:
        //
        // Initialization of 'Checkbox'
        //
        hItem = WM_GetDialogItem(pMsg->hWin, ID_CHECKBOX_COOLING);
        CHECKBOX_SetFont(hItem, GUI_FONT_20B_1);
        CHECKBOX_SetTextColor(hItem, GUI_MAKE_COLOR(0x00FFFFFF));
        //
        // Initialization of 'Checkbox'
        //
        hItem = WM_GetDialogItem(pMsg->hWin, ID_CHECKBOX_HEATING);
        CHECKBOX_SetFont(hItem, GUI_FONT_20B_ASCII);
        CHECKBOX_SetTextColor(hItem, GUI_MAKE_COLOR(0x00FFFFFF));
        //
        // Initialization of 'Button'
        //
        hItem = WM_GetDialogItem(pMsg->hWin, ID_BUTTON_CANCEL);
        BUTTON_SetFont(hItem, GUI_FONT_16B_1);
        BUTTON_SetTextColor(hItem, 0, GUI_MAKE_COLOR(0x00FFFFFF));
        //
        // Initialization of 'Button'
        //
        hItem = WM_GetDialogItem(pMsg->hWin, ID_BUTTON_SAVE);
        BUTTON_SetFont(hItem, GUI_FONT_16B_1);
        BUTTON_SetTextColor(hItem, 0, GUI_MAKE_COLOR(0x00FFFFFF));
        //
        // Initialization of 'Text'
        //
        hItem = WM_GetDialogItem(pMsg->hWin, ID_TEXT_HEADER);
        TEXT_SetFont(hItem, GUI_FONT_32B_1);
        TEXT_SetTextAlign(hItem, GUI_TA_HCENTER | GUI_TA_VCENTER);
        TEXT_SetTextColor(hItem, GUI_MAKE_COLOR(0x00FFFFFF));
        break;
    case WM_NOTIFY_PARENT:
        Id    = WM_GetId(pMsg->hWinSrc);
        NCode = pMsg->Data.v;
        switch(Id)
        {
        case ID_CHECKBOX_COOLING: // Notifications sent by 'Checkbox'
            switch(NCode)
            {
            case WM_NOTIFICATION_CLICKED:
                break;
            }
            break;
        case ID_CHECKBOX_HEATING: // Notifications sent by 'Checkbox'
            switch(NCode)
            {
            case WM_NOTIFICATION_CLICKED:
                break;
            }
            break;
        case ID_BUTTON_CANCEL: // Notifications sent by 'Button'
            switch(NCode)
            {
            case WM_NOTIFICATION_RELEASED:
                GUI_Delay(100);
                state=17;
            }
            break;
        case ID_BUTTON_SAVE: // Notifications sent by 'Button'
            switch(NCode)
            {
            case WM_NOTIFICATION_RELEASED:
                GUI_Delay(100);
                state=17;
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
WM_HWIN CreateThermostatControls(void);
WM_HWIN CreateThermostatControls(void)
{
    WM_HWIN hWin;

    hWin = GUI_CreateDialogBox(_aDialogCreate, GUI_COUNTOF(_aDialogCreate), _cbDialog, WM_HBKWIN, 0, 0);
    return hWin;
}

/*************************** End of file ****************************/
