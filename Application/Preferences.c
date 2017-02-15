#include "ranger.h"

#define ID_WINDOW_0 (GUI_ID_USER + 0x02)
#define ID_HEADER_0 (GUI_ID_USER + 0x07)
#define ID_TEXT_HEADER (GUI_ID_USER + 0x08)
#define ID_BUTTON_SCHEDULING_OPTIONS (GUI_ID_USER + 0x0E)
#define ID_BUTTON_TEMPURATURE_SCALE (GUI_ID_USER + 0x0F)
#define ID_BUTTON_CLOCK_FORMAT (GUI_ID_USER + 0x10)
#define ID_BUTTON_DST (GUI_ID_USER + 0x11)
#define ID_BUTTON_SYSTEM_CHANGE_OVER (GUI_ID_USER + 0x12)
#define ID_BUTTON_TEMPURATURE_LIMITS (GUI_ID_USER + 0x13)
#define ID_BUTTON_KEYBOARD_LOCKOUT (GUI_ID_USER + 0x14)
#define ID_BUTTON_SCHEDULING_PERIODS (GUI_ID_USER + 0x15)
#define ID_BUTTON_RETURN (GUI_ID_USER + 0x16)

/*********************************************************************
*
*       _aDialogCreate
*/
static const GUI_WIDGET_CREATE_INFO _aDialogCreate[] =
{
    { WINDOW_CreateIndirect, "Window", ID_WINDOW_0, 0, 0, 480, 272, 0, 0x0, 0 },
    { TEXT_CreateIndirect,   "PREFERENCES", ID_TEXT_HEADER, 0, 0, 480, 50, 0, 0x64, 0 },
    { BUTTON_CreateIndirect, "Sheduling Options", ID_BUTTON_SCHEDULING_OPTIONS, 10, 70, 220, 36, 0, 0x0, 0 },
    { BUTTON_CreateIndirect, "Tempurature Scale", ID_BUTTON_TEMPURATURE_SCALE, 10, 115, 220, 36, 0, 0x0, 0 },
    { BUTTON_CreateIndirect, "Clock Format", ID_BUTTON_CLOCK_FORMAT, 10, 160, 220, 36, 0, 0x0, 0 },
    { BUTTON_CreateIndirect, "Daylight Savings Time", ID_BUTTON_DST, 10, 205, 220, 36, 0, 0x0, 0 },
    { BUTTON_CreateIndirect, "System Change Over", ID_BUTTON_SYSTEM_CHANGE_OVER, 242, 70, 220, 36, 0, 0x0, 0 },
    { BUTTON_CreateIndirect, "Tempurature Limits", ID_BUTTON_TEMPURATURE_LIMITS, 242, 115, 220, 36, 0, 0x0, 0 },
    { BUTTON_CreateIndirect, "Keyboard Lockout", ID_BUTTON_KEYBOARD_LOCKOUT, 242, 160, 220, 36, 0, 0x0, 0 },
    { BUTTON_CreateIndirect, "Schedule Periods", ID_BUTTON_SCHEDULING_PERIODS, 242, 205, 220, 36, 0, 0x0, 0 },
    { BUTTON_CreateIndirect, "", ID_BUTTON_RETURN, 15, 0, 150, 50, 0, 0x0, 0 },
};
/*********************************************************************
*
*       _cbDialog
*/
static void _cbDialog(WM_MESSAGE * pMsg)
{
    const void * pData;
    WM_HWIN      hItem;
    U32          FileSize;
    int          NCode;
    int          Id;

    switch (pMsg->MsgId)
    {
    case WM_PAINT:
        GUI_DrawGradientV(0, 0, 480, 50, color_map[0].stop, color_map[0].start);
        GUI_DrawBitmap(&bmwatermark,45,52);
        break;
    case WM_INIT_DIALOG:
        hItem = WM_GetDialogItem(pMsg->hWin, ID_BUTTON_RETURN);
        BUTTON_SetSkin(hItem, returnSkin);

        hItem = WM_GetDialogItem(pMsg->hWin, ID_TEXT_HEADER);
        TEXT_SetFont(hItem, GUI_FONT_32B_1);
        TEXT_SetTextAlign(hItem, GUI_TA_HCENTER | GUI_TA_VCENTER);
        TEXT_SetTextColor(hItem, GUI_MAKE_COLOR(0x00FFFFFF));
        //
        hItem = WM_GetDialogItem(pMsg->hWin, ID_BUTTON_SCHEDULING_OPTIONS);
        WM_SetCallback(hItem, button22_cb);
        //
        hItem = WM_GetDialogItem(pMsg->hWin, ID_BUTTON_TEMPURATURE_SCALE);
        WM_SetCallback(hItem, button22_cb);
        //
        hItem = WM_GetDialogItem(pMsg->hWin, ID_BUTTON_CLOCK_FORMAT);
        WM_SetCallback(hItem, button22_cb);
        //
        hItem = WM_GetDialogItem(pMsg->hWin, ID_BUTTON_DST);
        WM_SetCallback(hItem, button22_cb);
        //
        hItem = WM_GetDialogItem(pMsg->hWin, ID_BUTTON_SYSTEM_CHANGE_OVER);
        WM_SetCallback(hItem, button22_cb);
        //
        hItem = WM_GetDialogItem(pMsg->hWin, ID_BUTTON_TEMPURATURE_LIMITS);
        WM_SetCallback(hItem, button22_cb);
        //
        hItem = WM_GetDialogItem(pMsg->hWin, ID_BUTTON_KEYBOARD_LOCKOUT);
        WM_SetCallback(hItem, button22_cb);
        //
        hItem = WM_GetDialogItem(pMsg->hWin, ID_BUTTON_SCHEDULING_PERIODS);
        WM_SetCallback(hItem, button22_cb);
        break;
    case WM_NOTIFY_PARENT:
        Id    = WM_GetId(pMsg->hWinSrc);
        NCode = pMsg->Data.v;
        switch(Id)
        {
        case ID_BUTTON_RETURN:
            switch(NCode)
            {
            case WM_NOTIFICATION_RELEASED:
                GUI_Delay(100);
                CreateSettings();
                //state=4;
            }
            break;
        case ID_BUTTON_SCHEDULING_OPTIONS:
            switch(NCode)
            {
            case WM_NOTIFICATION_RELEASED:
                GUI_Delay(100);
                CreateSchedulingOptions();
                //state=40;
            }
            break;
        case ID_BUTTON_TEMPURATURE_SCALE:
            switch(NCode)
            {
            case WM_NOTIFICATION_CLICKED:
                hItem = WM_GetDialogItem(pMsg->hWin, ID_BUTTON_TEMPURATURE_SCALE);
                WM_SetCallback(hItem, buttonPush22_cb);
                break;
            case WM_NOTIFICATION_RELEASED:
                GUI_Delay(100);
                CreateTempuratureScale();
                //state=41;
            }
            break;
        case ID_BUTTON_CLOCK_FORMAT:
            switch(NCode)
            {
            case WM_NOTIFICATION_CLICKED:
                hItem = WM_GetDialogItem(pMsg->hWin, ID_BUTTON_CLOCK_FORMAT);
                WM_SetCallback(hItem, buttonPush22_cb);
                break;
            case WM_NOTIFICATION_RELEASED:
                GUI_Delay(100);
                CreateClockFormat();
                //state=42;
            }
            break;
        case ID_BUTTON_DST:
            switch(NCode)
            {
            case WM_NOTIFICATION_CLICKED:
                hItem = WM_GetDialogItem(pMsg->hWin, ID_BUTTON_DST);
                WM_SetCallback(hItem, buttonPush22_cb);
                break;
            case WM_NOTIFICATION_RELEASED:
                GUI_Delay(100);
                CreateDaylightSavingTime();
                //state=43;
            }
            break;
        case ID_BUTTON_SYSTEM_CHANGE_OVER:
            switch(NCode)
            {
            case WM_NOTIFICATION_CLICKED:
                hItem = WM_GetDialogItem(pMsg->hWin, ID_BUTTON_SYSTEM_CHANGE_OVER);
                WM_SetCallback(hItem, buttonPush22_cb);
                break;
            case WM_NOTIFICATION_RELEASED:
                GUI_Delay(100);
                CreateSystemsChangeOver();
                //state=44;
            }
            break;
        case ID_BUTTON_TEMPURATURE_LIMITS:
            switch(NCode)
            {
            case WM_NOTIFICATION_CLICKED:
                hItem = WM_GetDialogItem(pMsg->hWin, ID_BUTTON_TEMPURATURE_LIMITS);
                WM_SetCallback(hItem, buttonPush22_cb);
                break;
            case WM_NOTIFICATION_RELEASED:
                GUI_Delay(100);
                CreateTempuratureLimits();
                //state=45;
            }
            break;
        case ID_BUTTON_KEYBOARD_LOCKOUT:
            switch(NCode)
            {
            case WM_NOTIFICATION_CLICKED:
                hItem = WM_GetDialogItem(pMsg->hWin, ID_BUTTON_KEYBOARD_LOCKOUT);
                WM_SetCallback(hItem, buttonPush22_cb);
                break;
            case WM_NOTIFICATION_RELEASED:
                GUI_Delay(100);
                CreateKeyboardLockout();
                //state=46;
            }
            break;
        case ID_BUTTON_SCHEDULING_PERIODS:
            switch(NCode)
            {
            case WM_NOTIFICATION_CLICKED:
                hItem = WM_GetDialogItem(pMsg->hWin, ID_BUTTON_SCHEDULING_PERIODS);
                WM_SetCallback(hItem, buttonPush22_cb);
                break;
            case WM_NOTIFICATION_RELEASED:
                GUI_Delay(100);
                CreateSchedulePeriods();
                //state=47;
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
WM_HWIN CreatePreferences(void);
WM_HWIN CreatePreferences(void)
{
    WM_HWIN hWin;

    hWin = GUI_CreateDialogBox(_aDialogCreate, GUI_COUNTOF(_aDialogCreate), _cbDialog, WM_HBKWIN, 0, 0);
    return hWin;
}

/*************************** End of file ****************************/
