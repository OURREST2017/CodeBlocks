#include "ranger.h"

#define ID_WINDOW_0 (GUI_ID_USER + 0x00)
#define ID_BUTTON_CANCEL (GUI_ID_USER + 0x02)
#define ID_BUTTON_EDIT (GUI_ID_USER + 0x03)

#define ID_TEXT_WAKE (GUI_ID_USER + 0x04)
#define ID_TEXT_WAKE_TIME (GUI_ID_USER + 0x05)
#define ID_TEXT_WAKE_TEMP (GUI_ID_USER + 0x07)

#define ID_TEXT_LEAVE (GUI_ID_USER + 0x08)
#define ID_TEXT_LEAVE_TIME (GUI_ID_USER + 0x09)
#define ID_TEXT_LEAVE_TEMP (GUI_ID_USER + 0x0A)

#define ID_TEXT_RETURN (GUI_ID_USER + 0x0B)
#define ID_TEXT_RETURN_TIME (GUI_ID_USER + 0x0C)
#define ID_TEXT_RETURN_TEMP (GUI_ID_USER + 0x0D)

#define ID_TEXT_SLEEP (GUI_ID_USER + 0x0E)
#define ID_TEXT_SLEEP_TIME (GUI_ID_USER + 0x0F)
#define ID_TEXT_SLEEP_TEMP (GUI_ID_USER + 0xA0)

#define ID_TEXT_MONDAY (GUI_ID_USER + 0xA1)
#define ID_TEXT_TUESDAY (GUI_ID_USER + 0xA2)
#define ID_TEXT_WEDNESDAY (GUI_ID_USER + 0xA3)
#define ID_TEXT_THURSDAY (GUI_ID_USER + 0xA4)
#define ID_TEXT_FRIDAY (GUI_ID_USER + 0xA5)
#define ID_TEXT_SATURDAY (GUI_ID_USER + 0xA6)
#define ID_TEXT_SUNDAY (GUI_ID_USER + 0xA7)

#define ID_BUTTON_SAVE (GUI_ID_USER + 0xD2)

/*********************************************************************
*
*       _aDialogCreate
*/
static const GUI_WIDGET_CREATE_INFO _aDialogCreate[] =
{
    { WINDOW_CreateIndirect, "Window", ID_WINDOW_0, 0, 0, 480, 272, 0, 0x0, 0 },

    { TEXT_CreateIndirect, "M", ID_TEXT_MONDAY, 28, 0, 32, 50, 0, 0x64, 0 },
    { TEXT_CreateIndirect, "T", ID_TEXT_TUESDAY, 80, 0, 32, 50, 0, 0x64, 0 },
    { TEXT_CreateIndirect, "W", ID_TEXT_WEDNESDAY, 133, 0, 50, 50, 0, 0x64, 0 },
    { TEXT_CreateIndirect, "TH", ID_TEXT_THURSDAY, 195, 0, 59, 50, 0, 0x64, 0 },
    { TEXT_CreateIndirect, "F", ID_TEXT_FRIDAY, 269, 0, 42, 50, 0, 0x64, 0 },
    { TEXT_CreateIndirect, "S", ID_TEXT_SATURDAY, 329, 0, 47, 50, 0, 0x64, 0 },
    { TEXT_CreateIndirect, "SU", ID_TEXT_SUNDAY, 390, 0, 71, 50, 0, 0x64, 0 },

    { TEXT_CreateIndirect, "WAKE", ID_TEXT_WAKE, 31, 65, 83, 23, 0, 0x64, 0 },
    { TEXT_CreateIndirect, "TIME", ID_TEXT_WAKE_TIME, 144, 65, 200, 20, 0, 0x64, 0 },
    { TEXT_CreateIndirect, "TEMP", ID_TEXT_WAKE_TEMP, 363, 65, 80, 20, 0, 0x64, 0 },

    { TEXT_CreateIndirect, "LEAVE", ID_TEXT_LEAVE, 31, 105, 83, 23, 0, 0x64, 0 },
    { TEXT_CreateIndirect, "TIME", ID_TEXT_LEAVE_TIME, 144, 105, 200, 20, 0, 0x64, 0 },
    { TEXT_CreateIndirect, "TEMP", ID_TEXT_LEAVE_TEMP, 363, 105, 80, 20, 0, 0x64, 0 },

    { TEXT_CreateIndirect, "RETURN", ID_TEXT_RETURN, 31, 145, 83, 23, 0, 0x64, 0 },
    { TEXT_CreateIndirect, "TIME", ID_TEXT_RETURN_TIME, 144, 145, 200, 20, 0, 0x64, 0 },
    { TEXT_CreateIndirect, "TEMP", ID_TEXT_RETURN_TEMP, 363, 145, 80, 20, 0, 0x64, 0 },

    { TEXT_CreateIndirect, "SLEEP", ID_TEXT_SLEEP, 31, 185, 83, 23, 0, 0x64, 0 },
    { TEXT_CreateIndirect, "TIME", ID_TEXT_SLEEP_TIME, 144, 185, 200, 20, 0, 0x64, 0 },
    { TEXT_CreateIndirect, "TEMP", ID_TEXT_SLEEP_TEMP, 363, 185, 80, 20, 0, 0x64, 0 },

    { BUTTON_CreateIndirect, "DONE", ID_BUTTON_CANCEL, 20, 230, 80, 32, 0, 0x0, 0 },
    { BUTTON_CreateIndirect, "EDIT", ID_BUTTON_EDIT, 375, 230, 80, 32, 0, 0x0, 0 },
};

static int selected_day, upperDegrees, lowerDegrees;

static struct days_s days[7];
static void  setDays(WM_HWIN *, int),  setDays1(WM_HWIN *, int);

static struct days_s selectedDay;
static struct periods_s selectedPeriod;
static struct periods_s periods[7];

static char *periods_text[] = {"wake","leave","return","sleep"};
static char *days_text[] = {"monday","tuesday","wednesday","thursday","friday","saturday","sunday"};

extern GUI_CONST_STORAGE GUI_FONT GUI_FontTahoma33hAA2;
extern GUI_CONST_STORAGE GUI_FONT GUI_FontTahoma33hAA2_B;
extern GUI_CONST_STORAGE GUI_FONT GUI_FontTahoma23hAA2;
extern GUI_CONST_STORAGE GUI_FONT GUI_FontLucidaSans23hAA4B;

static int week_days[] =
{
    ID_TEXT_MONDAY,ID_TEXT_TUESDAY,ID_TEXT_WEDNESDAY,
    ID_TEXT_THURSDAY,ID_TEXT_FRIDAY, ID_TEXT_SATURDAY, ID_TEXT_SUNDAY
};

static void resetFonts(WM_HWIN win, int id)
{
    WM_HWIN txt;
    int i;
    for (i=0; i<7; i++)
    {
        txt = WM_GetDialogItem(win, week_days[i]);
        TEXT_SetFont(txt, &GUI_FontTahoma33hAA2);
    }
    txt = WM_GetDialogItem(win, id);
    TEXT_SetFont(txt, &GUI_FontTahoma33hAA2_B);
}

static struct periods_s getPeriod(char * d)
{
    int sz1 = sizeof(periods) / sizeof(periods[0]);
    int i;
    for (i=0; i<sz1; i++)
    {
        if (strcmp(selectedDay.periods[i].label, d) == 0)
        {
            return selectedDay.periods[i];
            break;
        }
    }

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

static void getPeriods()
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

static char * getTimes(int st, int et, int m)
{
    static char buf[30];
    if (m)
    {
        sprintf(buf, "%02d:%02d - %02d:%02d",  st/60, st - (st/60)*60, et/60, et - (et/60)*60);
    }
    else
    {
        int sh = st/60;
        if (sh > 12) sh -= 12;
        int eh = et/60;
        if (eh > 12) eh -= 12;
        sprintf(buf, "%d:%02d%s - %d:%02d%s",
                sh, st - (st/60)*60, ((st/60 < 12) ? "am" : "pm"),
                eh, et - et/60*60, ((et/60 < 12) ? "am" : "pm"));
    }
    return buf;
}
/*********************************************************************
*
*       _cbDialog
*/
static void _cbDialog(WM_MESSAGE * pMsg)
{
    WM_HWIN hItem, spinWheel;
    int     NCode;
    int     Id;
    char buf[30];
    int xSize = 28;
    int ySize = 36;
    int lh = 20;

    switch (pMsg->MsgId)
    {
    case WM_PAINT:
        GUI_DrawGradientV(0, 0, 480, 50, color_map[0].stop, color_map[0].start);
        GUI_DrawBitmap(&bmwatermark,45,52);
        GUI_SetColor(0xcecece);
        GUI_DrawHLine(92, 0, 479);
        GUI_DrawHLine(132, 0, 479);
        GUI_DrawHLine(172, 0, 479);
        break;
    case WM_INIT_DIALOG:
        hItem = WM_GetDialogItem(pMsg->hWin, ID_TEXT_MONDAY);
        TEXT_SetTextAlign(hItem, GUI_TA_HCENTER | GUI_TA_VCENTER);
        TEXT_SetTextColor(hItem, GUI_MAKE_COLOR(0x00FFFFFF));
        if (selected_day == 0)
        {
            TEXT_SetFont(hItem, &GUI_FontTahoma33hAA2_B);
        }
        else
        {
            TEXT_SetFont(hItem, &GUI_FontTahoma33hAA2);
        }
        //
        hItem = WM_GetDialogItem(pMsg->hWin, ID_TEXT_TUESDAY);
        TEXT_SetTextAlign(hItem, GUI_TA_HCENTER | GUI_TA_VCENTER);
        if (selected_day == 1)
        {
            TEXT_SetFont(hItem, &GUI_FontTahoma33hAA2_B);
        }
        else
        {
            TEXT_SetFont(hItem, &GUI_FontTahoma33hAA2);
        }
        TEXT_SetTextColor(hItem, GUI_MAKE_COLOR(0x00FFFFFF));
        //
        hItem = WM_GetDialogItem(pMsg->hWin, ID_TEXT_WEDNESDAY);
        if (selected_day == 2)
        {
            TEXT_SetFont(hItem, &GUI_FontTahoma33hAA2_B);
        }
        else
        {
            TEXT_SetFont(hItem, &GUI_FontTahoma33hAA2);
        }
        TEXT_SetTextAlign(hItem, GUI_TA_HCENTER | GUI_TA_VCENTER);
        TEXT_SetTextColor(hItem, GUI_MAKE_COLOR(0x00FFFFFF));
        //
        hItem = WM_GetDialogItem(pMsg->hWin, ID_TEXT_THURSDAY);
        if (selected_day == 3)
        {
            TEXT_SetFont(hItem, &GUI_FontTahoma33hAA2_B);
        }
        else
        {
            TEXT_SetFont(hItem, &GUI_FontTahoma33hAA2);
        }
        TEXT_SetTextAlign(hItem, GUI_TA_HCENTER | GUI_TA_VCENTER);
        TEXT_SetTextColor(hItem, GUI_MAKE_COLOR(0x00FFFFFF));
        //
        hItem = WM_GetDialogItem(pMsg->hWin, ID_TEXT_FRIDAY);
        if (selected_day == 4)
        {
            TEXT_SetFont(hItem, &GUI_FontTahoma33hAA2_B);
        }
        else
        {
            TEXT_SetFont(hItem, &GUI_FontTahoma33hAA2);
        }
        TEXT_SetTextAlign(hItem, GUI_TA_HCENTER | GUI_TA_VCENTER);
        TEXT_SetTextColor(hItem, GUI_MAKE_COLOR(0x00FFFFFF));
        //
        hItem = WM_GetDialogItem(pMsg->hWin, ID_TEXT_SATURDAY);
        if (selected_day == 5)
        {
            TEXT_SetFont(hItem, &GUI_FontTahoma33hAA2_B);
        }
        else
        {
            TEXT_SetFont(hItem, &GUI_FontTahoma33hAA2);
        }
        TEXT_SetTextAlign(hItem, GUI_TA_HCENTER | GUI_TA_VCENTER);
        TEXT_SetTextColor(hItem, GUI_MAKE_COLOR(0x00FFFFFF));
        //
        hItem = WM_GetDialogItem(pMsg->hWin, ID_TEXT_SUNDAY);
        TEXT_SetTextAlign(hItem, GUI_TA_HCENTER | GUI_TA_VCENTER);
        if (selected_day == 6)
        {
            TEXT_SetFont(hItem, &GUI_FontTahoma33hAA2_B);
        }
        else
        {
            TEXT_SetFont(hItem, &GUI_FontTahoma33hAA2);
        }
        TEXT_SetTextColor(hItem, GUI_MAKE_COLOR(0x00FFFFFF));
        //
        hItem = WM_GetDialogItem(pMsg->hWin, ID_TEXT_WAKE);
        TEXT_SetFont(hItem, &GUI_FontTahoma23hAA2);
        TEXT_SetTextAlign(hItem, GUI_TA_LEFT);
        TEXT_SetTextColor(hItem, GUI_MAKE_COLOR(0x00808080));
        TEXT_SetText(hItem, toup(getPeriod(periods_text[0]).label));

        hItem = WM_GetDialogItem(pMsg->hWin, ID_TEXT_WAKE_TIME);
        TEXT_SetTextAlign(hItem, GUI_TA_HCENTER | GUI_TA_VCENTER);
        TEXT_SetFont(hItem, &GUI_FontTahoma23hAA2);
        TEXT_SetTextColor(hItem, GUI_MAKE_COLOR(0x00808080));
        //
        hItem = WM_GetDialogItem(pMsg->hWin, ID_TEXT_WAKE_TEMP);
        TEXT_SetFont(hItem, &GUI_FontTahoma23hAA2);
        TEXT_SetTextAlign(hItem, GUI_TA_HCENTER | GUI_TA_VCENTER);
        TEXT_SetTextColor(hItem, GUI_MAKE_COLOR(0x00808080));
        //
        hItem = WM_GetDialogItem(pMsg->hWin, ID_TEXT_LEAVE);
        TEXT_SetFont(hItem, &GUI_FontTahoma23hAA2);
        TEXT_SetTextAlign(hItem, GUI_TA_LEFT);
        TEXT_SetTextColor(hItem, GUI_MAKE_COLOR(0x00808080));
        //
        hItem = WM_GetDialogItem(pMsg->hWin, ID_TEXT_LEAVE_TIME);
        TEXT_SetTextAlign(hItem, GUI_TA_HCENTER | GUI_TA_VCENTER);
        TEXT_SetFont(hItem, &GUI_FontTahoma23hAA2);
        TEXT_SetTextColor(hItem, GUI_MAKE_COLOR(0x00808080));
        //
        hItem = WM_GetDialogItem(pMsg->hWin, ID_TEXT_LEAVE_TEMP);
        TEXT_SetFont(hItem, &GUI_FontTahoma23hAA2);
        TEXT_SetTextAlign(hItem, GUI_TA_HCENTER | GUI_TA_VCENTER);
        TEXT_SetTextColor(hItem, GUI_MAKE_COLOR(0x00808080));
        //
        hItem = WM_GetDialogItem(pMsg->hWin, ID_TEXT_RETURN);
        TEXT_SetFont(hItem, &GUI_FontTahoma23hAA2);
        TEXT_SetTextAlign(hItem, GUI_TA_LEFT);
        TEXT_SetTextColor(hItem, GUI_MAKE_COLOR(0x00808080));
        //
        hItem = WM_GetDialogItem(pMsg->hWin, ID_TEXT_RETURN_TIME);
        TEXT_SetTextAlign(hItem, GUI_TA_HCENTER | GUI_TA_VCENTER);
        TEXT_SetFont(hItem, &GUI_FontTahoma23hAA2);
        TEXT_SetTextColor(hItem, GUI_MAKE_COLOR(0x00808080));
        //
        hItem = WM_GetDialogItem(pMsg->hWin, ID_TEXT_RETURN_TEMP);
        TEXT_SetFont(hItem, &GUI_FontTahoma23hAA2);
        TEXT_SetTextAlign(hItem, GUI_TA_HCENTER | GUI_TA_VCENTER);
        TEXT_SetTextColor(hItem, GUI_MAKE_COLOR(0x00808080));
        //
        hItem = WM_GetDialogItem(pMsg->hWin, ID_TEXT_SLEEP);
        TEXT_SetFont(hItem, &GUI_FontTahoma23hAA2);
        TEXT_SetTextAlign(hItem, GUI_TA_LEFT);
        TEXT_SetTextColor(hItem, GUI_MAKE_COLOR(0x00808080));
        //
        hItem = WM_GetDialogItem(pMsg->hWin, ID_TEXT_SLEEP_TIME);
        TEXT_SetTextAlign(hItem, GUI_TA_HCENTER | GUI_TA_VCENTER);
        TEXT_SetFont(hItem, &GUI_FontTahoma23hAA2);
        TEXT_SetTextColor(hItem, GUI_MAKE_COLOR(0x00808080));
        //
        hItem = WM_GetDialogItem(pMsg->hWin, ID_TEXT_SLEEP_TEMP);
        TEXT_SetFont(hItem, &GUI_FontTahoma23hAA2);
        TEXT_SetTextAlign(hItem, GUI_TA_HCENTER | GUI_TA_VCENTER);
        TEXT_SetTextColor(hItem, GUI_MAKE_COLOR(0x00808080));
        //
        setDays(pMsg->hWin, selected_day);
        //
        hItem = WM_GetDialogItem(pMsg->hWin, ID_BUTTON_CANCEL);
        WM_SetCallback(hItem, buttonOn16_cb);
        //
        hItem = WM_GetDialogItem(pMsg->hWin, ID_BUTTON_EDIT);
        WM_SetCallback(hItem, buttonOn16_cb);

        break;
    case WM_NOTIFY_PARENT:
        Id    = WM_GetId(pMsg->hWinSrc);
        NCode = pMsg->Data.v;

        switch(Id)
        {
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
        case ID_BUTTON_EDIT:
            switch(NCode)
            {
            case WM_NOTIFICATION_RELEASED:
                GUI_Delay(100);
                CreateEditSchedule("each day", days_text[selected_day]);
                break;
            }
            break;
        case ID_BUTTON_SAVE:
            switch(NCode)
            {
            case WM_NOTIFICATION_RELEASED:
                GUI_Delay(100);
                CreateSettingsSchedule();
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

static void setDays(WM_HWIN *hWin, int d)
{
    char buf [20];
    WM_HWIN  hItem;

    selectedDay = getDay(days_text[d]);

    hItem = WM_GetDialogItem(hWin, ID_TEXT_WAKE);
    TEXT_SetText(hItem, toup(getPeriod(periods_text[0]).label));

    hItem = WM_GetDialogItem(hWin, ID_TEXT_WAKE_TIME);
    TEXT_SetText(hItem,getTimes(getPeriod(periods_text[0]).startMinutes,
                                getPeriod(periods_text[0]).stopMinutes, metric));

    hItem = WM_GetDialogItem(hWin, ID_TEXT_WAKE_TEMP);
    sprintf(buf,"%d°", getPeriod(periods_text[0]).tempurature);
    TEXT_SetText(hItem, buf);


    hItem = WM_GetDialogItem(hWin, ID_TEXT_LEAVE);
    TEXT_SetText(hItem, toup(getPeriod(periods_text[1]).label));

    hItem = WM_GetDialogItem(hWin, ID_TEXT_LEAVE_TIME);
    TEXT_SetText(hItem,getTimes(getPeriod(periods_text[1]).startMinutes,
                                getPeriod(periods_text[1]).stopMinutes, metric));

    hItem = WM_GetDialogItem(hWin, ID_TEXT_LEAVE_TEMP);
    sprintf(buf,"%d°", getPeriod(periods_text[1]).tempurature);
    TEXT_SetText(hItem, buf);


    hItem = WM_GetDialogItem(hWin, ID_TEXT_RETURN);
    TEXT_SetText(hItem, toup(getPeriod(periods_text[2]).label));

    hItem = WM_GetDialogItem(hWin, ID_TEXT_RETURN_TIME);
    TEXT_SetText(hItem,getTimes(getPeriod(periods_text[2]).startMinutes,
                                getPeriod(periods_text[2]).stopMinutes, metric));

    hItem = WM_GetDialogItem(hWin, ID_TEXT_RETURN_TEMP);
    sprintf(buf,"%d°", getPeriod(periods_text[2]).tempurature);
    TEXT_SetText(hItem, buf);


    hItem = WM_GetDialogItem(hWin, ID_TEXT_SLEEP);
    TEXT_SetText(hItem, toup(getPeriod(periods_text[3]).label));

    hItem = WM_GetDialogItem(hWin, ID_TEXT_SLEEP_TIME);
    TEXT_SetText(hItem,getTimes(getPeriod(periods_text[3]).startMinutes,
                                getPeriod(periods_text[3]).stopMinutes, metric));

    hItem = WM_GetDialogItem(hWin, ID_TEXT_SLEEP_TEMP);
    sprintf(buf,"%d°", getPeriod(periods_text[3]).tempurature);
    TEXT_SetText(hItem, buf);
}
/*********************************************************************
*
*       CreateWindow
*/
WM_HWIN CreateEachDay(char *day);
WM_HWIN CreateEachDay(char *day)
{
    WM_HWIN hWin;

    getPeriods();
    selectedDay = getDay(day);

    hWin = GUI_CreateDialogBox(_aDialogCreate, GUI_COUNTOF(_aDialogCreate), _cbDialog, WM_HBKWIN, 0, 0);
    return hWin;
}

/*************************** End of file ****************************/
