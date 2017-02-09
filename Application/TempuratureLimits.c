#include "ranger.h"

#define ID_WINDOW_0 (GUI_ID_USER + 0x02)
#define ID_BUTTON_CANCEL (GUI_ID_USER + 0x05)
#define ID_BUTTON_SAVE (GUI_ID_USER + 0x06)
#define ID_TEXT_HEADER (GUI_ID_USER + 0x08)
#define ID_TEXT_UPPER (GUI_ID_USER + 0x39)
#define ID_TEXT_LOWER (GUI_ID_USER + 0x40)

/*********************************************************************
*
*       _aDialogCreate
*/
static const GUI_WIDGET_CREATE_INFO _aDialogCreate[] =
{
    { WINDOW_CreateIndirect, "Window", ID_WINDOW_0, 0, 0, 480, 272, 0, 0x0, 0 },
    { TEXT_CreateIndirect, "TEMPUTATURE LIMITS", ID_TEXT_HEADER, 0, 0, 480, 50, 0, 0x64, 0 },
    { BUTTON_CreateIndirect, "CANCEL", ID_BUTTON_CANCEL, 20, 230, 80, 28, 0, 0x0, 0 },
    { BUTTON_CreateIndirect, "SAVE", ID_BUTTON_SAVE, 375, 230, 80, 28, 0, 0x0, 0 },
    { TEXT_CreateIndirect, "UPPER LIMIT", ID_TEXT_UPPER, 280, 56, 150, 80, 0, 0x64, 0 },
    { TEXT_CreateIndirect, "LOWER LIMIT", ID_TEXT_LOWER, 80, 56, 160, 80, 0, 0x64, 0 },
};

static WM_HWIN upUpperButton, dnUpperButton, upLowerButton, dnLowerButton;
int upperDegree, lowerDegree;

extern GUI_CONST_STORAGE GUI_BITMAP bmup_g;
extern GUI_CONST_STORAGE GUI_BITMAP bmdn_g;
extern void CreateDecoration(int,int,int, WHEEL *);
extern int OwnerDraw(const WIDGET_ITEM_DRAW_INFO * pDrawItemInfo);
static WHEEL code[2];
char temps[35][10] = {};

static int CreateListWheel(int x, int y, int xSize, int ySize, int Id, int TextAlign,
                           WM_HWIN hParent, WHEEL * pWheel, GUI_FONT *pFont, int lh, int pos)
{
    WM_HWIN                      hWin;
    int                          i;
    int                          LineHeight;

    LineHeight    = lh;
    pWheel->pFont = pFont;
    hWin          = LISTWHEEL_CreateUser(x, y, xSize, ySize, hParent, WM_CF_SHOW | WM_CF_HASTRANS, 0, Id, NULL, sizeof(void *));
    LISTWHEEL_SetFont(hWin, pFont);
    LISTWHEEL_SetTextAlign(hWin, TextAlign);
    LISTWHEEL_SetSnapPosition(hWin, (ySize - LineHeight) / 2);
    LISTWHEEL_SetOwnerDraw(hWin, OwnerDraw);
    LISTWHEEL_SetUserData(hWin, &pWheel, sizeof(pWheel));
    LISTWHEEL_SetLineHeight(hWin, LineHeight);
    LISTWHEEL_SetTextColor(hWin, LISTWHEEL_CI_SEL, 0x008800);
    LISTWHEEL_SetTextColor(hWin, LISTWHEEL_CI_UNSEL, 0x808080);

    for (i = 0; i < 35; i++)
    {
        LISTWHEEL_AddString(hWin, temps[i]);
    }
    if (TextAlign & GUI_TA_RIGHT)
    {
        LISTWHEEL_SetRBorder(hWin, 10);
    }
    CreateDecoration(xSize, ySize, LineHeight, pWheel);
    //
    // Fill WHEEL structure
    //
    pWheel->hWin = hWin;
    LISTWHEEL_SetPos(hWin, pos);
    LISTWHEEL_SetSel(hWin, pos);

    pWheel->hWin = hWin;
    return 0;
}

static void _cbBkWheel(WM_MESSAGE * pMsg)
{
    WM_HWIN hParent;
    int     xSize;
    int     ySize;

    switch (pMsg->MsgId)
    {
    case WM_NOTIFY_PARENT:
        hParent    = WM_GetParent(pMsg->hWin);
        pMsg->hWin = hParent;
        WM_SendMessage(hParent, pMsg);
        break;
    case WM_PAINT:
        xSize = WM_GetWindowSizeX(pMsg->hWin);
        ySize = WM_GetWindowSizeY(pMsg->hWin);
        GUI_DrawGradientV(0, 0, xSize - 1, ySize - 1, GUI_WHITE, GUI_WHITE);
        break;
    default:
        WM_DefaultProc(pMsg);
    }
}

/*********************************************************************
*
*       _cbDialog
*/
static void _cbDialog(WM_MESSAGE * pMsg)
{
    WM_HWIN hItem, spinWheel;
    int     NCode;
    int     Id;
    char buffer[10];
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

        hItem = WM_GetDialogItem(pMsg->hWin, ID_TEXT_UPPER);
        TEXT_SetTextColor(hItem, 0x808080);
        TEXT_SetFont(hItem, &FontBig20B);

        hItem = WM_GetDialogItem(pMsg->hWin, ID_TEXT_LOWER);
        TEXT_SetTextColor(hItem, 0x808080);
        TEXT_SetFont(hItem, &FontBig20B);

        int i;
        for (i=65; i<100; i++)
        {
            itoa(i, buffer, 10);
            strcpy(temps[i-65], buffer);
        }
        spinWheel = WM_CreateWindowAsChild(95, 80, 480, 140, pMsg->hWin, WM_CF_SHOW, _cbBkWheel, 0);
        CreateListWheel(  0, 0,  80, 125, GUI_ID_LISTWHEEL0, GUI_TA_VCENTER | GUI_TA_HCENTER, spinWheel,
                          &code[0], GUI_FONT_D36X48, 70, lowerDegreeLimit-65);
        CreateListWheel(  200, 0,  80, 125, GUI_ID_LISTWHEEL0, GUI_TA_VCENTER | GUI_TA_HCENTER, spinWheel,
                          &code[1], GUI_FONT_D36X48, 70, upperDegreeLimit-65);
        //
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
                upperDegreeLimit = atoi(temps[LISTWHEEL_GetPos(code[1].hWin)]);
                lowerDegreeLimit = atoi(temps[LISTWHEEL_GetPos(code[0].hWin)]);
                GUI_Delay(100);
                CreatePreferences();

                //state = 16;
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
WM_HWIN CreateTempuratureLimits(void);
WM_HWIN CreateTempuratureLimits(void)
{
    WM_HWIN hWin;

    hWin = GUI_CreateDialogBox(_aDialogCreate, GUI_COUNTOF(_aDialogCreate), _cbDialog, WM_HBKWIN, 0, 0);
    return hWin;
}

/*************************** End of file ****************************/
