#include "ranger.h"

#define ID_WINDOW_0  (GUI_ID_USER + 0x00)
#define ID_TEXT_HEADER (GUI_ID_USER + 0x02)
#define ID_BUTTON_CANCEL  (GUI_ID_USER + 0x14)
#define ID_BUTTON_SAVE  (GUI_ID_USER + 0x15)
#define ID_TEXT_0  (GUI_ID_USER + 0x1D)
#define ID_TEXT_1  (GUI_ID_USER + 0x1E)
#define GUI_ID_LISTWHEEL0  (GUI_ID_USER + 0x1F)
#define GUI_ID_LISTWHEEL1  (GUI_ID_USER + 0x20)
#define GUI_ID_LISTWHEEL2  (GUI_ID_USER + 0x21)
#define GUI_ID_LISTWHEEL3  (GUI_ID_USER + 0x22)
#define GUI_ID_LISTWHEEL4  (GUI_ID_USER + 0x23)
#define GUI_ID_LISTWHEEL5  (GUI_ID_USER + 0x24)

/********************************************************************
*
*       _aDialogCreate
*/
static const GUI_WIDGET_CREATE_INFO _aDialogCreate[] =
{
    { WINDOW_CreateIndirect, "Window", ID_WINDOW_0, 0, 0, 480, 272, 0, 0x0, 0 },
    { TEXT_CreateIndirect, "TIME/DATE", ID_TEXT_HEADER, 0, 0, 480, 50, 0, 0x64, 0 },
    { TEXT_CreateIndirect, "Text", ID_TEXT_0, 24, 65, 165, 20, 0, 0x64, 0 },
    { TEXT_CreateIndirect, "Text", ID_TEXT_1, 216, 65, 280, 20, 0, 0x64, 0 },
    { BUTTON_CreateIndirect, "CANCEL", ID_BUTTON_CANCEL, 20, 230, 80, BUTHEIGHT, 0, 0x0, 0 },
    { BUTTON_CreateIndirect, "SAVE", ID_BUTTON_SAVE, 380, 230, 80, BUTHEIGHT, 0, 0x0, 0 },
};

static char * years[] =
{
    "2010", "2011", "2012", "2013", "2014", "2015", "2016", "2017", "2018", "2019", "2020"
};

static char * months[] =
{
    "Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul",
    "Aug", "Sep", "Oct", "Nov", "Dec"
};

static char * days[] =
{
    "01", "02", "03", "04", "05", "06", "07", "08", "09", "10",
    "11", "12", "13", "14", "15", "16", "17", "18", "19", "20",
    "21", "22", "23", "24", "25", "26", "27", "28", "29", "30", "31"
};

static char *hours24[] =
{
    "00", "01", "02", "03", "04", "05", "06", "07", "08", "09", "10", "11", "12",
    "13", "14", "15", "16", "17", "18", "19", "20", "21", "22", "23"
};

static char *hours12[] =
{
    "01", "02", "03", "04", "05", "06", "07", "08", "09", "10", "11", "12"
};

static char * minutes[] =
{
    "00", "01", "02", "03", "04", "05", "06", "07", "08", "09", "10",
    "11", "12", "13", "14", "15", "16", "17", "18", "19", "20",
    "21", "22", "23", "24", "25", "26", "27", "28", "29", "30",
    "31", "32", "33", "34", "35", "36", "37", "38", "39", "40",
    "41", "42", "43", "44", "45", "46", "47", "48", "49", "50",
    "51", "52", "53", "54", "55", "56", "57", "58", "59"
};

static char * ampm[] =
{
    "AM", "PM"
};

static WHEEL _aWheel[6];

extern int CreateListWheel(int, int, int, int, int, char **, int, int, int,
                           WM_HWIN, WHEEL *, GUI_FONT *, int);

static void _cbBkWheel(WM_MESSAGE * pMsg)
{
    WM_HWIN hParent;
    int     xSize;
    int     ySize;

    switch (pMsg->MsgId)
    {
    case WM_NOTIFY_PARENT:
        hParent    = WM_GetParent(pMsg->hWin);
        pMsg->hWin = hParent;
        WM_SendMessage(hParent, pMsg);
        break;
    case WM_PAINT:
        xSize = WM_GetWindowSizeX(pMsg->hWin);
        ySize = WM_GetWindowSizeY(pMsg->hWin);
        GUI_DrawGradientV(0, 0, xSize - 1, ySize - 1, GUI_WHITE, GUI_WHITE);
        break;
    default:
        WM_DefaultProc(pMsg);
    }
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
    int ch = 60;
    int h = 120;

    switch (pMsg->MsgId)
    {
    case WM_PAINT:
        GUI_DrawGradientV(0, 0, 480, 50, color_map[0].stop, color_map[0].start);
        GUI_DrawBitmap(&bmwatermark,45,52);
        break;
    case WM_INIT_DIALOG:
        hItem = WM_GetDialogItem(pMsg->hWin, ID_TEXT_HEADER);
        TEXT_SetFont(hItem, &GUI_Font32B_ASCII);
        TEXT_SetTextAlign(hItem, GUI_TA_HCENTER | GUI_TA_VCENTER);
        TEXT_SetTextColor(hItem, GUI_MAKE_COLOR(0x00FFFFFF));

        hItem = WM_GetDialogItem(pMsg->hWin, ID_TEXT_0);
        TEXT_SetFont(hItem, &GUI_FontRounded22);
        TEXT_SetText(hItem, "Hour   Min");
        TEXT_SetTextColor(hItem, GUI_MAKE_COLOR(0x00808080));
        //
        hItem = WM_GetDialogItem(pMsg->hWin, ID_TEXT_1);
        TEXT_SetFont(hItem, &GUI_FontRounded22);
        TEXT_SetText(hItem, "Month    Day        Year");
        TEXT_SetTextColor(hItem, GUI_MAKE_COLOR(0x00808080));


        spinWheel = WM_CreateWindowAsChild(20, 90, 480, 120,
                                           pMsg->hWin, WM_CF_SHOW, _cbBkWheel, 0);
        if (clockFormat == 24)
        {
            CreateListWheel(0, 0,  ch, h, GUI_ID_LISTWHEEL0, hours24,
                            GUI_COUNTOF(hours24),  40, GUI_TA_VCENTER | GUI_TA_HCENTER,
                            spinWheel, &_aWheel[0], &GUI_Font32B_ASCII, current_hour);
        }
        else
        {
            int hour;
            if (current_hour > 12)
            {
                hour = current_hour - 12;
            }
            else
            {
                hour = current_hour;
            }
            CreateListWheel(0, 0,  ch, h, GUI_ID_LISTWHEEL0, hours12,
                            GUI_COUNTOF(hours12),  40, GUI_TA_VCENTER | GUI_TA_HCENTER,
                            spinWheel, &_aWheel[0], &GUI_Font32B_ASCII, hour);
        }
        CreateListWheel(60, 0, ch, h, GUI_ID_LISTWHEEL1, minutes,
                        GUI_COUNTOF(minutes), 40,  GUI_TA_VCENTER | GUI_TA_RIGHT,
                        spinWheel, &_aWheel[1], &GUI_Font32B_ASCII, current_minute);

        if (clockFormat == 12)
        {
            CreateListWheel(120, 0, ch, h, GUI_ID_LISTWHEEL2, ampm,
                            GUI_COUNTOF(ampm), 40, GUI_TA_VCENTER | GUI_TA_RIGHT,
                            spinWheel, &_aWheel[2], &GUI_Font32B_ASCII, current_ampm);
        }

        CreateListWheel(190, 0,  ch+20, h, GUI_ID_LISTWHEEL3, months,
                        GUI_COUNTOF(months),  40, GUI_TA_VCENTER | GUI_TA_HCENTER,
                        spinWheel, &_aWheel[3], &GUI_Font32B_ASCII, current_month-1);
        CreateListWheel(270, 0, ch, h, GUI_ID_LISTWHEEL4, days,
                        GUI_COUNTOF(days), 40, GUI_TA_VCENTER | GUI_TA_HCENTER,
                        spinWheel, &_aWheel[4], &GUI_Font32B_ASCII, current_day-1);
        CreateListWheel(330, 0,  ch+40, h, GUI_ID_LISTWHEEL5, years,
                        GUI_COUNTOF(years),  40, GUI_TA_VCENTER | GUI_TA_HCENTER,
                        spinWheel, &_aWheel[5], &GUI_Font32B_ASCII, current_year-2010);

        hItem = WM_GetDialogItem(pMsg->hWin, ID_BUTTON_CANCEL);
        WM_SetCallback(hItem, buttonOn16_cb);

        hItem = WM_GetDialogItem(pMsg->hWin, ID_BUTTON_SAVE);
        WM_SetCallback(hItem, buttonOn16_cb);
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
                CreateSettings();
                //state = 4;
                break;
            }
            break;
        case ID_BUTTON_SAVE:
            switch(NCode)
            {
            case WM_NOTIFICATION_RELEASED:
                current_hour = LISTWHEEL_GetPos(_aWheel[0].hWin);
                current_minute = LISTWHEEL_GetPos(_aWheel[1].hWin);
                current_ampm = LISTWHEEL_GetPos(_aWheel[2].hWin);
                current_day = LISTWHEEL_GetPos(_aWheel[3].hWin);
                current_month = LISTWHEEL_GetPos(_aWheel[4].hWin);
                current_year = LISTWHEEL_GetPos(_aWheel[5].hWin) + 2010;
#ifndef CODEBLOCK
                RTC_TimeTypeDef tm;
                RTC_DateTypeDef dt;

                dt.Year = current_year - 2000;
                dt.Date = current_day ;
                dt.Month = current_month;
                dt.WeekDay = current_wday;
                //current_dst = dt.daylight;

                tm.Hours = current_hour;
                tm.Minutes = current_minute;
               //= (tm.Hour <= 12) ? 0 : 1;

                BSP_RTC_SetTime(&tm);
                BSP_RTC_SetDate(&dt);
#endif

//                sprintf(buf, "%d,%d,%d,%d,%d,%d",
//                        current_hour, current_minute, current_ampm,current_day, current_month, current_year);
//                GUI_ErrorOut(buf);
                GUI_Delay(100);
                CreateSettings();
                // state = 4;
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

    time_t rawtime;
    struct tm *info;

    time( &rawtime );
    info = localtime( &rawtime );

    current_year = info->tm_year + 1900;
    current_day = info->tm_mday;
    current_month = info->tm_mon;
    current_wday = info->tm_wday;
    current_dst = info->tm_isdst;

    current_hour = info->tm_hour;
    current_minute = info->tm_min;
    current_ampm = (info->tm_hour <= 12) ? 0 : 1;

    hWin = GUI_CreateDialogBox(_aDialogCreate, GUI_COUNTOF(_aDialogCreate), _cbDialog, WM_HBKWIN, 0, 0);
    return hWin;
}


/*************************** End of file ****************************/
