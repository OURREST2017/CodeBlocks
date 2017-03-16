#include "ranger.h"
#ifndef CODEBLOCK
#include "stm324x9i_REST_HWv2_hvac.h"
#endif

#define ID_WINDOW_0  (GUI_ID_USER + 0x01)
#define ID_TEXT_0 (GUI_ID_USER + 0x02)
#define ID_BUTTON_AC_Y  (GUI_ID_USER + 0x03)
#define ID_BUTTON_AC_Y2  (GUI_ID_USER + 0x04)
#define ID_BUTTON_HEAT_W  (GUI_ID_USER + 0x05)
#define ID_BUTTON_HEAT_W2  (GUI_ID_USER + 0x06)
#define ID_BUTTON_FAN  (GUI_ID_USER + 0x07)
#define ID_BUTTON_B  (GUI_ID_USER + 0x08)
#define ID_BUTTON_O  (GUI_ID_USER + 0x09)
#define ID_BUTTON_X  (GUI_ID_USER + 0x1A)
#define ID_BUTTON_HOME  (GUI_ID_USER + 0x1B)

/*********************************************************************
*
*       _aDialogCreate
*/
static const GUI_WIDGET_CREATE_INFO _aDialogCreate[] =
{
    { WINDOW_CreateIndirect, "TriacPanelWin", ID_WINDOW_0, 0, 0, 480, 272, 0, 0x0, 0 },
    { TEXT_CreateIndirect, "Text", ID_TEXT_0, 0, 0, 480, 50, 0, 0x64, 0 },

    { BUTTON_CreateIndirect, "AC (Y)", ID_BUTTON_AC_Y, 60, 60, 160, 30, 0, 0x0, 0 },
    { BUTTON_CreateIndirect, "AC (Y2 )", ID_BUTTON_AC_Y2, 60, 100, 160, 30, 0, 0x0, 0 },
    { BUTTON_CreateIndirect, "HEAT (W)", ID_BUTTON_HEAT_W, 60, 140, 160, 30, 0, 0x0, 0 },
    { BUTTON_CreateIndirect, "HEAT (W2)", ID_BUTTON_HEAT_W2, 60, 180, 160, 30, 0, 0x0, 0 },
    { BUTTON_CreateIndirect, "FAN (G)", ID_BUTTON_FAN, 270, 60, 160, 30, 0, 0x0, 0 },
    { BUTTON_CreateIndirect, "(B)", ID_BUTTON_B, 270, 100, 160, 30, 0, 0x0, 0 },
    { BUTTON_CreateIndirect, "(O)", ID_BUTTON_O, 270, 140, 160, 30, 0, 0x0, 0 },
    { BUTTON_CreateIndirect, "(X)", ID_BUTTON_X, 270, 180, 160, 30, 0, 0x0, 0 },
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
        GUI_DrawGradientV(0, 0, 480, 50, color_map[0].stop, color_map[0].start);
        break;
    case WM_INIT_DIALOG:
        hItem = pMsg->hWin;
        WINDOW_SetBkColor(hItem, 0x0FFee0c6);

        hItem = WM_GetDialogItem(pMsg->hWin, ID_TEXT_0);
        TEXT_SetFont(hItem, HEADER_FONT_BOLD);
        TEXT_SetTextAlign(hItem, GUI_TA_HCENTER | GUI_TA_VCENTER);
        TEXT_SetTextColor(hItem, GUI_MAKE_COLOR(0x00FFFFFF));
        TEXT_SetText(hItem, "TRIAC TEST PANEL");

        hItem = WM_GetDialogItem(pMsg->hWin, ID_BUTTON_AC_Y);
        WM_SetCallback(hItem, buttonOn20_cb);

        hItem = WM_GetDialogItem(pMsg->hWin, ID_BUTTON_AC_Y2);
        WM_SetCallback(hItem, buttonOn20_cb);
        //
        hItem = WM_GetDialogItem(pMsg->hWin, ID_BUTTON_FAN);
        WM_SetCallback(hItem, buttonOn20_cb);
        //
        hItem = WM_GetDialogItem(pMsg->hWin, ID_BUTTON_B);
        WM_SetCallback(hItem, buttonOn20_cb);

        hItem = WM_GetDialogItem(pMsg->hWin, ID_BUTTON_HEAT_W);
        WM_SetCallback(hItem, buttonOn20_cb);

        hItem = WM_GetDialogItem(pMsg->hWin, ID_BUTTON_HEAT_W2);
        WM_SetCallback(hItem, buttonOn20_cb);
        //
        hItem = WM_GetDialogItem(pMsg->hWin, ID_BUTTON_O);
        WM_SetCallback(hItem, buttonOn20_cb);
        //
        hItem = WM_GetDialogItem(pMsg->hWin, ID_BUTTON_X);
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
        case ID_BUTTON_AC_Y:
            switch(NCode)
            {
            case WM_NOTIFICATION_RELEASED:
#ifndef CODEBLOCK
                BSP_HVAC_request_cool_Y(HVAC_FUNCTION_SET);
#endif
                GUI_Delay(100);
                CreatePassFail("AC (Y)");
                break;
            }
            break;
        case ID_BUTTON_AC_Y2:
            switch(NCode)
            {
            case WM_NOTIFICATION_RELEASED:
#ifndef CODEBLOCK
                BSP_HVAC_request_cool_Y2(HVAC_FUNCTION_SET);
#endif
                GUI_Delay(100);
                CreatePassFail("AC (Y2)");
                break;
            }
            break;
        case ID_BUTTON_FAN:
            switch(NCode)
            {
            case WM_NOTIFICATION_RELEASED:
#ifndef CODEBLOCK
                BSP_HVAC_request_fan_G(HVAC_FUNCTION_SET);
#endif
                GUI_Delay(100);
                CreatePassFail("FAN (G)");
                break;
            }
            break;
        case ID_BUTTON_HEAT_W:
            switch(NCode)
            {
            case WM_NOTIFICATION_RELEASED:
#ifndef CODEBLOCK
                BSP_HVAC_request_heat_W(HVAC_FUNCTION_SET);
#endif
                CreatePassFail("HEAT (W)");
                GUI_Delay(100);
            }
            break;
        case ID_BUTTON_HEAT_W2:
            switch(NCode)
            {
            case WM_NOTIFICATION_RELEASED:
#ifndef CODEBLOCK
                BSP_HVAC_request_heat_W2(HVAC_FUNCTION_SET);
#endif
                CreatePassFail("HEAT (W2)");
                GUI_Delay(100);
            }
            break;
        case ID_BUTTON_B:
            switch(NCode)
            {
            case WM_NOTIFICATION_RELEASED:
#ifndef CODEBLOCK
                BSP_HVAC_request_xxx_B(HVAC_FUNCTION_SET);
#endif
                GUI_Delay(100);
                CreatePassFail("B");
                break;
            }
            break;
        case ID_BUTTON_X:
            switch(NCode)
            {
            case WM_NOTIFICATION_RELEASED:
#ifndef CODEBLOCK
                BSP_HVAC_request_xxx_X(HVAC_FUNCTION_SET);
#endif
                GUI_Delay(100);
                CreatePassFail("X");
                break;
            }
            break;
        case ID_BUTTON_O:
            switch(NCode)
            {
            case WM_NOTIFICATION_RELEASED:
#ifndef CODEBLOCK
                BSP_HVAC_request_xxx_O(HVAC_FUNCTION_SET);
#endif
                GUI_Delay(100);
                CreatePassFail("O");
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
*       CreateTriacPanel
*/
WM_HWIN CreateTriacPanel(void);
WM_HWIN CreateTriacPanel(void)
{
    WM_HWIN hWin;

#ifndef CODEBLOCK
    BSP_HVAC_request_heat_W(HVAC_FUNCTION_RESET);
    BSP_HVAC_request_heat_W2(HVAC_FUNCTION_RESET);
    BSP_HVAC_request_cool_Y(HVAC_FUNCTION_RESET);
    BSP_HVAC_request_cool_Y2(HVAC_FUNCTION_RESET);
    BSP_HVAC_request_fan_G(HVAC_FUNCTION_RESET);
    BSP_HVAC_request_heat_W(HVAC_FUNCTION_RESET);
    BSP_HVAC_request_heat_W2(HVAC_FUNCTION_RESET);
    BSP_HVAC_request_xxx_B(HVAC_FUNCTION_RESET);
    BSP_HVAC_request_xxx_O(HVAC_FUNCTION_RESET);
    BSP_HVAC_request_xxx_X(HVAC_FUNCTION_RESET);
#endif

    hWin = GUI_CreateDialogBox(_aDialogCreate, GUI_COUNTOF(_aDialogCreate), _cbDialog, WM_HBKWIN, 0, 0);
    return hWin;
}

/*************************** End of file ****************************/
