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
#define ID_BUTTON_1_STAGE (GUI_ID_USER + 0x0E)
#define ID_BUTTON_2_STAGE (GUI_ID_USER + 0x0F)

/*********************************************************************
*
*       _aDialogCreate
*/
static const GUI_WIDGET_CREATE_INFO _aDialogCreate[] =
{
    { WINDOW_CreateIndirect, "Window", ID_WINDOW_0, 3, -1, 480, 272, 0, 0x0, 0 },
    { BUTTON_CreateIndirect, "CANCEL", ID_BUTTON_CANCEL, 20, 230, 80, 28, 0, 0x0, 0 },
    { BUTTON_CreateIndirect, "SAVE", ID_BUTTON_SAVE, 375, 230, 80, 28, 0, 0x0, 0 },
    { HEADER_CreateIndirect, "Header", ID_HEADER_0, 0, 0, 480, 50, 0, 0x0, 0 },
    { TEXT_CreateIndirect, "COOLING STAGES", ID_TEXT_HEADER, 0, 0, 480, 50, 0, 0x64, 0 },
    { BUTTON_CreateIndirect, "1 Stage", ID_BUTTON_1_STAGE, 120, 90, 240, 40, 0, 0x0, 0 },
    { BUTTON_CreateIndirect, "2 Stages", ID_BUTTON_2_STAGE, 120, 145, 240, 40, 0, 0x0, 0 },
};

static int one_mode;
static WM_HWIN oneButton, twoButton;

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
        GUI_DrawBitmap(&bmwatermark,45,50);
        break;
    case WM_INIT_DIALOG:
        hItem = WM_GetDialogItem(pMsg->hWin, ID_TEXT_HEADER);
        TEXT_SetFont(hItem, GUI_FONT_32B_1);
        TEXT_SetTextAlign(hItem, GUI_TA_HCENTER | GUI_TA_VCENTER);
        TEXT_SetTextColor(hItem, GUI_MAKE_COLOR(0x00FFFFFF));
        //
        oneButton = WM_GetDialogItem(pMsg->hWin, ID_BUTTON_1_STAGE);
        //
        twoButton = WM_GetDialogItem(pMsg->hWin, ID_BUTTON_2_STAGE);
        if (one_mode)
        {
            WM_SetCallback(oneButton, buttonOn22_cb);
            WM_SetCallback(twoButton, buttonOff22_cb);
        }
        else
        {
            WM_SetCallback(twoButton, buttonOn22_cb);
            WM_SetCallback(oneButton, buttonOff22_cb);
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
        case ID_BUTTON_CANCEL:
            switch(NCode)
            {
            case WM_NOTIFICATION_RELEASED:
                GUI_Delay(100);
            CreateSystemSetup();
                //state=17;
            }
            break;
        case ID_BUTTON_SAVE:
            switch(NCode)
            {
            case WM_NOTIFICATION_RELEASED:
                coolingStages = (one_mode == 1) ? 1 : 2;
                GUI_Delay(100);
            CreateSystemSetup();
                //state=17;
            }
            break;
        case ID_BUTTON_1_STAGE:
            switch(NCode)
            {
            case WM_NOTIFICATION_CLICKED:
                one_mode = 1;
                WM_SetCallback(oneButton, buttonOn22_cb);
                WM_SetCallback(twoButton, buttonOff22_cb);
                break;
            }
            break;
        case ID_BUTTON_2_STAGE:
            switch(NCode)
            {
            case WM_NOTIFICATION_CLICKED:
                one_mode =0;
                WM_SetCallback(twoButton, buttonOn22_cb);
                WM_SetCallback(oneButton, buttonOff22_cb);
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
WM_HWIN CreateCoolingStages(void);
WM_HWIN CreateCoolingStages(void)
{
    WM_HWIN hWin;

    one_mode = (coolingStages == 1);

    hWin = GUI_CreateDialogBox(_aDialogCreate, GUI_COUNTOF(_aDialogCreate), _cbDialog, WM_HBKWIN, 0, 0);
    return hWin;
}

/*************************** End of file ****************************/
