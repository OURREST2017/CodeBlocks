#include "main.h"

#define ID_WINDOW_0 (GUI_ID_USER + 0x03)
#define ID_IMAGE_PEAR (GUI_ID_USER + 0x04)
#define ID_IMAGE_TIME_DATE (GUI_ID_USER + 0x05)
#define ID_IMAGE_LOCK (GUI_ID_USER + 0x06)
#define ID_IMAGE_SCHEDULE (GUI_ID_USER + 0x07)
#define ID_IMAGE_LANGAGES (GUI_ID_USER + 0x08)
#define ID_IMAGE_PROFILE (GUI_ID_USER + 0x09)
#define ID_IMAGE_PREFERENCES (GUI_ID_USER + 0x0A)
#define ID_IMAGE_SETUP (GUI_ID_USER + 0x0B)
#define ID_TEXT_0 (GUI_ID_USER + 0x0C)
#define ID_TEXT_1 (GUI_ID_USER + 0x0D)
#define ID_TEXT_2 (GUI_ID_USER + 0x0E)
#define ID_TEXT_3 (GUI_ID_USER + 0x0F)
#define ID_TEXT_4 (GUI_ID_USER + 0x10)
#define ID_TEXT_5 (GUI_ID_USER + 0x11)
#define ID_TEXT_6 (GUI_ID_USER + 0x12)
#define ID_TEXT_7 (GUI_ID_USER + 0x13)
#define ID_HEADER_0 (GUI_ID_USER + 0x14)
#define ID_IMAGE_RETURN (GUI_ID_USER + 0x15)
#define ID_TEXT_HEADER (GUI_ID_USER + 0x16)
#define ID_BUTTON_RETURN (GUI_ID_USER + 0x17)

#define ID_IMAGE_0_IMAGE_0 0x00
#define ID_IMAGE_1_IMAGE_0 0x01
#define ID_IMAGE_2_IMAGE_0 0x02
#define ID_IMAGE_3_IMAGE_0 0x03
#define ID_IMAGE_4_IMAGE_0 0x04
#define ID_IMAGE_5_IMAGE_0 0x05
#define ID_IMAGE_6_IMAGE_0 0x06
#define ID_IMAGE_7_IMAGE_0 0x07
#define ID_IMAGE_8_IMAGE_0 0x08

extern const U8 time_date_image[2443];
extern const U8 lock_image[1479];
extern const U8 schedule_image[3247];
extern const U8 languages_image[2395];
extern const U8 profile_image[1977];
extern const U8 preferences_image[1027];
extern const U8 setup_image[1001];
extern const U8 pear_image[3358];

/*********************************************************************
*
*       _aDialogCreate
*/
static const GUI_WIDGET_CREATE_INFO _aDialogCreate[] =
{
    { WINDOW_CreateIndirect, "Window", ID_WINDOW_0, 0, 0, 480, 272, 0, 0x0, 0 },
    { IMAGE_CreateIndirect, "Image", ID_IMAGE_PEAR, 24, 167, 50, 60, 0, 0, 0 },
    { IMAGE_CreateIndirect, "Image", ID_IMAGE_TIME_DATE, 28, 70, 50, 50, 0, 0, 0 },
    { IMAGE_CreateIndirect, "Image", ID_IMAGE_LOCK, 138, 70, 38, 50, 0, 0, 0 },
    { IMAGE_CreateIndirect, "Image", ID_IMAGE_SCHEDULE, 257, 69, 45, 50, 0, 0, 0 },
    { IMAGE_CreateIndirect, "Image", ID_IMAGE_LANGAGES, 376, 75, 50, 42, 0, 0, 0 },
    { IMAGE_CreateIndirect, "Image", ID_IMAGE_PROFILE, 131, 180, 45, 39, 0, 0, 0 },
    { IMAGE_CreateIndirect, "Image", ID_IMAGE_PREFERENCES, 257, 178, 45, 50, 0, 0, 0 },
    { IMAGE_CreateIndirect, "Image", ID_IMAGE_SETUP, 378, 180, 44, 44, 0, 0, 0 },
    { TEXT_CreateIndirect, "Time/Date", ID_TEXT_0, 10, 128, 80, 20, 0, 0x64, 0 },
    { TEXT_CreateIndirect, "Lock", ID_TEXT_1, 126, 128, 59, 20, 0, 0x64, 0 },
    { TEXT_CreateIndirect, "Schedule", ID_TEXT_2, 237, 128, 80, 20, 0, 0x64, 0 },
    { TEXT_CreateIndirect, "Pair", ID_TEXT_4, 25, 230, 61, 20, 0, 0x64, 0 },
    { TEXT_CreateIndirect, "Languages", ID_TEXT_3, 365, 128, 80, 20, 0, 0x64, 0 },
    { TEXT_CreateIndirect, "Profile", ID_TEXT_5, 112, 230, 80, 20, 0, 0x64, 0 },
    { TEXT_CreateIndirect, "Preferences", ID_TEXT_6, 240, 230, 80, 20, 0, 0x64, 0 },
    { TEXT_CreateIndirect, "Setup", ID_TEXT_7, 359, 230, 80, 20, 0, 0x64, 0 },
    { HEADER_CreateIndirect, "Header", ID_HEADER_0, 0, 0, 480, 50, 0, 0x0, 0 },
    { TEXT_CreateIndirect, "SETTINGS", ID_TEXT_HEADER, 144, 9, 212, 33, 0, 0x64, 0 },
    { BUTTON_CreateIndirect, "", ID_BUTTON_RETURN, 15, 0, 150, 50, 0, 0x0, 0 },
};
/*********************************************************************
*
*       _GetImageById
*/
static const void * _GetImageById(U32 Id, U32 * pSize)
{
    switch (Id)
    {
    case ID_IMAGE_0_IMAGE_0:
        *pSize = sizeof(pear_image);
        return (const void *)pear_image;
    case ID_IMAGE_1_IMAGE_0:
        *pSize = sizeof(time_date_image);
        return (const void *)time_date_image;
    case ID_IMAGE_2_IMAGE_0:
        *pSize = sizeof(lock_image);
        return (const void *)lock_image;
    case ID_IMAGE_3_IMAGE_0:
        *pSize = sizeof(schedule_image);
        return (const void *)schedule_image;
    case ID_IMAGE_4_IMAGE_0:
        *pSize = sizeof(languages_image);
        return (const void *)languages_image;
    case ID_IMAGE_5_IMAGE_0:
        *pSize = sizeof(profile_image);
        return (const void *)profile_image;
    case ID_IMAGE_6_IMAGE_0:
        *pSize = sizeof(preferences_image);
        return (const void *)preferences_image;
    case ID_IMAGE_7_IMAGE_0:
        *pSize = sizeof(setup_image);
        return (const void *)setup_image;
    }
    return NULL;
}

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
    case WM_PAINT:
        GUI_DrawBitmap(&bmwatermark, 0,50);
        break;
    case WM_INIT_DIALOG:
        hItem = WM_GetDialogItem(pMsg->hWin, ID_BUTTON_RETURN);
        BUTTON_SetSkin(hItem, returnSkin);

        hItem = WM_GetDialogItem(pMsg->hWin, ID_TEXT_HEADER);
        TEXT_SetFont(hItem, GUI_FONT_32B_1);
        TEXT_SetTextAlign(hItem, GUI_TA_HCENTER | GUI_TA_VCENTER);
        TEXT_SetTextColor(hItem, GUI_WHITE);

        hItem = WM_GetDialogItem(pMsg->hWin, ID_IMAGE_PEAR);
        pData = _GetImageById(ID_IMAGE_0_IMAGE_0, &FileSize);
        IMAGE_SetGIF(hItem, pData, FileSize);
        //
        hItem = WM_GetDialogItem(pMsg->hWin, ID_IMAGE_TIME_DATE);
        pData = _GetImageById(ID_IMAGE_1_IMAGE_0, &FileSize);
        IMAGE_SetPNG(hItem, pData, FileSize);
        //
        hItem = WM_GetDialogItem(pMsg->hWin, ID_IMAGE_LOCK);
        pData = _GetImageById(ID_IMAGE_2_IMAGE_0, &FileSize);
        IMAGE_SetPNG(hItem, pData, FileSize);
        //
        hItem = WM_GetDialogItem(pMsg->hWin, ID_IMAGE_SCHEDULE);
        pData = _GetImageById(ID_IMAGE_3_IMAGE_0, &FileSize);
        IMAGE_SetPNG(hItem, pData, FileSize);
        //
        hItem = WM_GetDialogItem(pMsg->hWin, ID_IMAGE_LANGAGES);
        pData = _GetImageById(ID_IMAGE_4_IMAGE_0, &FileSize);
        IMAGE_SetPNG(hItem, pData, FileSize);
        //
        hItem = WM_GetDialogItem(pMsg->hWin, ID_IMAGE_PROFILE);
        pData = _GetImageById(ID_IMAGE_5_IMAGE_0, &FileSize);
        IMAGE_SetPNG(hItem, pData, FileSize);
        //
        hItem = WM_GetDialogItem(pMsg->hWin, ID_IMAGE_PREFERENCES);
        pData = _GetImageById(ID_IMAGE_6_IMAGE_0, &FileSize);
        IMAGE_SetPNG(hItem, pData, FileSize);
        //
        hItem = WM_GetDialogItem(pMsg->hWin, ID_IMAGE_SETUP);
        pData = _GetImageById(ID_IMAGE_7_IMAGE_0, &FileSize);
        IMAGE_SetPNG(hItem, pData, FileSize);
        //
        hItem = WM_GetDialogItem(pMsg->hWin, ID_TEXT_0);
        TEXT_SetFont(hItem, &GUI_FontRounded16);
        TEXT_SetTextColor(hItem, 0x808080);
        TEXT_SetTextAlign(hItem, GUI_TA_HCENTER | GUI_TA_VCENTER);
        //
        hItem = WM_GetDialogItem(pMsg->hWin, ID_TEXT_1);
        TEXT_SetFont(hItem, &GUI_FontRounded16);
        TEXT_SetTextColor(hItem, 0x808080);
        TEXT_SetTextAlign(hItem, GUI_TA_HCENTER | GUI_TA_VCENTER);
        //
        hItem = WM_GetDialogItem(pMsg->hWin, ID_TEXT_2);
        TEXT_SetFont(hItem, &GUI_FontRounded16);
        TEXT_SetTextColor(hItem, 0x808080);
        TEXT_SetTextAlign(hItem, GUI_TA_HCENTER | GUI_TA_VCENTER);
        //
        hItem = WM_GetDialogItem(pMsg->hWin, ID_TEXT_3);
        TEXT_SetTextAlign(hItem, GUI_TA_HCENTER | GUI_TA_VCENTER);
        TEXT_SetTextColor(hItem, 0x808080);
        TEXT_SetFont(hItem, &GUI_FontRounded16);
        //
        hItem = WM_GetDialogItem(pMsg->hWin, ID_TEXT_4);
        TEXT_SetTextAlign(hItem, GUI_TA_HCENTER | GUI_TA_VCENTER);
        TEXT_SetFont(hItem, &GUI_FontRounded16);
        TEXT_SetTextColor(hItem, 0x808080);
        //
        hItem = WM_GetDialogItem(pMsg->hWin, ID_TEXT_5);
        TEXT_SetTextAlign(hItem, GUI_TA_HCENTER | GUI_TA_VCENTER);
        TEXT_SetTextColor(hItem, 0x808080);
        TEXT_SetFont(hItem, &GUI_FontRounded16);
        //
        hItem = WM_GetDialogItem(pMsg->hWin, ID_TEXT_6);
        TEXT_SetTextAlign(hItem, GUI_TA_HCENTER | GUI_TA_VCENTER);
        TEXT_SetTextColor(hItem, 0x808080);
        TEXT_SetFont(hItem, &GUI_FontRounded16);
        //
        hItem = WM_GetDialogItem(pMsg->hWin, ID_TEXT_7);
        TEXT_SetFont(hItem, &GUI_FontRounded16);
        TEXT_SetTextColor(hItem, 0x808080);
        TEXT_SetTextAlign(hItem, GUI_TA_HCENTER | GUI_TA_VCENTER);

        break;
    case WM_NOTIFY_PARENT:
        Id    = WM_GetId(pMsg->hWinSrc);
        NCode = pMsg->Data.v;
        switch(Id)
        {
        case ID_IMAGE_PEAR:
            switch(NCode)
            {
            case WM_NOTIFICATION_CLICKED:
                CreateMobilePair();
                GUI_Delay(100);
            }
            break;
        case ID_IMAGE_TIME_DATE:
            switch(NCode)
            {
            case WM_NOTIFICATION_CLICKED:
                GUI_Delay(100);
                state=11;
            }
            break;
        case ID_IMAGE_LOCK:
            switch(NCode)
            {
            case WM_NOTIFICATION_CLICKED:
                GUI_Delay(100);
                state=12;
            }
            break;
        case ID_IMAGE_SCHEDULE:
            switch(NCode)
            {
            case WM_NOTIFICATION_CLICKED:
                GUI_Delay(100);
                state=13;
            }
            break;
        case ID_IMAGE_LANGAGES:
            switch(NCode)
            {
            case WM_NOTIFICATION_CLICKED:
                GUI_Delay(100);
                state=14;
            }
            break;
        case ID_IMAGE_PROFILE:
            switch(NCode)
            {
            case WM_NOTIFICATION_CLICKED:
                GUI_Delay(100);
                state=15;
            }
            break;
        case ID_IMAGE_PREFERENCES:
            switch(NCode)
            {
            case WM_NOTIFICATION_CLICKED:
                GUI_Delay(100);
                state=16;
            }
            break;
        case ID_IMAGE_SETUP:
            switch(NCode)
            {
            case WM_NOTIFICATION_CLICKED:
                GUI_Delay(100);
                state=17;
            }
            break;
        case ID_BUTTON_RETURN:
            switch(NCode)
            {
            case WM_NOTIFICATION_CLICKED:
                GUI_Delay(100);
                GUI_EndDialog(pMsg->hWin, 0);
                state=1;
            }
            break;
        }
        break;
    default:
        WM_DefaultProc(pMsg);
        break;
    }
}

WM_HWIN CreateSettings(void);
WM_HWIN CreateSettings(void)
{
    WM_HWIN hWin;

    hWin = GUI_CreateDialogBox(_aDialogCreate, GUI_COUNTOF(_aDialogCreate), _cbDialog, WM_HBKWIN, 0, 0);
    return hWin;
}

/*************************** End of file ****************************/
