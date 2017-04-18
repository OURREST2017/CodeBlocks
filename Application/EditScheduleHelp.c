#include "ranger.h"

#define ID_WINDOW_0 (GUI_ID_USER + 0x02)
#define ID_TEXT_HEADER (GUI_ID_USER + 0x08)
#define ID_BUTTON_CLOSE (GUI_ID_USER + 0x15)
#define ID_TEXT_1 (GUI_ID_USER + 0x17)
#define ID_TEXT_2 (GUI_ID_USER + 0x18)
#define ID_TEXT_3 (GUI_ID_USER + 0x19)

static const GUI_WIDGET_CREATE_INFO _aDialogCreate[] =
{
    { WINDOW_CreateIndirect, "Window", ID_WINDOW_0, 0, 0, 480, 272, 0, 0x0, 0 },
    { TEXT_CreateIndirect, "SCHEDULE HELP", ID_TEXT_HEADER, 0, 0, 480, 50, 0, 0x64, 0 },
    { TEXT_CreateIndirect, "Text", ID_TEXT_1, 0, 90, 480, 40, 0, 0x64, 0 },
    { TEXT_CreateIndirect, "Text", ID_TEXT_2, 0, 170, 480, 40, 0, 0x64, 0 },
    { BUTTON_CreateIndirect, "CLOSE", ID_BUTTON_CLOSE, 350, 230, BUT_WIDTH, BUT_HEIGHT, 0, 0x0, 0 },
};

static char edit_title[20], edit_sched[20];
static WM_HWIN wifiHelp;

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
        TEXT_SetTextColor(hItem, GUI_MAKE_COLOR(0xFFFFFF));
        TEXT_SetText(hItem, LANG("SCHEDULE HELP"));
        //
        hItem = WM_GetDialogItem(pMsg->hWin, ID_TEXT_1);
        TEXT_SetFont(hItem, Tahoma19B);
        TEXT_SetText(hItem, LANG("Press the PERIOD button to select desired \nscheduling period."));
        TEXT_SetTextAlign(hItem, GUI_TA_HCENTER | GUI_TA_VCENTER);
        TEXT_SetTextColor(hItem, GUI_MAKE_COLOR(0x808080));
        //
        hItem = WM_GetDialogItem(pMsg->hWin, ID_TEXT_2);
        TEXT_SetText(hItem, LANG("Press the START, STOP or TEMP buttons change\n current settings."));
        TEXT_SetFont(hItem, Tahoma19B);
        TEXT_SetTextAlign(hItem, GUI_TA_HCENTER | GUI_TA_VCENTER);
        TEXT_SetTextColor(hItem, GUI_MAKE_COLOR(0x808080));
        //
        hItem = WM_GetDialogItem(pMsg->hWin, ID_BUTTON_CLOSE);
        WM_SetCallback(hItem, buttonOn_cb);
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
                WM_SetCallback(hItem, buttonPush_cb);
                break;
            case WM_NOTIFICATION_RELEASED:
                WM_DeleteWindow(wifiHelp);
                GUI_Delay(100);
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

WM_HWIN CreateEditScheduleHelp(char *sched, char *day);
WM_HWIN CreateEditScheduleHelp(char *sched, char *day)
{
    WM_HWIN hWin;
    strcpy(edit_title, day);
    strcpy(edit_sched, sched);

    wifiHelp = GUI_CreateDialogBox(_aDialogCreate, GUI_COUNTOF(_aDialogCreate), _cbDialog, WM_HBKWIN, 0, 0);
    return hWin;
}
