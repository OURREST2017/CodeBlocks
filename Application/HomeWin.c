#include "ranger.h"

#define ID_HOME_WINDOW     (GUI_ID_USER + 0x00)
#define ID_BUTTON_COOL     (GUI_ID_USER + 0x01)
#define ID_BUTTON_MODE     (GUI_ID_USER + 0x02)
#define ID_BUTTON_HOLD     (GUI_ID_USER + 0x03)
#define ID_BUTTON_HEAT     (GUI_ID_USER + 0x04)
#define ID_BUTTON_FAN     (GUI_ID_USER + 0x05)
#define ID_TEXT_INSIDE_INT_TEMP       (GUI_ID_USER + 0x07)
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
#define ID_BUTTON_WIFI    (GUI_ID_USER + 0x41)

#define ID_BUTTON_DEBUG_UP     (GUI_ID_USER + 0x42)
#define ID_BUTTON_DEBUG_DN    (GUI_ID_USER + 0x43)
#define ID_HVAC_HEAT    (GUI_ID_USER + 0x44)
#define ID_HVAC_COOL    (GUI_ID_USER + 0x45)
#define ID_HVAC_FAN    (GUI_ID_USER + 0x46)
#define ID_TEXT_DEBUG (GUI_ID_USER + 0x47)
#define ID_BUTTON_DEGREE (GUI_ID_USER + 0x48)
#define ID_TEXT_INSIDE_FRAC_TEMP       (GUI_ID_USER + 0x49)
#define ID_TEXT_HOLD_UNTIL       (GUI_ID_USER + 0x4A)
#define ID_TEXT_SET_TO_TEMP     (GUI_ID_USER + 0x4B)

static const GUI_WIDGET_CREATE_INFO _aDialogCreate[] =
{
    { WINDOW_CreateIndirect, "HomeWin", ID_HOME_WINDOW, 0, 0, 480, 272, 0, 0x0, 0 },
    { TEXT_CreateIndirect, "", ID_TEXT_DATE, 14, 0, 140, 50, 0, 0x64, 0 },
    { TEXT_CreateIndirect, "", ID_TEXT_TIME, 160, 0, 150, 50, 0, 0x64, 0 },
    { TEXT_CreateIndirect, "Out_T_Temp", ID_TEXT_OUT_TEMP, 370, 7, 100, 20, 0, 0x64, 0 },
    { TEXT_CreateIndirect, "OUTSIDE", ID_TEXT_OUTSIDE, 380, 26, 70, 20, 0, 0x64, 0 },
    { BUTTON_CreateIndirect, "SETTINGS", ID_BUTTON_SETTINGS, 14, 110, 104, BUT_HEIGHT, 0, 0x0, 0 },
    { TEXT_CreateIndirect, "INDOOR", ID_TEXT_INDOOR, 165, 62, 120, 20, 0, 0x64, 0 },
    { TEXT_CreateIndirect, "INT Temp", ID_TEXT_INSIDE_INT_TEMP, 162, 58, 160, 120, 0, 0x64, 0 },
    { TEXT_CreateIndirect, "FRAC Temp", ID_TEXT_INSIDE_FRAC_TEMP, 305, 116, 50, 90, 0, 0x64, 0 },
    { TEXT_CreateIndirect, "HUMIDITY", ID_TEXT_HUMIDITY, 165, 170, 160, 20, 0, 0x64, 0 },

    { BUTTON_CreateIndirect, "", ID_BUTTON_UP, 380, 53, 60, 60, 0, 0x0, 0 },
    { BUTTON_CreateIndirect, "", ID_BUTTON_DN, 380, 143, 60, 60, 0, 0x0, 0 },
    { TEXT_CreateIndirect, "SET TO", ID_TEXT_SET_TO, 356, 104, 100, 20, 0, 0x64, 0 },
    { TEXT_CreateIndirect, "Set_to temp", ID_TEXT_SET_TO_TEMP, 359, 122, 100, 20, 0, 0x64, 0 },
    { TEXT_CreateIndirect, "Hold Until\n10:00pm", ID_TEXT_HOLD_UNTIL, 14, 124, 104, 42, 0, 0x64, 0 },

    { TEXT_CreateIndirect, "AUTO", ID_TEXT_MODE, 14, 200, 84, 20, 0, 0x64, 0 },
    { TEXT_CreateIndirect, "AUTO", ID_TEXT_FAN, 106, 200, 84, 20, 0, 0x64, 0 },
    { TEXT_CreateIndirect, "ON SCHED", ID_TEXT_HOLD, 200, 200, 84, 20, 0, 0x64, 0 },
    { TEXT_CreateIndirect, "HEATTO", ID_TEXT_HEATTO, 294, 200, 84, 20, 0, 0x64, 0 },
    { TEXT_CreateIndirect, "COOLTO", ID_TEXT_COOLTO, 386, 200, 84, 20, 0, 0x64, 0 },

    { BUTTON_CreateIndirect, "MODE", ID_BUTTON_MODE, 12, 230, 84, BUT_HEIGHT, 0, 0x0, 0 },
    { BUTTON_CreateIndirect, "FAN", ID_BUTTON_FAN, 104, 230, 84, BUT_HEIGHT, 0, 0x0, 0 },
    { BUTTON_CreateIndirect, "HOLD", ID_BUTTON_HOLD, 198, 230, 84, BUT_HEIGHT, 0, 0x0, 0 },
    { BUTTON_CreateIndirect, "HEAT", ID_BUTTON_HEAT, 292, 230, 84, BUT_HEIGHT, 0, 0x0, 0 },
    { BUTTON_CreateIndirect, "COOL", ID_BUTTON_COOL, 384, 230, 84, BUT_HEIGHT, 0, 0x0, 0 },

    { BUTTON_CreateIndirect, "", ID_BUTTON_WIFI, 325, 0, 50, 50, 0, 0x0, 0 },

#ifdef DEBUG_MODE
    { TEXT_CreateIndirect, "", ID_TEXT_DEBUG, 10, 54, 150, 60, 0, 0x64, 0 },
    { TEXT_CreateIndirect, "H", ID_HVAC_HEAT, 264, 13, 15, 20, 0, 0x64, 0 },
    { TEXT_CreateIndirect, "C", ID_HVAC_COOL, 279, 13, 15, 20, 0, 0x64, 0 },
    { TEXT_CreateIndirect, "F", ID_HVAC_FAN, 294, 13, 15, 20, 0, 0x64, 0 },
    { BUTTON_CreateIndirect, "", ID_BUTTON_DEBUG_UP, 18, 150, 50, 50, 0, 0x0, 0 },
    { BUTTON_CreateIndirect, "", ID_BUTTON_DEBUG_DN, 60, 150, 50, 50, 0, 0x0, 0 },
#endif
};

static int holdButtonOn = 0, timerTemp;
static int cool_border, heat_border,  but_pressed, temp_timer;
static GUI_TIMER_HANDLE tempTimer_h;

static float heat_to, cool_to, inside_temperature;

static WM_HWIN holdButton, insideTempIntWin, insideTempFracWin;
static WM_HWIN insideHumidityWin, upButton, dnButton, setPointWin, settingsButWin;
static WM_HWIN modeButton, fanButton, heatButton, coolButton, holdUntil;
static WM_HWIN dateText, timeText, textIndoor;

static char date_buf[20], time_buf[20];
static char *weekDays[] = {"Sun","Mon","Tue","Wed","Thu","Fri","Sat"};

static periods_s myPeriod;
extern struct periods_s getMyPeriod(char *sched, char *d, char *p);
extern struct periods_s getMyTimePeriod(char *sched, int tod, char *day);
extern char * getFormattedTime(int st);
extern char *convertTemp(float temp_set);

extern GUI_CONST_STORAGE GUI_BITMAP bmbig_degree;

extern GUI_CONST_STORAGE GUI_BITMAP bmdn_p;
extern GUI_CONST_STORAGE GUI_BITMAP bmdn_lg;
extern GUI_CONST_STORAGE GUI_BITMAP bmup_p;
extern GUI_CONST_STORAGE GUI_BITMAP bmup_lg;
extern GUI_CONST_STORAGE GUI_BITMAP bmup_s_lg;
extern GUI_CONST_STORAGE GUI_BITMAP bmdn_s_lg;

// debug vars
WM_HWIN textDebug;
WM_HWIN hvacHeat, hvacCool, hvacFan, holdText;
int hide_debug=0;

extern float sensor_temperature;

static void drawButton(char * but, int col)
{
    GUI_RECT rect;
    rect.x0 = 0;
    rect.y0 = 0;
    rect.x1 = 84;
    rect.y1 = BUT_HEIGHT-2;
    GUI_DrawGradientRoundedV(0, 0, rect.x1, rect.y1, 4, color_map[col].stop, color_map[col].start);
    GUI_SetFont(Tahoma18B);
    GUI_SetColor(0xffffff);
    GUI_SetTextMode(GUI_TM_TRANS);
    GUI_DispStringInRect(LANG(but), &rect, GUI_TA_HCENTER | GUI_TA_VCENTER);
}

static void holdUntil_cb(WM_MESSAGE * pMsg)
{
    char nm[50];
    WM_HWIN win = pMsg->hWin;
    GUI_RECT r;
    WM_GetClientRect(&r);
    TEXT_GetText(win, nm, 50);

    switch (pMsg->MsgId)
    {
    case WM_PAINT:
        GUI_DrawGradientRoundedV(0, 0, r.x1, r.y1, 4, 0x00cacaca, 0x00838383);
        GUI_SetFont(Tahoma18B);
        GUI_SetColor(GUI_WHITE);
        GUI_SetTextMode(GUI_TM_TRANS);
        r.y1-=2;
        GUI_DispStringInRect(LANG(nm), &r, GUI_TA_HCENTER | GUI_TA_VCENTER);
        break;
    default:
        TEXT_Callback(pMsg);
        break;
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
        GUI_DrawBitmap(&bmup_s_lg, 0, 0);
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
        GUI_DrawBitmap(&bmdn_s_lg, 0, 0);
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
    switch (pMsg->MsgId)
    {
    case WM_PAINT:
        switch(wifiStrength) {
        case 0:
            GUI_SetColor(0x666666);
            GUI_FillRect(x+21,(y+=5),x+26,ys);
            GUI_FillRect(x+14,(y+=5),x+19,ys);
            GUI_FillRect(x+7,(y+=5),x+12,ys);
            GUI_FillRect(x,(y+=5),x+5,ys);
            break;
        case 1:
            GUI_SetColor(0x666666);
            GUI_FillRect(x+21,(y+=5),x+26,ys);
            GUI_FillRect(x+14,(y+=5),x+19,ys);
            GUI_FillRect(x+7,(y+=5),x+12,ys);
            GUI_SetColor(0xeeeeee);
            GUI_FillRect(x,(y+=5),x+5,ys);
            break;
        case 2:
            GUI_SetColor(0x666666);
            GUI_FillRect(x+21,(y+=5),x+26,ys);
            GUI_FillRect(x+14,(y+=5),x+19,ys);
            GUI_SetColor(0xeeeeee);
            GUI_FillRect(x+7,(y+=5),x+12,ys);
            GUI_FillRect(x,(y+=5),x+5,ys);
            break;
        case 3:
            GUI_SetColor(0x666666);
            GUI_FillRect(x+21,(y+=5),x+26,ys);
            GUI_SetColor(0xeeeeee);
            GUI_FillRect(x+14,(y+=5),x+19,ys);
            GUI_FillRect(x+7,(y+=5),x+12,ys);
            GUI_FillRect(x,(y+=5),x+5,ys);
            break;
        case 4:
            GUI_SetColor(0xeeeeee);
            GUI_FillRect(x+21,(y+=5),x+26,ys);
            GUI_FillRect(x+14,(y+=5),x+19,ys);
            GUI_FillRect(x+7,(y+=5),x+12,ys);
            GUI_FillRect(x,(y+=5),x+5,ys);
            break;
       }
        break;
    default:
        BUTTON_Callback(pMsg);
        break;
    }
}

static void holdModeOptions()
{
    holdButtonOn = holdMode;
    if (!holdMode)
    {
        WM_SetCallback(holdButton, hold_button_off);
        WM_EnableWindow(modeButton);
        WM_EnableWindow(coolButton);
        WM_EnableWindow(heatButton);
        WM_EnableWindow(fanButton);
        WM_SetCallback(modeButton, buttonOn_cb);
        WM_SetCallback(fanButton, buttonOn_cb);
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
        WM_SetCallback(modeButton, buttonOff_cb);
        WM_SetCallback(fanButton, buttonOff_cb);
        WM_SetCallback(coolButton, coolButton_cb);
        WM_SetCallback(heatButton, heatButton_cb);
        TEXT_SetText(holdText, "ON HOLD");
    }
    WM_InvalidateWindow(modeButton);
    WM_InvalidateWindow(fanButton);
    WM_InvalidateWindow(coolButton);
    WM_InvalidateWindow(heatButton);
}

static void tempTimer(GUI_TIMER_MESSAGE * pTM)
{
    char buf[10];
    float inside_temp;

    if (metric)
    {
        inside_temp = (insideTemperature - 32.) * 5./9.;
    }
    else
    {
        inside_temp = insideTemperature;
    }
    sprintf(buf,"%d", (int)inside_temp);
    TEXT_SetText(insideTempIntWin, buf);

    sprintf(buf,"%1d", (int)(((inside_temp - (int)inside_temp) * 100)/10));
    TEXT_SetText(insideTempFracWin, buf);

    TEXT_SetText(textIndoor, LANG("INDOOR"));
    temp_timer = 0;
}

static void convertIntTemp(float temp_set)
{
    char buf[10];
    float inside_temp;

    if (metric)
    {
        inside_temp = (temp_set - 32.) * 5./9.;
    }
    else
    {
        inside_temp = temp_set;
    }
    sprintf(buf,"%d", (int)inside_temp);
    TEXT_SetText(insideTempIntWin, buf);

    sprintf(buf,"%1d", (int)(((inside_temp - (int)inside_temp) * 100)/10));
    TEXT_SetText(insideTempFracWin, buf);
}

void _cbDialog(WM_MESSAGE * pMsg)
{
    WM_HWIN hItem;
    int     NCode;
    int     Id;
    char		buffer[50];
    GUI_COLOR textColor = 0xffffff;

    switch (pMsg->MsgId)
    {
    case WM_PAINT:
        GUI_DrawGradientV(0, 0, 480, 50, color_map[0].stop, color_map[0].start);

        GUI_DrawBitmap(&bmwatermark, 10,52);
        GUI_DrawBitmap(&bmbig_degree, 296,84);

        if (metric)
        {
            GUI_SetColor(0x808080);
            GUI_AA_FillCircle(301, 162, 3);
        }

        GUI_SetColor(0xcecece);
        GUI_DrawVLine(342, 75, 170);
        GUI_DrawVLine(343, 75, 170);

        GUI_DrawGradientV(0, 198, 480, 223, 0x00cacaca, 0x00838383);

        break;
    case WM_INIT_DIALOG:
        dateText = WM_GetDialogItem(pMsg->hWin, ID_TEXT_DATE);
        TEXT_SetTextAlign(dateText, GUI_TA_LEFT | GUI_TA_VCENTER);
        TEXT_SetFont(dateText, Tahoma23B);
        TEXT_SetTextColor(dateText, textColor);
        TEXT_SetText(dateText, date_buf);
        //
        timeText = WM_GetDialogItem(pMsg->hWin, ID_TEXT_TIME);
        TEXT_SetText(timeText, time_buf);
        TEXT_SetTextAlign(timeText, GUI_TA_LEFT | GUI_TA_VCENTER);
        TEXT_SetFont(timeText, Tahoma23B);
        TEXT_SetTextColor(timeText, textColor);
        //
        hItem = WM_GetDialogItem(pMsg->hWin, ID_BUTTON_WIFI);
        WM_SetCallback(hItem, wifi_cb);

        holdUntil = WM_GetDialogItem(pMsg->hWin, ID_TEXT_HOLD_UNTIL);
        WM_SetCallback(holdUntil, holdUntil_cb);
        WM_HideWindow(holdUntil);

#ifdef DEBUG_MODE
        hItem = WM_GetDialogItem(pMsg->hWin, ID_BUTTON_DEBUG_UP);
        WM_SetCallback(hItem, upUpperButton_cb);
        //
        hItem = WM_GetDialogItem(pMsg->hWin, ID_BUTTON_DEBUG_DN);
        WM_SetCallback(hItem, dnUpperButton_cb);

        hvacHeat = WM_GetDialogItem(pMsg->hWin, ID_HVAC_HEAT);
        TEXT_SetFont(hvacHeat, Tahoma23B);
        TEXT_SetTextColor(hvacHeat, GUI_RED);
        if (heat_control)
        {
            WM_ShowWindow(hvacHeat);
        }
        else
        {
            WM_HideWindow(hvacHeat);
        }

        hvacCool = WM_GetDialogItem(pMsg->hWin, ID_HVAC_COOL);
        TEXT_SetFont(hvacCool, Tahoma23B);
        TEXT_SetTextColor(hvacCool, GUI_CYAN);
        if (cool_control)
        {
            WM_ShowWindow(hvacCool);
        }
        else
        {
            WM_HideWindow(hvacCool);
        }

        hvacFan = WM_GetDialogItem(pMsg->hWin, ID_HVAC_FAN);
        TEXT_SetFont(hvacFan, Tahoma23B);
        TEXT_SetTextColor(hvacFan, GUI_YELLOW);
        if (fan_control)
        {
            WM_ShowWindow(hvacFan);
        }
        else
        {
            WM_HideWindow(hvacFan);
        }
#endif

        sprintf(buffer, "%d°  |  %d%%", localTemperature, localHumidity);
        hItem = WM_GetDialogItem(pMsg->hWin, ID_TEXT_OUT_TEMP);
        TEXT_SetText(hItem, buffer);
        TEXT_SetFont(hItem, Tahoma18B);
        TEXT_SetTextColor(hItem, textColor);
        //
        hItem = WM_GetDialogItem(pMsg->hWin, ID_TEXT_OUTSIDE);
        TEXT_SetFont(hItem, Tahoma18B);
        TEXT_SetTextColor(hItem, textColor);
        TEXT_SetText(hItem, LANG("OUTSIDE"));
        //
        settingsButWin = WM_GetDialogItem(pMsg->hWin, ID_BUTTON_SETTINGS);
        WM_SetCallback(settingsButWin, buttonOn_cb);

        cool_border = (strcmp(hvacMode, "cool") == 0);
        heat_border = strcmp(hvacMode, "heat") == 0;

        modeButton = WM_GetDialogItem(pMsg->hWin, ID_BUTTON_MODE);
        WM_SetCallback(modeButton, buttonOn_cb);
        //
        fanButton = WM_GetDialogItem(pMsg->hWin, ID_BUTTON_FAN);
        WM_SetCallback(fanButton, buttonOn_cb);
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
        TEXT_SetTextColor(textIndoor, 0x808080);
        TEXT_SetFont(textIndoor, Tahoma19B);
        TEXT_SetText(textIndoor, LANG("INDOOR"));
        //
        insideTempIntWin = WM_GetDialogItem(pMsg->hWin, ID_TEXT_INSIDE_INT_TEMP);
        TEXT_SetFont(insideTempIntWin,Tahoma129B);
        TEXT_SetTextColor(insideTempIntWin, 0x00808080);
//
        insideTempFracWin = WM_GetDialogItem(pMsg->hWin, ID_TEXT_INSIDE_FRAC_TEMP);
        TEXT_SetFont(insideTempFracWin, Tahoma58);
        TEXT_SetTextColor(insideTempFracWin, 0x00808080);

        convertIntTemp(inside_temperature);
        //
        insideHumidityWin = WM_GetDialogItem(pMsg->hWin, ID_TEXT_HUMIDITY);
        TEXT_SetFont(insideHumidityWin, Tahoma19B);
        TEXT_SetTextColor(insideHumidityWin, 0x808080);
        sprintf(buffer, "%d%% %s", insideHumidity, LANG("HUMIDITY"));
        TEXT_SetText(insideHumidityWin, buffer);
        if (metric)
        {
            WM_ShowWindow(insideTempFracWin);
        }
        else
        {
            WM_HideWindow(insideTempFracWin);
        }

        hItem = WM_GetDialogItem(pMsg->hWin, ID_TEXT_SET_TO);
        TEXT_SetTextAlign(hItem, GUI_TA_HCENTER | GUI_TA_VCENTER);
        TEXT_SetTextColor(hItem, 0x808080);
        TEXT_SetFont(hItem, &GUI_FontLucidaSans15hAA4);
        sprintf(buffer, LANG("SET TO"));
        TEXT_SetText(hItem, buffer);

        setPointWin = WM_GetDialogItem(pMsg->hWin, ID_TEXT_SET_TO_TEMP);
        TEXT_SetTextAlign(setPointWin, GUI_TA_HCENTER | GUI_TA_VCENTER);
        TEXT_SetTextColor(setPointWin, 0x666666);
        TEXT_SetFont(setPointWin, Tahoma23B);
        sprintf(buffer, "%s°", convertTemp(temperatureSetPoint));
        TEXT_SetText(setPointWin, buffer);

        upButton = WM_GetDialogItem(pMsg->hWin, ID_BUTTON_UP);
        WM_SetCallback(upButton, upButton_cb);
        //
        dnButton = WM_GetDialogItem(pMsg->hWin, ID_BUTTON_DN);
        WM_SetCallback(dnButton, dnButton_cb);
        //
        hvacModeText = WM_GetDialogItem(pMsg->hWin, ID_TEXT_MODE);
        TEXT_SetTextAlign(hvacModeText, GUI_TA_HCENTER | GUI_TA_VCENTER);
        TEXT_SetFont(hvacModeText, Tahoma18B);
        TEXT_SetTextColor(hvacModeText, 0x00FFFFFF);
        TEXT_SetText(hvacModeText, LANG(toup(hvacMode)));
        //
        fanModeText = WM_GetDialogItem(pMsg->hWin, ID_TEXT_FAN);
        TEXT_SetTextAlign(fanModeText, GUI_TA_HCENTER | GUI_TA_VCENTER);
        TEXT_SetFont(fanModeText, Tahoma18B);
        TEXT_SetTextColor(fanModeText, 0x00FFFFFF);
        TEXT_SetText(fanModeText, LANG(toup(fanMode)));

        holdText = WM_GetDialogItem(pMsg->hWin, ID_TEXT_HOLD);
        TEXT_SetTextAlign(holdText, GUI_TA_HCENTER | GUI_TA_VCENTER);
        TEXT_SetFont(holdText, Tahoma18B);
        TEXT_SetTextColor(holdText, 0x00FFFFFF);
        TEXT_SetText(holdText, LANG("ON SCHED"));
        //
        if (strcmp(hvacMode, "auto") == 0)
        {
            heat_to = heatToDegrees;
            cool_to = coolToDegrees;
        }
        else
        {
            heat_to = scheduleTemperature(getScheduleTime(), currentSchedule, "heat");
            cool_to = scheduleTemperature(getScheduleTime(), currentSchedule, "cool");
        }

        heatToWin = WM_GetDialogItem(pMsg->hWin, ID_TEXT_HEATTO);
        TEXT_SetTextAlign(heatToWin, GUI_TA_HCENTER | GUI_TA_VCENTER);
        TEXT_SetFont(heatToWin, Tahoma18B);
        TEXT_SetTextColor(heatToWin, 0x00FFFFFF);
        sprintf(buffer, "%s°", convertTemp(heat_to));
        TEXT_SetText(heatToWin, buffer);

        coolToWin = WM_GetDialogItem(pMsg->hWin, ID_TEXT_COOLTO);
        TEXT_SetTextAlign(coolToWin, GUI_TA_HCENTER | GUI_TA_VCENTER);
        TEXT_SetFont(coolToWin, Tahoma18B);
        TEXT_SetTextColor(coolToWin, 0x00FFFFFF);
        sprintf(buffer, "%s°", convertTemp(cool_to));
        TEXT_SetText(coolToWin, buffer);

        textDebug = WM_GetDialogItem(pMsg->hWin, ID_TEXT_DEBUG);
        TEXT_SetTextColor(textDebug, GUI_BLACK);
        TEXT_SetFont(textDebug, Tahoma16B);

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
        case ID_TEXT_OUTSIDE:
            switch(NCode)
            {
            case WM_NOTIFICATION_CLICKED:
                hide_debug = !hide_debug;

                WM_HideWindow(hvacHeat);
                WM_HideWindow(hvacCool);
                WM_HideWindow(hvacFan);
                hItem = WM_GetDialogItem(pMsg->hWin, ID_BUTTON_DEBUG_UP);
                WM_HideWindow(hItem);
                hItem = WM_GetDialogItem(pMsg->hWin, ID_BUTTON_DEBUG_DN);
                WM_HideWindow(hItem);
                WM_HideWindow(textDebug);
                WM_HideWindow(hvacHeat);
                WM_HideWindow(hvacCool);
                WM_HideWindow(hvacFan);

                if (!hide_debug)
                {
                    hItem = WM_GetDialogItem(pMsg->hWin, ID_BUTTON_DEBUG_UP);
                    WM_ShowWindow(hItem);
                    hItem = WM_GetDialogItem(pMsg->hWin, ID_BUTTON_DEBUG_DN);
                    WM_ShowWindow(hItem);
                    WM_ShowWindow(textDebug);
                    if (heat_control)
                    {
                        WM_ShowWindow(hvacHeat);
                    }
                    else
                    {
                        WM_HideWindow(hvacHeat);
                    }

                    if (cool_control)
                    {
                        WM_ShowWindow(hvacCool);
                    }
                    else
                    {
                        WM_HideWindow(hvacCool);
                    }

                    if (fan_control)
                    {
                        WM_ShowWindow(hvacFan);
                    }
                    else
                    {
                        WM_HideWindow(hvacFan);
                    }
                }
                break;
            }
            break;
        case ID_BUTTON_DEBUG_UP:
            switch(NCode)
            {
            case WM_NOTIFICATION_CLICKED:
                inside_temperature += .5;
                sensor_temperature = (5./9.)*(inside_temperature-32.);
                hvacControlCode();
                break;
            }
            break;
        case ID_BUTTON_DEBUG_DN:
            switch(NCode)
            {
            case WM_NOTIFICATION_CLICKED:
                inside_temperature -= .5;
                sensor_temperature = (5./9.)*(inside_temperature-32.);
                hvacControlCode();
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
//                //GUI_TIMER_SetPeriod(lockTimer_h, 9999999);
//                GUI_TIMER_Restart(lockTimer_h);
//                GUI_Delay(100);
                WM_HideWindow(homeWin);
                WM_ShowWindow(settingsWin);
                screenState = NOWIN;
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

                temperatureSetPoint++;
                if (temperatureSetPoint == 86.) temperatureSetPoint = 85.;
                sprintf(buffer,"%s %s°", LANG("SET TO"), convertTemp(temperatureSetPoint));
                TEXT_SetText(textIndoor, buffer);

                sprintf(buffer,"%s°", convertTemp(temperatureSetPoint));
                hItem = WM_GetDialogItem(pMsg->hWin, ID_TEXT_SET_TO_TEMP);
                TEXT_SetText(hItem, buffer);

                timerTemp = (int)temperatureSetPoint;
                convertIntTemp(temperatureSetPoint);

                if (strcmp(hvacMode, "heat") == 0)
                {
                    if (temperatureSetPoint > scheduleTemperature(getScheduleTime(),
                                                                  currentSchedule, hvacMode))
                    {
                        sprintf(buffer,"Hold Until\n%s",
                                     getFormattedTime(getMyPeriod(currentSchedule, currentSchedule,myPeriod.next).startTime));
                        TEXT_SetText(holdUntil, buffer);
                        WM_MoveTo(settingsButWin, 14, 84);
                        WM_ShowWindow(holdUntil);
                        holdMode = 1;
                    }
                }
                else
                {
                    if (temperatureSetPoint >= scheduleTemperature(getScheduleTime(),
                                                                   currentSchedule, hvacMode))
                    {
                        WM_MoveTo(settingsButWin, 14, 110);
                        WM_HideWindow(holdUntil);
                        holdMode = 0;
                    }
                }
                break;
            case WM_NOTIFICATION_RELEASED:
                GUI_TIMER_SetPeriod(tempTimer_h, 3000);
                GUI_TIMER_Restart(tempTimer_h);
                WM_MoveWindow(upButton, 1, 0);
                temp_timer = 1;
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
                temperatureSetPoint--;
                if (temperatureSetPoint == 64.) temperatureSetPoint = 65.;
                if (heatToDegrees < coolToDegrees) heatToDegrees = coolToDegrees;

                sprintf(buffer,"%s %s°", LANG("SET TO"), convertTemp(temperatureSetPoint));
                TEXT_SetText(textIndoor, buffer);

                sprintf(buffer,"%s°", convertTemp(temperatureSetPoint));
                hItem = WM_GetDialogItem(pMsg->hWin, ID_TEXT_SET_TO_TEMP);
                TEXT_SetText(hItem, buffer);

                timerTemp = (int)temperatureSetPoint;
                convertIntTemp(temperatureSetPoint);

                if (strcmp(hvacMode, "heat") == 0)
                {
                    if (temperatureSetPoint <= scheduleTemperature(getScheduleTime(), currentSchedule, hvacMode))
                    {
                        WM_MoveTo(settingsButWin, 14, 110);
                        WM_HideWindow(holdUntil);
                        holdMode = 0;
                    }
                }
                else
                {
                    if (temperatureSetPoint < scheduleTemperature(getScheduleTime(), currentSchedule, hvacMode))
                    {
                        sprintf(buffer,"Hold Until\n%s",
                                     getFormattedTime(getMyPeriod(currentSchedule, currentSchedule,myPeriod.next).startTime));
                        TEXT_SetText(holdUntil, buffer);
                        WM_MoveTo(settingsButWin, 14, 84);
                        WM_ShowWindow(holdUntil);
                        holdMode = 1;
                    }
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
        case ID_BUTTON_HEAT:
            switch(NCode)
            {
            case WM_NOTIFICATION_CLICKED:
                if (strcmp(hvacMode, "auto") == 0)
                {
                    CreateHeatTo();
                }
                else
                {
                    cool_border = 0;
                    heat_border = 1;
                    WM_SetCallback(heatButton, heatButton_cb);
                    WM_SetCallback(coolButton, coolButton_cb);
                    strcpy(hvacMode, "heat");
                    TEXT_SetText(hvacModeText, LANG("HEAT"));
                    temperatureSetPoint = scheduleTemperature(getScheduleTime(), currentSchedule, hvacMode);
                    sprintf(buffer,"%s°", convertTemp(temperatureSetPoint));
                    hItem = WM_GetDialogItem(pMsg->hWin, ID_TEXT_SET_TO_TEMP);
                    TEXT_SetText(hItem, buffer);
                    WM_HideWindow(holdUntil);
                    holdMode = 0;
               }
                break;
            }
            break;
        case ID_BUTTON_COOL:
            switch(NCode)
            {
            case WM_NOTIFICATION_CLICKED:
                if (strcmp(hvacMode, "auto") == 0)
                {
                    CreateCoolTo();
                }
                else
                {
                    cool_border = 1;
                    heat_border = 0;
                    WM_SetCallback(heatButton, heatButton_cb);
                    WM_SetCallback(coolButton, coolButton_cb);
                    strcpy(hvacMode, "cool");
                    TEXT_SetText(hvacModeText, LANG("COOL"));
                    temperatureSetPoint = scheduleTemperature(getScheduleTime(), currentSchedule, hvacMode);
                    sprintf(buffer,"%s°", convertTemp((float)temperatureSetPoint));
                    hItem = WM_GetDialogItem(pMsg->hWin, ID_TEXT_SET_TO_TEMP);
                    TEXT_SetText(hItem, buffer);
                    WM_HideWindow(holdUntil);
                    holdMode = 0;
                }
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
                    WM_SetCallback(fanButton, buttonOn_cb);
                    WM_EnableWindow(coolButton);
                    WM_EnableWindow(heatButton);
                    WM_EnableWindow(fanButton);
                    WM_SetCallback(modeButton, buttonOn_cb);
                    WM_SetCallback(coolButton, coolButton_cb);
                    WM_SetCallback(heatButton, heatButton_cb);
                    TEXT_SetText(holdText, "ON SCHED");

                    if (cool_border)
                    {
                        sprintf(buffer,"%s°",
                                convertTemp(scheduleTemperature(getScheduleTime(), currentSchedule, "cool")));
                        TEXT_SetText(setPointWin, buffer);
                    }
                    else
                    {
                        sprintf(buffer,"%s°",
                                convertTemp(scheduleTemperature(getScheduleTime(), currentSchedule, "heat")));
                        TEXT_SetText(setPointWin, buffer);
                    }

                    sprintf(buffer,"%s°",
                            convertTemp(scheduleTemperature(getScheduleTime(), currentSchedule, "cool")));
                    TEXT_SetText(coolToWin, buffer);
                    sprintf(buffer,"%s°",
                            convertTemp(scheduleTemperature(getScheduleTime(), currentSchedule, "heat")));
                    TEXT_SetText(heatToWin, buffer);
                }
                else
                {
                    WM_SetCallback(holdButton, hold_button_on);
                    WM_DisableWindow(modeButton);
                    WM_DisableWindow(coolButton);
                    WM_DisableWindow(heatButton);
                    WM_DisableWindow(fanButton);
                    WM_SetCallback(modeButton, buttonOff_cb);
                    WM_SetCallback(fanButton, buttonOff_cb);
                    WM_SetCallback(coolButton, coolButton_cb);
                    WM_SetCallback(heatButton, heatButton_cb);
                    TEXT_SetText(holdText, "ON HOLD");

                    sprintf(buffer,"%s°", convertTemp(temperatureSetPoint));
                    TEXT_SetText(setPointWin, buffer);
                    TEXT_SetText(coolToWin, buffer);
                    TEXT_SetText(heatToWin, buffer);
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
        }
        break;
    default:
        WM_DefaultProc(pMsg);
        break;
    }
}
//#define CODEBLOCK
static void getDateTime()
{
#ifdef CODEBLOCK
    time_t now = time(NULL);
    struct tm *info;
    time( &now );
    info = localtime( &now );
    info->tm_mday;

    sprintf(date_buf, "%s %2d/%2d/%2d", LANG(weekDays[info->tm_wday]),
            info->tm_mon+1,info->tm_mday,(info->tm_year-100));

    int h = (info->tm_hour > 12) ? info->tm_hour - 12 : info->tm_hour ;
    sprintf(time_buf, "%3d:%02d %s", h, info->tm_min, (info->tm_hour > 12) ? "PM" : "AM");
#else
    RTC_TimeTypeDef tm;
    RTC_DateTypeDef dt;

    BSP_RTC_GetTime(&tm);
    BSP_RTC_GetDate(&dt);

    int h = (tm.Hours > 12) ? tm.Hours - 12 : tm.Hours;
    sprintf(time_buf, "%3d:%02d %s", h, tm.Minutes, (tm.Hours > 12) ? "PM" : "AM");

    sprintf(date_buf, "%s %02d/%02d/%d", LANG(weekDays[dt.WeekDay]), dt.Month, dt.Date, dt.Year);
#endif
}

static void dateTimer(GUI_TIMER_MESSAGE * pTM)
{
    char buffer[10];
    float inside_temp;
    getDateTime();
    TEXT_SetText(dateText, date_buf);
    TEXT_SetText(timeText, time_buf);

    if (but_pressed || temp_timer) return;
    if (metric)
    {
        inside_temp = (insideTemperature - 32.) * 5./9.;
    }
    else
    {
        inside_temp = insideTemperature;
    }

    if (strcmp(hvacMode, "auto") == 0)
    {
        heat_to = heatToDegrees;
        cool_to = coolToDegrees;
        temperatureSetPoint = cool_to - ((cool_to - heat_to)/2.);
        sprintf(buffer,"%s°", convertTemp(temperatureSetPoint));
        TEXT_SetText(setPointWin, buffer);
    }
    else
    {
        if (holdMode) {

        } else {
            heat_to = scheduleTemperature(getScheduleTime(), currentSchedule, "heat");
            cool_to = scheduleTemperature(getScheduleTime(), currentSchedule, "cool");

            if (strcmp(hvacMode, "cool") == 0) {
               temperatureSetPoint = cool_to;
            } else {
               temperatureSetPoint = heat_to;
            }
            sprintf(buffer,"%s°", convertTemp(temperatureSetPoint));
            TEXT_SetText(setPointWin, buffer);

            sprintf(buffer, "%s°", convertTemp(heat_to));
            TEXT_SetText(heatToWin, buffer);

            sprintf(buffer, "%s°", convertTemp(cool_to));
            TEXT_SetText(coolToWin, buffer);
       }
    }

    sprintf(buffer,"%d", (int)inside_temp);
    TEXT_SetText(insideTempIntWin, buffer);

    sprintf(buffer,"%1d", (int)(((inside_temp - (int)inside_temp) * 100)/10));
    TEXT_SetText(insideTempFracWin, buffer);

    sprintf(buffer, "%d%% %s", insideHumidity, LANG("HUMIDITY"));
    TEXT_SetText(insideHumidityWin, buffer);
    //
    GUI_TIMER_SetPeriod(pTM->hTimer, 2000);
    GUI_TIMER_Restart(pTM->hTimer);
}

WM_HWIN CreateHomeWin(void);
WM_HWIN CreateHomeWin(void)
{
    WM_HWIN hWin;
    getDateTime();

    if (!tempTimerSet)
    {
        GUI_TIMER_Create(dateTimer, 5000, 0, 0);
        tempTimer_h = GUI_TIMER_Create(tempTimer, 0, 0, 0);
        tempTimerSet = 1;
    }

    myPeriod = getMyPeriod(currentSchedule, currentSchedule,
                           getMyTimePeriod(currentSchedule, getScheduleTime(), currentSchedule).label );
    temperatureSetPoint = scheduleTemperature(getScheduleTime(), currentSchedule, hvacMode);
    inside_temperature = insideTemperature;

    hWin = GUI_CreateDialogBox(_aDialogCreate, GUI_COUNTOF(_aDialogCreate), _cbDialog, WM_HBKWIN, 0, 0);
    WM_HideWindow(hWin);
    return hWin;
}
