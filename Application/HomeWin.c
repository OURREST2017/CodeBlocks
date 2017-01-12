#include "main.h"

#define ID_HOME_WINDOW     (GUI_ID_USER + 0x00)
#define ID_BUTTON_COOL     (GUI_ID_USER + 0x01)
#define ID_BUTTON_MODE     (GUI_ID_USER + 0x02)
#define ID_BUTTON_HOLD     (GUI_ID_USER + 0x03)
#define ID_BUTTON_HEAT     (GUI_ID_USER + 0x04)
#define ID_BUTTON_FAN     (GUI_ID_USER + 0x05)
#define ID_TEXT_INSIDE_TEMP       (GUI_ID_USER + 0x07)
#define ID_HEADER     (GUI_ID_USER + 0x08)
#define ID_BUTTON_UP     (GUI_ID_USER + 0x09)
#define ID_BUTTON_DN     (GUI_ID_USER + 0x0A)
#define ID_BUTTON_SETTINGS     (GUI_ID_USER + 0x0B)
#define ID_TEXT_COOLTO     (GUI_ID_USER + 0x0C)
#define ID_TEXT_HEATTO     (GUI_ID_USER + 0x0D)
#define ID_TEXT_MODE     (GUI_ID_USER + 0x0E)
#define ID_TEXT_FAN     (GUI_ID_USER + 0x0F)
#define ID_TEXT_DATE     (GUI_ID_USER + 0x10)
#define ID_TEXT_OUT_TEMP     (GUI_ID_USER + 0x11)
#define ID_TEXT_TIME     (GUI_ID_USER + 0x12)
#define ID_TEXT_OUTSIDE     (GUI_ID_USER + 0x13)
#define ID_TEXT_HUMIDITY     (GUI_ID_USER + 0x14)
#define ID_TEXT_INDOOR     (GUI_ID_USER + 0x15)
#define ID_IMAGE_GRAY_BAR (GUI_ID_USER + 0x17)
#define ID_TEXT_SET_TO     (GUI_ID_USER + 0x18)
#define ID_TEXT_HOLD     (GUI_ID_USER + 0x19)

static U8 gray_bar[454] =
{
    0x89, 0x50, 0x4E, 0x47, 0x0D, 0x0A, 0x1A, 0x0A, 0x00, 0x00, 0x00, 0x0D, 0x49, 0x48, 0x44, 0x52, 0x00, 0x00, 0x01, 0xE0, 0x00, 0x00, 0x00, 0x16, 0x08, 0x06, 0x00, 0x00, 0x00, 0x18, 0x68, 0x4F, 0x25, 0x00, 0x00, 0x00, 0x01, 0x73, 0x52, 0x47, 0x42, 0x00,
    0xAE, 0xCE, 0x1C, 0xE9, 0x00, 0x00, 0x00, 0x04, 0x67, 0x41, 0x4D, 0x41, 0x00, 0x00, 0xB1, 0x8F, 0x0B, 0xFC, 0x61, 0x05, 0x00, 0x00, 0x00, 0x09, 0x70, 0x48, 0x59, 0x73, 0x00, 0x00, 0x0E, 0xC4, 0x00, 0x00, 0x0E, 0xC4, 0x01, 0x95, 0x2B, 0x0E, 0x1B, 0x00,
    0x00, 0x01, 0x5B, 0x49, 0x44, 0x41, 0x54, 0x78, 0x5E, 0xED, 0xDA, 0x5F, 0x86, 0x82, 0x61, 0x14, 0xC0, 0xE1, 0xCE, 0xD4, 0xEC, 0x61, 0x36, 0x39, 0xCC, 0x1E, 0xE6, 0x26, 0xA2, 0x8B, 0x88, 0x88, 0x2E, 0x22, 0x22, 0x26, 0x13, 0x11, 0x5D, 0x44, 0xB4, 0x86,
    0x59, 0x4B, 0xF1, 0x69, 0xBC, 0xE3, 0x9B, 0x3D, 0x1C, 0xC7, 0xF3, 0xDC, 0xF4, 0x7E, 0x0B, 0x38, 0x7E, 0xBD, 0x7F, 0xE2, 0x76, 0xBB, 0x3D, 0x07, 0x05, 0x0C, 0x87, 0xC3, 0x7E, 0x05, 0xFC, 0xEB, 0xBA, 0xAE, 0x5F, 0xD5, 0x60, 0xCE, 0xA9, 0x24, 0xAE, 0xD7,
    0xAB, 0x00, 0x43, 0x51, 0x2D, 0xC0, 0x66, 0x03, 0x72, 0x8A, 0xCB, 0xE5, 0x22, 0xC0, 0x50, 0x50, 0x9B, 0x89, 0xC7, 0xE3, 0x61, 0x36, 0x20, 0xA9, 0x38, 0x9F, 0xCF, 0x25, 0x02, 0x3C, 0x1A, 0x8D, 0xFA, 0x15, 0xD0, 0xB4, 0xF0, 0xDE, 0xEF, 0x77, 0xB3, 0x01,
    0x49, 0xC5, 0xE9, 0x74, 0xB2, 0x03, 0x86, 0x82, 0x5A, 0x78, 0x5B, 0x80, 0xCD, 0x06, 0xE4, 0x14, 0xC7, 0xE3, 0x51, 0x80, 0xA1, 0xA0, 0x36, 0x13, 0x8E, 0xA0, 0x21, 0xAF, 0x38, 0x1C, 0x0E, 0x02, 0x0C, 0x05, 0x09, 0x30, 0xE4, 0x16, 0xFB, 0xFD, 0x5E, 0x80,
    0xA1, 0x20, 0x01, 0x86, 0xDC, 0x62, 0xB7, 0xDB, 0x79, 0x84, 0x05, 0x05, 0xB5, 0xF0, 0x7A, 0x84, 0x05, 0x79, 0xC5, 0x76, 0xBB, 0xB5, 0x03, 0x86, 0x82, 0x3C, 0xC2, 0x82, 0xDC, 0x62, 0xB3, 0xD9, 0x08, 0x30, 0x14, 0xD4, 0x66, 0xC2, 0x11, 0x34, 0xE4, 0x15,
    0xEB, 0xF5, 0x5A, 0x80, 0xA1, 0x20, 0x01, 0x86, 0xDC, 0x62, 0xB5, 0x5A, 0xB9, 0x03, 0x86, 0x82, 0x5A, 0x78, 0xDD, 0x01, 0x43, 0x5E, 0xB1, 0x5C, 0x2E, 0xED, 0x80, 0xA1, 0x20, 0x77, 0xC0, 0x90, 0x5B, 0x2C, 0x16, 0x0B, 0x01, 0x86, 0x82, 0xDA, 0x4C, 0x38,
    0x82, 0x86, 0xBC, 0x62, 0x3E, 0x9F, 0x0B, 0x30, 0x14, 0x24, 0xC0, 0x90, 0x5B, 0xCC, 0x66, 0x33, 0x01, 0x86, 0x82, 0x04, 0x18, 0x72, 0x8B, 0xE9, 0x74, 0xEA, 0x11, 0x16, 0x14, 0xD4, 0xC2, 0xEB, 0x11, 0x16, 0xE4, 0x15, 0x93, 0xC9, 0xC4, 0x0E, 0x18, 0x0A,
    0xF2, 0x08, 0x0B, 0x72, 0x8B, 0xF1, 0x78, 0x2C, 0xC0, 0x50, 0x50, 0x9B, 0x09, 0x47, 0xD0, 0x90, 0x57, 0xBC, 0x7D, 0xFE, 0x3C, 0x3F, 0x5E, 0xBF, 0xFB, 0x4F, 0xA0, 0x8A, 0xFF, 0xF0, 0x76, 0x5D, 0xF7, 0xF7, 0x0B, 0xE4, 0xF2, 0x17, 0xE0, 0xF7, 0x97, 0xAF,
    0xFE, 0x13, 0xA8, 0xA2, 0xDA, 0xCE, 0xD7, 0x1F, 0x09, 0x6A, 0x19, 0x0C, 0x7E, 0x01, 0x2C, 0x98, 0x84, 0xEE, 0x45, 0x0C, 0xDA, 0xE5, 0x00, 0x00, 0x00, 0x00, 0x49, 0x45, 0x4E, 0x44, 0xAE, 0x42, 0x60, 0x82,
};

static const void * _GetImageById(U32 Id, U32 * pSize)
{
    switch (Id)
    {
    case ID_IMAGE_GRAY_BAR:
        *pSize = sizeof(gray_bar);
        return (const void *)gray_bar;
    }
    return NULL;
}

static const GUI_WIDGET_CREATE_INFO _aDialogCreate[] =
{
    { WINDOW_CreateIndirect, "HomeWin", ID_HOME_WINDOW, 1, 1, 480, 272, 0, 0x0, 0 },
    { BUTTON_CreateIndirect, "COOL", ID_BUTTON_COOL, 384, 233, 75, 28, 0, 0x0, 0 },
    { BUTTON_CreateIndirect, "MODE", ID_BUTTON_MODE, 12, 233, 75, 28, 0, 0x0, 0 },
    { BUTTON_CreateIndirect, "HOLD", ID_BUTTON_HOLD, 198, 233, 75, 28, 0, 0x0, 0 },
    { BUTTON_CreateIndirect, "HEAT", ID_BUTTON_HEAT, 292, 233, 75, 28, 0, 0x0, 0 },
    { BUTTON_CreateIndirect, "FAN", ID_BUTTON_FAN, 104, 233, 75, 28, 0, 0x0, 0 },
    { IMAGE_CreateIndirect, "Image", ID_IMAGE_GRAY_BAR, -1, 201, 480, 25, 0, 0, 0 },
    { TEXT_CreateIndirect, "In_T_Panel", ID_TEXT_INSIDE_TEMP, 162, 88, 135, 100, 0, 0x64, 0 },
    { HEADER_CreateIndirect, "Header", ID_HEADER, -1, 0, 480, 50, 0, 0x0, 0 },
    { BUTTON_CreateIndirect, "Button_Up", ID_BUTTON_UP, 390, 70, 50, 50, 0, 0x0, 0 },
    { BUTTON_CreateIndirect, "Button_Dn", ID_BUTTON_DN, 390, 140, 50, 50, 0, 0x0, 0 },
    { BUTTON_CreateIndirect, "SETTINGS", ID_BUTTON_SETTINGS, 14, 110, 104, 28, 0, 0x0, 0 },
    { TEXT_CreateIndirect, "Cool_T_Panel", ID_TEXT_COOLTO, 411, 204, 34, 20, 0, 0x64, 0 },
    { TEXT_CreateIndirect, "Heat_T_Panel", ID_TEXT_HEATTO, 319, 204, 36, 20, 0, 0x64, 0 },
    { TEXT_CreateIndirect, "AUTO", ID_TEXT_MODE, 33, 204, 45, 20, 0, 0x64, 0 },
    { TEXT_CreateIndirect, "AUTO", ID_TEXT_FAN, 125, 204, 43, 20, 0, 0x64, 0 },
    { TEXT_CreateIndirect, "ON SCHED", ID_TEXT_HOLD, 200, 204, 100, 20, 0, 0x64, 0 },
    { TEXT_CreateIndirect, "", ID_TEXT_DATE, 20, 0, 150, 50, 0, 0x64, 0 },
    { TEXT_CreateIndirect, "", ID_TEXT_TIME, 150, 0, 100, 50, 0, 0x64, 0 },
    { TEXT_CreateIndirect, "Out_T_Temp", ID_TEXT_OUT_TEMP, 386, 7, 72, 20, 0, 0x64, 0 },
    { TEXT_CreateIndirect, "OUSIDE", ID_TEXT_OUTSIDE, 389, 26, 61, 20, 0, 0x64, 0 },
    { TEXT_CreateIndirect, "HUMIDITY", ID_TEXT_HUMIDITY, 165, 176, 160, 20, 0, 0x64, 0 },
    { TEXT_CreateIndirect, "INDOOR", ID_TEXT_INDOOR, 165, 62, 89, 20, 0, 0x64, 0 },
    { TEXT_CreateIndirect, "SET_TO", ID_TEXT_SET_TO, 380, 122, 89, 20, 0, 0x64, 0 },
};

static int holdButtonOn = 0;
static int cool_border, heat_border;

static void hold_button_on(WM_MESSAGE * pMsg)
{
    switch (pMsg->MsgId)
    {
    case WM_PAINT:
        drawButton("HOLD", 5);
        break;
    default:
        BUTTON_Callback(pMsg);
        break;
    }
}

static void hold_button_off(WM_MESSAGE * pMsg)
{
    switch (pMsg->MsgId)
    {
    case WM_PAINT:
        drawButton("HOLD", color_scheme);
        break;
    default:
        BUTTON_Callback(pMsg);
        break;
    }
}

void coolButton_cb(WM_MESSAGE * pMsg)
{
    char nm[50];
    WM_HWIN win = pMsg->hWin;
    GUI_RECT r;
    WIDGET *w;
    w = BUTTON_GetpWidget(win);
    r = w->Win.Rect;
    BUTTON_GetText(win, nm, 20);
    switch (pMsg->MsgId)
    {
    case WM_PAINT:
        drawCoolButton(nm, r.x1-r.x0, r.y1-r.y0, !holdButtonOn, cool_border);
        break;
    default:
        BUTTON_Callback(pMsg);
        break;
    }
}

void heatButton_cb(WM_MESSAGE * pMsg)
{
    char nm[50];
    WM_HWIN win = pMsg->hWin;
    GUI_RECT r;
    WIDGET *w;
    w = BUTTON_GetpWidget(win);
    r = w->Win.Rect;
    BUTTON_GetText(win, nm, 20);
    switch (pMsg->MsgId)
    {
    case WM_PAINT:
        drawCoolButton(nm, r.x1-r.x0, r.y1-r.y0, !holdButtonOn, heat_border);
        break;
    default:
        BUTTON_Callback(pMsg);
        break;
    }
}

char * toup(char *s)
{
    int i;
    char *t;
    static char o[100];
    for (i=0; i<strlen(s); i++)
    {
        o[i] = toupper(s[i]);
    }
    o[i] = '\0';
    return o;
}

static WM_HWIN upButton, dnButton, holdButton;
static WM_HWIN modeButton, fanButton, heatButton, coolButton;

char date_buf[20];
char time_buf[20];


WM_HWIN dateText, timeText;

/*********************************************************************
*
*       _cbDialog
*/
static void _cbDialog(WM_MESSAGE * pMsg)
{
    WM_HWIN hItem;
    WM_HWIN                  hWin;
    int     NCode;
    int     Id;
    char		buffer[10];
    const void * pData;
    U32 FileSize;

    hWin = pMsg->hWin;
    switch (pMsg->MsgId)
    {
    case WM_PAINT:
        GUI_DrawBitmap(&bmwatermark, 0,50);
        GUI_SetColor(0xcecece);
        GUI_DrawVLine(340, 75, 170);
        GUI_DrawVLine(341, 75, 170);
        break;
    case WM_INIT_DIALOG:
        hItem = pMsg->hWin;
        WINDOW_SetBkColor(hItem, 0x00FFFFFF);

        hItem = WM_GetDialogItem(pMsg->hWin, ID_IMAGE_GRAY_BAR);
        pData = _GetImageById(ID_IMAGE_GRAY_BAR, &FileSize);
        IMAGE_SetPNG(hItem, pData, FileSize);

        hItem = WM_GetDialogItem(pMsg->hWin, ID_BUTTON_SETTINGS);
        WM_SetCallback(hItem, buttonOn16_cb);

        modeButton = WM_GetDialogItem(pMsg->hWin, ID_BUTTON_MODE);
        WM_SetCallback(modeButton, buttonOn16_cb);
        //
        fanButton = WM_GetDialogItem(pMsg->hWin, ID_BUTTON_FAN);
        WM_SetCallback(fanButton, buttonOn16_cb);
        //
        holdButton = WM_GetDialogItem(pMsg->hWin, ID_BUTTON_HOLD);
        WM_SetCallback(holdButton, hold_button_off);
        //
        heatButton = WM_GetDialogItem(pMsg->hWin, ID_BUTTON_HEAT);
        WM_SetCallback(heatButton, heatButton_cb);
        //
        coolButton = WM_GetDialogItem(pMsg->hWin, ID_BUTTON_COOL);
        WM_SetCallback(coolButton, coolButton_cb);
        //
        sprintf(buffer,"%d",insideTemp);
        hItem = WM_GetDialogItem(pMsg->hWin, ID_TEXT_INSIDE_TEMP);
        TEXT_SetText(hItem, buffer);
        TEXT_SetFont(hItem, GUI_FONT_D80);
        TEXT_SetTextColor(hItem, 0x00808080);
        //
        upButton = WM_GetDialogItem(pMsg->hWin, ID_BUTTON_UP);
        WM_SetCallback(upButton, big_up_button);
        //
        dnButton = WM_GetDialogItem(pMsg->hWin, ID_BUTTON_DN);
        WM_SetCallback(dnButton, big_dn_button);

        sprintf(buffer, "%d °", coolToDegrees);
        hItem = WM_GetDialogItem(pMsg->hWin, ID_TEXT_COOLTO);
        TEXT_SetText(hItem, buffer);
        TEXT_SetFont(hItem, &GUI_FontRounded16);
        TEXT_SetTextColor(hItem, 0x00FFFFFF);
        //
        sprintf(buffer, "%d °", heatToDegrees);
        hItem = WM_GetDialogItem(pMsg->hWin, ID_TEXT_HEATTO);
        TEXT_SetFont(hItem, &GUI_FontRounded16);
        TEXT_SetText(hItem, buffer);
        TEXT_SetTextColor(hItem, 0x00FFFFFF);
        //
        hItem = WM_GetDialogItem(pMsg->hWin, ID_TEXT_MODE);
        TEXT_SetText(hItem, toup(hvacMode));
        TEXT_SetFont(hItem, &GUI_FontRounded16);
        TEXT_SetTextColor(hItem, 0x00FFFFFF);
        //
        hItem = WM_GetDialogItem(pMsg->hWin, ID_TEXT_FAN);
        TEXT_SetText(hItem,toup(selectedFanMode));
        TEXT_SetFont(hItem, &GUI_FontRounded16);
        TEXT_SetTextColor(hItem, 0x00FFFFFF);

        hItem = WM_GetDialogItem(pMsg->hWin, ID_TEXT_HOLD);
        TEXT_SetTextAlign(dateText, GUI_TA_HCENTER | GUI_TA_VCENTER);
        TEXT_SetText(hItem, "ON SCHED");
        TEXT_SetFont(hItem, &GUI_FontRounded16);
        TEXT_SetTextColor(hItem, 0x00FFFFFF);
        //
        dateText = WM_GetDialogItem(pMsg->hWin, ID_TEXT_DATE);
        TEXT_SetText(dateText, date_buf);
        TEXT_SetTextAlign(dateText, GUI_TA_LEFT | GUI_TA_VCENTER);
        TEXT_SetFont(dateText, &GUI_FontRounded22);
        TEXT_SetTextColor(dateText, 0x00FFFFFF);
        //
        timeText = WM_GetDialogItem(pMsg->hWin, ID_TEXT_TIME);
        TEXT_SetText(timeText, time_buf);
        TEXT_SetTextAlign(timeText, GUI_TA_LEFT | GUI_TA_VCENTER);
        TEXT_SetFont(timeText, &GUI_FontRounded22);
        TEXT_SetTextColor(timeText, 0x00FFFFFF);
        //
        sprintf(buffer, "%d °  |  %d%%", localTemp, localHumidity);
        hItem = WM_GetDialogItem(pMsg->hWin, ID_TEXT_OUT_TEMP);
        TEXT_SetText(hItem, buffer);
        TEXT_SetFont(hItem, &GUI_FontRounded16);
        TEXT_SetTextColor(hItem, 0x00FFFFFF);
        //
        hItem = WM_GetDialogItem(pMsg->hWin, ID_TEXT_OUTSIDE);
        TEXT_SetFont(hItem, &GUI_FontRounded16);
        TEXT_SetText(hItem, "OUTSIDE");
        TEXT_SetTextColor(hItem, 0x00FFFFFF);
        //
        sprintf(buffer, "%d%% HUMIDITY", insideHumidity);
        hItem = WM_GetDialogItem(pMsg->hWin, ID_TEXT_HUMIDITY);
        TEXT_SetFont(hItem, &FontBig20B);
        TEXT_SetText(hItem, buffer);
        //
        hItem = WM_GetDialogItem(pMsg->hWin, ID_TEXT_INDOOR);
        TEXT_SetText(hItem, "INDOOR");
        TEXT_SetFont(hItem, &FontBig20B);

        sprintf(buffer, "SET TO %d °", tempSetPoint);
        hItem = WM_GetDialogItem(pMsg->hWin, ID_TEXT_SET_TO);
        TEXT_SetText(hItem, buffer);
        TEXT_SetFont(hItem, &GUI_FontRounded16);
        break;
    case WM_NOTIFY_PARENT:
        Id    = WM_GetId(pMsg->hWinSrc);
        NCode = pMsg->Data.v;
        switch(Id)
        {
        case ID_BUTTON_SETTINGS:
            switch(NCode)
            {
            case WM_NOTIFICATION_CLICKED:
                hItem = WM_GetDialogItem(pMsg->hWin, ID_BUTTON_SETTINGS);
                WM_InvalidateWindow(hItem);
                WM_SetCallback(hItem, buttonOff16_cb);
                break;
            case WM_NOTIFICATION_RELEASED:
                hItem = WM_GetDialogItem(pMsg->hWin, ID_BUTTON_SETTINGS);
                WM_InvalidateWindow(hItem);
                WM_SetCallback(hItem, buttonOn16_cb);
                state=4;
            }
            break;
        case ID_BUTTON_COOL:
            switch(NCode)
            {
            case WM_NOTIFICATION_CLICKED:
                WM_InvalidateWindow(coolButton);
                WM_SetCallback(coolButton, buttonOff16_cb);
                break;
            case WM_NOTIFICATION_RELEASED:
                WM_InvalidateWindow(coolButton);
                WM_SetCallback(coolButton, buttonOn16_cb);
                break;
            }
            break;
        case ID_BUTTON_MODE:
            switch(NCode)
            {
            case WM_NOTIFICATION_CLICKED:
                WM_InvalidateWindow(modeButton);
                WM_SetCallback(modeButton, buttonOff16_cb);
                break;
            case WM_NOTIFICATION_RELEASED:
                WM_InvalidateWindow(modeButton);
                WM_SetCallback(modeButton, buttonOn16_cb);
                state=3;
                break;
            }
            break;
        case ID_BUTTON_HOLD:
            switch(NCode)
            {
            case WM_NOTIFICATION_RELEASED:
                hItem = WM_GetDialogItem(pMsg->hWin, ID_TEXT_HOLD);
                if (holdButtonOn)
                {
                    WM_SetCallback(holdButton, hold_button_off);
                    WM_EnableWindow(modeButton);
                    WM_EnableWindow(coolButton);
                    WM_EnableWindow(heatButton);
                    WM_EnableWindow(fanButton);
                    WM_SetCallback(modeButton, buttonOn16_cb);
                    WM_SetCallback(coolButton, coolButton_cb);
                    WM_SetCallback(heatButton, heatButton_cb);
                    WM_SetCallback(fanButton, buttonOn16_cb);
                    TEXT_SetText(hItem, "ON SCHED");
                }
                else
                {
                    WM_SetCallback(holdButton, hold_button_on);
                    WM_DisableWindow(modeButton);
                    WM_DisableWindow(coolButton);
                    WM_DisableWindow(heatButton);
                    WM_DisableWindow(fanButton);
                    WM_SetCallback(modeButton, buttonOff16_cb);
                    WM_SetCallback(coolButton, coolButton_cb);
                    WM_SetCallback(heatButton, heatButton_cb);
                    WM_SetCallback(fanButton, buttonOff16_cb);
                    TEXT_SetText(hItem, " ON HOLD");
                }
                WM_InvalidateWindow(modeButton);
                WM_InvalidateWindow(fanButton);
                WM_InvalidateWindow(coolButton);
                WM_InvalidateWindow(heatButton);
                holdButtonOn = !holdButtonOn;
                holdMode = !holdMode;
                break;
            }
            break;
        case ID_BUTTON_HEAT:
            switch(NCode)
            {
            case WM_NOTIFICATION_CLICKED:
                WM_InvalidateWindow(heatButton);
                WM_SetCallback(heatButton, buttonOff16_cb);
                break;
            case WM_NOTIFICATION_RELEASED:
                WM_InvalidateWindow(heatButton);
                WM_SetCallback(heatButton, buttonOn16_cb);
                break;
            }
            break;
        case ID_BUTTON_FAN:
            switch(NCode)
            {
            case WM_NOTIFICATION_CLICKED:
                WM_InvalidateWindow(fanButton);
                WM_SetCallback(fanButton, buttonOff16_cb);
                break;
            case WM_NOTIFICATION_RELEASED:
                WM_InvalidateWindow(fanButton);
                WM_SetCallback(fanButton, buttonOn16_cb);
                state=5;
                break;
            }
            break;
        case ID_BUTTON_UP:
            switch(NCode)
            {
            case WM_NOTIFICATION_RELEASED:
                if (strcmp(hvacMode, "heat") == 0)
                {
                    heatToDegrees++;
                    sprintf(buffer,"%d °", heatToDegrees);
                    hItem = WM_GetDialogItem(pMsg->hWin, ID_TEXT_HEATTO);
                    TEXT_SetText(hItem, buffer);
                    sprintf(buffer,"SET TO %d °", heatToDegrees);
                    hItem = WM_GetDialogItem(pMsg->hWin, ID_TEXT_SET_TO);
                    TEXT_SetText(hItem, buffer);
                }
                else
                {
                    coolToDegrees++;
                    sprintf(buffer,"%d °", coolToDegrees);
                    hItem = WM_GetDialogItem(pMsg->hWin, ID_TEXT_COOLTO);
                    TEXT_SetText(hItem, buffer);
                    sprintf(buffer,"SET TO %d °", coolToDegrees);
                    hItem = WM_GetDialogItem(pMsg->hWin, ID_TEXT_SET_TO);
                    TEXT_SetText(hItem, buffer);
                }
                break;
            }
            break;
        case ID_BUTTON_DN:
            switch(NCode)
            {
            case WM_NOTIFICATION_RELEASED:
                if (strcmp(hvacMode, "heat") == 0)
                {
                    heatToDegrees--;
                    sprintf(buffer,"%d °", heatToDegrees);
                    hItem = WM_GetDialogItem(pMsg->hWin, ID_TEXT_HEATTO);
                    TEXT_SetText(hItem, buffer);
                    sprintf(buffer,"SET TO %d °", heatToDegrees);
                    hItem = WM_GetDialogItem(pMsg->hWin, ID_TEXT_SET_TO);
                    TEXT_SetText(hItem, buffer);
                }
                else
                {
                    coolToDegrees--;
                    sprintf(buffer,"%d °", coolToDegrees);
                    hItem = WM_GetDialogItem(pMsg->hWin, ID_TEXT_COOLTO);
                    TEXT_SetText(hItem, buffer);
                    sprintf(buffer,"SET TO %d °", coolToDegrees);
                    hItem = WM_GetDialogItem(pMsg->hWin, ID_TEXT_SET_TO);
                    TEXT_SetText(hItem, buffer);
                }
            }
            break;
        }
        break;
    default:
        WM_DefaultProc(pMsg);
        break;
    }
}
static void _OnTimer(GUI_TIMER_MESSAGE * pTM)
{
    time_t now = time(NULL);
    strftime(date_buf, 20, "%a %m/%d/%y", localtime(&now));
    strftime(time_buf, 20, "%I:%M %p", localtime(&now));
    TEXT_SetText(dateText, date_buf);
    TEXT_SetText(timeText, time_buf);

    GUI_TIMER_Restart(pTM->hTimer);
}
/*********************************************************************
*
*       CreateHomeWin
*/
WM_HWIN CreateHomeWin(void);
WM_HWIN CreateHomeWin(void)
{
    WM_HWIN hWin;
    time_t now = time(NULL);
    strftime(date_buf, 20, "%a %m/%d/%y", localtime(&now));
    strftime(time_buf, 20, "%I:%M %p", localtime(&now));
    cool_border = strcmp(hvacMode, "cool") == 0;
    heat_border =  strcmp(hvacMode, "heat") == 0;
    holdMode = 0;
    //GUI_TIMER_Create(_OnTimer, 30000, 0, 0);
    hWin = GUI_CreateDialogBox(_aDialogCreate, GUI_COUNTOF(_aDialogCreate), _cbDialog, WM_HBKWIN, 0, 0);
    return hWin;
}

/*************************** End of file ****************************/
