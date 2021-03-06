#include "ranger.h"

#define ID_WINDOW_0 (GUI_ID_USER + 0x02)
#define ID_BUTTON_SET_SCHEDULE (GUI_ID_USER + 0x05)
#define ID_BUTTON_EDIT (GUI_ID_USER + 0x06)
#define ID_TEXT_HEADER (GUI_ID_USER + 0x08)
#define ID_BUTTON_ALL_DAYS (GUI_ID_USER + 0x09)
#define ID_BUTTON_WEEKEND (GUI_ID_USER + 0x0A)
#define ID_BUTTON_EACH_DAY (GUI_ID_USER + 0x0B)
#define ID_BUTTON_VACATION (GUI_ID_USER + 0x0C)
#define ID_BUTTON_HELP (GUI_ID_USER + 0x0D)
#define ID_BUTTON_RETURN (GUI_ID_USER + 0x0E)
#define ID_TEXT_TITLE (GUI_ID_USER + 0x10)

static const GUI_WIDGET_CREATE_INFO _aDialogCreate[] =
{
    { WINDOW_CreateIndirect, "Window", ID_WINDOW_0, 0, 0, 480, 272, 0, 0x0, 0 },
    { TEXT_CreateIndirect,   "SETTINGS:", ID_TEXT_HEADER, 80, 0, 160, 50, 0, 0x64, 0 },
    { TEXT_CreateIndirect,   "", ID_TEXT_TITLE, 250, 0, 200, 50, 0, 0x64, 0 },
    { BUTTON_CreateIndirect, "All Days", ID_BUTTON_ALL_DAYS, 20, 90, 200, 42, 0, 0x0, 0 },
    { BUTTON_CreateIndirect, "Weekday/Weekend", ID_BUTTON_WEEKEND, 20, 150, 200, 42, 0, 0x0, 0 },
    { BUTTON_CreateIndirect, "Each Day", ID_BUTTON_EACH_DAY, 255, 90, 200, 42, 0, 0x0, 0 },
    { BUTTON_CreateIndirect, "Vacation", ID_BUTTON_VACATION, 255, 150, 200, 42, 0, 0x0, 0 },
    { BUTTON_CreateIndirect, "", ID_BUTTON_RETURN, 15, 0, 100, 50, 0, 0x0, 0 },
    { BUTTON_CreateIndirect, "HELP", ID_BUTTON_HELP, 228, 230, BUT_WIDTH, BUT_HEIGHT, 0, 0x0, 0 },
    { BUTTON_CreateIndirect, "SAVE SCHEDULE", ID_BUTTON_SET_SCHEDULE, 20, 230, 194, BUT_HEIGHT, 0, 0x0, 0 },
    { BUTTON_CreateIndirect, "EDIT", ID_BUTTON_EDIT, 350, 230, BUT_WIDTH, BUT_HEIGHT, 0, 0x0, 0 },
};

static int vacation_border, allDays_border, weekend_border, eachDay_border;

static void schedButton(WM_MESSAGE * pMsg, char *nm, int bor)
{
    switch (pMsg->MsgId)
    {
    case WM_PAINT:
        if (BUTTON_IsPressed(pMsg->hWin))
        {
            drawButton22(nm, 200, 42, bor, 1);
        }
        else
        {
            drawButton22(nm, 200, 42, bor, 0);
        }
        break;
    default:
        BUTTON_Callback(pMsg);
        break;
    }
}
static void vacation_cb(WM_MESSAGE * pMsg)
{
    schedButton(pMsg, "Vacation", (vacation_border == 0) ? 2 : 1);
}

static void allDays_cb(WM_MESSAGE * pMsg)
{
    schedButton(pMsg, "All Days", (allDays_border == 0) ? 2 : 1);
}

static void eachDay_cb(WM_MESSAGE * pMsg)
{
    schedButton(pMsg, "Each Day", (eachDay_border == 0) ? 2 : 1);
}

static void weekend_cb(WM_MESSAGE * pMsg)
{
    schedButton(pMsg, "Weekday/Weekend", (weekend_border == 0) ? 2 : 1);
}

static void invalidateButtons(WM_HWIN hWin)
{
    WM_HWIN hItem;

    hItem = WM_GetDialogItem(hWin, ID_BUTTON_ALL_DAYS);
    WM_InvalidateWindow(hItem);
    WM_SetCallback(hItem, allDays_cb);

    hItem = WM_GetDialogItem(hWin, ID_BUTTON_WEEKEND);
    WM_InvalidateWindow(hItem);
    WM_SetCallback(hItem, weekend_cb);

    hItem = WM_GetDialogItem(hWin, ID_BUTTON_EACH_DAY);
    WM_InvalidateWindow(hItem);
    WM_SetCallback(hItem, eachDay_cb);

    hItem = WM_GetDialogItem(hWin, ID_BUTTON_VACATION);
    WM_InvalidateWindow(hItem);
    WM_SetCallback(hItem, vacation_cb);
}

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
        TEXT_SetFont(hItem, HEADER_FONT);
        TEXT_SetTextAlign(hItem, GUI_TA_RIGHT | GUI_TA_VCENTER);
        TEXT_SetTextColor(hItem, GUI_MAKE_COLOR(0x00FFFFFF));
        TEXT_SetText(hItem, LANG("SETTINGS:"));
        //
        hItem = WM_GetDialogItem(pMsg->hWin, ID_TEXT_TITLE);
        TEXT_SetTextAlign(hItem, GUI_TA_LEFT | GUI_TA_VCENTER);
        TEXT_SetFont(hItem, HEADER_FONT_BOLD);
        TEXT_SetTextColor(hItem, GUI_MAKE_COLOR(0x00FFFFFF));
        TEXT_SetText(hItem, LANG("Schedule"));
        //
        hItem = WM_GetDialogItem(pMsg->hWin, ID_BUTTON_RETURN);
        BUTTON_SetSkin(hItem, returnSkin);
        //
        hItem = WM_GetDialogItem(pMsg->hWin, ID_BUTTON_ALL_DAYS);
        WM_SetCallback(hItem, allDays_cb);
        //
        hItem = WM_GetDialogItem(pMsg->hWin, ID_BUTTON_WEEKEND);
        WM_SetCallback(hItem, weekend_cb);
        //
        hItem = WM_GetDialogItem(pMsg->hWin, ID_BUTTON_EACH_DAY);
        WM_SetCallback(hItem, eachDay_cb);
        //
        hItem = WM_GetDialogItem(pMsg->hWin, ID_BUTTON_VACATION);
        WM_SetCallback(hItem, vacation_cb);
        //
        hItem = WM_GetDialogItem(pMsg->hWin, ID_BUTTON_HELP);
        WM_SetCallback(hItem, buttonOn_cb);

        hItem = WM_GetDialogItem(pMsg->hWin, ID_BUTTON_SET_SCHEDULE);
        WM_SetCallback(hItem, buttonOn_cb);
        //
        hItem = WM_GetDialogItem(pMsg->hWin, ID_BUTTON_EDIT);
        WM_SetCallback(hItem, buttonOn_cb);
        break;
    case WM_NOTIFY_PARENT:
        Id    = WM_GetId(pMsg->hWinSrc);
        NCode = pMsg->Data.v;

        switch(Id)
        {
        case ID_BUTTON_RETURN:
            switch(NCode)
            {
            case WM_NOTIFICATION_RELEASED:
                GUI_Delay(100);
                WM_HideWindow(settingsScheduleWin);
                screenState = SETTINGSWIN;
            }
            break;
        case ID_BUTTON_SET_SCHEDULE:
            switch(NCode)
            {
            case WM_NOTIFICATION_RELEASED:
                strcpy(currentSchedule, tolow(schedulePeriod));
                int i;
                for (i=0; i<5; i++)
                {
                    if (strcmp(schedules[i].label, currentSchedule) == 0)
                    {
                        selectedSchedule = schedules[i];
                        break;
                    }
                }
                break;
            }
            break;
        case ID_BUTTON_EDIT:
            switch(NCode)
            {
            case WM_NOTIFICATION_RELEASED:
                GUI_Delay(100);
                WM_HideWindow(settingsScheduleWin);
                if (vacation_border)
                {
                    strcpy(schedulePeriod,"vacation" );
                    strcpy(scheduleDay,"vacation" );
                }
                else if (weekend_border)
                {
                    strcpy(schedulePeriod,"weekend" );
                    strcpy(scheduleDay,"weekend" );
                }
                else if (eachDay_border)
                {
                    strcpy(scheduleDay,"monday" );
                }
                else
                {
                    strcpy(schedulePeriod,"all days" );
                    strcpy(scheduleDay,"all days" );
                }
                screenState = EDITSCHEDULEWIN;
                break;
            }
            break;
        case ID_BUTTON_ALL_DAYS:
            switch(NCode)
            {
            case WM_NOTIFICATION_CLICKED:
                hItem = WM_GetDialogItem(pMsg->hWin, ID_BUTTON_ALL_DAYS);
                WM_SetCallback(hItem, buttonPush22_cb);
                break;
            case WM_NOTIFICATION_RELEASED:
                strcpy(schedulePeriod, "All Days");
                vacation_border = 0;
                allDays_border = 1;
                eachDay_border = 0;
                weekend_border = 0;
                invalidateButtons(pMsg->hWin);
                break;
            }
            break;
        case ID_BUTTON_WEEKEND:
            switch(NCode)
            {
            case WM_NOTIFICATION_CLICKED:
                hItem = WM_GetDialogItem(pMsg->hWin, ID_BUTTON_WEEKEND);
                WM_SetCallback(hItem, buttonPush22_cb);
                break;
            case WM_NOTIFICATION_RELEASED:
                strcpy(schedulePeriod, "Weekend");
                vacation_border = 0;
                allDays_border = 0;
                eachDay_border = 0;
                weekend_border = 1;
                invalidateButtons(pMsg->hWin);
                break;
            }
            break;
        case ID_BUTTON_EACH_DAY:
            switch(NCode)
            {
            case WM_NOTIFICATION_CLICKED:
                hItem = WM_GetDialogItem(pMsg->hWin, ID_BUTTON_EACH_DAY);
                WM_SetCallback(hItem, buttonPush22_cb);
                break;
            case WM_NOTIFICATION_RELEASED:
                strcpy(schedulePeriod, "Each Day");
                vacation_border = 0;
                allDays_border = 0;
                eachDay_border = 1;
                weekend_border = 0;
                invalidateButtons(pMsg->hWin);
                break;
            }
            break;
        case ID_BUTTON_VACATION:
            switch(NCode)
            {
            case WM_NOTIFICATION_CLICKED:
                hItem = WM_GetDialogItem(pMsg->hWin, ID_BUTTON_VACATION);
                WM_SetCallback(hItem, buttonPush22_cb);
                break;
            case WM_NOTIFICATION_RELEASED:
                strcpy(schedulePeriod, "Vacation");
                vacation_border = 1;
                allDays_border = 0;
                eachDay_border = 0;
                weekend_border = 0;
                invalidateButtons(pMsg->hWin);
                break;
            }
            break;
        case ID_BUTTON_HELP:
            switch(NCode)
            {
            case WM_NOTIFICATION_RELEASED:
                GUI_Delay(100);
                CreateScheduleHelp();
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

WM_HWIN CreateSettingsSchedule(void);
WM_HWIN CreateSettingsSchedule(void)
{
    WM_HWIN hWin;

    vacation_border = 0;
    allDays_border = 0;
    eachDay_border = 0;
    weekend_border = 0;

    strcpy(schedulePeriod, currentSchedule);
    if (strcasecmp(currentSchedule, "all days") == 0 )
    {
        allDays_border = 1;
    }
    else if (strcasecmp(currentSchedule, "each day") == 0)
    {
        eachDay_border = 1;
    }
    else if (strcasecmp(currentSchedule, "weekend") == 0)
    {
        weekend_border = 1;
    }
    else
    {
        vacation_border = 1;
    }

    hWin = GUI_CreateDialogBox(_aDialogCreate, GUI_COUNTOF(_aDialogCreate), _cbDialog, WM_HBKWIN, 0, 0);
    WM_HideWindow(hWin);
    return hWin;
}
