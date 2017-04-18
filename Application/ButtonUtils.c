#include "ranger.h"

int color_scheme;
GUI_COLOR buttonTextColor = 0xffffff;

void initColors()
{
//    color_map[0].start  = 0x00763c;       // 72 134 108
//    color_map[0].middle = 0x009e5a;       // 80 158 129
//    color_map[0].stop   = 0x00b364;       // 99 179 155
//
//    color_map[0].start = 0x48866c;
//    color_map[0].middle = 0x509e81;
//    color_map[0].stop  = 0x63b39b;
//
    color_map[0].start  = 0x00763c;       // 72 134 108
    color_map[0].middle = 0x009e5a;       // 80 158 129
    color_map[0].stop   = 0x00b364;       // 99 179 155

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
}

void buttonOn_cb(WM_MESSAGE * pMsg)
{
    char nm[50];
    WM_HWIN win = pMsg->hWin;
    GUI_RECT r, rect;
    WM_GetClientRect(&r);

    BUTTON_GetText(win, nm, 50);
    switch (pMsg->MsgId)
    {
    case WM_PAINT:
        if (BUTTON_IsPressed(pMsg->hWin))
        {
            drawButtonPush18(nm, r.x1-r.x0, r.y1-r.y0, 0);
        }
        else
        {
            drawButton18(nm, r.x1-r.x0, r.y1-r.y0, 1, 0);
        }
        break;
    default:
        BUTTON_Callback(pMsg);
        break;
    }
}

void buttonOff_cb(WM_MESSAGE * pMsg)
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
        drawButtonOff18(nm, r.x1-r.x0, r.y1-r.y0, 0);
        break;
    default:
        BUTTON_Callback(pMsg);
        break;
    }
}

void buttonPush_cb(WM_MESSAGE * pMsg)
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
            drawButtonPush18(nm, r.x1-r.x0, r.y1-r.y0, 0);
        }
        else
        {
            drawButton18(nm, r.x1-r.x0, r.y1-r.y0, 1, 0);
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

void drawButton18(char * but, int w, int h, int col, int bor)
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
    GUI_SetFont(Tahoma18B);
    if (col == 0) GUI_SetColor(0x666666);
    if (col == 1) GUI_SetColor(buttonTextColor);
    if (col == 2) GUI_SetColor(GUI_BLACK);
    GUI_SetTextMode(GUI_TM_TRANS);
    GUI_DispStringInRect(LANG(but), &rect, GUI_TA_HCENTER | GUI_TA_VCENTER);
}

void drawButtonOff18(char * but, int w, int h, int col)
{
    GUI_RECT rect;
    rect.x0 = 0;
    rect.y0 = 0;
    rect.x1 = w-1;
    rect.y1 = h-1;
    GUI_DrawGradientRoundedV(0, 0, rect.x1, rect.y1, 4, color_map[2].stop, color_map[2].start);
    GUI_SetColor((col == 2) ? GUI_BLACK : buttonTextColor);
    GUI_SetTextMode(GUI_TM_TRANS);
    GUI_DispStringInRect(LANG(but), &rect, GUI_TA_HCENTER | GUI_TA_VCENTER);
}

void drawButtonPush18(char * but, int w, int h, int col)
{
    GUI_RECT rect;
    rect.x0 = 0;
    rect.y0 = 0;
    rect.x1 = w-1;
    rect.y1 = h-1;
    GUI_DrawGradientRoundedV(0,0, rect.x1, rect.y1, 4, color_map[color_scheme].start, color_map[color_scheme].stop);
    GUI_SetFont(Tahoma18B);
    GUI_SetTextMode(GUI_TM_TRANS);
    GUI_DispStringInRect(LANG(but), &rect, GUI_TA_HCENTER | GUI_TA_VCENTER);
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
    GUI_SetFont(Tahoma19B);
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
    GUI_SetFont(Tahoma19B);
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
    if (col == 1)
    {
        GUI_DrawGradientRoundedV(0, 0, rect.x1, rect.y1, 4, color_map[color_scheme].stop, color_map[color_scheme].start);
    }
    else
    {
        GUI_DrawGradientRoundedV(0, 0, rect.x1, rect.y1, 4, color_map[2].stop, color_map[2].start);
    }
    GUI_SetFont(Tahoma23B);
    GUI_SetColor((col == 2) ? 0x666666 : buttonTextColor);
    GUI_SetTextMode(GUI_TM_TRANS);
    GUI_DispStringInRect(LANG(but), &rect, GUI_TA_HCENTER | GUI_TA_VCENTER);
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
    GUI_SetFont(Tahoma23B);
    GUI_SetTextMode(GUI_TM_TRANS);
    GUI_DispStringInRect(LANG(but), &rect, GUI_TA_HCENTER | GUI_TA_VCENTER);
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
    GUI_SetFont(Tahoma18B);
    GUI_SetColor((col == 6) ? GUI_BLACK : buttonTextColor);
    GUI_SetTextMode(GUI_TM_TRANS);
    GUI_DispStringInRect(LANG(but), &rect, GUI_TA_HCENTER | GUI_TA_VCENTER);
    if (strcmp(but, "COOL") == 0 || strcmp(but, "GUAY") == 0)
    {
        GUI_SetColor((bor == 0) ? 0x00cccccc : 0xd1a83d);
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

char * updateTime(char *tm, int dr, int *tout)
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
        mm -= 15;
        if (mm < 0)
        {
            mm = 45;
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
        mm += 15;
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

    if (am == 0) {
        *tout = hh * 100 + mm;
    } else {
        *tout = (hh + 12) * 100 + mm;
    }
    sprintf(buf,"%d:%02d%s", hh, mm, (am == 1) ? "am" : "pm");

    return buf;
}

int returnSkin(const WIDGET_ITEM_DRAW_INFO * pDrawItemInfo)
{
    GUI_POINT poly[] =
    {
        {0,25},{15,15},{15,21},{35,21},{35,29},{15,29},{15,35}
    };
    switch (pDrawItemInfo->Cmd)
    {
    case WIDGET_ITEM_DRAW_BACKGROUND:
        GUI_SetColor(GUI_WHITE);
        GUI_AA_FillPolygon(poly, 7,0,0);
        break;
    default:
        return BUTTON_DrawSkinFlex(pDrawItemInfo);
    }
    return 0;
}

