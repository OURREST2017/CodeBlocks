#include "ranger.h"

#define ID_HOME_WINDOW     (GUI_ID_USER + 0x00)
#define ID_BUTTON_COOL     (GUI_ID_USER + 0x01)
#define ID_BUTTON_MODE     (GUI_ID_USER + 0x02)
#define ID_BUTTON_HOLD     (GUI_ID_USER + 0x03)
#define ID_BUTTON_HEAT     (GUI_ID_USER + 0x04)
#define ID_BUTTON_FAN     (GUI_ID_USER + 0x05)
#define ID_TEXT_INSIDE_TEMP       (GUI_ID_USER + 0x07)
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

#define ID_BUTTON_UPPER_UP (GUI_ID_USER + 0x33)
#define ID_BUTTON_UPPER_DN (GUI_ID_USER + 0x34)
#define ID_BUTTON_LOWER_UP (GUI_ID_USER + 0x35)
#define ID_BUTTON_LOWER_DN (GUI_ID_USER + 0x36)
#define ID_TEXT_UPPER_TEMP (GUI_ID_USER + 0x37)
#define ID_TEXT_LOWER_TEMP (GUI_ID_USER + 0x38)
#define ID_TEXT_UPPER (GUI_ID_USER + 0x39)
#define ID_TEXT_LOWER (GUI_ID_USER + 0x40)
#define ID_BUTTON_WIFI    (GUI_ID_USER + 0x41)

#define ID_BUTTON_INSIDE_UP     (GUI_ID_USER + 0x42)
#define ID_BUTTON_INSIDE_DN    (GUI_ID_USER + 0x43)
#define ID_HVAC_HEAT    (GUI_ID_USER + 0x44)
#define ID_HVAC_COOL    (GUI_ID_USER + 0x45)
#define ID_HVAC_FAN    (GUI_ID_USER + 0x46)
#define ID_TEXT_DEBUG (GUI_ID_USER + 0x47)

static const GUI_WIDGET_CREATE_INFO _aDialogCreate[] =
{
    { WINDOW_CreateIndirect, "HomeWin", ID_HOME_WINDOW, 0, 0, 480, 272, 0, 0x0, 0 },
    { TEXT_CreateIndirect, "", ID_TEXT_DATE, 10, 0, 140, 50, 0, 0x64, 0 },
    { TEXT_CreateIndirect, "", ID_TEXT_TIME, 160, 0, 150, 50, 0, 0x64, 0 },
    { TEXT_CreateIndirect, "Out_T_Temp", ID_TEXT_OUT_TEMP, 378, 7, 90, 20, 0, 0x64, 0 },
    { TEXT_CreateIndirect, "OUTSIDE", ID_TEXT_OUTSIDE, 389, 26, 61, 20, 0, 0x64, 0 },
//    { BUTTON_CreateIndirect, "lock", ID_BUTTON_SETTINGS, 26, 76, 90, 90, 0, 0x0, 0 },
    { BUTTON_CreateIndirect, "SETTINGS", ID_BUTTON_SETTINGS, 14, 110, 104, BUTHEIGHT, 0, 0x0, 0 },
    { TEXT_CreateIndirect, "INDOOR", ID_TEXT_INDOOR, 165, 60, 100, 20, 0, 0x64, 0 },
    { TEXT_CreateIndirect, "In_T_Panel", ID_TEXT_INSIDE_TEMP, 162, 58, 160, 120, 0, 0x64, 0 },
    { TEXT_CreateIndirect, "HUMIDITY", ID_TEXT_HUMIDITY, 165, 172, 160, 20, 0, 0x64, 0 },

    { BUTTON_CreateIndirect, "", ID_BUTTON_UP, 380, 62, 60, 60, 0, 0x0, 0 },
    { BUTTON_CreateIndirect, "", ID_BUTTON_DN, 380, 139, 60, 60, 0, 0x0, 0 },
    { TEXT_CreateIndirect, "SET_TO", ID_TEXT_SET_TO, 360, 118, 100, 25, 0, 0x64, 0 },

    { TEXT_CreateIndirect, "AUTO", ID_TEXT_MODE, 33, 202, 45, 20, 0, 0x64, 0 },
    { TEXT_CreateIndirect, "AUTO", ID_TEXT_FAN, 125, 202, 43, 20, 0, 0x64, 0 },
    { TEXT_CreateIndirect, "ON SCHED", ID_TEXT_HOLD, 200, 202, 100, 20, 0, 0x64, 0 },
    { TEXT_CreateIndirect, "Cool_T_Panel", ID_TEXT_COOLTO, 411, 202, 34, 20, 0, 0x64, 0 },
    { TEXT_CreateIndirect, "Heat_T_Panel", ID_TEXT_HEATTO, 319, 202, 36, 20, 0, 0x64, 0 },

    { BUTTON_CreateIndirect, "COOL", ID_BUTTON_COOL, 384, 233, 75, BUTHEIGHT, 0, 0x0, 0 },
    { BUTTON_CreateIndirect, "MODE", ID_BUTTON_MODE, 12, 233, 75, BUTHEIGHT, 0, 0x0, 0 },
    { BUTTON_CreateIndirect, "HOLD", ID_BUTTON_HOLD, 198, 233, 75, BUTHEIGHT, 0, 0x0, 0 },
    { BUTTON_CreateIndirect, "HEAT", ID_BUTTON_HEAT, 292, 233, 75, BUTHEIGHT, 0, 0x0, 0 },
    { BUTTON_CreateIndirect, "FAN", ID_BUTTON_FAN, 104, 233, 75, BUTHEIGHT, 0, 0x0, 0 },

    { TEXT_CreateIndirect, "UPPER", ID_TEXT_UPPER, 355, 54, 89, 80, 0, 0x64, 0 },
    { TEXT_CreateIndirect, "", ID_TEXT_UPPER_TEMP, 351, 70, 89, 80, 0, 0x64, 0 },
    { BUTTON_CreateIndirect, "", ID_BUTTON_UPPER_UP, 432, 58, 36, 36, 0, 0x0, 0 },
    { BUTTON_CreateIndirect, "", ID_BUTTON_UPPER_DN, 432, 91, 36, 36, 0, 0x0, 0 },

    { TEXT_CreateIndirect, "LOWER", ID_TEXT_LOWER, 355, 124, 89, 80, 0, 0x64, 0 },
    { TEXT_CreateIndirect, "", ID_TEXT_LOWER_TEMP, 351, 142, 89, 80, 0, 0x64, 0 },
    { BUTTON_CreateIndirect, "", ID_BUTTON_LOWER_UP, 432, 130, 36, 36, 0, 0x0, 0 },
    { BUTTON_CreateIndirect, "", ID_BUTTON_LOWER_DN, 432, 163, 36, 36, 0, 0x0, 0 },

    { BUTTON_CreateIndirect, "", ID_BUTTON_WIFI, 320, 0, 50, 50, 0, 0x0, 0 },

#ifdef DEBUG_MODE
    { TEXT_CreateIndirect, "DEBUG", ID_TEXT_DEBUG, 10, 52, 350, 20, 0, 0x64, 0 },
    { TEXT_CreateIndirect, "H", ID_HVAC_HEAT, 260, 14, 15, 20, 0, 0x64, 0 },
    { TEXT_CreateIndirect, "C", ID_HVAC_COOL, 275, 14, 15, 20, 0, 0x64, 0 },
    { TEXT_CreateIndirect, "F", ID_HVAC_FAN , 290, 14, 15, 20, 0, 0x64, 0 },
    { BUTTON_CreateIndirect, "", ID_BUTTON_INSIDE_UP, 40, 74, 60, 33, 0, 0x0, 0 },
    { BUTTON_CreateIndirect, "", ID_BUTTON_INSIDE_DN, 40, 142, 60, 30, 0, 0x0, 0 },
#endif
};

static int holdButtonOn = 0, timerTemp;
static int cool_border, heat_border;
static GUI_TIMER_HANDLE tempTimer_h;

static WM_HWIN holdButton, insideTempText, insideHumidityText, upButton, dnButton;
static WM_HWIN upUpperButton, dnUpperButton, upLowerButton, dnLowerButton;
static WM_HWIN modeButton, fanButton, heatButton, coolButton;
WM_HWIN textDebug;

static char date_buf[20];
static char time_buf[20];

extern GUI_CONST_STORAGE GUI_BITMAP bmdn_small;
extern GUI_CONST_STORAGE GUI_BITMAP bmup_small;
extern GUI_CONST_STORAGE GUI_BITMAP bmdn_small_p;
extern GUI_CONST_STORAGE GUI_BITMAP bmup_small_p;
extern GUI_CONST_STORAGE GUI_BITMAP bmsmall_degree;
extern GUI_CONST_STORAGE GUI_BITMAP bmbig_degree;

extern GUI_CONST_STORAGE GUI_BITMAP bmdn_p;
extern GUI_CONST_STORAGE GUI_BITMAP bmdn_lg;
extern GUI_CONST_STORAGE GUI_BITMAP bmup_p;
extern GUI_CONST_STORAGE GUI_BITMAP bmup_lg;
extern GUI_CONST_STORAGE GUI_BITMAP bmup_p;
extern GUI_CONST_STORAGE GUI_BITMAP bmdtup;
extern GUI_CONST_STORAGE GUI_BITMAP bmdtdn;
extern GUI_CONST_STORAGE GUI_BITMAP bmlocked;
extern GUI_CONST_STORAGE GUI_BITMAP bmunlocked;

static char *weekDays[] = {"Sun","Mon","Tue","Wed","Thu","Fri","Sat","Sun"};

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
            GUI_DrawBitmap(&bmup_p, 0, 0);
        }
        else
        {
            GUI_DrawBitmap(&bmup_lg, 0, 0);
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
            GUI_DrawBitmap(&bmdn_p, 1, 0);
        }
        else
        {
            GUI_DrawBitmap(&bmdn_lg, 0, 0);
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
        GUI_DrawBitmap(&bmdtup, 0, 0);
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
        GUI_DrawBitmap(&bmdtdn, 0, 0);
        break;
    default:
        BUTTON_Callback(pMsg);
        break;
    }
}

static void locked_cb(WM_MESSAGE * pMsg)
{
    switch (pMsg->MsgId)
    {
    case WM_PAINT:
        GUI_DrawBitmap(&bmlocked, 0, 0);
        break;
    default:
        BUTTON_Callback(pMsg);
        break;
    }
}

static void unlocked_cb(WM_MESSAGE * pMsg)
{
    switch (pMsg->MsgId)
    {
    case WM_PAINT:
        GUI_DrawBitmap(&bmunlocked, 0, 0);
        break;
    default:
        BUTTON_Callback(pMsg);
        break;
    }
}

static void wifi_cb(WM_MESSAGE * pMsg)
{
    int x = 0;
    int y = 7;
    int ys = 35;
    int xw = 6;
    switch (pMsg->MsgId)
    {
    case WM_PAINT:
        GUI_SetColor(0x666666);
        GUI_FillRect(x+21,(y+=5),x+26,ys);
        GUI_FillRect(x+14,(y+=5),x+19,ys);
        GUI_SetColor(0xeeeeee);
        GUI_FillRect(x+7,(y+=5),x+12,ys);
        GUI_FillRect(x,(y+=5),x+5,ys);
        break;
    default:
        BUTTON_Callback(pMsg);
        break;
    }
}

static void confirm_cb(WM_MESSAGE * pMsg)
{
    WM_HWIN hItem;
   int     NCode;
   int     Id;
   switch (pMsg->MsgId)
    {
    case WM_PAINT:
        GUI_SetFont(&GUI_Font24B_1);
        GUI_SetPenSize(2);
        GUI_SetColor(GUI_WHITE);
        GUI_FillRect(0,30,179, 109);
        GUI_SetColor(0x808080);
        GUI_DrawRoundedFrame(0,0,179,109,6, 2);
        GUI_DrawGradientV(0, 0, 179, 30, color_map[0].stop, color_map[0].start);
        GUI_SetTextMode(GUI_TEXTMODE_TRANS);
        GUI_SetColor(GUI_WHITE);
        GUI_DispStringAt("LOCK SCREEN", 16, 5);

        GUI_SetColor(GUI_BLACK);
        GUI_DispStringAt("Are you Sure?", 16, 36);
        hItem = BUTTON_CreateEx(25,70,52,26, pMsg->hWin, WM_CF_SHOW, 0, 1);
        BUTTON_SetText(hItem, "Yes");
        BUTTON_SetFont(hItem, &GUI_Font20B_ASCII);
        hItem = BUTTON_CreateEx(100,70,52,26, pMsg->hWin, WM_CF_SHOW, 0, 2);
        BUTTON_SetFont(hItem, &GUI_Font20B_ASCII);
        BUTTON_SetText(hItem, "No");
        break;
    case WM_NOTIFY_PARENT:
       Id    = WM_GetId(pMsg->hWinSrc);
        NCode = pMsg->Data.v;
        switch(Id)
        {
         case 1:
            switch(NCode)
            {
            case WM_NOTIFICATION_RELEASED:
               WM_DeleteWindow(pMsg->hWin);
               CreateHomeWin();
               break;
            }
            break;
        case 2:
            switch(NCode)
            {
            case WM_NOTIFICATION_RELEASED:
                WM_DeleteWindow(pMsg->hWin);
                CreateHomeWin();
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

static void screen_lock_cb(WM_MESSAGE * pMsg)
{
    WM_HWIN hItem;
   int     NCode;
   int     Id;
   switch (pMsg->MsgId)
    {
    case WM_PAINT:
        GUI_SetFont(&GUI_Font24B_1);
        GUI_SetPenSize(2);
        GUI_SetColor(GUI_WHITE);
        GUI_FillRect(0,30,179, 109);
        GUI_SetColor(0x808080);
        GUI_DrawRoundedFrame(0,0,179,109,6, 2);
        GUI_DrawGradientV(0, 0, 179, 30, color_map[0].stop, color_map[0].start);
        GUI_SetTextMode(GUI_TEXTMODE_TRANS);
        GUI_SetColor(GUI_WHITE);
        GUI_DispStringAt("LOCK SCREEN", 16, 5);

        GUI_SetColor(GUI_BLACK);
        GUI_DispStringAt("Confirm Lock?", 16, 36);
        hItem = BUTTON_CreateEx(25,70,52,26, pMsg->hWin, WM_CF_SHOW, 0, 1);
        BUTTON_SetText(hItem, "Yes");
        BUTTON_SetFont(hItem, &GUI_Font20B_ASCII);
        hItem = BUTTON_CreateEx(100,70,52,26, pMsg->hWin, WM_CF_SHOW, 0, 2);
        BUTTON_SetFont(hItem, &GUI_Font20B_ASCII);
        BUTTON_SetText(hItem, "No");
        break;
    case WM_NOTIFY_PARENT:
       Id    = WM_GetId(pMsg->hWinSrc);
        NCode = pMsg->Data.v;
        switch(Id)
        {
         case 1:
            switch(NCode)
            {
            case WM_NOTIFICATION_RELEASED:
                WM_DeleteWindow(pMsg->hWin);
                hItem = WM_CreateWindow(150,80,180,110, WM_CF_SHOW, confirm_cb, 0);
                WM_MakeModal(hItem);
               break;
            }
            break;
        case 2:
            switch(NCode)
            {
            case WM_NOTIFICATION_RELEASED:
                WM_DeleteWindow(pMsg->hWin);
                CreateHomeWin();
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
static WM_HWIN dateText, timeText, textIndoor;
WM_HWIN hvacHeat, hvacCool, hvacFan, holdText;
static int but_pressed;

static void holdModeOptions() {
    //TEXT_SetText(textDebug, (holdMode == 0) ? "false" : "true");
    holdButtonOn = holdMode;
    if (!holdMode)
    {
        WM_SetCallback(holdButton, hold_button_off);
        WM_EnableWindow(modeButton);
        WM_EnableWindow(coolButton);
        WM_EnableWindow(heatButton);
        WM_EnableWindow(fanButton);
        WM_SetCallback(modeButton, buttonOn16_cb);
        WM_SetCallback(fanButton, buttonOn16_cb);
        WM_SetCallback(coolButton, coolButton_cb);
        WM_SetCallback(heatButton, heatButton_cb);
        TEXT_SetText(holdText, "ON SCHED");
    }
    else
    {
        WM_SetCallback(holdButton, hold_button_on);
        WM_DisableWindow(modeButton);
        WM_DisableWindow(coolButton);
        WM_DisableWindow(heatButton);
        WM_DisableWindow(fanButton);
        WM_SetCallback(modeButton, buttonOff16_cb);
        WM_SetCallback(fanButton, buttonOff16_cb);
        WM_SetCallback(coolButton, coolButton_cb);
        WM_SetCallback(heatButton, heatButton_cb);
        TEXT_SetText(holdText, " ON HOLD");
    }
    WM_InvalidateWindow(modeButton);
    WM_InvalidateWindow(fanButton);
    WM_InvalidateWindow(coolButton);
    WM_InvalidateWindow(heatButton);
}

static void autoMode(WM_HWIN hWin)
{
    WM_HWIN hItem;
//    if (strcmp(hvacMode, "auto") == 0)
//    {
//        hItem = WM_GetDialogItem(hWin, ID_BUTTON_UP);
//        WM_HideWindow(hItem);
//        hItem = WM_GetDialogItem(hWin, ID_BUTTON_DN);
//        WM_HideWindow(hItem);
//        hItem = WM_GetDialogItem(hWin, ID_TEXT_SET_TO);
//        WM_HideWindow(hItem);
//
//        hItem = WM_GetDialogItem(hWin, ID_TEXT_UPPER);
//        WM_ShowWindow(hItem);
//        hItem = WM_GetDialogItem(hWin, ID_TEXT_UPPER_TEMP);
//        WM_ShowWindow(hItem);
//        hItem = WM_GetDialogItem(hWin, ID_BUTTON_UPPER_UP);
//        WM_ShowWindow(hItem);
//        hItem = WM_GetDialogItem(hWin, ID_BUTTON_UPPER_DN);
//        WM_ShowWindow(hItem);
//        hItem = WM_GetDialogItem(hWin, ID_TEXT_LOWER);
//        WM_ShowWindow(hItem);
//        hItem = WM_GetDialogItem(hWin, ID_TEXT_LOWER_TEMP);
//        WM_ShowWindow(hItem);
//        hItem = WM_GetDialogItem(hWin, ID_BUTTON_LOWER_UP);
//        WM_ShowWindow(hItem);
//        hItem = WM_GetDialogItem(hWin, ID_BUTTON_LOWER_DN);
//        WM_ShowWindow(hItem);
//    }
//    else
//    {
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
//    }
}

static void tempTimer(GUI_TIMER_MESSAGE * pTM)
{
    char buf[10];
    sprintf(buf,"%d",insideTemp);
    TEXT_SetText(insideTempText, buf);
    TEXT_SetText(textIndoor, "INDOOR");
}
/*********************************************************************
*
*       _cbDialog
*/
static void _cbDialog(WM_MESSAGE * pMsg)
{
    WM_HWIN hItem;
    int     NCode;
    int     Id;
    char		buffer[10];
    GUI_COLOR textColor = 0xffffff;

    switch (pMsg->MsgId)
    {
    case WM_PAINT:
        GUI_DrawGradientV(0, 0, 480, 50, color_map[0].stop, color_map[0].start);

        GUI_DrawBitmap(&bmwatermark, 45,52);
        GUI_DrawBitmap(&bmbig_degree, 296,82);

        GUI_SetColor(0xcecece);
        GUI_DrawVLine(340, 75, 170);
        GUI_DrawVLine(341, 75, 170);

        GUI_DrawGradientV(0, 198, 480, 223, 0x00cacaca, 0x00838383);
        break;
    case WM_INIT_DIALOG:
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
        hItem = WM_GetDialogItem(pMsg->hWin, ID_BUTTON_WIFI);
        WM_SetCallback(hItem, wifi_cb);

#ifdef DEBUG_MODE
        hItem = WM_GetDialogItem(pMsg->hWin, ID_BUTTON_INSIDE_UP);
        WM_SetCallback(hItem, upUpperButton_cb);
        //
        hItem = WM_GetDialogItem(pMsg->hWin, ID_BUTTON_INSIDE_DN);
        WM_SetCallback(hItem, dnUpperButton_cb);

        hvacHeat = WM_GetDialogItem(pMsg->hWin, ID_HVAC_HEAT);
        TEXT_SetFont(hvacHeat, &GUI_FontRounded22);
        TEXT_SetTextColor(hvacHeat, GUI_RED);
        if (heat_control) {
            WM_ShowWindow(hvacHeat);
        } else {
            WM_HideWindow(hvacHeat);
        }

        hvacCool = WM_GetDialogItem(pMsg->hWin, ID_HVAC_COOL);
        TEXT_SetFont(hvacCool, &GUI_FontRounded22);
        TEXT_SetTextColor(hvacCool, GUI_CYAN);
        if (cool_control) {
            WM_ShowWindow(hvacCool);
        } else {
            WM_HideWindow(hvacCool);
        }

        hvacFan = WM_GetDialogItem(pMsg->hWin, ID_HVAC_FAN);
        TEXT_SetFont(hvacFan, &GUI_FontRounded22);
        TEXT_SetTextColor(hvacFan, GUI_YELLOW);
        if (fan_control) {
            WM_ShowWindow(hvacFan);
        } else {
            WM_HideWindow(hvacFan);
        }
#endif

        //
        sprintf(buffer, "%d°  |  %d%%", localTemp, localHumidity);
        hItem = WM_GetDialogItem(pMsg->hWin, ID_TEXT_OUT_TEMP);
        TEXT_SetText(hItem, buffer);
        TEXT_SetFont(hItem, &GUI_FontVerdana16hAA4B);
        TEXT_SetTextColor(hItem, textColor);
        //
        hItem = WM_GetDialogItem(pMsg->hWin, ID_TEXT_OUTSIDE);
        TEXT_SetFont(hItem, &GUI_FontRounded16);
        TEXT_SetText(hItem, "OUTSIDE");
        TEXT_SetTextColor(hItem, textColor);
        //
        hItem = WM_GetDialogItem(pMsg->hWin, ID_BUTTON_SETTINGS);
        WM_SetCallback(hItem, buttonOn16_cb);
        //WM_SetCallback(hItem, locked_cb);

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
        textIndoor = WM_GetDialogItem(pMsg->hWin, ID_TEXT_INDOOR);
        TEXT_SetText(textIndoor, "INDOOR");
        TEXT_SetTextColor(textIndoor, 0x808080);
        TEXT_SetFont(textIndoor, &GUI_FontTahoma19hAA4B);
        //
        sprintf(buffer,"%d",insideTemp);
        insideTempText = WM_GetDialogItem(pMsg->hWin, ID_TEXT_INSIDE_TEMP);
        TEXT_SetText(insideTempText, buffer);
        TEXT_SetFont(insideTempText, &GUI_FontTahoma129hAA4B);
        TEXT_SetTextColor(insideTempText, 0x00808080);
        //
        sprintf(buffer, "%d%% HUMIDITY", insideHumidity);
        insideHumidityText = WM_GetDialogItem(pMsg->hWin, ID_TEXT_HUMIDITY);
        TEXT_SetFont(insideHumidityText, &GUI_FontTahoma19hAA4B);
        TEXT_SetTextColor(insideHumidityText, 0x808080);
        TEXT_SetText(insideHumidityText, buffer);

        sprintf(buffer, "SET TO %d°", tempSetPoint);
        hItem = WM_GetDialogItem(pMsg->hWin, ID_TEXT_SET_TO);
        TEXT_SetText(hItem, buffer);
        TEXT_SetTextColor(hItem, 0x808080);
        TEXT_SetFont(hItem, &GUI_FontTahoma19hAA4B);

        upButton = WM_GetDialogItem(pMsg->hWin, ID_BUTTON_UP);
        WM_SetCallback(upButton, upButton_cb);
        //
        dnButton = WM_GetDialogItem(pMsg->hWin, ID_BUTTON_DN);
        WM_SetCallback(dnButton, dnButton_cb);
        //
        hvacModeText = WM_GetDialogItem(pMsg->hWin, ID_TEXT_MODE);
        TEXT_SetText(hvacModeText, toup(hvacMode));
        TEXT_SetFont(hvacModeText, &GUI_FontVerdana16hAA4B);
        TEXT_SetTextColor(hvacModeText, 0x00FFFFFF);
        //
        fanModeText = WM_GetDialogItem(pMsg->hWin, ID_TEXT_FAN);
        TEXT_SetFont(fanModeText, &GUI_FontVerdana16hAA4B);
        TEXT_SetTextColor(fanModeText, 0x00FFFFFF);

        holdText = WM_GetDialogItem(pMsg->hWin, ID_TEXT_HOLD);
        TEXT_SetTextAlign(dateText, GUI_TA_HCENTER | GUI_TA_VCENTER);
        TEXT_SetText(holdText, "ON SCHED");
        TEXT_SetFont(holdText, &GUI_FontVerdana16hAA4B);
        TEXT_SetTextColor(holdText, 0x00FFFFFF);
        //
        sprintf(buffer, "%d°", heatToDegrees);
        heatToText = WM_GetDialogItem(pMsg->hWin, ID_TEXT_HEATTO);
        TEXT_SetFont(heatToText, &GUI_FontVerdana16hAA4B);
        TEXT_SetText(heatToText, buffer);
        TEXT_SetTextColor(heatToText, 0x00FFFFFF);

        sprintf(buffer, "%d°", coolToDegrees);
        coolToText = WM_GetDialogItem(pMsg->hWin, ID_TEXT_COOLTO);
        TEXT_SetText(coolToText, buffer);
        TEXT_SetFont(coolToText, &GUI_FontVerdana16hAA4B);
        TEXT_SetTextColor(coolToText, 0x00FFFFFF);

        textDebug = WM_GetDialogItem(pMsg->hWin, ID_TEXT_DEBUG);
        TEXT_SetTextColor(textDebug, GUI_BLACK);
        TEXT_SetFont(textDebug, &GUI_FontRounded16);

        autoMode(pMsg->hWin);
        holdModeOptions();

        break;
    case WM_NOTIFY_PARENT:
        Id    = WM_GetId(pMsg->hWinSrc);
        NCode = pMsg->Data.v;
        //GUI_TIMER_SetPeriod(lockTimer_h, idleTimeOut);
        //GUI_TIMER_Restart(lockTimer_h);
        but_pressed = 0;
        switch(Id)
        {
        case ID_BUTTON_INSIDE_UP:
            switch(NCode)
            {
            case WM_NOTIFICATION_CLICKED:
                insideTemp++;
                sprintf(buffer,"%d", insideTemp);
                TEXT_SetText(insideTempText, buffer);
                break;
             }
            break;
        case ID_BUTTON_INSIDE_DN:
            switch(NCode)
            {
             case WM_NOTIFICATION_CLICKED:
               insideTemp--;
                sprintf(buffer,"%d", insideTemp);
                TEXT_SetText(insideTempText, buffer);
                break;
             }
            break;
        case ID_BUTTON_WIFI:
            switch(NCode)
            {
            case WM_NOTIFICATION_RELEASED:
                GUI_Delay(100);
                CreateTriacPanel();
            }
            break;
        case ID_BUTTON_SETTINGS:
            switch(NCode)
            {
            case WM_NOTIFICATION_CLICKED:
                break;
            case WM_NOTIFICATION_RELEASED:
//                hItem = WM_CreateWindow(150,80,180,110, WM_CF_SHOW, screen_lock_cb, 0);
//                WM_MakeModal(hItem);
                //WM_CreateTimer();
//                hItem = WINDOW_CreateEx(150,80,180,110,
//                                         WM_HBKWIN, WM_CF_SHOW, 0, 0, confirm_cb);
//                //GUI_TIMER_SetPeriod(lockTimer_h, 9999999);
//                GUI_TIMER_Restart(lockTimer_h);
//                GUI_Delay(100);
                WM_HideWindow(homeWin);
                WM_ShowWindow(settingsWin);
                //CreateSettings();
                screenState = 0;
           }
            break;
        case ID_BUTTON_HEAT:
            switch(NCode)
            {
            case WM_NOTIFICATION_CLICKED:
                CreateHeatTo();
                break;
            }
            break;
        case ID_BUTTON_COOL:
            switch(NCode)
            {
            case WM_NOTIFICATION_CLICKED:
                CreateCoolTo();
                break;
            }
            break;
        case ID_BUTTON_MODE:
            switch(NCode)
            {
            case WM_NOTIFICATION_CLICKED:
                break;
            case WM_NOTIFICATION_RELEASED:
                GUI_Delay(100);
                CreateMode();
                break;
            }
            break;
        case ID_BUTTON_HOLD:
            switch(NCode)
            {
            case WM_NOTIFICATION_RELEASED:
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
                    TEXT_SetText(holdText, "ON SCHED");
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
                    TEXT_SetText(holdText, " ON HOLD");
                }
                holdButtonOn = !holdButtonOn;
                holdMode = !holdMode;
                break;
            }
            break;
        case ID_BUTTON_FAN:
            switch(NCode)
            {
            case WM_NOTIFICATION_CLICKED:
                break;
            case WM_NOTIFICATION_RELEASED:
                GUI_Delay(100);
                CreateFanMode();
                break;
            }
            break;
        case ID_BUTTON_UP:
            switch(NCode)
            {
            case WM_NOTIFICATION_CLICKED:
                //GUI_TIMER_SetPeriod(lockTimer_h, idleTimeOut);
                //GUI_TIMER_Restart(lockTimer_h);
                but_pressed = 1;
                WM_MoveWindow(upButton, -1, 0);
                if (strcmp(hvacMode, "heat") == 0)
                {
                    heatToDegrees++;
                    sprintf(buffer,"%d°", heatToDegrees);
                    hItem = WM_GetDialogItem(pMsg->hWin, ID_TEXT_HEATTO);
                    TEXT_SetText(hItem, buffer);

                    sprintf(buffer,"SET TO %d°", heatToDegrees);
                    hItem = WM_GetDialogItem(pMsg->hWin, ID_TEXT_SET_TO);
                    TEXT_SetText(hItem, buffer);
                    TEXT_SetText(textIndoor, buffer);

                    timerTemp = heatToDegrees;
                    sprintf(buffer,"%d", heatToDegrees);
                    TEXT_SetText(insideTempText, buffer);
                }
                else
                {
                    coolToDegrees++;
                    sprintf(buffer,"%d°", coolToDegrees);
                    hItem = WM_GetDialogItem(pMsg->hWin, ID_TEXT_COOLTO);
                    TEXT_SetText(hItem, buffer);

                    sprintf(buffer,"SET TO %d°", coolToDegrees);
                    hItem = WM_GetDialogItem(pMsg->hWin, ID_TEXT_SET_TO);
                    TEXT_SetText(hItem, buffer);
                    TEXT_SetText(textIndoor, buffer);

                    timerTemp = coolToDegrees;
                    sprintf(buffer,"%d", coolToDegrees);
                    TEXT_SetText(insideTempText, buffer);
                }
                break;
            case WM_NOTIFICATION_RELEASED:
                //tempTimer_h = GUI_TIMER_Create(tempTimer, 3000, 0, 0);
                GUI_TIMER_SetPeriod(tempTimer_h, 3000);
                GUI_TIMER_Restart(tempTimer_h);
                WM_MoveWindow(upButton, 1, 0);
                but_pressed = 0;
                break;
            case WM_NOTIFICATION_MOVED_OUT:
//                GUI_TIMER_SetPeriod(tempTimer_h, 3000);
//                GUI_TIMER_Restart(tempTimer_h);
                break;
            }
            break;
        case ID_BUTTON_DN:
            switch(NCode)
            {
            case WM_NOTIFICATION_CLICKED:
                //GUI_TIMER_SetPeriod(lockTimer_h, idleTimeOut);
                //GUI_TIMER_Restart(lockTimer_h);
                 but_pressed = 1;
               WM_MoveWindow(dnButton, -1, 0);
                //
                if (strcmp(hvacMode, "heat") == 0)
                {
                    heatToDegrees--;
                    sprintf(buffer,"%d°", heatToDegrees);
                    hItem = WM_GetDialogItem(pMsg->hWin, ID_TEXT_HEATTO);
                    TEXT_SetText(hItem, buffer);

                    sprintf(buffer,"SET TO %d°", heatToDegrees);
                    hItem = WM_GetDialogItem(pMsg->hWin, ID_TEXT_SET_TO);
                    TEXT_SetText(hItem, buffer);
                    TEXT_SetText(textIndoor, buffer);

                    timerTemp = heatToDegrees;
                    sprintf(buffer,"%d", heatToDegrees);
                    TEXT_SetText(insideTempText, buffer);
                }
                else
                {
                    coolToDegrees--;
                    sprintf(buffer,"%d°", coolToDegrees);
                    hItem = WM_GetDialogItem(pMsg->hWin, ID_TEXT_COOLTO);
                    TEXT_SetText(hItem, buffer);

                    sprintf(buffer,"SET TO %d°", coolToDegrees);
                    hItem = WM_GetDialogItem(pMsg->hWin, ID_TEXT_SET_TO);
                    TEXT_SetText(hItem, buffer);
                    TEXT_SetText(textIndoor, buffer);

                    timerTemp = coolToDegrees;
                    sprintf(buffer,"%d", coolToDegrees);
                    TEXT_SetText(insideTempText, buffer);
                }
                break;
            case WM_NOTIFICATION_RELEASED:
                //tempTimer_h = GUI_TIMER_Create(tempTimer, 3000, 0, 0);
                GUI_TIMER_SetPeriod(tempTimer_h, 3000);
                GUI_TIMER_Restart(tempTimer_h );
                WM_MoveWindow(dnButton, 1, 0);
                 but_pressed = 0;
                break;
            case WM_NOTIFICATION_MOVED_OUT:
                GUI_TIMER_SetPeriod(tempTimer_h, 3000);
                GUI_TIMER_Restart(tempTimer_h );
                break;
            }
            break;
//        case ID_BUTTON_UPPER_UP:
//            switch(NCode)
//            {
//            case WM_NOTIFICATION_CLICKED:
//                upperDegreeLimit++;
//                if (upperDegreeLimit == 100) upperDegreeLimit = 99;
//                sprintf(buffer,"%d", upperDegreeLimit);
//                hItem = WM_GetDialogItem(pMsg->hWin, ID_TEXT_UPPER_TEMP);
//                TEXT_SetText(hItem, buffer);
//                break;
//            }
//            break;
//        case ID_BUTTON_UPPER_DN:
//            switch(NCode)
//            {
//            case WM_NOTIFICATION_CLICKED:
//                upperDegreeLimit--;
//                if (upperDegreeLimit == 64) upperDegreeLimit = 65;
//                sprintf(buffer,"%d", upperDegreeLimit);
//                hItem = WM_GetDialogItem(pMsg->hWin, ID_TEXT_UPPER_TEMP);
//                TEXT_SetText(hItem, buffer);
//                break;
//            }
//            break;
//        case ID_BUTTON_LOWER_UP:
//            switch(NCode)
//            {
//            case WM_NOTIFICATION_CLICKED:
//                lowerDegreeLimit++;
//                if (lowerDegreeLimit == 100) lowerDegreeLimit = 99;
//                sprintf(buffer,"%d", lowerDegreeLimit);
//                hItem = WM_GetDialogItem(pMsg->hWin, ID_TEXT_LOWER_TEMP);
//                TEXT_SetText(hItem, buffer);
//                break;
//            }
//            break;
//        case ID_BUTTON_LOWER_DN:
//            switch(NCode)
//            {
//            case WM_NOTIFICATION_CLICKED:
//                lowerDegreeLimit--;
//                if (lowerDegreeLimit == 64) lowerDegreeLimit = 65;
//                sprintf(buffer,"%d", lowerDegreeLimit);
//                hItem = WM_GetDialogItem(pMsg->hWin, ID_TEXT_LOWER_TEMP);
//                TEXT_SetText(hItem, buffer);
//                break;
//            }
//            break;
        }
    default:
        WM_DefaultProc(pMsg);
        break;
    }
}

static void setDateTime()
{
#ifdef CODEBLOCK
    time_t now = time(NULL);
    strftime(date_buf, 20, "%a %m/%d/%y", localtime(&now));
    if (clockFormat == 24)
    {
        strftime(time_buf, 20, "%H:%M", localtime(&now));
    }
    else
    {
        strftime(time_buf, 20, "%I:%M %p", localtime(&now));
    }
#else
    RTC_TimeTypeDef tm;
    RTC_DateTypeDef dt;

    BSP_RTC_GetTime(&tm);
    BSP_RTC_GetDate(&dt);

    if (clockFormat == 24)
    {
        sprintf(time_buf, "%d:%02d", tm.Hours, tm.Minutes);
    }
    else
    {
        sprintf(time_buf, "%d:%02d", tm.Hours, tm.Minutes);
    }
    sprintf(date_buf, "%s %02d/%02d/%d", weekDays[dt.WeekDay], dt.Month, dt.Date, dt.Year);
#endif
}

static void dateTimer(GUI_TIMER_MESSAGE * pTM)
{
    setDateTime();
    TEXT_SetText(dateText, date_buf);
    TEXT_SetText(timeText, time_buf);

    if (but_pressed) return;
    char buffer[10];
    sprintf(buffer,"%d",insideTemp);
    TEXT_SetText(insideTempText, buffer);
    sprintf(buffer,"%d%% HUMIDITY",insideHumidity);
    TEXT_SetText(insideHumidityText, buffer);

//#ifdef DEBUG_MODE
//    WM_HWIN hItem;
//    if (fan_control) {
//        WM_ShowWindow(hvacFan);
//    } else {
//        WM_HideWindow(hvacFan);
//    }
//
//    //GUI_ErrorOut1("H",heat_control);
//    if (heat_control) {
//        WM_ShowWindow(hvacHeat);
//    } else {
//        WM_HideWindow(hvacHeat);
//    }
//
//    if (cool_control) {
//        WM_ShowWindow(hvacCool);
//    } else {
//        WM_HideWindow(hvacCool);
//    }
//#endif
//
    GUI_TIMER_SetPeriod(pTM->hTimer, 2000);
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
    setDateTime();
    cool_border = strcmp(hvacMode, "cool") == 0;
    heat_border = strcmp(hvacMode, "heat") == 0;

    if (!tempTimerSet)
    {
        GUI_TIMER_Create(dateTimer, 5000, 0, 0);
        tempTimer_h = GUI_TIMER_Create(tempTimer, 0, 0, 0);
        tempTimerSet = 1;
    }

    hWin = GUI_CreateDialogBox(_aDialogCreate, GUI_COUNTOF(_aDialogCreate), _cbDialog, WM_HBKWIN, 0, 0);
    WM_HideWindow(hWin);
    return hWin;
}

/*************************** End of file ****************************/
