
#include "main.h"

#define ID_HOME_WINDOW     (GUI_ID_USER + 0x00)
#define ID_BUTTON_COOL     (GUI_ID_USER + 0x01)
#define ID_BUTTON_MODE     (GUI_ID_USER + 0x02)
#define ID_BUTTON_HOLD     (GUI_ID_USER + 0x03)
#define ID_BUTTON_HEAT     (GUI_ID_USER + 0x04)
#define ID_BUTTON_FAN     (GUI_ID_USER + 0x05)
#define ID_TEXT_INSIDE_TEMP       (GUI_ID_USER + 0x07)
#define ID_HEADER     (GUI_ID_USER + 0x08)
#define ID_BUTTON_UP     (GUI_ID_USER + 0x09)
#define ID_BUTTON_DN     (GUI_ID_USER + 0x0A)
#define ID_BUTTON_SETTINGS     (GUI_ID_USER + 0x0B)
#define ID_TEXT_COOLTO     (GUI_ID_USER + 0x0C)
#define ID_TEXT_HEATTO     (GUI_ID_USER + 0x0D)
#define ID_TEXT_MODE     (GUI_ID_USER + 0x0E)
#define ID_TEXT_FAN     (GUI_ID_USER + 0x0F)
#define ID_TEXT_DATE     (GUI_ID_USER + 0x10)
#define ID_TEXT_OUT_TEMP     (GUI_ID_USER + 0x11)
#define ID_TEXT_TIME     (GUI_ID_USER + 0x12)
#define ID_TEXT_OUTSIDE     (GUI_ID_USER + 0x13)
#define ID_TEXT_HUMIDITY     (GUI_ID_USER + 0x14)
#define ID_TEXT_INDOOR     (GUI_ID_USER + 0x15)
#define ID_IMAGE_GRAY_BAR (GUI_ID_USER + 0x17)
#define ID_TEXT_SET_TO     (GUI_ID_USER + 0x18)

static void _DrawGradientRoundBar(int x0, int y0_, int x1, int y1_, GUI_COLOR Color0, GUI_COLOR Color1)
{
    GUI_COLOR Color;
    double    rd;
    double    rr;
    double    x;
    double    y;
    int       Temp;
    int       Add;
    int       r0;
    int       g0;
    int       b0;
    int       r1;
    int       g1;
    int       b1;
    int       d;
    int       i;
    U32       r;
    U32       g;
    U32       b;

    if (y0_ > y1_)
    {
        Temp = y0_;
        y0_   = y1_;
        y1_   = Temp;
    }
    if (x0 > x1)
    {
        Temp = x0;
        x0   = x1;
        x1   = Temp;
    }
    r0  = (Color0 >>  0) & 0x000000ff;
    g0  = (Color0 >>  8) & 0x000000ff;
    b0  = (Color0 >> 16) & 0x000000ff;
    r1  = (Color1 >>  0) & 0x000000ff;
    g1  = (Color1 >>  8) & 0x000000ff;
    b1  = (Color1 >> 16) & 0x000000ff;
    Add = -1;
    d   = y1_ - y0_ + 1;
    rd  = (double)(y1_ - y0_) / 2;
    rr  = rd * rd;
    y   = rd;
    for (i = y0_; i <= y1_; i++)
    {
        x = sqrt(rr - y * y);
        r = r0 + (r1 - r0) * (i - y0_) / d;
        g = g0 + (g1 - g0) * (i - y0_) / d;
        b = b0 + (b1 - b0) * (i - y0_) / d;
        Color = r | (g << 8) | (b << 16);
#if (GUI_USE_ARGB)
        Color |= 0xFF000000;
#endif
        GUI_SetColor(Color);
        GUI_DrawHLine(i, (int)(x0 + rd - x), (int)(x0 + rd));
        GUI_DrawHLine(i, (int)(x0 + rd),     (int)(x1 - rd));
        GUI_DrawHLine(i, (int)(x1 - rd),     (int)(x1 - rd + x));
        y += Add;
        if (y < 0)
        {
            Add = -Add;
            y = -y;
        }
    }
}

/*********************************************************************
*
*       _CreateBitmap
*
* Function description
*   Creates the background image in form of a rounded horizontal bar
*   with a surrounding frame and a gray gradient within the bar
*/
static GUI_MEMDEV_Handle _CreateBitmap(WM_HWIN hWin, int x0, int y0_, int x1, int y1_)
{
    GUI_MEMDEV_Handle hMem;
    GUI_MEMDEV_Handle hOld;
    int               xSizeLCD;
    int               ySizeLCD;
    int               xPos;
    int               yPos;
    int               r;

    r = (y1_ - y0_ + 1) / 2;
    xPos  = WM_GetWindowOrgX(hWin);
    yPos  = WM_GetWindowOrgY(hWin);
    xSizeLCD = LCD_GetXSize();
    ySizeLCD = LCD_GetYSize();
    //hMem = GUI_MEMDEV_Create(xPos + x0, yPos + y0_, x1 - x0 + 1, y1_ - y0_ + 1);
    GUI_DrawGradientV(5, 80, xSizeLCD - 6, ySizeLCD - 1, GUI_MAKE_COLOR(0xffffff), GUI_MAKE_COLOR(0xffa0a0));     // Draws the background of the bar
    //if (hMem) {
    WM_SelectWindow(hWin);
    //hOld = GUI_MEMDEV_Select(hMem);
    //GUI_MEMDEV_CopyFromLCD(hMem);
    _DrawGradientRoundBar(x0 + 2, y0_ + 2, x1 - 2, y1_ - 2, GUI_MAKE_COLOR(0xEEEEEE), GUI_MAKE_COLOR(0x737373));
    GUI_SetColor(GUI_MAKE_COLOR(0xff0000));
    GUI_SetPenSize(3);
    GUI_AA_DrawArc(x0 + r, y0_ + r, r - 2, r - 2,  90, 270);
    GUI_AA_DrawArc(x1 - r, y0_ + r, r - 2, r - 2, 270, 450);
    GUI_AA_DrawLine(x0 + r, y0_ + 2, x1 - r, y0_ + 2);
    GUI_AA_DrawLine(x0 + r, y1_ - 2, x1 - r, y1_ - 2);
    //GUI_MEMDEV_Select(hOld);
    //} else {
    //  _NoMemory = 1;
    //}
    return hMem;
}

static GUI_MEMDEV_Handle _CreateButton(WM_HWIN hWin, int x0, int y0_, int xSize, int ySize, GUI_COLOR Color0, GUI_COLOR Color1)
{
    GUI_MEMDEV_Handle hMem;
    GUI_MEMDEV_Handle hOld;
    int               xSizeLCD;
    int               ySizeLCD;
    int               xPos;
    int               yPos;
    int               r;

    xSizeLCD = LCD_GetXSize();
    ySizeLCD = LCD_GetYSize();
    r = xSize / 2;
    WM_SelectWindow(hWin);
    xPos  = WM_GetWindowOrgX(hWin);
    yPos  = WM_GetWindowOrgY(hWin);
    //hMem = GUI_MEMDEV_Create(xPos + x0, yPos + y0_, xSize, ySize);
    GUI_DrawGradientV(5, 80, xSizeLCD - 6, ySizeLCD - 1, GUI_MAKE_COLOR(0xffffff), GUI_MAKE_COLOR(0xffa0a0));  // Draws the background of the button
    //if (hMem) {
    //hOld = GUI_MEMDEV_Select(hMem);
    //GUI_MEMDEV_CopyFromLCD(hMem);
    _DrawGradientRoundBar(x0 + 2, y0_ + 2, x0 + xSize - 2, y0_ + ySize - 2, Color0, Color1);
    GUI_SetColor(GUI_MAKE_COLOR(0xff0000));
    GUI_SetPenSize(3);
    GUI_AA_DrawArc(x0 + r, y0_ + r, r - 2, r - 2,  0, 360);
    //GUI_MEMDEV_Select(hOld);
    //} else {
//   _NoMemory = 1;
// }
    return hMem;
}

/*********************************************************************
*
*       _aDialogCreate
*/

static U8 gray_bar[454] =
{
    0x89, 0x50, 0x4E, 0x47, 0x0D, 0x0A, 0x1A, 0x0A, 0x00, 0x00, 0x00, 0x0D, 0x49, 0x48, 0x44, 0x52, 0x00, 0x00, 0x01, 0xE0, 0x00, 0x00, 0x00, 0x16, 0x08, 0x06, 0x00, 0x00, 0x00, 0x18, 0x68, 0x4F, 0x25, 0x00, 0x00, 0x00, 0x01, 0x73, 0x52, 0x47, 0x42, 0x00,
    0xAE, 0xCE, 0x1C, 0xE9, 0x00, 0x00, 0x00, 0x04, 0x67, 0x41, 0x4D, 0x41, 0x00, 0x00, 0xB1, 0x8F, 0x0B, 0xFC, 0x61, 0x05, 0x00, 0x00, 0x00, 0x09, 0x70, 0x48, 0x59, 0x73, 0x00, 0x00, 0x0E, 0xC4, 0x00, 0x00, 0x0E, 0xC4, 0x01, 0x95, 0x2B, 0x0E, 0x1B, 0x00,
    0x00, 0x01, 0x5B, 0x49, 0x44, 0x41, 0x54, 0x78, 0x5E, 0xED, 0xDA, 0x5F, 0x86, 0x82, 0x61, 0x14, 0xC0, 0xE1, 0xCE, 0xD4, 0xEC, 0x61, 0x36, 0x39, 0xCC, 0x1E, 0xE6, 0x26, 0xA2, 0x8B, 0x88, 0x88, 0x2E, 0x22, 0x22, 0x26, 0x13, 0x11, 0x5D, 0x44, 0xB4, 0x86,
    0x59, 0x4B, 0xF1, 0x69, 0xBC, 0xE3, 0x9B, 0x3D, 0x1C, 0xC7, 0xF3, 0xDC, 0xF4, 0x7E, 0x0B, 0x38, 0x7E, 0xBD, 0x7F, 0xE2, 0x76, 0xBB, 0x3D, 0x07, 0x05, 0x0C, 0x87, 0xC3, 0x7E, 0x05, 0xFC, 0xEB, 0xBA, 0xAE, 0x5F, 0xD5, 0x60, 0xCE, 0xA9, 0x24, 0xAE, 0xD7,
    0xAB, 0x00, 0x43, 0x51, 0x2D, 0xC0, 0x66, 0x03, 0x72, 0x8A, 0xCB, 0xE5, 0x22, 0xC0, 0x50, 0x50, 0x9B, 0x89, 0xC7, 0xE3, 0x61, 0x36, 0x20, 0xA9, 0x38, 0x9F, 0xCF, 0x25, 0x02, 0x3C, 0x1A, 0x8D, 0xFA, 0x15, 0xD0, 0xB4, 0xF0, 0xDE, 0xEF, 0x77, 0xB3, 0x01,
    0x49, 0xC5, 0xE9, 0x74, 0xB2, 0x03, 0x86, 0x82, 0x5A, 0x78, 0x5B, 0x80, 0xCD, 0x06, 0xE4, 0x14, 0xC7, 0xE3, 0x51, 0x80, 0xA1, 0xA0, 0x36, 0x13, 0x8E, 0xA0, 0x21, 0xAF, 0x38, 0x1C, 0x0E, 0x02, 0x0C, 0x05, 0x09, 0x30, 0xE4, 0x16, 0xFB, 0xFD, 0x5E, 0x80,
    0xA1, 0x20, 0x01, 0x86, 0xDC, 0x62, 0xB7, 0xDB, 0x79, 0x84, 0x05, 0x05, 0xB5, 0xF0, 0x7A, 0x84, 0x05, 0x79, 0xC5, 0x76, 0xBB, 0xB5, 0x03, 0x86, 0x82, 0x3C, 0xC2, 0x82, 0xDC, 0x62, 0xB3, 0xD9, 0x08, 0x30, 0x14, 0xD4, 0x66, 0xC2, 0x11, 0x34, 0xE4, 0x15,
    0xEB, 0xF5, 0x5A, 0x80, 0xA1, 0x20, 0x01, 0x86, 0xDC, 0x62, 0xB5, 0x5A, 0xB9, 0x03, 0x86, 0x82, 0x5A, 0x78, 0xDD, 0x01, 0x43, 0x5E, 0xB1, 0x5C, 0x2E, 0xED, 0x80, 0xA1, 0x20, 0x77, 0xC0, 0x90, 0x5B, 0x2C, 0x16, 0x0B, 0x01, 0x86, 0x82, 0xDA, 0x4C, 0x38,
    0x82, 0x86, 0xBC, 0x62, 0x3E, 0x9F, 0x0B, 0x30, 0x14, 0x24, 0xC0, 0x90, 0x5B, 0xCC, 0x66, 0x33, 0x01, 0x86, 0x82, 0x04, 0x18, 0x72, 0x8B, 0xE9, 0x74, 0xEA, 0x11, 0x16, 0x14, 0xD4, 0xC2, 0xEB, 0x11, 0x16, 0xE4, 0x15, 0x93, 0xC9, 0xC4, 0x0E, 0x18, 0x0A,
    0xF2, 0x08, 0x0B, 0x72, 0x8B, 0xF1, 0x78, 0x2C, 0xC0, 0x50, 0x50, 0x9B, 0x09, 0x47, 0xD0, 0x90, 0x57, 0xBC, 0x7D, 0xFE, 0x3C, 0x3F, 0x5E, 0xBF, 0xFB, 0x4F, 0xA0, 0x8A, 0xFF, 0xF0, 0x76, 0x5D, 0xF7, 0xF7, 0x0B, 0xE4, 0xF2, 0x17, 0xE0, 0xF7, 0x97, 0xAF,
    0xFE, 0x13, 0xA8, 0xA2, 0xDA, 0xCE, 0xD7, 0x1F, 0x09, 0x6A, 0x19, 0x0C, 0x7E, 0x01, 0x2C, 0x98, 0x84, 0xEE, 0x45, 0x0C, 0xDA, 0xE5, 0x00, 0x00, 0x00, 0x00, 0x49, 0x45, 0x4E, 0x44, 0xAE, 0x42, 0x60, 0x82,
};

static const void * _GetImageById(U32 Id, U32 * pSize)
{
    switch (Id)
    {
    case ID_IMAGE_GRAY_BAR:
        *pSize = sizeof(gray_bar);
        return (const void *)gray_bar;
    }
    return NULL;
}

static const GUI_WIDGET_CREATE_INFO _aDialogCreate[] =
{
    { WINDOW_CreateIndirect, "HomeWin", ID_HOME_WINDOW, 1, 1, 480, 272, 0, 0x0, 0 },
    { BUTTON_CreateIndirect, "Button_Cool", ID_BUTTON_COOL, 384, 233, 75, 25, 0, 0x0, 0 },
    { BUTTON_CreateIndirect, "Button_Mode", ID_BUTTON_MODE, 12, 233, 75, 25, 0, 0x0, 0 },
    { BUTTON_CreateIndirect, "Button_Hold", ID_BUTTON_HOLD, 198, 233, 75, 25, 0, 0x0, 0 },
    { BUTTON_CreateIndirect, "Button_Heat", ID_BUTTON_HEAT, 292, 233, 75, 25, 0, 0x0, 0 },
    { BUTTON_CreateIndirect, "Button_Fan", ID_BUTTON_FAN, 104, 233, 75, 25, 0, 0x0, 0 },
    { IMAGE_CreateIndirect, "Image", ID_IMAGE_GRAY_BAR, -1, 201, 480, 25, 0, 0, 0 },
    { TEXT_CreateIndirect, "In_T_Panel", ID_TEXT_INSIDE_TEMP, 162, 84, 135, 100, 0, 0x64, 0 },
    { HEADER_CreateIndirect, "Header", ID_HEADER, -1, 0, 480, 50, 0, 0x0, 0 },
    { BUTTON_CreateIndirect, "Button_Up", ID_BUTTON_UP, 390, 70, 48, 48, 0, 0x0, 0 },
    { BUTTON_CreateIndirect, "Button_Dn", ID_BUTTON_DN, 390, 145, 48, 48, 0, 0x0, 0 },
    { BUTTON_CreateIndirect, "Button_Settings", ID_BUTTON_SETTINGS, 10, 110, 88, 31, 0, 0x0, 0 },
    { TEXT_CreateIndirect, "Cool_T_Panel", ID_TEXT_COOLTO, 411, 204, 34, 20, 0, 0x64, 0 },
    { TEXT_CreateIndirect, "Heat_T_Panel", ID_TEXT_HEATTO, 319, 204, 36, 20, 0, 0x64, 0 },
    { TEXT_CreateIndirect, "MODE", ID_TEXT_MODE, 33, 204, 45, 20, 0, 0x64, 0 },
    { TEXT_CreateIndirect, "FAN", ID_TEXT_FAN, 125, 204, 43, 20, 0, 0x64, 0 },
    { TEXT_CreateIndirect, "Date_Display", ID_TEXT_DATE, 20, 15, 100, 20, 0, 0x64, 0 },
    { TEXT_CreateIndirect, "Time_Display", ID_TEXT_TIME, 140, 15, 80, 20, 0, 0x64, 0 },
    { TEXT_CreateIndirect, "Out_T_Temp", ID_TEXT_OUT_TEMP, 386, 7, 72, 20, 0, 0x64, 0 },
    { TEXT_CreateIndirect, "OUSIDE", ID_TEXT_OUTSIDE, 389, 26, 61, 20, 0, 0x64, 0 },
    { TEXT_CreateIndirect, "HUMIDITY", ID_TEXT_HUMIDITY, 165, 176, 160, 20, 0, 0x64, 0 },
    { TEXT_CreateIndirect, "INDOOR", ID_TEXT_INDOOR, 165, 62, 89, 20, 0, 0x64, 0 },
    { TEXT_CreateIndirect, "SET_TO", ID_TEXT_SET_TO, 380, 122, 89, 20, 0, 0x64, 0 },
};

/*********************************************************************
*
*       _cbDialog
*/
static void _cbDialog(WM_MESSAGE * pMsg)
{
    static GUI_MEMDEV_Handle hBitmap;
    WM_HWIN hItem;
    WM_HWIN                  hWin;
    int     NCode;
    int     Id;
    char		buffer[10];
    const void * pData;
    U32 FileSize;

    hWin = pMsg->hWin;
    switch (pMsg->MsgId)
    {
    case WM_INIT_DIALOG:
        //
        // Initialization of 'HomeWin'
        //
         hItem = pMsg->hWin;
        WINDOW_SetBkColor(hItem, 0x00FFFFFF);

        hItem = WM_GetDialogItem(pMsg->hWin, ID_IMAGE_GRAY_BAR);
        pData = _GetImageById(ID_IMAGE_GRAY_BAR, &FileSize);
        IMAGE_SetPNG(hItem, pData, FileSize);

        hItem = WM_GetDialogItem(pMsg->hWin, ID_BUTTON_SETTINGS);
        BUTTON_SetFont(hItem, GUI_FONT_16B_1);
        BUTTON_SetText(hItem, "SETTINGS");
        BUTTON_SetTextColor(hItem, BUTTON_CI_UNPRESSED, GUI_WHITE);
        BUTTON_SetTextColor(hItem, BUTTON_CI_PRESSED, GUI_WHITE);
        BUTTON_SetBkColor(hItem, BUTTON_CI_UNPRESSED,GUI_RED);

        hItem = WM_GetDialogItem(pMsg->hWin, ID_BUTTON_COOL);
        BUTTON_SetFont(hItem, GUI_FONT_16B_1);
        BUTTON_SetText(hItem, "COOL");
        BUTTON_SetTextColor(hItem, BUTTON_CI_UNPRESSED, GUI_BLUE);
        BUTTON_SetTextColor(hItem, BUTTON_CI_PRESSED, GUI_BLUE);
     // Initialization of 'Button_Mode'
        //
        hItem = WM_GetDialogItem(pMsg->hWin, ID_BUTTON_MODE);
        BUTTON_SetFont(hItem, GUI_FONT_16B_1);
        BUTTON_SetText(hItem, "MODE");
        BUTTON_SetTextColor(hItem, BUTTON_CI_UNPRESSED, GUI_WHITE);
        BUTTON_SetTextColor(hItem, BUTTON_CI_PRESSED, GUI_WHITE);
      //
        // Initialization of 'Button_Hold'
        //
        hItem = WM_GetDialogItem(pMsg->hWin, ID_BUTTON_HOLD);
        BUTTON_SetFont(hItem, GUI_FONT_16B_1);
        BUTTON_SetText(hItem, "HOLD");
        BUTTON_SetTextColor(hItem, BUTTON_CI_UNPRESSED, GUI_WHITE);
        BUTTON_SetTextColor(hItem, BUTTON_CI_PRESSED, GUI_WHITE);
        //
        // Initialization of 'Button_Heat'
        //
        hItem = WM_GetDialogItem(pMsg->hWin, ID_BUTTON_HEAT);
        BUTTON_SetFont(hItem, GUI_FONT_16B_1);
        BUTTON_SetText(hItem, "HEAT");
        BUTTON_SetTextColor(hItem, BUTTON_CI_UNPRESSED, GUI_RED);
        BUTTON_SetTextColor(hItem, BUTTON_CI_PRESSED, GUI_RED);
        //
        // Initialization of 'Button_Fan'
        //
        hItem = WM_GetDialogItem(pMsg->hWin, ID_BUTTON_FAN);
        BUTTON_SetFont(hItem, GUI_FONT_16B_1);
        BUTTON_SetText(hItem, "FAN");
        BUTTON_SetTextColor(hItem, BUTTON_CI_UNPRESSED, GUI_WHITE);
        BUTTON_SetTextColor(hItem, BUTTON_CI_PRESSED, GUI_WHITE);
        //
        // Initialization of 'In_T_Panel'
        //
        sprintf(buffer,"%d",temperature);

        hItem = WM_GetDialogItem(pMsg->hWin, ID_TEXT_INSIDE_TEMP);
        //TEXT_SetText(hItem, "76");
        TEXT_SetText(hItem, buffer);
        TEXT_SetFont(hItem, GUI_FONT_D80);
        TEXT_SetTextColor(hItem, 0x00808080);
        //
        // Initialization of 'Button_Up'
        //
        hItem = WM_GetDialogItem(pMsg->hWin, ID_BUTTON_UP);
        BUTTON_SetFont(hItem, GUI_FONT_24_1);
        BUTTON_SetText(hItem, "UP");
        BUTTON_SetTextColor(hItem, BUTTON_CI_UNPRESSED, GUI_WHITE);
        BUTTON_SetTextColor(hItem, BUTTON_CI_PRESSED, GUI_WHITE);
        //
        // Initialization of 'Button_Dn'
        //
        hItem = WM_GetDialogItem(pMsg->hWin, ID_BUTTON_DN);
        BUTTON_SetFont(hItem, GUI_FONT_24_1);
        BUTTON_SetText(hItem, "DN");
        BUTTON_SetTextColor(hItem, BUTTON_CI_UNPRESSED, GUI_WHITE);
        BUTTON_SetTextColor(hItem, BUTTON_CI_PRESSED, GUI_WHITE);

        hItem = WM_GetDialogItem(pMsg->hWin, ID_TEXT_COOLTO);
        TEXT_SetText(hItem, "78 °");
        TEXT_SetFont(hItem, GUI_FONT_16B_1);
        TEXT_SetTextColor(hItem, 0x00FFFFFF);
        //
        // Initialization of 'Heat_T_Panel'
        //
        hItem = WM_GetDialogItem(pMsg->hWin, ID_TEXT_HEATTO);
        TEXT_SetFont(hItem, GUI_FONT_16B_1);
        TEXT_SetText(hItem, "68 °");
        TEXT_SetTextColor(hItem, 0x00FFFFFF);
        //
        // Initialization of 'Text'
        //
        hItem = WM_GetDialogItem(pMsg->hWin, ID_TEXT_MODE);
        TEXT_SetText(hItem, "AUTO");
        TEXT_SetFont(hItem, GUI_FONT_16B_1);
        TEXT_SetTextColor(hItem, 0x00FFFFFF);
        //
        // Initialization of 'Text'
        //
        hItem = WM_GetDialogItem(pMsg->hWin, ID_TEXT_FAN);
        TEXT_SetText(hItem, "AUTO");
        TEXT_SetFont(hItem, GUI_FONT_16B_1);
        TEXT_SetTextColor(hItem, 0x00FFFFFF);
        //
        // Initialization of 'Date_Display'
        //
        hItem = WM_GetDialogItem(pMsg->hWin, ID_TEXT_DATE);
        TEXT_SetText(hItem, "WED 7/7/09");
        TEXT_SetFont(hItem, GUI_FONT_20_1);
        TEXT_SetTextColor(hItem, 0x00FFFFFF);
        //
        // Initialization of 'Text'
        //
        hItem = WM_GetDialogItem(pMsg->hWin, ID_TEXT_TIME);
        TEXT_SetText(hItem, "1:36PM");
        TEXT_SetFont(hItem, GUI_FONT_20_1);
        TEXT_SetTextColor(hItem, 0x00FFFFFF);
        //
        // Initialization of 'Out_T_Temp'
        //
        hItem = WM_GetDialogItem(pMsg->hWin, ID_TEXT_OUT_TEMP);
        TEXT_SetText(hItem, "84 °  |  80%");
        TEXT_SetFont(hItem, GUI_FONT_16B_1);
        TEXT_SetTextColor(hItem, 0x00FFFFFF);
        //
        // Initialization of 'Text'
        //
        hItem = WM_GetDialogItem(pMsg->hWin, ID_TEXT_OUTSIDE);
        TEXT_SetFont(hItem, GUI_FONT_16B_1);
        TEXT_SetText(hItem, "OUTSIDE");
        TEXT_SetTextColor(hItem, 0x00FFFFFF);
        //
        // Initialization of 'Text'
        //
        hItem = WM_GetDialogItem(pMsg->hWin, ID_TEXT_HUMIDITY);
        TEXT_SetFont(hItem, GUI_FONT_20_1);
        TEXT_SetText(hItem, "30% HUMIDITY");
        //
        // Initialization of 'Text'
        //
        hItem = WM_GetDialogItem(pMsg->hWin, ID_TEXT_INDOOR);
        TEXT_SetText(hItem, "INDOOR");
        TEXT_SetFont(hItem, GUI_FONT_20_1);

        hItem = WM_GetDialogItem(pMsg->hWin, ID_TEXT_SET_TO);
        TEXT_SetText(hItem, "SET TO 72 °");
        TEXT_SetFont(hItem, GUI_FONT_16B_1);
        // USER START (Optionally insert additional code for further widget initialization)
        // USER END
        break;
    case WM_NOTIFY_PARENT:
        Id    = WM_GetId(pMsg->hWinSrc);
        NCode = pMsg->Data.v;
        sprintf(buffer,"ID=%d,%d,%d",Id, NCode, ID_IMAGE_GRAY_BAR);
       // GUI_ErrorOut(buffer);
        switch(Id)
        {
        case ID_BUTTON_COOL: // Notifications sent by 'Button_Cool'
            switch(NCode)
            {
            case WM_NOTIFICATION_CLICKED:
                break;
            }
            break;
        case ID_BUTTON_MODE: // Notifications sent by 'Button_Mode'
            switch(NCode)
            {
            case WM_NOTIFICATION_CLICKED:
                GUI_Delay(100);
                state=3;
                break;
            }
            break;
        case ID_BUTTON_HOLD: // Notifications sent by 'Button_Hold'
            switch(NCode)
            {
            case WM_NOTIFICATION_CLICKED:
                break;
            }
            break;
        case ID_BUTTON_HEAT: // Notifications sent by 'Button_Heat'
            switch(NCode)
            {
            case WM_NOTIFICATION_CLICKED:
                break;
            }
            break;
        case ID_BUTTON_FAN: // Notifications sent by 'Button_Fan'
            switch(NCode)
            {
            case WM_NOTIFICATION_CLICKED:
                state=5;
                break;
            }
            break;
        case ID_BUTTON_UP: // Notifications sent by 'Button_Up'
            switch(NCode)
            {
            case WM_NOTIFICATION_CLICKED:
                temperature++;
                GUI_Delay(100);
                state=1;
                break;
            }
            break;
        case ID_BUTTON_DN: // Notifications sent by 'Button_Dn'
            switch(NCode)
            {
            case WM_NOTIFICATION_CLICKED:
                temperature--;
                GUI_Delay(100);
                state=1;
                break;
            }
            break;
        case ID_BUTTON_SETTINGS: // Notifications sent by 'Button_Settings'
            switch(NCode)
            {
            case WM_NOTIFICATION_CLICKED:
                state=4;
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
*       Public code
*
**********************************************************************
*/
/*********************************************************************
*
*       CreateHomeWin
*/
WM_HWIN CreateHomeWin(void);
WM_HWIN CreateHomeWin(void)
{
    WM_HWIN hWin;
    BUTTON_Handle          hButton;

    hWin = GUI_CreateDialogBox(_aDialogCreate, GUI_COUNTOF(_aDialogCreate), _cbDialog, WM_HBKWIN, 0, 0);
    return hWin;
}

// USER START (Optionally insert additional public code)
// USER END

/*************************** End of file ****************************/
