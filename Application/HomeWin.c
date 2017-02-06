#include "main.h"

#define ID_HOME_WINDOW     (GUI_ID_USER + 0x00)
#define ID_BUTTON_COOL     (GUI_ID_USER + 0x01)
#define ID_BUTTON_MODE     (GUI_ID_USER + 0x02)
#define ID_BUTTON_HOLD     (GUI_ID_USER + 0x03)
#define ID_BUTTON_HEAT     (GUI_ID_USER + 0x04)
#define ID_BUTTON_FAN     (GUI_ID_USER + 0x05)
#define ID_TEXT_INSIDE_TEMP       (GUI_ID_USER + 0x07)
#define ID_HEADER     (GUI_ID_USER + 0x08)
#define ID_IMAGE_UP     (GUI_ID_USER + 0x09)
#define ID_IMAGE_DN     (GUI_ID_USER + 0x0A)
#define ID_IMAGE_UP_H     (GUI_ID_USER + 0x29)
#define ID_IMAGE_DN_H     (GUI_ID_USER + 0x2A)
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
#define ID_TEXT_SET_TO     (GUI_ID_USER + 0x18)
#define ID_TEXT_HOLD     (GUI_ID_USER + 0x19)
#define ID_BUTTON_UP     (GUI_ID_USER + 0x30)
#define ID_BUTTON_DN    (GUI_ID_USER + 0x31)
#define ID_BUTTON_WIFI (GUI_ID_USER + 0x32)

#define ID_BUTTON_UPPER_UP (GUI_ID_USER + 0x33)
#define ID_BUTTON_UPPER_DN (GUI_ID_USER + 0x34)
#define ID_BUTTON_LOWER_UP (GUI_ID_USER + 0x35)
#define ID_BUTTON_LOWER_DN (GUI_ID_USER + 0x36)
#define ID_TEXT_UPPER_TEMP (GUI_ID_USER + 0x37)
#define ID_TEXT_LOWER_TEMP (GUI_ID_USER + 0x38)
#define ID_TEXT_UPPER (GUI_ID_USER + 0x39)
#define ID_TEXT_LOWER (GUI_ID_USER + 0x40)
#define ID_BUTTON_OUT_DEGREES (GUI_ID_USER + 0x41)

static const GUI_WIDGET_CREATE_INFO _aDialogCreate[] =
{
    { WINDOW_CreateIndirect, "HomeWin", ID_HOME_WINDOW, 0, 0, 480, 272, 0, 0x0, 0 },
    { HEADER_CreateIndirect, "Header", ID_HEADER, 0, 0, 480, 50, 0, 0x0, 0 },
    { BUTTON_CreateIndirect, "COOL", ID_BUTTON_COOL, 384, 233, 75, 28, 0, 0x0, 0 },
    { BUTTON_CreateIndirect, "MODE", ID_BUTTON_MODE, 12, 233, 75, 28, 0, 0x0, 0 },
    { BUTTON_CreateIndirect, "HOLD", ID_BUTTON_HOLD, 198, 233, 75, 28, 0, 0x0, 0 },
    { BUTTON_CreateIndirect, "HEAT", ID_BUTTON_HEAT, 292, 233, 75, 28, 0, 0x0, 0 },

    { BUTTON_CreateIndirect, "FAN", ID_BUTTON_FAN, 104, 233, 75, 28, 0, 0x0, 0 },
    { IMAGE_CreateIndirect, "Image", ID_IMAGE_UP, 390, 70, 50, 50, 0, 0, 0 },
    { IMAGE_CreateIndirect, "Image", ID_IMAGE_DN, 390, 140, 50, 50, 0, 0, 0 },
    { TEXT_CreateIndirect, "In_T_Panel", ID_TEXT_INSIDE_TEMP, 162, 88, 135, 100, 0, 0x64, 0 },
    { BUTTON_CreateIndirect, "Button_Up", ID_BUTTON_UP, 390, 70, 50, 50, 0, 0x0, 0 },
    { BUTTON_CreateIndirect, "Button_Dn", ID_BUTTON_DN, 390, 140, 50, 50, 0, 0x0, 0 },
    { BUTTON_CreateIndirect, "SETTINGS", ID_BUTTON_SETTINGS, 14, 110, 104, 30, 0, 0x0, 0 },
    { TEXT_CreateIndirect, "Cool_T_Panel", ID_TEXT_COOLTO, 411, 204, 34, 20, 0, 0x64, 0 },
    { TEXT_CreateIndirect, "Heat_T_Panel", ID_TEXT_HEATTO, 319, 204, 36, 20, 0, 0x64, 0 },
    { TEXT_CreateIndirect, "AUTO", ID_TEXT_MODE, 33, 204, 45, 20, 0, 0x64, 0 },
    { TEXT_CreateIndirect, "AUTO", ID_TEXT_FAN, 125, 204, 43, 20, 0, 0x64, 0 },
    { TEXT_CreateIndirect, "ON SCHED", ID_TEXT_HOLD, 200, 204, 100, 20, 0, 0x64, 0 },
    { TEXT_CreateIndirect, "", ID_TEXT_DATE, 10, 0, 140, 50, 0, 0x64, 0 },
    { TEXT_CreateIndirect, "", ID_TEXT_TIME, 160, 0, 150, 50, 0, 0x64, 0 },
    { TEXT_CreateIndirect, "Out_T_Temp", ID_TEXT_OUT_TEMP, 386, 7, 72, 20, 0, 0x64, 0 },
    { TEXT_CreateIndirect, "OUSIDE", ID_TEXT_OUTSIDE, 389, 26, 61, 20, 0, 0x64, 0 },
    { TEXT_CreateIndirect, "HUMIDITY", ID_TEXT_HUMIDITY, 165, 176, 160, 20, 0, 0x64, 0 },
    { TEXT_CreateIndirect, "INDOOR", ID_TEXT_INDOOR, 165, 62, 89, 20, 0, 0x64, 0 },
    { TEXT_CreateIndirect, "SET_TO", ID_TEXT_SET_TO, 380, 122, 89, 20, 0, 0x64, 0 },
    { BUTTON_CreateIndirect, "", ID_BUTTON_WIFI, 320, 0, 50, 50, 0, 0x0, 0 },
    { BUTTON_CreateIndirect, "", ID_BUTTON_OUT_DEGREES, 400, 0, 50, 50, 0, 0x0, 0 },

    { TEXT_CreateIndirect, "UPPER", ID_TEXT_UPPER, 355, 54, 89, 80, 0, 0x64, 0 },
    { TEXT_CreateIndirect, "", ID_TEXT_UPPER_TEMP, 351, 70, 89, 80, 0, 0x64, 0 },
    { BUTTON_CreateIndirect, "Button_Up", ID_BUTTON_UPPER_UP, 432, 60, 36, 36, 0, 0x0, 0 },
    { BUTTON_CreateIndirect, "Button_Dn", ID_BUTTON_UPPER_DN, 433, 90, 36, 36, 0, 0x0, 0 },

    { TEXT_CreateIndirect, "LOWER", ID_TEXT_LOWER, 355, 124, 89, 80, 0, 0x64, 0 },
    { TEXT_CreateIndirect, "", ID_TEXT_LOWER_TEMP, 351, 142, 89, 80, 0, 0x64, 0 },
    { BUTTON_CreateIndirect, "Button_Up", ID_BUTTON_LOWER_UP, 432, 132, 36, 36, 0, 0x0, 0 },
    { BUTTON_CreateIndirect, "Button_Dn", ID_BUTTON_LOWER_DN, 433, 162, 36, 36, 0, 0x0, 0 },
};

static int holdButtonOn = 0, timerTemp;
static int cool_border, heat_border;
static GUI_TIMER_HANDLE tempTimer_h;

static WM_HWIN holdButton, insideTempText, insideHumidityText, upButton, dnButton;
static WM_HWIN upUpperButton, dnUpperButton, upLowerButton, dnLowerButton;
static WM_HWIN modeButton, fanButton, heatButton, coolButton;

static char date_buf[20];
static char time_buf[20];

extern GUI_CONST_STORAGE GUI_BITMAP bmdn_small;
extern GUI_CONST_STORAGE GUI_BITMAP bmup_small;
extern GUI_CONST_STORAGE GUI_BITMAP bmdn_small_p;
extern GUI_CONST_STORAGE GUI_BITMAP bmup_small_p;

static int wifiSkin(const WIDGET_ITEM_DRAW_INFO * pDrawItemInfo)
{
    int y = 7;
    int ys = 35;
    int xw = 6;
    switch (pDrawItemInfo->Cmd)
    {
    case WIDGET_ITEM_DRAW_BACKGROUND:
        GUI_SetColor(0x666666);
        GUI_FillRect(21,(y+=5),26,ys);
        GUI_FillRect(14,(y+=5),19,ys);
        GUI_SetColor(0xeeeeee);
        GUI_FillRect(7,(y+=5),12,ys);
        GUI_FillRect(0,(y+=5),5,ys);
      break;
    default:
        return BUTTON_DrawSkinFlex(pDrawItemInfo);
    }
}
static int outDegrees(const WIDGET_ITEM_DRAW_INFO * pDrawItemInfo)
{
    switch (pDrawItemInfo->Cmd)
    {
    case WIDGET_ITEM_DRAW_BACKGROUND:
        GUI_SetPenSize(1);
        GUI_SetColor(GUI_WHITE);
        GUI_AA_DrawArc(4, 12, 2,2,0,360);
        break;
    default:
        return BUTTON_DrawSkinFlex(pDrawItemInfo);
    }
}

static void hold_button_on(WM_MESSAGE * pMsg)
{
    switch (pMsg->MsgId)
    {
    case WM_PAINT:
        drawButton("HOLD", 1);
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

static void coolButton_cb(WM_MESSAGE * pMsg)
{
    char nm[50];
    GUI_RECT r;
    WM_GetClientRect(&r);
    BUTTON_GetText(pMsg->hWin, nm, 50);

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

static void heatButton_cb(WM_MESSAGE * pMsg)
{
    char nm[50];
    GUI_RECT r;
    WM_GetClientRect(&r);
    BUTTON_GetText(pMsg->hWin, nm, 50);

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

static void upButton_cb(WM_MESSAGE * pMsg)
{
    switch (pMsg->MsgId)
    {
    case WM_PAINT:
        if (BUTTON_IsPressed(pMsg->hWin))
        {
            GUI_DrawBitmap(&bmup_r, 0, 0);
        }
        else
        {
            GUI_DrawBitmap(&bmup_nb, 0, 0);
        }
        break;
    default:
        BUTTON_Callback(pMsg);
        break;
    }
}

static void dnButton_cb(WM_MESSAGE * pMsg)
{
    switch (pMsg->MsgId)
    {
    case WM_PAINT:
        if (BUTTON_IsPressed(pMsg->hWin))
        {
            GUI_DrawBitmap(&bmdn_r, 1, 0);

        }
        else
        {
            GUI_DrawBitmap(&bmdn_nb, 0, 0);
        }
        break;
    default:
        BUTTON_Callback(pMsg);
        break;
    }
}

// AUTO CALLBACKS

static void upUpperButton_cb(WM_MESSAGE * pMsg)
{
    switch (pMsg->MsgId)
    {
    case WM_PAINT:
        GUI_DrawBitmap(&bmup_small, 0, 0);
        break;
    default:
        BUTTON_Callback(pMsg);
        break;
    }
}

static void upUpperButtonPush_cb(WM_MESSAGE * pMsg)
{
    switch (pMsg->MsgId)
    {
    case WM_PAINT:
        GUI_DrawBitmap(&bmup_small_p, 0, 0);
        break;
    default:
        BUTTON_Callback(pMsg);
        break;
    }
}

static void dnUpperButton_cb(WM_MESSAGE * pMsg)
{
    switch (pMsg->MsgId)
    {
    case WM_PAINT:
        GUI_DrawBitmap(&bmdn_small, 0, 0);
        break;
    default:
        BUTTON_Callback(pMsg);
        break;
    }
}

static void dnUpperButtonPush_cb(WM_MESSAGE * pMsg)
{
    switch (pMsg->MsgId)
    {
    case WM_PAINT:
        GUI_DrawBitmap(&bmdn_small_p, 0, 0);
        break;
    default:
        BUTTON_Callback(pMsg);
        break;
    }
}

static void upLowerButton_cb(WM_MESSAGE * pMsg)
{
    switch (pMsg->MsgId)
    {
    case WM_PAINT:
        GUI_DrawBitmap(&bmup_small, 0, 0);
        break;
    default:
        BUTTON_Callback(pMsg);
        break;
    }
}

static void upLowerButtonPush_cb(WM_MESSAGE * pMsg)
{
    switch (pMsg->MsgId)
    {
    case WM_PAINT:
        GUI_DrawBitmap(&bmup_small_p, 0, 0);
        break;
    default:
        BUTTON_Callback(pMsg);
        break;
    }
}

static void dnLowerButton_cb(WM_MESSAGE * pMsg)
{
    switch (pMsg->MsgId)
    {
    case WM_PAINT:
        GUI_DrawBitmap(&bmdn_small, 0, 0);
        break;
    default:
        BUTTON_Callback(pMsg);
        break;
    }
}

static void dnLowerButtonPush_cb(WM_MESSAGE * pMsg)
{
    switch (pMsg->MsgId)
    {
    case WM_PAINT:
        GUI_DrawBitmap(&bmdn_small_p, 0, 0);
        break;
    default:
        BUTTON_Callback(pMsg);
        break;
    }
}

static void autoMode(WM_HWIN hWin)
{
    WM_HWIN hItem;
    if (strcmp(hvacMode, "auto") == 0)
    {
        hItem = WM_GetDialogItem(hWin, ID_BUTTON_UP);
        WM_HideWindow(hItem);
        hItem = WM_GetDialogItem(hWin, ID_BUTTON_DN);
        WM_HideWindow(hItem);
        hItem = WM_GetDialogItem(hWin, ID_TEXT_SET_TO);
        WM_HideWindow(hItem);

        hItem = WM_GetDialogItem(hWin, ID_TEXT_UPPER);
        WM_ShowWindow(hItem);
        hItem = WM_GetDialogItem(hWin, ID_TEXT_UPPER_TEMP);
        WM_ShowWindow(hItem);
        hItem = WM_GetDialogItem(hWin, ID_BUTTON_UPPER_UP);
        WM_ShowWindow(hItem);
        hItem = WM_GetDialogItem(hWin, ID_BUTTON_UPPER_DN);
        WM_ShowWindow(hItem);
        hItem = WM_GetDialogItem(hWin, ID_TEXT_LOWER);
        WM_ShowWindow(hItem);
        hItem = WM_GetDialogItem(hWin, ID_TEXT_LOWER_TEMP);
        WM_ShowWindow(hItem);
        hItem = WM_GetDialogItem(hWin, ID_BUTTON_LOWER_UP);
        WM_ShowWindow(hItem);
        hItem = WM_GetDialogItem(hWin, ID_BUTTON_LOWER_DN);
        WM_ShowWindow(hItem);
    }
    else
    {
        hItem = WM_GetDialogItem(hWin, ID_TEXT_UPPER);
        WM_HideWindow(hItem);
        hItem = WM_GetDialogItem(hWin, ID_TEXT_UPPER_TEMP);
        WM_HideWindow(hItem);
        hItem = WM_GetDialogItem(hWin, ID_BUTTON_UPPER_UP);
        WM_HideWindow(hItem);
        hItem = WM_GetDialogItem(hWin, ID_BUTTON_UPPER_DN);
        WM_HideWindow(hItem);
        hItem = WM_GetDialogItem(hWin, ID_TEXT_LOWER);
        WM_HideWindow(hItem);
        hItem = WM_GetDialogItem(hWin, ID_TEXT_LOWER_TEMP);
        WM_HideWindow(hItem);
        hItem = WM_GetDialogItem(hWin, ID_BUTTON_LOWER_UP);
        WM_HideWindow(hItem);
        hItem = WM_GetDialogItem(hWin, ID_BUTTON_LOWER_DN);
        WM_HideWindow(hItem);

        hItem = WM_GetDialogItem(hWin, ID_BUTTON_UP);
        WM_ShowWindow(hItem);
        hItem = WM_GetDialogItem(hWin, ID_BUTTON_DN);
        WM_ShowWindow(hItem);
        hItem = WM_GetDialogItem(hWin, ID_TEXT_SET_TO);
        WM_ShowWindow(hItem);
    }
}

WM_HWIN dateText, timeText, textIndoor;
extern void wifi_cb(WM_MESSAGE *);

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
    GUI_COLOR textColor = 0xffffff;


    hWin = pMsg->hWin;
    switch (pMsg->MsgId)
    {
    case WM_PAINT:
        GUI_DrawBitmap(&bmwatermark, 45,50);
        GUI_SetColor(0xcecece);
        GUI_DrawVLine(340, 75, 170);
        GUI_DrawVLine(341, 75, 170);
        GUI_DrawGradientV(0, 200, 480, 225, 0x00cacaca, 0x00838383);

        GUI_SetColor(0x808080);
        GUI_SetPenSize(4);
        GUI_AA_DrawArc(290, 90, 6,6,0,360);
        GUI_SetPenSize(1);
        GUI_SetColor(GUI_WHITE);
        GUI_AA_DrawArc(394, 7, 2,2,0,360);
        GUI_AA_DrawArc(337, 209, 2,2,0,360);
        GUI_AA_DrawArc(429, 209, 2,2,0,360);

        GUI_SetColor(0x808080);
        if (strcmp(hvacMode, "auto") == 0)
        {
            GUI_SetPenSize(3);
            GUI_AA_DrawArc(428, 72, 4,4,0,360);
            GUI_AA_DrawArc(428, 145, 4,4,0,360);
        }
        else
        {
            GUI_AA_DrawArc(453, 127, 2,2,0,360);
        }
        break;
    case WM_INIT_DIALOG:
        hItem = pMsg->hWin;

        hItem = WM_GetDialogItem(pMsg->hWin, ID_BUTTON_WIFI);
        BUTTON_SetSkin(hItem, wifiSkin);

        hItem = WM_GetDialogItem(pMsg->hWin, ID_BUTTON_OUT_DEGREES);
        BUTTON_SetSkin(hItem, outDegrees);

        dateText = WM_GetDialogItem(pMsg->hWin, ID_TEXT_DATE);
        TEXT_SetText(dateText, date_buf);
        TEXT_SetTextAlign(dateText, GUI_TA_LEFT | GUI_TA_VCENTER);
        TEXT_SetFont(dateText, &GUI_FontRounded22);
        TEXT_SetTextColor(dateText, textColor);
        //
        timeText = WM_GetDialogItem(pMsg->hWin, ID_TEXT_TIME);
        TEXT_SetText(timeText, time_buf);
        TEXT_SetTextAlign(timeText, GUI_TA_LEFT | GUI_TA_VCENTER);
        TEXT_SetFont(timeText, &GUI_FontRounded22);
        TEXT_SetTextColor(timeText, textColor);
        //
        sprintf(buffer, "%d °  |  %d%%", localTemp, localHumidity);
        hItem = WM_GetDialogItem(pMsg->hWin, ID_TEXT_OUT_TEMP);
        TEXT_SetText(hItem, buffer);
        TEXT_SetFont(hItem, &GUI_FontRounded16);
        TEXT_SetTextColor(hItem, textColor);
        //
        hItem = WM_GetDialogItem(pMsg->hWin, ID_TEXT_OUTSIDE);
        TEXT_SetFont(hItem, &GUI_FontRounded16);
        TEXT_SetText(hItem, "OUTSIDE");
        TEXT_SetTextColor(hItem, textColor);
        //
        hItem = WM_GetDialogItem(pMsg->hWin, ID_BUTTON_SETTINGS);
        BUTTON_SetTextColor(hItem, 2, textColor);
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
        insideTempText = WM_GetDialogItem(pMsg->hWin, ID_TEXT_INSIDE_TEMP);
        TEXT_SetText(insideTempText, buffer);
        TEXT_SetFont(insideTempText, GUI_FONT_D80);
        TEXT_SetTextColor(insideTempText, 0x00808080);
        //
        upButton = WM_GetDialogItem(pMsg->hWin, ID_BUTTON_UP);
        WM_SetCallback(upButton, upButton_cb);
        //
        dnButton = WM_GetDialogItem(pMsg->hWin, ID_BUTTON_DN);
        WM_SetCallback(dnButton, dnButton_cb);

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
        sprintf(buffer, "%d%% HUMIDITY", insideHumidity);
        insideHumidityText = WM_GetDialogItem(pMsg->hWin, ID_TEXT_HUMIDITY);
        TEXT_SetFont(insideHumidityText, &FontBig20B);
        TEXT_SetTextColor(insideHumidityText, 0x808080);
        TEXT_SetText(insideHumidityText, buffer);
        //
        textIndoor = WM_GetDialogItem(pMsg->hWin, ID_TEXT_INDOOR);
        TEXT_SetText(textIndoor, "INDOOR");
        TEXT_SetTextColor(textIndoor, 0x808080);
        TEXT_SetFont(textIndoor, &FontBig20B);

        sprintf(buffer, "SET TO %d °", tempSetPoint);
        hItem = WM_GetDialogItem(pMsg->hWin, ID_TEXT_SET_TO);
        TEXT_SetText(hItem, buffer);
        TEXT_SetTextColor(hItem, 0x808080);
        TEXT_SetFont(hItem, &GUI_FontRounded16);

        hItem = WM_GetDialogItem(pMsg->hWin, ID_TEXT_UPPER);
        TEXT_SetTextColor(hItem, 0x808080);
        TEXT_SetFont(hItem, &GUI_FontRounded16);

        sprintf(buffer, "%d °", upperDegreeLimit);
        hItem = WM_GetDialogItem(pMsg->hWin, ID_TEXT_UPPER_TEMP);
        TEXT_SetText(hItem, buffer);
        TEXT_SetTextColor(hItem, 0x808080);
        TEXT_SetFont(hItem, &GUI_FontD36x48);

        hItem = WM_GetDialogItem(pMsg->hWin, ID_TEXT_LOWER);
        TEXT_SetTextColor(hItem, 0x808080);
        TEXT_SetFont(hItem, &GUI_FontRounded16);

        sprintf(buffer, "%d °", lowerDegreeLimit);
        hItem = WM_GetDialogItem(pMsg->hWin, ID_TEXT_LOWER_TEMP);
        TEXT_SetText(hItem, buffer);
        TEXT_SetTextColor(hItem, 0x808080);
        TEXT_SetFont(hItem, &GUI_FontD36x48);

        upUpperButton = WM_GetDialogItem(pMsg->hWin, ID_BUTTON_UPPER_UP);
        WM_SetCallback(upUpperButton, upUpperButton_cb);
        //
        dnUpperButton = WM_GetDialogItem(pMsg->hWin, ID_BUTTON_UPPER_DN);
        WM_SetCallback(dnUpperButton, dnUpperButton_cb);

        upLowerButton = WM_GetDialogItem(pMsg->hWin, ID_BUTTON_LOWER_UP);
        WM_SetCallback(upLowerButton, upLowerButton_cb);
        //
        dnLowerButton = WM_GetDialogItem(pMsg->hWin, ID_BUTTON_LOWER_DN);
        WM_SetCallback(dnLowerButton, dnLowerButton_cb);

        autoMode(pMsg->hWin);

        break;
    case WM_NOTIFY_PARENT:
        Id    = WM_GetId(pMsg->hWinSrc);
        NCode = pMsg->Data.v;
        GUI_TIMER_SetPeriod(lockTimer_h, idleTimeOut);
        GUI_TIMER_Restart(lockTimer_h);
        switch(Id)
        {
        case ID_BUTTON_SETTINGS:
            switch(NCode)
            {
            case WM_NOTIFICATION_CLICKED:
                break;
            case WM_NOTIFICATION_RELEASED:
                GUI_TIMER_SetPeriod(lockTimer_h, 9999999);
                GUI_TIMER_Restart(lockTimer_h);
                CreateSettings();
                GUI_Delay(100);
            }
            break;
        case ID_BUTTON_COOL:
            switch(NCode)
            {
            case WM_NOTIFICATION_CLICKED:
                break;
            case WM_NOTIFICATION_RELEASED:
                break;
            }
            break;
        case ID_BUTTON_MODE:
            switch(NCode)
            {
            case WM_NOTIFICATION_CLICKED:
                break;
            case WM_NOTIFICATION_RELEASED:
                CreateMode();
                GUI_Delay(100);
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
                break;
            case WM_NOTIFICATION_RELEASED:
                break;
            }
            break;
        case ID_BUTTON_FAN:
            switch(NCode)
            {
            case WM_NOTIFICATION_CLICKED:
                break;
            case WM_NOTIFICATION_RELEASED:
                CreateFanMode();
                //state=5;
                break;
            }
            break;
        case ID_BUTTON_UP:
            switch(NCode)
            {
            case WM_NOTIFICATION_CLICKED:
                GUI_TIMER_SetPeriod(lockTimer_h, idleTimeOut);
                GUI_TIMER_Restart(lockTimer_h);

                GUI_TIMER_SetPeriod(tempTimer_h, 333000);
                GUI_TIMER_Restart(tempTimer_h);
                if (strcmp(hvacMode, "heat") == 0)
                {
                    heatToDegrees++;
                    sprintf(buffer,"%d °", heatToDegrees);
                    hItem = WM_GetDialogItem(pMsg->hWin, ID_TEXT_HEATTO);
                    TEXT_SetText(hItem, buffer);

                    sprintf(buffer,"SET TO %d °", heatToDegrees);
                    hItem = WM_GetDialogItem(pMsg->hWin, ID_TEXT_SET_TO);
                    TEXT_SetText(hItem, buffer);
                    TEXT_SetText(textIndoor, buffer);

                    timerTemp = heatToDegrees;
                    sprintf(buffer,"%d °", heatToDegrees);
                    TEXT_SetText(insideTempText, buffer);
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
                    TEXT_SetText(textIndoor, buffer);

                    timerTemp = coolToDegrees;
                    sprintf(buffer,"%d °", coolToDegrees);
                    TEXT_SetText(insideTempText, buffer);
                }
                break;
            case WM_NOTIFICATION_RELEASED:
                GUI_TIMER_SetPeriod(tempTimer_h, 3000);
                GUI_TIMER_Restart(tempTimer_h);
                break;
            case WM_NOTIFICATION_MOVED_OUT:
                GUI_TIMER_SetPeriod(tempTimer_h, 3000);
                GUI_TIMER_Restart(tempTimer_h);
                break;
            }
            break;
        case ID_BUTTON_DN:
            switch(NCode)
            {
            case WM_NOTIFICATION_CLICKED:
                GUI_TIMER_SetPeriod(lockTimer_h, idleTimeOut);
                GUI_TIMER_Restart(lockTimer_h);
                GUI_TIMER_SetPeriod(tempTimer_h, 3333000);
                GUI_TIMER_Restart(tempTimer_h );
                //  }
                if (strcmp(hvacMode, "heat") == 0)
                {
                    heatToDegrees--;
                    sprintf(buffer,"%d °", heatToDegrees);
                    hItem = WM_GetDialogItem(pMsg->hWin, ID_TEXT_HEATTO);
                    TEXT_SetText(hItem, buffer);

                    sprintf(buffer,"SET TO %d °", heatToDegrees);
                    hItem = WM_GetDialogItem(pMsg->hWin, ID_TEXT_SET_TO);
                    TEXT_SetText(hItem, buffer);
                    TEXT_SetText(textIndoor, buffer);

                    timerTemp = heatToDegrees;
                    sprintf(buffer,"%d °", heatToDegrees);
                    TEXT_SetText(insideTempText, buffer);
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
                    TEXT_SetText(textIndoor, buffer);

                    timerTemp = coolToDegrees;
                    sprintf(buffer,"%d °", coolToDegrees);
                    TEXT_SetText(insideTempText, buffer);
                }
                break;
            case WM_NOTIFICATION_RELEASED:
                GUI_TIMER_SetPeriod(tempTimer_h, 3000);
                GUI_TIMER_Restart(tempTimer_h );
                break;
            case WM_NOTIFICATION_MOVED_OUT:
                GUI_TIMER_SetPeriod(tempTimer_h, 3000);
                GUI_TIMER_Restart(tempTimer_h );
                break;
            }
            break;
        case ID_BUTTON_UPPER_UP:
            switch(NCode)
            {
            case WM_NOTIFICATION_CLICKED:
                upperDegreeLimit++;
                if (upperDegreeLimit == 100) upperDegreeLimit = 99;
                sprintf(buffer,"%d °", upperDegreeLimit);
                hItem = WM_GetDialogItem(pMsg->hWin, ID_TEXT_UPPER_TEMP);
                TEXT_SetText(hItem, buffer);
                break;
            }
            break;
        case ID_BUTTON_UPPER_DN:
            switch(NCode)
            {
            case WM_NOTIFICATION_CLICKED:
                upperDegreeLimit--;
                if (upperDegreeLimit == 64) upperDegreeLimit = 65;
                sprintf(buffer,"%d °", upperDegreeLimit);
                hItem = WM_GetDialogItem(pMsg->hWin, ID_TEXT_UPPER_TEMP);
                TEXT_SetText(hItem, buffer);
                break;
            }
            break;
        case ID_BUTTON_LOWER_UP:
            switch(NCode)
            {
            case WM_NOTIFICATION_CLICKED:
                lowerDegreeLimit++;
                if (lowerDegreeLimit == 100) lowerDegreeLimit = 99;
                sprintf(buffer,"%d °", lowerDegreeLimit);
                hItem = WM_GetDialogItem(pMsg->hWin, ID_TEXT_LOWER_TEMP);
                TEXT_SetText(hItem, buffer);
                break;
            }
            break;
        case ID_BUTTON_LOWER_DN:
            switch(NCode)
            {
            case WM_NOTIFICATION_CLICKED:
                lowerDegreeLimit--;
                if (lowerDegreeLimit == 64) lowerDegreeLimit = 65;
                sprintf(buffer,"%d °", lowerDegreeLimit);
                hItem = WM_GetDialogItem(pMsg->hWin, ID_TEXT_LOWER_TEMP);
                TEXT_SetText(hItem, buffer);
                break;
            }
            break;
        }
    default:
        WM_DefaultProc(pMsg);
        break;
    }
}

static void tempTimer(GUI_TIMER_MESSAGE * pTM)
{
    char buf[10];
    sprintf(buf,"%d",insideTemp);
    TEXT_SetText(insideTempText, buf);
    TEXT_SetText(textIndoor, "INDOOR");
    GUI_TIMER_SetPeriod(pTM->hTimer, 4000);
    GUI_TIMER_Restart(pTM->hTimer);
}

static void dateTimer(GUI_TIMER_MESSAGE * pTM)
{
    time_t now = time(NULL);
    strftime(date_buf, 20, "%a %m/%d/%Y", localtime(&now));
    if (clockFormat == 24)
    {
        strftime(time_buf, 20, "%H:%M", localtime(&now));
    }
    else
    {
        strftime(time_buf, 20, "%I:%M %p", localtime(&now));
    }
    TEXT_SetText(dateText, date_buf);
    TEXT_SetText(timeText, time_buf);

    char buffer[10];
    sprintf(buffer,"%d",insideTemp);
    TEXT_SetText(insideTempText, buffer);
    sprintf(buffer,"%d%% HUMIDITY",insideHumidity);
    TEXT_SetText(insideHumidityText, buffer);

    GUI_TIMER_SetPeriod(pTM->hTimer, 60000);
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

    strftime(date_buf, 20, "%a %m/%d/%Y", localtime(&now));
    if (clockFormat == 24)
    {
        strftime(time_buf, 20, "%H:%M", localtime(&now));
    }
    else
    {
        strftime(time_buf, 20, "%I:%M %p", localtime(&now));
    }
    cool_border = strcmp(hvacMode, "cool") == 0;
    heat_border = strcmp(hvacMode, "heat") == 0;
    holdMode = 0;


    if (!tempTimerSet)
    {
        GUI_TIMER_Create(dateTimer, 60000, 0, 0);
        tempTimer_h = GUI_TIMER_Create(tempTimer, 4000, 0, 0);
        tempTimerSet = 1;
    }

    hWin = GUI_CreateDialogBox(_aDialogCreate, GUI_COUNTOF(_aDialogCreate), _cbDialog, WM_HBKWIN, 0, 0);
    return hWin;
}

/*************************** End of file ****************************/
