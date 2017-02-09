#include "ranger.h"

#define ID_WINDOW_0     (GUI_ID_USER + 0x24)
#define ID_BUTTON_PERIOD     (GUI_ID_USER + 0x25)
#define ID_BUTTON_START     (GUI_ID_USER + 0x26)
#define ID_BUTTON_HEAT_TO     (GUI_ID_USER + 0x27)
#define ID_BUTTON_COOL_TO     (GUI_ID_USER + 0x28)
#define ID_BUTTON_UP     (GUI_ID_USER + 0x29)
#define ID_BUTTON_DOWN     (GUI_ID_USER + 0x2A)
#define ID_BUTTON_CANCEL     (GUI_ID_USER + 0x2B)
#define ID_BUTTON_WEEKDAY     (GUI_ID_USER + 0x2C)
#define ID_BUTTON_SAVE     (GUI_ID_USER + 0x2D)
#define ID_TEXT_0     (GUI_ID_USER + 0x2F)
#define ID_TEXT_1     (GUI_ID_USER + 0x30)

/*********************************************************************
*
*       _aDialogCreate
*/
static const GUI_WIDGET_CREATE_INFO _aDialogCreate[] =
{
    { WINDOW_CreateIndirect, "Schedule", ID_WINDOW_0, 0, 0, 480, 272, 0, 0x0, 0 },
    { BUTTON_CreateIndirect, "PERIOD", ID_BUTTON_PERIOD, 39, 77, 80, 30, 0, 0x0, 0 },
    { BUTTON_CreateIndirect, "START", ID_BUTTON_START, 144, 77, 80, 30, 0, 0x0, 0 },
    { BUTTON_CreateIndirect, "HEAT TO", ID_BUTTON_HEAT_TO, 254, 77, 80, 30, 0, 0x0, 0 },
    { BUTTON_CreateIndirect, "COOL TO", ID_BUTTON_COOL_TO, 360, 77, 80, 30, 0, 0x0, 0 },
    { BUTTON_CreateIndirect, "", ID_BUTTON_UP, 42, 118, 58, 40, 0, 0x0, 0 },
    { BUTTON_CreateIndirect, "", ID_BUTTON_DOWN, 42, 168, 58, 40, 0, 0x0, 0 },
    { BUTTON_CreateIndirect, "CANCEL", ID_BUTTON_CANCEL, 15, 229, 80, 30, 0, 0x0, 0 },
    { BUTTON_CreateIndirect, "WEEKDAY", ID_BUTTON_WEEKDAY, 188, 230, 80, 30, 0, 0x0, 0 },
    { BUTTON_CreateIndirect, "SAVE", ID_BUTTON_SAVE, 384, 231, 80, 30, 0, 0x0, 0 },
    { TEXT_CreateIndirect, "Edit Schedule for:", ID_TEXT_0, 77, 8, 187, 20, 0, 0x64, 0 },
    { TEXT_CreateIndirect, "WEEKEND", ID_TEXT_1, 257, 9, 119, 20, 0, 0x64, 0 },
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
        //
        hItem = WM_GetDialogItem(pMsg->hWin, ID_BUTTON_PERIOD);
        BUTTON_SetFont(hItem, &GUI_FontRounded16);
        BUTTON_SetTextColor(hItem, 0, GUI_MAKE_COLOR(0x00FFFFFF));
        //
        hItem = WM_GetDialogItem(pMsg->hWin, ID_BUTTON_START);
        BUTTON_SetFont(hItem, &GUI_FontRounded16);
        BUTTON_SetTextColor(hItem, 0, GUI_MAKE_COLOR(0x00FFFFFF));
        //
        hItem = WM_GetDialogItem(pMsg->hWin, ID_BUTTON_HEAT_TO);
        BUTTON_SetFont(hItem, &GUI_FontRounded16);
        BUTTON_SetTextColor(hItem, 0, GUI_MAKE_COLOR(0x00FFFFFF));
        //
        hItem = WM_GetDialogItem(pMsg->hWin, ID_BUTTON_COOL_TO);
        BUTTON_SetFont(hItem, &GUI_FontRounded16);
        BUTTON_SetTextColor(hItem, 0, GUI_MAKE_COLOR(0x00FFFFFF));
        //
        hItem = WM_GetDialogItem(pMsg->hWin, ID_BUTTON_UP);
        BUTTON_SetFont(hItem, &GUI_FontRounded16);
        BUTTON_SetTextColor(hItem, 0, GUI_MAKE_COLOR(0x00FFFFFF));
        //
        hItem = WM_GetDialogItem(pMsg->hWin, ID_BUTTON_DOWN);
        BUTTON_SetFont(hItem, &GUI_FontRounded16);
        BUTTON_SetTextColor(hItem, 0, GUI_MAKE_COLOR(0x00FFFFFF));
        //
        hItem = WM_GetDialogItem(pMsg->hWin, ID_BUTTON_CANCEL);
        BUTTON_SetFont(hItem, &GUI_FontRounded16);
        BUTTON_SetTextColor(hItem, BUTTON_CI_UNPRESSED, GUI_WHITE);
        BUTTON_SetTextColor(hItem, BUTTON_CI_PRESSED, GUI_WHITE);
        //
        hItem = WM_GetDialogItem(pMsg->hWin, ID_BUTTON_WEEKDAY);
        BUTTON_SetFont(hItem, &GUI_FontRounded16);
        BUTTON_SetTextColor(hItem, BUTTON_CI_UNPRESSED, GUI_WHITE);
        BUTTON_SetTextColor(hItem, BUTTON_CI_PRESSED, GUI_WHITE);
        //
        hItem = WM_GetDialogItem(pMsg->hWin, ID_BUTTON_SAVE);
        BUTTON_SetFont(hItem, &GUI_FontRounded16);
        BUTTON_SetTextColor(hItem, BUTTON_CI_UNPRESSED, GUI_WHITE);
        BUTTON_SetTextColor(hItem, BUTTON_CI_PRESSED, GUI_WHITE);
        //
        hItem = WM_GetDialogItem(pMsg->hWin, ID_TEXT_0);
        TEXT_SetFont(hItem, GUI_FONT_24_1);
        TEXT_SetTextColor(hItem, 0x00FFFFFF);
        //
        hItem = WM_GetDialogItem(pMsg->hWin, ID_TEXT_1);
        TEXT_SetFont(hItem, GUI_FONT_24B_1);
        TEXT_SetTextColor(hItem, GUI_MAKE_COLOR(0x00FFFFFF));
        break;
    case WM_NOTIFY_PARENT:
        Id    = WM_GetId(pMsg->hWinSrc);
        NCode = pMsg->Data.v;
        switch(Id)
        {
        case ID_BUTTON_PERIOD:
            switch(NCode)
            {
            case WM_NOTIFICATION_CLICKED:
                break;
            }
            break;
        case ID_BUTTON_START:
            switch(NCode)
            {
            case WM_NOTIFICATION_CLICKED:
                break;
            }
            break;
        case ID_BUTTON_HEAT_TO:
            switch(NCode)
            {
            case WM_NOTIFICATION_CLICKED:
                break;
            }
            break;
        case ID_BUTTON_COOL_TO:
            switch(NCode)
            {
            case WM_NOTIFICATION_CLICKED:
                break;
            }
            break;
        case ID_BUTTON_UP:
            switch(NCode)
            {
            case WM_NOTIFICATION_CLICKED:
                break;
            }
            break;
        case ID_BUTTON_DOWN:
            switch(NCode)
            {
            case WM_NOTIFICATION_CLICKED:
                break;
            }
            break;
        case ID_BUTTON_CANCEL:
            switch(NCode)
            {
            case WM_NOTIFICATION_CLICKED:
                GUI_Delay(100);
                CreateSettings();
                //state=4;
                break;
            }
            break;
        case ID_BUTTON_WEEKDAY:
            switch(NCode)
            {
            case WM_NOTIFICATION_CLICKED:
                break;
            }
            break;
        case ID_BUTTON_SAVE:
            switch(NCode)
            {
            case WM_NOTIFICATION_CLICKED:
                GUI_Delay(100);
                CreateSettings();
                //state=4;
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
*       CreateSchedule
*/
WM_HWIN CreateSchedule(void);
WM_HWIN CreateSchedule(void)
{
    WM_HWIN hWin;

    hWin = GUI_CreateDialogBox(_aDialogCreate, GUI_COUNTOF(_aDialogCreate), _cbDialog, WM_HBKWIN, 0, 0);
    return hWin;
}

/*************************** End of file ****************************/
