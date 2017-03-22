#include "ranger.h"

#define ID_WINDOW_0 (GUI_ID_USER + 0x02)
#define ID_BUTTON_CANCEL (GUI_ID_USER + 0x05)
#define ID_BUTTON_SAVE (GUI_ID_USER + 0x06)
#define ID_TEXT_HEADER (GUI_ID_USER + 0x08)
#define ID_BUTTON_ON (GUI_ID_USER + 0x0E)
#define ID_BUTTON_OFF (GUI_ID_USER + 0x0F)

/*********************************************************************
*
*       _aDialogCreate
*/
static const GUI_WIDGET_CREATE_INFO _aDialogCreate[] =
{
    { WINDOW_CreateIndirect, "Window", ID_WINDOW_0, 0, 0, 480, 272, 0, 0x0, 0 },
    { TEXT_CreateIndirect, "DAYLIGHT SAVING TIME", ID_TEXT_HEADER, 0, 0, 480, 50, 0, 0x64, 0 },
    { BUTTON_CreateIndirect, "On", ID_BUTTON_ON, 120, 90, 240, 40, 0, 0x0, 0 },
    { BUTTON_CreateIndirect, "Off", ID_BUTTON_OFF, 120, 145, 240, 40, 0, 0x0, 0 },
    { BUTTON_CreateIndirect, "CANCEL", ID_BUTTON_CANCEL, 20, 230, 80, BUTHEIGHT, 0, 0x0, 0 },
    { BUTTON_CreateIndirect, "SAVE", ID_BUTTON_SAVE, 375, 230, 80, BUTHEIGHT, 0, 0x0, 0 },
};

static int dstOn_mode;
static WM_HWIN dstOnButton, dstOffButton, daylightSavingsTimeWin;

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
        dstOnButton = WM_GetDialogItem(pMsg->hWin, ID_BUTTON_ON);
        //
        dstOffButton = WM_GetDialogItem(pMsg->hWin, ID_BUTTON_OFF);

        if (dstOn_mode)
        {
            WM_SetCallback(dstOnButton, buttonOn22_cb);
            WM_SetCallback(dstOffButton, buttonOff22_cb);
        }
        else
        {
            WM_SetCallback(dstOnButton, buttonOff22_cb);
            WM_SetCallback(dstOffButton, buttonOn22_cb);
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
                WM_DeleteWindow(daylightSavingsTimeWin);
                GUI_Delay(100);
                screenState = 16;
                break;
            }
            break;
        case ID_BUTTON_SAVE:
            switch(NCode)
            {
            case WM_NOTIFICATION_RELEASED:
                dst = dstOn_mode;
                WM_DeleteWindow(daylightSavingsTimeWin);
                GUI_Delay(100);
                screenState = 16;
                break;
            }
            break;
        case ID_BUTTON_ON:
            switch(NCode)
            {
            case WM_NOTIFICATION_CLICKED:
                dstOn_mode = 1;
                WM_SetCallback(dstOnButton, buttonOn22_cb);
                WM_SetCallback(dstOffButton, buttonOff22_cb);
                break;
            }
            break;
        case ID_BUTTON_OFF:
            switch(NCode)
            {
            case WM_NOTIFICATION_CLICKED:
                dstOn_mode = 0;
                WM_SetCallback(dstOffButton, buttonOn22_cb);
                WM_SetCallback(dstOnButton, buttonOff22_cb);
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
WM_HWIN CreateDaylightSavingsTime(void);
WM_HWIN CreateDaylightSavingsTime(void)
{
    WM_HWIN hWin;

    dstOn_mode = dst;

    daylightSavingsTimeWin = GUI_CreateDialogBox(_aDialogCreate, GUI_COUNTOF(_aDialogCreate), _cbDialog, WM_HBKWIN, 0, 0);
    return hWin;
}

/*************************** End of file ****************************/
