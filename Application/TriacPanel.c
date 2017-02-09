#include "ranger.h"

#define ID_WINDOW_0  (GUI_ID_USER + 0x16)
#define ID_TEXT_0 (GUI_ID_USER + 0x08)
#define ID_BUTTON_AC  (GUI_ID_USER + 0x17)
#define ID_BUTTON_HEATER  (GUI_ID_USER + 0x18)
#define ID_BUTTON_FAN  (GUI_ID_USER + 0x19)
#define ID_BUTTON_SPARE  (GUI_ID_USER + 0x1A)
#define ID_BUTTON_HOME  (GUI_ID_USER + 0x1C)

/*********************************************************************
*
*       _aDialogCreate
*/
static const GUI_WIDGET_CREATE_INFO _aDialogCreate[] =
{
    { WINDOW_CreateIndirect, "TriacPanelWin", ID_WINDOW_0, 0, 0, 480, 272, 0, 0x0, 0 },
    { TEXT_CreateIndirect, "Text", ID_TEXT_0, 0, 0, 480, 50, 0, 0x64, 0 },
    { BUTTON_CreateIndirect, "AC", ID_BUTTON_AC, 60, 90, 160, 30, 0, 0x0, 0 },
    { BUTTON_CreateIndirect, "HEATER", ID_BUTTON_HEATER, 60, 140, 160, 30, 0, 0x0, 0 },
    { BUTTON_CreateIndirect, "FAN", ID_BUTTON_FAN, 270, 90, 160, 30, 0, 0x0, 0 },
    { BUTTON_CreateIndirect, "SPARE", ID_BUTTON_SPARE, 270, 140, 160, 30, 0, 0x0, 0 },
    { BUTTON_CreateIndirect, "Home", ID_BUTTON_HOME, 180, 230, 140, 30, 0, 0x0, 0 },
};

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
        break;
    case WM_INIT_DIALOG:
        hItem = pMsg->hWin;
        WINDOW_SetBkColor(hItem, 0x0FFee0c6);

        hItem = WM_GetDialogItem(pMsg->hWin, ID_TEXT_0);
        TEXT_SetFont(hItem, GUI_FONT_32B_1);
        TEXT_SetTextAlign(hItem, GUI_TA_HCENTER | GUI_TA_VCENTER);
        TEXT_SetTextColor(hItem, GUI_MAKE_COLOR(0x00FFFFFF));
        TEXT_SetText(hItem, "TRIAC TEST PANEL");

        hItem = WM_GetDialogItem(pMsg->hWin, ID_BUTTON_AC);
        WM_SetCallback(hItem, buttonOn20_cb);

        hItem = WM_GetDialogItem(pMsg->hWin, ID_BUTTON_HEATER);
        WM_SetCallback(hItem, buttonOn20_cb);
        //
        hItem = WM_GetDialogItem(pMsg->hWin, ID_BUTTON_FAN);
        WM_SetCallback(hItem, buttonOn20_cb);
        //
        hItem = WM_GetDialogItem(pMsg->hWin, ID_BUTTON_SPARE);
        WM_SetCallback(hItem, buttonOn20_cb);
        //
        hItem = WM_GetDialogItem(pMsg->hWin, ID_BUTTON_HOME);
        WM_SetCallback(hItem, buttonOn20_cb);
        break;
    case WM_NOTIFY_PARENT:
        Id    = WM_GetId(pMsg->hWinSrc);
        NCode = pMsg->Data.v;
        switch(Id)
        {
        case ID_BUTTON_AC:
            switch(NCode)
            {
            case WM_NOTIFICATION_RELEASED:
                  //HAL_GPIO_TogglePin(GPIOB, GPIO_PIN_0);  //AC
                CreatePassFail("AC");
                GUI_Delay(100);
                //state=2;
                break;
            }
            break;
        case ID_BUTTON_FAN:
            switch(NCode)
            {
            case WM_NOTIFICATION_RELEASED:
                //HAL_GPIO_TogglePin(GPIOB, GPIO_PIN_1);  //FAN
                     CreatePassFail("FAN");
           GUI_Delay(100);
                //state=2;
                break;
            }
            break;
        case ID_BUTTON_HEATER:
            switch(NCode)
            {
            case WM_NOTIFICATION_RELEASED:
                CreatePassFail("HEATER");
                //HAL_GPIO_TogglePin(GPIOB, GPIO_PIN_5);  //HEATER
                GUI_Delay(100);
                //state=2;
                break;
           }
            break;
        case ID_BUTTON_SPARE:
            switch(NCode)
            {
            case WM_NOTIFICATION_RELEASED:
                //HAL_GPIO_TogglePin(GPIOB, GPIO_PIN_10);  //SPARE
                 CreatePassFail("SPARE");
               GUI_Delay(100);
                //state=2;
                break;
            }
            break;
        case ID_BUTTON_HOME:
            switch(NCode)
            {
            case WM_NOTIFICATION_RELEASED:
                GUI_Delay(100);
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
*       CreateTriacPanelWin
*/
WM_HWIN CreateTriacPanel(void);
WM_HWIN CreateTriacPanel(void)
{
    WM_HWIN hWin;

    hWin = GUI_CreateDialogBox(_aDialogCreate, GUI_COUNTOF(_aDialogCreate), _cbDialog, WM_HBKWIN, 0, 0);
    return hWin;
}

/*************************** End of file ****************************/
