#include "ranger.h"

#define ID_WINDOW_0 (GUI_ID_USER + 0x02)
#define ID_BUTTON_CANCEL (GUI_ID_USER + 0x05)
#define ID_BUTTON_SAVE (GUI_ID_USER + 0x06)
#define ID_TEXT_HEADER (GUI_ID_USER + 0x08)
#define ID_BUTTON_MANUAL (GUI_ID_USER + 0x0E)
#define ID_BUTTON_AUTOMATIC (GUI_ID_USER + 0x0F)

static const GUI_WIDGET_CREATE_INFO _aDialogCreate[] =
{
    { WINDOW_CreateIndirect, "Window", ID_WINDOW_0, 0, 0, 480, 272, 0, 0x0, 0 },
    { TEXT_CreateIndirect, "SYSTEMS CHANGE OVER", ID_TEXT_HEADER, 0, 0, 480, 50, 0, 0x64, 0 },
    { BUTTON_CreateIndirect, "Manual", ID_BUTTON_MANUAL, 120, 90, 240, 40, 0, 0x0, 0 },
    { BUTTON_CreateIndirect, "Automatic", ID_BUTTON_AUTOMATIC, 120, 145, 240, 40, 0, 0x0, 0 },
    { BUTTON_CreateIndirect, "CANCEL", ID_BUTTON_CANCEL, 20, 230, BUT_WIDTH, BUT_HEIGHT, 0, 0x0, 0 },
    { BUTTON_CreateIndirect, "SAVE", ID_BUTTON_SAVE, 350, 230,BUT_WIDTH, BUT_HEIGHT, 0, 0x0, 0 },
};

static int manual_mode;
static WM_HWIN manualButton, autoButton, systemChangeOverWin;

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
        TEXT_SetText(hItem, LANG("SYSTEMS CHANGE OVER"));
        //
        manualButton = WM_GetDialogItem(pMsg->hWin, ID_BUTTON_MANUAL);
        //
        autoButton = WM_GetDialogItem(pMsg->hWin, ID_BUTTON_AUTOMATIC);

        if (manual_mode)
        {
            WM_SetCallback(manualButton, buttonOn22_cb);
            WM_SetCallback(autoButton, buttonOff22_cb);
        }
        else
        {
            WM_SetCallback(autoButton, buttonOn22_cb);
            WM_SetCallback(manualButton, buttonOff22_cb);
        }

        hItem = WM_GetDialogItem(pMsg->hWin, ID_BUTTON_CANCEL);
        WM_SetCallback(hItem, buttonOn_cb);
        //
        hItem = WM_GetDialogItem(pMsg->hWin, ID_BUTTON_SAVE);
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
                WM_DeleteWindow(systemChangeOverWin);
                GUI_Delay(100);
                screenState = PREFERENCESWIN;
                break;
            }
            break;
        case ID_BUTTON_SAVE:
            switch(NCode)
            {
            case WM_NOTIFICATION_RELEASED:
                if (manual_mode)
                {
                    strcpy(systemsChangeOver, "manual");
                }
                else
                {
                    strcpy(systemsChangeOver, "automatic");
                }
                WM_DeleteWindow(systemChangeOverWin);
                GUI_Delay(100);
                screenState = PREFERENCESWIN;
                break;
            }
            break;
        case ID_BUTTON_MANUAL:
            switch(NCode)
            {
            case WM_NOTIFICATION_RELEASED:
                manual_mode = 1;
                WM_SetCallback(manualButton, buttonOn22_cb);
                WM_SetCallback(autoButton, buttonOff22_cb);
                break;
            }
            break;
        case ID_BUTTON_AUTOMATIC:
            switch(NCode)
            {
            case WM_NOTIFICATION_RELEASED:
                manual_mode = 0;
                WM_SetCallback(autoButton, buttonOn22_cb);
                WM_SetCallback(manualButton, buttonOff22_cb);
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

WM_HWIN CreateSystemsChangeOver(void);
WM_HWIN CreateSystemsChangeOver(void)
{
    WM_HWIN hWin;

    if (strcmp(systemsChangeOver, "manual") == 0)
    {
        manual_mode = 1;
    }
    else
    {
        manual_mode = 0;
    }

    systemChangeOverWin = GUI_CreateDialogBox(_aDialogCreate, GUI_COUNTOF(_aDialogCreate), _cbDialog, WM_HBKWIN, 0, 0);
    return hWin;
}
