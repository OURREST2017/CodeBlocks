#include "ranger.h"

#define ID_WINDOW_0  (GUI_ID_USER + 0x00)
#define ID_TEXT_HEADER  (GUI_ID_USER + 0x02)
#define ID_TEXT_1  (GUI_ID_USER + 0x03)
#define ID_TEXT_2  (GUI_ID_USER + 0x04)
#define ID_TEXT_3  (GUI_ID_USER + 0x05)
#define ID_TEXT_4  (GUI_ID_USER + 0x06)
#define ID_BUTTON_CUSTOMER  (GUI_ID_USER + 0x07)
#define ID_BUTTON_ZIP  (GUI_ID_USER + 0x08)
#define ID_BUTTON_MAC  (GUI_ID_USER + 0x09)
#define ID_BUTTON_CRC  (GUI_ID_USER + 0x0A)
#define ID_BUTTON_CANCEL  (GUI_ID_USER + 0x0B)
#define ID_BUTTON_SAVE  (GUI_ID_USER + 0x0C)

static char customer_text[30], mac_text[30], zip_text[12], crc_text[10];

static const GUI_WIDGET_CREATE_INFO _aDialogCreate[] =
{
    { WINDOW_CreateIndirect, "Window", ID_WINDOW_0, 0, 0, 480, 272, 0, 0x0, 0 },
    { TEXT_CreateIndirect, "PROFILE", ID_TEXT_HEADER, 0, 0, 480, 50, 0, 0x64, 0 },
    { TEXT_CreateIndirect, "Text", ID_TEXT_1, 0, 94, 168, 20, 0, 0x64, 0 },
    { TEXT_CreateIndirect, "Text", ID_TEXT_2, 0, 129, 168, 20, 0, 0x64, 0 },
    { TEXT_CreateIndirect, "Text", ID_TEXT_3, 0, 163, 168, 20, 0, 0x64, 0 },
    { BUTTON_CreateIndirect, customer_text, ID_BUTTON_CUSTOMER, 176, 90, 230, 30, 0, 0x0, 0 },
    { BUTTON_CreateIndirect, zip_text, ID_BUTTON_ZIP, 176, 125, 230, 30, 0, 0x0, 0 },
    { BUTTON_CreateIndirect, mac_text, ID_BUTTON_MAC, 176, 160, 230, 30, 0, 0x0, 0 },
    { BUTTON_CreateIndirect, "CANCEL", ID_BUTTON_CANCEL, 20, 230, BUT_WIDTH, BUT_HEIGHT, 0, 0x0, 0 },
    { BUTTON_CreateIndirect, "SAVE", ID_BUTTON_SAVE, 350, 230,BUT_WIDTH, BUT_HEIGHT, 0, 0x0, 0 },
};

static void drawProfileButton(char * but, int w, int h, int col)
{
    GUI_RECT rect;
    rect.x0 = 4;
    rect.y0 = 0;
    rect.x1 = w;
    rect.y1 = h;
    GUI_DrawGradientRoundedV(0, 0, w, h, 4, color_map[col].stop, color_map[col].start);
    GUI_SetFont(Tahoma23B);
    GUI_SetColor(GUI_WHITE);
    GUI_SetTextMode(GUI_TM_TRANS);
    GUI_DispStringInRect(but, &rect, GUI_TA_LEFT | GUI_TA_VCENTER);
    GUI_SetColor(GUI_LIGHTGRAY);
    GUI_SetPenSize(2);
}

static void profile_cb(WM_MESSAGE * pMsg)
{
    char nm[20];
    WM_HWIN win = pMsg->hWin;
    GUI_RECT r;
    WIDGET *w;
    w = BUTTON_GetpWidget(win);
    r = w->Win.Rect;
    BUTTON_GetText(win, nm, 20);
    switch (pMsg->MsgId)
    {
    case WM_PAINT:
        drawProfileButton(nm, r.x1-r.x0, r.y1-r.y0, color_scheme);
        break;
    default:
        BUTTON_Callback(pMsg);
        break;
    }
}
static WM_HWIN customerButton;

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
        TEXT_SetTextAlign(hItem, GUI_TA_HCENTER | GUI_TA_VCENTER);
        TEXT_SetFont(hItem, HEADER_FONT_BOLD);
        TEXT_SetTextColor(hItem, GUI_MAKE_COLOR(0x00FFFFFF));
        TEXT_SetText(hItem, LANG("PROFILE"));
        //
        hItem = WM_GetDialogItem(pMsg->hWin, ID_TEXT_1);
        TEXT_SetTextAlign(hItem, GUI_TA_RIGHT | GUI_TA_VCENTER);
        TEXT_SetFont(hItem, GUI_FONT_20_1);
        TEXT_SetText(hItem, LANG("Name:"));
        TEXT_SetTextColor(hItem, GUI_MAKE_COLOR(0x00008080));
        //
        hItem = WM_GetDialogItem(pMsg->hWin, ID_TEXT_2);
        TEXT_SetTextAlign(hItem, GUI_TA_RIGHT | GUI_TA_VCENTER);
        TEXT_SetFont(hItem, GUI_FONT_20_1);
        TEXT_SetText(hItem, LANG("Zip Code:"));
        TEXT_SetTextColor(hItem, GUI_MAKE_COLOR(0x00008080));
        //
        hItem = WM_GetDialogItem(pMsg->hWin, ID_TEXT_3);
        TEXT_SetTextAlign(hItem, GUI_TA_RIGHT | GUI_TA_VCENTER);
        TEXT_SetFont(hItem, GUI_FONT_20_1);
        TEXT_SetText(hItem, LANG("Thermostat MAC:"));
        TEXT_SetTextColor(hItem, GUI_MAKE_COLOR(0x00008080));
        //
        hItem = WM_GetDialogItem(pMsg->hWin, ID_TEXT_4);
        WM_SetCallback(hItem, profile_cb);
        //
        customerButton = WM_GetDialogItem(pMsg->hWin, ID_BUTTON_CUSTOMER);
        BUTTON_SetText(customerButton, customer_text);
        WM_SetCallback(customerButton, profile_cb);
        //
        hItem = WM_GetDialogItem(pMsg->hWin, ID_BUTTON_ZIP);
        BUTTON_SetText(hItem, zip_text);
        WM_SetCallback(hItem, profile_cb);

        hItem = WM_GetDialogItem(pMsg->hWin, ID_BUTTON_MAC);
        BUTTON_SetText(hItem, mac_text);
        WM_SetCallback(hItem, profile_cb);
        //
//        hItem = WM_GetDialogItem(pMsg->hWin, ID_BUTTON_CRC);
//        BUTTON_SetFont(hItem, GUI_FONT_20B_1);
//        BUTTON_SetTextColor(hItem, 0, GUI_MAKE_COLOR(0x00FFFFFF));
//        BUTTON_SetTextAlign(hItem, GUI_TA_LEFT | GUI_TA_VCENTER);
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
        case ID_BUTTON_CUSTOMER:
            switch(NCode)
            {
            case WM_NOTIFICATION_RELEASED:
                WM_HideWindow(profileWin);
                CreateKeyboardWin(1, ownersName, "Name", "Profile");
                break;
            }
            break;
        case ID_BUTTON_ZIP:
            switch(NCode)
            {
            case WM_NOTIFICATION_RELEASED:
                WM_HideWindow(profileWin);
                CreateKeyboardWin(2, zipCode, "Zip Code", "Profile");
                break;
            }
            break;
        case ID_BUTTON_MAC:
            switch(NCode)
            {
            case WM_NOTIFICATION_RELEASED:
                //state = 8;
                break;
            }
            break;
        case ID_BUTTON_CRC:
            switch(NCode)
            {
            case WM_NOTIFICATION_RELEASED:
                //state = 8;
                break;
            }
            break;
        case ID_BUTTON_CANCEL:
            switch(NCode)
            {
            case WM_NOTIFICATION_RELEASED:
                GUI_Delay(100);
                WM_HideWindow(profileWin);
                screenState = SETTINGSWIN;
                break;
            }
            break;
        case ID_BUTTON_SAVE:
            switch(NCode)
            {
            case WM_NOTIFICATION_RELEASED:
                GUI_Delay(100);
                WM_HideWindow(profileWin);
                screenState = SETTINGSWIN;
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

WM_HWIN CreateProfile(int profileIdx, char * profileTxt);
WM_HWIN CreateProfile(int profileIdx, char * profileTxt)
{
    WM_HWIN hWin;
    if (profileIdx == 0)
    {
        strcpy(crc_text, "1234");
        strcpy(zip_text, zipCode);
        strcpy(customer_text, ownersName);
        strcpy(mac_text, "00:11:22:44:55:66");
    }
    else if (profileIdx == 1)
    {
        strcpy(customer_text, profileTxt);
    }
    else if (profileIdx == 2)
    {
        strcpy(zip_text, profileTxt);
    }

    profileWin = GUI_CreateDialogBox(_aDialogCreate, GUI_COUNTOF(_aDialogCreate), _cbDialog, WM_HBKWIN, 0, 0);
    return hWin;
}
