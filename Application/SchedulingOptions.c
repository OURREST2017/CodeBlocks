#include "ranger.h"

#define ID_WINDOW_0 (GUI_ID_USER + 0x02)
#define ID_BUTTON_CANCEL (GUI_ID_USER + 0x05)
#define ID_BUTTON_SAVE (GUI_ID_USER + 0x06)
#define ID_TEXT_HEADER (GUI_ID_USER + 0x08)
#define ID_BUTTON_PROGRAMMABLE (GUI_ID_USER + 0x0E)
#define ID_BUTTON_NON_PROGRAMMABLE (GUI_ID_USER + 0x0F)

/*********************************************************************
*
*       _aDialogCreate
*/
static const GUI_WIDGET_CREATE_INFO _aDialogCreate[] =
{
    { WINDOW_CreateIndirect, "Window", ID_WINDOW_0, 0, 0, 480, 272, 0, 0x0, 0 },
    { BUTTON_CreateIndirect, "CANCEL", ID_BUTTON_CANCEL, 20, 230, 80, 28, 0, 0x0, 0 },
    { BUTTON_CreateIndirect, "SAVE", ID_BUTTON_SAVE, 375, 230, 80, 28, 0, 0x0, 0 },
    { TEXT_CreateIndirect, "SCHEDULING OPTIONS", ID_TEXT_HEADER, 0, 0, 480, 50, 0, 0x64, 0 },
    { BUTTON_CreateIndirect, "Programmable", ID_BUTTON_PROGRAMMABLE, 120, 90, 240, 40, 0, 0x0, 0 },
    { BUTTON_CreateIndirect, "Non-Programmable", ID_BUTTON_NON_PROGRAMMABLE, 120, 145, 240, 40, 0, 0x0, 0 },
};

static int prog_mode;

/*********************************************************************
*
*       _cbDialog
*/
static WM_HWIN progButton, noProgButton;
static void _cbDialog(WM_MESSAGE * pMsg)
{
    WM_HWIN hItem;
    int     NCode;
    int     Id;

    switch (pMsg->MsgId)
    {
    case WM_PAINT:
        GUI_DrawGradientV(0, 0, 480, 50, 0x63b39b, 0x48866c);
        GUI_DrawBitmap(&bmwatermark,45,52);
        break;
    case WM_INIT_DIALOG:
        //
        hItem = WM_GetDialogItem(pMsg->hWin, ID_TEXT_HEADER);
        TEXT_SetFont(hItem, GUI_FONT_32B_1);
        TEXT_SetTextAlign(hItem, GUI_TA_HCENTER | GUI_TA_VCENTER);
        TEXT_SetTextColor(hItem, GUI_MAKE_COLOR(0x00FFFFFF));
        //
        progButton = WM_GetDialogItem(pMsg->hWin, ID_BUTTON_PROGRAMMABLE);
        //
        noProgButton = WM_GetDialogItem(pMsg->hWin, ID_BUTTON_NON_PROGRAMMABLE);
        if (prog_mode)
        {
            WM_SetCallback(progButton, buttonOn22_cb);
            WM_SetCallback(noProgButton, buttonOff22_cb);
        }
        else
        {
            WM_SetCallback(noProgButton, buttonOn22_cb);
            WM_SetCallback(progButton, buttonOff22_cb);
        }

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
        case ID_BUTTON_CANCEL:
            switch(NCode)
            {
            case WM_NOTIFICATION_RELEASED:
                GUI_Delay(100);
                CreatePreferences();
                //state = 16;
                break;
            }
            break;
        case ID_BUTTON_SAVE:
            switch(NCode)
            {
            case WM_NOTIFICATION_RELEASED:
                if (prog_mode)
                {
                    strcpy(schedulingOption, "programmable");
                }
                else
                {
                    strcpy(schedulingOption, "non-programmable");
                }
                GUI_Delay(100);
                CreatePreferences();
                //state = 16;
                break;
            }
            break;
        case ID_BUTTON_PROGRAMMABLE:
            switch(NCode)
            {
            case WM_NOTIFICATION_CLICKED:
                prog_mode = 1;
                WM_SetCallback(progButton, buttonOn22_cb);
                WM_SetCallback(noProgButton, buttonOff22_cb);
                break;
            }
            break;
        case ID_BUTTON_NON_PROGRAMMABLE:
            switch(NCode)
            {
            case WM_NOTIFICATION_CLICKED:
                prog_mode = 0;
                WM_SetCallback(noProgButton, buttonOn22_cb);
                WM_SetCallback(progButton, buttonOff22_cb);
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
WM_HWIN CreateSchedulingOptions(void);
WM_HWIN CreateSchedulingOptions(void)
{
    WM_HWIN hWin;
    if (strcmp(schedulingOption, "programmable") == 0)
    {
        prog_mode = 1;
    }
    else
    {
        prog_mode = 0;
    }

    hWin = GUI_CreateDialogBox(_aDialogCreate, GUI_COUNTOF(_aDialogCreate), _cbDialog, WM_HBKWIN, 0, 0);
    return hWin;
}

/*************************** End of file ****************************/
