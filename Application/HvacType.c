#include "ranger.h"

#define ID_WINDOW_0 (GUI_ID_USER + 0x1A)
#define ID_BUTTON_FORCED_AIR (GUI_ID_USER + 0x1B)
#define ID_BUTTON_HEAT_PUMP (GUI_ID_USER + 0x1C)
#define ID_BUTTON_HOT_WATER (GUI_ID_USER + 0x1D)
#define ID_TEXT_HEADER (GUI_ID_USER + 0x1F)
#define ID_BUTTON_CANCEL (GUI_ID_USER + 0x20)
#define ID_BUTTON_SAVE (GUI_ID_USER + 0x21)

/*********************************************************************
*
*       _aDialogCreate
*/
static const GUI_WIDGET_CREATE_INFO _aDialogCreate[] =
{
    { WINDOW_CreateIndirect, "Window", ID_WINDOW_0, 0, 0, 480, 272, 0, 0x0, 0 },
    { BUTTON_CreateIndirect, "FORCED AIR", ID_BUTTON_FORCED_AIR, 90, 75, 300, 36, 0, 0x0, 0 },
    { BUTTON_CreateIndirect, "HEAT PUMP", ID_BUTTON_HEAT_PUMP, 90, 125, 300, 36, 0, 0x0, 0 },
    { BUTTON_CreateIndirect, "HOT WATER OR STEAM", ID_BUTTON_HOT_WATER, 90, 175, 300, 36, 0, 0x0, 0 },
    { TEXT_CreateIndirect, "SYSTEM TYPE", ID_TEXT_HEADER, 0, 0, 480, 50, 0, 0x64, 0 },
    { BUTTON_CreateIndirect, "CANCEL", ID_BUTTON_CANCEL, 20, 230, 80, BUTHEIGHT, 0, 0x0, 0 },
    { BUTTON_CreateIndirect, "SAVE", ID_BUTTON_SAVE, 375, 230, 80, BUTHEIGHT, 0, 0x0, 0 },
};

static int forcedAir_mode, heatPump_mode, hotWater_mode;

static WM_HWIN forcedAirButton, heatPumpButton, hotWaterButton;

/*********************************************************************
*
*       _cbDialog
*/
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
        TEXT_SetFont(hItem, GUI_FONT_32B_1);
        TEXT_SetTextColor(hItem, GUI_MAKE_COLOR(0x00FFFFFF));
        //
        forcedAirButton = WM_GetDialogItem(pMsg->hWin, ID_BUTTON_FORCED_AIR);
        //
        heatPumpButton = WM_GetDialogItem(pMsg->hWin, ID_BUTTON_HEAT_PUMP);
        //
        hotWaterButton = WM_GetDialogItem(pMsg->hWin, ID_BUTTON_HOT_WATER);
        //
        if (forcedAir_mode)
        {
            WM_SetCallback(forcedAirButton, buttonOn22_cb);
            WM_SetCallback(heatPumpButton, buttonOff22_cb);
            WM_SetCallback(hotWaterButton, buttonOff22_cb);
        }
        else if (heatPump_mode)
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
        WM_SetCallback(hItem, buttonOn16_cb);
        if (firstTime)
        {
            BUTTON_SetText(hItem, "BACK");
        }
        else
        {
            BUTTON_SetText(hItem, "CANCEL");
        }
        //
        hItem = WM_GetDialogItem(pMsg->hWin, ID_BUTTON_SAVE);
        WM_SetCallback(hItem, buttonOn16_cb);
        if (firstTime)
        {
            BUTTON_SetText(hItem, "NEXT");
        }
        else
        {
            BUTTON_SetText(hItem, "SAVE");
        }

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
                if (firstTime)
                {
                    CreateThermostatLocations();
                }
                else
                {
                    CreateSystemSetup();
                    //state=17;
                }
            }
            break;
        case ID_BUTTON_SAVE:
            switch(NCode)
            {
            case WM_NOTIFICATION_RELEASED:
                GUI_Delay(100);
                if (forcedAir_mode)
                {
                    strcpy(hvacType,"air");
                }
                else if (heatPump_mode)
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
                    CreateSystemSetup();
                    //state=17;
                }
            }
            break;
        case ID_BUTTON_HOT_WATER:
            switch(NCode)
            {
            case WM_NOTIFICATION_RELEASED:
                forcedAir_mode = 0;
                heatPump_mode = 0;
                hotWater_mode = 1;

                WM_SetCallback(forcedAirButton, buttonOff22_cb);
                WM_SetCallback(heatPumpButton, buttonOff22_cb);
                WM_SetCallback(hotWaterButton, buttonOn22_cb);
                break;
            }
            break;
        case ID_BUTTON_FORCED_AIR:
            switch(NCode)
            {
            case WM_NOTIFICATION_RELEASED:
                forcedAir_mode = 1;
                heatPump_mode = 0;
                hotWater_mode = 0;

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
                forcedAir_mode = 0;
                heatPump_mode = 1;
                hotWater_mode = 0;

                WM_SetCallback(forcedAirButton, buttonOff22_cb);
                WM_SetCallback(heatPumpButton, buttonOn22_cb);
                WM_SetCallback(hotWaterButton, buttonOff22_cb);
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
WM_HWIN CreateHvacType(void);
WM_HWIN CreateHvacType(void)
{
    WM_HWIN hWin;

    if (strcmp(hvacType, "heat") == 0)
    {
        forcedAir_mode = 0;
        hotWater_mode = 0;
        heatPump_mode = 1;
    }
    else if (strcmp(hvacType, "air") == 0)
    {
        forcedAir_mode = 1;
        hotWater_mode = 0;
        heatPump_mode = 0;
    }
    else
    {
        forcedAir_mode = 0;
        hotWater_mode = 1;
        heatPump_mode = 0;
    }

    hWin = GUI_CreateDialogBox(_aDialogCreate, GUI_COUNTOF(_aDialogCreate), _cbDialog, WM_HBKWIN, 0, 0);
    return hWin;
}

/*************************** End of file ****************************/
