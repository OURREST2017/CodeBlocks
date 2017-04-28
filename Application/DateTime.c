#include "ranger.h"

#define ID_WINDOW_0  (GUI_ID_USER + 0x00)
#define ID_WINDOW_1  (GUI_ID_USER + 0x23)
#define ID_WINDOW_2  (GUI_ID_USER + 0x24)
#define ID_HEADER_0  (GUI_ID_USER + 0x01)
#define ID_TEXT_HEADER (GUI_ID_USER + 0x02)
#define ID_BUTTON_HOUR_UP  (GUI_ID_USER + 0x03)
#define ID_BUTTON_HOUR_DN  (GUI_ID_USER + 0x04)
#define ID_BUTTON_MONTH_UP  (GUI_ID_USER + 0x06)
#define ID_BUTTON_MONTH_DN  (GUI_ID_USER + 0x07)
#define ID_BUTTON_MINUTE_UP  (GUI_ID_USER + 0x09)
#define ID_BUTTON_MINUTE_DN  (GUI_ID_USER + 0x0A)
#define ID_BUTTON_DAY_UP  (GUI_ID_USER + 0x0C)
#define ID_BUTTON_DAY_DN  (GUI_ID_USER + 0x0D)
#define ID_BUTTON_AMPM_UP  (GUI_ID_USER + 0x0F)
#define ID_BUTTON_AMPM_DN  (GUI_ID_USER + 0x10)
#define ID_BUTTON__YEAR_UP  (GUI_ID_USER + 0x12)
#define ID_BUTTON_YEAR_DN  (GUI_ID_USER + 0x13)
#define ID_BUTTON_CANCEL  (GUI_ID_USER + 0x14)
#define ID_BUTTON_SAVE  (GUI_ID_USER + 0x15)
#define ID_EDIT_HOUR  (GUI_ID_USER + 0x16)
#define ID_EDIT_MONTH  (GUI_ID_USER + 0x18)
#define ID_EDIT_MINUTE  (GUI_ID_USER + 0x19)
#define ID_EDIT_DAY  (GUI_ID_USER + 0x1A)
#define ID_EDIT_AMPM  (GUI_ID_USER + 0x1B)
#define ID_EDIT_YEAR  (GUI_ID_USER + 0x1C)
#define ID_TEXT_HOUR  (GUI_ID_USER + 0x1D)
#define ID_TEXT_MINUTE  (GUI_ID_USER + 0x1E)
#define ID_TEXT_AMPM  (GUI_ID_USER + 0x1F)
#define ID_TEXT_YEAR  (GUI_ID_USER + 0x20)
#define ID_TEXT_MONTH  (GUI_ID_USER + 0x21)
#define ID_TEXT_DAY  (GUI_ID_USER + 0x22)
#define ID_BUTTON_DATE (GUI_ID_USER + 0x30)
#define ID_BUTTON_TIME  (GUI_ID_USER + 0x31)
#define ID_TEXT_HEADER_DATE  (GUI_ID_USER + 0x32)

/*********************************************************************
*
*       _aDialogCreate
*/
static const GUI_WIDGET_CREATE_INFO _aDialogCreate[] =
{
    { WINDOW_CreateIndirect, "Window", ID_WINDOW_0, 0, 0, 480, 272, 0, 0x0, 0 },
};

static const GUI_WIDGET_CREATE_INFO timeDialog[] =
{
    { WINDOW_CreateIndirect, "Window", ID_WINDOW_1, 0, 0, 480, 272, 0, 0x0, 0 },
    { TEXT_CreateIndirect, "", ID_TEXT_HEADER, 0, 0, 480, 50, 0, 0x64, 0 },
    { BUTTON_CreateIndirect, "Button", ID_BUTTON_HOUR_UP, 110, 92, 50, 50, 0, 0x0, 0 },
    { BUTTON_CreateIndirect, "Button", ID_BUTTON_HOUR_DN, 110, 138, 50, 50, 0, 0x0, 0 },
    { BUTTON_CreateIndirect, "Button", ID_BUTTON_MINUTE_UP, 259, 92, 50, 50, 0, 0x0, 0 },
    { BUTTON_CreateIndirect, "Button", ID_BUTTON_MINUTE_DN, 259, 138, 50, 50, 0, 0x0, 0 },
    { BUTTON_CreateIndirect, "Button", ID_BUTTON_AMPM_UP, 410, 92, 50, 50, 0, 0x0, 0 },
    { BUTTON_CreateIndirect, "Button", ID_BUTTON_AMPM_DN, 410, 138, 50, 50, 0, 0x0, 0 },

    { TEXT_CreateIndirect, "Edit", ID_EDIT_HOUR, 30, 105, 75, 60, 0, 0x64, 0 },
    { TEXT_CreateIndirect, "Edit", ID_EDIT_MINUTE, 180, 105, 75, 60, 0, 0x64, 0 },
    { TEXT_CreateIndirect, "Edit", ID_EDIT_AMPM, 330, 105, 75, 60, 0, 0x64, 0 },

    { TEXT_CreateIndirect, "Hour", ID_TEXT_HOUR, 30, 85, 75, 20, 0, 0x64, 0 },
    { TEXT_CreateIndirect, "Minute", ID_TEXT_MINUTE, 180, 85, 75, 20, 0, 0x64, 0 },
    { TEXT_CreateIndirect, "AM/PM", ID_TEXT_AMPM, 330, 85, 75, 20, 0, 0x64, 0 },

    { BUTTON_CreateIndirect, "CANCEL", ID_BUTTON_CANCEL, 20, 230, BUT_WIDTH, BUT_HEIGHT, 0, 0x0, 0 },
    { BUTTON_CreateIndirect, "SET DATE", ID_BUTTON_DATE, 190, 230, 110, BUT_HEIGHT, 0, 0x0, 0 },
    { BUTTON_CreateIndirect, "SAVE", ID_BUTTON_SAVE, 350, 230, BUT_WIDTH, BUT_HEIGHT, 0, 0x0, 0 },
};

static const GUI_WIDGET_CREATE_INFO dateDialog[] =
{
    { WINDOW_CreateIndirect, "Window", ID_WINDOW_2, 0, 0, 480, 272, 0, 0x0, 0 },
    { TEXT_CreateIndirect, "SET DATE", ID_TEXT_HEADER_DATE, 0, 0, 480, 50, 0, 0x64, 0 },
    { BUTTON_CreateIndirect, "Button", ID_BUTTON_MONTH_UP, 118, 92, 50, 50, 0, 0x0, 0 },
    { BUTTON_CreateIndirect, "Button", ID_BUTTON_MONTH_DN, 118, 138, 50, 50, 0, 0x0, 0 },
    { BUTTON_CreateIndirect, "Button", ID_BUTTON_DAY_UP, 249, 92, 50, 50, 0, 0x0, 0 },
    { BUTTON_CreateIndirect, "Button", ID_BUTTON_DAY_DN, 249, 138, 50, 50, 0, 0x0, 0 },
    { BUTTON_CreateIndirect, "Button", ID_BUTTON__YEAR_UP, 410, 92, 50, 50, 0, 0x0, 0 },
    { BUTTON_CreateIndirect, "Button", ID_BUTTON_YEAR_DN, 410, 138, 50, 50, 0, 0x0, 0 },

    { TEXT_CreateIndirect, "Edit", ID_EDIT_MONTH, 20, 105, 94, 60, 0, 0x64, 0 },
    { TEXT_CreateIndirect, "Edit", ID_EDIT_DAY, 180, 105, 65, 60, 0, 0x64, 0 },
    { TEXT_CreateIndirect, "Edit", ID_EDIT_YEAR, 312, 105, 95, 60, 0, 0x64, 0 },

    { TEXT_CreateIndirect, "Month", ID_TEXT_MONTH, 20, 85, 88, 20, 0, 0x64, 0 },
    { TEXT_CreateIndirect, "Day", ID_TEXT_DAY, 180, 85, 75, 20, 0, 0x64, 0 },
    { TEXT_CreateIndirect, "Year", ID_TEXT_YEAR, 312, 85, 95, 20, 0, 0x64, 0 },

    { BUTTON_CreateIndirect, "CANCEL", ID_BUTTON_CANCEL, 20, 230, BUT_WIDTH, BUT_HEIGHT, 0, 0x0, 0 },
    { BUTTON_CreateIndirect, "SET TIME", ID_BUTTON_TIME, 190, 230, 110, BUT_HEIGHT, 0, 0x0, 0 },
    { BUTTON_CreateIndirect, "SAVE", ID_BUTTON_SAVE, 350, 230, BUT_WIDTH, BUT_HEIGHT, 0, 0x0, 0 },
};

extern GUI_CONST_STORAGE GUI_BITMAP bmup_s_lg;
extern GUI_CONST_STORAGE GUI_BITMAP bmdn_s_lg;
extern GUI_CONST_STORAGE GUI_FONT GUI_FontTahoma42hAA4B;

static char *Months[] = {"JAN","FEB","MAR","APR","MAY","JUN","JUL","AUG","SEP","OCT","NOV","DEC"};
static int days[12] = {31,28,31,30,31,30,31,31,30,31,30,31};
static GUI_TIMER_HANDLE but_timer;

WM_HWIN hour_text, minute_text, ampm_text, month_text, day_text, year_text;
int but_id;

static WM_HWIN timeWin, dateWin;

void up_button(WM_MESSAGE * pMsg)
{
    switch (pMsg->MsgId)
    {
    case WM_PAINT:
        if (BUTTON_IsPressed(pMsg->hWin))
        {
            GUI_DrawBitmap(&bmup_s_lg, 0, 0);
        }
        else
        {
            GUI_DrawBitmap(&bmup_s_lg, 0, 0);
        }
        break;
    default:
        BUTTON_Callback(pMsg);
        break;
    }
}

void dn_button(WM_MESSAGE * pMsg)
{
    switch (pMsg->MsgId)
    {
    case WM_PAINT:
        if (BUTTON_IsPressed(pMsg->hWin))
        {
            GUI_DrawBitmap(&bmdn_s_lg, 0, 0);
        }
        else
        {
            GUI_DrawBitmap(&bmdn_s_lg, 0, 0);
        }
        break;
    default:
        BUTTON_Callback(pMsg);
        break;
    }
}

static void dateChanger()
{
    if (but_id == -1) return;
    int ctime = current_hour > 12 ? current_hour -12 : current_hour;
    char buf[10];

    switch(but_id)
    {
    case 0:
        current_hour++;
        if (current_hour > 12) current_hour -= 12;
        //GUI_ErrorOut1("H",current_hour);
        ctime = current_hour > 12 ? current_hour - 12 : current_hour;
        sprintf(buf, "%d", ctime);
        TEXT_SetText(hour_text, buf);
        break;
    case 1:
        current_hour--;
        if (current_hour == 0) current_hour = 12;
        ctime = current_hour > 12 ? current_hour -12 : current_hour;
        sprintf(buf, "%d", ctime);
        TEXT_SetText(hour_text, buf);
        break;
    case 2:
        current_minute++;
        if (current_minute == 60) current_minute = 0;
        sprintf(buf, "%02d", current_minute);
        TEXT_SetText(minute_text, buf);
        break;
    case 3:
        current_minute--;
        if (current_minute == -1) current_minute = 59;
        sprintf(buf, "%02d", current_minute);
        TEXT_SetText(minute_text, buf);
        break;
    case 4:
        current_ampm = !current_ampm;
        TEXT_SetText(ampm_text, current_ampm ? "PM" : "AM");
        break;
    case 5:
        current_ampm = !current_ampm;
        TEXT_SetText(ampm_text, current_ampm ? "PM" : "AM");
        break;
    case 6:
        current_month++;
        if (current_month == 12) current_month = 0;
        if (current_month == 3 || current_month == 5  || current_month == 8 || current_month == 11)
        {
            if (current_day > 30) current_day = 30;
            sprintf(buf, "%d", current_day);
            TEXT_SetText(day_text, buf);
        }
        else if (current_month == 1)
        {
            if ((current_year & 3) == 0 && ((current_year % 25) != 0 || (current_year & 15) == 0))
            {
                if (current_day > 29) current_day = 29;
                sprintf(buf, "%d", current_day);
                TEXT_SetText(day_text, buf);
            }
            else
            {
                if (current_day > 28) current_day = 28;
                sprintf(buf, "%d", current_day);
                TEXT_SetText(day_text, buf);
            }
        }
        TEXT_SetText(month_text, LANG(Months[current_month]));
        break;
    case 7:
        current_month--;
        if (current_month == -1) current_month = 11;
        if (current_month == 3 || current_month == 5  || current_month == 8 || current_month == 11)
        {
            if (current_day > 30) current_day = 30;
            sprintf(buf, "%d", current_day);
            TEXT_SetText(day_text, buf);
        }
        else if (current_month == 1)
        {
            if ((current_year & 3) == 0 && ((current_year % 25) != 0 || (current_year & 15) == 0))
            {
                if (current_day > 29) current_day = 29;
                sprintf(buf, "%d", current_day);
                TEXT_SetText(day_text, buf);
            }
            else
            {
                if (current_day > 28) current_day = 28;
                sprintf(buf, "%d", current_day);
                TEXT_SetText(day_text, buf);
            }
        }
        TEXT_SetText(month_text, LANG(Months[current_month]));
        break;
    case 8:
        current_day++;
        if (current_month == 0 || current_month == 2 || current_month == 4 ||
                current_month == 6 || current_month == 7 || current_month == 9 || current_month == 11)
        {
            if (current_day == 32) current_day = 1;
        }
        else if (current_month == 1)
        {
            if ((current_year & 3) == 0 && ((current_year % 25) != 0 || (current_year & 15) == 0))
            {
                if (current_day == 30) current_day = 1;
            }
            else
            {
                if (current_day == 29) current_day = 1;
            }
        }
        else
        {
            if (current_day == 31) current_day = 1;
        }
        sprintf(buf, "%d", current_day);
        TEXT_SetText(day_text, buf);
        break;
    case 9:
        current_day--;
        if (current_day == 0)
        {
            if (current_month == 0 || current_month == 2 || current_month == 4 ||
                    current_month == 6 || current_month == 7 || current_month == 9 || current_month == 11)
            {
                current_day = 31;
            }
            else if (current_month == 1)
            {
                if ((current_year & 3) == 0 && ((current_year % 25) != 0 || (current_year & 15) == 0))
                {
                    current_day = 29;
                }
                else
                {
                    current_day = 28;
                }
            }
            else
            {
                current_day = 30;
            }
        }
        sprintf(buf, "%d", current_day);
        TEXT_SetText(day_text, buf);
        break;
    case 10:
        current_year++;
        if (current_year == 2051) current_year = 2016;
        sprintf(buf, "%d", current_year);
        TEXT_SetText(year_text, buf);
        break;
    case 11:
        current_year--;
        if (current_year == 2015) current_year = 2050;
        sprintf(buf, "%d", current_year);
        TEXT_SetText(year_text, buf);
        break;
    default:
        break;
    }
    GUI_TIMER_SetPeriod(but_timer, 1000);
    GUI_TIMER_Restart(but_timer);
}

static void date_box_cb(WM_MESSAGE * pMsg)
{
    char buf[50];
    GUI_RECT rt;
    WM_GetClientRect(&rt);
    switch (pMsg->MsgId)
    {
    case WM_PAINT:
        TEXT_GetText(pMsg->hWin, buf, 10);
        GUI_DrawGradientRoundedV(0,0, rt.x1, rt.y1, 4, color_map[2].stop, color_map[2].start);

        GUI_SetColor(0x808080);
        GUI_SetTextMode(GUI_TEXTMODE_TRANS);
        GUI_SetFont(Tahoma42B);
        rt.y0-=4;
        GUI_DispStringInRect(buf, &rt, GUI_TA_HCENTER | GUI_TA_VCENTER);

        break;
    default:
        TEXT_Callback(pMsg);
        break;
    }
}

static void saveCurrentTime()
{
#ifdef CODEBLOCK

//    sprintf(date_buf, "%s %2d/%2d/%2d", LANG(day), info->tm_mon+1,info->tm_mday,(info->tm_year-100));
//
//    int h = (info->tm_hour > 12) ? info->tm_hour - 12 : info->tm_hour ;
//    sprintf(time_buf, "%3d:%02d %s", h, info->tm_min, (info->tm_hour > 12) ? "PM" : "AM");
#else
//    tm.Hours = current_hour;
//    tm.Minutes = current_minute;
//    tm.DayLightSaving = 1;
//    tm.TimeFormat = 64;
//
//    dt.Date = current_day;
//    dt.Month = current_month;
//    dt.Year = current_year;
//    dt.WeekDay = current_wday;
//
//    BSP_RTC_SetTime(&tm);
//    BSP_RTC_SetDate(&dt);
//
//    int h = (tm.Hours > 12) ? tm.Hours - 12 : tm.Hours;
//    sprintf(time_buf, "%d:%02d", tm.Hours, tm.Minutes, (tm.Hours > 12) ? "pm" : "am");
//
//    sprintf(date_buf, "%s %02d/%02d/%d", LANG(weekDays[dt.WeekDay]), dt.Month, dt.Date, dt.Year);
#endif
}

static void timeWin_cb(WM_MESSAGE * pMsg)
{
    WM_HWIN hItem;
    int     NCode;
    int     Id;
    char buf[20];

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
        TEXT_SetTextColor(hItem, GUI_MAKE_COLOR(0x00FFFFFF));
        TEXT_SetText(hItem, LANG("SET TIME"));

        hItem = WM_GetDialogItem(pMsg->hWin, ID_BUTTON_HOUR_UP);
        WM_SetCallback(hItem, up_button);
        //
        hItem = WM_GetDialogItem(pMsg->hWin, ID_BUTTON_HOUR_DN);
        WM_SetCallback(hItem, dn_button);
        //
        hItem = WM_GetDialogItem(pMsg->hWin, ID_BUTTON_MINUTE_UP);
        WM_SetCallback(hItem, up_button);
        //
        hItem = WM_GetDialogItem(pMsg->hWin, ID_BUTTON_MINUTE_DN);
        WM_SetCallback(hItem, dn_button);
        //
        hItem = WM_GetDialogItem(pMsg->hWin, ID_BUTTON_AMPM_UP);
        WM_SetCallback(hItem, up_button);
        //
        hItem = WM_GetDialogItem(pMsg->hWin, ID_BUTTON_AMPM_DN);
        int ctime = current_hour > 12 ? current_hour -12 : current_hour;
        WM_SetCallback(hItem, dn_button);
        sprintf(buf, "%d", ctime);
        hour_text = WM_GetDialogItem(pMsg->hWin, ID_EDIT_HOUR);
        TEXT_SetText(hour_text, buf);
        WM_SetCallback(hour_text, date_box_cb);
        //
        sprintf(buf, "%02d", current_minute);
        minute_text = WM_GetDialogItem(pMsg->hWin, ID_EDIT_MINUTE);
        TEXT_SetText(minute_text, buf);
        WM_SetCallback(minute_text, date_box_cb);
        //
        ampm_text = WM_GetDialogItem(pMsg->hWin, ID_EDIT_AMPM);
        TEXT_SetText(ampm_text, current_ampm ? "PM" : "AM");
        WM_SetCallback(ampm_text, date_box_cb);
        //
        hItem = WM_GetDialogItem(pMsg->hWin, ID_TEXT_HOUR);
        TEXT_SetTextAlign(hItem, GUI_TA_HCENTER);
        TEXT_SetFont(hItem, Tahoma19B);
        TEXT_SetTextColor(hItem, GUI_MAKE_COLOR(0x00808080));
        TEXT_SetText(hItem, LANG("Hour"));
        //
        hItem = WM_GetDialogItem(pMsg->hWin, ID_TEXT_MINUTE);
        TEXT_SetTextAlign(hItem, GUI_TA_HCENTER);
        TEXT_SetFont(hItem, Tahoma19B);
        TEXT_SetTextColor(hItem, GUI_MAKE_COLOR(0x00808080));
        TEXT_SetText(hItem, LANG("Minute"));
        //
        hItem = WM_GetDialogItem(pMsg->hWin, ID_TEXT_AMPM);
        TEXT_SetFont(hItem, Tahoma19B);
        TEXT_SetTextAlign(hItem, GUI_TA_HCENTER);
        TEXT_SetTextColor(hItem, GUI_MAKE_COLOR(0x00808080));
        TEXT_SetText(hItem, "AM/PM");

        hItem = WM_GetDialogItem(pMsg->hWin, ID_BUTTON_CANCEL);
        WM_SetCallback(hItem, buttonOn_cb);
        //
        hItem = WM_GetDialogItem(pMsg->hWin, ID_BUTTON_DATE);
        WM_SetCallback(hItem, buttonOn_cb);
        //
        hItem = WM_GetDialogItem(pMsg->hWin, ID_BUTTON_SAVE);
        WM_SetCallback(hItem, buttonOn_cb);
        //
        break;
    case WM_NOTIFY_PARENT:
        Id    = WM_GetId(pMsg->hWinSrc);
        NCode = pMsg->Data.v;

        switch(Id)
        {
        case ID_BUTTON_HOUR_UP:
            switch(NCode)
            {
            case WM_NOTIFICATION_CLICKED:
                but_id = 0;
                dateChanger();
                break;
            case WM_NOTIFICATION_RELEASED:
                but_id = -1;
                dateChanger();
                break;
            }
            break;
        case ID_BUTTON_HOUR_DN:
            switch(NCode)
            {
            case WM_NOTIFICATION_RELEASED:
                but_id = 1;
                dateChanger();
                break;
            }
            break;
        case ID_BUTTON_MINUTE_UP:
            switch(NCode)
            {
            case WM_NOTIFICATION_RELEASED:
                but_id = 2;
                dateChanger();
                break;
            }
            break;
        case ID_BUTTON_MINUTE_DN:
            switch(NCode)
            {
            case WM_NOTIFICATION_RELEASED:
                but_id = 3;
                dateChanger();
                break;
            }
            break;
        case ID_BUTTON_AMPM_UP:
            switch(NCode)
            {
            case WM_NOTIFICATION_RELEASED:
                but_id = 4;
                dateChanger();
                break;
            }
            break;
        case ID_BUTTON_AMPM_DN:
            switch(NCode)
            {
            case WM_NOTIFICATION_RELEASED:
                but_id = 5;
                dateChanger();
                break;
            }
            break;
        case ID_BUTTON_CANCEL:
            switch(NCode)
            {
            case WM_NOTIFICATION_RELEASED:
                GUI_Delay(100);
                //WM_HideWindow(dateTimeWin);
                WM_DeleteWindow(dateTimeWin);
                screenState = SETTINGSWIN;
                break;
            }
            break;
        case ID_BUTTON_DATE:
            switch(NCode)
            {
            case WM_NOTIFICATION_RELEASED:
                GUI_Delay(100);

                WM_HideWindow(timeWin);
                WM_ShowWindow(dateWin);
                break;
            }
            break;
        case ID_BUTTON_SAVE:
            switch(NCode)
            {
            case WM_NOTIFICATION_RELEASED:
                GUI_Delay(100);
                GUI_ErrorOut1("H",current_ampm);
                WM_DeleteWindow(dateTimeWin);
                screenState = SETTINGSWIN;
                break;
            }
            break;
        }
    default:
        WM_DefaultProc(pMsg);
        break;
    }
}

static void dateWin_cb(WM_MESSAGE * pMsg)
{
    WM_HWIN hItem;
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
        hItem = WM_GetDialogItem(pMsg->hWin, ID_TEXT_HEADER_DATE);
        TEXT_SetText(hItem, LANG("SET DATE"));
        TEXT_SetFont(hItem, HEADER_FONT_BOLD);
        TEXT_SetTextAlign(hItem, GUI_TA_HCENTER | GUI_TA_VCENTER);
        TEXT_SetTextColor(hItem, GUI_MAKE_COLOR(0x00FFFFFF));

        hItem = WM_GetDialogItem(pMsg->hWin, ID_BUTTON_MONTH_UP);
        WM_SetCallback(hItem, up_button);;
        //
        hItem = WM_GetDialogItem(pMsg->hWin, ID_BUTTON_MONTH_DN);
        WM_SetCallback(hItem, dn_button);
        //
        hItem = WM_GetDialogItem(pMsg->hWin, ID_BUTTON_DAY_UP);
        WM_SetCallback(hItem, up_button);
        //
        hItem = WM_GetDialogItem(pMsg->hWin, ID_BUTTON_DAY_DN);
        WM_SetCallback(hItem, dn_button);
        //
        hItem = WM_GetDialogItem(pMsg->hWin, ID_BUTTON__YEAR_UP);
        WM_SetCallback(hItem, up_button);
        //
        hItem = WM_GetDialogItem(pMsg->hWin, ID_BUTTON_YEAR_DN);
        WM_SetCallback(hItem, dn_button);
        //
        month_text = WM_GetDialogItem(pMsg->hWin, ID_EDIT_MONTH);
        TEXT_SetText(month_text, Months[current_month]);
        WM_SetCallback(month_text, date_box_cb);
        //
        sprintf(buf, "%d", current_day);
        day_text = WM_GetDialogItem(pMsg->hWin, ID_EDIT_DAY);
        TEXT_SetText(day_text, buf);
        WM_SetCallback(day_text, date_box_cb);
        //
        sprintf(buf, "%d", current_year);
        year_text = WM_GetDialogItem(pMsg->hWin, ID_EDIT_YEAR);
        TEXT_SetText(year_text, buf);
        WM_SetCallback(year_text, date_box_cb);
        //
        hItem = WM_GetDialogItem(pMsg->hWin, ID_TEXT_MONTH);
        TEXT_SetFont(hItem, GUI_FONT_20_1);
        TEXT_SetTextAlign(hItem, GUI_TA_HCENTER);
        TEXT_SetText(hItem, LANG("Month"));
        TEXT_SetTextColor(hItem, GUI_MAKE_COLOR(0x00808080));
        //
        hItem = WM_GetDialogItem(pMsg->hWin, ID_TEXT_DAY);
        TEXT_SetFont(hItem, GUI_FONT_20_1);
        TEXT_SetTextAlign(hItem, GUI_TA_HCENTER);
        TEXT_SetText(hItem, LANG("Day"));
        TEXT_SetTextColor(hItem, GUI_MAKE_COLOR(0x00808080));
        //
        hItem = WM_GetDialogItem(pMsg->hWin, ID_TEXT_YEAR);
        TEXT_SetFont(hItem, GUI_FONT_20_1);
        TEXT_SetTextAlign(hItem, GUI_TA_HCENTER);
        TEXT_SetText(hItem, LANG("Year"));
        TEXT_SetTextColor(hItem, GUI_MAKE_COLOR(0x00808080));

        hItem = WM_GetDialogItem(pMsg->hWin, ID_BUTTON_CANCEL);
        WM_SetCallback(hItem, buttonOn_cb);
        //
        hItem = WM_GetDialogItem(pMsg->hWin, ID_BUTTON_TIME);
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
        case ID_BUTTON_MONTH_UP:
            switch(NCode)
            {
            case WM_NOTIFICATION_RELEASED:
                but_id = 6;
                dateChanger();
                break;
            }
            break;
        case ID_BUTTON_MONTH_DN:
            switch(NCode)
            {
            case WM_NOTIFICATION_RELEASED:
                but_id = 7;
                dateChanger();
                break;
            }
            break;
        case ID_BUTTON_DAY_UP:
            switch(NCode)
            {
            case WM_NOTIFICATION_RELEASED:
                but_id = 8;
                dateChanger();
                break;
            }
            break;
        case ID_BUTTON_DAY_DN:
            switch(NCode)
            {
            case WM_NOTIFICATION_RELEASED:
                but_id = 9;
                dateChanger();
                break;
            }
            break;
        case ID_BUTTON__YEAR_UP:
            switch(NCode)
            {
            case WM_NOTIFICATION_RELEASED:
                but_id = 10;
                dateChanger();
                break;
            }
            break;
        case ID_BUTTON_YEAR_DN:
            switch(NCode)
            {
            case WM_NOTIFICATION_RELEASED:
                but_id = 11;
                dateChanger();
                break;
            }
            break;
        case ID_BUTTON_CANCEL:
            switch(NCode)
            {
            case WM_NOTIFICATION_RELEASED:
                GUI_Delay(100);
                WM_DeleteWindow(dateTimeWin);
                screenState = SETTINGSWIN;
                break;
            }
            break;
        case ID_BUTTON_TIME:
            switch(NCode)
            {
            case WM_NOTIFICATION_RELEASED:
                GUI_Delay(100);
                WM_HideWindow(dateWin);
                WM_ShowWindow(timeWin);
                break;
            }
            break;
        case ID_BUTTON_SAVE:
            switch(NCode)
            {
            case WM_NOTIFICATION_RELEASED:
                GUI_Delay(100);
                saveCurrentTime();
                WM_DeleteWindow(dateTimeWin);
                screenState = SETTINGSWIN;
                break;
            }
            break;
        }
    default:
        WM_DefaultProc(pMsg);
        break;
    }
}

WM_HWIN CreateDateTime(void);
WM_HWIN CreateDateTime(void)
{
    WM_HWIN hWin;

    hWin = GUI_CreateDialogBox(_aDialogCreate, GUI_COUNTOF(_aDialogCreate),
                               0, WM_HBKWIN, 0, 0);

    timeWin = GUI_CreateDialogBox(timeDialog, GUI_COUNTOF(timeDialog),
                                  timeWin_cb, hWin, 0, 0);
    dateWin = GUI_CreateDialogBox(dateDialog, GUI_COUNTOF(dateDialog),
                                  dateWin_cb, hWin, 0, 0);
    WM_HideWindow(dateWin);

    return hWin;
}

