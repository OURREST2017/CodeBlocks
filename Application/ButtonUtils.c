#include "main.h"

#define TRANS0    0x1163b39b
#define TRANS1    0xEE48866c
#define TRANS2    0xFF000000

int color_scheme;

typedef struct colors
{
    GUI_COLOR start;
    GUI_COLOR middle;
    GUI_COLOR stop;
    char * color;
} colors;

struct colors color_map[7];

void initColors()
{
    color_map[0].start = 0x48866c;
    color_map[0].middle = 0x509e81;
    color_map[0].stop  = 0x63b39b;
    color_map[0].color = "green";

    color_map[5].start = 0x272780;
    color_map[5].middle = 0x38389e;
    color_map[5].stop  = 0x4343bf;
    color_map[5].color = "red";

    color_map[6].start = 0xdfc4d8;
    color_map[6].middle = 0xdfcddb;
    color_map[6].stop  = 0xdfdfdf;
    color_map[6].color = "gray";

    setSkin();
}
//9cb464
void setSkin()
{
    HEADER_SKINFLEX_PROPS PropsH;
    HEADER_GetSkinFlexProps(&PropsH, 0);
    PropsH.aColorUpper[0] = color_map[color_scheme].stop;
    PropsH.aColorUpper[1] = color_map[color_scheme].middle;
    PropsH.aColorLower[0] = color_map[color_scheme].middle;
    PropsH.aColorLower[1] = color_map[color_scheme].start;
    HEADER_SetSkinFlexProps(&PropsH, 0);
}

void drawBigUpButton()
{
    GUI_POINT aPoints[] =
    {
        { 0, 44 },
        { 24, 0 },
        { 50, 44 },
        {0, 44}
    };
    int i,y,x1,x2,r,g,b;
    x1 = 24;
    y = 4;
    x2 = 24;
    float gs,bs,rs,r0,g0,b0,r1,b1,g1;
    GUI_COLOR Color;

    r0  = (color_map[color_scheme].stop>>  0) & 0x000000ff;
    g0  = (color_map[color_scheme].stop >>  8) & 0x000000ff;
    b0  = (color_map[color_scheme].stop >> 16) & 0x000000ff;
    r1  = (color_map[color_scheme].start >>  0) & 0x000000ff;
    g1  = (color_map[color_scheme].start >>  8) & 0x000000ff;
    b1  = (color_map[color_scheme].start >> 16) & 0x000000ff;

    bs = (b0-b1)/30.;
    rs = (r0-r1)/30.;
    gs = (g0-g1)/30.;

    for (i=0; i<21; i++)
    {
        Color = (int)r0 | ((int)g0 << 8) | ((int)b0 << 16);
        GUI_SetColor(Color);
        GUI_DrawHLine(y++, x1, x2);
        g0 -= gs;
        b0 -= bs;
        r0 -= rs;
        Color = (int)r0 | ((int)g0 << 8) | ((int)b0 << 16);
        GUI_SetColor(Color);
        GUI_DrawHLine(y++, x1--, x2++);
        g0 -= gs;
        b0 -= bs;
        r0 -= rs;
    }
    GUI_SetColor(GUI_LIGHTGRAY);
    //GUI_AA_DrawPolyOutline(aPoints, countof(aPoints), 2, 4, 27);
}

void drawBigDnButton()
{
    GUI_POINT aPoints[] =
    {
        { 0, 44 },
        { 24, 0 },
        { 50, 44 },
        {0, 44}
    };
    int i,y,x1,x2,r,g,b;
    x1 = 4;
    x2 = 44;
    y = 4;
    float gs,bs,rs,r0,g0,b0,r1,b1,g1;
    GUI_COLOR Color;

    r0  = (color_map[color_scheme].start>>  0) & 0x000000ff;
    g0  = (color_map[color_scheme].start >> 8) & 0x000000ff;
    b0  = (color_map[color_scheme].start >> 16) & 0x000000ff;
    r1  = (color_map[color_scheme].stop >>  0) & 0x000000ff;
    g1  = (color_map[color_scheme].stop >>  8) & 0x000000ff;
    b1  = (color_map[color_scheme].stop >> 16) & 0x000000ff;

    bs = (b1-b0)/30.;
    rs = (r1-r0)/30.;
    gs = (g1-g0)/30.;

    for (i=0; i<21; i++) //21
    {
        Color = (int)r0 | ((int)g0 << 8) | ((int)b0 << 16);
        GUI_SetColor(Color);
        GUI_DrawHLine(y++, x1, x2);
        g0 += gs;
        b0 += bs;
        r0 += rs;
        Color = (int)r0 | ((int)g0 << 8) | ((int)b0 << 16);
        GUI_SetColor(Color);
//        if (i == 0)
//        {
//            GUI_DrawHLine(y++, x1+4, x2-4);
//        }
//        else if (i == 1)
//        {
//            GUI_DrawHLine(y++, x1+2, x2-2);
//        }
//        else if (i == 2)
//        {
//            GUI_DrawHLine(y++, x1+1, x2-1);
//        }
//        else if (i == 3)
//        {
//            GUI_DrawHLine(y++, x1+1, x2-1);
//        }
//        else
//        {
//            GUI_DrawHLine(y++, x1, x2);
//        }
        GUI_DrawHLine(y++, x1, x2);
        x1++;
        x2--;
        g0 += gs;
        b0 += bs;
        r0 += rs;
    }
    GUI_SetColor(GUI_RED);
    //GUI_AA_DrawPolyOutline(aPoints, 4, 2, 4, 27);
}

void drawSmallUpButton()
{
    GUI_POINT aPoints[] =
    {
        { 0, 22 },
        { 12, 0 },
        { 25, 22 }
    };
    int i,y,x1,x2,r,g,b;
    GUI_COLOR Color;

    x1 = 15;
    y = 4;
    x2 = 15;
    float gs,bs,rs,r0,g0,b0,r1,b1,g1;

    r0  = (color_map[color_scheme].stop >>  0) & 0x000000ff;
    g0  = (color_map[color_scheme].stop >>  8) & 0x000000ff;
    b0  = (color_map[color_scheme].stop >> 16) & 0x000000ff;
    r1  = (color_map[color_scheme].start >>  0) & 0x000000ff;
    g1  = (color_map[color_scheme].start >>  8) & 0x000000ff;
    b1  = (color_map[color_scheme].start >> 16) & 0x000000ff;

    bs = (b0-b1)/24.;
    rs = (r0-r1)/24.;
    gs = (g0-g1)/24.;

    for (i=0; i<12; i++)
    {
        Color = (int)r0 | ((int)g0 << 8) | ((int)b0 << 16);
        GUI_SetColor(Color);
        GUI_DrawHLine(y++, x1, x2);
        g0 -= gs;
        b0 -= bs;
        r0 -= rs;
        Color = (int)r0 | ((int)g0 << 8) | ((int)b0 << 16);
        GUI_SetColor(Color);
        GUI_DrawHLine(y++, x1--, x2++);
        g0 -= gs;
        b0 -= bs;
        r0 -= rs;
    }
    //GUI_AA_DrawPolyOutline(aPoints, countof(aPoints), 2, 4, 27);

}
//9bb363 8da758 819e50 79954c 6c8748
//63b39b 58a78d 509e81 4c9579 48876c
void drawSmallDnButton()
{
    GUI_POINT aPoints[] =
    {
        { 0, 22 },
        { 12, 0 },
        { 25, 22 }
    };
    int i,y,x1,x2,r,g,b;

    x1 = 4;
    y = 4;
    x2 = 26;

    float gs,bs,rs,r0,g0,b0,r1,b1,g1;
    GUI_COLOR Color;

    r0  = (color_map[color_scheme].start>>  0) & 0x000000ff;
    g0  = (color_map[color_scheme].start >> 8) & 0x000000ff;
    b0  = (color_map[color_scheme].start >> 16) & 0x000000ff;
    r1  = (color_map[color_scheme].stop >>  0) & 0x000000ff;
    g1  = (color_map[color_scheme].stop >>  8) & 0x000000ff;
    b1  = (color_map[color_scheme].stop >> 16) & 0x000000ff;

    bs = (b1-b0)/20.;
    rs = (r1-r0)/20.;
    gs = (g1-g0)/20.;

    for (i=0; i<12; i++)
    {
        Color = (int)r0 | ((int)g0 << 8) | ((int)b0 << 16);
        GUI_SetColor(Color);
        GUI_DrawHLine(y++, x1, x2);
        g0 += gs;
        b0 += bs;
        r0 += rs;
        Color = (int)r0 | ((int)g0 << 8) | ((int)b0 << 16);
        GUI_SetColor(Color);
        GUI_DrawHLine(y++, x1++, x2--);
        g0 += gs;
        b0 += bs;
        r0 += rs;
    }
    //GUI_AA_DrawPolyOutline(aPoints, countof(aPoints), 2, 4, 27);
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
void small_up_button(WM_MESSAGE * pMsg)
{
    switch (pMsg->MsgId)
    {
    case WM_PAINT:
        drawSmallUpButton();
        break;
    default:
        BUTTON_Callback(pMsg);
        break;
    }
}

void small_dn_button(WM_MESSAGE * pMsg)
{
    switch (pMsg->MsgId)
    {
    case WM_PAINT:
        drawSmallDnButton();
        break;
    default:
        BUTTON_Callback(pMsg);
        break;
    }
}

void big_up_button(WM_MESSAGE * pMsg)
{
    switch (pMsg->MsgId)
    {
    case WM_PAINT:
        drawBigUpButton();
        break;
    default:
        BUTTON_Callback(pMsg);
        break;
    }
}

void big_dn_button(WM_MESSAGE * pMsg)
{
    switch (pMsg->MsgId)
    {
    case WM_PAINT:
        drawBigDnButton();
        break;
    default:
        BUTTON_Callback(pMsg);
        break;
    }
}

void buttonOn20_cb(WM_MESSAGE * pMsg)
{
    char buf[50], nm[50];
    WM_HWIN win = pMsg->hWin;
    GUI_RECT r;
    WIDGET *w;
    w = BUTTON_GetpWidget(win);
    r = w->Win.Rect;
    BUTTON_GetText(win, nm, 50);
    switch (pMsg->MsgId)
    {
    case WM_PAINT:
        drawButton20(nm, r.x1-r.x0, r.y1-r.y0, 1);
        break;
    default:
        BUTTON_Callback(pMsg);
        break;
    }
}

void buttonOn16_cb(WM_MESSAGE * pMsg)
{
    char buf[50], nm[50];
    WM_HWIN win = pMsg->hWin;
    GUI_RECT r;
    WIDGET *w;
    w = BUTTON_GetpWidget(win);
    r = w->Win.Rect;
    BUTTON_GetText(win, nm, 50);
//      BUTTON_GetUserData(win, buf, 3);
    sprintf(buf,"%d,%s,%d,%d,%d,%d",w->Id,nm,r.x0,r.y0,r.x1,r.y1);
//    GUI_ErrorOut(buf);
    switch (pMsg->MsgId)
    {
    case WM_PAINT:
        //GUI_ErrorOut(buf);
        drawButton16(nm, r.x1-r.x0, r.y1-r.y0, 1);
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
        drawButton16(nm, r.x1-r.x0, r.y1-r.y0, 0);
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
    WIDGET *w;
    w = BUTTON_GetpWidget(win);
    r = w->Win.Rect;
    BUTTON_GetText(win, nm, 50);
    switch (pMsg->MsgId)
    {
    case WM_PAINT:
        drawButton22(nm, r.x1-r.x0, r.y1-r.y0, 1);
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
    WIDGET *w;
    w = BUTTON_GetpWidget(win);
    r = w->Win.Rect;
    BUTTON_GetText(win, nm, 50);
    switch (pMsg->MsgId)
    {
    case WM_PAINT:
        drawButton22(nm, r.x1-r.x0, r.y1-r.y0, 0);
        break;
    default:
        BUTTON_Callback(pMsg);
        break;
    }
}

void drawButton20(char * but, int w, int h, int col)
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
        GUI_DrawGradientRoundedV(0, 0, rect.x1, rect.y1, 4, color_map[6].stop, color_map[6].start);
    }
    GUI_SetFont(&FontBig20B);
    GUI_SetColor((col == 6) ? GUI_BLACK : GUI_WHITE);
    GUI_SetTextMode(GUI_TM_TRANS);
    GUI_DispStringInRect(but, &rect, GUI_TA_HCENTER | GUI_TA_VCENTER);
    GUI_SetColor(0x00cccccc);
    GUI_SetPenSize(2);
    //GUI_AA_DrawRoundedRect(0, 0, rect.x1, rect.y1, 6);
}

void drawButton16(char * but, int w, int h, int col)
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
        GUI_DrawGradientRoundedV(0, 0, rect.x1, rect.y1, 4, color_map[6].stop, color_map[6].start);
    }
    GUI_SetFont(&GUI_FontRounded16);
    GUI_SetColor((col == 6) ? GUI_BLACK : GUI_WHITE);
    GUI_SetTextMode(GUI_TM_TRANS);
    GUI_DispStringInRect(but, &rect, GUI_TA_HCENTER | GUI_TA_VCENTER);
    GUI_SetColor(0xdbdbdb);
    GUI_SetPenSize(2);
    //GUI_AA_DrawRoundedRect(0, 0, rect.x1, rect.y1, 10);
}

void drawButtonOff16(char * but, int w, int h, int col)
{
    GUI_RECT rect;
    rect.x0 = 0;
    rect.y0 = 0;
    rect.x1 = w-1;
    rect.y1 = h-1;
    GUI_DrawGradientRoundedV(0, 0, rect.x1, rect.y1, 4, color_map[6].stop, color_map[6].start);
    GUI_SetFont(&GUI_FontRounded16);
    GUI_SetColor((col == 6) ? GUI_BLACK : GUI_WHITE);
    GUI_SetTextMode(GUI_TM_TRANS);
    GUI_DispStringInRect(but, &rect, GUI_TA_HCENTER | GUI_TA_VCENTER);
    GUI_SetColor(0x00cccccc);
    GUI_SetPenSize(2);
    //GUI_AA_DrawRoundedRect(0, 0, rect.x1, rect.y1, 6);
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
        GUI_DrawGradientRoundedV(2, 2, rect.x1-2, rect.y1-2, 4, color_map[6].stop, color_map[6].start);
    }
    GUI_SetFont(&GUI_FontRounded22);
    GUI_SetColor((col == 6) ? GUI_BLACK : GUI_WHITE);
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
        GUI_DrawGradientRoundedV(2, 2, rect.x1-2, rect.y1-2, 4, color_map[6].stop, color_map[6].start);
    }
//    GUI_DrawGradientRoundedV(2,1, rect.x1-1, rect.y1-1, 4, color_map[color_scheme].stop, color_map[color_scheme].start);
    GUI_SetFont(&GUI_FontRounded16);
    GUI_SetColor((col == 6) ? GUI_BLACK : GUI_WHITE);
    GUI_SetTextMode(GUI_TM_TRANS);
    GUI_DispStringInRect(but, &rect, GUI_TA_HCENTER | GUI_TA_VCENTER);
    if (strcmp(but, "COOL") == 0)
    {
        GUI_SetColor((bor == 0) ? 0x00cccccc : 0xd1983d);
    }
    else
    {
        GUI_SetColor((bor == 0) ? 0x00cccccc : GUI_RED);
    }
    if (bor)
    {
        GUI_SetPenSize(3);
        GUI_AA_DrawRoundedRect(1, 1, rect.x1, rect.y1, 6);
    }
}

void drawButton22(char * but, int w, int h, int col)
{
    GUI_RECT rect;
    rect.x0 = 0;
    rect.y0 = 0;
    rect.x1 = w;
    rect.y1 = h;
    if (col)
    {
        GUI_DrawGradientRoundedV(2, 2, rect.x1-2, rect.y1-2, 4, color_map[color_scheme].stop, color_map[color_scheme].start);
    }
    else
    {
        GUI_DrawGradientRoundedV(2, 2, rect.x1-2, rect.y1-2, 4, color_map[6].stop, color_map[6].start);
    }
    GUI_SetFont(&GUI_FontRounded22);
    GUI_SetColor((col == 6) ? GUI_BLACK : GUI_WHITE);
    GUI_SetTextMode(GUI_TM_TRANS);
    GUI_DispStringInRect(but, &rect, GUI_TA_HCENTER | GUI_TA_VCENTER);
    GUI_SetColor(0x00cccccc);
    GUI_SetPenSize(2);
    //GUI_AA_DrawRoundedRect(2, 2, rect.x1-2, rect.y1-2, 3);
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
    GUI_SetColor(GUI_WHITE);
    GUI_SetTextMode(GUI_TM_TRANS);
    GUI_DispStringInRect(but, &rect, GUI_TA_HCENTER | GUI_TA_VCENTER);
    GUI_SetColor(GUI_LIGHTGRAY);
    GUI_SetPenSize(2);
    //GUI_AA_DrawRoundedRect(0, 0, 74, 23, 4);
}

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
    GUI_SetColor(GUI_LIGHTGREEN);
    GUI_DrawVLine(0, 0, ySize - 1);
    GUI_SetColor(GUI_LIGHTGRAY);
    GUI_FillRect(1, 0, 3, ySize - 1);
    //
    // Create right border
    //
    hMemRBorder = GUI_MEMDEV_CreateFixed(0, 0, 4, ySize, GUI_MEMDEV_NOTRANS, GUI_MEMDEV_APILIST_32, GUI_COLOR_CONV_8888);
    GUI_MEMDEV_Select(hMemRBorder);
    GUI_SetColor(GUI_LIGHTGREEN);
    GUI_DrawVLine(3, 0, ySize - 1);
    GUI_SetColor(GUI_LIGHTGRAY);
    GUI_FillRect(0, 0, 2, ySize - 1);
    //
    // Create overlay device
    //
    hMemOverlay = GUI_MEMDEV_CreateFixed(0, 0, xSize, ySize, GUI_MEMDEV_NOTRANS, GUI_MEMDEV_APILIST_32, GUI_COLOR_CONV_8888);
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
    LISTWHEEL_SetTextColor(hWin, LISTWHEEL_CI_SEL, GUI_LIGHTBLUE);
    for (i = 0; i < NumItems; i++)
    {
        LISTWHEEL_AddString(hWin, *(apText + i));
    }
    if (TextAlign & GUI_TA_RIGHT)
    {
        LISTWHEEL_SetRBorder(hWin, 10);
    }

    LISTWHEEL_SetPos(hWin, pos);

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
    int hh, mm ,am;
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

void scheduleButton(WM_MESSAGE * pMsg, char *nm, int on) {
    switch (pMsg->MsgId)
    {
    case WM_PAINT:
        drawButton16(nm ,90, 26, on);
        break;
    default:
        BUTTON_Callback(pMsg);
        break;
    }
}


