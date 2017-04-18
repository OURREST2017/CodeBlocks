#include "ranger.h"

#define ID_WINDOW_0 (GUI_ID_USER + 0x02)
#define ID_BUTTON_CANCEL (GUI_ID_USER + 0x05)
#define ID_BUTTON_SAVE (GUI_ID_USER + 0x06)
#define ID_TEXT_HEADER (GUI_ID_USER + 0x08)
#define ID_BUTTON_ENGLISH (GUI_ID_USER + 0x09)
#define ID_BUTTON_SPANISH (GUI_ID_USER + 0x0A)

static const GUI_WIDGET_CREATE_INFO _aDialogCreate[] =
{
    { WINDOW_CreateIndirect, "Window", ID_WINDOW_0, 0, 0, 480, 272, 0, 0x0, 0 },
    { TEXT_CreateIndirect, "LANGUAGES / IDIOMAS", ID_TEXT_HEADER, 0, 0, 480, 50, 0, 0x64, 0 },
    { BUTTON_CreateIndirect, "English", ID_BUTTON_ENGLISH, 140, 97, 200, 34, 0, 0x0, 0 },
    { BUTTON_CreateIndirect, "Español", ID_BUTTON_SPANISH, 140, 156, 200, 34, 0, 0x0, 0 },
    { BUTTON_CreateIndirect, "CANCEL", ID_BUTTON_CANCEL, 20, 230, BUT_WIDTH, BUT_HEIGHT, 0, 0x0, 0 },
    { BUTTON_CreateIndirect, "SAVE", ID_BUTTON_SAVE, 350, 230,BUT_WIDTH, BUT_HEIGHT, 0, 0x0, 0 },
};

static int eng_mode;
static WM_HWIN engButton, spaButton;

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
        //
        hItem = WM_GetDialogItem(pMsg->hWin, ID_TEXT_HEADER);
        TEXT_SetFont(hItem, HEADER_FONT_BOLD);
        TEXT_SetTextAlign(hItem, GUI_TA_HCENTER | GUI_TA_VCENTER);
        TEXT_SetTextColor(hItem, GUI_MAKE_COLOR(0x00FFFFFF));
        //
        engButton = WM_GetDialogItem(pMsg->hWin, ID_BUTTON_ENGLISH);
        //
        spaButton = WM_GetDialogItem(pMsg->hWin, ID_BUTTON_SPANISH);
        if (eng_mode)
        {
            WM_SetCallback(engButton, buttonOn22_cb);
            WM_SetCallback(spaButton, buttonOff22_cb);
        }
        else
        {
            WM_SetCallback(spaButton, buttonOn22_cb);
            WM_SetCallback(engButton, buttonOff22_cb);
        }

        hItem = WM_GetDialogItem(pMsg->hWin, ID_BUTTON_CANCEL);
        WM_SetCallback(hItem, buttonOn_cb);
        if (firstTime) WM_HideWin(hItem);
        //
        hItem = WM_GetDialogItem(pMsg->hWin, ID_BUTTON_SAVE);
        if (firstTime) BUTTON_SetText(hItem, LANG("NEXT"));
        WM_SetCallback(hItem, buttonOn_cb);
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
                WM_HideWindow(languagesWin);
                screenState = SETTINGSWIN;
                break;
            }
            break;
        case ID_BUTTON_SAVE:
            switch(NCode)
            {
            case WM_NOTIFICATION_RELEASED:
                GUI_Delay(100);
                if (eng_mode)
                {
                    strcpy(language, "english");
                }
                else
                {
                    strcpy(language, "spanish");
                }

                if (firstTime)
                {
                    WM_DeleteWindow(languagesWin);
                    CreateThermostatLocations();
                }
                else
                {
                    WM_HideWindow(languagesWin);

                    WM_MESSAGE msg;
                    msg.MsgId = WM_INIT_DIALOG;
                    WM_SendMessage(homeWin, &msg);
                    WM_MESSAGE msg1;
                    msg1.MsgId = WM_INIT_DIALOG;
                    WM_SendMessage(settingsWin, &msg1);
                    WM_MESSAGE msg2;
                    msg2.MsgId = WM_INIT_DIALOG;
                    WM_SendMessage(idleWin, &msg2);
                    WM_MESSAGE msg3;
                    msg3.MsgId = WM_INIT_DIALOG;
                    WM_SendMessage(settingsScheduleWin, &msg3);
                    WM_MESSAGE msg4;
                    msg4.MsgId = WM_INIT_DIALOG;
                    WM_SendMessage(screenLockoutWin, &msg4);
                    WM_MESSAGE msg5;
                    msg5.MsgId = WM_INIT_DIALOG;
                    WM_SendMessage(preferencesWin, &msg5);
                    WM_MESSAGE msg6;
                    msg6.MsgId = WM_INIT_DIALOG;
                    WM_SendMessage(systemSetupWin, &msg6);

                    screenState = SETTINGSWIN;
                }
                break;
            }
            break;
        case ID_BUTTON_ENGLISH:
            switch(NCode)
            {
            case WM_NOTIFICATION_RELEASED:
                eng_mode = 1;

                WM_SetCallback(engButton, buttonOn22_cb);
                WM_SetCallback(spaButton, buttonOff22_cb);
                strcpy(language, "english");
                hItem = WM_GetDialogItem(pMsg->hWin, ID_BUTTON_SAVE);
                WM_SetCallback(hItem, buttonOn_cb);
                hItem = WM_GetDialogItem(pMsg->hWin, ID_BUTTON_CANCEL);
                WM_SetCallback(hItem, buttonOn_cb);
                break;
            }
            break;
        case ID_BUTTON_SPANISH:
            switch(NCode)
            {
            case WM_NOTIFICATION_RELEASED:
                eng_mode = 0;

                WM_SetCallback(spaButton, buttonOn22_cb);
                WM_SetCallback(engButton, buttonOff22_cb);
                strcpy(language, "spanish");
                hItem = WM_GetDialogItem(pMsg->hWin, ID_BUTTON_SAVE);
                WM_SetCallback(hItem, buttonOn_cb);
                hItem = WM_GetDialogItem(pMsg->hWin, ID_BUTTON_CANCEL);
                WM_SetCallback(hItem, buttonOn_cb);
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

WM_HWIN CreateLanguages(void);
WM_HWIN CreateLanguages(void)
{
    WM_HWIN hWin;

    if (strcmp(language, "english") == 0)
    {
        eng_mode = 1;
    }
    else
    {
        eng_mode = 0;
    }
    languagesWin = GUI_CreateDialogBox(_aDialogCreate, GUI_COUNTOF(_aDialogCreate), _cbDialog, WM_HBKWIN, 0, 0);
    return hWin;
}
