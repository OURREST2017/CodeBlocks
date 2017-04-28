#include "ranger.h"

#define ID_WINDOW_0 (GUI_ID_USER + 0x02)
#define ID_BUTTON_CANCEL (GUI_ID_USER + 0x05)
#define ID_BUTTON_SAVE (GUI_ID_USER + 0x06)
#define ID_TEXT_HEADER (GUI_ID_USER + 0x08)
#define ID_TEXT_HEATTO (GUI_ID_USER + 0x09)
#define ID_TEXT_COOLTO (GUI_ID_USER + 0x0A)
#define ID_BUTTON_UP  (GUI_ID_USER + 0x0B)
#define ID_BUTTON_DN  (GUI_ID_USER + 0x0C)
#define ID_BUTTON_UPPER_UP  (GUI_ID_USER + 0x0D)
#define ID_BUTTON_UPPER_DN  (GUI_ID_USER + 0x0E)
#define ID_TEXT_COOLTO_TXT  (GUI_ID_USER + 0x10)
#define ID_TEXT_HEATO_TXT  (GUI_ID_USER + 0x11)

static const GUI_WIDGET_CREATE_INFO _aDialogCreate[] =
{
    { WINDOW_CreateIndirect, "Window", ID_WINDOW_0, 0, 0, 480, 272, 0, 0x0, 0 },
    { TEXT_CreateIndirect, "COOL TO SETTINGS", ID_TEXT_HEADER, 0, 0, 480, 50, 0, 0x64, 0 },
    { TEXT_CreateIndirect, "COOL\nTO", ID_TEXT_COOLTO, 105, 110, 100, 80, 0, 0x64, 0 },
    { BUTTON_CreateIndirect, "Button", ID_BUTTON_UP, 217, 66, 60, 60, 0, 0x0, 0 },
    { BUTTON_CreateIndirect, "Button", ID_BUTTON_DN, 217, 192, 60, 60, 0, 0x0, 0 },
    { TEXT_CreateIndirect, "", ID_TEXT_COOLTO_TXT, 190, 110, 170, 80, 0, 0x64, 0 },

    { BUTTON_CreateIndirect, "CANCEL", ID_BUTTON_CANCEL, 20, 230, BUT_WIDTH, BUT_HEIGHT, 0, 0x0, 0 },
    { BUTTON_CreateIndirect, "SAVE", ID_BUTTON_SAVE, 350, 230,BUT_WIDTH, BUT_HEIGHT, 0, 0x0, 0 },
};

static float cool_to;

extern GUI_CONST_STORAGE GUI_BITMAP bmbut_up_blue;
extern GUI_CONST_STORAGE GUI_BITMAP bmbut_dn_blue;
extern char *convertTemp(float temp_set);
extern void text_box_cb(WM_MESSAGE * pMsg);

static void up_cool(WM_MESSAGE * pMsg)
{
    switch (pMsg->MsgId)
    {
    case WM_PAINT:
        if (BUTTON_IsPressed(pMsg->hWin))
        {
            GUI_DrawBitmap(&bmbut_up_blue, 0, 0);
        }
        else
        {
            GUI_DrawBitmap(&bmbut_up_blue, 0, 0);
        }
        break;
    default:
        BUTTON_Callback(pMsg);
        break;
    }
}

static void dn_cool(WM_MESSAGE * pMsg)
{
    switch (pMsg->MsgId)
    {
    case WM_PAINT:
        if (BUTTON_IsPressed(pMsg->hWin))
        {
            GUI_DrawBitmap(&bmbut_dn_blue, 0, 0);
        }
        else
        {
            GUI_DrawBitmap(&bmbut_dn_blue, 0, 0);
        }
        break;
    default:
        BUTTON_Callback(pMsg);
        break;
    }
}

static void _cbDialog(WM_MESSAGE * pMsg)
{
    WM_HWIN hItem, spinWheel;
    int     NCode;
    int     Id;
    char buf[10];
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
        TEXT_SetText(hItem, LANG("COOL TO SETTINGS"));

        hItem = WM_GetDialogItem(pMsg->hWin, ID_TEXT_COOLTO);
        TEXT_SetTextColor(hItem, 0x7a5114);
        TEXT_SetTextAlign(hItem, GUI_TA_HCENTER | GUI_TA_VCENTER);
        TEXT_SetFont(hItem, Tahoma23B);
        TEXT_SetText(hItem, LANG("COOL\nTO"));
        if (metric) {
            WM_MoveTo(hItem, 65, 110);
        } else {
            WM_MoveTo(hItem, 105, 110);
        }

        hItem = WM_GetDialogItem(pMsg->hWin, ID_BUTTON_UP);
        WM_SetCallback(hItem, up_cool);
        if (metric) {
            WM_MoveTo(hItem, 215, 66);
        } else {
            WM_MoveTo(hItem, 217, 66);
        }
        //
        hItem = WM_GetDialogItem(pMsg->hWin, ID_BUTTON_DN);
        WM_SetCallback(hItem, dn_cool);
        if (metric) {
            WM_MoveTo(hItem, 215, 191);
        } else {
            WM_MoveTo(hItem, 217, 191);
        }
        //
        hItem = WM_GetDialogItem(pMsg->hWin, ID_TEXT_COOLTO_TXT);
        TEXT_SetText(hItem, convertTemp(cool_to));
        WM_SetCallback(hItem, text_box_cb);
        if (metric) {
            WM_SetSize(hItem, 170, 80);
            WM_MoveTo(hItem, 150, 110);
        } else {
            WM_SetSize(hItem, 105, 80);
            WM_MoveTo(hItem, 190, 110);
        }

        //
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
        case ID_BUTTON_UP:
            switch(NCode)
            {
            case WM_NOTIFICATION_RELEASED:
                cool_to++;
                if (cool_to == 86) cool_to = 85;
                hItem = WM_GetDialogItem(pMsg->hWin, ID_TEXT_COOLTO_TXT);
                TEXT_SetText(hItem, convertTemp(cool_to));
                break;
            }
            break;
        case ID_BUTTON_DN:
            switch(NCode)
            {
            case WM_NOTIFICATION_RELEASED:
                cool_to--;
                if (cool_to == 64) cool_to = 65;
                if (cool_to < heatToDegrees+3) cool_to = heatToDegrees+3;
                hItem = WM_GetDialogItem(pMsg->hWin, ID_TEXT_COOLTO_TXT);
                TEXT_SetText(hItem, convertTemp(cool_to));
                break;
            }
            break;
        case ID_BUTTON_CANCEL:
            switch(NCode)
            {
            case WM_NOTIFICATION_RELEASED:
                GUI_Delay(100);
                WM_HideWindow(coolToWin);
                screenState = HOMEWIN;
                break;
            }
            break;
        case ID_BUTTON_SAVE:
            switch(NCode)
            {
            case WM_NOTIFICATION_RELEASED:
                coolToDegrees = cool_to;
                GUI_Delay(100);
                WM_HideWindow(coolToWin);
                WM_MESSAGE msg;
                msg.MsgId = WM_INIT_DIALOG;
                WM_SendMessage(homeWin, &msg);
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
WM_HWIN CreateCoolTo(void);
WM_HWIN CreateCoolTo(void)
{
    WM_HWIN hWin;

    cool_to = coolToDegrees;
    coolToWin = GUI_CreateDialogBox(_aDialogCreate, GUI_COUNTOF(_aDialogCreate), _cbDialog, WM_HBKWIN, 0, 0);
    return hWin;
}

