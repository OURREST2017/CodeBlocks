#include "main.h"

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

    color_map[1].start = 0xb7a491;
    color_map[1].middle = 0xccaeae;
    color_map[1].stop  = 0xedb6bd;
    color_map[1].color = "lightblue";

    color_map[2].start = 0x85b4cb;
    color_map[2].middle = 0x9ecede;
    color_map[2].stop  = 0xa1e6fd;
    color_map[2].color = "yellow";

    color_map[3].start = 0xb794c2;
    color_map[3].middle = 0xceaecf;
    color_map[3].stop  = 0xdfc4d8;
    color_map[3].color = "pink";

    color_map[4].start = 0x7a5114;
    color_map[4].middle = 0x9a5924;
    color_map[4].stop  = 0xc1842d;
    color_map[4].color = "blue";

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

// blue outline c1882d
// red outline 4444ccc1
// gray text 808080\

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
        GUI_DrawHLine(y++, x1++, x2--);
        g0 += gs;
        b0 += bs;
        r0 += rs;
    }
    GUI_SetColor(GUI_LIGHTGRAY);
    //GUI_AA_DrawPolyOutline(aPoints, countof(aPoints), 2, 4, 27);
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
        GUI_DrawGradientRoundedV(xo, yo, rect.x1-xo, rect.y1-yo, 2, color_map[color_scheme].stop, color_map[color_scheme].start);
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

