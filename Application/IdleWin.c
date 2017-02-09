#include "ranger.h"

#define ID_HOME_WINDOW     (GUI_ID_USER + 0x00)
#define ID_TEXT_INSIDE_TEMP       (GUI_ID_USER + 0x07)
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

static const GUI_WIDGET_CREATE_INFO _aDialogCreate[] =
{
    { WINDOW_CreateIndirect, "HomeWin", ID_HOME_WINDOW, 0, 0, 480, 272, 0, 0x0, 0 },
    { TEXT_CreateIndirect, "", ID_TEXT_IDLE, 0, 0, 480, 270, 0, 0x64, 0 },
    { TEXT_CreateIndirect, "In_T_Panel", ID_TEXT_INSIDE_TEMP, 162, 118, 135, 100, 0, 0x64, 0 },
    { TEXT_CreateIndirect, "", ID_TEXT_DATE, 10, 0, 140, 50, 0, 0x64, 0 },
    { TEXT_CreateIndirect, "", ID_TEXT_TIME, 160, 0, 150, 50, 0, 0x64, 0 },
    { TEXT_CreateIndirect, "Out_T_Temp", ID_TEXT_OUT_TEMP, 386, 7, 72, 20, 0, 0x64, 0 },
    { TEXT_CreateIndirect, "OUSIDE", ID_TEXT_OUTSIDE, 389, 26, 61, 20, 0, 0x64, 0 },
    { TEXT_CreateIndirect, "INDOOR", ID_TEXT_INDOOR, 165, 92, 89, 20, 0, 0x64, 0 },
    { TEXT_CreateIndirect, "HUMIDITY", ID_TEXT_HUMIDITY, 165, 206, 160, 20, 0, 0x64, 0 },
    { BUTTON_CreateIndirect, "", ID_BUTTON_WIFI, 320, 0, 50, 50, 0, 0x0, 0 },

};

static int timerTemp;
static GUI_TIMER_HANDLE tempTimer_h;

static WM_HWIN insideTempText;

static char date_buf[20];
static char time_buf[20];

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
extern void wifi_cb(WM_MESSAGE *);

/*********************************************************************
*
*       _cbDialog
*/
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
        GUI_DrawGradientV(0, 0, 480, 50, 0x63b39b, 0x48866c);
        GUI_DrawBitmap(&bmwatermark, 45,50);
        GUI_SetColor(0x808080);
        GUI_SetPenSize(3);
        GUI_AA_DrawArc(285,107,6,6,0,360);
        break;
    case WM_INIT_DIALOG:
        hItem = pMsg->hWin;

        hItem = WM_GetDialogItem(pMsg->hWin, ID_BUTTON_WIFI);
        BUTTON_SetSkin(hItem, wifiSkin);

        dateText = WM_GetDialogItem(pMsg->hWin, ID_TEXT_DATE);
        TEXT_SetText(dateText, date_buf);
        TEXT_SetTextAlign(dateText, GUI_TA_LEFT | GUI_TA_VCENTER);
        TEXT_SetFont(dateText, &GUI_FontRounded22);
        TEXT_SetTextColor(dateText, textColor);
        //
        timeText = WM_GetDialogItem(pMsg->hWin, ID_TEXT_TIME);
        TEXT_SetText(timeText, time_buf);
        TEXT_SetTextAlign(timeText, GUI_TA_LEFT | GUI_TA_VCENTER);
        TEXT_SetFont(timeText, &GUI_FontRounded22);
        TEXT_SetTextColor(timeText, textColor);
        //
        sprintf(buffer, "%d °  |  %d%%", localTemp, localHumidity);
        hItem = WM_GetDialogItem(pMsg->hWin, ID_TEXT_OUT_TEMP);
        TEXT_SetText(hItem, buffer);
        TEXT_SetFont(hItem, &GUI_FontRounded16);
        TEXT_SetTextColor(hItem, textColor);
        //
        hItem = WM_GetDialogItem(pMsg->hWin, ID_TEXT_OUTSIDE);
        TEXT_SetFont(hItem, &GUI_FontRounded16);
        TEXT_SetText(hItem, "OUTSIDE");
        TEXT_SetTextColor(hItem, textColor);
        //
        sprintf(buffer,"%d",insideTemp);
        insideTempText = WM_GetDialogItem(pMsg->hWin, ID_TEXT_INSIDE_TEMP);
        TEXT_SetText(insideTempText, buffer);
        TEXT_SetFont(insideTempText, GUI_FONT_D80);
        TEXT_SetTextColor(insideTempText, 0x00808080);
//        WM_HideWindow(insideTempText);

        textIndoor = WM_GetDialogItem(pMsg->hWin, ID_TEXT_INDOOR);
        TEXT_SetText(textIndoor, "INDOOR");
        TEXT_SetTextColor(textIndoor, 0x808080);
        TEXT_SetFont(textIndoor, &FontBig20B);
        //
        sprintf(buffer, "%d%% HUMIDITY", insideHumidity);
        hItem = WM_GetDialogItem(pMsg->hWin, ID_TEXT_HUMIDITY);
        TEXT_SetFont(hItem, &FontBig20B);
        TEXT_SetTextColor(hItem, 0x808080);
        TEXT_SetText(hItem, buffer);

        break;
    case WM_NOTIFY_PARENT:
        Id    = WM_GetId(pMsg->hWinSrc);
        NCode = pMsg->Data.v;
        if (NCode == 1) {
            GUI_TIMER_SetPeriod(lockTimer_h, idleTimeOut);
            GUI_TIMER_Restart(lockTimer_h);
            CreateHomeWin();
        }
    default:
        WM_DefaultProc(pMsg);
        break;
    }
}

static void tempTimer(GUI_TIMER_MESSAGE * pTM)
{
    char buf[10];
    sprintf(buf,"%d",insideTemp);
    TEXT_SetText(insideTempText, buf);
    TEXT_SetText(textIndoor, "INDOOR");
    GUI_TIMER_SetPeriod(pTM->hTimer, 4000);
    GUI_TIMER_Restart(pTM->hTimer);
}

static void dateTimer(GUI_TIMER_MESSAGE * pTM)
{
    time_t now = time(NULL);
    strftime(date_buf, 20, "%a %m/%d/%Y", localtime(&now));
    if (clockFormat == 24)
    {
        strftime(time_buf, 20, "%H:%M", localtime(&now));
    }
    else
    {
        strftime(time_buf, 20, "%I:%M %p", localtime(&now));
    }
    TEXT_SetText(dateText, date_buf);
    TEXT_SetText(timeText, time_buf);

    GUI_TIMER_SetPeriod(pTM->hTimer, 60000);
    GUI_TIMER_Restart(pTM->hTimer);
}
/*********************************************************************
*
*       CreateHomeWin
*/
WM_HWIN CreateIdleWin(void);
WM_HWIN CreateIdleWin(void)
{
    WM_HWIN hWin;
    time_t now = time(NULL);

    strftime(date_buf, 20, "%a %m/%d/%Y", localtime(&now));
    if (clockFormat == 24)
    {
        strftime(time_buf, 20, "%H:%M", localtime(&now));
    }
    else
    {
        strftime(time_buf, 20, "%I:%M %p", localtime(&now));
    }

    if (!tempTimerSet)
    {
        GUI_TIMER_Create(dateTimer, 60000, 0, 0);
        tempTimer_h = GUI_TIMER_Create(tempTimer, 4000, 0, 0);
        tempTimerSet = 1;
    }

    hWin = GUI_CreateDialogBox(_aDialogCreate, GUI_COUNTOF(_aDialogCreate), _cbDialog, WM_HBKWIN, 0, 0);
    return hWin;
}

/*************************** End of file ****************************/
