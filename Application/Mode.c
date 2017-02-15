#include "ranger.h"

#define ID_WINDOW_0  (GUI_ID_USER + 0x00)
#define ID_BUTTON_OFF  (GUI_ID_USER + 0x01)
#define ID_BUTTON_HEAT  (GUI_ID_USER + 0x02)
#define ID_BUTTON_COOL  (GUI_ID_USER + 0x03)
#define ID_BUTTON_AUTO  (GUI_ID_USER + 0x04)
#define ID_BUTTON_EHEAT  (GUI_ID_USER + 0x05)
#define ID_BUTTON_CANCEL  (GUI_ID_USER + 0x06)
#define ID_BUTTON_DONE  (GUI_ID_USER + 0x07)
#define ID_TEXT_HEADER  (GUI_ID_USER + 0x09)

/*********************************************************************
*
*       _aDialogCreate
*/
static const GUI_WIDGET_CREATE_INFO _aDialogCreate[] =
{
    { WINDOW_CreateIndirect, "Mode", ID_WINDOW_0, 0, 0, 480, 272, 0, 0x0, 0 },
    { TEXT_CreateIndirect, "SELECT MODE", ID_TEXT_HEADER, 0, 0, 480, 50, 0, 0x64, 0 },
    { BUTTON_CreateIndirect, "OFF", ID_BUTTON_OFF, 18, 130, 80, BUTHEIGHT, 0, 0x0, 0 },
    { BUTTON_CreateIndirect, "HEAT", ID_BUTTON_HEAT, 108, 130, 80, BUTHEIGHT, 0, 0x0, 0 },
    { BUTTON_CreateIndirect, "COOL", ID_BUTTON_COOL, 198, 130, 80, BUTHEIGHT, 0, 0x0, 0 },
    { BUTTON_CreateIndirect, "AUTO", ID_BUTTON_AUTO, 289, 130, 80, BUTHEIGHT, 0, 0x0, 0 },
    { BUTTON_CreateIndirect, "E-HEAT", ID_BUTTON_EHEAT, 380, 130, 80, BUTHEIGHT, 0, 0x0, 0 },
    { BUTTON_CreateIndirect, "CANCEL", ID_BUTTON_CANCEL, 20, 230, 80, BUTHEIGHT, 0, 0x0, 0 },
    { BUTTON_CreateIndirect, "DONE", ID_BUTTON_DONE, 375, 230, 80, BUTHEIGHT, 0, 0x0, 0 },
};

static int cool, heat, off, autob=1, eheat;

static void modeButton(WM_MESSAGE * pMsg, char *nm, int sel)
{
    switch (pMsg->MsgId)
    {
    case WM_PAINT:
        if (BUTTON_IsPressed(pMsg->hWin))
        {
            drawButton16(nm, 80, 30, sel, 1);
        }
        else
        {
            drawButton16(nm, 80, 30, sel, 0);
        }
        break;
    default:
        BUTTON_Callback(pMsg);
        break;
    }
}
static void eheat_cb(WM_MESSAGE * pMsg)
{
    modeButton(pMsg, "E-HEAT", eheat);
}

static void auto_cb(WM_MESSAGE * pMsg)
{
    modeButton(pMsg, "AUTO", autob);
}

static void cool_cb(WM_MESSAGE * pMsg)
{
    modeButton(pMsg, "COOL", cool);
}

static void heat_cb(WM_MESSAGE * pMsg)
{
    modeButton(pMsg, "HEAT", heat);
}

static void off_cb(WM_MESSAGE * pMsg)
{
    modeButton(pMsg, "OFF", off);
}

static void invalidateButtons(WM_HWIN hWin)
{
    WM_HWIN hItem;

    hItem = WM_GetDialogItem(hWin, ID_BUTTON_OFF);
    WM_InvalidateWindow(hItem);
    WM_SetCallback(hItem, off_cb);

    hItem = WM_GetDialogItem(hWin, ID_BUTTON_HEAT);
    WM_InvalidateWindow(hItem);
    WM_SetCallback(hItem, heat_cb);

    hItem = WM_GetDialogItem(hWin, ID_BUTTON_COOL);
    WM_InvalidateWindow(hItem);
    WM_SetCallback(hItem, cool_cb);

    hItem = WM_GetDialogItem(hWin, ID_BUTTON_AUTO);
    WM_InvalidateWindow(hItem);
    WM_SetCallback(hItem, auto_cb);

    hItem = WM_GetDialogItem(hWin, ID_BUTTON_EHEAT);
    WM_InvalidateWindow(hItem);
    WM_SetCallback(hItem, eheat_cb);
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
        TEXT_SetTextColor(hItem, 0x00FFFFFF);
        TEXT_SetTextAlign(hItem, GUI_TA_HCENTER | GUI_TA_VCENTER);
        TEXT_SetFont(hItem, GUI_FONT_32B_1);

        hItem = WM_GetDialogItem(pMsg->hWin, ID_BUTTON_OFF);
        WM_SetCallback(hItem, off_cb);
        //
        hItem = WM_GetDialogItem(pMsg->hWin, ID_BUTTON_HEAT);
        WM_SetCallback(hItem, heat_cb);
        //
        hItem = WM_GetDialogItem(pMsg->hWin, ID_BUTTON_COOL);
        WM_SetCallback(hItem, cool_cb);
        //
        hItem = WM_GetDialogItem(pMsg->hWin, ID_BUTTON_AUTO);
        WM_SetCallback(hItem, auto_cb);
        //
        hItem = WM_GetDialogItem(pMsg->hWin, ID_BUTTON_EHEAT);
        WM_SetCallback(hItem, eheat_cb);
        //
        hItem = WM_GetDialogItem(pMsg->hWin, ID_BUTTON_CANCEL);
        WM_SetCallback(hItem, buttonOn16_cb);
        //
        hItem = WM_GetDialogItem(pMsg->hWin, ID_BUTTON_DONE);
        WM_SetCallback(hItem, buttonOn16_cb);
        break;
    case WM_NOTIFY_PARENT:
        Id    = WM_GetId(pMsg->hWinSrc);
        NCode = pMsg->Data.v;
        switch(Id)
        {
        case ID_BUTTON_OFF:
            switch(NCode)
            {
            case WM_NOTIFICATION_CLICKED:
                hItem = WM_GetDialogItem(pMsg->hWin, ID_BUTTON_OFF);
                WM_SetCallback(hItem, buttonPush16_cb);
                break;
            case WM_NOTIFICATION_RELEASED:
                off = 1;
                autob = 0;
                cool = 0;
                heat = 0;
                eheat = 0;
                invalidateButtons( pMsg->hWin);
                break;
            }
            break;
        case ID_BUTTON_HEAT:
            switch(NCode)
            {
            case WM_NOTIFICATION_CLICKED:
                hItem = WM_GetDialogItem(pMsg->hWin, ID_BUTTON_HEAT);
                WM_SetCallback(hItem, buttonPush16_cb);
                break;
            case WM_NOTIFICATION_RELEASED:
                off = 0;
                autob = 0;
                cool = 0;
                heat = 1;
                eheat = 0;
                tempSetPoint = heatToDegrees;
                invalidateButtons( pMsg->hWin);
                break;
            }
            break;
        case ID_BUTTON_COOL:
            switch(NCode)
            {
            case WM_NOTIFICATION_CLICKED:
                hItem = WM_GetDialogItem(pMsg->hWin, ID_BUTTON_COOL);
                WM_SetCallback(hItem, buttonPush16_cb);
                break;
            case WM_NOTIFICATION_RELEASED:
                off = 0;
                autob = 0;
                cool = 1;
                heat = 0;
                eheat = 0;
                tempSetPoint = coolToDegrees;
                invalidateButtons( pMsg->hWin);
                break;
            }
            break;
        case ID_BUTTON_AUTO:
            switch(NCode)
            {
            case WM_NOTIFICATION_CLICKED:
                hItem = WM_GetDialogItem(pMsg->hWin, ID_BUTTON_AUTO);
                WM_SetCallback(hItem, buttonPush16_cb);
                break;
            case WM_NOTIFICATION_RELEASED:
                off = 0;
                autob = 1;
                cool = 0;
                heat = 0;
                eheat = 0;
                invalidateButtons( pMsg->hWin);
                break;
            }
            break;
        case ID_BUTTON_EHEAT:
            switch(NCode)
            {
            case WM_NOTIFICATION_CLICKED:
                hItem = WM_GetDialogItem(pMsg->hWin, ID_BUTTON_EHEAT);
                WM_SetCallback(hItem, buttonPush16_cb);
                break;
            case WM_NOTIFICATION_RELEASED:
                off = 0;
                autob = 0;
                cool = 0;
                heat = 0;
                eheat = 1;
                invalidateButtons( pMsg->hWin);
                break;
            }
            break;
        case ID_BUTTON_CANCEL:
            switch(NCode)
            {
            case WM_NOTIFICATION_RELEASED:
                state=1;
                break;
            }
            break;
        case ID_BUTTON_DONE:
            switch(NCode)
            {
            case WM_NOTIFICATION_RELEASED:
                if (off) strcpy(hvacMode, "off");
                if (autob)strcpy(hvacMode, "auto");
                if (cool) strcpy(hvacMode, "cool");
                if (heat) strcpy(hvacMode, "heat");
                if (eheat) strcpy(hvacMode, "eheat");
                state=1;
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
*       CreateMode
*/
WM_HWIN CreateMode(void);
WM_HWIN CreateMode(void)
{
    WM_HWIN hWin;
    off = 0;
    autob = 0;
    cool = 0;
    heat = 0;
    eheat = 0;

    if (strcmp(hvacMode, "off") == 0) off = 1;
    if (strcmp(hvacMode, "auto") == 0) autob = 1;
    if (strcmp(hvacMode, "heat") == 0) heat = 1;
    if (strcmp(hvacMode, "cool") == 0) cool = 1;
    if (strcmp(hvacMode, "eheat") == 0) eheat = 1;

    hWin = GUI_CreateDialogBox(_aDialogCreate, GUI_COUNTOF(_aDialogCreate), _cbDialog, WM_HBKWIN, 0, 0);
    return hWin;
}

/*************************** End of file ****************************/
