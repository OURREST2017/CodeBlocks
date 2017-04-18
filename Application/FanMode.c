#include "ranger.h"

#define ID_WINDOW_0     (GUI_ID_USER + 0x0A)
#define ID_TEXT_HEADER     (GUI_ID_USER + 0x0C)
#define ID_BUTTON_AUTO     (GUI_ID_USER + 0x0D)
#define ID_BUTTON_ON     (GUI_ID_USER + 0x0E)
#define ID_BUTTON_CANCEL     (GUI_ID_USER + 0x0F)
#define ID_BUTTON_DONE     (GUI_ID_USER + 0x10)

static const GUI_WIDGET_CREATE_INFO _aDialogCreate[] =
{
    { WINDOW_CreateIndirect, "FAN", ID_WINDOW_0, 0, 0, 480, 272, 0, 0x0, 0 },
    { TEXT_CreateIndirect, "FAN MODE", ID_TEXT_HEADER, 0, 0, 480, 50, 0, 0x64, 0 },
    { BUTTON_CreateIndirect, "AUTO", ID_BUTTON_AUTO, 129, 130, BUT_WIDTH, BUT_HEIGHT, 0, 0x0, 0 },
    { BUTTON_CreateIndirect, "ON", ID_BUTTON_ON, 260, 130, BUT_WIDTH, BUT_HEIGHT, 0, 0x0, 0 },
    { BUTTON_CreateIndirect, "CANCEL", ID_BUTTON_CANCEL, 20, 225, BUT_WIDTH, BUT_HEIGHT, 0, 0x0, 0 },
    { BUTTON_CreateIndirect, "DONE", ID_BUTTON_DONE, 350, 225, BUT_WIDTH, BUT_HEIGHT, 0, 0x0, 0 },
};

static int auto_mode;
static WM_HWIN autoButton, onButton;

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
        TEXT_SetTextColor(hItem, 0x00FFFFFF);
        TEXT_SetText(hItem, LANG("FAN MODE"));
        //
        autoButton = WM_GetDialogItem(pMsg->hWin, ID_BUTTON_AUTO);
        //
        onButton = WM_GetDialogItem(pMsg->hWin, ID_BUTTON_ON);
        //
        if (auto_mode)
        {
            WM_SetCallback(autoButton, buttonOn22_cb);
            WM_SetCallback(onButton, buttonOff22_cb);
        }
        else
        {
            WM_SetCallback(onButton, buttonOn22_cb);
            WM_SetCallback(autoButton, buttonOff22_cb);
        }

        hItem = WM_GetDialogItem(pMsg->hWin, ID_BUTTON_CANCEL);
        WM_SetCallback(hItem, buttonOn_cb);
        //
        hItem = WM_GetDialogItem(pMsg->hWin, ID_BUTTON_DONE);
        WM_SetCallback(hItem, buttonOn_cb);
        break;
    case WM_NOTIFY_PARENT:
        Id    = WM_GetId(pMsg->hWinSrc);
        NCode = pMsg->Data.v;
        switch(Id)
        {
        case ID_BUTTON_AUTO:
            switch(NCode)
            {
            case WM_NOTIFICATION_RELEASED:
                auto_mode = 1;
                WM_SetCallback(onButton, buttonOff22_cb);
                WM_SetCallback(autoButton, buttonOn22_cb);
                break;
            }
            break;
        case ID_BUTTON_ON:
            switch(NCode)
            {
            case WM_NOTIFICATION_RELEASED:
                auto_mode = 0;
                WM_SetCallback(autoButton, buttonOff22_cb);
                WM_SetCallback(onButton, buttonOn22_cb);
                break;
            }
            break;
        case ID_BUTTON_CANCEL:
            switch(NCode)
            {
            case WM_NOTIFICATION_RELEASED:
                WM_HideWindow(fanModeWin);
                screenState = HOMEWIN;
                break;
            }
            break;
        case ID_BUTTON_DONE:
            switch(NCode)
            {
            case WM_NOTIFICATION_RELEASED:
                if (auto_mode)
                {
                    strcpy(fanMode, "auto");
               }
                else
                {
                    strcpy(fanMode, "on");
                }
                WM_HideWindow(fanModeWin);
                TEXT_SetText(fanModeText, toup(fanMode));
                screenState = HOMEWIN;
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

WM_HWIN CreateFanMode(void);
WM_HWIN CreateFanMode(void)
{
    WM_HWIN hWin;

    auto_mode = 0;
    if (strcmp(fanMode, "auto") == 0) auto_mode = 1;

    fanModeWin = GUI_CreateDialogBox(_aDialogCreate, GUI_COUNTOF(_aDialogCreate), _cbDialog, WM_HBKWIN, 0, 0);
    return hWin;
}
