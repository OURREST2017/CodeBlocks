#include "ranger.h"

int color_scheme;
GUI_COLOR buttonTextColor = 0xffffff;
//GUI_FONT buttonFont = GUI_FontRounded16;

typedef struct colors
{
    GUI_COLOR start;
    GUI_COLOR middle;
    GUI_COLOR stop;
    char * color;
} colors;

struct colors color_map[3];

void initColors()
{
//    color_map[0].start  = 0x00763c;       // 72 134 108
//    color_map[0].middle = 0x009e5a;      // 80 158 129
//    color_map[0].stop   = 0x00b364;       // 99 179 155
//
    color_map[0].start = 0x48866c;       // 72 134 108
    color_map[0].middle = 0x509e81;      // 80 158 129
    color_map[0].stop  = 0x63b39b;       // 99 179 155
//
    color_map[0].color = "green";

//    18 200 70      12c850
//    28 225 95      1ce15f
//    38 255 120     26ff78

    color_map[1].start = 0x272780;
    color_map[1].middle = 0x38389e;
    color_map[1].stop  = 0x4343bf;
    color_map[1].color = "red";

    color_map[2].start = 0xdfc4d8;
    color_map[2].middle = 0xdfcddb;
    color_map[2].stop  = 0xdfdfdf;
    color_map[2].color = "gray";

    HEADER_SKINFLEX_PROPS PropsH;
    HEADER_GetSkinFlexProps(&PropsH, 0);
    PropsH.aColorUpper[0] = color_map[color_scheme].stop;
    PropsH.aColorUpper[1] = color_map[color_scheme].middle;
    PropsH.aColorLower[0] = color_map[color_scheme].middle;
    PropsH.aColorLower[1] = color_map[color_scheme].start;
    HEADER_SetSkinFlexProps(&PropsH, 0);
}

void edit_text_cb(WM_MESSAGE * pMsg)
{
    int xw,yw;
    char   nm[6];
    WM_HWIN win = pMsg->hWin;
    GUI_RECT r;
    WIDGET *w;
    w = BUTTON_GetpWidget(win);
    r = w->Win.Rect;
    BUTTON_GetText(win, nm, 6);
    xw = (r.x1-r.x0);
    yw = r.y1-r.y0;
    switch (pMsg->MsgId)
    {
    case WM_PAINT:
        GUI_SetTextMode(GUI_TM_TRANS);
        GUI_SetPenSize(3);
        GUI_SetColor(0xe2e2e2);
        GUI_AA_FillRoundedRect(4,4,xw-4,yw-2,4);
        GUI_SetColor(0xaaaaaa);
        GUI_AA_DrawRoundedRect(2,2,xw-2,yw-2, 10);
        GUI_SetColor(GUI_DARKGRAY);
        GUI_SetFont(GUI_FONT_D24X32);
        r.x0 = 0;
        r.y0 = 0;
        r.x1 = xw;
        r.y1 = yw;
        GUI_DispStringInRect(nm, &r, GUI_TA_HCENTER | GUI_TA_VCENTER);
        break;
    default:
        BUTTON_Callback(pMsg);
        break;
    }
}

void buttonOn16_cb(WM_MESSAGE * pMsg)
{
    char nm[50];
    WM_HWIN win = pMsg->hWin;
    GUI_RECT r;
    WM_GetClientRect(&r);
    BUTTON_GetText(win, nm, 50);
    switch (pMsg->MsgId)
    {
    case WM_PAINT:
        if (BUTTON_IsPressed(pMsg->hWin))
        {
            drawButtonPush16(nm, r.x1-r.x0, r.y1-r.y0, 0);
        }
        else
        {
            drawButton16(nm, r.x1-r.x0, r.y1-r.y0, 1, 0);
        }
        break;
    default:
        BUTTON_Callback(pMsg);
        break;
    }
}

void buttonOff16_cb(WM_MESSAGE * pMsg)
{
    char nm[50];
    WM_HWIN win = pMsg->hWin;
    GUI_RECT r;
    WIDGET *w;
    w = BUTTON_GetpWidget(win);
    r = w->Win.Rect;
    BUTTON_GetText(win, nm, 50);
    switch (pMsg->MsgId)
    {
    case WM_PAINT:
        drawButtonOff16(nm, r.x1-r.x0, r.y1-r.y0, 0);
        break;
    default:
        BUTTON_Callback(pMsg);
        break;
    }
}

void buttonPush16_cb(WM_MESSAGE * pMsg)
{
    char nm[50];
    WM_HWIN win = pMsg->hWin;
    GUI_RECT r;
    WM_GetClientRect(&r);
    BUTTON_GetText(win, nm, 50);
    switch (pMsg->MsgId)
    {
    case WM_PAINT:
        if ( BUTTON_IsPressed(pMsg->hWin) == 1)
        {
            drawButtonPush16(nm, r.x1-r.x0, r.y1-r.y0, 0);
        }
        else
        {
            drawButton16(nm, r.x1-r.x0, r.y1-r.y0, 1, 0);
        }
        break;
    default:
        BUTTON_Callback(pMsg);
        break;
    }
}

void buttonPush22_cb(WM_MESSAGE * pMsg)
{
    char nm[50];
    WM_HWIN win = pMsg->hWin;
    GUI_RECT r;
    WM_GetClientRect(&r);
    BUTTON_GetText(win, nm, 50);
    switch (pMsg->MsgId)
    {
    case WM_PAINT:
        if (BUTTON_IsPressed(pMsg->hWin) == 1)
        {
            drawButtonPush22(nm, r.x1-r.x0, r.y1-r.y0, 0);
        }
        else
        {
            drawButton22(nm, r.x1-r.x0, r.y1-r.y0, 1, 0);
        }
        break;
    default:
        BUTTON_Callback(pMsg);
        break;
    }
}

void button20_cb(WM_MESSAGE * pMsg)
{
    char nm[50];
    WM_HWIN win = pMsg->hWin;
    GUI_RECT r;
    WM_GetClientRect(&r);
    BUTTON_GetText(win, nm, 50);
    switch (pMsg->MsgId)
    {
    case WM_PAINT:
        if (BUTTON_IsPressed(pMsg->hWin))
        {
            drawButtonPush20(nm, r.x1-r.x0, r.y1-r.y0, 0);
        }
        else
        {
            drawButton20(nm, r.x1-r.x0, r.y1-r.y0, 1, 0);
        }
        break;
    default:
        BUTTON_Callback(pMsg);
        break;
    }
}

void buttonOn20_cb(WM_MESSAGE * pMsg)
{
    char nm[50];
    GUI_RECT r;
    WM_GetClientRect(&r);
    BUTTON_GetText(pMsg->hWin, nm, 50);

    switch (pMsg->MsgId)
    {
    case WM_PAINT:
        drawButton20(nm, r.x1-r.x0, r.y1-r.y0, 1,0);
        break;
    default:
        BUTTON_Callback(pMsg);
        break;
    }
}

void button22_cb(WM_MESSAGE * pMsg)
{
    char nm[50];
    WM_HWIN win = pMsg->hWin;
    GUI_RECT r;
    WM_GetClientRect(&r);
    BUTTON_GetText(win, nm, 50);
    switch (pMsg->MsgId)
    {
    case WM_PAINT:
        if (BUTTON_IsPressed(pMsg->hWin))
        {
            drawButtonPush22(nm, r.x1-r.x0, r.y1-r.y0, 0);
        }
        else
        {
            drawButton22(nm, r.x1-r.x0, r.y1-r.y0, 1, 0);
        }
        break;
    default:
        BUTTON_Callback(pMsg);
        break;
    }
}

void buttonOn22_cb(WM_MESSAGE * pMsg)
{
    char nm[50];
    WM_HWIN win = pMsg->hWin;
    GUI_RECT r;
    WM_GetClientRect(&r);
    BUTTON_GetText(win, nm, 50);
    switch (pMsg->MsgId)
    {
    case WM_PAINT:
        drawButton22(nm, r.x1-r.x0, r.y1-r.y0, 1, 0);
        break;
    default:
        BUTTON_Callback(pMsg);
        break;
    }
}

void buttonOff22_cb(WM_MESSAGE * pMsg)
{
    char nm[50];
    WM_HWIN win = pMsg->hWin;
    GUI_RECT r;
    WM_GetClientRect(&r);
    BUTTON_GetText(win, nm, 50);
    switch (pMsg->MsgId)
    {
    case WM_PAINT:
        drawButton22(nm, r.x1-r.x0, r.y1-r.y0, 0, 0);
        break;
    default:
        BUTTON_Callback(pMsg);
        break;
    }
}


void drawButton16(char * but, int w, int h, int col, int bor)
{
    GUI_RECT rect;
    rect.x0 = 0;
    rect.y0 = 0;
    rect.x1 = w-1;
    rect.y1 = h-1;

    if (col)
    {
        GUI_DrawGradientRoundedV(0,0, rect.x1, rect.y1, 4, color_map[color_scheme].stop, color_map[color_scheme].start);
    }
    else
    {
        GUI_DrawGradientRoundedV(0, 0, rect.x1, rect.y1, 4, color_map[2].stop, color_map[2].start);
    }
    GUI_SetFont(&GUI_FontRounded16);
    GUI_SetColor((col == 2) ? GUI_BLACK : buttonTextColor);
    GUI_SetTextMode(GUI_TM_TRANS);
    GUI_DispStringInRect(but, &rect, GUI_TA_HCENTER | GUI_TA_VCENTER);
    GUI_SetColor(0x509e81);
    GUI_SetPenSize(2);
    if (bor) GUI_AA_DrawRoundedRect(0, 0, rect.x1, rect.y1, 8);
}

void drawButtonOff16(char * but, int w, int h, int col)
{
    GUI_RECT rect;
    rect.x0 = 0;
    rect.y0 = 0;
    rect.x1 = w-1;
    rect.y1 = h-1;
    GUI_DrawGradientRoundedV(0, 0, rect.x1, rect.y1, 4, color_map[2].stop, color_map[2].start);
    GUI_SetFont(&GUI_FontRounded16);
    GUI_SetColor((col == 2) ? GUI_BLACK : buttonTextColor);
    GUI_SetTextMode(GUI_TM_TRANS);
    GUI_DispStringInRect(but, &rect, GUI_TA_HCENTER | GUI_TA_VCENTER);
    GUI_SetColor(0x00cccccc);
    GUI_SetPenSize(2);
    //GUI_AA_DrawRoundedRect(0, 0, rect.x1, rect.y1, 6);
}

void drawButtonPush16(char * but, int w, int h, int col)
{
    GUI_RECT rect;
    rect.x0 = 0;
    rect.y0 = 0;
    rect.x1 = w-1;
    rect.y1 = h-1;
    GUI_DrawGradientRoundedV(0,0, rect.x1, rect.y1, 4, color_map[color_scheme].start, color_map[color_scheme].stop);
    GUI_SetFont(&GUI_FontRounded16);
    GUI_SetTextMode(GUI_TM_TRANS);
    GUI_DispStringInRect(but, &rect, GUI_TA_HCENTER | GUI_TA_VCENTER);
    GUI_SetColor(0x509e81);
    GUI_SetPenSize(2);
    //GUI_AA_DrawRoundedRect(0, 0, rect.x1, rect.y1, 8);

}

void drawButton20(char * but, int w, int h, int col, int bor)
{
    GUI_RECT rect;
    rect.x0 = 0;
    rect.y0 = 0;
    rect.x1 = w-1;
    rect.y1 = h-1;
    if (col)
    {
        GUI_DrawGradientRoundedV(0,0, rect.x1, rect.y1, 4, color_map[color_scheme].stop, color_map[color_scheme].start);
    }
    else
    {
        GUI_DrawGradientRoundedV(0, 0, rect.x1, rect.y1, 4, color_map[2].stop, color_map[2].start);
    }
    GUI_SetFont(&FontBig20B);
    GUI_SetColor((col == 2) ? GUI_BLACK : buttonTextColor);
    GUI_SetTextMode(GUI_TM_TRANS);
    GUI_DispStringInRect(but, &rect, GUI_TA_HCENTER | GUI_TA_VCENTER);
    GUI_SetColor(0x509e81);
    GUI_SetPenSize(2);
    if (bor) GUI_AA_DrawRoundedRect(0, 0, rect.x1, rect.y1, 6);
}

void drawButtonPush20(char * but, int w, int h, int col)
{
    GUI_RECT rect;
    rect.x0 = 0;
    rect.y0 = 0;
    rect.x1 = w-1;
    rect.y1 = h-1;
    GUI_DrawGradientRoundedV(0,0, rect.x1, rect.y1, 4, color_map[color_scheme].start, color_map[color_scheme].stop);
    GUI_SetFont(&FontBig20B);
    GUI_SetTextMode(GUI_TM_TRANS);
    GUI_DispStringInRect(but, &rect, GUI_TA_HCENTER | GUI_TA_VCENTER);
}

void drawButton22(char * but, int w, int h, int col, int bor)
{
    GUI_RECT rect;
    rect.x0 = 0;
    rect.y0 = 0;
    rect.x1 = w-1;
    rect.y1 = h-1;
    if (col)
    {
        GUI_DrawGradientRoundedV(0, 0, rect.x1, rect.y1, 4, color_map[color_scheme].stop, color_map[color_scheme].start);
    }
    else
    {
        GUI_DrawGradientRoundedV(0, 0, rect.x1, rect.y1, 4, color_map[2].stop, color_map[2].start);
    }
    GUI_SetFont(&GUI_FontRounded22);
    GUI_SetColor((col == 2) ? GUI_BLACK : buttonTextColor);
    GUI_SetTextMode(GUI_TM_TRANS);
    GUI_DispStringInRect(but, &rect, GUI_TA_HCENTER | GUI_TA_VCENTER);
    GUI_SetColor(0x509e81);
    GUI_SetPenSize(2);
    if (bor) GUI_AA_DrawRoundedRect(0, 0, rect.x1, rect.y1, 3);
}

void drawButtonPush22(char * but, int w, int h, int col)
{
    GUI_RECT rect;
    rect.x0 = 0;
    rect.y0 = 0;
    rect.x1 = w-1;
    rect.y1 = h-1;
    GUI_DrawGradientRoundedV(0,0, rect.x1, rect.y1, 4, color_map[color_scheme].start, color_map[color_scheme].stop);
    GUI_SetFont(&GUI_FontRounded22);
    GUI_SetTextMode(GUI_TM_TRANS);
    GUI_DispStringInRect(but, &rect, GUI_TA_HCENTER | GUI_TA_VCENTER);
}

void drawScheduleButton(char * but, int w, int h, int col, int bor)
{
    GUI_RECT rect;
    rect.x0 = 0;
    rect.y0 = 0;
    rect.x1 = w-1;
    rect.y1 = h-1;
    int xo;
    int yo;
    xo = bor * 2;
    yo = bor * 2;
    if (col)
    {
        GUI_DrawGradientRoundedV(xo, yo, rect.x1-xo, rect.y1-yo, 2, color_map[color_scheme].stop, color_map[color_scheme].start);
    }
    else
    {
        GUI_DrawGradientRoundedV(2, 2, rect.x1-2, rect.y1-2, 4, color_map[2].stop, color_map[2].start);
    }
    GUI_SetFont(&GUI_FontRounded22);
    GUI_SetColor((col == 6) ? GUI_BLACK : buttonTextColor);
    GUI_SetTextMode(GUI_TM_TRANS);
    GUI_DispStringInRect(but, &rect, GUI_TA_HCENTER | GUI_TA_VCENTER);
    GUI_SetColor((bor == 0) ? 0x00cccccc : GUI_RED);
    if (bor)
    {
        GUI_SetPenSize(3);
        GUI_AA_DrawRoundedRect(1, 1, rect.x1, rect.y1, 6);
    }
}

void drawCoolButton(char * but, int w, int h, int col, int bor)
{
    GUI_RECT rect;
    rect.x0 = 0;
    rect.y0 = 0;
    rect.x1 = w-1;
    rect.y1 = h-1;
    int xo;
    int yo;
    xo = bor * 2;
    yo = bor * 2;
    if (col)
    {
        GUI_DrawGradientRoundedV(xo, yo, rect.x1-xo+1, rect.y1-yo+1,4, color_map[color_scheme].stop, color_map[color_scheme].start);
    }
    else
    {
        GUI_DrawGradientRoundedV(2, 2, rect.x1-2, rect.y1-2, 4, color_map[2].stop, color_map[2].start);
    }
    GUI_SetFont(&GUI_FontRounded16);
    GUI_SetColor((col == 6) ? GUI_BLACK : buttonTextColor);
    GUI_SetTextMode(GUI_TM_TRANS);
    GUI_DispStringInRect(but, &rect, GUI_TA_HCENTER | GUI_TA_VCENTER);
    if (strcmp(but, "COOL") == 0)
    {
        GUI_SetColor((bor == 0) ? 0x00cccccc : 0xd1983d);
    }
    else
    {
        GUI_SetColor((bor == 0) ? 0x00cccccc : 0x4343cf);
    }
    if (bor)
    {
        GUI_SetPenSize(3);
        GUI_AA_DrawRoundedRect(1, 1, rect.x1, rect.y1, 6);
    }
}

void drawProfileButton(char * but, int w, int h, int col)
{
    GUI_RECT rect;
    rect.x0 = 4;
    rect.y0 = 0;
    rect.x1 = w;
    rect.y1 = h;
    GUI_DrawGradientRoundedV(0, 0, w, h, 4, color_map[col].stop, color_map[col].start);
    GUI_SetFont(&GUI_FontRounded22);
    GUI_SetColor(GUI_WHITE);
    GUI_SetTextMode(GUI_TM_TRANS);
    GUI_DispStringInRect(but, &rect, GUI_TA_LEFT | GUI_TA_VCENTER);
    GUI_SetColor(GUI_LIGHTGRAY);
    GUI_SetPenSize(2);
    //GUI_AA_DrawRoundedRect(0, 0, 74, 23, 4);
}

void drawButton(char * but, int col)
{
    GUI_RECT rect;
    rect.x0 = 0;
    rect.y0 = 0;
    rect.x1 = 73;
    rect.y1 = 26;
    GUI_DrawGradientRoundedV(0, 0, rect.x1, rect.y1, 4, color_map[col].stop, color_map[col].start);
    GUI_SetFont(&GUI_FontRounded16);
    GUI_SetColor(buttonTextColor);
    GUI_SetTextMode(GUI_TM_TRANS);
    GUI_DispStringInRect(but, &rect, GUI_TA_HCENTER | GUI_TA_VCENTER);
    GUI_SetColor(GUI_LIGHTGRAY);
    GUI_SetPenSize(2);
    //GUI_AA_DrawRoundedRect(0, 0, 74, 23, 4);
}

#define TRANS0    0xAA000000
#define TRANS1    0xEE000000
#define TRANS2    0xFF000000

//#define TRANS0    0x1163b39b
//#define TRANS1    0xEE48866c
//#define TRANS2    0xFF000000
//    color_map[0].start = 0x48866c;
//    color_map[0].middle = 0x509e81;
//    color_map[0].stop  = 0x63b39b;
//    color_map[0].color = "green";
//
//#define TRANS0    0x112b7218
//#define TRANS1    0xEE48866c
//#define TRANS2    0xFF48866c

int OwnerDraw(const WIDGET_ITEM_DRAW_INFO * pDrawItemInfo)
{
    WM_HWIN   hWin;
    WHEEL   * pWheel;
    int       xPos;
    int       yPos;
    int       xSizeWin;
    int       ySizeWin;
    int       xSizeDev;

    hWin = pDrawItemInfo->hWin;
    //
    // Process messages
    //
    switch (pDrawItemInfo->Cmd)
    {
    case WIDGET_ITEM_GET_XSIZE:
        //
        // Return x-size of item
        //
        return LISTWHEEL_OwnerDraw(pDrawItemInfo);
    case WIDGET_ITEM_GET_YSIZE:
        //
        // Return y-size of item
        //
        return LISTWHEEL_OwnerDraw(pDrawItemInfo);
    case WIDGET_ITEM_DRAW:
        //
        // Draw item
        //
        return LISTWHEEL_OwnerDraw(pDrawItemInfo);
    case WIDGET_ITEM_DRAW_BACKGROUND:
        xSizeWin = WM_GetWindowSizeX(hWin);
        ySizeWin = WM_GetWindowSizeY(hWin);
        //
        // Draw background
        //
         GUI_SetColor(0x00FFFFFF);
        GUI_FillRect(4, 0, xSizeWin - 5, ySizeWin - 1);
        break;
    case WIDGET_ITEM_DRAW_OVERLAY:
        LISTWHEEL_GetUserData(hWin, &pWheel, sizeof(pWheel));
        xPos     = WM_GetWindowOrgX(hWin);
        yPos     = WM_GetWindowOrgY(hWin);
        xSizeWin = WM_GetWindowSizeX(hWin);
        xSizeDev = GUI_MEMDEV_GetXSize(pWheel->hMemRBorder);
        //
        // Draw border
        //
        GUI_MEMDEV_WriteAt(pWheel->hMemLBorder, xPos, yPos);
        GUI_MEMDEV_WriteAt(pWheel->hMemRBorder, xPos + xSizeWin - xSizeDev, yPos);
        //
        // Draw overlay
        //
        GUI_MEMDEV_WriteAt(pWheel->hMemOverlay, xPos, yPos);
        break;
    }
    return 0;
}

void CreateDecoration(int xSize, int ySize, int LineHeight, WHEEL * pWheel)
{
    GUI_MEMDEV_Handle hMemPrev;
    GUI_MEMDEV_Handle hMemRBorder;
    GUI_MEMDEV_Handle hMemLBorder;
    GUI_MEMDEV_Handle hMemOverlay;

    //
    // Create left border
    //
    hMemLBorder = GUI_MEMDEV_CreateFixed(0, 0, 4, ySize, GUI_MEMDEV_NOTRANS, GUI_MEMDEV_APILIST_32, GUI_COLOR_CONV_8888);
    hMemPrev = GUI_MEMDEV_Select(hMemLBorder);
    GUI_SetColor(GUI_LIGHTGRAY);
    GUI_DrawVLine(0, 0, ySize - 1);
    GUI_SetColor(GUI_LIGHTGRAY);
    GUI_FillRect(1, 0, 3, ySize - 1);
    //
    // Create right border
    //
    hMemRBorder = GUI_MEMDEV_CreateFixed(0, 0, 4, ySize, GUI_MEMDEV_NOTRANS, GUI_MEMDEV_APILIST_32, GUI_COLOR_CONV_8888);
    GUI_MEMDEV_Select(hMemRBorder);
    GUI_SetColor(GUI_LIGHTGRAY);
    GUI_DrawVLine(3, 0, ySize - 1);
    GUI_SetColor(GUI_LIGHTGRAY);
    GUI_FillRect(0, 0, 2, ySize - 1);
    //
    // Create overlay device
    //
    hMemOverlay = GUI_MEMDEV_CreateFixed(0, 0, xSize, ySize,
                                         GUI_MEMDEV_NOTRANS, GUI_MEMDEV_APILIST_32, GUI_COLOR_CONV_8888);
    GUI_MEMDEV_Select(hMemOverlay);
    //
    // Gray gradients at top
    //
    GUI_DrawGradientV(0,                0,                   xSize - 1, (ySize * 2) / 10 - 1,               TRANS0,     TRANS1);
    GUI_DrawGradientV(0, (ySize * 2) / 10,                   xSize - 1, (ySize / 2) - (LineHeight / 2) - 1, TRANS1,     TRANS2);
    //
    // Gray gradients at bottom
    //
    GUI_DrawGradientV(0, (ySize / 2) + (LineHeight / 2),     xSize - 1, (ySize / 2) + (LineHeight / 2) + 2, 0x88000000, TRANS2);
    GUI_DrawGradientV(0, (ySize / 2) + (LineHeight / 2) + 3, xSize - 1, ySize - (ySize * 2) / 10 - 1,       TRANS2,     TRANS1);
    GUI_DrawGradientV(0, ySize - (ySize * 2) / 10,           xSize - 1, ySize - 1,                          TRANS1,     TRANS0);
    GUI_DrawGradientV(0, ySize - 1,                          xSize - 1, ySize - 1,                          0x33000000, 0x33000000);
    //
    // Translucent glass effect in the middle
    //
    GUI_SetColor(0x80000000);
    GUI_DrawHLine((ySize / 2) - (LineHeight / 2),     0, xSize - 1);
    GUI_SetColor(0x44000000);
    GUI_DrawHLine((ySize / 2) + (LineHeight / 2) - 1, 0, xSize - 1);
    GUI_DrawGradientV(1, (ySize / 2) - (LineHeight / 2) + 1, xSize - 2, (ySize / 2) - 1,                    0x88FFFFFF, 0x55AAAAAA);
    GUI_DrawGradientV(1, (ySize / 2),                        xSize - 2, (ySize / 2) + (LineHeight / 2) - 2, 0xBB000000, 0xBB000000);
    GUI_MEMDEV_Select(hMemPrev);
    //
    // Store result
    //
    pWheel->hMemLBorder = hMemLBorder;
    pWheel->hMemRBorder = hMemRBorder;
    pWheel->hMemOverlay = hMemOverlay;
}

int CreateListWheel(int x, int y, int xSize, int ySize, int Id,
                    char ** apText, int NumItems, int LineHeight, int TextAlign,
                    WM_HWIN hParent, WHEEL * pWheel, GUI_FONT *pFont, int pos)
{
    WM_HWIN                      hWin;
    int                          i;

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

    LISTWHEEL_SetPos(hWin, pos);
    LISTWHEEL_SetSel(hWin, pos);

    // Create overlay devices
    CreateDecoration(xSize, ySize, LineHeight, pWheel);
    // Fill WHEEL structure
    pWheel->hWin = hWin;
    return 0;
}

void _cbBkWheel(WM_MESSAGE * pMsg)
{
    WM_HWIN hParent;
    int     xSize;
    int     ySize;

    switch (pMsg->MsgId)
    {
    case WM_NOTIFY_PARENT:
        break;
    case WM_PAINT:
        break;
    default:

        WM_DefaultProc(pMsg);
    }
}

char * updateTime(char *tm, int dr)
{
    static  char buf[10];
    int hh, mm,am;
    sscanf(tm, "%d:%d", &hh, &mm);

    if (strchr(tm, 'a'))
    {
        am = 1;
    }
    else
    {
        am = 0;
    }

    if (dr == -1)
    {
        mm--;
        if (mm == -1)
        {
            mm = 59;
            hh--;
            if (hh == 11) am = !am;
        }
        if (hh == 0)
        {
            hh = 12;
        }
    }
    else
    {
        mm++;
        if (mm == 60)
        {
            mm = 0;
            hh++;
            if (hh == 12) am = !am;
        }
        if (hh == 13)
        {
            hh = 1;
        }
    }

    sprintf(buf,"%d:%02d%s\n", hh, mm, (am == 1) ? "am" : "pm");
    return buf;
}

void scheduleButton(WM_MESSAGE * pMsg, char *nm, int on)
{
    switch (pMsg->MsgId)
    {
    case WM_PAINT:
        drawButton16(nm,90, 26, on, 0);
        break;
    default:
        BUTTON_Callback(pMsg);
        break;
    }
}


