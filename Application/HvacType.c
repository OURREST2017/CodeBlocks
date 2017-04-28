#include "ranger.h"

#define ID_WINDOW_0 (GUI_ID_USER + 0x1A)
#define ID_BUTTON_FORCED_AIR (GUI_ID_USER + 0x1B)
#define ID_BUTTON_HEAT_PUMP (GUI_ID_USER + 0x1C)
#define ID_BUTTON_HOT_WATER (GUI_ID_USER + 0x1D)
#define ID_TEXT_HEADER (GUI_ID_USER + 0x1F)
#define ID_BUTTON_CANCEL (GUI_ID_USER + 0x20)
#define ID_BUTTON_SAVE (GUI_ID_USER + 0x21)
#define ID_BUTTON_NEXT (GUI_ID_USER + 0x30)
#define ID_BUTTON_BACK (GUI_ID_USER + 0x31)

static const GUI_WIDGET_CREATE_INFO _aDialogCreate[] =
{
    { WINDOW_CreateIndirect, "Window", ID_WINDOW_0, 0, 0, 480, 272, 0, 0x0, 0 },
    { TEXT_CreateIndirect, "SYSTEM TYPE", ID_TEXT_HEADER, 0, 0, 480, 50, 0, 0x64, 0 },
    { BUTTON_CreateIndirect, "FORCED AIR", ID_BUTTON_FORCED_AIR, 90, 75, 300, 36, 0, 0x0, 0 },
    { BUTTON_CreateIndirect, "HEAT PUMP", ID_BUTTON_HEAT_PUMP, 90, 125, 300, 36, 0, 0x0, 0 },
    { BUTTON_CreateIndirect, "HOT WATER OR STEAM", ID_BUTTON_HOT_WATER, 90, 175, 300, 36, 0, 0x0, 0 },
    { BUTTON_CreateIndirect, "CANCEL", ID_BUTTON_CANCEL, 20, 230, BUT_WIDTH, BUT_HEIGHT, 0, 0x0, 0 },
    { BUTTON_CreateIndirect, "SAVE", ID_BUTTON_SAVE, 350, 230, BUT_WIDTH, BUT_HEIGHT, 0, 0x0, 0 },
    { BUTTON_CreateIndirect, "BACK", ID_BUTTON_BACK, 20, 230, BUT_WIDTH, BUT_HEIGHT, 0, 0x0, 0 },
    { BUTTON_CreateIndirect, "NEXT", ID_BUTTON_NEXT, 350, 230, BUT_WIDTH, BUT_HEIGHT, 0, 0x0, 0 },
};

static int mode;

static WM_HWIN forcedAirButton, heatPumpButton, hotWaterButton, hvacTypeWin;
static WM_HWIN back, next;

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
        TEXT_SetTextAlign(hItem, GUI_TA_HCENTER | GUI_TA_VCENTER);
        TEXT_SetFont(hItem, HEADER_FONT_BOLD);
        TEXT_SetTextColor(hItem, GUI_MAKE_COLOR(0x00FFFFFF));
        TEXT_SetText(hItem, LANG("SYSTEM TYPE"));
        //
        forcedAirButton = WM_GetDialogItem(pMsg->hWin, ID_BUTTON_FORCED_AIR);
        //
        heatPumpButton = WM_GetDialogItem(pMsg->hWin, ID_BUTTON_HEAT_PUMP);
        //
        hotWaterButton = WM_GetDialogItem(pMsg->hWin, ID_BUTTON_HOT_WATER);
        //
        if (mode == 0)
        {
            WM_SetCallback(forcedAirButton, buttonOn22_cb);
            WM_SetCallback(heatPumpButton, buttonOff22_cb);
            WM_SetCallback(hotWaterButton, buttonOff22_cb);
        }
        else if (mode == 1)
        {
            WM_SetCallback(forcedAirButton, buttonOff22_cb);
            WM_SetCallback(heatPumpButton, buttonOn22_cb);
            WM_SetCallback(hotWaterButton, buttonOff22_cb);
        }
        else
        {
            WM_SetCallback(forcedAirButton, buttonOff22_cb);
            WM_SetCallback(heatPumpButton, buttonOff22_cb);
            WM_SetCallback(hotWaterButton, buttonOn22_cb);
        }

        hItem = WM_GetDialogItem(pMsg->hWin, ID_BUTTON_CANCEL);
        WM_SetCallback(hItem, buttonOn_cb);
        if (firstTime)
        {
            WM_HideWindow(hItem);
        } else {
            WM_ShowWindow(hItem);
        }
        //
        hItem = WM_GetDialogItem(pMsg->hWin, ID_BUTTON_SAVE);
        WM_SetCallback(hItem, buttonOn_cb);
        if (firstTime)
        {
            WM_HideWindow(hItem);
        } else {
            WM_ShowWindow(hItem);
        }

        next = WM_GetDialogItem(pMsg->hWin, ID_BUTTON_NEXT);
        WM_SetCallback(next, buttonOn_cb);

        back = WM_GetDialogItem(pMsg->hWin, ID_BUTTON_BACK);
        WM_SetCallback(back, buttonOn_cb);

        if (firstTime)
        {
            WM_ShowWindow(next);
            WM_ShowWindow(back);
        }
        else
        {
            WM_HideWindow(next);
            WM_HideWindow(back);
        }

        break;
    case WM_NOTIFY_PARENT:
        Id    = WM_GetId(pMsg->hWinSrc);
        NCode = pMsg->Data.v;
        switch(Id)
        {
        case ID_BUTTON_CANCEL:
        case ID_BUTTON_BACK:
            switch(NCode)
            {
            case WM_NOTIFICATION_RELEASED:
                GUI_Delay(100);
                WM_DeleteWindow(hvacTypeWin);
                if (firstTime)
                {
                    CreateThermostatControls();
                }
                else
                {
                    screenState = SYSTEMSETUPWIN;
                }
            }
            break;
        case ID_BUTTON_SAVE:
        case ID_BUTTON_NEXT:
            switch(NCode)
            {
            case WM_NOTIFICATION_RELEASED:
                GUI_Delay(100);
                WM_DeleteWindow(hvacTypeWin);
                if (mode == 0)
                {
                    strcpy(hvacType,"air");
                }
                else if (mode == 1)
                {
                    strcpy(hvacType,"heat");
                }
                else
                {
                    strcpy(hvacType,"water");
                }

                if (firstTime)
                {
                    CreateWifiConnect();
                }
                else
                {
                    screenState = SYSTEMSETUPWIN;
                }
            }
            break;
        case ID_BUTTON_FORCED_AIR:
            switch(NCode)
            {
            case WM_NOTIFICATION_RELEASED:
                mode = 0;
                WM_SetCallback(forcedAirButton, buttonOn22_cb);
                WM_SetCallback(heatPumpButton, buttonOff22_cb);
                WM_SetCallback(hotWaterButton, buttonOff22_cb);
                break;
            }
            break;
        case ID_BUTTON_HEAT_PUMP:
            switch(NCode)
            {
            case WM_NOTIFICATION_RELEASED:
                mode = 1;
                WM_SetCallback(forcedAirButton, buttonOff22_cb);
                WM_SetCallback(heatPumpButton, buttonOn22_cb);
                WM_SetCallback(hotWaterButton, buttonOff22_cb);
                break;
            }
            break;
        case ID_BUTTON_HOT_WATER:
            switch(NCode)
            {
            case WM_NOTIFICATION_RELEASED:
                mode = 2;
                WM_SetCallback(forcedAirButton, buttonOff22_cb);
                WM_SetCallback(heatPumpButton, buttonOff22_cb);
                WM_SetCallback(hotWaterButton, buttonOn22_cb);
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

WM_HWIN CreateHvacType(void);
WM_HWIN CreateHvacType(void)
{
    WM_HWIN hWin;

    if (strcmp(hvacType, "air") == 0)
    {
        mode = 0;
    }
    else if (strcmp(hvacType, "heat") == 0)
    {
        mode = 1;
    }
    else
    {
        mode = 2;
    }

    hvacTypeWin = GUI_CreateDialogBox(_aDialogCreate, GUI_COUNTOF(_aDialogCreate), _cbDialog, WM_HBKWIN, 0, 0);
    return hWin;
}
