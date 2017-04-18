#include "ranger.h"

#define ID_WINDOW_0 (GUI_ID_USER + 0x02)
#define ID_HEADER_0 (GUI_ID_USER + 0x07)
#define ID_TEXT_HEADER (GUI_ID_USER + 0x08)
#define ID_BUTTON_TEMPERATURE_SCALE (GUI_ID_USER + 0x0F)
#define ID_BUTTON_SYSTEM_CHANGE_OVER (GUI_ID_USER + 0x12)
#define ID_BUTTON_TEMPERATURE_LIMITS (GUI_ID_USER + 0x13)
#define ID_BUTTON_KEYBOARD_LOCKOUT (GUI_ID_USER + 0x14)
#define ID_TEXT_RETURN (GUI_ID_USER + 0x16)
#define ID_BUTTON_NEXT (GUI_ID_USER + 0x17)
#define ID_BUTTON_BACK (GUI_ID_USER + 0x18)

#define BUT_X 66
#define BUT_HEIGHT 34
#define BUT_WIDTH 350
#define BUT_SPACING 40
#define BUTTON_Y_OFFSET 65

#define BUTTON_Y_POS(x)  BUTTON_Y_OFFSET + (x * BUT_SPACING)

static const GUI_WIDGET_CREATE_INFO _aDialogCreate[] =
{
    { WINDOW_CreateIndirect, "Window", ID_WINDOW_0, 0, 0, 480, 272, 0, 0x0, 0 },
    { TEXT_CreateIndirect,   "PREFERENCES", ID_TEXT_HEADER, 0, 0, 480, 50, 0, 0x64, 0 },
    { BUTTON_CreateIndirect, "Keyboard Lockout", ID_BUTTON_KEYBOARD_LOCKOUT, BUT_X,  BUTTON_Y_POS(0), BUT_WIDTH, BUT_HEIGHT, 0, 0x0, 0 },
    { BUTTON_CreateIndirect, "Temperature Scale", ID_BUTTON_TEMPERATURE_SCALE, BUT_X,  BUTTON_Y_POS(1), BUT_WIDTH, BUT_HEIGHT, 0, 0x0, 0 },
    { BUTTON_CreateIndirect, "System Change Over", ID_BUTTON_SYSTEM_CHANGE_OVER, BUT_X,  BUTTON_Y_POS(2), BUT_WIDTH, BUT_HEIGHT, 0, 0x0, 0 },
    { BUTTON_CreateIndirect, "Temperature Limits", ID_BUTTON_TEMPERATURE_LIMITS, BUT_X,  BUTTON_Y_POS(3), BUT_WIDTH, BUT_HEIGHT, 0, 0x0, 0 },
    { BUTTON_CreateIndirect, "", ID_TEXT_RETURN, 15, 0, 150, 50, 0, 0x0, 0 },
};

static int page_number;
static WM_HWIN win1,win2,win3, win4, win5, win6, win7, next, back;

static void showWindows()
{
    if (page_number == 1)
    {
        WM_HideWindow(win5);
        WM_HideWindow(win6);
        WM_HideWindow(win7);
        WM_ShowWindow(win1);
        WM_ShowWindow(win2);
        WM_ShowWindow(win3);
        WM_ShowWindow(win4);
        WM_HideWindow(back);
        WM_ShowWindow(next);
    }
    else
    {
        WM_HideWindow(win1);
        WM_HideWindow(win2);
        WM_HideWindow(win3);
        WM_HideWindow(win4);
        WM_ShowWindow(win5);
        WM_ShowWindow(win6);
        WM_ShowWindow(win7);
        WM_HideWindow(next);
        WM_ShowWindow(back);
    }
}

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
        hItem = WM_GetDialogItem(pMsg->hWin, ID_TEXT_RETURN);
        BUTTON_SetSkin(hItem, returnSkin);

        hItem = WM_GetDialogItem(pMsg->hWin, ID_TEXT_HEADER);
        TEXT_SetFont(hItem, HEADER_FONT_BOLD);
        TEXT_SetTextAlign(hItem, GUI_TA_HCENTER | GUI_TA_VCENTER);
        TEXT_SetTextColor(hItem, GUI_MAKE_COLOR(0x00FFFFFF));
        TEXT_SetText(hItem, LANG("PREFERENCES"));
        //
        win1 = WM_GetDialogItem(pMsg->hWin, ID_BUTTON_TEMPERATURE_SCALE);
        WM_SetCallback(win1, button22_cb);
        //
        win2 = WM_GetDialogItem(pMsg->hWin, ID_BUTTON_SYSTEM_CHANGE_OVER);
        WM_SetCallback(win2, button22_cb);
        //
        win3 = WM_GetDialogItem(pMsg->hWin, ID_BUTTON_TEMPERATURE_LIMITS);
        WM_SetCallback(win3, button22_cb);
        //
        win4 = WM_GetDialogItem(pMsg->hWin, ID_BUTTON_KEYBOARD_LOCKOUT);
        WM_SetCallback(win4, button22_cb);

        break;
    case WM_NOTIFY_PARENT:
        Id    = WM_GetId(pMsg->hWinSrc);
        NCode = pMsg->Data.v;
        switch(Id)
        {
        case ID_TEXT_RETURN:
            switch(NCode)
            {
            case WM_NOTIFICATION_RELEASED:
                GUI_Delay(100);
                WM_HideWindow(preferencesWin);
                screenState = SETTINGSWIN;
            }
            break;
        case ID_BUTTON_TEMPERATURE_SCALE:
            switch(NCode)
            {
            case WM_NOTIFICATION_CLICKED:
                hItem = WM_GetDialogItem(pMsg->hWin, ID_BUTTON_TEMPERATURE_SCALE);
                WM_SetCallback(hItem, buttonPush22_cb);
                break;
            case WM_NOTIFICATION_RELEASED:
                GUI_Delay(100);
                CreateTemperatureScale();
                //state=41;
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
        case ID_BUTTON_TEMPERATURE_LIMITS:
            switch(NCode)
            {
            case WM_NOTIFICATION_CLICKED:
                hItem = WM_GetDialogItem(pMsg->hWin, ID_BUTTON_TEMPERATURE_LIMITS);
                WM_SetCallback(hItem, buttonPush22_cb);
                break;
            case WM_NOTIFICATION_RELEASED:
                GUI_Delay(100);
                CreateTemperatureLimits(0);
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
        }
        break;
    default:
        WM_DefaultProc(pMsg);
        break;
    }
}

WM_HWIN CreatePreferences(void);
WM_HWIN CreatePreferences(void)
{
    WM_HWIN hWin;

    page_number = 1;

    hWin = GUI_CreateDialogBox(_aDialogCreate, GUI_COUNTOF(_aDialogCreate), _cbDialog, WM_HBKWIN, 0, 0);
    WM_HideWindow(hWin);
    return hWin;
}
