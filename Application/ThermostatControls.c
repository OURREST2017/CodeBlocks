#include "ranger.h"

#define ID_WINDOW_0 (GUI_ID_USER + 0x02)
//#define ID_BUTTON_COOLING (GUI_ID_USER + 0x03)
//#define ID_BUTTON_HEATING (GUI_ID_USER + 0x04)
#define ID_BUTTON_CANCEL (GUI_ID_USER + 0x05)
#define ID_BUTTON_SAVE (GUI_ID_USER + 0x06)
#define ID_TEXT_HEADER (GUI_ID_USER + 0x08)

#define ID_TEXT_COOLING (GUI_ID_USER + 0x03)
#define ID_TEXT_HEATING (GUI_ID_USER + 0x04)
#define ID_CHECKBOX_COOL (GUI_ID_USER + 0x09)
#define ID_CHECKBOX_HEAT (GUI_ID_USER + 0x0A)
#define ID_BUTTON_NEXT (GUI_ID_USER + 0x10)
#define ID_BUTTON_BACK (GUI_ID_USER + 0x11)

static const GUI_WIDGET_CREATE_INFO _aDialogCreate[] =
{
    { WINDOW_CreateIndirect, "Window", ID_WINDOW_0, 0, 0, 480, 272, 0, 0x0, 0 },
    { TEXT_CreateIndirect, "THERMOSTAT CONTROLS", ID_TEXT_HEADER, 0, 0, 480, 50, 0, 0x64, 0 },
    { TEXT_CreateIndirect, "Cooling", ID_TEXT_COOLING, 210, 103, 200, 40, 0, 0x64, 0 },
    { TEXT_CreateIndirect, "Heating", ID_TEXT_HEATING, 210, 152, 200, 40, 0, 0x64, 0 },

    { BUTTON_CreateIndirect, "", ID_CHECKBOX_COOL, 160,103, 60, 60, 0, 0x0, 0 },
    { BUTTON_CreateIndirect, "", ID_CHECKBOX_HEAT, 160,152, 60, 60, 0, 0x0, 0 },

    { BUTTON_CreateIndirect, "BACK", ID_BUTTON_BACK, 20, 230, BUT_WIDTH, BUT_HEIGHT, 0, 0x0, 0 },
    { BUTTON_CreateIndirect, "CANCEL", ID_BUTTON_CANCEL, 20, 230, BUT_WIDTH, BUT_HEIGHT, 0, 0x0, 0 },
    { BUTTON_CreateIndirect, "NEXT", ID_BUTTON_NEXT, 350, 230, BUT_WIDTH, BUT_HEIGHT, 0, 0x0, 0 },
    { BUTTON_CreateIndirect, "SAVE", ID_BUTTON_SAVE, 350, 230, BUT_WIDTH, BUT_HEIGHT, 0, 0x0, 0 },
};

static int coolOn, heatOn;
static WM_HWIN cooling, heating, thermostatControlsWin;
static WM_HWIN coolBox, heatBox;
extern GUI_CONST_STORAGE GUI_BITMAP bmchecked36;
extern GUI_CONST_STORAGE GUI_BITMAP bmunchecked36;

static void cool_on_cb(WM_MESSAGE * pMsg)
{
    switch (pMsg->MsgId)
    {
    case WM_PAINT:
        GUI_DrawBitmap(&bmchecked36, 0, 0);
        break;
    default:
        BUTTON_Callback(pMsg);
        break;
    }
}

static void cool_off_cb(WM_MESSAGE * pMsg)
{
    switch (pMsg->MsgId)
    {
    case WM_PAINT:
        GUI_DrawBitmap(&bmunchecked36, 0, 0);
        break;
    default:
        BUTTON_Callback(pMsg);
        break;
    }
}
static void heat_on_cb(WM_MESSAGE * pMsg)
{
    switch (pMsg->MsgId)
    {
    case WM_PAINT:
        GUI_DrawBitmap(&bmchecked36, 0, 0);
        break;
    default:
        BUTTON_Callback(pMsg);
        break;
    }
}

static void heat_off_cb(WM_MESSAGE * pMsg)
{
    switch (pMsg->MsgId)
    {
    case WM_PAINT:
        GUI_DrawBitmap(&bmunchecked36, 0, 0);
        break;
    default:
        BUTTON_Callback(pMsg);
        break;
    }
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
        TEXT_SetFont(hItem, HEADER_FONT_BOLD);
        TEXT_SetTextAlign(hItem, GUI_TA_HCENTER | GUI_TA_VCENTER);
        TEXT_SetTextColor(hItem, GUI_MAKE_COLOR(0x00FFFFFF));
        TEXT_SetText(hItem, LANG("THERMOSTAT CONTROLS"));

        coolBox = WM_GetDialogItem(pMsg->hWin, ID_CHECKBOX_COOL);

        heatBox = WM_GetDialogItem(pMsg->hWin, ID_CHECKBOX_HEAT);

        cooling = WM_GetDialogItem(pMsg->hWin, ID_TEXT_COOLING);
        TEXT_SetFont(cooling, &GUI_FontTahoma29hAA4B);
        TEXT_SetTextAlign(cooling, GUI_TA_LEFT | GUI_TA_VCENTER);
        TEXT_SetTextColor(cooling, GUI_MAKE_COLOR(0x666666));
        TEXT_SetText(cooling, LANG("Cooling"));
        if (coolOn)
        {
            WM_SetCallback(coolBox, cool_on_cb);
        }
        else
        {
            WM_SetCallback(coolBox, cool_off_cb);
        }
        //
        heating = WM_GetDialogItem(pMsg->hWin, ID_TEXT_HEATING);
        TEXT_SetFont(heating, &GUI_FontTahoma29hAA4B);
        TEXT_SetTextAlign(heating, GUI_TA_LEFT | GUI_TA_VCENTER);
        TEXT_SetTextColor(heating, GUI_MAKE_COLOR(0x666666));
        TEXT_SetText(heating, LANG("Heating"));
        if (heatOn)
        {
            WM_SetCallback(heatBox, heat_on_cb);
        }
        else
        {
            WM_SetCallback(heatBox, heat_off_cb);
        }

        hItem = WM_GetDialogItem(pMsg->hWin, ID_BUTTON_CANCEL);
        WM_SetCallback(hItem, buttonOn_cb);
        if (!firstTime) {
            WM_ShowWindow(hItem);
        } else {
            WM_HideWindow(hItem);
        }

        hItem = WM_GetDialogItem(pMsg->hWin, ID_BUTTON_BACK);
        WM_SetCallback(hItem, buttonOn_cb);
        if (firstTime) {
            WM_ShowWindow(hItem);
        } else {
            WM_HideWindow(hItem);
        }
        //
        hItem = WM_GetDialogItem(pMsg->hWin, ID_BUTTON_NEXT);
        WM_SetCallback(hItem, buttonOn_cb);
        if (firstTime) {
            WM_ShowWindow(hItem);
        } else {
            WM_HideWindow(hItem);
        }

        hItem = WM_GetDialogItem(pMsg->hWin, ID_BUTTON_SAVE);
        WM_SetCallback(hItem, buttonOn_cb);
        if (!firstTime) {
            WM_ShowWindow(hItem);
        } else {
            WM_HideWindow(hItem);
        }
        //
        break;
    case WM_NOTIFY_PARENT:
        Id    = WM_GetId(pMsg->hWinSrc);
        NCode = pMsg->Data.v;
        int c,h;
        switch(Id)
        {
        case ID_TEXT_COOLING:
        case ID_CHECKBOX_COOL:
            switch(NCode)
            {
            case WM_NOTIFICATION_CLICKED:
                coolOn = !coolOn;
                if (coolOn)
                {
                    WM_SetCallback(coolBox, cool_on_cb);
                }
                else
                {
                    WM_SetCallback(coolBox, cool_off_cb);
                }
                break;
            }
            break;
        case ID_TEXT_HEATING:
        case ID_CHECKBOX_HEAT:
            switch(NCode)
            {
            case WM_NOTIFICATION_CLICKED:
                heatOn = !heatOn;
                if (heatOn)
                {
                    WM_SetCallback(heatBox, heat_on_cb);
                }
                else
                {
                    WM_SetCallback(heatBox, heat_off_cb);
                }
                break;
            }
            break;
        case ID_BUTTON_CANCEL:
        case ID_BUTTON_BACK:
            switch(NCode)
            {
            case WM_NOTIFICATION_RELEASED:
                WM_DeleteWindow(thermostatControlsWin);
                GUI_Delay(100);
                if (firstTime) {
                    CreateThermostatLocations();
                } else {
                    screenState = SYSTEMSETUPWIN;
                }
            }
            break;
        case ID_BUTTON_SAVE:
        case ID_BUTTON_NEXT:
            switch(NCode)
            {
            case WM_NOTIFICATION_RELEASED:
                if (coolOn == 0 && heatOn == 0) thermostatControls = 0;
                if (coolOn == 1 && heatOn == 0) thermostatControls = 1;
                if (coolOn == 0 && heatOn == 1) thermostatControls = 2;
                if (coolOn == 1 && heatOn == 1) thermostatControls = 3;

                WM_DeleteWindow(thermostatControlsWin);
                GUI_Delay(100);
                if (firstTime) {
                    CreateHvacType();
                } else {
                    screenState = SYSTEMSETUPWIN;
                }
            }
            break;
        }
        break;
    default:
        WM_DefaultProc(pMsg);
        break;
    }
}

WM_HWIN CreateThermostatControls(void);
WM_HWIN CreateThermostatControls(void)
{
    WM_HWIN hWin;
    coolOn = heatOn = 0;
    if (thermostatControls == 1) coolOn = 1;
    if (thermostatControls == 2) heatOn = 1;
    if (thermostatControls == 3) coolOn = heatOn = 1;

    thermostatControlsWin = GUI_CreateDialogBox(_aDialogCreate, GUI_COUNTOF(_aDialogCreate), _cbDialog, WM_HBKWIN, 0, 0);
    return hWin;
}
