#include "ranger.h"

#define ID_WINDOW_0 (GUI_ID_USER + 0x00)
#define ID_TEXT_HEADER (GUI_ID_USER + 0x02)
#define ID_BUTTON_CANCEL (GUI_ID_USER + 0x07)
#define ID_BUTTON_SAVE (GUI_ID_USER + 0x08)

/*********************************************************************
*
*       _aDialogCreate
*/
static const GUI_WIDGET_CREATE_INFO _aDialogCreate[] =
{
    { WINDOW_CreateIndirect, "Window", ID_WINDOW_0, 0, 0, 480, 272, 0, 0x0, 0 },
    { TEXT_CreateIndirect, "KEYBOARD LOCK", ID_TEXT_HEADER, 0, 0, 480, 50, 0, 0x64, 0 },
    { BUTTON_CreateIndirect, "SAVE", ID_BUTTON_SAVE, 375, 230, 80, 28, 0, 0x0, 0 },
    { BUTTON_CreateIndirect, "CANCEL", ID_BUTTON_CANCEL, 20, 230, 80, 28, 0, 0x0, 0 },
};

static char * codes[] =
{
    "0", "1", "2", "3", "4", "5", "6", "7", "8", "9"
};

extern void CreateDecoration(int,int,int, WHEEL *);
extern int OwnerDraw(const WIDGET_ITEM_DRAW_INFO * pDrawItemInfo);
static WHEEL code[4];
static int dig[4], bc;

static int CreateListWheel(int x, int y, int xSize, int ySize, int Id,
                            char ** apText, int NumItems, int TextAlign,
                            WM_HWIN hParent, WHEEL * pWheel, GUI_FONT *pFont, int lh, int pos)
{
    WM_HWIN                      hWin;
    int                          i;
    int                          LineHeight;

    pWheel->pFont = pFont;
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

    for (i = 0; i < NumItems; i++)
    {
        LISTWHEEL_AddString(hWin, *(apText + i));
    }
    if (TextAlign & GUI_TA_RIGHT)
    {
        LISTWHEEL_SetRBorder(hWin, 10);
    }
    CreateDecoration(xSize, ySize, LineHeight, pWheel);
    //
    // Fill WHEEL structure
    //
    code[bc++].hWin = hWin;
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
        //GUI_SetBkColor(GUI_WHITE);
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
    int NCode;
    int Id, i;

    switch (pMsg->MsgId)
    {
    case WM_PAINT:
        GUI_DrawGradientV(0, 0, 480, 50, 0x63b39b, 0x48866c);
        GUI_DrawBitmap(&bmwatermark,45,52);
        break;
    case WM_INIT_DIALOG:
        hItem = WM_GetDialogItem(pMsg->hWin, ID_TEXT_HEADER);
        TEXT_SetFont(hItem, GUI_FONT_32B_1);
        TEXT_SetTextAlign(hItem, GUI_TA_HCENTER | GUI_TA_VCENTER);
        TEXT_SetTextColor(hItem, GUI_MAKE_COLOR(0x00FFFFFF));

        spinWheel = WM_CreateWindowAsChild(50, 75, 480, 140,
                                           pMsg->hWin, WM_CF_SHOW, _cbBkWheel, 0);
        CreateListWheel(  0, 0,  80, 125, GUI_ID_LISTWHEEL0, codes,
                           GUI_COUNTOF(codes),   GUI_TA_VCENTER | GUI_TA_HCENTER, spinWheel,
                        &code[0], GUI_FONT_D36X48, 70, dig[0]);
        CreateListWheel(  100, 0,  80, 125, GUI_ID_LISTWHEEL0, codes,
                           GUI_COUNTOF(codes),   GUI_TA_VCENTER | GUI_TA_HCENTER, spinWheel,
                         &code[1], GUI_FONT_D36X48, 70, dig[1]);
        CreateListWheel(  200, 0,  80, 125, GUI_ID_LISTWHEEL0, codes,
                           GUI_COUNTOF(codes),   GUI_TA_VCENTER | GUI_TA_HCENTER, spinWheel,
                        &code[2], GUI_FONT_D36X48, 70, dig[2]);
        CreateListWheel(  300, 0,  80, 125, GUI_ID_LISTWHEEL0, codes,
                           GUI_COUNTOF(codes),   GUI_TA_VCENTER | GUI_TA_HCENTER, spinWheel,
                        &code[3], GUI_FONT_D36X48, 70, dig[3]);

        hItem = WM_GetDialogItem(pMsg->hWin, ID_BUTTON_CANCEL);
        WM_SetCallback(hItem, buttonOn16_cb);

        hItem = WM_GetDialogItem(pMsg->hWin, ID_BUTTON_SAVE);
        WM_SetCallback(hItem, buttonOn16_cb);
        break;

    case WM_NOTIFY_PARENT:
        Id    = WM_GetId(pMsg->hWinSrc);
        NCode = pMsg->Data.v;
        char buf[10];
        switch(Id)
        {
        case ID_BUTTON_CANCEL:
            switch(NCode)
            {
            case WM_NOTIFICATION_RELEASED:
                GUI_Delay(100);
                CreateSettings();
                //state = 4;
                break;
            }
            break;
        case ID_BUTTON_SAVE:
            switch(NCode)
            {
            case WM_NOTIFICATION_RELEASED:
                lockCode[0] = LISTWHEEL_GetPos(code[0].hWin) + 48;
                lockCode[1] = LISTWHEEL_GetPos(code[1].hWin) + 48;
                lockCode[2] = LISTWHEEL_GetPos(code[2].hWin) + 48;
                lockCode[3] = LISTWHEEL_GetPos(code[3].hWin) + 48;
                lockCode[4] = '\0';

                GUI_Delay(100);
                CreateSettings();
                //state = 4;
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
WM_HWIN CreateScreenLockout(void);
WM_HWIN CreateScreenLockout(void)
{
    WM_HWIN hWin;
    bc = 0;
    dig[0] = lockCode[0] - 48;
    dig[1] = lockCode[1] - 48;
    dig[2] = lockCode[2] - 48;
    dig[3] = lockCode[3] - 48;

    hWin = GUI_CreateDialogBox(_aDialogCreate, GUI_COUNTOF(_aDialogCreate), _cbDialog, WM_HBKWIN, 0, 0);
    return hWin;
}

/*************************** End of file ****************************/
