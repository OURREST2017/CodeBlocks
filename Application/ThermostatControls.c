#include "ranger.h"

#define ID_WINDOW_0 (GUI_ID_USER + 0x02)
#define ID_CHECKBOX_COOLING (GUI_ID_USER + 0x03)
#define ID_CHECKBOX_HEATING (GUI_ID_USER + 0x04)
#define ID_BUTTON_CANCEL (GUI_ID_USER + 0x05)
#define ID_BUTTON_SAVE (GUI_ID_USER + 0x06)
#define ID_TEXT_HEADER (GUI_ID_USER + 0x08)

/*********************************************************************
*
*       _aDialogCreate
*/
static const GUI_WIDGET_CREATE_INFO _aDialogCreate[] =
{
    { WINDOW_CreateIndirect, "Window", ID_WINDOW_0, 0, 0, 480, 272, 0, 0x0, 0 },
    { CHECKBOX_CreateIndirect, "Cooling", ID_CHECKBOX_COOLING, 175, 103, 160, 32, 0, 0x0, 0 },
    { CHECKBOX_CreateIndirect, "Heating", ID_CHECKBOX_HEATING, 175, 152, 160, 32, 0, 0x0, 0 },
    { BUTTON_CreateIndirect, "CANCEL", ID_BUTTON_CANCEL, 20, 230, 80, 30, 0, 0x0, 0 },
    { BUTTON_CreateIndirect, "SAVE", ID_BUTTON_SAVE, 380, 230, 80, 30, 0, 0x0, 0 },
    { TEXT_CreateIndirect, "THERMOSTAT CONTROLS", ID_TEXT_HEADER, 0, 0, 480, 50, 0, 0x64, 0 },
};

static int thermo_controls;
static WM_HWIN cooling, heating;

static int checkBoxSkin(const WIDGET_ITEM_DRAW_INFO * pDrawItemInfo)
{
    char buf[20];
    switch (pDrawItemInfo->Cmd)
    {
    case WIDGET_ITEM_DRAW_TEXT:
        CHECKBOX_GetText(pDrawItemInfo->hWin, buf, 20);;
        GUI_SetColor(0x569e85);
        GUI_FillRoundedRect(36,1,140,30,3);
        GUI_SetColor(GUI_WHITE);
        GUI_SetTextMode(GUI_TEXTMODE_TRANS);
        GUI_SetFont(&GUI_FontRounded22);
        GUI_DispStringAt(buf,42,4);
        break;
    default:
        return CHECKBOX_DrawSkinFlex(pDrawItemInfo);
    }
}

static int buttonSkin(const WIDGET_ITEM_DRAW_INFO * pDrawItemInfo)
{
    char buf[20];
    switch (pDrawItemInfo->Cmd)
    {
    case WIDGET_ITEM_DRAW_BACKGROUND:
        GUI_SetColor(GUI_RED);
        GUI_FillRoundedRect(0,0,80,28,3);
        break;
    case WIDGET_ITEM_DRAW_TEXT:
        BUTTON_GetText(pDrawItemInfo->hWin, buf, 20);;
        GUI_SetColor(GUI_WHITE);
        GUI_SetTextMode(GUI_TEXTMODE_TRANS);
        GUI_SetFont(&GUI_FontRounded16);
        GUI_DispStringAt(buf,3,4);
        break;
    default:
        return BUTTON_DrawSkinFlex(pDrawItemInfo);
    }
}

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
        GUI_DrawGradientV(0, 0, 480, 50, 0x63b39b, 0x48866c);
        GUI_DrawBitmap(&bmwatermark,45,52);
        break;
    case WM_INIT_DIALOG:
        hItem = WM_GetDialogItem(pMsg->hWin, ID_TEXT_HEADER);
        TEXT_SetFont(hItem, GUI_FONT_32B_ASCII);
        TEXT_SetTextAlign(hItem, GUI_TA_HCENTER | GUI_TA_VCENTER);
        TEXT_SetTextColor(hItem, GUI_MAKE_COLOR(0x00FFFFFF));

        cooling = WM_GetDialogItem(pMsg->hWin, ID_CHECKBOX_COOLING);
        CHECKBOX_SetFont(cooling, &GUI_FontRounded22);
        CHECKBOX_SetTextColor(cooling, 0x48866c);
        CHECKBOX_SetText(cooling, "Cooling");
        CHECKBOX_SetSpacing(cooling, 10);
        CHECKBOX_SetSkin(cooling, checkBoxSkin);

        heating = WM_GetDialogItem(pMsg->hWin, ID_CHECKBOX_HEATING);
        CHECKBOX_SetFont(heating, &GUI_FontRounded22);
        CHECKBOX_SetTextColor(heating, 0x48866c);
        CHECKBOX_SetText(heating, "Heating");
        CHECKBOX_SetSpacing(heating, 10);
        CHECKBOX_SetSkin(heating, checkBoxSkin);

        if (thermo_controls == 0)
        {
            CHECKBOX_SetState(cooling, 0);
            CHECKBOX_SetState(heating, 0);
        }
        else if (thermo_controls == 1)
        {
            CHECKBOX_SetState(cooling, 1);
            CHECKBOX_SetState(heating, 0);
        }
        else if (thermo_controls == 2)
        {
            CHECKBOX_SetState(cooling, 0);
            CHECKBOX_SetState(heating, 1);
        }
        else
        {
            CHECKBOX_SetState(cooling, 1);
            CHECKBOX_SetState(heating, 1);
        }

        hItem = WM_GetDialogItem(pMsg->hWin, ID_BUTTON_CANCEL);
//        BUTTON_SetSkin(hItem, buttonSkin);
        WM_SetCallback(hItem, buttonOn16_cb);
        //
        hItem = WM_GetDialogItem(pMsg->hWin, ID_BUTTON_SAVE);
        WM_SetCallback(hItem, buttonOn16_cb);
        //
        break;
    case WM_NOTIFY_PARENT:
        Id    = WM_GetId(pMsg->hWinSrc);
        NCode = pMsg->Data.v;
        int c,h;
        switch(Id)
        {
        case ID_CHECKBOX_COOLING:
            switch(NCode)
            {
            case WM_NOTIFICATION_CLICKED:
                break;
            }
            break;
        case ID_CHECKBOX_HEATING:
            switch(NCode)
            {
            case WM_NOTIFICATION_CLICKED:
                break;
            }
            break;
        case ID_BUTTON_CANCEL:
            switch(NCode)
            {
            case WM_NOTIFICATION_CLICKED:
                hItem = WM_GetDialogItem(pMsg->hWin, ID_BUTTON_CANCEL);
                WM_SetCallback(hItem, buttonPush16_cb);
                break;
            case WM_NOTIFICATION_RELEASED:
                GUI_Delay(100);
                CreateSystemSetup();
                //state=17;
            }
            break;
        case ID_BUTTON_SAVE:
            switch(NCode)
            {
            case WM_NOTIFICATION_CLICKED:
                hItem = WM_GetDialogItem(pMsg->hWin, ID_BUTTON_SAVE);
                WM_SetCallback(hItem, buttonPush16_cb);
                break;
            case WM_NOTIFICATION_RELEASED:
                c = CHECKBOX_GetState(cooling);
                h = CHECKBOX_GetState(heating);

                if (c == 0 && h == 0)
                {
                    thermostatControls = 0;
                }
                else if (c == 1 && h == 0)
                {
                    thermostatControls = 1;
                }
                else if (c == 0 && h == 1)
                {
                    thermostatControls = 2;
                }
                else
                {
                    thermostatControls = 3;
                }

                GUI_Delay(100);
                CreateSystemSetup();
                //state=17;
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
WM_HWIN CreateThermostatControls(void);
WM_HWIN CreateThermostatControls(void)
{
    WM_HWIN hWin;

    thermo_controls = thermostatControls;
    hWin = GUI_CreateDialogBox(_aDialogCreate, GUI_COUNTOF(_aDialogCreate), _cbDialog, WM_HBKWIN, 0, 0);
    return hWin;
}

/*************************** End of file ****************************/
