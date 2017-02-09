#include "ranger.h"

#define ID_WINDOW_0 (GUI_ID_USER + 0x02)
#define ID_TEXT_HEADER (GUI_ID_USER + 0x08)
#define ID_BUTTON_CLOSE (GUI_ID_USER + 0x15)
#define ID_TEXT_1 (GUI_ID_USER + 0x17)
#define ID_TEXT_2 (GUI_ID_USER + 0x18)
#define ID_TEXT_3 (GUI_ID_USER + 0x19)

/*********************************************************************
*
*       _aDialogCreate
*/
static const GUI_WIDGET_CREATE_INFO _aDialogCreate[] =
{
    { WINDOW_CreateIndirect, "Window", ID_WINDOW_0, 0, 0, 480, 272, 0, 0x0, 0 },
    { TEXT_CreateIndirect, "SCHEDULE HELP", ID_TEXT_HEADER, 0, 0, 480, 50, 0, 0x64, 0 },
    { BUTTON_CreateIndirect, "CLOSE", ID_BUTTON_CLOSE, 378, 230, 80, 28, 0, 0x0, 0 },
    { TEXT_CreateIndirect, "Text", ID_TEXT_1, 0, 90, 480, 20, 0, 0x64, 0 },
    { TEXT_CreateIndirect, "Text", ID_TEXT_2, 0, 120, 480, 20, 0, 0x64, 0 },
    { TEXT_CreateIndirect, "Text", ID_TEXT_3, 0, 142, 480, 20, 0, 0x64, 0 },
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
    case WM_PAINT:
        GUI_DrawGradientV(0, 0, 480, 50, 0x63b39b, 0x48866c);
        GUI_DrawBitmap(&bmwatermark,45,52);
        break;
    case WM_INIT_DIALOG:
        hItem = WM_GetDialogItem(pMsg->hWin, ID_TEXT_HEADER);
        TEXT_SetFont(hItem, GUI_FONT_32B_1);
        TEXT_SetTextAlign(hItem, GUI_TA_HCENTER | GUI_TA_VCENTER);
        TEXT_SetTextColor(hItem, GUI_MAKE_COLOR(0xFFFFFF));
        //
        hItem = WM_GetDialogItem(pMsg->hWin, ID_TEXT_1);
        TEXT_SetFont(hItem, &FontBig20B);
        TEXT_SetText(hItem, "Use the Set Schedule button to set the desired schedule.");
        TEXT_SetTextAlign(hItem, GUI_TA_HCENTER | GUI_TA_VCENTER);
        TEXT_SetTextColor(hItem, GUI_MAKE_COLOR(0x808080));
        //
        hItem = WM_GetDialogItem(pMsg->hWin, ID_TEXT_2);
        TEXT_SetText(hItem, "To edit a schedule select the desired schedule");
        TEXT_SetFont(hItem, &FontBig20B);
        TEXT_SetTextAlign(hItem, GUI_TA_HCENTER | GUI_TA_VCENTER);
        TEXT_SetTextColor(hItem, GUI_MAKE_COLOR(0x808080));
       //
        hItem = WM_GetDialogItem(pMsg->hWin, ID_TEXT_3);
        TEXT_SetText(hItem, "and press the Edit button.");
        TEXT_SetFont(hItem, &FontBig20B);
        TEXT_SetTextAlign(hItem, GUI_TA_HCENTER | GUI_TA_VCENTER);
        TEXT_SetTextColor(hItem, GUI_MAKE_COLOR(0x808080));

        hItem = WM_GetDialogItem(pMsg->hWin, ID_BUTTON_CLOSE);
        WM_SetCallback(hItem, buttonOn16_cb);
        break;
    case WM_NOTIFY_PARENT:
        Id    = WM_GetId(pMsg->hWinSrc);
        NCode = pMsg->Data.v;
        switch(Id)
        {
        case ID_BUTTON_CLOSE:
            switch(NCode)
            {
            case WM_NOTIFICATION_CLICKED:
                hItem = WM_GetDialogItem(pMsg->hWin, ID_BUTTON_CLOSE);
                WM_SetCallback(hItem, buttonPush16_cb);
                break;
            case WM_NOTIFICATION_RELEASED:
                GUI_Delay(100);
                CreateSettingsSchedule();
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
WM_HWIN CreateScheduleHelp(void);
WM_HWIN CreateScheduleHelp(void)
{
    WM_HWIN hWin;

    hWin = GUI_CreateDialogBox(_aDialogCreate, GUI_COUNTOF(_aDialogCreate), _cbDialog, WM_HBKWIN, 0, 0);
    return hWin;
}

/*************************** End of file ****************************/
