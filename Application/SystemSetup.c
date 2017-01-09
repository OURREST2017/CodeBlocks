/*********************************************************************
*                                                                    *
*                SEGGER Microcontroller GmbH & Co. KG                *
*        Solutions for real time microcontroller applications        *
*                                                                    *
**********************************************************************
*                                                                    *
* C-file generated by:                                               *
*                                                                    *
*        GUI_Builder for emWin version 5.32                          *
*        Compiled Oct  8 2015, 11:59:02                              *
*        (c) 2015 Segger Microcontroller GmbH & Co. KG               *
*                                                                    *
**********************************************************************
*                                                                    *
*        Internet: www.segger.com  Support: support@segger.com       *
*                                                                    *
**********************************************************************
*/

#include "main.h"

#define ID_WINDOW_0 (GUI_ID_USER + 0x02)
#define ID_HEADER_0 (GUI_ID_USER + 0x07)
#define ID_TEXT_HEADER (GUI_ID_USER + 0x08)
#define ID_BUTTON_THERMO_LOCATION (GUI_ID_USER + 0x0E)
#define ID_BUTTON_SYSTEM_TYPE (GUI_ID_USER + 0x0F)
#define ID_BUTTON_THERMO_CONTROLS (GUI_ID_USER + 0x10)
#define ID_BUTTON_FAN_CONTROLS (GUI_ID_USER + 0x11)
#define ID_BUTTON_WIFI_SETUP (GUI_ID_USER + 0x12)
#define ID_BUTTON_BACKUP_HEAT (GUI_ID_USER + 0x13)
#define ID_BUTTON_COOLING_STAGES (GUI_ID_USER + 0x14)
#define ID_BUTTON_HEATING_STAGES (GUI_ID_USER + 0x15)
#define ID_BUTTON_RETURN (GUI_ID_USER + 0x16)

static GUI_CONST_STORAGE unsigned char acreturn[] =
{
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x01, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x00, 0x00, 0x00,
    0x21, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x00, 0x00,
    0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x10, 0x00,
    0x01, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x00,
    0x03, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x11, 0x11, 0x10,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x11, 0x11, 0x10,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x11, 0x11, 0x10,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x11, 0x11, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x11, 0x11, 0x10,
    0x00, 0x00, 0x00, 0x00, 0x11, 0x11, 0x11, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x11, 0x11, 0x10,
    0x00, 0x00, 0x00, 0x11, 0x11, 0x11, 0x11, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x11, 0x11, 0x10,
    0x00, 0x00, 0x01, 0x11, 0x11, 0x11, 0x11, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x11, 0x11, 0x11, 0x10,
    0x00, 0x01, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x10,
    0x01, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x00,
    0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x10, 0x00,
    0x01, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x00, 0x00,
    0x00, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x11, 0x11, 0x11, 0x11, 0x11, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x01, 0x11, 0x11, 0x11, 0x11, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x01, 0x11, 0x11, 0x11, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x01, 0x11, 0x11, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x10, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
};

static const GUI_COLOR Colors[] = { 0x000000, 0xFFFFFF };
static const GUI_LOGPALETTE Palette = { 2, 1, Colors };

GUI_CONST_STORAGE GUI_BITMAP bm_return =
{
    44, // xSize
    25, // ySize
    22, // BytesPerLine
    4, // BitsPerPixel
    acreturn,  // Pointer to picture data (indices)
    &Palette   // Pointer to palette
};

static void return_cb(WM_MESSAGE * pMsg)
{
    switch (pMsg->MsgId)
    {
    case WM_PAINT:
        GUI_DrawBitmap(&bm_return, 0, 0);
        break;
    default:
        BUTTON_Callback(pMsg); // The original callback
        break;
    }
}
/*********************************************************************
*
*       _aDialogCreate
*/
static const GUI_WIDGET_CREATE_INFO _aDialogCreate[] =
{
    { WINDOW_CreateIndirect, "Window", ID_WINDOW_0, 0, 0, 480, 272, 0, 0x0, 0 },
    { HEADER_CreateIndirect, "Header", ID_HEADER_0, 0, 0, 480, 50, 0, 0x0, 0 },
    { TEXT_CreateIndirect, "SYSTEM SETUP", ID_TEXT_HEADER, 0, 0, 480, 50, 0, 0x64, 0 },
    { BUTTON_CreateIndirect, "Thermostat Location", ID_BUTTON_THERMO_LOCATION, 10, 70, 220, 36, 0, 0x0, 0 },
    { BUTTON_CreateIndirect, "System Type", ID_BUTTON_SYSTEM_TYPE, 10, 115, 220, 36, 0, 0x0, 0 },
    { BUTTON_CreateIndirect, "Thermostat Controls", ID_BUTTON_THERMO_CONTROLS, 10, 160, 220, 36, 0, 0x0, 0 },
    { BUTTON_CreateIndirect, "Fan Control", ID_BUTTON_FAN_CONTROLS, 10, 205, 220, 36, 0, 0x0, 0 },
    { BUTTON_CreateIndirect, "WIFI Setup", ID_BUTTON_WIFI_SETUP, 242, 70, 220, 36, 0, 0x0, 0 },
    { BUTTON_CreateIndirect, "Backup Heat", ID_BUTTON_BACKUP_HEAT, 242, 115, 220, 36, 0, 0x0, 0 },
    { BUTTON_CreateIndirect, "Cooling Stages", ID_BUTTON_COOLING_STAGES, 242, 160, 220, 36, 0, 0x0, 0 },
    { BUTTON_CreateIndirect, "Heating Stages", ID_BUTTON_HEATING_STAGES, 242, 205, 220, 36, 0, 0x0, 0 },
    { BUTTON_CreateIndirect, "return", ID_BUTTON_RETURN, 20, 12, 50, 50, 0, 0x0, 0 },
};

/*********************************************************************
*
*       _cbDialog
*/
static void _cbDialog(WM_MESSAGE * pMsg)
{
    const void * pData;
    WM_HWIN      hItem;
    U32          FileSize;
    int          NCode;
    int          Id;

    switch (pMsg->MsgId)
    {
    case WM_INIT_DIALOG:
        //
        // Initialization of 'Text'
        //
        //GUI_DrawBitmap(&bm_return, 100, 150);

        hItem = WM_GetDialogItem(pMsg->hWin, ID_BUTTON_RETURN);
        WM_SetCallback(hItem, return_cb);

        hItem = WM_GetDialogItem(pMsg->hWin, ID_TEXT_HEADER);
        TEXT_SetFont(hItem, GUI_FONT_32B_1);
        TEXT_SetTextAlign(hItem, GUI_TA_HCENTER | GUI_TA_VCENTER);
        TEXT_SetTextColor(hItem, GUI_MAKE_COLOR(0x00FFFFFF));
        //
        // Initialization of 'Button'
        //
        hItem = WM_GetDialogItem(pMsg->hWin, ID_BUTTON_THERMO_LOCATION);
        BUTTON_SetFont(hItem, GUI_FONT_20B_1);
        BUTTON_SetTextColor(hItem, 0, GUI_MAKE_COLOR(0x00FFFFFF));
//
        // Initialization of 'Button'
        //
        hItem = WM_GetDialogItem(pMsg->hWin, ID_BUTTON_SYSTEM_TYPE);
        BUTTON_SetFont(hItem, GUI_FONT_20B_1);
        BUTTON_SetTextColor(hItem, 0, GUI_MAKE_COLOR(0x00FFFFFF));
        //
        // Initialization of 'Button'
        //
        hItem = WM_GetDialogItem(pMsg->hWin, ID_BUTTON_THERMO_CONTROLS);
        BUTTON_SetFont(hItem, GUI_FONT_20B_1);
        BUTTON_SetTextColor(hItem, 0, GUI_MAKE_COLOR(0x00FFFFFF));
        //
        // Initialization of 'Button'
        //
        hItem = WM_GetDialogItem(pMsg->hWin, ID_BUTTON_FAN_CONTROLS);
        BUTTON_SetFont(hItem, GUI_FONT_20B_1);
        BUTTON_SetTextColor(hItem, 0, GUI_MAKE_COLOR(0x00FFFFFF));
        //
        // Initialization of 'Button'
        //
        hItem = WM_GetDialogItem(pMsg->hWin, ID_BUTTON_WIFI_SETUP);
        BUTTON_SetFont(hItem, GUI_FONT_20B_1);
        BUTTON_SetTextColor(hItem, 0, GUI_MAKE_COLOR(0x00FFFFFF));
        //
        // Initialization of 'Button'
        //
        hItem = WM_GetDialogItem(pMsg->hWin, ID_BUTTON_BACKUP_HEAT);
        BUTTON_SetFont(hItem, GUI_FONT_20B_1);
        BUTTON_SetTextColor(hItem, 0, GUI_MAKE_COLOR(0x00FFFFFF));
        //
        // Initialization of 'Button'
        //
        hItem = WM_GetDialogItem(pMsg->hWin, ID_BUTTON_COOLING_STAGES);
        BUTTON_SetFont(hItem, GUI_FONT_20B_1);
        BUTTON_SetTextColor(hItem, 0, GUI_MAKE_COLOR(0x00FFFFFF));
        //
        // Initialization of 'Button'
        //
        hItem = WM_GetDialogItem(pMsg->hWin, ID_BUTTON_HEATING_STAGES);
        BUTTON_SetFont(hItem, GUI_FONT_20B_1);
        BUTTON_SetTextColor(hItem, 0, GUI_MAKE_COLOR(0x00FFFFFF));
        break;
    case WM_NOTIFY_PARENT:
        Id    = WM_GetId(pMsg->hWinSrc);
        NCode = pMsg->Data.v;
        switch(Id)
        {
        case ID_BUTTON_RETURN: // Notifications sent by 'Button'
            switch(NCode)
            {
            case WM_NOTIFICATION_RELEASED:
                GUI_Delay(100);
                state=4;
            }
            break;
        case ID_BUTTON_THERMO_LOCATION: // Notifications sent by 'Button'
            switch(NCode)
            {
            case WM_NOTIFICATION_RELEASED:
                GUI_Delay(100);
                state=20;
            }
            break;
        case ID_BUTTON_SYSTEM_TYPE: // Notifications sent by 'Button'
            switch(NCode)
            {
            case WM_NOTIFICATION_RELEASED:
                GUI_Delay(100);
                state=21;
            }
            break;
        case ID_BUTTON_THERMO_CONTROLS: // Notifications sent by 'Button'
            switch(NCode)
            {
            case WM_NOTIFICATION_RELEASED:
                GUI_Delay(100);
                state=22;
            }
            break;
        case ID_BUTTON_FAN_CONTROLS: // Notifications sent by 'Button'
            switch(NCode)
            {
            case WM_NOTIFICATION_RELEASED:
                GUI_Delay(100);
                state=23;
            }
            break;
        case ID_BUTTON_WIFI_SETUP: // Notifications sent by 'Button'
            switch(NCode)
            {
            case WM_NOTIFICATION_RELEASED:
                GUI_Delay(100);
                state=24;
            }
            break;
        case ID_BUTTON_BACKUP_HEAT: // Notifications sent by 'Button'
            switch(NCode)
            {
            case WM_NOTIFICATION_RELEASED:
                GUI_Delay(100);
                state=25;
            }
            break;
        case ID_BUTTON_COOLING_STAGES: // Notifications sent by 'Button'
            switch(NCode)
            {
            case WM_NOTIFICATION_RELEASED:
                GUI_Delay(100);
                state=26;
            }
            break;
        case ID_BUTTON_HEATING_STAGES: // Notifications sent by 'Button'
            switch(NCode)
            {
            case WM_NOTIFICATION_RELEASED:
                GUI_Delay(100);
                state=27;
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
WM_HWIN CreateSystemSetup(void);
WM_HWIN CreateSystemSetup(void)
{
    WM_HWIN hWin;

    hWin = GUI_CreateDialogBox(_aDialogCreate, GUI_COUNTOF(_aDialogCreate), _cbDialog, WM_HBKWIN, 0, 0);
    return hWin;
}

/*************************** End of file ****************************/
