#include "ranger.h"

#define ID_WINDOW_0 (GUI_ID_USER + 0x02)
#define ID_TEXT_HEADER (GUI_ID_USER + 0x08)
#define ID_BUTTON_CANCEL (GUI_ID_USER + 0x11)
#define ID_BUTTON_WEEKDAY (GUI_ID_USER + 0x14)
#define ID_BUTTON_SAVE (GUI_ID_USER + 0x15)
#define ID_TEXT_TITLE (GUI_ID_USER + 0x25)
#define ID_BUTTON_PERIOD (GUI_ID_USER + 0x26)
#define ID_BUTTON_START (GUI_ID_USER + 0x27)
#define ID_BUTTON_STOP (GUI_ID_USER + 0x28)
#define ID_BUTTON_TEMPURATURE (GUI_ID_USER + 0x29)
#define ID_TEXT_WAKE (GUI_ID_USER + 0x2A)
#define ID_TEXT_START_TIME (GUI_ID_USER + 0x2B)
#define ID_TEXT_STOP_TIME (GUI_ID_USER + 0x2C)
#define ID_TEXT_TEMP_VAR (GUI_ID_USER + 0x2D)
#define ID_BUTTON_UP (GUI_ID_USER + 0x2E)
#define ID_BUTTON_DN (GUI_ID_USER + 0x2F)
#define ID_BUTTON_HELP (GUI_ID_USER + 0x30)

/*********************************************************************
*
*       _aDialogCreate
*/
static const GUI_WIDGET_CREATE_INFO _aDialogCreate[] =
{
    { WINDOW_CreateIndirect, "Window", ID_WINDOW_0, 0, 0, 480, 272, 0, 0x0, 0 },
    { TEXT_CreateIndirect, "EDIT SCHEDULE:", ID_TEXT_HEADER, 0, 0, 260, 50, 0, 0x64, 0 },
    { TEXT_CreateIndirect, "", ID_TEXT_TITLE, 270, 0, 280, 50, 0, 0x64, 0 },
    { BUTTON_CreateIndirect, "PERIOD", ID_BUTTON_PERIOD, 25, 90, 90, 28, 0, 0x0, 0 },
    { BUTTON_CreateIndirect, "START", ID_BUTTON_START, 135, 90, 90, 28, 0, 0x0, 0 },
    { BUTTON_CreateIndirect, "STOP", ID_BUTTON_STOP, 245, 90, 90, 28, 0, 0x0, 0 },
    { BUTTON_CreateIndirect, "Button", ID_BUTTON_TEMPURATURE, 355, 90, 90, 28, 0, 0x0, 0 },
    { TEXT_CreateIndirect, "WAKE", ID_TEXT_WAKE, 31, 60, 83, 23, 0, 0x64, 0 },
    { TEXT_CreateIndirect, "Text", ID_TEXT_START_TIME, 144, 60, 80, 23, 0, 0x64, 0 },
    { TEXT_CreateIndirect, "Text", ID_TEXT_STOP_TIME, 251, 62, 81, 22, 0, 0x64, 0 },
    { TEXT_CreateIndirect, "TEMP", ID_TEXT_TEMP_VAR, 363, 63, 80, 20, 0, 0x64, 0 },
    { BUTTON_CreateIndirect, "", ID_BUTTON_UP, 45, 124, 48, 48, 0, 0x0, 0 },
    { BUTTON_CreateIndirect, "", ID_BUTTON_DN, 45, 168, 48, 48, 0, 0x0, 0 },
    { BUTTON_CreateIndirect, "CANCEL", ID_BUTTON_CANCEL, 20, 230, 80, 28, 0, 0x0, 0 },
    { BUTTON_CreateIndirect, "WEEKDAY", ID_BUTTON_WEEKDAY, 236, 230, 110, 28, 0, 0x0, 0 },
    { BUTTON_CreateIndirect, "HELP", ID_BUTTON_HELP, 200, 230, 80, 28, 0, 0x0, 0 },
    { BUTTON_CreateIndirect, "SAVE", ID_BUTTON_SAVE, 375, 230, 80, 28, 0, 0x0, 0 },
};

static WM_HWIN periodButton, startButton, stopButton, tempButton;
static WM_HWIN period_text, start_text, stop_text, temp_text;
static WM_HWIN upButton, dnButton, weekdayButton;

static int period_idx, tempurature, period, selected_period;

static struct periods_s getPeriod(char * p);
static int getPeriodInt(char * p);
static void setSchedule(char *sched, char *day, char *per, struct periods_s period);
static struct days_s selectedDay;

static char *periods_text[] = {"wake","leave","return","sleep"};
static char edit_title[20], edit_sched[20];

static int period_on, start_on, stop_on, temp_on;

static void periodButton_cb(WM_MESSAGE * pMsg)
{
    scheduleButton(pMsg, "PERIOD", period_on);
}

static void start_button_on(WM_MESSAGE * pMsg)
{
    scheduleButton(pMsg, "START", start_on);
}

static void stopButton_cb(WM_MESSAGE * pMsg)
{
    scheduleButton(pMsg, "STOP", stop_on);
}

static void tempButton_cb(WM_MESSAGE * pMsg)
{
    scheduleButton(pMsg, "TEMP", temp_on);
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
            GUI_DrawBitmap(&bmdn_r, 0, 0);
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

static void invalidateButtons(int sel)
{
    WM_InvalidateWindow(periodButton);
    WM_InvalidateWindow(startButton);
    WM_InvalidateWindow(startButton);
    WM_InvalidateWindow(stopButton);
    WM_InvalidateWindow(tempButton);

    WM_MoveTo(upButton, 45+sel*110,124);
    WM_MoveTo(dnButton, 45+sel*110,168);

    period_idx = sel;
    period_on = (sel == 0);
    start_on  = (sel == 1);
    stop_on   = (sel == 2);
    temp_on   = (sel == 3);
}

static char * getTime(int st)
{

    static char buf[30];
    if (clockFormat == 24)
    {
        sprintf(buf, "%02d:%02d",  st/60, st - (st/60)*60);
    }
    else
    {
        int sh = st/60;
        if (sh > 12) sh -= 12;
        sprintf(buf, "%d:%02d%s",
                sh, st - (st/60)*60, ((st/60 < 12) ? "am" : "pm"));
    }
    return buf;
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
    char buf[10];

    switch (pMsg->MsgId)
    {
    case WM_PAINT:
        GUI_DrawGradientV(0, 0, 480, 50, 0x63b39b, 0x48866c);
        GUI_DrawBitmap(&bmwatermark,45,52);
        break;
    case WM_INIT_DIALOG:
        hItem = WM_GetDialogItem(pMsg->hWin, ID_TEXT_HEADER);
        TEXT_SetFont(hItem, GUI_FONT_32_1);
        TEXT_SetTextAlign(hItem, GUI_TA_RIGHT | GUI_TA_VCENTER);
        TEXT_SetTextColor(hItem, GUI_MAKE_COLOR(0x00FFFFFF));
        //
        hItem = WM_GetDialogItem(pMsg->hWin, ID_TEXT_TITLE);
        TEXT_SetTextAlign(hItem, GUI_TA_LEFT | GUI_TA_VCENTER);
        TEXT_SetFont(hItem, GUI_FONT_32B_1);
        TEXT_SetTextColor(hItem, GUI_MAKE_COLOR(0x00FFFFFF));
        TEXT_SetText(hItem, toup(edit_title));
        //
        periodButton = WM_GetDialogItem(pMsg->hWin, ID_BUTTON_PERIOD);
        WM_SetCallback(periodButton, periodButton_cb);
        //
        startButton = WM_GetDialogItem(pMsg->hWin, ID_BUTTON_START);
        WM_SetCallback(startButton, start_button_on);
        //
        stopButton = WM_GetDialogItem(pMsg->hWin, ID_BUTTON_STOP);
        WM_SetCallback(stopButton, stopButton_cb);
        //
        tempButton = WM_GetDialogItem(pMsg->hWin, ID_BUTTON_TEMPURATURE);
        WM_SetCallback(tempButton, tempButton_cb);
        //
        period_text = WM_GetDialogItem(pMsg->hWin, ID_TEXT_WAKE);
        TEXT_SetFont(period_text, GUI_FONT_20B_1);
        TEXT_SetTextAlign(period_text, GUI_TA_HCENTER | GUI_TA_VCENTER);
        TEXT_SetTextColor(period_text, GUI_MAKE_COLOR(0x00808080));
        TEXT_SetText(period_text, toup(getPeriod(periods_text[0]).label));
        //
        start_text = WM_GetDialogItem(pMsg->hWin, ID_TEXT_START_TIME);
        TEXT_SetTextAlign(start_text, GUI_TA_HCENTER | GUI_TA_VCENTER);
        TEXT_SetFont(start_text, GUI_FONT_20B_1);
        TEXT_SetText(start_text, getTime(getPeriod(periods_text[0]).startMinutes));
        TEXT_SetTextColor(start_text, GUI_MAKE_COLOR(0x00808080));
        //
        stop_text = WM_GetDialogItem(pMsg->hWin, ID_TEXT_STOP_TIME);
        TEXT_SetFont(stop_text, GUI_FONT_20B_1);
        TEXT_SetTextAlign(stop_text, GUI_TA_HCENTER | GUI_TA_VCENTER);
        TEXT_SetText(stop_text,  getTime(getPeriod(periods_text[0]).stopMinutes));
        TEXT_SetTextColor(stop_text, GUI_MAKE_COLOR(0x00808080));
        //
        temp_text = WM_GetDialogItem(pMsg->hWin, ID_TEXT_TEMP_VAR);
        TEXT_SetFont(temp_text, GUI_FONT_20B_1);
        TEXT_SetTextAlign(temp_text, GUI_TA_HCENTER | GUI_TA_VCENTER);
        sprintf(buf, "%d°",  getPeriod(periods_text[0]).tempurature);
        TEXT_SetText(temp_text, buf);
        TEXT_SetTextColor(temp_text, GUI_MAKE_COLOR(0x00808080));
        //
        upButton = WM_GetDialogItem(pMsg->hWin, ID_BUTTON_UP);
        WM_SetCallback(upButton, upButton_cb);
        //
        dnButton = WM_GetDialogItem(pMsg->hWin, ID_BUTTON_DN);
        WM_SetCallback(dnButton, dnButton_cb);

        hItem = WM_GetDialogItem(pMsg->hWin, ID_BUTTON_CANCEL);
        WM_SetCallback(hItem, buttonOn16_cb);
        //
        weekdayButton = WM_GetDialogItem(pMsg->hWin, ID_BUTTON_WEEKDAY);
        WM_SetCallback(weekdayButton, buttonOn16_cb);
        if (strcmp(edit_title,"weekend") == 0 || strcmp(edit_title,"weekday") == 0 )
        {
            hItem = WM_GetDialogItem(pMsg->hWin, ID_BUTTON_HELP);
            WM_MoveTo(hItem, 128, 230);
            WM_ShowWindow(weekdayButton);
            if (strcmp(edit_title,"weekend") == 0)
            {
                BUTTON_SetText(weekdayButton, "WEEKDAY");
            }
            else
            {
                BUTTON_SetText(weekdayButton, "WEEKEND");
            }
        }
        else
        {
            WM_HideWindow(weekdayButton);
        }
        //
        hItem = WM_GetDialogItem(pMsg->hWin, ID_BUTTON_HELP);
        WM_SetCallback(hItem, buttonOn16_cb);

        hItem = WM_GetDialogItem(pMsg->hWin, ID_BUTTON_SAVE);
        WM_SetCallback(hItem, buttonOn16_cb);

        invalidateButtons(0);

        break;
    case WM_NOTIFY_PARENT:
        Id    = WM_GetId(pMsg->hWinSrc);
        NCode = pMsg->Data.v;

        switch(Id)
        {
        case ID_BUTTON_CANCEL:
            switch(NCode)
            {
            case WM_NOTIFICATION_RELEASED:
                GUI_Delay(100);
                CreateSettingsSchedule();
                //state = 13;
                break;
            }
            break;
        case ID_BUTTON_HELP:
            switch(NCode)
            {
            case WM_NOTIFICATION_RELEASED:
                GUI_Delay(100);
                CreateEditScheduleHelp(edit_sched, edit_title);
                //state = 13;
                break;
            }
            break;
        case ID_BUTTON_SAVE:
            switch(NCode)
            {
            case WM_NOTIFICATION_RELEASED:
                GUI_Delay(100);
                int i;
                for (i=0; i<4; i++)
                {
                    setSchedule(selectedSchedule.label, selectedDay.label, periods_text[i],
                                selectedDay.periods[getPeriodInt(periods_text[i])]);
                }
               if (strcmp(edit_sched, "each day") == 0) {
                    CreateEachDay(edit_title);
                } else {
                    CreateSettingsSchedule();
                }
                //state = 13;
                break;
            }
            break;
        case ID_BUTTON_WEEKDAY:
            switch(NCode)
            {
            case WM_NOTIFICATION_RELEASED:
                GUI_Delay(100);
                if (strcmp(edit_title, "weekend") ==  0)
                {
                    CreateEditSchedule("weekday", "weekday");
                }
                else
                {
                    CreateEditSchedule("weekend", "weekend");
                }
            }
            break;
        case ID_BUTTON_PERIOD:
            switch(NCode)
            {
            case WM_NOTIFICATION_RELEASED:
                invalidateButtons(0);
                break;
            }
            break;
        case ID_BUTTON_START:
            switch(NCode)
            {
            case WM_NOTIFICATION_RELEASED:
                invalidateButtons(1);
                break;
            }
            break;
        case ID_BUTTON_STOP:
            switch(NCode)
            {
            case WM_NOTIFICATION_RELEASED:
                invalidateButtons(2);
                break;
            }
            break;
        case ID_BUTTON_TEMPURATURE:
            switch(NCode)
            {
            case WM_NOTIFICATION_RELEASED:
                invalidateButtons(3);
                break;
            }
            break;
        case ID_BUTTON_UP:
            switch(NCode)
            {
            case WM_NOTIFICATION_CLICKED:
                break;
            case WM_NOTIFICATION_RELEASED:
                switch(period_idx)
                {
                case 0:
                    period++;
                    if (period == 4) period = 0;
                    selected_period = getPeriodInt(periods_text[period]);
                    TEXT_SetText(period_text, toup(selectedDay.periods[selected_period].label));
                    TEXT_SetText(start_text, getTime(selectedDay.periods[selected_period].startMinutes));
                    TEXT_SetText(stop_text, getTime(selectedDay.periods[selected_period].stopMinutes));
                    itoa(selectedDay.periods[selected_period].tempurature, buf, 10);
                    TEXT_SetText(temp_text, buf);
                    break;
                case 1:
                    TEXT_GetText(start_text, buf, 10);
                    TEXT_SetText(start_text, updateTime(buf,1));
                    selectedDay.periods[selected_period].startMinutes++;
                    if (selectedDay.periods[selected_period].startMinutes == 1441)
                    {
                        selectedDay.periods[selected_period].startMinutes = 0;
                    }
                    selectedDay.periods[selected_period].startTime = updateTime(buf,1);
                    break;
                case 2:
                    TEXT_GetText(stop_text, buf, 10);
                    TEXT_SetText(stop_text, updateTime(buf, 1));
                    selectedDay.periods[selected_period].stopMinutes++;
                    if (selectedDay.periods[selected_period].stopMinutes == 1441)
                    {
                        selectedDay.periods[selected_period].stopMinutes = 0;
                    }
                    selectedDay.periods[selected_period].stopTime = updateTime(buf,1);
                    break;
                case 3:
                    tempurature = selectedDay.periods[selected_period].tempurature + 1;
                    if (tempurature == 111) tempurature = 110;
                    sprintf(buf, "%d°", tempurature);
                    TEXT_SetText(temp_text, buf);
                    selectedDay.periods[selected_period].tempurature = tempurature;
                    break;
                }
                break;
            }
            break;
        case ID_BUTTON_DN:
            switch(NCode)
            {
            case WM_NOTIFICATION_CLICKED:
                break;
            case WM_NOTIFICATION_RELEASED:
                switch(period_idx)
                {
                case 0:
                    period--;
                    if (period == -1) period = 3;
                    selected_period = getPeriodInt(periods_text[period]);
                    TEXT_SetText(period_text, toup(selectedDay.periods[selected_period].label));
                    TEXT_SetText(start_text, getTime(selectedDay.periods[selected_period].startMinutes));
                    TEXT_SetText(stop_text, getTime(selectedDay.periods[selected_period].stopMinutes));
                    itoa(selectedDay.periods[selected_period].tempurature, buf, 10);
                    TEXT_SetText(temp_text, buf);
                    break;
                case 1:
                    TEXT_GetText(start_text, buf, 10);
                    TEXT_SetText(start_text, updateTime(buf, -1));
                    selectedDay.periods[selected_period].startMinutes--;
                    if (selectedDay.periods[selected_period].startMinutes == -1)
                    {
                        selectedDay.periods[selected_period].startMinutes = 1440;
                    }
                    selectedDay.periods[selected_period].startTime = updateTime(buf, -1);
                    break;
                case 2:
                    TEXT_GetText(stop_text, buf, 10);
                    TEXT_SetText(stop_text, updateTime(buf, -1));
                    selectedDay.periods[selected_period].stopMinutes--;
                    if (selectedDay.periods[selected_period].stopMinutes == -1)
                    {
                        selectedDay.periods[selected_period].stopMinutes = 1440;
                    }
                    selectedDay.periods[selected_period].stopTime = updateTime(buf,1);
                    break;
                case 3:
                    tempurature = selectedDay.periods[selected_period].tempurature - 1;
                    if (tempurature == 64) tempurature = 65;
                    sprintf(buf, "%d°", tempurature);
                    TEXT_SetText(temp_text, buf);
                    selectedDay.periods[selected_period].tempurature = tempurature;
                    break;
                }
                break;
            }
        }
        break;
    default:
        WM_DefaultProc(pMsg);
        break;
    }
}

static int getPeriodInt(char * s)
{
    int i;
    for (i=0; i<4; i++)
    {
        if (strcmp(selectedDay.periods[i].label, s) == 0)
        {
            return i;
        }
    }
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

/*********************************************************************
*
*       CreateWindow
*/
WM_HWIN CreateEditSchedule(char *sched, char *day);
WM_HWIN CreateEditSchedule(char *sched, char *day)
{
    WM_HWIN hWin;
    int i,j;
    strcpy(edit_title, day);
    strcpy(edit_sched, sched);

    for (i=0; i<5; i++)
    {
        if (strcmp(schedules[i].label, sched) == 0)
        {
            selectedSchedule = schedules[i];
            break;
        }
    }

    for (i=0; i<selectedSchedule.day_count; i++)
    {
        if (strcmp(selectedSchedule.days[i].label, day) == 0)
        {
            selectedDay = selectedSchedule.days[i];
            break;
        }
    }

    period = 0;
    period_on = 1;
    selected_period = getPeriodInt(periods_text[period]);

    hWin = GUI_CreateDialogBox(_aDialogCreate, GUI_COUNTOF(_aDialogCreate), _cbDialog, WM_HBKWIN, 0, 0);
    return hWin;
}

/*************************** End of file ****************************/
