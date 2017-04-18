#include "ranger.h"

#define ID_WINDOW_0 (GUI_ID_USER + 0x02)
#define ID_BUTTON_CANCEL (GUI_ID_USER + 0x05)
#define ID_BUTTON_SAVE (GUI_ID_USER + 0x06)
#define ID_TEXT_HEADER (GUI_ID_USER + 0x08)
#define ID_TEXT_UPPER (GUI_ID_USER + 0x09)
#define ID_TEXT_LOWER (GUI_ID_USER + 0x0A)
#define ID_BUTTON_COOL_TO_UP  (GUI_ID_USER + 0x0B)
#define ID_BUTTON_COOL_TO_DN  (GUI_ID_USER + 0x0C)
#define ID_BUTTON_HEAT_TO_UP  (GUI_ID_USER + 0x0D)
#define ID_BUTTON_HEAT_TO_DN  (GUI_ID_USER + 0x0E)
#define ID_TEXT_COOL_TO  (GUI_ID_USER + 0x10)
#define ID_TEXT_HEAT_TO  (GUI_ID_USER + 0x11)

static const GUI_WIDGET_CREATE_INFO _aDialogCreate[] =
{
    { WINDOW_CreateIndirect, "Window", ID_WINDOW_0, 0, 0, 480, 272, 0, 0x0, 0 },
    { TEXT_CreateIndirect, "AUTO TEMPERATURE SETTINGS", ID_TEXT_HEADER, 0, 0, 480, 50, 0, 0x64, 0 },
    { TEXT_CreateIndirect, "COOL\nTO", ID_TEXT_LOWER, 354, 110, 100, 80, 0, 0x64, 0 },
    { TEXT_CreateIndirect, "HEAT\nTO", ID_TEXT_UPPER, 38, 110, 70, 80, 0, 0x64, 0 },
    { BUTTON_CreateIndirect, "Button", ID_BUTTON_HEAT_TO_UP, 150, 62, 60, 60, 0, 0x0, 0 },
    { BUTTON_CreateIndirect, "Button", ID_BUTTON_HEAT_TO_DN, 150, 194, 60, 60, 0, 0x0, 0 },
    { BUTTON_CreateIndirect, "Button", ID_BUTTON_COOL_TO_UP, 290, 62, 60, 60, 0, 0x0, 0 },
    { BUTTON_CreateIndirect, "Button", ID_BUTTON_COOL_TO_DN, 290, 194, 60, 60, 0, 0x0, 0 },
    { TEXT_CreateIndirect, "", ID_TEXT_HEAT_TO, 123, 110, 105, 80, 0, 0x64, 0 },
    { TEXT_CreateIndirect, "", ID_TEXT_COOL_TO, 263, 110, 105, 80, 0, 0x64, 0 },

    { BUTTON_CreateIndirect, "CANCEL", ID_BUTTON_CANCEL, 20, 230, BUT_WIDTH, BUT_HEIGHT, 0, 0x0, 0 },
    { BUTTON_CreateIndirect, "SAVE", ID_BUTTON_SAVE, 350, 230,BUT_WIDTH, BUT_HEIGHT, 0, 0x0, 0 },
};

static int cool_to, heat_to, fromHome;

extern GUI_CONST_STORAGE GUI_BITMAP bmbut_up_blue;
extern GUI_CONST_STORAGE GUI_BITMAP bmbut_dn_blue;
extern GUI_CONST_STORAGE GUI_BITMAP bmbut_up_red;
extern GUI_CONST_STORAGE GUI_BITMAP bmbut_dn_red;
extern char *convertTemp(float temp_set);
extern GUI_CONST_STORAGE GUI_FONT GUI_FontTahoma81hAA4B;

static void up_heat(WM_MESSAGE * pMsg)
{
    switch (pMsg->MsgId)
    {
    case WM_PAINT:
        if (BUTTON_IsPressed(pMsg->hWin))
        {
            GUI_DrawBitmap(&bmbut_up_red, 0, 0);
        }
        else
        {
            GUI_DrawBitmap(&bmbut_up_red, 0, 0);
        }
        break;
    default:
        BUTTON_Callback(pMsg);
        break;
    }
}

static void dn_heat(WM_MESSAGE * pMsg)
{
    switch (pMsg->MsgId)
    {
    case WM_PAINT:
        if (BUTTON_IsPressed(pMsg->hWin))
        {
            GUI_DrawBitmap(&bmbut_dn_red, 0, 0);
        }
        else
        {
            GUI_DrawBitmap(&bmbut_dn_red, 0, 0);
        }
        break;
    default:
        BUTTON_Callback(pMsg);
        break;
    }
}
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

static void text_box_cb(WM_MESSAGE * pMsg)
{
    char buf[50];
    GUI_RECT rt;
    WM_GetClientRect(&rt);
    switch (pMsg->MsgId)
    {
    case WM_PAINT:
        GUI_SetColor(0xeaeaea);
        GUI_AA_FillRoundedRect(0,0,rt.x1,rt.y1,10);
        GUI_SetColor(0x808080);
        GUI_SetPenSize(2);
        GUI_AA_DrawRoundedRect(0,0,rt.x1,rt.y1,10);
        TEXT_GetText(pMsg->hWin, buf, 10);

        GUI_SetColor(GUI_BLACK);
        GUI_SetTextMode(GUI_TEXTMODE_TRANS);
        GUI_SetFont(&GUI_FontTahoma81hAA4B);
        GUI_DispStringInRect(buf, &rt, GUI_TA_HCENTER | GUI_TA_VCENTER);
        break;
    default:
        TEXT_Callback(pMsg);
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
        TEXT_SetFont(hItem, &GUI_FontTahoma29hAA4B);
        TEXT_SetTextAlign(hItem, GUI_TA_HCENTER | GUI_TA_VCENTER);
        TEXT_SetTextColor(hItem, GUI_MAKE_COLOR(0x00FFFFFF));
        TEXT_SetText(hItem, LANG("AUTO TEMPERATURE SETTINGS"));

        hItem = WM_GetDialogItem(pMsg->hWin, ID_TEXT_UPPER);
        TEXT_SetTextColor(hItem, 0x4343bf);
        TEXT_SetTextAlign(hItem, GUI_TA_HCENTER | GUI_TA_VCENTER);
        TEXT_SetFont(hItem, Tahoma23B);
        TEXT_SetText(hItem, LANG("HEAT\nTO"));
        if (metric)
        {
            WM_MoveTo(hItem, 0, 110);
        }
        else
        {
            WM_MoveTo(hItem, 48, 110);
        }

        hItem = WM_GetDialogItem(pMsg->hWin, ID_TEXT_LOWER);
        TEXT_SetTextColor(hItem, 0x7a5114);
        TEXT_SetTextAlign(hItem, GUI_TA_HCENTER | GUI_TA_VCENTER);
        TEXT_SetFont(hItem, Tahoma23B);
        TEXT_SetText(hItem, LANG("COOL\nTO"));
        if (metric)
        {
            WM_MoveTo(hItem, 391, 110);
        }
        else
        {
            WM_MoveTo(hItem, 354, 110);
        }

        //
        hItem = WM_GetDialogItem(pMsg->hWin, ID_BUTTON_HEAT_TO_UP);
        WM_SetCallback(hItem, up_heat);
        if (metric)
        {
            WM_MoveTo(hItem, 140, 62);
        }
        else
        {
            WM_MoveTo(hItem, 150, 62);
        }
        //
        hItem = WM_GetDialogItem(pMsg->hWin, ID_BUTTON_HEAT_TO_DN);
        WM_SetCallback(hItem, dn_heat);
        if (metric)
        {
            WM_MoveTo(hItem, 140, 194);
        }
        else
        {
            WM_MoveTo(hItem, 150, 194);
        }
        //
        hItem = WM_GetDialogItem(pMsg->hWin, ID_BUTTON_COOL_TO_UP);
        WM_SetCallback(hItem, up_cool);
        if (metric)
        {
            WM_MoveTo(hItem, 280, 62);
        }
        else
        {
            WM_MoveTo(hItem, 290, 62);
        }
        //
        hItem = WM_GetDialogItem(pMsg->hWin, ID_BUTTON_COOL_TO_DN);
        WM_SetCallback(hItem, dn_cool);
        if (metric)
        {
            WM_MoveTo(hItem, 280, 194);
        }
        else
        {
            WM_MoveTo(hItem, 290, 194);
        }
        //
        hItem = WM_GetDialogItem(pMsg->hWin, ID_TEXT_HEAT_TO);
        TEXT_SetText(hItem, convertTemp(heat_to));
        WM_SetCallback(hItem, text_box_cb);
        if (metric)
        {
            WM_SetSize(hItem, 170, 80);
            WM_MoveTo(hItem, 65, 110);
        }
        else
        {
            WM_SetSize(hItem, 105, 80);
            WM_MoveTo(hItem, 123, 110);
        }
        //
        hItem = WM_GetDialogItem(pMsg->hWin, ID_TEXT_COOL_TO);
        TEXT_SetText(hItem, convertTemp(cool_to));
        WM_SetCallback(hItem, text_box_cb);
        if (metric)
        {
            WM_SetSize(hItem, 170, 80);
            WM_MoveTo(hItem, 240, 110);
        }
        else
        {
            WM_SetSize(hItem, 105, 80);
            WM_MoveTo(hItem, 263, 110);
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
        case ID_BUTTON_HEAT_TO_UP:
            switch(NCode)
            {
            case WM_NOTIFICATION_RELEASED:
                heat_to++;
                if (heat_to == 83) heat_to = 82;
                if (cool_to - heat_to == 2)
                {
                    cool_to++;
                    hItem = WM_GetDialogItem(pMsg->hWin, ID_TEXT_COOL_TO);
                    TEXT_SetText(hItem, convertTemp(cool_to));
                }
                hItem = WM_GetDialogItem(pMsg->hWin, ID_TEXT_HEAT_TO);
                TEXT_SetText(hItem, convertTemp(heat_to));
                break;
            }
            break;
        case ID_BUTTON_HEAT_TO_DN:
            switch(NCode)
            {
            case WM_NOTIFICATION_RELEASED:
                heat_to--;
                if (heat_to == 64) heat_to = 65;
                hItem = WM_GetDialogItem(pMsg->hWin, ID_TEXT_HEAT_TO);
                TEXT_SetText(hItem, convertTemp(heat_to));
                break;
            }
            break;
        case ID_BUTTON_COOL_TO_UP:
            switch(NCode)
            {
            case WM_NOTIFICATION_RELEASED:
                cool_to++;
                if (cool_to == 86) cool_to = 85;
                hItem = WM_GetDialogItem(pMsg->hWin, ID_TEXT_COOL_TO);
                TEXT_SetText(hItem, convertTemp(cool_to));
                break;
            }
            break;
        case ID_BUTTON_COOL_TO_DN:
            switch(NCode)
            {
            case WM_NOTIFICATION_RELEASED:
                cool_to--;
                if (cool_to == 67) cool_to = 68;
                if (cool_to - heat_to == 2)
                {
                    heat_to--;
                    hItem = WM_GetDialogItem(pMsg->hWin, ID_TEXT_HEAT_TO);
                    TEXT_SetText(hItem, convertTemp(heat_to));
                }
                hItem = WM_GetDialogItem(pMsg->hWin, ID_TEXT_COOL_TO);
                TEXT_SetText(hItem, convertTemp(cool_to));
                break;
            }
            break;
        case ID_BUTTON_CANCEL:
            switch(NCode)
            {
            case WM_NOTIFICATION_RELEASED:
                WM_DeleteWindow(temperatureLimitsWin);
                GUI_Delay(100);
                if (fromHome)
                {
                    screenState = HOMEWIN;
                }
                else
                {
                    screenState = PREFERENCESWIN;
                }
                break;
            }
            break;
        case ID_BUTTON_SAVE:
            switch(NCode)
            {
            case WM_NOTIFICATION_RELEASED:
                coolToDegrees = cool_to;
                heatToDegrees = heat_to;
                WM_DeleteWindow(temperatureLimitsWin);
                sprintf(buf, "%s°", convertTemp(coolToDegrees));
                TEXT_SetText(coolToText, buf);
                sprintf(buf, "%s°", convertTemp(heatToDegrees));
                TEXT_SetText(heatToText, buf);

                WM_MESSAGE msg;
                msg.MsgId = WM_INIT_DIALOG;
                WM_SendMessage(homeWin, &msg);
                GUI_Delay(100);
                if (fromHome)
                {
                    screenState = HOMEWIN;
                }
                else
                {
                    screenState = PREFERENCESWIN;
                }

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

WM_HWIN CreateTemperatureLimits(int home);
WM_HWIN CreateTemperatureLimits(int home)
{
    WM_HWIN hWin;
    fromHome = home;
    cool_to = coolToDegrees;
    heat_to = heatToDegrees;
    temperatureLimitsWin = GUI_CreateDialogBox(_aDialogCreate, GUI_COUNTOF(_aDialogCreate), _cbDialog, WM_HBKWIN, 0, 0);
    return hWin;
}
