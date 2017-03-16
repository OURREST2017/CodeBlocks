#include "ranger.h"

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
#define ID_IMAGE_RETURN (GUI_ID_USER + 0x15)
#define ID_TEXT_HEADER (GUI_ID_USER + 0x16)
#define ID_BUTTON_RETURN (GUI_ID_USER + 0x17)

#define ID_IMAGE_0_IMAGE_0 0x00

/*********************************************************************
*
*       _aDialogCreate
*/
static const GUI_WIDGET_CREATE_INFO _aDialogCreate[] =
{
    { WINDOW_CreateIndirect, "Window", ID_WINDOW_0, 0, 0, 480, 272, 0, 0x0, 0 },
    { IMAGE_CreateIndirect, "Image", ID_IMAGE_TIME_DATE, 38, 70, 50, 50, 0, 0, 0 },
    { IMAGE_CreateIndirect, "Image", ID_IMAGE_LOCK, 150, 66, 38, 50, 0, 0, 0 },
    { IMAGE_CreateIndirect, "Image", ID_IMAGE_SCHEDULE, 264, 69, 45, 50, 0, 0, 0 },
    { IMAGE_CreateIndirect, "Image", ID_IMAGE_LANGAGES, 384, 75, 50, 42, 0, 0, 0 },
    { IMAGE_CreateIndirect, "Image", ID_IMAGE_PEAR, 38, 167, 50, 60, 0, 0, 0 },
    { IMAGE_CreateIndirect, "Image", ID_IMAGE_PROFILE, 150, 180, 45, 39, 0, 0, 0 },
    { IMAGE_CreateIndirect, "Image", ID_IMAGE_PREFERENCES, 264, 178, 45, 50, 0, 0, 0 },
    { IMAGE_CreateIndirect, "Image", ID_IMAGE_SETUP, 384, 180, 44, 44, 0, 0, 0 },
    { TEXT_CreateIndirect, "Time/Date", ID_TEXT_0, 20, 128, 80, 20, 0, 0x64, 0 },
    { TEXT_CreateIndirect, "Lock", ID_TEXT_1, 142, 128, 59, 20, 0, 0x64, 0 },
    { TEXT_CreateIndirect, "Schedule", ID_TEXT_2, 246, 128, 80, 20, 0, 0x64, 0 },
    { TEXT_CreateIndirect, "Languages", ID_TEXT_3, 370, 128, 80, 20, 0, 0x64, 0 },
    { TEXT_CreateIndirect, "Mobile\nPair", ID_TEXT_4, 38, 230, 61, 40, 0, 0x64, 0 },
    { TEXT_CreateIndirect, "Profile", ID_TEXT_5, 132, 230, 80, 20, 0, 0x64, 0 },
    { TEXT_CreateIndirect, "Preferences", ID_TEXT_6, 246, 230, 80, 20, 0, 0x64, 0 },
    { TEXT_CreateIndirect, "Setup", ID_TEXT_7, 366, 230, 80, 20, 0, 0x64, 0 },
    { TEXT_CreateIndirect, "SETTINGS", ID_TEXT_HEADER, 144, 9, 212, 33, 0, 0x64, 0 },
    { BUTTON_CreateIndirect, "", ID_BUTTON_RETURN, 15, 0, 150, 50, 0, 0x0, 0 },
};

extern const U8 pear_image[3358];
static const void * _GetImageById(U32 Id, U32 * pSize)
{
    switch (Id)
    {
    case ID_IMAGE_0_IMAGE_0:
        *pSize = sizeof(pear_image);
        return (const void *)pear_image;
    }
    return NULL;
}
/*********************************************************************
*
*       _GetImageById
*/
extern GUI_CONST_STORAGE GUI_BITMAP bmlock ;
extern GUI_CONST_STORAGE GUI_BITMAP bmprofile ;
extern GUI_CONST_STORAGE GUI_BITMAP bmtime_date;
extern GUI_CONST_STORAGE GUI_BITMAP bmsetup;
extern GUI_CONST_STORAGE GUI_BITMAP bmschedule;
extern GUI_CONST_STORAGE GUI_BITMAP bmprofile;
extern GUI_CONST_STORAGE GUI_BITMAP bmpreferences;
extern GUI_CONST_STORAGE GUI_BITMAP bmlanguages;

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
        GUI_DrawGradientV(0, 0, 480, 50, color_map[0].stop, color_map[0].start);
        GUI_DrawBitmap(&bmwatermark, 45,52);
        GUI_DrawBitmap(&bmtime_date, 38, 70);
        GUI_DrawBitmap(&bmlock, 150, 66);
        GUI_DrawBitmap(&bmschedule, 264, 69);
        GUI_DrawBitmap(&bmlanguages, 384, 75);
        GUI_DrawBitmap(&bmprofile, 150, 180);
        GUI_DrawBitmap(&bmpreferences, 264, 178);
        GUI_DrawBitmap(&bmsetup, 384, 180);
        break;
    case WM_INIT_DIALOG:
        hItem = WM_GetDialogItem(pMsg->hWin, ID_BUTTON_RETURN);
        BUTTON_SetSkin(hItem, returnSkin);

        hItem = WM_GetDialogItem(pMsg->hWin, ID_TEXT_HEADER);
        TEXT_SetFont(hItem, HEADER_FONT_BOLD);
        TEXT_SetTextAlign(hItem, GUI_TA_HCENTER | GUI_TA_VCENTER);
        TEXT_SetTextColor(hItem, GUI_WHITE);

        hItem = WM_GetDialogItem(pMsg->hWin, ID_IMAGE_PEAR);
        pData = _GetImageById(ID_IMAGE_0_IMAGE_0, &FileSize);
        IMAGE_SetGIF(hItem, pData, FileSize);
        //
        hItem = WM_GetDialogItem(pMsg->hWin, ID_IMAGE_TIME_DATE);
        //
        hItem = WM_GetDialogItem(pMsg->hWin, ID_IMAGE_LOCK);
        //
        hItem = WM_GetDialogItem(pMsg->hWin, ID_IMAGE_SCHEDULE);
        //
        hItem = WM_GetDialogItem(pMsg->hWin, ID_IMAGE_LANGAGES);
       //
        hItem = WM_GetDialogItem(pMsg->hWin, ID_IMAGE_PROFILE);
        //
        hItem = WM_GetDialogItem(pMsg->hWin, ID_IMAGE_PREFERENCES);
        //
        hItem = WM_GetDialogItem(pMsg->hWin, ID_IMAGE_SETUP);
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
        case ID_BUTTON_RETURN:
            switch(NCode)
            {
            case WM_NOTIFICATION_RELEASED:
                GUI_Delay(100);
                state=1;
            }
            break;
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
                CreateDateTime();
                //state=11;
            }
            break;
        case ID_IMAGE_LOCK:
            switch(NCode)
            {
            case WM_NOTIFICATION_CLICKED:
                GUI_Delay(100);
                CreateScreenLockout();
                //state=12;
            }
            break;
        case ID_IMAGE_SCHEDULE:
            switch(NCode)
            {
            case WM_NOTIFICATION_CLICKED:
                GUI_Delay(100);
                CreateSettingsSchedule();
                // state=13;
            }
            break;
        case ID_IMAGE_LANGAGES:
            switch(NCode)
            {
            case WM_NOTIFICATION_CLICKED:
                GUI_Delay(100);
                CreateLanguages();
                // state=14;
            }
            break;
        case ID_IMAGE_PROFILE:
            switch(NCode)
            {
            case WM_NOTIFICATION_CLICKED:
                GUI_Delay(100);
                CreateProfile(0, "");
                // state=15;
            }
            break;
        case ID_IMAGE_PREFERENCES:
            switch(NCode)
            {
            case WM_NOTIFICATION_CLICKED:
                GUI_Delay(100);
                CreatePreferences();
                //state=16;
            }
            break;
        case ID_IMAGE_SETUP:
            switch(NCode)
            {
            case WM_NOTIFICATION_CLICKED:
                GUI_Delay(100);
                CreateSystemSetup();
                // state=17;
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
