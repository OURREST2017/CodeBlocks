#include "ranger.h"

#define ID_WINDOW_0 (GUI_ID_USER + 0x02)
#define ID_TEXT_HEADER (GUI_ID_USER + 0x08)
#define ID_BUTTON_CANCEL (GUI_ID_USER + 0x11)
#define ID_BUTTON_WEEKDAY (GUI_ID_USER + 0x14)
#define ID_BUTTON_SAVE (GUI_ID_USER + 0x15)
#define ID_TEXT_TITLE (GUI_ID_USER + 0x25)
#define ID_TEXT_WAKE (GUI_ID_USER + 0x26)
#define ID_TEXT_LEAVE (GUI_ID_USER + 0x27)
#define ID_TEXT_RETURN (GUI_ID_USER + 0x28)
#define ID_TEXT_SLEEP (GUI_ID_USER + 0x29)
#define ID_TEXT_TIME (GUI_ID_USER + 0x2B)
#define ID_TEXT_TEMP (GUI_ID_USER + 0x2D)
#define ID_BUTTON_TIME_UP (GUI_ID_USER + 0x2E)
#define ID_BUTTON_TIME_DN (GUI_ID_USER + 0x2F)

#define ID_BUTTON_HELP (GUI_ID_USER + 0x32)
#define ID_TEXT_START_TXT (GUI_ID_USER + 0x33)
#define ID_TEXT_TEMP (GUI_ID_USER + 0x34)

#define ID_TEXT_WAKE_TIME (GUI_ID_USER + 0x35)
#define ID_TEXT_LEAVE_TIME (GUI_ID_USER + 0x36)
#define ID_TEXT_RETURN_TIME (GUI_ID_USER + 0x37)
#define ID_TEXT_SLEEP_TIME (GUI_ID_USER + 0x38)

#define ID_TEXT_WAKE_HEAT (GUI_ID_USER + 0x39)
#define ID_TEXT_LEAVE_HEAT (GUI_ID_USER + 0x3A)
#define ID_TEXT_RETURN_HEAT (GUI_ID_USER + 0x3B)
#define ID_TEXT_SLEEP_HEAT (GUI_ID_USER + 0x3C)
#define ID_TEXT_TIME (GUI_ID_USER + 0x3D)
#define ID_TEXT_HEAT (GUI_ID_USER + 0x3E)
#define ID_TEXT_COOL (GUI_ID_USER + 0x3E)
#define ID_TEXT_PERIOD (GUI_ID_USER + 0x40)
#define ID_BUTTON_WEEKEND (GUI_ID_USER + 0x41)

#define ID_TEXT_WAKE_COOL (GUI_ID_USER + 0x42)
#define ID_TEXT_LEAVE_COOL (GUI_ID_USER + 0x43)
#define ID_TEXT_RETURN_COOL (GUI_ID_USER + 0x44)
#define ID_TEXT_SLEEP_COOL (GUI_ID_USER + 0x45)
#define ID_TEXT_COOL (GUI_ID_USER + 0x46)

#define ID_TEXT_MONDAY (GUI_ID_USER + 0xA1)
#define ID_TEXT_TUESDAY (GUI_ID_USER + 0xA2)
#define ID_TEXT_WEDNESDAY (GUI_ID_USER + 0xA3)
#define ID_TEXT_THURSDAY (GUI_ID_USER + 0xA4)
#define ID_TEXT_FRIDAY (GUI_ID_USER + 0xA5)
#define ID_TEXT_SATURDAY (GUI_ID_USER + 0xA6)
#define ID_TEXT_SUNDAY (GUI_ID_USER + 0xA7)

#define BUTWIDTH 110
#define XPOS 30

#define BUT_SPACING 32
#define BUTTON_Y_OFFSET 85
#define BOX_WIDTH 80
#define TIME_X 140
#define HEAT_X TIME_X+BOX_WIDTH
#define COOL_X HEAT_X+BOX_WIDTH

#define BUTTON_Y_POS(x)  BUTTON_Y_OFFSET + (x * BUT_SPACING)

static const GUI_WIDGET_CREATE_INFO _aDialogCreate[] =
{
    { WINDOW_CreateIndirect, "Window", ID_WINDOW_0, 0, 0, 480, 272, 0, 0x0, 0 },
    { TEXT_CreateIndirect, "EDIT SCHEDULE:", ID_TEXT_HEADER, 0, 0, 260, 50, 0, 0x64, 0 },
    { TEXT_CreateIndirect, "", ID_TEXT_TITLE, 270, 0, 280, 50, 0, 0x64, 0 },

    { TEXT_CreateIndirect, "WAKE", ID_TEXT_WAKE, XPOS,BUTTON_Y_POS(0), BUTWIDTH, 32, 0, 0x0, 0},
    { TEXT_CreateIndirect, "LEAVE", ID_TEXT_LEAVE, XPOS, BUTTON_Y_POS(1), BUTWIDTH, 32, 0, 0x0, 0 },
    { TEXT_CreateIndirect, "RETURN", ID_TEXT_RETURN, XPOS, BUTTON_Y_POS(2), BUTWIDTH, 32, 0, 0x0, 0 },
    { TEXT_CreateIndirect, "SLEEP", ID_TEXT_SLEEP, XPOS, BUTTON_Y_POS(3), BUTWIDTH, 32, 0, 0x0, 0 },

    { TEXT_CreateIndirect, "Period", ID_TEXT_PERIOD, XPOS, 60, BUTWIDTH, 28, 0, 0x0, 0 },
    { TEXT_CreateIndirect, "Time", ID_TEXT_TIME, TIME_X, 60, BOX_WIDTH, 28, 0, 0x0, 0 },
    { TEXT_CreateIndirect, "Heat", ID_TEXT_HEAT, HEAT_X, 60, BOX_WIDTH, 28, 0, 0x0, 0 },
    { TEXT_CreateIndirect, "Cool", ID_TEXT_COOL, COOL_X, 60, BOX_WIDTH, 28, 0, 0x0, 0 },

    { TEXT_CreateIndirect, "", ID_TEXT_WAKE_TIME, TIME_X, BUTTON_Y_POS(0), BOX_WIDTH, 32, 0, 0x64, 0 },
    { TEXT_CreateIndirect, "", ID_TEXT_LEAVE_TIME, TIME_X, BUTTON_Y_POS(1), BOX_WIDTH, 32, 0, 0x64, 0 },
    { TEXT_CreateIndirect, "", ID_TEXT_RETURN_TIME, TIME_X, BUTTON_Y_POS(2), BOX_WIDTH, 32, 0, 0x64, 0 },
    { TEXT_CreateIndirect, "", ID_TEXT_SLEEP_TIME, TIME_X, BUTTON_Y_POS(3), BOX_WIDTH, 32, 0, 0x64, 0 },

    { TEXT_CreateIndirect, "", ID_TEXT_WAKE_HEAT, HEAT_X, BUTTON_Y_POS(0), BOX_WIDTH, 32, 0, 0x64, 0 },
    { TEXT_CreateIndirect, "", ID_TEXT_LEAVE_HEAT, HEAT_X, BUTTON_Y_POS(1), BOX_WIDTH, 32, 0, 0x64, 0 },
    { TEXT_CreateIndirect, "", ID_TEXT_RETURN_HEAT, HEAT_X, BUTTON_Y_POS(2), BOX_WIDTH, 32, 0, 0x64, 0 },
    { TEXT_CreateIndirect, "", ID_TEXT_SLEEP_HEAT, HEAT_X, BUTTON_Y_POS(3), BOX_WIDTH, 32, 0, 0x64, 0 },

    { TEXT_CreateIndirect, "", ID_TEXT_WAKE_COOL, COOL_X, BUTTON_Y_POS(0), BOX_WIDTH, 32, 0, 0x64, 0 },
    { TEXT_CreateIndirect, "", ID_TEXT_LEAVE_COOL, COOL_X, BUTTON_Y_POS(1), BOX_WIDTH, 32, 0, 0x64, 0 },
    { TEXT_CreateIndirect, "", ID_TEXT_RETURN_COOL, COOL_X, BUTTON_Y_POS(2), BOX_WIDTH, 32, 0, 0x64, 0 },
    { TEXT_CreateIndirect, "", ID_TEXT_SLEEP_COOL, COOL_X, BUTTON_Y_POS(3), BOX_WIDTH, 32, 0, 0x64, 0 },

    { TEXT_CreateIndirect, "M", ID_TEXT_MONDAY, 28, 0, 32, 50, 0, 0x64, 0 },
    { TEXT_CreateIndirect, "T", ID_TEXT_TUESDAY, 80, 0, 32, 50, 0, 0x64, 0 },
    { TEXT_CreateIndirect, "W", ID_TEXT_WEDNESDAY, 133, 0, 50, 50, 0, 0x64, 0 },
    { TEXT_CreateIndirect, "TH", ID_TEXT_THURSDAY, 195, 0, 59, 50, 0, 0x64, 0 },
    { TEXT_CreateIndirect, "F", ID_TEXT_FRIDAY, 269, 0, 42, 50, 0, 0x64, 0 },
    { TEXT_CreateIndirect, "S", ID_TEXT_SATURDAY, 329, 0, 47, 50, 0, 0x64, 0 },
    { TEXT_CreateIndirect, "SU", ID_TEXT_SUNDAY, 390, 0, 71, 50, 0, 0x64, 0 },

    { BUTTON_CreateIndirect, "", ID_BUTTON_TIME_UP, 390, 98, 60, 60, 0, 0x0, 0 },
    { BUTTON_CreateIndirect, "", ID_BUTTON_TIME_DN, 390, 153, 60, 60, 0, 0x0, 0 },
//
    { BUTTON_CreateIndirect, "CANCEL", ID_BUTTON_CANCEL, 20, 230, BUT_WIDTH, BUT_HEIGHT, 0, 0x0, 0 },
    { BUTTON_CreateIndirect, "HELP", ID_BUTTON_HELP, 200, 230, 80, BUT_HEIGHT, 0, 0x0, 0 },
    { BUTTON_CreateIndirect, "WEEKDAY", ID_BUTTON_WEEKDAY, 230, 230, 110, BUT_HEIGHT, 0, 0x0, 0 },
    { BUTTON_CreateIndirect, "WEEKEND", ID_BUTTON_WEEKEND, 230, 230, 110, BUT_HEIGHT, 0, 0x0, 0 },
    { BUTTON_CreateIndirect, "SAVE", ID_BUTTON_SAVE, 350, 230,BUT_WIDTH, BUT_HEIGHT, 0, 0x0, 0 },
};

static WM_HWIN wake_win, leave_win, return_win, sleep_win, time_win, temp_win;
static WM_HWIN wake_time_win, leave_time_win, return_time_win, sleep_time_win;
static WM_HWIN wake_heat_win, leave_heat_win, return_heat_win, sleep_heat_win;
static WM_HWIN wake_cool_win, leave_cool_win, return_cool_win, sleep_cool_win;

static WM_HWIN timeUpButton, timeDnButton,tempUpButton, tempDnButton;
static WM_HWIN weekdayButton, weekendButton, textTitle, scheduleHeaderWin;
static WM_HWIN mondayWin, tuesdayWin, wednesdayWin, thursdayWin, fridayWin, saturdayWin, sundayWin;

static int period, selected_period, selected_slot, each_day, selected_day;
static void  setDays(WM_HWIN *, int),  setDays1(WM_HWIN *, int);

static struct days_s days[7];
static struct periods_s getPeriod(char * p);
static int getPeriodIndex(char * p);
static struct days_s selectedDay;
static void setSchedule(char *sched, char *day, char *per, struct periods_s period);

static char *days_text[] =
{
    "monday","tuesday","wednesday","thursday","friday","saturday","sunday"
};
static char *periods_text[] = {"wake","leave","return","sleep"};
static char edit_title[20], edit_sched[20];
static void setPeriods();

static int week_days[] =
{
    ID_TEXT_MONDAY,ID_TEXT_TUESDAY,ID_TEXT_WEDNESDAY,
    ID_TEXT_THURSDAY,ID_TEXT_FRIDAY, ID_TEXT_SATURDAY, ID_TEXT_SUNDAY
};

static int wake_time_on, leave_time_on, return_time_on, sleep_time_on;
static int wake_heat_on, leave_heat_on, return_heat_on, sleep_heat_on;
static int wake_cool_on, leave_cool_on, return_cool_on, sleep_cool_on;

extern GUI_CONST_STORAGE GUI_BITMAP bmup_lg;
extern GUI_CONST_STORAGE GUI_BITMAP bmdn_lg;

extern char *convertTemp(float temp_set);

static char * updateTime(char *tm, int dr, int *tout)
{
    static  char buf[10];
    int hh, mm,am;
    sscanf(tm, "%d:%d", &hh, &mm);

    if (strchr(tm, 'a'))
    {
        am = 1;
    }
    else
    {
        am = 0;
    }

    if (dr == -1)
    {
        mm -= 15;
        if (mm < 0)
        {
            mm = 45;
            hh--;
            if (hh == 11) am = !am;
        }
        if (hh == 0)
        {
            hh = 12;
        }
    }
    else
    {
        mm += 15;
        if (mm == 60)
        {
            mm = 0;
            hh++;
            if (hh == 12) am = !am;
        }
        if (hh == 13)
        {
            hh = 1;
        }
    }

    if (am == 0) {
        *tout = hh * 100 + mm;
    } else {
        *tout = (hh + 12) * 100 + mm;
    }
    sprintf(buf,"%d:%02d%s", hh, mm, (am == 1) ? "am" : "pm");

    return buf;
}

static void periodSlot(WM_MESSAGE * pMsg, int sel)
{
    char nm[50];
    WM_HWIN win = pMsg->hWin;
    GUI_RECT r;
    WM_GetClientRect(&r);
    TEXT_GetText(win, nm, 50);

    switch (pMsg->MsgId)
    {
    case WM_PAINT:
        GUI_DrawGradientRoundedV(1, 1, r.x1-1, r.y1-1, 4, color_map[2].stop, color_map[2].start);
        GUI_SetFont(Tahoma18B);
        GUI_SetColor(0x666666);
        GUI_SetTextMode(GUI_TM_TRANS);
        GUI_DispStringInRect(LANG(nm), &r, GUI_TA_HCENTER | GUI_TA_VCENTER);
        break;
    default:
        TEXT_Callback(pMsg);
        break;
    }
}

static void scheduleSlot(WM_MESSAGE * pMsg, int sel)
{
    char nm[50];
    WM_HWIN win = pMsg->hWin;
    GUI_RECT r;
    WM_GetClientRect(&r);
    TEXT_GetText(win, nm, 50);

    GUI_COLOR txt;
    switch (pMsg->MsgId)
    {
    case WM_PAINT:
        if (sel == 1)
        {
            GUI_DrawGradientRoundedV(1, 1, r.x1-1, r.y1-1, 4,
                                     color_map[color_scheme].stop, color_map[color_scheme].start);
            GUI_SetFont(Tahoma18B);
            GUI_SetColor(GUI_WHITE);
        }
        else
        {
            GUI_DrawGradientRoundedV(1, 1, r.x1-1, r.y1-1, 4,
                                     color_map[2].stop, color_map[2].start);
            GUI_SetFont(Tahoma18B);
            txt = TEXT_GetTextColor(pMsg->hWin);
            GUI_SetColor(txt);
        }
        GUI_SetTextMode(GUI_TM_TRANS);
        GUI_DispStringInRect(nm, &r, GUI_TA_HCENTER | GUI_TA_VCENTER);
        break;
    default:
        TEXT_Callback(pMsg);
        break;
    }
}

static void slot_cb(WM_MESSAGE * pMsg)
{
    WM_HWIN win = pMsg->hWin;

    if (win == wake_time_win && wake_time_on)
    {
        scheduleSlot(pMsg, 1);
    }
    else if (win == leave_time_win && leave_time_on)
    {
        scheduleSlot(pMsg, 1);
    }
    else if (win == return_time_win && return_time_on)
    {
        scheduleSlot(pMsg, 1);
    }
    else if (win == sleep_time_win && sleep_time_on)
    {
        scheduleSlot(pMsg, 1);
    }
    else if (win == wake_heat_win && wake_heat_on)
    {
        scheduleSlot(pMsg, 1);
    }
    else if (win == leave_heat_win && leave_heat_on)
    {
        scheduleSlot(pMsg, 1);
    }
    else if (win == return_heat_win && return_heat_on)
    {
        scheduleSlot(pMsg, 1);
    }
    else if (win == sleep_heat_win && sleep_heat_on)
    {
        scheduleSlot(pMsg, 1);
    }
    else if (win == wake_cool_win && wake_cool_on)
    {
        scheduleSlot(pMsg, 1);
    }
    else if (win == leave_cool_win && leave_cool_on)
    {
        scheduleSlot(pMsg, 1);
    }
    else if (win == return_cool_win && return_cool_on)
    {
        scheduleSlot(pMsg, 1);
    }
    else if (win == sleep_cool_win && sleep_cool_on)
    {
        scheduleSlot(pMsg, 1);
    }
    else
    {
        scheduleSlot(pMsg, 0);
    }
}

static void invalidateButtons(int sel)
{
    WM_InvalidateWindow(wake_time_win);
    WM_InvalidateWindow(leave_time_win);
    WM_InvalidateWindow(return_time_win);
    WM_InvalidateWindow(sleep_time_win);

    WM_InvalidateWindow(wake_heat_win);
    WM_InvalidateWindow(leave_heat_win);
    WM_InvalidateWindow(return_heat_win);
    WM_InvalidateWindow(sleep_heat_win);

    WM_InvalidateWindow(wake_cool_win);
    WM_InvalidateWindow(leave_cool_win);
    WM_InvalidateWindow(return_cool_win);
    WM_InvalidateWindow(sleep_cool_win);

    period = sel;
    if (sel > 3 && sel < 8)
    {
        period -= 4;
    }
    else if (sel > 7)
    {
        period -= 8;
    }

    selected_period = getPeriodIndex(periods_text[period]);

    selected_slot = sel;
    wake_time_on = (sel == 0);
    leave_time_on  = (sel == 1);
    return_time_on   = (sel == 2);
    sleep_time_on   = (sel == 3);

    wake_heat_on = (sel == 4);
    leave_heat_on  = (sel == 5);
    return_heat_on   = (sel == 6);
    sleep_heat_on   = (sel == 7);

    wake_cool_on = (sel == 8);
    leave_cool_on  = (sel == 9);
    return_cool_on   = (sel == 10);
    sleep_cool_on   = (sel == 11);
}

static void upButton_cb(WM_MESSAGE * pMsg)
{
    switch (pMsg->MsgId)
    {
    case WM_PAINT:
        if (BUTTON_IsPressed(pMsg->hWin))
        {
            GUI_DrawBitmap(&bmup_lg, 0, 0);
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
            GUI_DrawBitmap(&bmdn_lg, 0, 0);
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

static char * getTime(int st)
{
    static char buf[30];

    int h = st/100;
    int m = st - (st/100)*100;

    if (h > 12) h -= 12;
    sprintf(buf, "%d:%02d%s",
            h, m, ((st >= 0 && st <= 1201) ? "am" : "pm"));
    return buf;
}

static void resetFonts(WM_HWIN win, int id)
{
    WM_HWIN txt;
    int i;
    for (i=0; i<7; i++)
    {
        txt = WM_GetDialogItem(win, week_days[i]);
        TEXT_SetFont(txt, &GUI_FontTahoma33hAA4);
    }
    txt = WM_GetDialogItem(win, id);
    TEXT_SetFont(txt, &GUI_FontTahoma33hAA4B);
}

static struct days_s getDay(char * d)
{
    int sz1 = sizeof(days) / sizeof(days[0]);
    int i;
    for (i=0; i<sz1; i++)
    {
        if (strcmp(days[i].label, d) == 0)
        {
            selected_day = i;
            return days[i];
            break;
        }
    }
}

static void getDayPeriods()
{
    int i,k,j;

    int sz1 = sizeof(schedules) / sizeof(schedules[0]);
    int sz2 = sizeof(days) / sizeof(days[0]);

    for (i=0; i<sz1; i++)
    {
        if (strcmp(schedules[i].label, "each day") == 0)
        {
            for (k=0; k<sz2; k++)
            {
                days[k] = schedules[i].days[k];
            }
            break;
        }
    }
}

static void selectWeekType()
{
    int i;
    if (strcmp(edit_title, "weekend") ==  0)
    {
        strcpy(edit_title, "weekday");
        strcpy(edit_sched, "weekday");
        strcpy(scheduleDay, "weekday");
        strcpy(schedulePeriod, "weekday");

        WM_HideWindow(weekdayButton);
        WM_ShowWindow(weekendButton);

        for (i=0; i<5; i++)
        {
            if (strcmp(schedules[i].label, tolow(schedulePeriod)) == 0)
            {
                selectedSchedule = schedules[i];
                break;
            }
        }

        for (i=0; i<selectedSchedule.day_count; i++)
        {
            if (strcmp(selectedSchedule.days[i].label, tolow(scheduleDay)) == 0)
            {
                selectedDay = selectedSchedule.days[i];
                break;
            }
        }
    }
    else
    {
        strcpy(edit_title, "weekend");
        strcpy(edit_sched, "weekend");
        strcpy(scheduleDay, "weekend");
        strcpy(schedulePeriod, "weekend");

        WM_HideWindow(weekendButton);
        WM_ShowWindow(weekdayButton);

        for (i=0; i<5; i++)
        {
            if (strcmp(schedules[i].label, tolow(schedulePeriod)) == 0)
            {
                selectedSchedule = schedules[i];
                break;
            }
        }

        for (i=0; i<selectedSchedule.day_count; i++)
        {
            if (strcmp(selectedSchedule.days[i].label, tolow(scheduleDay)) == 0)
            {
                selectedDay = selectedSchedule.days[i];
                break;
            }
        }

    }

    period = 0;
    wake_time_on = 1;
    selected_period = getPeriodIndex(periods_text[period]);
    TEXT_SetText(textTitle, LANG(toup(edit_title)));
}

static void eachDayHeader(WM_HWIN hWin)
{
    mondayWin = WM_GetDialogItem(hWin, ID_TEXT_MONDAY);
    TEXT_SetTextAlign(mondayWin, GUI_TA_HCENTER | GUI_TA_VCENTER);
    TEXT_SetTextColor(mondayWin, GUI_MAKE_COLOR(0x00FFFFFF));
    if (selected_day == 0)
    {
        TEXT_SetFont(mondayWin, Tahoma33B);
    }
    else
    {
        TEXT_SetFont(mondayWin, Tahoma33);
    }
    //
    tuesdayWin = WM_GetDialogItem(hWin, ID_TEXT_TUESDAY);
    TEXT_SetTextAlign(tuesdayWin, GUI_TA_HCENTER | GUI_TA_VCENTER);
    TEXT_SetTextColor(tuesdayWin, GUI_MAKE_COLOR(0x00FFFFFF));
    if (selected_day == 1)
    {
        TEXT_SetFont(tuesdayWin, Tahoma33B);
    }
    else
    {
        TEXT_SetFont(tuesdayWin, Tahoma33);
    }

    wednesdayWin = WM_GetDialogItem(hWin, ID_TEXT_WEDNESDAY);
    TEXT_SetTextAlign(wednesdayWin, GUI_TA_HCENTER | GUI_TA_VCENTER);
    TEXT_SetTextColor(wednesdayWin, GUI_MAKE_COLOR(0x00FFFFFF));
    if (selected_day == 2)
    {
        TEXT_SetFont(wednesdayWin, Tahoma33B);
    }
    else
    {
        TEXT_SetFont(wednesdayWin, Tahoma33);
    }
    //
    thursdayWin = WM_GetDialogItem(hWin, ID_TEXT_THURSDAY);
    TEXT_SetTextAlign(thursdayWin, GUI_TA_HCENTER | GUI_TA_VCENTER);
    TEXT_SetTextColor(thursdayWin, GUI_MAKE_COLOR(0x00FFFFFF));
    if (selected_day == 3)
    {
        TEXT_SetFont(thursdayWin, Tahoma33B);
    }
    else
    {
        TEXT_SetFont(thursdayWin, Tahoma33);
    }
    //
    fridayWin = WM_GetDialogItem(hWin, ID_TEXT_FRIDAY);
    TEXT_SetTextAlign(fridayWin, GUI_TA_HCENTER | GUI_TA_VCENTER);
    TEXT_SetTextColor(fridayWin, GUI_MAKE_COLOR(0x00FFFFFF));
    if (selected_day == 4)
    {
        TEXT_SetFont(fridayWin, Tahoma33B);
    }
    else
    {
        TEXT_SetFont(fridayWin, Tahoma33);
    }
    //
    saturdayWin = WM_GetDialogItem(hWin, ID_TEXT_SATURDAY);
    TEXT_SetTextAlign(saturdayWin, GUI_TA_HCENTER | GUI_TA_VCENTER);
    TEXT_SetTextColor(saturdayWin, GUI_MAKE_COLOR(0x00FFFFFF));
    if (selected_day == 5)
    {
        TEXT_SetFont(saturdayWin, Tahoma33B);
    }
    else
    {
        TEXT_SetFont(saturdayWin, Tahoma33);
    }
    //
    sundayWin = WM_GetDialogItem(hWin, ID_TEXT_SUNDAY);
    TEXT_SetTextAlign(sundayWin, GUI_TA_HCENTER | GUI_TA_VCENTER);
    TEXT_SetTextColor(sundayWin, GUI_MAKE_COLOR(0x00FFFFFF));
    if (selected_day == 6)
    {
        TEXT_SetFont(sundayWin, Tahoma33B);
    }
    else
    {
        TEXT_SetFont(sundayWin, Tahoma33);
    }
}

static void scheduleHeader(WM_HWIN hWin)
{
    scheduleHeaderWin = WM_GetDialogItem(hWin, ID_TEXT_HEADER);
    TEXT_SetFont(scheduleHeaderWin, HEADER_FONT);
    TEXT_SetTextAlign(scheduleHeaderWin, GUI_TA_RIGHT | GUI_TA_VCENTER);
    TEXT_SetTextColor(scheduleHeaderWin, GUI_MAKE_COLOR(0x00FFFFFF));
    TEXT_SetText(scheduleHeaderWin, LANG("EDIT SCHEDULE:"));
    //
    textTitle = WM_GetDialogItem(hWin, ID_TEXT_TITLE);
    TEXT_SetTextAlign(textTitle, GUI_TA_LEFT | GUI_TA_VCENTER);
    TEXT_SetFont(textTitle, HEADER_FONT_BOLD);
    TEXT_SetTextColor(textTitle, GUI_MAKE_COLOR(0x00FFFFFF));
    TEXT_SetText(textTitle, LANG(toup(edit_title)));
}

static void _cbDialog(WM_MESSAGE * pMsg)
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

        GUI_SetColor(0xf0f0f0);
        GUI_AA_FillRoundedRect(26, 80, 384, 218, 3);
        GUI_SetColor(0xcecece);
        GUI_SetPenSize(2);
        GUI_AA_DrawRoundedRect(26, 80, 384, 218, 3);

        GUI_DrawHLine(115, 36, 124);
        GUI_DrawHLine(116, 36, 124);
        GUI_DrawHLine(148, 36, 124);
        GUI_DrawHLine(149, 36, 124);
        GUI_DrawHLine(181, 36, 124);
        GUI_DrawHLine(182, 36, 124);

        GUI_DrawVLine(136, 80, 218);
        break;
    case WM_INIT_DIALOG:
        scheduleHeader(pMsg->hWin);
        eachDayHeader(pMsg->hWin);

        if (each_day)
        {
            WM_HideWindow(scheduleHeaderWin);
            WM_HideWindow(textTitle);

            WM_ShowWindow(mondayWin);
            WM_ShowWindow(tuesdayWin);
            WM_ShowWindow(wednesdayWin);
            WM_ShowWindow(thursdayWin);
            WM_ShowWindow(fridayWin);
            WM_ShowWindow(saturdayWin);
            WM_ShowWindow(sundayWin);
        }
        else
        {
            WM_ShowWindow(scheduleHeaderWin);
            WM_ShowWindow(textTitle);

            WM_HideWindow(mondayWin);
            WM_HideWindow(tuesdayWin);
            WM_HideWindow(wednesdayWin);
            WM_HideWindow(thursdayWin);
            WM_HideWindow(fridayWin);
            WM_HideWindow(saturdayWin);
            WM_HideWindow(sundayWin);
        }
        //
        hItem = WM_GetDialogItem(pMsg->hWin, ID_TEXT_PERIOD);
        TEXT_SetTextAlign(hItem, GUI_TA_HCENTER);
        TEXT_SetFont(hItem, Tahoma19B);
        TEXT_SetTextColor(hItem, GUI_MAKE_COLOR(0x6c8e54));
        TEXT_SetText(hItem, LANG("Personal"));

        wake_win = WM_GetDialogItem(pMsg->hWin, ID_TEXT_WAKE);
        TEXT_SetTextAlign(wake_win, GUI_TA_HCENTER | GUI_TA_VCENTER);
        TEXT_SetFont(wake_win, Tahoma19B);
        TEXT_SetTextColor(wake_win, GUI_MAKE_COLOR(0x707070));
        TEXT_SetText(wake_win, LANG("WAKE"));
        //
        leave_win = WM_GetDialogItem(pMsg->hWin, ID_TEXT_LEAVE);
        TEXT_SetText(leave_win, LANG("LEAVE"));
        TEXT_SetTextAlign(leave_win, GUI_TA_HCENTER | GUI_TA_VCENTER);
        TEXT_SetFont(leave_win, Tahoma19B);
        TEXT_SetTextColor(leave_win, GUI_MAKE_COLOR(0x707070));
        //
        return_win = WM_GetDialogItem(pMsg->hWin, ID_TEXT_RETURN);
        TEXT_SetText(return_win, LANG("RETURN"));
        TEXT_SetTextAlign(return_win, GUI_TA_HCENTER | GUI_TA_VCENTER);
        TEXT_SetFont(return_win, Tahoma19B);
        TEXT_SetTextColor(return_win, GUI_MAKE_COLOR(0x707070));
        //
        sleep_win = WM_GetDialogItem(pMsg->hWin, ID_TEXT_SLEEP);
        TEXT_SetText(sleep_win, LANG("SLEEP"));
        TEXT_SetTextAlign(sleep_win, GUI_TA_HCENTER | GUI_TA_VCENTER);
        TEXT_SetFont(sleep_win, Tahoma19B);
        TEXT_SetTextColor(sleep_win, GUI_MAKE_COLOR(0x707070));
        //
        // TIME COLUMN
        hItem = WM_GetDialogItem(pMsg->hWin, ID_TEXT_TIME);
        TEXT_SetTextAlign(hItem, GUI_TA_HCENTER);
        TEXT_SetFont(hItem, Tahoma19B);
        TEXT_SetTextColor(hItem, GUI_MAKE_COLOR(0x6c8e54));
        TEXT_SetText(hItem, LANG("Time"));

        wake_time_win = WM_GetDialogItem(pMsg->hWin, ID_TEXT_WAKE_TIME);
        TEXT_SetText(wake_time_win, getTime(getPeriod(periods_text[0]).startTime));
        TEXT_SetTextColor(wake_time_win, 0x808080);
        WM_SetCallback(wake_time_win, slot_cb);

        leave_time_win = WM_GetDialogItem(pMsg->hWin, ID_TEXT_LEAVE_TIME);
        TEXT_SetText(leave_time_win, getTime(getPeriod(periods_text[1]).startTime));
        TEXT_SetTextColor(leave_time_win, 0x808080);
        WM_SetCallback(leave_time_win, slot_cb);

        return_time_win = WM_GetDialogItem(pMsg->hWin, ID_TEXT_RETURN_TIME);
        TEXT_SetText(return_time_win, getTime(getPeriod(periods_text[2]).startTime));
        TEXT_SetTextColor(return_time_win, 0x808080);
        WM_SetCallback(return_time_win, slot_cb);

        sleep_time_win = WM_GetDialogItem(pMsg->hWin, ID_TEXT_SLEEP_TIME);
        TEXT_SetText(sleep_time_win, getTime(getPeriod(periods_text[3]).startTime));
        TEXT_SetTextColor(sleep_time_win, 0x808080);
        WM_SetCallback(sleep_time_win, slot_cb);
        //
        // HEAT COLUMN
        hItem = WM_GetDialogItem(pMsg->hWin, ID_TEXT_HEAT);
        TEXT_SetTextAlign(hItem, GUI_TA_HCENTER);
        TEXT_SetFont(hItem, Tahoma19B);
        TEXT_SetTextColor(hItem, GUI_MAKE_COLOR(0x6c8e54));
        TEXT_SetText(hItem, LANG("Heat"));

        wake_heat_win = WM_GetDialogItem(pMsg->hWin, ID_TEXT_WAKE_HEAT);
        sprintf(buf, "%s°",  convertTemp(getPeriod(periods_text[0]).heat));
        TEXT_SetText(wake_heat_win, buf);
        TEXT_SetTextColor(wake_heat_win, GUI_DARKRED);
        WM_SetCallback(wake_heat_win, slot_cb);

        leave_heat_win = WM_GetDialogItem(pMsg->hWin, ID_TEXT_LEAVE_HEAT);
        sprintf(buf, "%s°",  convertTemp(getPeriod(periods_text[1]).heat));
        TEXT_SetText(leave_heat_win, buf);
        TEXT_SetTextColor(leave_heat_win, GUI_DARKRED);
        WM_SetCallback(leave_heat_win, slot_cb);

        return_heat_win = WM_GetDialogItem(pMsg->hWin, ID_TEXT_RETURN_HEAT);
        sprintf(buf, "%s°",  convertTemp(getPeriod(periods_text[2]).heat));
        TEXT_SetText(return_heat_win, buf);
        TEXT_SetTextColor(return_heat_win, GUI_DARKRED);
        WM_SetCallback(return_heat_win, slot_cb);

        sleep_heat_win = WM_GetDialogItem(pMsg->hWin, ID_TEXT_SLEEP_HEAT);
        sprintf(buf, "%s°",  convertTemp(getPeriod(periods_text[3]).heat));
        TEXT_SetText(sleep_heat_win, buf);
        TEXT_SetTextColor(sleep_heat_win, GUI_DARKRED);
        WM_SetCallback(sleep_heat_win, slot_cb);
        //
        // COOL COLUMN
        hItem = WM_GetDialogItem(pMsg->hWin, ID_TEXT_COOL);
        TEXT_SetTextAlign(hItem, GUI_TA_HCENTER);
        TEXT_SetFont(hItem, Tahoma19B);
        TEXT_SetTextColor(hItem, GUI_MAKE_COLOR(0x6c8e54));
        TEXT_SetText(hItem, LANG("Cool"));

        wake_cool_win = WM_GetDialogItem(pMsg->hWin, ID_TEXT_WAKE_COOL);
        sprintf(buf, "%s°",  convertTemp(getPeriod(periods_text[0]).cool));
        TEXT_SetText(wake_cool_win, buf);
        TEXT_SetTextColor(wake_cool_win, GUI_LIGHTBLUE);
        WM_SetCallback(wake_cool_win, slot_cb);

        leave_cool_win = WM_GetDialogItem(pMsg->hWin, ID_TEXT_LEAVE_COOL);
        sprintf(buf, "%s°",  convertTemp(getPeriod(periods_text[1]).cool));
        TEXT_SetText(leave_cool_win, buf);
        TEXT_SetTextColor(leave_cool_win, GUI_LIGHTBLUE);
        WM_SetCallback(leave_cool_win, slot_cb);

        return_cool_win = WM_GetDialogItem(pMsg->hWin, ID_TEXT_RETURN_COOL);
        sprintf(buf, "%s°",  convertTemp(getPeriod(periods_text[2]).cool));
        TEXT_SetText(return_cool_win, buf);
        TEXT_SetTextColor(return_cool_win, GUI_LIGHTBLUE);
        WM_SetCallback(return_cool_win, slot_cb);

        sleep_cool_win = WM_GetDialogItem(pMsg->hWin, ID_TEXT_SLEEP_COOL);
        sprintf(buf, "%s°",  convertTemp(getPeriod(periods_text[3]).cool));
        TEXT_SetText(sleep_cool_win, buf);
        TEXT_SetTextColor(sleep_cool_win, GUI_LIGHTBLUE);
        WM_SetCallback(sleep_cool_win, slot_cb);

        timeUpButton = WM_GetDialogItem(pMsg->hWin, ID_BUTTON_TIME_UP);
        WM_SetCallback(timeUpButton, upButton_cb);
        //
        timeDnButton = WM_GetDialogItem(pMsg->hWin, ID_BUTTON_TIME_DN);
        WM_SetCallback(timeDnButton, dnButton_cb);

        hItem = WM_GetDialogItem(pMsg->hWin, ID_BUTTON_CANCEL);
        WM_SetCallback(hItem, buttonOn_cb);
        //
        weekdayButton = WM_GetDialogItem(pMsg->hWin, ID_BUTTON_WEEKDAY);
        WM_SetCallback(weekdayButton, buttonOn_cb);

        weekendButton = WM_GetDialogItem(pMsg->hWin, ID_BUTTON_WEEKEND);
        WM_SetCallback(weekendButton, buttonOn_cb);

        //
        hItem = WM_GetDialogItem(pMsg->hWin, ID_BUTTON_HELP);
        WM_SetCallback(hItem, buttonOn_cb);
        if (strcmp(edit_title,"weekend") == 0 || strcmp(edit_title,"weekday") == 0 )
        {
            WM_MoveTo(hItem, 140, 230);
            WM_SetSize(hItem, 80, BUT_HEIGHT);
            WM_ShowWindow(weekdayButton);
            WM_HideWindow(weekendButton);
        }
        else
        {
            WM_MoveTo(hItem, 185, 230);
            WM_SetSize(hItem, BUT_WIDTH, BUT_HEIGHT);
            WM_HideWindow(weekendButton);
            WM_HideWindow(weekdayButton);
        }

        hItem = WM_GetDialogItem(pMsg->hWin, ID_BUTTON_SAVE);
        WM_SetCallback(hItem, buttonOn_cb);

        invalidateButtons(0);

        break;
    case WM_NOTIFY_PARENT:
        Id    = WM_GetId(pMsg->hWinSrc);
        NCode = pMsg->Data.v;
        int tout;

        switch(Id)
        {
        case ID_TEXT_WAKE_TIME:
            switch(NCode)
            {
            case WM_NOTIFICATION_CLICKED:
                invalidateButtons(0);
                break;
            }
            break;
        case ID_TEXT_LEAVE_TIME:
            switch(NCode)
            {
            case WM_NOTIFICATION_CLICKED:
                invalidateButtons(1);
                break;
            }
            break;
        case ID_TEXT_RETURN_TIME:
            switch(NCode)
            {
            case WM_NOTIFICATION_CLICKED:
                invalidateButtons(2);
                break;
            }
            break;
        case ID_TEXT_SLEEP_TIME:
            switch(NCode)
            {
            case WM_NOTIFICATION_CLICKED:
                invalidateButtons(3);
                break;
            }
            break;
        case ID_TEXT_WAKE_HEAT:
            switch(NCode)
            {
            case WM_NOTIFICATION_CLICKED:
                invalidateButtons(4);
                break;
            }
            break;
        case ID_TEXT_LEAVE_HEAT:
            switch(NCode)
            {
            case WM_NOTIFICATION_CLICKED:
                invalidateButtons(5);
                break;
            }
            break;
        case ID_TEXT_RETURN_HEAT:
            switch(NCode)
            {
            case WM_NOTIFICATION_CLICKED:
                invalidateButtons(6);
                break;
            }
            break;
        case ID_TEXT_SLEEP_HEAT:
            switch(NCode)
            {
            case WM_NOTIFICATION_CLICKED:
                invalidateButtons(7);
                break;
            }
            break;
        case ID_TEXT_WAKE_COOL:
            switch(NCode)
            {
            case WM_NOTIFICATION_CLICKED:
                invalidateButtons(8);
                break;
            }
            break;
        case ID_TEXT_LEAVE_COOL:
            switch(NCode)
            {
            case WM_NOTIFICATION_CLICKED:
                invalidateButtons(9);
                break;
            }
            break;
        case ID_TEXT_RETURN_COOL:
            switch(NCode)
            {
            case WM_NOTIFICATION_CLICKED:
                invalidateButtons(10);
                break;
            }
            break;
        case ID_TEXT_SLEEP_COOL:
            switch(NCode)
            {
            case WM_NOTIFICATION_CLICKED:
                invalidateButtons(11);
                break;
            }
            break;
        case ID_TEXT_MONDAY:
            switch(NCode)
            {
            case WM_NOTIFICATION_RELEASED:
                selected_day = 0;
                setDays(pMsg->hWin, 0);
                resetFonts(pMsg->hWin, ID_TEXT_MONDAY);
                break;
            }
            break;
        case ID_TEXT_TUESDAY:
            switch(NCode)
            {
            case WM_NOTIFICATION_RELEASED:
                selected_day = 1;
                setDays(pMsg->hWin, 1);
                resetFonts(pMsg->hWin, ID_TEXT_TUESDAY);
                break;
            }
            break;
        case ID_TEXT_WEDNESDAY:
            switch(NCode)
            {
            case WM_NOTIFICATION_RELEASED:
                selected_day = 2;
                setDays(pMsg->hWin, 2);
                resetFonts(pMsg->hWin, ID_TEXT_WEDNESDAY);
                break;
            }
            break;
        case ID_TEXT_THURSDAY:
            switch(NCode)
            {
            case WM_NOTIFICATION_RELEASED:
                selected_day = 3;
                setDays(pMsg->hWin, 3);
                resetFonts(pMsg->hWin, ID_TEXT_THURSDAY);
                break;
            }
            break;
        case ID_TEXT_FRIDAY:
            switch(NCode)
            {
            case WM_NOTIFICATION_RELEASED:
                selected_day = 4;
                setDays(pMsg->hWin, 4);
                resetFonts(pMsg->hWin, ID_TEXT_FRIDAY);
                break;
            }
            break;
        case ID_TEXT_SATURDAY:
            switch(NCode)
            {
            case WM_NOTIFICATION_RELEASED:
                selected_day = 5;
                setDays(pMsg->hWin, 5);
                resetFonts(pMsg->hWin, ID_TEXT_SATURDAY);
                break;
            }
            break;
        case ID_TEXT_SUNDAY:
            switch(NCode)
            {
            case WM_NOTIFICATION_RELEASED:
                selected_day = 6;
                setDays(pMsg->hWin, 6);
                resetFonts(pMsg->hWin, ID_TEXT_SUNDAY);
                break;
            }
            break;
        case ID_BUTTON_TIME_UP:
            switch(NCode)
            {
            case WM_NOTIFICATION_CLICKED:
                switch(selected_slot)
                {
                case 0:
                    TEXT_GetText(wake_time_win, buf, 10);
                    TEXT_SetText(wake_time_win, updateTime(buf, 1, &tout));
                    selectedDay.periods[selected_period].startTime = tout;
                    break;
                case 1:
                    TEXT_GetText(leave_time_win, buf, 10);
                    TEXT_SetText(leave_time_win, updateTime(buf, 1, &tout));
                    selectedDay.periods[selected_period].startTime = tout;
                    break;
                case 2:
                    TEXT_GetText(return_time_win, buf, 10);
                    TEXT_SetText(return_time_win, updateTime(buf, 1, &tout));
                    selectedDay.periods[selected_period].startTime = tout;
                    break;
                case 3:
                    TEXT_GetText(sleep_time_win, buf, 10);
                    TEXT_SetText(sleep_time_win, updateTime(buf, 1, &tout));
                    selectedDay.periods[selected_period].startTime = tout;
                    break;
                case 4:
                    temperature = selectedDay.periods[selected_period].heat + 1;
                    if (temperature == 86) temperature = 85;
                    sprintf(buf, "%s°", convertTemp((float)temperature));
                    TEXT_SetText(wake_heat_win,buf);
                    selectedDay.periods[selected_period].heat = temperature;
                    break;
                case 5:
                    temperature = selectedDay.periods[selected_period].heat + 1;
                    if (temperature == 86) temperature = 85;
                    sprintf(buf, "%s°", convertTemp((float)temperature));
                    TEXT_SetText(leave_heat_win, buf);
                    selectedDay.periods[selected_period].heat = temperature;
                    break;
                case 6:
                    temperature = selectedDay.periods[selected_period].heat + 1;
                    if (temperature == 86) temperature = 85;
                    sprintf(buf, "%s°", convertTemp((float)temperature));
                    TEXT_SetText(return_heat_win,buf);
                    selectedDay.periods[selected_period].heat = temperature;
                    break;
                case 7:
                    temperature = selectedDay.periods[selected_period].heat + 1;
                    if (temperature == 86) temperature = 85;
                    sprintf(buf, "%s°", convertTemp((float)temperature));
                    TEXT_SetText(sleep_heat_win,buf);
                    selectedDay.periods[selected_period].heat = temperature;
                    break;
                case 8:
                    temperature = selectedDay.periods[selected_period].cool + 1;
                    if (temperature == 86) temperature = 85;
                    sprintf(buf, "%s°", convertTemp((float)temperature));
                    TEXT_SetText(wake_cool_win,buf);
                    selectedDay.periods[selected_period].cool = temperature;
                    break;
                case 9:
                    temperature = selectedDay.periods[selected_period].cool + 1;
                    if (temperature == 86) temperature = 85;
                    sprintf(buf, "%s°", convertTemp((float)temperature));
                    TEXT_SetText(leave_cool_win, buf);
                    selectedDay.periods[selected_period].cool = temperature;
                    break;
                case 10:
                    temperature = selectedDay.periods[selected_period].cool + 1;
                    if (temperature == 86) temperature = 85;
                    sprintf(buf, "%s°", convertTemp((float)temperature));
                    TEXT_SetText(return_cool_win,buf);
                    selectedDay.periods[selected_period].cool = temperature;
                    break;
                case 11:
                    temperature = selectedDay.periods[selected_period].cool + 1;
                    if (temperature == 86) temperature = 85;
                    sprintf(buf, "%s°", convertTemp((float)temperature));
                    TEXT_SetText(sleep_cool_win,buf);
                    selectedDay.periods[selected_period].cool = temperature;
                    break;
                }
                break;
            }
            break;
        case ID_BUTTON_TIME_DN:
            switch(NCode)
            {
            case WM_NOTIFICATION_CLICKED:
                switch(selected_slot)
                {
                case 0:
                    TEXT_GetText(wake_time_win, buf, 10);
                    TEXT_SetText(wake_time_win, updateTime(buf, -1, &tout));
                    selectedDay.periods[selected_period].startTime = tout;
                    break;
                case 1:
                    TEXT_GetText(leave_time_win, buf, 10);
                    TEXT_SetText(leave_time_win, updateTime(buf, -1, &tout));
                    selectedDay.periods[selected_period].startTime = tout;
                    break;
                case 2:
                    TEXT_GetText(return_time_win, buf, 10);
                    TEXT_SetText(return_time_win, updateTime(buf, -1, &tout));
                    selectedDay.periods[selected_period].startTime = tout;
                    break;
                case 3:
                    TEXT_GetText(sleep_time_win, buf, 10);
                    TEXT_SetText(sleep_time_win, updateTime(buf, -1, &tout));
                    selectedDay.periods[selected_period].startTime = tout;
                    break;
                case 4:
                    temperature = selectedDay.periods[selected_period].heat - 1;
                    if (temperature == 64) temperature = 65;
                    sprintf(buf, "%s°", convertTemp((float)temperature));
                    TEXT_SetText(wake_heat_win,buf);
                    selectedDay.periods[selected_period].heat = temperature;
                    break;
                case 5:
                    temperature = selectedDay.periods[selected_period].heat - 1;
                    if (temperature == 64) temperature = 65;
                    sprintf(buf, "%s°", convertTemp((float)temperature));
                    TEXT_SetText(leave_heat_win, buf);
                    selectedDay.periods[selected_period].heat = temperature;
                    break;
                case 6:
                    temperature = selectedDay.periods[selected_period].heat - 1;
                    if (temperature == 64) temperature = 65;
                    sprintf(buf, "%s°", convertTemp((float)temperature));
                    TEXT_SetText(return_heat_win,buf);
                    selectedDay.periods[selected_period].heat = temperature;
                    break;
                case 7:
                    temperature = selectedDay.periods[selected_period].heat - 1;
                    if (temperature == 64) temperature = 65;
                    sprintf(buf, "%s°", convertTemp((float)temperature));
                    TEXT_SetText(sleep_heat_win,buf);
                    selectedDay.periods[selected_period].heat = temperature;
                    break;
                case 8:
                    temperature = selectedDay.periods[selected_period].cool - 1;
                    if (temperature == 64) temperature = 65;
                    sprintf(buf, "%s°", convertTemp((float)temperature));
                    TEXT_SetText(wake_cool_win,buf);
                    selectedDay.periods[selected_period].cool = temperature;
                    break;
                case 9:
                    temperature = selectedDay.periods[selected_period].cool - 1;
                    if (temperature == 64) temperature = 65;
                    sprintf(buf, "%s°", convertTemp((float)temperature));
                    TEXT_SetText(leave_cool_win, buf);
                    selectedDay.periods[selected_period].cool = temperature;
                    break;
                case 10:
                    temperature = selectedDay.periods[selected_period].cool - 1;
                    if (temperature == 64) temperature = 65;
                    sprintf(buf, "%s°", convertTemp((float)temperature));
                    TEXT_SetText(return_cool_win,buf);
                    selectedDay.periods[selected_period].cool = temperature;
                    break;
                case 11:
                    temperature = selectedDay.periods[selected_period].cool - 1;
                    if (temperature == 64) temperature = 65;
                    sprintf(buf, "%s°", convertTemp((float)temperature));
                    TEXT_SetText(sleep_cool_win,buf);
                    selectedDay.periods[selected_period].cool = temperature;
                    break;
                }
                break;
            }
            break;
        case ID_BUTTON_CANCEL:
            switch(NCode)
            {
            case WM_NOTIFICATION_CLICKED:
                WM_HideWindow(editScheduleWin);
                GUI_Delay(100);
                screenState = SETTINGSCHEDULEWIN;
                break;
            }
            break;
        case ID_BUTTON_HELP:
            switch(NCode)
            {
            case WM_NOTIFICATION_CLICKED:
                GUI_Delay(100);
                CreateEditScheduleHelp(edit_sched, edit_title);
                break;
            }
            break;
        case ID_BUTTON_WEEKDAY:
            switch(NCode)
            {
            case WM_NOTIFICATION_CLICKED:
                GUI_Delay(100);
                selectWeekType();
                setPeriods();
            }
            break;
        case ID_BUTTON_WEEKEND:
            switch(NCode)
            {
            case WM_NOTIFICATION_CLICKED:
                GUI_Delay(100);
                selectWeekType();
                setPeriods();
            }
            break;
        case ID_BUTTON_SAVE:
            switch(NCode)
            {
            case WM_NOTIFICATION_RELEASED:
               GUI_Delay(100);
                int i;
                char buf[100];
                for (i=0; i<4; i++)
                {
                    setSchedule(selectedSchedule.label, selectedDay.label, periods_text[i],
                                selectedDay.periods[getPeriodIndex(periods_text[i])]);
                }

                for (i=0; i<5; i++)
                {
                    if (strcmp(schedules[i].label, tolow(schedulePeriod)) == 0)
                    {
                        selectedSchedule = schedules[i];
                        break;
                    }
                }

                WM_MESSAGE msg;
                msg.MsgId = WM_INIT_DIALOG;
                WM_SendMessage(homeWin, &msg);
                WM_HideWindow(editScheduleWin);
                screenState = SETTINGSCHEDULEWIN;
                break;
            }
            break;
        }
    default:
        WM_DefaultProc(pMsg);
        break;
    }
}

static void setPeriods()
{
    char buf[10];

    TEXT_SetText(wake_time_win, getTime(getPeriod(periods_text[0]).startTime));
    TEXT_SetText(leave_time_win,getTime(getPeriod(periods_text[1]).startTime));
    TEXT_SetText(return_time_win,getTime(getPeriod(periods_text[2]).startTime));
    TEXT_SetText(sleep_time_win,getTime(getPeriod(periods_text[3]).startTime));

    sprintf(buf,"%s°", convertTemp((float)getPeriod(periods_text[0]).heat));
    TEXT_SetText(wake_heat_win, buf);

    sprintf(buf,"%s°", convertTemp((float)getPeriod(periods_text[1]).heat));
    TEXT_SetText(leave_heat_win, buf);

    sprintf(buf,"%s°", convertTemp((float)getPeriod(periods_text[2]).heat));
    TEXT_SetText(return_heat_win, buf);

    sprintf(buf,"%s°", convertTemp((float)getPeriod(periods_text[3]).heat));
    TEXT_SetText(sleep_heat_win, buf);

    sprintf(buf,"%s°", convertTemp((float)getPeriod(periods_text[0]).cool));
    TEXT_SetText(wake_cool_win, buf);

    sprintf(buf,"%s°", convertTemp((float)getPeriod(periods_text[1]).cool));
    TEXT_SetText(leave_cool_win, buf);

    sprintf(buf,"%s°", convertTemp((float)getPeriod(periods_text[2]).cool));
    TEXT_SetText(return_cool_win, buf);

    sprintf(buf,"%s°", convertTemp((float)getPeriod(periods_text[3]).cool));
    TEXT_SetText(sleep_cool_win, buf);
}

static void setDays(WM_HWIN *hWin, int d)
{
    char buf [20];
    WM_HWIN  hItem;

    selectedDay = getDay(days_text[d]);
    setPeriods();
}

static int getPeriodIndex(char * s)
{
    int i;
    for (i=0; i<4; i++)
    {
        if (strcmp(selectedDay.periods[i].label, s) == 0)
        {
            return i;
        }
    }
    return 0;
}

static struct periods_s getPeriod(char * s)
{
    int i;
    for (i=0; i<4; i++)
    {
        if (strcmp(selectedDay.periods[i].label, s) == 0)
        {
            return selectedDay.periods[i];
        }
    }
}

static void setSchedule(char *sched, char *day, char *per, struct periods_s period)
{
    int i,j,k;
    char buf[50];

    for (i=0; i<5; i++)
    {
        if (strcmp(schedules[i].label, sched) == 0)
        {
            for (j=0; j<schedules[i].day_count; j++)
            {
                if (strcmp(schedules[i].days[j].label, day) == 0)
                {
                    for (k=0; k<4; k++)
                    {
                        if (strcmp(schedules[i].days[j].periods[k].label, per) == 0)
                        {
                            schedules[i].days[j].periods[k] = period;
                            return;
                        }
                    }
                }
            }
        }
    }
}

WM_HWIN CreateEditSchedule();
WM_HWIN CreateEditSchedule()
{
    WM_HWIN hWin;
    int i;

    strcpy(edit_title, scheduleDay);
    strcpy(edit_sched, schedulePeriod);

    if (strcmp(edit_title, "monday") == 0)
    {
        each_day = 1;
        getDayPeriods();
        selectedDay = getDay(scheduleDay);
    }
    else
    {
        each_day = 0;
    }

    for (i=0; i<5; i++)
    {
        if (strcmp(schedules[i].label, tolow(schedulePeriod)) == 0)
        {
            selectedSchedule = schedules[i];
            break;
        }
    }

    for (i=0; i<selectedSchedule.day_count; i++)
    {
        if (strcmp(selectedSchedule.days[i].label, tolow(scheduleDay)) == 0)
        {
            selectedDay = selectedSchedule.days[i];
            break;
        }
    }

    selected_period = getPeriodIndex(periods_text[period]);

    editScheduleWin = GUI_CreateDialogBox(_aDialogCreate,
                                          GUI_COUNTOF(_aDialogCreate), _cbDialog, WM_HBKWIN, 0, 0);
    return hWin;
}
