#include "ranger.h"

#define ID_WINDOW_0 (GUI_ID_USER + 0x02)
#define ID_BUTTON_CANCEL (GUI_ID_USER + 0x05)
#define ID_BUTTON_SAVE (GUI_ID_USER + 0x06)
#define ID_TEXT_HEADER (GUI_ID_USER + 0x08)
#define ID_TEXT_UPPER (GUI_ID_USER + 0x09)
#define ID_TEXT_LOWER (GUI_ID_USER + 0x0A)
#define ID_BUTTON_LOWER_UP  (GUI_ID_USER + 0x0B)
#define ID_BUTTON_LOWER_DN  (GUI_ID_USER + 0x0C)
#define ID_BUTTON_UPPER_UP  (GUI_ID_USER + 0x0D)
#define ID_BUTTON_UPPER_DN  (GUI_ID_USER + 0x0E)
#define ID_TEXT_LOWER_TXT  (GUI_ID_USER + 0x10)
#define ID_TEXT_UPPER_TXT  (GUI_ID_USER + 0x11)

/*********************************************************************
*
*       _aDialogCreate
*/
static const GUI_WIDGET_CREATE_INFO _aDialogCreate[] =
{
    { WINDOW_CreateIndirect, "Window", ID_WINDOW_0, 0, 0, 480, 272, 0, 0x0, 0 },
    { TEXT_CreateIndirect, "COOL TO SETTINGS", ID_TEXT_HEADER, 0, 0, 480, 50, 0, 0x64, 0 },
    { TEXT_CreateIndirect, "COOL\nTO", ID_TEXT_LOWER, 105, 110, 100, 80, 0, 0x64, 0 },
    { BUTTON_CreateIndirect, "Button", ID_BUTTON_LOWER_UP, 210, 66, 60, 60, 0, 0x0, 0 },
    { BUTTON_CreateIndirect, "Button", ID_BUTTON_LOWER_DN, 210, 192, 60, 60, 0, 0x0, 0 },
    { TEXT_CreateIndirect, "", ID_TEXT_LOWER_TXT, 186, 110, 94, 80, 0, 0x64, 0 },

    { BUTTON_CreateIndirect, "CANCEL", ID_BUTTON_CANCEL, 20, 230, 80, BUTHEIGHT, 0, 0x0, 0 },
    { BUTTON_CreateIndirect, "SAVE", ID_BUTTON_SAVE, 375, 230, 80, BUTHEIGHT, 0, 0x0, 0 },
};

static WM_HWIN upLowerButton, dnLowerButton;
static int lowerDegree;

extern GUI_CONST_STORAGE GUI_BITMAP bmup_s_lg;
extern GUI_CONST_STORAGE GUI_BITMAP bmdn_s_lg;

extern GUI_CONST_STORAGE GUI_BITMAP bmbut_up_blue;
extern GUI_CONST_STORAGE GUI_BITMAP bmbut_dn_blue;

static void up_cool(WM_MESSAGE * pMsg)
{
    switch (pMsg->MsgId)
    {
    case WM_PAINT:
        if (BUTTON_IsPressed(pMsg->hWin))
        {
            GUI_DrawBitmap(&bmbut_up_blue, 0, 0);
        }
        else
        {
            GUI_DrawBitmap(&bmbut_up_blue, 0, 0);
        }
        break;
    default:
        BUTTON_Callback(pMsg);
        break;
    }
}

static void dn_cool(WM_MESSAGE * pMsg)
{
    switch (pMsg->MsgId)
    {
    case WM_PAINT:
        if (BUTTON_IsPressed(pMsg->hWin))
        {
            GUI_DrawBitmap(&bmbut_dn_blue, 0, 0);
        }
        else
        {
            GUI_DrawBitmap(&bmbut_dn_blue, 0, 0);
        }
        break;
    default:
        BUTTON_Callback(pMsg);
        break;
    }
}

static void text_box_cb(WM_MESSAGE * pMsg)
{
    char buf[50];
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
        GUI_SetFont(&GUI_FontTahoma87hAA4B);
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
    WM_HWIN hItem, spinWheel;
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
        //
        hItem = WM_GetDialogItem(pMsg->hWin, ID_TEXT_HEADER);
        TEXT_SetFont(hItem, HEADER_FONT_BOLD);
        TEXT_SetTextAlign(hItem, GUI_TA_HCENTER | GUI_TA_VCENTER);
        TEXT_SetTextColor(hItem, GUI_MAKE_COLOR(0x00FFFFFF));

        hItem = WM_GetDialogItem(pMsg->hWin, ID_TEXT_LOWER);
        TEXT_SetTextColor(hItem, 0x7a5114);
        TEXT_SetTextAlign(hItem, GUI_TA_HCENTER | GUI_TA_VCENTER);
        TEXT_SetFont(hItem, &GUI_FontRounded22);

        hItem = WM_GetDialogItem(pMsg->hWin, ID_BUTTON_LOWER_UP);
        WM_SetCallback(hItem, up_cool);
        //
        hItem = WM_GetDialogItem(pMsg->hWin, ID_BUTTON_LOWER_DN);
        WM_SetCallback(hItem, dn_cool);
        //
        sprintf(buf, "%d", lowerDegree);
        hItem = WM_GetDialogItem(pMsg->hWin, ID_TEXT_LOWER_TXT);
        TEXT_SetText(hItem, buf);
        WM_SetCallback(hItem, text_box_cb);
        //
        hItem = WM_GetDialogItem(pMsg->hWin, ID_BUTTON_CANCEL);
        WM_SetCallback(hItem, buttonOn16_cb);
        //
        hItem = WM_GetDialogItem(pMsg->hWin, ID_BUTTON_SAVE);
        WM_SetCallback(hItem, buttonOn16_cb);
        break;
    case WM_NOTIFY_PARENT:
        Id    = WM_GetId(pMsg->hWinSrc);
        NCode = pMsg->Data.v;
        switch(Id)
        {
         case ID_BUTTON_LOWER_UP:
            switch(NCode)
            {
            case WM_NOTIFICATION_RELEASED:
            	lowerDegree++;
                if (lowerDegree == 86) lowerDegree = 85;
                sprintf(buf, "%d", lowerDegree);
                hItem = WM_GetDialogItem(pMsg->hWin, ID_TEXT_LOWER_TXT);
                TEXT_SetText(hItem, buf);
                break;
            }
            break;
        case ID_BUTTON_LOWER_DN:
            switch(NCode)
            {
            case WM_NOTIFICATION_RELEASED:
                lowerDegree--;
                if (lowerDegree == 64) lowerDegree = 65;
                sprintf(buf, "%d", lowerDegree);
                hItem = WM_GetDialogItem(pMsg->hWin, ID_TEXT_LOWER_TXT);
                TEXT_SetText(hItem, buf);
                break;
            }
            break;
       case ID_BUTTON_CANCEL:
            switch(NCode)
            {
            case WM_NOTIFICATION_RELEASED:
                GUI_Delay(100);
                WM_HideWindow(coolToWin);
                screenState = 1;
                break;
            }
            break;
        case ID_BUTTON_SAVE:
            switch(NCode)
            {
            case WM_NOTIFICATION_RELEASED:
                lowerDegreeLimit = lowerDegree;
                GUI_Delay(100);
                WM_HideWindow(coolToWin);
                screenState = 1;
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
WM_HWIN CreateCoolTo(void);
WM_HWIN CreateCoolTo(void)
{
    WM_HWIN hWin;

    lowerDegree = lowerDegreeLimit;
    coolToWin = GUI_CreateDialogBox(_aDialogCreate, GUI_COUNTOF(_aDialogCreate), _cbDialog, WM_HBKWIN, 0, 0);
    return hWin;
}

/*************************** End of file ****************************/