#include "ranger.h"

#define ID_HOME_WINDOW     (GUI_ID_USER + 0x00)
#define ID_TEXT_INSIDE_INT_TEMP       (GUI_ID_USER + 0x07)
#define ID_TEXT_DATE     (GUI_ID_USER + 0x10)
#define ID_TEXT_OUT_TEMP     (GUI_ID_USER + 0x11)
#define ID_TEXT_TIME     (GUI_ID_USER + 0x12)
#define ID_TEXT_OUTSIDE     (GUI_ID_USER + 0x13)
#define ID_TEXT_HUMIDITY     (GUI_ID_USER + 0x14)
#define ID_TEXT_INDOOR     (GUI_ID_USER + 0x15)
#define ID_BUTTON_DEGREES     (GUI_ID_USER + 0x16)
#define ID_BUTTON_DEGREES_SET     (GUI_ID_USER + 0x17)
#define ID_BUTTON_WIFI     (GUI_ID_USER + 0x18)
#define ID_BUTTON_TOUCH     (GUI_ID_USER + 0x19)
#define ID_TEXT_IDLE     (GUI_ID_USER + 0x20)
#define ID_TEXT_INSIDE_FRAC_TEMP       (GUI_ID_USER + 0x21)

static const GUI_WIDGET_CREATE_INFO _aDialogCreate[] =
{
    { WINDOW_CreateIndirect, "HomeWin", ID_HOME_WINDOW, 0, 0, 480, 272, 0, 0x0, 0 },
    { TEXT_CreateIndirect, "", ID_TEXT_IDLE, 0, 0, 480, 270, 0, 0x64, 0 },
    { TEXT_CreateIndirect, "In_T_Panel", ID_TEXT_INSIDE_INT_TEMP, 162, 88, 135, 120, 0, 0x64, 0 },
    { TEXT_CreateIndirect, "FRAC Temp", ID_TEXT_INSIDE_FRAC_TEMP, 306, 146, 50, 90, 0, 0x64, 0 },
    { TEXT_CreateIndirect, "", ID_TEXT_DATE, 10, 0, 140, 50, 0, 0x64, 0 },
    { TEXT_CreateIndirect, "", ID_TEXT_TIME, 160, 0, 150, 50, 0, 0x64, 0 },
    { TEXT_CreateIndirect, "Out_T_Temp", ID_TEXT_OUT_TEMP, 370, 7, 100, 20, 0, 0x64, 0 },
    { TEXT_CreateIndirect, "OUTSIDE", ID_TEXT_OUTSIDE, 380, 26, 70, 20, 0, 0x64, 0 },
    { TEXT_CreateIndirect, "INDOOR", ID_TEXT_INDOOR, 165, 92, 89, 20, 0, 0x64, 0 },
    { TEXT_CreateIndirect, "HUMIDITY", ID_TEXT_HUMIDITY, 165, 202, 160, 20, 0, 0x64, 0 },
    { BUTTON_CreateIndirect, "", ID_BUTTON_WIFI, 320, 0, 50, 50, 0, 0x0, 0 },
};

static GUI_TIMER_HANDLE tempTimer_h;
static char *weekDays[] = {"Sun","Mon","Tue","Wed","Thu","Fri","Sat","Sun"};

static WM_HWIN insideTempIntText, insideTempFracText, insideHumidityText;

static char date_buf[20];
static char time_buf[20];
extern GUI_CONST_STORAGE GUI_BITMAP bmbig_degree;

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
    TEXT_SetText(insideTempIntText, buf);

    sprintf(buf,"%1d", (int)(((inside_temp - (int)inside_temp) * 100)/10));
    TEXT_SetText(insideTempFracText, buf);
}

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
        GUI_SetColor(0xdbdbdb);
        GUI_FillRect(7,(y+=5),12,ys);
        GUI_FillRect(0,(y+=5),5,ys);
        break;
    default:
        return BUTTON_DrawSkinFlex(pDrawItemInfo);
    }
}

WM_HWIN dateText, timeText, textIndoor;

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
        GUI_DrawGradientV(0, 0, 480, 50, color_map[0].stop, color_map[0].start);
        GUI_DrawBitmap(&bmwatermark, 45,52);
        GUI_DrawBitmap(&bmbig_degree, 296,112);

        if (metric)
        {
            GUI_SetColor(0x808080);
            GUI_FillCircle(302, 190, 4);
        }
       break;
    case WM_INIT_DIALOG:
        hItem = pMsg->hWin;

        hItem = WM_GetDialogItem(pMsg->hWin, ID_BUTTON_WIFI);
        BUTTON_SetSkin(hItem, wifiSkin);

        dateText = WM_GetDialogItem(pMsg->hWin, ID_TEXT_DATE);
        TEXT_SetText(dateText, date_buf);
        TEXT_SetTextAlign(dateText, GUI_TA_LEFT | GUI_TA_VCENTER);
        TEXT_SetFont(dateText, Tahoma23B);
        TEXT_SetTextColor(dateText, textColor);
        //
        timeText = WM_GetDialogItem(pMsg->hWin, ID_TEXT_TIME);
        TEXT_SetText(timeText, time_buf);
        TEXT_SetTextAlign(timeText, GUI_TA_LEFT | GUI_TA_VCENTER);
        TEXT_SetFont(timeText, Tahoma23B);
        TEXT_SetTextColor(timeText, textColor);
        //
        sprintf(buffer, "%d°  |  %d%%", localTemperature, localHumidity);
        hItem = WM_GetDialogItem(pMsg->hWin, ID_TEXT_OUT_TEMP);
        TEXT_SetText(hItem, buffer);
        TEXT_SetFont(hItem, Tahoma18B);
        TEXT_SetTextColor(hItem, textColor);
        //
        hItem = WM_GetDialogItem(pMsg->hWin, ID_TEXT_OUTSIDE);
        TEXT_SetFont(hItem, Tahoma18B);
        TEXT_SetText(hItem, LANG("OUTSIDE"));
        TEXT_SetTextColor(hItem, textColor);
        //
        insideTempIntText = WM_GetDialogItem(pMsg->hWin, ID_TEXT_INSIDE_INT_TEMP);
        TEXT_SetFont(insideTempIntText,Tahoma129B);
        TEXT_SetTextColor(insideTempIntText, 0x00808080);
//
        insideTempFracText = WM_GetDialogItem(pMsg->hWin, ID_TEXT_INSIDE_FRAC_TEMP);
        TEXT_SetFont(insideTempFracText, Tahoma58);
        TEXT_SetTextColor(insideTempFracText, 0x00808080);
        if (!metric)
        {
            WM_HideWindow(insideTempFracText);
        }

        convertIntTemp(insideTemperature);

        textIndoor = WM_GetDialogItem(pMsg->hWin, ID_TEXT_INDOOR);
        TEXT_SetText(textIndoor, LANG("INDOOR"));
        TEXT_SetTextColor(textIndoor, 0x808080);
        TEXT_SetFont(textIndoor, Tahoma19B);
        //
        sprintf(buffer, "%d%% %s", insideHumidity, LANG("HUMIDITY"));
        insideHumidityText = WM_GetDialogItem(pMsg->hWin, ID_TEXT_HUMIDITY);
        TEXT_SetFont(insideHumidityText, Tahoma19B);
        TEXT_SetTextColor(insideHumidityText, 0x808080);
        TEXT_SetText(insideHumidityText, buffer);

        break;
    case WM_NOTIFY_PARENT:
        Id    = WM_GetId(pMsg->hWinSrc);
        NCode = pMsg->Data.v;
        if (NCode == 1) {
            GUI_TIMER_SetPeriod(lockTimer_h, idleTimeOut);
            GUI_TIMER_Restart(lockTimer_h);
            WM_HideWindow(idleWin);
            WM_ShowWindow(homeWin);
        }
        break;
    default:
        WM_DefaultProc(pMsg);
        break;
    }
}

static void setDateTime() {
#ifdef CODEBLOCK
    time_t now = time(NULL);
    struct tm *info;
    time( &now );
    info = localtime( &now );
    info->tm_mday;
    char day[5];

    strcpy(day, weekDays[info->tm_wday]);

    sprintf(date_buf, "%s %2d/%2d/%2d", LANG(day), info->tm_mon+1,info->tm_mday,(info->tm_year-100));

    int h = (info->tm_hour > 12) ? info->tm_hour - 12 : info->tm_hour ;
    sprintf(time_buf, "%3d:%02d %s", h, info->tm_min, (info->tm_hour > 12) ? "PM" : "AM");
#else
    RTC_TimeTypeDef tm;
    RTC_DateTypeDef dt;

    BSP_RTC_GetTime(&tm);
    BSP_RTC_GetDate(&dt);

    int h = (tm.Hours > 12) ? tm.Hours - 12 : tm.Hours;
    sprintf(time_buf, "%d:%02d %s", h, tm.Minutes, (tm.Hours > 12) ? "PM" : "AM");

    sprintf(date_buf, "%s %02d/%02d/%d", LANG(weekDays[dt.WeekDay]), dt.Month, dt.Date, dt.Year);
#endif
}

static void dateTimer(GUI_TIMER_MESSAGE * pTM)
{
    setDateTime();
    TEXT_SetText(dateText, date_buf);
    TEXT_SetText(timeText, time_buf);
    float inside_temp;

    //if (but_pressed || temp_timer) return;
    if (metric)
    {
        inside_temp = (insideTemperature - 32.) * 5./9.;
    }
    else
    {
        inside_temp = insideTemperature;
    }

    char buffer[10];
    sprintf(buffer,"%d", (int)inside_temp);
    TEXT_SetText(insideTempIntText, buffer);

    sprintf(buffer,"%1d", (int)(((inside_temp - (int)inside_temp) * 100)/10));
    TEXT_SetText(insideTempFracText, buffer);

    sprintf(buffer, "%d%% %s", insideHumidity, LANG("HUMIDITY"));
    TEXT_SetText(insideHumidityText, buffer);
    //
    GUI_TIMER_SetPeriod(pTM->hTimer, 2000);
    GUI_TIMER_Restart(pTM->hTimer);
}

WM_HWIN CreateIdleWin(void);
WM_HWIN CreateIdleWin(void)
{
    WM_HWIN hWin;

    setDateTime();

    if (!tempTimerSet)
    {
        GUI_TIMER_Create(dateTimer, 60000, 0, 0);
    }

    hWin = GUI_CreateDialogBox(_aDialogCreate, GUI_COUNTOF(_aDialogCreate), _cbDialog, WM_HBKWIN, 0, 0);
    WM_HideWindow(hWin);

    return hWin;
}
