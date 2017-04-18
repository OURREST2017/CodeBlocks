#include "ranger.h"

#define ID_WINDOW_0 (GUI_ID_USER + 0x03)
#define ID_IMAGE_PEAR (GUI_ID_USER + 0x04)
#define ID_IMAGE_TIME_DATE (GUI_ID_USER + 0x05)
#define ID_IMAGE_LOCK (GUI_ID_USER + 0x06)
#define ID_IMAGE_SCHEDULE (GUI_ID_USER + 0x07)
#define ID_IMAGE_LANGAGES (GUI_ID_USER + 0x08)
#define ID_IMAGE_PROFILE (GUI_ID_USER + 0x09)
#define ID_IMAGE_PREFERENCES (GUI_ID_USER + 0x0A)
#define ID_IMAGE_SETUP (GUI_ID_USER + 0x0B)
#define ID_TEXT_TIME_DATE (GUI_ID_USER + 0x0C)
#define ID_TEXT_LOCK (GUI_ID_USER + 0x0D)
#define ID_TEXT_SCHEDULE (GUI_ID_USER + 0x0E)
#define ID_TEXT_LANGUAGES (GUI_ID_USER + 0x0F)
#define ID_TEXT_MOBILE_PAIR (GUI_ID_USER + 0x10)
#define ID_TEXT_PROFILE (GUI_ID_USER + 0x11)
#define ID_TEXT_PREFERENCES (GUI_ID_USER + 0x12)
#define ID_TEXT_SETUP (GUI_ID_USER + 0x13)
#define ID_IMAGE_RETURN (GUI_ID_USER + 0x15)
#define ID_TEXT_HEADER (GUI_ID_USER + 0x16)
#define ID_BUTTON_RETURN (GUI_ID_USER + 0x17)

static const GUI_WIDGET_CREATE_INFO _aDialogCreate[] =
{
    { WINDOW_CreateIndirect, "Window", ID_WINDOW_0, 0, 0, 480, 272, 0, 0x0, 0 },
    { TEXT_CreateIndirect, "SETTINGS", ID_TEXT_HEADER, 144, 9, 212, 33, 0, 0x64, 0 },
    { BUTTON_CreateIndirect, "", ID_BUTTON_RETURN, 15, 0, 150, 50, 0, 0x0, 0 },

    { IMAGE_CreateIndirect, "Image", ID_IMAGE_TIME_DATE, 28, 64, 70, 70, 0, 0, 0 },
    { IMAGE_CreateIndirect, "Image", ID_IMAGE_LOCK, 140, 64, 70, 70, 0, 0, 0 },
    { IMAGE_CreateIndirect, "Image", ID_IMAGE_SCHEDULE, 254, 62, 70, 70, 0, 0, 0 },
    { IMAGE_CreateIndirect, "Image", ID_IMAGE_LANGAGES, 375, 72, 70, 70, 0, 0, 0 },
    { IMAGE_CreateIndirect, "Image", ID_IMAGE_PEAR, 25, 167, 70, 70, 0, 0, 0 },
    { IMAGE_CreateIndirect, "Image", ID_IMAGE_PROFILE, 140, 174, 70, 70, 0, 0, 0 },
    { IMAGE_CreateIndirect, "Image", ID_IMAGE_PREFERENCES, 264, 168, 70, 70, 0, 0, 0 },
    { IMAGE_CreateIndirect, "Image", ID_IMAGE_SETUP, 374, 170, 70, 70, 0, 0, 0 },

    { TEXT_CreateIndirect, "Time/Date", ID_TEXT_TIME_DATE, 0, 128, 110, 20, 0, 0x64, 0 },
    { TEXT_CreateIndirect, "Lock", ID_TEXT_LOCK, 116, 128, 110, 20, 0, 0x64, 0 },
    { TEXT_CreateIndirect, "Schedule", ID_TEXT_SCHEDULE, 230, 128, 110, 20, 0, 0x64, 0 },
    { TEXT_CreateIndirect, "Languages", ID_TEXT_LANGUAGES, 355, 128, 110, 20, 0, 0x64, 0 },

    { TEXT_CreateIndirect, "Mobile Pair", ID_TEXT_MOBILE_PAIR, 6, 230, 110, 20, 0, 0x64, 0 },
    { TEXT_CreateIndirect, "Profile", ID_TEXT_PROFILE, 114, 230, 110, 20, 0, 0x64, 0 },
    { TEXT_CreateIndirect, "Preferences", ID_TEXT_PREFERENCES, 236, 230, 110, 20, 0, 0x64, 0 },
    { TEXT_CreateIndirect, "Setup", ID_TEXT_SETUP, 356, 230, 110, 20, 0, 0x64, 0 },
};

extern GUI_CONST_STORAGE GUI_BITMAP bmLockIcon ;
extern GUI_CONST_STORAGE GUI_BITMAP bmProfileIcon ;
extern GUI_CONST_STORAGE GUI_BITMAP bmTimeDateIcon;
extern GUI_CONST_STORAGE GUI_BITMAP bmSetupIcon;
extern GUI_CONST_STORAGE GUI_BITMAP bmScheduleIcon;
extern GUI_CONST_STORAGE GUI_BITMAP bmPairingIcon;
extern GUI_CONST_STORAGE GUI_BITMAP bmPreferenceIcon;
extern GUI_CONST_STORAGE GUI_BITMAP bmLanguagesIcon;

static void _cbDialog(WM_MESSAGE * pMsg)
{
    WM_HWIN      hItem;
    int          NCode;
    int          Id;

    switch (pMsg->MsgId)
    {
    case WM_PAINT:
        GUI_DrawGradientV(0, 0, 480, 50, color_map[0].stop, color_map[0].start);
        GUI_DrawBitmap(&bmwatermark, 10,52);

        GUI_DrawBitmap(&bmTimeDateIcon, 28, 62);
        GUI_DrawBitmap(&bmLockIcon, 144, 64);
        GUI_DrawBitmap(&bmScheduleIcon, 256, 62);
        GUI_DrawBitmap(&bmLanguagesIcon, 375, 72);
        GUI_DrawBitmap(&bmPairingIcon, 38, 167);
        GUI_DrawBitmap(&bmProfileIcon, 140, 174);
        GUI_DrawBitmap(&bmPreferenceIcon, 264, 168);
        GUI_DrawBitmap(&bmSetupIcon, 374, 170);
        break;
    case WM_INIT_DIALOG:
        hItem = WM_GetDialogItem(pMsg->hWin, ID_BUTTON_RETURN);
        BUTTON_SetSkin(hItem, returnSkin);

        hItem = WM_GetDialogItem(pMsg->hWin, ID_TEXT_HEADER);
        TEXT_SetFont(hItem, HEADER_FONT_BOLD);
        TEXT_SetTextAlign(hItem, GUI_TA_HCENTER | GUI_TA_VCENTER);
        TEXT_SetTextColor(hItem, GUI_WHITE);
        TEXT_SetText(hItem, LANG("SETTINGS"));
        //
        hItem = WM_GetDialogItem(pMsg->hWin, ID_TEXT_TIME_DATE);
        TEXT_SetFont(hItem, Tahoma18B);
        TEXT_SetTextColor(hItem, 0x808080);
        TEXT_SetTextAlign(hItem, GUI_TA_HCENTER | GUI_TA_VCENTER);
        TEXT_SetText(hItem, LANG("Time/Date"));
        //
        hItem = WM_GetDialogItem(pMsg->hWin, ID_TEXT_LOCK);
        TEXT_SetFont(hItem, Tahoma18B);
        TEXT_SetTextColor(hItem, 0x808080);
        TEXT_SetTextAlign(hItem, GUI_TA_HCENTER | GUI_TA_VCENTER);
        TEXT_SetText(hItem, LANG("Lock"));
        //
        hItem = WM_GetDialogItem(pMsg->hWin, ID_TEXT_SCHEDULE);
        TEXT_SetFont(hItem, Tahoma18B);
        TEXT_SetTextColor(hItem, 0x808080);
        TEXT_SetTextAlign(hItem, GUI_TA_HCENTER | GUI_TA_VCENTER);
        TEXT_SetText(hItem, LANG("Schedule"));
        //
        hItem = WM_GetDialogItem(pMsg->hWin, ID_TEXT_LANGUAGES);
        TEXT_SetTextAlign(hItem, GUI_TA_HCENTER | GUI_TA_VCENTER);
        TEXT_SetTextColor(hItem, 0x808080);
        TEXT_SetFont(hItem, Tahoma18B);
        TEXT_SetText(hItem, LANG("Languages"));
        //
        hItem = WM_GetDialogItem(pMsg->hWin, ID_TEXT_MOBILE_PAIR);
        TEXT_SetTextAlign(hItem, GUI_TA_HCENTER | GUI_TA_VCENTER);
        TEXT_SetFont(hItem, Tahoma18B);
        TEXT_SetTextColor(hItem, 0x808080);
        TEXT_SetText(hItem, LANG("Mobile Pair"));
       //
        hItem = WM_GetDialogItem(pMsg->hWin, ID_TEXT_PROFILE);
        TEXT_SetTextAlign(hItem, GUI_TA_HCENTER | GUI_TA_VCENTER);
        TEXT_SetTextColor(hItem, 0x808080);
        TEXT_SetFont(hItem, Tahoma18B);
        TEXT_SetText(hItem, LANG("Profile"));
        //
        hItem = WM_GetDialogItem(pMsg->hWin, ID_TEXT_PREFERENCES);
        TEXT_SetTextAlign(hItem, GUI_TA_HCENTER | GUI_TA_VCENTER);
        TEXT_SetTextColor(hItem, 0x808080);
        TEXT_SetFont(hItem, Tahoma18B);
        TEXT_SetText(hItem, LANG("Preferences"));
        //
        hItem = WM_GetDialogItem(pMsg->hWin, ID_TEXT_SETUP);
        TEXT_SetFont(hItem, Tahoma18B);
        TEXT_SetTextColor(hItem, 0x808080);
        TEXT_SetTextAlign(hItem, GUI_TA_HCENTER | GUI_TA_VCENTER);
        TEXT_SetText(hItem, LANG("Setup"));

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
                WM_HideWindow(settingsWin);
                screenState = HOMEWIN;
            }
            break;
        case ID_IMAGE_PEAR:
            switch(NCode)
            {
            case WM_NOTIFICATION_CLICKED:
                GUI_Delay(100);
                screenState = MOBILEPAREWIN;
            }
            break;
        case ID_IMAGE_TIME_DATE:
            switch(NCode)
            {
            case WM_NOTIFICATION_CLICKED:
                GUI_Delay(100);
                screenState = DATETIMEWIN;
            }
            break;
        case ID_IMAGE_LOCK:
            switch(NCode)
            {
            case WM_NOTIFICATION_CLICKED:
                GUI_Delay(100);
                screenState = LOCKWIN;
            }
            break;
        case ID_IMAGE_SCHEDULE:
            switch(NCode)
            {
            case WM_NOTIFICATION_CLICKED:
                WM_HideWindow(settingsWin);
                GUI_Delay(100);
                screenState = SETTINGSCHEDULEWIN;
            }
            break;
        case ID_IMAGE_LANGAGES:
            switch(NCode)
            {
            case WM_NOTIFICATION_CLICKED:
                GUI_Delay(100);
                screenState = LANGUAGESWIN;
            }
            break;
        case ID_IMAGE_PROFILE:
            switch(NCode)
            {
            case WM_NOTIFICATION_CLICKED:
                GUI_Delay(100);
                WM_HideWindow(settingsWin);
                screenState = PROFILEWIN;
            }
            break;
        case ID_IMAGE_PREFERENCES:
            switch(NCode)
            {
            case WM_NOTIFICATION_CLICKED:
                GUI_Delay(100);
                screenState = PREFERENCESWIN;
            }
            break;
        case ID_IMAGE_SETUP:
            switch(NCode)
            {
            case WM_NOTIFICATION_CLICKED:
                GUI_Delay(100);
                screenState = SYSTEMSETUPWIN;
            }
            break;
        }
        break;
    default:
        WM_DefaultProc(pMsg);
        break;
    }
}

WM_HWIN CreateSettings(void);
WM_HWIN CreateSettings(void)
{
    WM_HWIN hWin;

    hWin = GUI_CreateDialogBox(_aDialogCreate, GUI_COUNTOF(_aDialogCreate), _cbDialog, WM_HBKWIN, 0, 0);
    WM_HideWindow(hWin);
    return hWin;
}
