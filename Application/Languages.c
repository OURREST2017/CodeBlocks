#include "ranger.h"

#define ID_WINDOW_0 (GUI_ID_USER + 0x02)
#define ID_BUTTON_CANCEL (GUI_ID_USER + 0x05)
#define ID_BUTTON_SAVE (GUI_ID_USER + 0x06)
#define ID_TEXT_HEADER (GUI_ID_USER + 0x08)
#define ID_BUTTON_ENGLISH (GUI_ID_USER + 0x09)
#define ID_BUTTON_ESPANOL (GUI_ID_USER + 0x0A)

/*********************************************************************
*
*       _aDialogCreate
*/
static const GUI_WIDGET_CREATE_INFO _aDialogCreate[] =
{
    { WINDOW_CreateIndirect, "Window", ID_WINDOW_0, 0, 0, 480, 272, 0, 0x0, 0 },
    { TEXT_CreateIndirect, "LANGUAGES / IDIOMAS", ID_TEXT_HEADER, 0, 0, 480, 50, 0, 0x64, 0 },
    { BUTTON_CreateIndirect, "English", ID_BUTTON_ENGLISH, 109, 97, 265, 34, 0, 0x0, 0 },
    { BUTTON_CreateIndirect, "Espanol", ID_BUTTON_ESPANOL, 111, 156, 265, 34, 0, 0x0, 0 },
    { BUTTON_CreateIndirect, "CANCEL", ID_BUTTON_CANCEL, 20, 230, 80, BUTHEIGHT, 0, 0x0, 0 },
    { BUTTON_CreateIndirect, "SAVE", ID_BUTTON_SAVE, 375, 230, 80, BUTHEIGHT, 0, 0x0, 0 },
};

static int eng_mode;
static WM_HWIN engButton, spaButton;
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
        //
        hItem = WM_GetDialogItem(pMsg->hWin, ID_TEXT_HEADER);
        TEXT_SetFont(hItem, HEADER_FONT_BOLD);
        TEXT_SetTextAlign(hItem, GUI_TA_HCENTER | GUI_TA_VCENTER);
        TEXT_SetTextColor(hItem, GUI_MAKE_COLOR(0x00FFFFFF));
        //
        engButton = WM_GetDialogItem(pMsg->hWin, ID_BUTTON_ENGLISH);
        //
        spaButton = WM_GetDialogItem(pMsg->hWin, ID_BUTTON_ESPANOL);
        if (eng_mode)
        {
            WM_SetCallback(engButton, buttonOn22_cb);
            WM_SetCallback(spaButton, buttonOff22_cb);
        }
        else
        {
            WM_SetCallback(spaButton, buttonOn22_cb);
            WM_SetCallback(engButton, buttonOff22_cb);
        }

        hItem = WM_GetDialogItem(pMsg->hWin, ID_BUTTON_CANCEL);
        WM_SetCallback(hItem, buttonOn16_cb);
        if (firstTime) WM_HideWin(hItem);
        //
        hItem = WM_GetDialogItem(pMsg->hWin, ID_BUTTON_SAVE);
        if (firstTime) BUTTON_SetText(hItem, "NEXT");
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
                CreateSettings();
                //state=4;
                break;
            }
            break;
        case ID_BUTTON_SAVE:
            switch(NCode)
            {
            case WM_NOTIFICATION_RELEASED:
                GUI_Delay(100);
                if (eng_mode)
                {
                    strcpy(language, "english");
                }
                else
                {
                    strcpy(language, "espanol");
                }

                if (firstTime)
                {
                    CreateThermostatLocations();
                }
                else
                {
                    CreateSettings();
                    //state=4;
                }
                break;
            }
            break;
        case ID_BUTTON_ENGLISH:
            switch(NCode)
            {
            case WM_NOTIFICATION_RELEASED:
                eng_mode = 1;

                WM_SetCallback(engButton, buttonOn22_cb);
                WM_SetCallback(spaButton, buttonOff22_cb);
                break;
            }
            break;
        case ID_BUTTON_ESPANOL:
            switch(NCode)
            {
            case WM_NOTIFICATION_RELEASED:
                eng_mode = 0;

                WM_SetCallback(spaButton, buttonOn22_cb);
                WM_SetCallback(engButton, buttonOff22_cb);
                break;
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
WM_HWIN CreateLanguages(void);
WM_HWIN CreateLanguages(void)
{
    WM_HWIN hWin;

    if (strcmp(language, "english") == 0)
    {
        eng_mode = 1;
    }
    else
    {
        eng_mode = 0;
    }
    hWin = GUI_CreateDialogBox(_aDialogCreate, GUI_COUNTOF(_aDialogCreate), _cbDialog, WM_HBKWIN, 0, 0);
    return hWin;
}

/*************************** End of file ****************************/
