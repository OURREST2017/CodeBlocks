#include "ranger.h"

#define ID_WINDOW_0  (GUI_ID_USER + 0x00)
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
#define ID_TEXT_0  (GUI_ID_USER + 0x1D)
#define ID_TEXT_1  (GUI_ID_USER + 0x1E)
#define ID_TEXT_2  (GUI_ID_USER + 0x1F)
#define ID_TEXT_3  (GUI_ID_USER + 0x20)
#define ID_TEXT_4  (GUI_ID_USER + 0x21)
#define ID_TEXT_5  (GUI_ID_USER + 0x22)

/*********************************************************************
*
*       _aDialogCreate
*/
static const GUI_WIDGET_CREATE_INFO _aDialogCreate[] =
{
    { WINDOW_CreateIndirect, "Window", ID_WINDOW_0, 0, 0, 480, 272, 0, 0x0, 0 },
    { TEXT_CreateIndirect, "TIME/DATE", ID_TEXT_HEADER, 0, 0, 480, 50, 0, 0x64, 0 },
    { BUTTON_CreateIndirect, "Button", ID_BUTTON_HOUR_UP, 109, 70, 40, 40, 0, 0x0, 0 },
    { BUTTON_CreateIndirect, "Button", ID_BUTTON_HOUR_DN, 109, 104, 40, 40, 0, 0x0, 0 },
    { BUTTON_CreateIndirect, "Button", ID_BUTTON_MONTH_UP, 110, 150, 40, 40, 0, 0x0, 0 },
    { BUTTON_CreateIndirect, "Button", ID_BUTTON_MONTH_DN, 110, 184, 40, 40, 0, 0x0, 0 },
    { BUTTON_CreateIndirect, "Button", ID_BUTTON_MINUTE_UP, 248, 70, 40, 40, 0, 0x0, 0 },
    { BUTTON_CreateIndirect, "Button", ID_BUTTON_MINUTE_DN, 248, 104, 40, 40, 0, 0x0, 0 },
    { BUTTON_CreateIndirect, "Button", ID_BUTTON_DAY_UP, 248, 150, 40, 40, 0, 0x0, 0 },
    { BUTTON_CreateIndirect, "Button", ID_BUTTON_DAY_DN, 248, 184, 40, 40, 0, 0x0, 0 },
    { BUTTON_CreateIndirect, "Button", ID_BUTTON_AMPM_UP, 423, 70, 40, 40, 0, 0x0, 0 },
    { BUTTON_CreateIndirect, "Button", ID_BUTTON_AMPM_DN, 423, 104, 40, 40, 0, 0x0, 0 },
    { BUTTON_CreateIndirect, "Button", ID_BUTTON__YEAR_UP, 423, 150, 40, 40, 0, 0x0, 0 },
    { BUTTON_CreateIndirect, "Button", ID_BUTTON_YEAR_DN, 423, 184, 40, 40, 0, 0x0, 0 },
    { BUTTON_CreateIndirect, "CANCEL", ID_BUTTON_CANCEL, 20, 230, 80, 30, 0, 0x0, 0 },
    { BUTTON_CreateIndirect, "SAVE", ID_BUTTON_SAVE, 380, 230, 80, 30, 0, 0x0, 0 },
    { TEXT_CreateIndirect, "Edit", ID_EDIT_HOUR, 40, 80, 65, 50, 0, 0x64, 0 },
    { TEXT_CreateIndirect, "Edit", ID_EDIT_MONTH, 22, 160, 83, 50, 0, 0x64, 0 },
    { TEXT_CreateIndirect, "Edit", ID_EDIT_MINUTE, 178, 80, 65, 50, 0, 0x64, 0 },
    { TEXT_CreateIndirect, "Edit", ID_EDIT_DAY, 175, 160, 65, 50, 0, 0x64, 0 },
    { TEXT_CreateIndirect, "Edit", ID_EDIT_AMPM, 350, 80, 65, 50, 0, 0x64, 0 },
    { TEXT_CreateIndirect, "Edit", ID_EDIT_YEAR, 315, 160, 100, 50, 0, 0x64, 0 },
    { TEXT_CreateIndirect, "Text", ID_TEXT_0, 43, 58, 59, 20, 0, 0x64, 0 },
    { TEXT_CreateIndirect, "Text", ID_TEXT_1, 172, 58, 84, 20, 0, 0x64, 0 },
    { TEXT_CreateIndirect, "Text", ID_TEXT_2, 340, 58, 87, 20, 0, 0x64, 0 },
    { TEXT_CreateIndirect, "Text", ID_TEXT_3, 26, 139, 80, 20, 0, 0x64, 0 },
    { TEXT_CreateIndirect, "Text", ID_TEXT_4, 172, 139, 74, 20, 0, 0x64, 0 },
    { TEXT_CreateIndirect, "Text", ID_TEXT_5, 320, 139, 80, 20, 0, 0x64, 0 },
};
extern void up_button(WM_MESSAGE *);
extern void dn_button(WM_MESSAGE *);
extern GUI_CONST_STORAGE GUI_BITMAP bmdtup;
extern GUI_CONST_STORAGE GUI_BITMAP bmdtdn;
extern GUI_CONST_STORAGE GUI_FONT GUI_FontTahoma33hAA2_B;

static char *Months[] = {"JAN","FEB","MAR","APR","MAY","JUN","JUL","AUG","SEP","OCT","NOV","DEC"};
static int days[12] = {30,28,30,30,30,30,30,30,30,30,30,30};
static GUI_TIMER_HANDLE but_timer;

void up_button(WM_MESSAGE * pMsg)
{
    switch (pMsg->MsgId)
    {
    case WM_PAINT:
        if (BUTTON_IsPressed(pMsg->hWin))
        {
            GUI_DrawBitmap(&bmdtup, 0, 0);
        }
        else
        {
            GUI_DrawBitmap(&bmdtup, 0, 0);
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
            GUI_DrawBitmap(&bmdtdn, 0, 0);
        }
        else
        {
            GUI_DrawBitmap(&bmdtdn, 0, 0);
        }
        break;
    default:
        BUTTON_Callback(pMsg);
        break;
    }
}
WM_HWIN hour_text, minute_text, ampm_text, month_text, day_text, year_text;
int but_id, but_delay, but_started;

static void dateChanger()
{
    if (!but_started)
    {
        GUI_TIMER_SetPeriod(but_timer, 0);
        GUI_TIMER_Restart(but_timer);
        but_started = 1;
    }
}

static void dateTimer(GUI_TIMER_MESSAGE * pTM)
{
    if (but_id == -1) return;
    char buf[10];
    switch(but_id)
    {
    case 0:
        current_hour++;
        if (current_hour == 13) current_hour = 1;
        sprintf(buf, "%d", current_hour);
        TEXT_SetText(hour_text, buf);
        break;
    case 1:
        current_hour--;
        if (current_hour == 0) current_hour = 12;
        sprintf(buf, "%d", current_hour);
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
        TEXT_SetText(ampm_text, current_ampm ? "AM" : "PM");
        break;
    case 5:
        current_ampm = !current_ampm;
        TEXT_SetText(ampm_text, current_ampm ? "AM" : "PM");
        break;
    case 6:
        current_month++;
        if (current_month == 12) current_month = 0;
        TEXT_SetText(month_text, Months[current_month]);
        break;
    case 7:
        current_month--;
        if (current_month == -1) current_month = 11;
        TEXT_SetText(month_text, Months[current_month]);
        break;
    case 8:
        current_day++;
        if (current_day == 32) current_day = 1;
        sprintf(buf, "%d", current_day);
        TEXT_SetText(day_text, buf);
        break;
    case 9:
        current_day--;
        if (current_day == 0) current_day = 31;
        sprintf(buf, "%d", current_day);
        TEXT_SetText(day_text, buf);
        break;
    case 10:
        current_year++;
        if (current_year == 2050) current_year = 2016;
        sprintf(buf, "%d", current_year);
        TEXT_SetText(year_text, buf);
        break;
    case 11:
        current_year--;
        if (current_year == 2016) current_year = 2050;
        sprintf(buf, "%d", current_year);
        TEXT_SetText(year_text, buf);
        break;
    default:
        break;
    }

    GUI_TIMER_SetPeriod(but_timer, 300);
    GUI_TIMER_Restart(but_timer);
}

static void text_box_cb(WM_MESSAGE * pMsg)
{
    char buf[50], nm[50];
    GUI_RECT rt;
    WM_GetClientRect(&rt);
    switch (pMsg->MsgId)
    {
    case WM_PAINT:
        GUI_SetColor(0xeaeaea);
        GUI_AA_FillRoundedRect(0,0,rt.x1,rt.y1,10);
        GUI_SetColor(0x808080);
        GUI_SetPenSize(2);
        GUI_AA_DrawRoundedRect(0,0,rt.x1,rt.y1,10);
        TEXT_GetText(pMsg->hWin, buf, 10);

        GUI_SetColor(GUI_BLACK);
        GUI_SetTextMode(GUI_TEXTMODE_TRANS);
        GUI_SetFont(&GUI_FontTahoma33hAA2_B);
        GUI_DispStringInRect(buf, &rt, GUI_TA_HCENTER | GUI_TA_VCENTER);
        break;
    default:
        TEXT_Callback(pMsg);
        break;
    }
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
        GUI_DrawGradientV(0, 0, 480, 50, color_map[0].stop, color_map[0].start);
        GUI_DrawBitmap(&bmwatermark,45,52);
        break;
    case WM_INIT_DIALOG:
        hItem = WM_GetDialogItem(pMsg->hWin, ID_TEXT_HEADER);
        TEXT_SetFont(hItem, HEADER_FONT_BOLD);
        TEXT_SetTextAlign(hItem, GUI_TA_HCENTER | GUI_TA_VCENTER);
        TEXT_SetTextColor(hItem, GUI_MAKE_COLOR(0x00FFFFFF));

        hItem = WM_GetDialogItem(pMsg->hWin, ID_BUTTON_HOUR_UP);
        WM_SetCallback(hItem, up_button);
        //
        hItem = WM_GetDialogItem(pMsg->hWin, ID_BUTTON_HOUR_DN);
        WM_SetCallback(hItem, dn_button);
        //
        hItem = WM_GetDialogItem(pMsg->hWin, ID_BUTTON_MONTH_UP);
        WM_SetCallback(hItem, up_button);;
        //
        hItem = WM_GetDialogItem(pMsg->hWin, ID_BUTTON_MONTH_DN);
        WM_SetCallback(hItem, dn_button);
        //
        hItem = WM_GetDialogItem(pMsg->hWin, ID_BUTTON_MINUTE_UP);
        WM_SetCallback(hItem, up_button);
        //
        hItem = WM_GetDialogItem(pMsg->hWin, ID_BUTTON_MINUTE_DN);
        WM_SetCallback(hItem, dn_button);
        //
        hItem = WM_GetDialogItem(pMsg->hWin, ID_BUTTON_DAY_UP);
        WM_SetCallback(hItem, up_button);
        //
        hItem = WM_GetDialogItem(pMsg->hWin, ID_BUTTON_DAY_DN);
        WM_SetCallback(hItem, dn_button);
        //
        hItem = WM_GetDialogItem(pMsg->hWin, ID_BUTTON_AMPM_UP);
        WM_SetCallback(hItem, up_button);
        //
        hItem = WM_GetDialogItem(pMsg->hWin, ID_BUTTON_AMPM_DN);
        WM_SetCallback(hItem, dn_button);
        //
        hItem = WM_GetDialogItem(pMsg->hWin, ID_BUTTON__YEAR_UP);
        WM_SetCallback(hItem, up_button);
        //
        hItem = WM_GetDialogItem(pMsg->hWin, ID_BUTTON_YEAR_DN);
        WM_SetCallback(hItem, dn_button);
        //
        hItem = WM_GetDialogItem(pMsg->hWin, ID_BUTTON_CANCEL);
        WM_SetCallback(hItem, buttonOn16_cb);
        //
        hItem = WM_GetDialogItem(pMsg->hWin, ID_BUTTON_SAVE);
        WM_SetCallback(hItem, buttonOn16_cb);
        //
        sprintf(buf, "%d", current_hour);
        hour_text = WM_GetDialogItem(pMsg->hWin, ID_EDIT_HOUR);
        TEXT_SetText(hour_text, buf);
        WM_SetCallback(hour_text, text_box_cb);
        //
        sprintf(buf, "%02d", current_minute);
        minute_text = WM_GetDialogItem(pMsg->hWin, ID_EDIT_MINUTE);
        TEXT_SetText(minute_text, buf);
        WM_SetCallback(minute_text, text_box_cb);
        //
        month_text = WM_GetDialogItem(pMsg->hWin, ID_EDIT_MONTH);
        TEXT_SetText(month_text, Months[current_month]);
        WM_SetCallback(month_text, text_box_cb);
        //
        sprintf(buf, "%d", current_day);
        day_text = WM_GetDialogItem(pMsg->hWin, ID_EDIT_DAY);
        TEXT_SetText(day_text, buf);
        WM_SetCallback(day_text, text_box_cb);
        //
        ampm_text = WM_GetDialogItem(pMsg->hWin, ID_EDIT_AMPM);
        TEXT_SetText(ampm_text, current_ampm ? "AM" : "PM");
        WM_SetCallback(ampm_text, text_box_cb);
        //
        sprintf(buf, "%d", current_year);
        year_text = WM_GetDialogItem(pMsg->hWin, ID_EDIT_YEAR);
        TEXT_SetText(year_text, buf);
        WM_SetCallback(year_text, text_box_cb);
        //
        hItem = WM_GetDialogItem(pMsg->hWin, ID_TEXT_0);
        TEXT_SetTextAlign(hItem, GUI_TA_HCENTER | GUI_TA_VCENTER);
        TEXT_SetText(hItem, "Hour");
        TEXT_SetFont(hItem, GUI_FONT_20_1);
        TEXT_SetTextColor(hItem, GUI_MAKE_COLOR(0x00808080));
        //
        hItem = WM_GetDialogItem(pMsg->hWin, ID_TEXT_1);
        TEXT_SetTextAlign(hItem, GUI_TA_HCENTER | GUI_TA_VCENTER);
        TEXT_SetFont(hItem, GUI_FONT_20_1);
        TEXT_SetText(hItem, "Minute");
        TEXT_SetTextColor(hItem, GUI_MAKE_COLOR(0x00808080));
        //
        hItem = WM_GetDialogItem(pMsg->hWin, ID_TEXT_2);
        TEXT_SetFont(hItem, GUI_FONT_20_1);
        TEXT_SetTextAlign(hItem, GUI_TA_HCENTER | GUI_TA_VCENTER);
        TEXT_SetText(hItem, "AM/PM");
        TEXT_SetTextColor(hItem, GUI_MAKE_COLOR(0x00808080));
        //
        hItem = WM_GetDialogItem(pMsg->hWin, ID_TEXT_3);
        TEXT_SetFont(hItem, GUI_FONT_20_1);
        TEXT_SetTextAlign(hItem, GUI_TA_HCENTER | GUI_TA_VCENTER);
        TEXT_SetText(hItem, "Month");
        TEXT_SetTextColor(hItem, GUI_MAKE_COLOR(0x00808080));
        //
        hItem = WM_GetDialogItem(pMsg->hWin, ID_TEXT_4);
        TEXT_SetFont(hItem, GUI_FONT_20_1);
        TEXT_SetTextAlign(hItem, GUI_TA_HCENTER | GUI_TA_VCENTER);
        TEXT_SetText(hItem, "Day");
        TEXT_SetTextColor(hItem, GUI_MAKE_COLOR(0x00808080));
        //
        hItem = WM_GetDialogItem(pMsg->hWin, ID_TEXT_5);
        TEXT_SetFont(hItem, GUI_FONT_20_1);
        TEXT_SetTextAlign(hItem, GUI_TA_HCENTER | GUI_TA_VCENTER);
        TEXT_SetText(hItem, "Year");
        TEXT_SetTextColor(hItem, GUI_MAKE_COLOR(0x00808080));
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
                but_started = 0;
                but_id = -1;
                //dateChanger();
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
                CreateSettings();
                break;
            }
            break;
        case ID_BUTTON_SAVE:
            switch(NCode)
            {
            case WM_NOTIFICATION_RELEASED:
                GUI_Delay(100);
                CreateSettings();
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

/*********************************************************************
*
*       CreateWindow
*/
WM_HWIN CreateDateTime(void);
WM_HWIN CreateDateTime(void)
{
    WM_HWIN hWin;

    but_delay = 300;

    but_id = -1;
    but_started = 0;
    but_timer = GUI_TIMER_Create(dateTimer, 0, 0, 0);

    hWin = GUI_CreateDialogBox(_aDialogCreate, GUI_COUNTOF(_aDialogCreate), _cbDialog, WM_HBKWIN, 0, 0);
    return hWin;
}


/*************************** End of file ****************************/
