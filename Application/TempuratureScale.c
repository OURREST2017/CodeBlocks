#include "ranger.h"

#define ID_WINDOW_0 (GUI_ID_USER + 0x02)
#define ID_BUTTON_CANCEL (GUI_ID_USER + 0x05)
#define ID_BUTTON_SAVE (GUI_ID_USER + 0x06)
#define ID_TEXT_HEADER (GUI_ID_USER + 0x08)
#define ID_BUTTON_FARENHEIT (GUI_ID_USER + 0x0E)
#define ID_BUTTON_CELCIOUS (GUI_ID_USER + 0x0F)

/*********************************************************************
*
*       _aDialogCreate
*/
static const GUI_WIDGET_CREATE_INFO _aDialogCreate[] =
{
    { WINDOW_CreateIndirect, "Window", ID_WINDOW_0, 0, 0, 480, 272, 0, 0x0, 0 },
    { BUTTON_CreateIndirect, "CANCEL", ID_BUTTON_CANCEL, 20, 230, 80, 28, 0, 0x0, 0 },
    { BUTTON_CreateIndirect, "SAVE", ID_BUTTON_SAVE, 375, 230, 80, 28, 0, 0x0, 0 },
    { TEXT_CreateIndirect, "TEMPURATURE SCALE", ID_TEXT_HEADER, 0, 0, 480, 50, 0, 0x64, 0 },
    { BUTTON_CreateIndirect, "Farenheit", ID_BUTTON_FARENHEIT, 120, 90, 240, 40, 0, 0x0, 0 },
    { BUTTON_CreateIndirect, "Celsius", ID_BUTTON_CELCIOUS, 120, 145, 240, 40, 0, 0x0, 0 },
};

static int celcius;

static WM_HWIN farenheitButton, celciusButton;

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
        //
        hItem = WM_GetDialogItem(pMsg->hWin, ID_TEXT_HEADER);
        TEXT_SetFont(hItem, GUI_FONT_32B_1);
        TEXT_SetTextAlign(hItem, GUI_TA_HCENTER | GUI_TA_VCENTER);
        TEXT_SetTextColor(hItem, GUI_MAKE_COLOR(0x00FFFFFF));
        //
        farenheitButton = WM_GetDialogItem(pMsg->hWin, ID_BUTTON_FARENHEIT);
        //
        celciusButton = WM_GetDialogItem(pMsg->hWin, ID_BUTTON_CELCIOUS);

        if (celcius)
        {
            WM_SetCallback(farenheitButton, buttonOff22_cb);
            WM_SetCallback(celciusButton, buttonOn22_cb);
        }
        else
        {
            WM_SetCallback(farenheitButton, buttonOn22_cb);
            WM_SetCallback(celciusButton, buttonOff22_cb);
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
                metric = celcius;
                GUI_Delay(100);
                CreatePreferences();
                //state = 16;
                break;
            }
            break;
        case ID_BUTTON_FARENHEIT:
            switch(NCode)
            {
            case WM_NOTIFICATION_RELEASED:
                celcius = 0;
                WM_SetCallback(farenheitButton, buttonOn22_cb);
                WM_SetCallback(celciusButton, buttonOff22_cb);
                break;
            }
            break;
        case ID_BUTTON_CELCIOUS:
            switch(NCode)
            {
            case WM_NOTIFICATION_RELEASED:
                celcius = 1;
                WM_SetCallback(farenheitButton, buttonOff22_cb);
                WM_SetCallback(celciusButton, buttonOn22_cb);
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
WM_HWIN CreateTempuratureScale(void);
WM_HWIN CreateTempuratureScale(void)
{
    WM_HWIN hWin;

    celcius = metric;
    hWin = GUI_CreateDialogBox(_aDialogCreate, GUI_COUNTOF(_aDialogCreate), _cbDialog, WM_HBKWIN, 0, 0);
    return hWin;
}

/*************************** End of file ****************************/
