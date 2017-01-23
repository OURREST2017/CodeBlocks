/*********************************************************************
*                                                                    *
*                SEGGER Microcontroller GmbH & Co. KG                *
*        Solutions for real time microcontroller applications        *
*                                                                    *
**********************************************************************
*                                                                    *
* C-file generated by:                                               *
*                                                                    *
*        GUI_Builder for emWin version 5.32                          *
*        Compiled Oct  8 2015, 11:59:02                              *
*        (c) 2015 Segger Microcontroller GmbH & Co. KG               *
*                                                                    *
**********************************************************************
*                                                                    *
*        Internet: www.segger.com  Support: support@segger.com       *
*                                                                    *
**********************************************************************
*/

#include "main.h"

#define ID_WINDOW_0 (GUI_ID_USER + 0x00)
#define ID_HEADER_0 (GUI_ID_USER + 0x01)
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

#define ID_LW_WAKE_HOUR1 (GUI_ID_USER + 0xB1)
#define ID_LW_WAKE_MINUTE1 (GUI_ID_USER + 0xB2)
#define ID_TEXT_WAKE_SEP1 (GUI_ID_USER + 0xB3)
#define ID_LW_WAKE_AMPM1 (GUI_ID_USER + 0xB4)

#define ID_LW_WAKE_HOUR2 (GUI_ID_USER + 0xB5)
#define ID_LW_WAKE_MINUTE2 (GUI_ID_USER + 0xB6)
#define ID_TEXT_WAKE_SEP2 (GUI_ID_USER + 0xB7)
#define ID_LW_WAKE_AMPM2 (GUI_ID_USER + 0xB8)

#define ID_LW_LEAVE_HOUR1 (GUI_ID_USER + 0xB9)
#define ID_LW_LEAVE_MINUTE1 (GUI_ID_USER + 0xBA)
#define ID_TEXT_LEAVE_SEP1 (GUI_ID_USER + 0xBB)
#define ID_LW_LEAVE_AMPM1 (GUI_ID_USER + 0xBC)

#define ID_LW_LEAVE_HOUR2 (GUI_ID_USER + 0xBD)
#define ID_LW_LEAVE_MINUTE2 (GUI_ID_USER + 0xBE)
#define ID_TEXT_LEAVE_SEP2 (GUI_ID_USER + 0xBF)
#define ID_LW_LEAVE_AMPM2 (GUI_ID_USER + 0xC0)

#define ID_LW_RETURN_HOUR1 (GUI_ID_USER + 0xC1)
#define ID_LW_RETURN_MINUTE1 (GUI_ID_USER + 0xC2)
#define ID_TEXT_RETURN_SEP1 (GUI_ID_USER + 0xC3)
#define ID_LW_RETURN_AMPM1 (GUI_ID_USER + 0xC4)

#define ID_LW_RETURN_HOUR2 (GUI_ID_USER + 0xC5)
#define ID_LW_RETURN_MINUTE2 (GUI_ID_USER + 0xC6)
#define ID_TEXT_RETURN_SEP2 (GUI_ID_USER + 0xC7)
#define ID_LW_RETURN_AMPM2 (GUI_ID_USER + 0xC8)

#define ID_LW_SLEEP_HOUR1 (GUI_ID_USER + 0xC9)
#define ID_LW_SLEEP_MINUTE1 (GUI_ID_USER + 0xCA)
#define ID_TEXT_SLEEP_SEP1 (GUI_ID_USER + 0xCB)
#define ID_LW_SLEEP_AMPM1 (GUI_ID_USER + 0xCC)

#define ID_LW_SLEEP_HOUR2 (GUI_ID_USER + 0xCD)
#define ID_LW_SLEEP_MINUTE2 (GUI_ID_USER + 0xCE)
#define ID_TEXT_SLEEP_SEP2 (GUI_ID_USER + 0xCF)
#define ID_LW_SLEEP_AMPM2 (GUI_ID_USER + 0xD0)

/*********************************************************************
*
*       _aDialogCreate
*/
static const GUI_WIDGET_CREATE_INFO _aDialogCreate[] =
{
    { WINDOW_CreateIndirect, "Window", ID_WINDOW_0, 0, 0, 480, 272, 0, 0x0, 0 },
    { HEADER_CreateIndirect, "Header", ID_HEADER_0, 0, 0, 480, 50, 0, 0x0, 0 },

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

    { BUTTON_CreateIndirect, "CANCEL", ID_BUTTON_CANCEL, 20, 230, 80, 28, 0, 0x0, 0 },
    { BUTTON_CreateIndirect, "EDIT", ID_BUTTON_EDIT, 375, 230, 80, 28, 0, 0x0, 0 },

    { LISTWHEEL_CreateIndirect, "", ID_LW_WAKE_HOUR1, 144, 56, 25,34, 0, 0x0, 0 },
    { LISTWHEEL_CreateIndirect, "", ID_LW_WAKE_MINUTE1, 176, 56, 25,34, 0, 0x0, 0 },
    { TEXT_CreateIndirect, ":", ID_TEXT_WAKE_SEP1, 169, 56, 8, 34, 0, 0x64, 0 },
    { LISTWHEEL_CreateIndirect, "", ID_LW_WAKE_AMPM1, 204, 56, 25,34, 0, 0x0, 0 },

    { LISTWHEEL_CreateIndirect, "", ID_LW_WAKE_HOUR2, 244, 56, 25,34, 0, 0x0, 0 },
    { LISTWHEEL_CreateIndirect, "", ID_LW_WAKE_MINUTE2, 276, 56, 25,34, 0, 0x0, 0 },
    { TEXT_CreateIndirect, ":", ID_TEXT_WAKE_SEP2, 269, 56, 8, 34, 0, 0x64, 0 },
    { LISTWHEEL_CreateIndirect, "", ID_LW_WAKE_AMPM2, 304, 56, 25,34, 0, 0x0, 0 },

    { LISTWHEEL_CreateIndirect, "", ID_LW_LEAVE_HOUR1, 144, 96, 25,34, 0, 0x0, 0 },
    { LISTWHEEL_CreateIndirect, "", ID_LW_LEAVE_MINUTE1, 176, 96, 25,34, 0, 0x0, 0 },
    { TEXT_CreateIndirect, ":", ID_TEXT_LEAVE_SEP1, 169, 96, 8, 34, 0, 0x64, 0 },
    { LISTWHEEL_CreateIndirect, "", ID_LW_LEAVE_AMPM1, 204, 96, 25,34, 0, 0x0, 0 },

    { LISTWHEEL_CreateIndirect, "", ID_LW_LEAVE_HOUR2, 244, 96, 25,34, 0, 0x0, 0 },
    { LISTWHEEL_CreateIndirect, "", ID_LW_LEAVE_MINUTE2, 276, 96, 25,34, 0, 0x0, 0 },
    { TEXT_CreateIndirect, ":", ID_TEXT_LEAVE_SEP2, 269, 96, 8, 34, 0, 0x64, 0 },
    { LISTWHEEL_CreateIndirect, "", ID_LW_LEAVE_AMPM2, 304, 96, 25,34, 0, 0x0, 0 },

    { LISTWHEEL_CreateIndirect, "", ID_LW_RETURN_HOUR1, 144, 136, 25,34, 0, 0x0, 0 },
    { LISTWHEEL_CreateIndirect, "", ID_LW_RETURN_MINUTE1, 176, 136, 25,34, 0, 0x0, 0 },
    { TEXT_CreateIndirect, ":", ID_TEXT_RETURN_SEP1, 169, 136, 8, 36, 0, 0x64, 0 },
    { LISTWHEEL_CreateIndirect, "", ID_LW_RETURN_AMPM1, 204, 136, 25,34, 0, 0x0, 0 },

    { LISTWHEEL_CreateIndirect, "", ID_LW_RETURN_HOUR2, 244, 136, 25,34, 0, 0x0, 0 },
    { LISTWHEEL_CreateIndirect, "", ID_LW_RETURN_MINUTE2, 276, 136, 25,34, 0, 0x0, 0 },
    { TEXT_CreateIndirect, ":", ID_TEXT_RETURN_SEP2, 269, 136, 8, 36, 0, 0x64, 0 },
    { LISTWHEEL_CreateIndirect, "", ID_LW_RETURN_AMPM2, 304, 136, 25,34, 0, 0x0, 0 },

    { LISTWHEEL_CreateIndirect, "", ID_LW_SLEEP_HOUR1, 144, 176, 25,34, 0, 0x0, 0 },
    { LISTWHEEL_CreateIndirect, "", ID_LW_SLEEP_MINUTE1, 176, 176, 25,34, 0, 0x0, 0 },
    { TEXT_CreateIndirect, ":", ID_TEXT_SLEEP_SEP1, 169, 176, 8, 34, 0, 0x64, 0 },
    { LISTWHEEL_CreateIndirect, "", ID_LW_SLEEP_AMPM1, 204, 176, 25,34, 0, 0x0, 0 },

    { LISTWHEEL_CreateIndirect, "", ID_LW_SLEEP_HOUR2, 244, 176, 25, 34, 0, 0x0, 0 },
    { LISTWHEEL_CreateIndirect, "", ID_LW_SLEEP_MINUTE2, 276, 176, 25, 34, 0, 0x0, 0 },
    { TEXT_CreateIndirect, ":", ID_TEXT_SLEEP_SEP2, 269, 176, 8, 34, 0, 0x64, 0 },
    { LISTWHEEL_CreateIndirect, "", ID_LW_SLEEP_AMPM2, 304, 176, 25,34, 0, 0x0, 0 },
};

static int selected_day, upperDegrees, lowerDegrees;

static struct days_s days[7];
static void  setDays(WM_HWIN *, int);

static struct days_s selectedDay;
static struct periods_s selectedPeriod;
static struct periods_s periods[7];

static char *periods_text[] = {"wake","leave","return","sleep"};
static char *days_text[] = {"monday","tuesday","wednesday","thursday","friday","saturday","sunday"};

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
        TEXT_SetFont(txt, GUI_FONT_32_1);
    }
    txt = WM_GetDialogItem(win, id);
    TEXT_SetFont(txt, GUI_FONT_32B_1);
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

static char *hours[2][24] =
{
    {
        "00", "01", "02", "03", "04", "05", "06", "07", "08", "09", "10", "11", "12",
        "13", "14", "15", "16", "17", "18", "19", "20", "21", "22", "23", 0
    },
    {" 1", " 2", " 3", " 4", " 5", " 6", " 7", " 8", " 9", "10", "11", "12", 0}
};

static char * minutes[] =
{
    "00", "01", "02", "03", "04", "05", "06", "07", "08", "09", "10",
    "11", "12", "13", "14", "15", "16", "17", "18", "19", "20",
    "21", "22", "23", "24", "25", "26", "27", "28", "29", "30",
    "31", "32", "33", "34", "35", "36", "37", "38", "39", "40",
    "41", "42", "43", "44", "45", "46", "47", "48", "49", "50",
    "51", "52", "53", "54", "55", "56", "57", "58", "59", 0
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

static int _OwnerDraw(const WIDGET_ITEM_DRAW_INFO * pDrawItemInfo)
{
    switch (pDrawItemInfo->Cmd)
    {
    case WIDGET_DRAW_OVERLAY:
        GUI_SetColor(GUI_DARKGREEN);
        GUI_DrawHLine(9, 0, 99);
        GUI_DrawHLine(8, 0, 99);
        GUI_DrawHLine(26, 0, 99);
        GUI_DrawHLine(27, 0, 99);
        GUI_SetColor(0x00dbdbdb);
        GUI_SetAlpha(170);
        GUI_FillRect(0,8,40,25);
        break;
    default:
        return LISTWHEEL_OwnerDraw(pDrawItemInfo);
    }
    return 0;
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

void listWheel(WM_HWIN hItem, char **items, int count, GUI_FONT *font)
{
    int i;

    LISTWHEEL_SetLineHeight(hItem, 20);
    LISTWHEEL_SetFont(hItem, font);
    LISTWHEEL_SetSnapPosition(hItem, 8);
    LISTWHEEL_SetTextAlign(hItem, GUI_TA_VCENTER | GUI_TA_HCENTER);
    LISTWHEEL_SetOwnerDraw(hItem, _OwnerDraw);
    LISTWHEEL_SetBkColor(hItem, 0, 0xcccccc);
    LISTWHEEL_SetBkColor(hItem, 1, 0x005500);
    LISTWHEEL_SetTextColor(hItem, 0, 0x666666);
    LISTWHEEL_SetTextColor(hItem, 1, GUI_WHITE);
    //WM_SetTransState(hItem, WM_CF_HASTRANS);

    for (i = 0; i < count; i++)
    {
        LISTWHEEL_AddString(hItem, *(items + i));
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
    char buf[30];
    int xSize = 28;
    int ySize = 36;
    int lh = 20;

    switch (pMsg->MsgId)
    {
    case WM_PAINT:
        GUI_DrawBitmap(&bmwatermark, 0,50);
        GUI_SetColor(0xcecece);
        GUI_DrawHLine(92, 0, 479);
        GUI_DrawHLine(132, 0, 479);
        GUI_DrawHLine(172, 0, 479);
        break;
    case WM_INIT_DIALOG:
        hItem = WM_GetDialogItem(pMsg->hWin, ID_TEXT_MONDAY);
        TEXT_SetTextAlign(hItem, GUI_TA_HCENTER | GUI_TA_VCENTER);
        TEXT_SetFont(hItem, GUI_FONT_32B_1);
        TEXT_SetTextColor(hItem, GUI_MAKE_COLOR(0x00FFFFFF));
        //
        hItem = WM_GetDialogItem(pMsg->hWin, ID_TEXT_TUESDAY);
        TEXT_SetTextAlign(hItem, GUI_TA_HCENTER | GUI_TA_VCENTER);
        TEXT_SetFont(hItem, GUI_FONT_32_1);
        TEXT_SetTextColor(hItem, GUI_MAKE_COLOR(0x00FFFFFF));
        //
        hItem = WM_GetDialogItem(pMsg->hWin, ID_TEXT_WEDNESDAY);
        TEXT_SetFont(hItem, GUI_FONT_32_1);
        TEXT_SetTextAlign(hItem, GUI_TA_HCENTER | GUI_TA_VCENTER);
        TEXT_SetTextColor(hItem, GUI_MAKE_COLOR(0x00FFFFFF));
        //
        hItem = WM_GetDialogItem(pMsg->hWin, ID_TEXT_THURSDAY);
        TEXT_SetFont(hItem, GUI_FONT_32_1);
        TEXT_SetTextAlign(hItem, GUI_TA_HCENTER | GUI_TA_VCENTER);
        TEXT_SetTextColor(hItem, GUI_MAKE_COLOR(0x00FFFFFF));
        //
        hItem = WM_GetDialogItem(pMsg->hWin, ID_TEXT_FRIDAY);
        TEXT_SetFont(hItem, GUI_FONT_32_1);
        TEXT_SetTextAlign(hItem, GUI_TA_HCENTER | GUI_TA_VCENTER);
        TEXT_SetTextColor(hItem, GUI_MAKE_COLOR(0x00FFFFFF));
        //
        hItem = WM_GetDialogItem(pMsg->hWin, ID_TEXT_SATURDAY);
        TEXT_SetFont(hItem, GUI_FONT_32_1);
        TEXT_SetTextAlign(hItem, GUI_TA_HCENTER | GUI_TA_VCENTER);
        TEXT_SetTextColor(hItem, GUI_MAKE_COLOR(0x00FFFFFF));
        //
        hItem = WM_GetDialogItem(pMsg->hWin, ID_TEXT_SUNDAY);
        TEXT_SetTextAlign(hItem, GUI_TA_HCENTER | GUI_TA_VCENTER);
        TEXT_SetFont(hItem, GUI_FONT_32_1);
        TEXT_SetTextColor(hItem, GUI_MAKE_COLOR(0x00FFFFFF));
        //
        hItem = WM_GetDialogItem(pMsg->hWin, ID_TEXT_WAKE);
        TEXT_SetFont(hItem, &FontBig20B);
        TEXT_SetTextAlign(hItem, GUI_TA_LEFT);
        TEXT_SetTextColor(hItem, GUI_MAKE_COLOR(0x00808080));
        TEXT_SetText(hItem, toup(getPeriod(periods_text[0]).label));

        //  WAKE
        hItem = WM_GetDialogItem(pMsg->hWin, ID_LW_WAKE_HOUR1);
        listWheel(hItem, hours[(clockFormat == 12)], clockFormat, &FontBig20B);

        hItem = WM_GetDialogItem(pMsg->hWin, ID_TEXT_WAKE_SEP1);
        TEXT_SetTextAlign(hItem, GUI_TA_HCENTER | GUI_TA_VCENTER);
        TEXT_SetFont(hItem, &FontBig20B);
        TEXT_SetTextColor(hItem, GUI_MAKE_COLOR(0x555555));
        TEXT_SetText(hItem, ":");

        hItem = WM_GetDialogItem(pMsg->hWin, ID_LW_WAKE_MINUTE1);
        listWheel(hItem, minutes, 60, &FontBig20B);

        hItem = WM_GetDialogItem(pMsg->hWin, ID_LW_WAKE_AMPM1);
        listWheel(hItem, ampm, 2, &GUI_Font16B_ASCII);
        if (clockFormat == 24) WM_HideWindow(hItem);

        hItem = WM_GetDialogItem(pMsg->hWin, ID_LW_WAKE_HOUR2);
        listWheel(hItem, hours[(clockFormat == 12)], clockFormat, &FontBig20B);

        hItem = WM_GetDialogItem(pMsg->hWin, ID_TEXT_WAKE_SEP2);
        TEXT_SetTextAlign(hItem, GUI_TA_HCENTER | GUI_TA_VCENTER);
        TEXT_SetFont(hItem, &FontBig20B);
        TEXT_SetTextColor(hItem, GUI_MAKE_COLOR(0x555555));
        TEXT_SetText(hItem, ":");

        hItem = WM_GetDialogItem(pMsg->hWin, ID_LW_WAKE_MINUTE2);
        listWheel(hItem, minutes, 60, &FontBig20B);

        hItem = WM_GetDialogItem(pMsg->hWin, ID_LW_WAKE_AMPM2);
        listWheel(hItem, ampm, 2, &GUI_Font16B_ASCII);
        if (clockFormat == 24) WM_HideWindow(hItem);

        // LEAVE
        hItem = WM_GetDialogItem(pMsg->hWin, ID_LW_LEAVE_HOUR1);
        listWheel(hItem, hours[(clockFormat == 12)], clockFormat, &FontBig20B);

        hItem = WM_GetDialogItem(pMsg->hWin, ID_TEXT_LEAVE_SEP1);
        TEXT_SetTextAlign(hItem, GUI_TA_HCENTER | GUI_TA_VCENTER);
        TEXT_SetFont(hItem, &FontBig20B);
        TEXT_SetTextColor(hItem, GUI_MAKE_COLOR(0x555555));
        TEXT_SetText(hItem, ":");

        hItem = WM_GetDialogItem(pMsg->hWin, ID_LW_LEAVE_MINUTE1);
        listWheel(hItem, minutes, 60, &FontBig20B);

        hItem = WM_GetDialogItem(pMsg->hWin, ID_LW_LEAVE_AMPM1);
        listWheel(hItem, ampm, 2, &GUI_Font16B_ASCII);
        if (clockFormat == 24) WM_HideWindow(hItem);

        hItem = WM_GetDialogItem(pMsg->hWin, ID_LW_LEAVE_HOUR2);
        listWheel(hItem, hours[(clockFormat == 12)], clockFormat, &FontBig20B);

        hItem = WM_GetDialogItem(pMsg->hWin, ID_TEXT_LEAVE_SEP2);
        TEXT_SetTextAlign(hItem, GUI_TA_HCENTER | GUI_TA_VCENTER);
        TEXT_SetFont(hItem, &FontBig20B);
        TEXT_SetTextColor(hItem, GUI_MAKE_COLOR(0x555555));
        TEXT_SetText(hItem, ":");

        hItem = WM_GetDialogItem(pMsg->hWin, ID_LW_LEAVE_MINUTE2);
        listWheel(hItem, minutes, 60, &FontBig20B);

        hItem = WM_GetDialogItem(pMsg->hWin, ID_LW_LEAVE_AMPM2);
        listWheel(hItem, ampm, 2, &GUI_Font16B_ASCII);
        if (clockFormat == 24) WM_HideWindow(hItem);

        // RETURN
        hItem = WM_GetDialogItem(pMsg->hWin, ID_LW_RETURN_HOUR1);
        listWheel(hItem, hours[(clockFormat == 12)], clockFormat, &FontBig20B);

        hItem = WM_GetDialogItem(pMsg->hWin, ID_TEXT_RETURN_SEP1);
        TEXT_SetTextAlign(hItem, GUI_TA_HCENTER | GUI_TA_VCENTER);
        TEXT_SetFont(hItem, &FontBig20B);
        TEXT_SetTextColor(hItem, GUI_MAKE_COLOR(0x555555));
        TEXT_SetText(hItem, ":");

        hItem = WM_GetDialogItem(pMsg->hWin, ID_LW_RETURN_MINUTE1);
        listWheel(hItem, minutes, 60, &FontBig20B);

        hItem = WM_GetDialogItem(pMsg->hWin, ID_LW_RETURN_AMPM1);
        listWheel(hItem, ampm, 2, &GUI_Font16B_ASCII);
        if (clockFormat == 24) WM_HideWindow(hItem);

        hItem = WM_GetDialogItem(pMsg->hWin, ID_LW_RETURN_HOUR2);
        listWheel(hItem, hours[(clockFormat == 12)], clockFormat, &FontBig20B);

        hItem = WM_GetDialogItem(pMsg->hWin, ID_TEXT_RETURN_SEP2);
        TEXT_SetTextAlign(hItem, GUI_TA_HCENTER | GUI_TA_VCENTER);
        TEXT_SetFont(hItem, &FontBig20B);
        TEXT_SetTextColor(hItem, GUI_MAKE_COLOR(0x555555));
        TEXT_SetText(hItem, ":");

        hItem = WM_GetDialogItem(pMsg->hWin, ID_LW_RETURN_MINUTE2);
        listWheel(hItem, minutes, 60, &FontBig20B);

        hItem = WM_GetDialogItem(pMsg->hWin, ID_LW_RETURN_AMPM2);
        listWheel(hItem, ampm, 2, &GUI_Font16B_ASCII);
        if (clockFormat == 24) WM_HideWindow(hItem);

        // SLEEP
        hItem = WM_GetDialogItem(pMsg->hWin, ID_LW_SLEEP_HOUR1);
        listWheel(hItem, hours[(clockFormat == 12)], clockFormat, &FontBig20B);

        hItem = WM_GetDialogItem(pMsg->hWin, ID_TEXT_SLEEP_SEP1);
        TEXT_SetTextAlign(hItem, GUI_TA_HCENTER | GUI_TA_VCENTER);
        TEXT_SetFont(hItem, &FontBig20B);
        TEXT_SetTextColor(hItem, GUI_MAKE_COLOR(0x555555));
        TEXT_SetText(hItem, ":");

        hItem = WM_GetDialogItem(pMsg->hWin, ID_LW_SLEEP_MINUTE1);
        listWheel(hItem, minutes, 60, &FontBig20B);

        hItem = WM_GetDialogItem(pMsg->hWin, ID_LW_SLEEP_AMPM1);
        listWheel(hItem, ampm, 2, &GUI_Font16B_ASCII);
        if (clockFormat == 24) WM_HideWindow(hItem);

        hItem = WM_GetDialogItem(pMsg->hWin, ID_LW_SLEEP_HOUR2);
        listWheel(hItem, hours[(clockFormat == 12)], clockFormat, &FontBig20B);

        hItem = WM_GetDialogItem(pMsg->hWin, ID_TEXT_SLEEP_SEP2);
        TEXT_SetTextAlign(hItem, GUI_TA_HCENTER | GUI_TA_VCENTER);
        TEXT_SetFont(hItem, &FontBig20B);
        TEXT_SetTextColor(hItem, GUI_MAKE_COLOR(0x555555));
        TEXT_SetText(hItem, ":");

        hItem = WM_GetDialogItem(pMsg->hWin, ID_LW_SLEEP_MINUTE2);
        listWheel(hItem, minutes, 60, &FontBig20B);

        hItem = WM_GetDialogItem(pMsg->hWin, ID_LW_SLEEP_AMPM2);
        listWheel(hItem, ampm, 2, &GUI_Font16B_ASCII);
        if (clockFormat == 24) WM_HideWindow(hItem);

        setDays(pMsg->hWin, 0);

//        hItem = WM_GetDialogItem(pMsg->hWin, ID_TEXT_WAKE_TIME);
//        TEXT_SetTextAlign(hItem, GUI_TA_HCENTER | GUI_TA_VCENTER);
//        TEXT_SetFont(hItem, &FontBig20B);
//        TEXT_SetTextColor(hItem, GUI_MAKE_COLOR(0x00808080));
//        sprintf(buf,"%s - %s",
//                getPeriod(periods_text[0]).startTime, getPeriod(periods_text[0]).stopTime);
//        TEXT_SetText(hItem, buf);
        //
        hItem = WM_GetDialogItem(pMsg->hWin, ID_TEXT_WAKE_TEMP);
        TEXT_SetFont(hItem, &FontBig20B);
        TEXT_SetTextAlign(hItem, GUI_TA_HCENTER | GUI_TA_VCENTER);
        TEXT_SetTextColor(hItem, GUI_MAKE_COLOR(0x00808080));
        sprintf(buf,"%d", getPeriod(periods_text[0]).tempurature);
        TEXT_SetText(hItem, buf);
//        //
        hItem = WM_GetDialogItem(pMsg->hWin, ID_TEXT_LEAVE);
        TEXT_SetFont(hItem, &FontBig20B);
        TEXT_SetTextAlign(hItem, GUI_TA_LEFT);
        TEXT_SetTextColor(hItem, GUI_MAKE_COLOR(0x00808080));
        TEXT_SetText(hItem, toup(getPeriod(periods_text[1]).label));
//        //
//        hItem = WM_GetDialogItem(pMsg->hWin, ID_TEXT_LEAVE_TIME);
//        TEXT_SetTextAlign(hItem, GUI_TA_HCENTER | GUI_TA_VCENTER);
//        TEXT_SetFont(hItem, &FontBig20B);
//        TEXT_SetTextColor(hItem, GUI_MAKE_COLOR(0x00808080));
//        TEXT_SetText(hItem, getTimes(getPeriod(periods_text[1]).stopMinutes,
//                            getPeriod(periods_text[1]).startMinutes, metric));
//
        hItem = WM_GetDialogItem(pMsg->hWin, ID_TEXT_LEAVE_TEMP);
        TEXT_SetFont(hItem, &FontBig20B);
        TEXT_SetTextAlign(hItem, GUI_TA_HCENTER | GUI_TA_VCENTER);
        sprintf(buf,"%d", getPeriod(periods_text[1]).tempurature);
        TEXT_SetTextColor(hItem, GUI_MAKE_COLOR(0x00808080));
        TEXT_SetText(hItem, buf);
        //
        hItem = WM_GetDialogItem(pMsg->hWin, ID_TEXT_RETURN);
        TEXT_SetFont(hItem, &FontBig20B);
        TEXT_SetTextAlign(hItem, GUI_TA_LEFT);
        TEXT_SetTextColor(hItem, GUI_MAKE_COLOR(0x00808080));
        TEXT_SetText(hItem, toup(getPeriod(periods_text[2]).label));
//        //
//        hItem = WM_GetDialogItem(pMsg->hWin, ID_TEXT_RETURN_TIME);
//        TEXT_SetTextAlign(hItem, GUI_TA_HCENTER | GUI_TA_VCENTER);
//        TEXT_SetFont(hItem, &FontBig20B);
//        TEXT_SetText(hItem, getTimes(getPeriod(periods_text[2]).stopMinutes,
//                            getPeriod(periods_text[2]).startMinutes, metric));
//        TEXT_SetTextColor(hItem, GUI_MAKE_COLOR(0x00808080));
//        //
        hItem = WM_GetDialogItem(pMsg->hWin, ID_TEXT_RETURN_TEMP);
        TEXT_SetFont(hItem, &FontBig20B);
        TEXT_SetTextAlign(hItem, GUI_TA_HCENTER | GUI_TA_VCENTER);
        sprintf(buf,"%d", getPeriod(periods_text[2]).tempurature);
        TEXT_SetText(hItem, buf);
        TEXT_SetTextColor(hItem, GUI_MAKE_COLOR(0x00808080));
//        //
        hItem = WM_GetDialogItem(pMsg->hWin, ID_TEXT_SLEEP);
        TEXT_SetFont(hItem, &FontBig20B);
        TEXT_SetTextAlign(hItem, GUI_TA_LEFT);
        TEXT_SetTextColor(hItem, GUI_MAKE_COLOR(0x00808080));
        TEXT_SetText(hItem, toup(getPeriod(periods_text[3]).label));
//        //
//        hItem = WM_GetDialogItem(pMsg->hWin, ID_TEXT_SLEEP_TIME);
//        TEXT_SetTextAlign(hItem, GUI_TA_HCENTER | GUI_TA_VCENTER);
//        TEXT_SetFont(hItem, &FontBig20B);
//        TEXT_SetTextColor(hItem, GUI_MAKE_COLOR(0x00808080));
//        TEXT_SetText(hItem, getTimes(getPeriod(periods_text[3]).stopMinutes,
//                            getPeriod(periods_text[3]).startMinutes, metric));
//        //
        hItem = WM_GetDialogItem(pMsg->hWin, ID_TEXT_SLEEP_TEMP);
        TEXT_SetFont(hItem, &FontBig20B);
        TEXT_SetTextAlign(hItem, GUI_TA_HCENTER | GUI_TA_VCENTER);
        TEXT_SetTextColor(hItem, GUI_MAKE_COLOR(0x00808080));
        sprintf(buf,"%d", getPeriod(periods_text[3]).tempurature);
        TEXT_SetText(hItem, buf);
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
                state = 13;
                break;
            }
            break;
        case ID_BUTTON_EDIT:
            switch(NCode)
            {
            case WM_NOTIFICATION_RELEASED:
                CreateEditSchedule(days_text[selected_day]);
                GUI_Delay(100);
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

static void setDay(WM_HWIN *hWin, int minutes, WM_HWIN **lw)
{
    WM_HWIN *hItem;
    int hour = minutes/60;
    int minute = minutes - hour*60;
    if (minute == 60) minute = 0;
    int pm = hour > 12;
    if (clockFormat == 12 && pm) hour -= 13;
    if (clockFormat == 12 && !pm) hour--;

    int vars[] = {hour, minute, pm};

    int i;
    for (i=0;i<3;i++) {
        hItem = WM_GetDialogItem(hWin, lw[i]);
        LISTWHEEL_SetPos(hItem, vars[i]);
        LISTWHEEL_SetSel(hItem, vars[i]);
    }
}

static void setDays(WM_HWIN *hWin, int d)
{
    WM_HWIN  hItem;

    selectedDay = getDay(days_text[d]);

    WM_HWIN *lws[] = {ID_LW_WAKE_HOUR1, ID_LW_WAKE_MINUTE1, ID_LW_WAKE_AMPM1};
    setDay(hWin, getPeriod(periods_text[0]).startMinutes, lws);

    lws[0] = ID_LW_WAKE_HOUR2; lws[1] = ID_LW_WAKE_MINUTE2; lws[2] = ID_LW_WAKE_AMPM2;
    setDay(hWin, getPeriod(periods_text[0]).stopMinutes, lws);

    lws[0] = ID_LW_LEAVE_HOUR1; lws[1] = ID_LW_LEAVE_MINUTE1; lws[2] = ID_LW_LEAVE_AMPM1;
    setDay(hWin, getPeriod(periods_text[1]).startMinutes, lws);

    lws[0] = ID_LW_LEAVE_HOUR2; lws[1] = ID_LW_LEAVE_MINUTE2; lws[2] = ID_LW_LEAVE_AMPM2;
    setDay(hWin, getPeriod(periods_text[1]).stopMinutes, lws);

    lws[0] = ID_LW_RETURN_HOUR1; lws[1] = ID_LW_RETURN_MINUTE1; lws[2] = ID_LW_RETURN_AMPM1;
    setDay(hWin, getPeriod(periods_text[2]).startMinutes, lws);

    lws[0] = ID_LW_RETURN_HOUR2; lws[1] = ID_LW_RETURN_MINUTE2; lws[2] = ID_LW_RETURN_AMPM2;
    setDay(hWin, getPeriod(periods_text[2]).stopMinutes, lws);

    lws[0] = ID_LW_SLEEP_HOUR1; lws[1] = ID_LW_SLEEP_MINUTE1; lws[2] = ID_LW_SLEEP_AMPM1;
    setDay(hWin, getPeriod(periods_text[3]).startMinutes, lws);

    lws[0] = ID_LW_SLEEP_HOUR2; lws[1] = ID_LW_SLEEP_MINUTE2; lws[2] = ID_LW_SLEEP_AMPM2;
    setDay(hWin, getPeriod(periods_text[3]).stopMinutes, lws);
}

static void setDays1(WM_HWIN *hWin, int d)
{
    char buf [20];
    WM_HWIN  hItem;

    selectedDay = getDay(days_text[d]);

    hItem = WM_GetDialogItem(hWin, ID_TEXT_WAKE);
    TEXT_SetText(hItem, toup(getPeriod(periods_text[0]).label));

    hItem = WM_GetDialogItem(hWin, ID_TEXT_WAKE_TIME);
    sprintf(buf,"%s - %s", getPeriod(periods_text[0]).startTime,
            getPeriod(periods_text[0]).stopTime);
    TEXT_SetText(hItem, buf);

    hItem = WM_GetDialogItem(hWin, ID_TEXT_WAKE_TEMP);
    sprintf(buf,"%d", getPeriod(periods_text[0]).tempurature);
    TEXT_SetText(hItem, buf);


    hItem = WM_GetDialogItem(hWin, ID_TEXT_LEAVE);
    TEXT_SetText(hItem, toup(getPeriod(periods_text[1]).label));

    hItem = WM_GetDialogItem(hWin, ID_TEXT_LEAVE_TIME);
    sprintf(buf,"%s - %s", getPeriod(periods_text[1]).startTime,
            getPeriod(periods_text[1]).stopTime);
    TEXT_SetText(hItem, buf);

    hItem = WM_GetDialogItem(hWin, ID_TEXT_LEAVE_TEMP);
    sprintf(buf,"%d", getPeriod(periods_text[1]).tempurature);
    TEXT_SetText(hItem, buf);


    hItem = WM_GetDialogItem(hWin, ID_TEXT_RETURN);
    TEXT_SetText(hItem, toup(getPeriod(periods_text[2]).label));

    hItem = WM_GetDialogItem(hWin, ID_TEXT_RETURN_TIME);
    sprintf(buf,"%s - %s", getPeriod(periods_text[2]).startTime,
            getPeriod(periods_text[2]).stopTime);
    TEXT_SetText(hItem, buf);

    hItem = WM_GetDialogItem(hWin, ID_TEXT_RETURN_TEMP);
    sprintf(buf,"%d", getPeriod(periods_text[2]).tempurature);
    TEXT_SetText(hItem, buf);


    hItem = WM_GetDialogItem(hWin, ID_TEXT_SLEEP);
    TEXT_SetText(hItem, toup(getPeriod(periods_text[3]).label));

    hItem = WM_GetDialogItem(hWin, ID_TEXT_SLEEP_TIME);
    sprintf(buf,"%s - %s", getPeriod(periods_text[3]).startTime,
            getPeriod(periods_text[3]).stopTime);
    TEXT_SetText(hItem, buf);

    hItem = WM_GetDialogItem(hWin, ID_TEXT_SLEEP_TEMP);
    sprintf(buf,"%d", getPeriod(periods_text[3]).tempurature);
    TEXT_SetText(hItem, buf);
}
/*********************************************************************
*
*       CreateWindow
*/
WM_HWIN CreateEachDay(void);
WM_HWIN CreateEachDay(void)
{
    WM_HWIN hWin;

    getPeriods();
    selectedDay = getDay("monday");

    hWin = GUI_CreateDialogBox(_aDialogCreate, GUI_COUNTOF(_aDialogCreate), _cbDialog, WM_HBKWIN, 0, 0);
    return hWin;
}

/*************************** End of file ****************************/
