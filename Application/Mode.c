/*********************************************************************
*                                                                    *
*                SEGGER Microcontroller GmbH & Co. KG                *
*        Solutions for real time microcontroller applications        *
*                                                                    *
**********************************************************************
*                                                                    *
* C-file generated by:                                               *
*                                                                    *
*        GUI_Builder for emWin version 5.28                          *
*        Compiled Jan 30 2015, 16:41:06                              *
*        (c) 2015 Segger Microcontroller GmbH & Co. KG               *
*                                                                    *
**********************************************************************
*                                                                    *
*        Internet: www.segger.com  Support: support@segger.com       *
*                                                                    *
**********************************************************************
*/

#include "main.h"

#define ID_WINDOW_0  (GUI_ID_USER + 0x00)
#define ID_BUTTON_OFF  (GUI_ID_USER + 0x01)
#define ID_BUTTON_HEAT  (GUI_ID_USER + 0x02)
#define ID_BUTTON_COOL  (GUI_ID_USER + 0x03)
#define ID_BUTTON_AUTO  (GUI_ID_USER + 0x04)
#define ID_BUTTON_EHEAT  (GUI_ID_USER + 0x05)
#define ID_BUTTON_CANCEL  (GUI_ID_USER + 0x06)
#define ID_BUTTON_DONE  (GUI_ID_USER + 0x07)
#define ID_HEADER_0  (GUI_ID_USER + 0x08)
#define ID_TEXT_HEADER  (GUI_ID_USER + 0x09)

/*********************************************************************
*
*       _aDialogCreate
*/
static const GUI_WIDGET_CREATE_INFO _aDialogCreate[] =
{
    { WINDOW_CreateIndirect, "Mode", ID_WINDOW_0, 0, 0, 480, 272, 0, 0x0, 0 },
    { BUTTON_CreateIndirect, "OFF", ID_BUTTON_OFF, 18, 130, 80, 30, 0, 0x0, 0 },
    { BUTTON_CreateIndirect, "HEAT", ID_BUTTON_HEAT, 108, 130, 80, 30, 0, 0x0, 0 },
    { BUTTON_CreateIndirect, "COOL", ID_BUTTON_COOL, 198, 130, 80, 30, 0, 0x0, 0 },
    { BUTTON_CreateIndirect, "AUTO", ID_BUTTON_AUTO, 289, 130, 80, 30, 0, 0x0, 0 },
    { BUTTON_CreateIndirect, "E-HEAT", ID_BUTTON_EHEAT, 380, 130, 80, 30, 0, 0x0, 0 },
    { BUTTON_CreateIndirect, "CANCEL", ID_BUTTON_CANCEL, 20, 230, 80, 25, 0, 0x0, 0 },
    { BUTTON_CreateIndirect, "DONE", ID_BUTTON_DONE, 380, 230, 80, 25, 0, 0x0, 0 },
    { HEADER_CreateIndirect, "Header", ID_HEADER_0, 0, 0, 480, 50, 0, 0x0, 0 },
    { TEXT_CreateIndirect, "SELECT MODE", ID_TEXT_HEADER, 0, 0, 480, 50, 0, 0x64, 0 },
};

static int cool, heat, off, autob=1, eheat;
static void eheat_cb(WM_MESSAGE * pMsg)
{
    switch (pMsg->MsgId)
    {
    case WM_PAINT:
        drawButton16("E-HEAT", 80, 30, eheat);
        break;
    default:
        BUTTON_Callback(pMsg);
        break;
    }
}
static void auto_cb(WM_MESSAGE * pMsg)
{
    switch (pMsg->MsgId)
    {
    case WM_PAINT:
        drawButton16("AUTO", 80, 30, autob);
        break;
    default:
        BUTTON_Callback(pMsg);
        break;
    }
}
static void cool_cb(WM_MESSAGE * pMsg)
{
    switch (pMsg->MsgId)
    {
    case WM_PAINT:
        drawButton16("COOL", 80, 30, cool);
        break;
    default:
        BUTTON_Callback(pMsg);
        break;
    }
}
static void heat_cb(WM_MESSAGE * pMsg)
{
    switch (pMsg->MsgId)
    {
    case WM_PAINT:
        drawButton16("HEAT", 80, 30, heat);
        break;
    default:
        BUTTON_Callback(pMsg);
        break;
    }
}
static void off_cb(WM_MESSAGE * pMsg)
{
    switch (pMsg->MsgId)
    {
    case WM_PAINT:
        drawButton16("OFF", 80, 30, off);
        break;
    default:
        BUTTON_Callback(pMsg);
        break;
    }
}
static WM_HWIN cool_but, heat_but, auto_but, off_but, eheat_but;
/*********************************************************************
*
*       _cbDialog
*/
static WM_HWIN cool_but, heat_but, off_but, auto_but, eheat_but;

static void _cbDialog(WM_MESSAGE * pMsg)
{
    WM_HWIN hItem;
    int     NCode;
    int     Id;

    switch (pMsg->MsgId)
    {
    case WM_INIT_DIALOG:
        //
        off_but = WM_GetDialogItem(pMsg->hWin, ID_BUTTON_OFF);
        WM_SetCallback(off_but, off_cb);
        //
        heat_but = WM_GetDialogItem(pMsg->hWin, ID_BUTTON_HEAT);
        WM_SetCallback(heat_but, heat_cb);
        //
        cool_but = WM_GetDialogItem(pMsg->hWin, ID_BUTTON_COOL);
        WM_SetCallback(cool_but, cool_cb);
        //
        auto_but = WM_GetDialogItem(pMsg->hWin, ID_BUTTON_AUTO);
        WM_SetCallback(auto_but, auto_cb);
        //
        eheat_but = WM_GetDialogItem(pMsg->hWin, ID_BUTTON_EHEAT);
        WM_SetCallback(eheat_but, eheat_cb);
        //
        hItem = WM_GetDialogItem(pMsg->hWin, ID_BUTTON_CANCEL);
        WM_SetCallback(hItem, cancel_cb);
        //
        hItem = WM_GetDialogItem(pMsg->hWin, ID_BUTTON_DONE);
        WM_SetCallback(hItem, done_cb);
        //
        hItem = WM_GetDialogItem(pMsg->hWin, ID_TEXT_HEADER);
        TEXT_SetTextColor(hItem, 0x00FFFFFF);
        TEXT_SetTextAlign(hItem, GUI_TA_HCENTER | GUI_TA_VCENTER);
        TEXT_SetFont(hItem, GUI_FONT_32B_1);
        break;
    case WM_NOTIFY_PARENT:
        Id    = WM_GetId(pMsg->hWinSrc);
        NCode = pMsg->Data.v;
        GUI_RECT rect;
        rect.x0 = 0;
        rect.y0 = 60;
        rect.x1 = 480;
        rect.y1 = 200;
        switch(Id)
        {
        case ID_BUTTON_OFF:
            switch(NCode)
            {
            case WM_NOTIFICATION_RELEASED:
                off = 1;
                autob = 0;
                cool = 0;
                heat = 0;
                eheat = 0;
                WM_InvalidateArea(&rect);
                break;
            }
            break;
        case ID_BUTTON_HEAT:
            switch(NCode)
            {
            case WM_NOTIFICATION_RELEASED:
                off = 0;
                autob = 0;
                cool = 0;
                heat = 1;
                eheat = 0;
                WM_InvalidateArea(&rect);
                break;
            }
            break;
        case ID_BUTTON_COOL:
            switch(NCode)
            {
            case WM_NOTIFICATION_RELEASED:
                off = 0;
                autob = 0;
                cool = 1;
                heat = 0;
                eheat = 0;
                WM_InvalidateArea(&rect);
                break;
            }
            break;
        case ID_BUTTON_AUTO:
            switch(NCode)
            {
            case WM_NOTIFICATION_RELEASED:
                off = 0;
                autob = 1;
                cool = 0;
                heat = 0;
                eheat = 0;
                WM_InvalidateArea(&rect);
                break;
            }
            break;
        case ID_BUTTON_EHEAT:
            switch(NCode)
            {
            case WM_NOTIFICATION_RELEASED:
                off = 0;
                autob = 0;
                cool = 0;
                heat = 0;
                eheat = 1;
                WM_InvalidateArea(&rect);
                break;
            }
            break;
        case ID_BUTTON_CANCEL:
            switch(NCode)
            {
            case WM_NOTIFICATION_RELEASED:
                GUI_Delay(100);
                state=1;
                break;
            }
            break;
        case ID_BUTTON_DONE: // Notifications sent by 'Button'
            switch(NCode)
            {
            case WM_NOTIFICATION_RELEASED:
                GUI_Delay(100);
                if (off) strcpy(selectedMode, "off");
                if (autob)strcpy(selectedMode, "auto");
                if (cool) strcpy(selectedMode, "cool");
                if (heat) strcpy(selectedMode, "heat");
                if (eheat) strcpy(selectedMode, "eheat");
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

    if (strcmp(selectedMode, "off") == 0) off = 1;
    if (strcmp(selectedMode, "auto") == 0) autob = 1;
    if (strcmp(selectedMode, "heat") == 0) heat = 1;
    if (strcmp(selectedMode, "cool") == 0) cool = 1;
    if (strcmp(selectedMode, "eheat") == 0) eheat = 1;

    hWin = GUI_CreateDialogBox(_aDialogCreate, GUI_COUNTOF(_aDialogCreate), _cbDialog, WM_HBKWIN, 0, 0);
    return hWin;
}

/*************************** End of file ****************************/
