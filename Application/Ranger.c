#include "main.h"

#define countof(Array) (sizeof(Array) / sizeof(Array[0]))
#define INIT_BUTTON          (WM_USER + 0)

static GUI_POINT aPoints[] =
{
    { 0, 0 },
    { 15, 30 },
    { 0, 20 },
    {-15, 30 }
};

static void blowme(WM_MESSAGE * pMsg)
{
    switch (pMsg->MsgId)
    {
    case WM_PAINT:
        // GUI_DrawBitmap(&bm_return, 0, 0);
        //_OnPaint(pMsg->hWin);
        break;
    default:
        BUTTON_Callback(pMsg); // The original callback
        break;
    }
    if (pMsg->MsgId == WM_TOUCH)
    {
        if (BUTTON_IsPressed(pMsg->hWin))
        {
            GUI_ErrorOut("PRESSED");
        }
    }
}

static void _DrawGradientRoundBar(int xPos0, int yPos0, int xPos1, int yPos1,
                                  GUI_COLOR Color0, GUI_COLOR Color1)
{
    GUI_COLOR Color;
    unsigned  r;
    unsigned  g;
    U32       b;
    double    rd;
    double    rr;
    double    x;
    double    y;
    int       Add;
    int       r0;
    int       g0;
    int       b0;
    int       r1;
    int       g1;
    int       b1;
    int       d;
    int       i;

    for (i = 0; i < 50; i++) {
        U32 Alpha;
        Alpha = (i * 255 / 100) << 24;
        GUI_SetColor(GUI_YELLOW | Alpha);
        GUI_DrawHLine(i, 50 - i, 50 + i);
    }

//    r0  = (Color0 >>  0) & 0x000000ff;
//    g0  = (Color0 >>  8) & 0x000000ff;
//    b0  = (Color0 >> 16) & 0x000000ff;
//    r1  = (Color1 >>  0) & 0x000000ff;
//    g1  = (Color1 >>  8) & 0x000000ff;
//    b1  = (Color1 >> 16) & 0x000000ff;
//    Add = -1;
//    d   = yPos1 - yPos0 + 1;
//    rd  = (yPos1 - yPos0) / 2.0;
//    rr  = rd * rd;
//    y   = rd;
//    for (i = yPos0; i <= yPos1; i++)
//    {
//        x = sqrt(rr - y * y);
//        r = r0 + (r1 - r0) * (i - yPos0) / d;
//        g = g0 + (g1 - g0) * (i - yPos0) / d;
//        b = b0 + (b1 - b0) * (i - yPos0) / d;
//        Color = r | (g << 8) | (b << 16);
//        GUI_SetColor(Color);
//        GUI_DrawHLine(i, (int)(xPos0 + rd - x), (int)(xPos0 + rd));
//        GUI_DrawHLine(i, (int)(xPos0 + rd),     (int)(xPos1 - rd));
//        GUI_DrawHLine(i, (int)(xPos1 - rd),     (int)(xPos1 - rd + x));
//        y += Add;
//        if (y < 0)
//        {
//            Add = -Add;
//            y = -y;
//        }
//    }
}

void setSkin()
{
    BUTTON_SKINFLEX_PROPS Props;/* Temp variable to store customized settings of the skin */
    BUTTON_GetSkinFlexProps(&Props, BUTTON_SKINFLEX_PI_ENABLED); /* Get current skin properties of enabled button */
    Props.aColorFrame[0] = GUI_LIGHTGRAY; /* Change colors of several parts of the button */
    Props.aColorFrame[1] = GUI_LIGHTGRAY;
    Props.aColorFrame[2] = 0x000DA088;
    Props.aColorUpper[0] = 0x0064B49C;//GUI_LIGHTGREEN;
    Props.aColorUpper[1] = 0x0059A89C;//GUI_GREEN;
    Props.aColorLower[0] = 0x0059A89C;//GUI_GREEN;
    Props.aColorLower[1] = 0x0048856A;//GUI_DARKGREEN;
    BUTTON_SetSkinFlexProps(&Props, BUTTON_SKINFLEX_PI_ENABLED); /* Store new skin properties to enabled button */
    BUTTON_SetSkinFlexProps(&Props, BUTTON_SKINFLEX_PI_FOCUSSED); /* Store new skin properties to enabled button */

    Props.aColorUpper[0] = GUI_DARKBLUE;
    Props.aColorUpper[1] = GUI_DARKBLUE;
    Props.aColorLower[0] = GUI_DARKBLUE;
    Props.aColorLower[1] = GUI_DARKBLUE;
    BUTTON_SetSkinFlexProps(&Props, BUTTON_SKINFLEX_PI_PRESSED); /* Store new skin properties to enabled button */

    Props.aColorFrame[0] = 0xdddddd;
    Props.aColorFrame[1] = 0xdddddd;
    Props.aColorFrame[2] = 0xdddddd;
    Props.aColorUpper[0] = 0xdfdfdf;
    Props.aColorUpper[1] = 0xdfc4d8;
    Props.aColorLower[0] = 0xdfc4d8;
    Props.aColorLower[1] = 0xdfdfdf;
    BUTTON_SetSkinFlexProps(&Props, BUTTON_SKINFLEX_PI_DISABLED); /* Store new skin properties to enabled button */

    CHECKBOX_SKINFLEX_PROPS Props1;/* Temp variable to store customized settings of the skin */
    CHECKBOX_GetSkinFlexProps(&Props1, CHECKBOX_SKINFLEX_PI_ENABLED); /* Get current skin properties of enabled button */
    Props1.aColorFrame[0] = GUI_GREEN; /* Change colors of several parts of the button */
    Props1.aColorFrame[1] = GUI_BLUE;
    Props1.aColorFrame[2] = GUI_RED;
    Props1.aColorInner[0] = 0x0059A89C;
    Props1.aColorInner[1] = 0x0059A88D;
    Props1.aColorInner[2] = 0x0048856A;
    CHECKBOX_SetSkinFlexProps(&Props1, CHECKBOX_SKINFLEX_PI_ENABLED); /* Store new skin properties to enabled button */
    CHECKBOX_SetSkinFlexProps(&Props1, CHECKBOX_SKINFLEX_PI_DISABLED); /* Store new skin properties to enabled button */

    HEADER_SKINFLEX_PROPS PropsH;/* Temp variable to store customized settings of the skin */
    HEADER_GetSkinFlexProps(&PropsH, 0); /* Get current skin properties of enabled button */
    PropsH.aColorUpper[0] = 0x0064B49C;//GUI_LIGHTGREEN;
    PropsH.aColorUpper[1] = 0x0059A89C;//GUI_GREEN;
    PropsH.aColorLower[0] = 0x0059A89C;//GUI_GREEN;
    PropsH.aColorLower[1] = 0x0048856A;//GUI_DARKGREEN;
    HEADER_SetSkinFlexProps(&PropsH, 0); /* Store new skin properties to enabled button */
}

static void _cbBkWin(WM_MESSAGE * pMsg) {
  const WM_KEY_INFO * pKeyInfo;
  int                 NCode;
  int                 Id;

  switch (pMsg->MsgId) {
  case WM_NOTIFY_PARENT:
    Id    = WM_GetId(pMsg->hWinSrc);    // Id of widget
    NCode = pMsg->Data.v;               // Notification code
    switch (NCode) {
    case WM_NOTIFICATION_RELEASED:      // React only if released
      switch (Id) {
      case GUI_ID_BUTTON0:
        break;
      case GUI_ID_BUTTON1:
        break;
      }
      break;
    }
    break;
  case WM_PAINT:
    GUI_DrawGradientV(0, 0, 639, 479, GUI_BLUE, GUI_BLACK);
    GUI_SetTextMode(GUI_TM_TRANS);
    GUI_SetColor(GUI_WHITE);
    GUI_DispStringHCenterAt("emWin VGA Demonstration\n", 400, 44);
    GUI_DispStringHCenterAt("Press the 'Dashboard' or the 'Cash Terminal'\nbutton to start one of the applications\n", 320, 150);
    //GUI_DrawBitmap(&bmSeggerLogo, 30, 30);
    break;
  }
}

static WM_HWIN _CreateButton(int x, int y, int w, int h, int bx, int by, const char * pText, GUI_CONST_STORAGE GUI_BITMAP * pBm, int Id) {
  WM_HWIN hWin;

  hWin = BUTTON_CreateEx(x, y, w, h, WM_HBKWIN, WM_CF_SHOW, 0, Id);
  //BUTTON_SetBitmapEx(hWin, 0, pBm, bx + 0, by + 0);
  //BUTTON_SetBitmapEx(hWin, 1, pBm, bx + 1, by + 0);
  //BUTTON_SetFont(hWin, &GUI_FontAA2_21);
  BUTTON_SetTextAlign(hWin, GUI_TA_TOP | GUI_TA_HCENTER);
  BUTTON_SetText(hWin, pText);
  BUTTON_SetBkColor(hWin, 0, GUI_LIGHTBLUE);
  return hWin;
}

static int _ButtonSkin(const WIDGET_ITEM_DRAW_INFO * pDrawItemInfo) {
  int Index, xSize, ySize, IsPressed;
  WM_HWIN hWin;
  const GUI_BITMAP * pBm;
  GUI_COLOR Color;

  hWin = pDrawItemInfo->hWin;
  switch (pDrawItemInfo->Cmd) {
  case WIDGET_ITEM_DRAW_BACKGROUND:
    //
    // Get state of button
    //
    IsPressed = BUTTON_IsPressed(pDrawItemInfo->hWin);
    //
    // Get window dimension
    //
    xSize = WM_GetWindowSizeX(hWin);
    ySize = WM_GetWindowSizeY(hWin);
    //
    // Get button index
    //
    BUTTON_GetUserData(hWin, &Index, sizeof(Index));
    //
    // Draw background color depending on state
    //
    if (IsPressed) {
      Color = 0xCCCCCC;
    } else {
      Color = GUI_WHITE;
    }
    GUI_SetBkColor(Color);
    GUI_Clear();
    //
    // Draw antialiased rounded rectangle as background for image
    //
    GUI_SetColor(GUI_BLUE);
    GUI_AA_FillRoundedRect(10, 6, 47 + 10, 47 + 6, 12);
    //
    // Draw compressed alpha bitmap
    //
    GUI_SetColor(GUI_WHITE);
    //GUI_DrawBitmap(_aMenu[Index].pBm, 18, 14);
    //
    // Draw button text
    //
    GUI_SetColor(GUI_BLACK);
    //GUI_SetFont(&GUI_Font28_AA4);
    GUI_SetTextAlign(GUI_TA_LEFT | GUI_TA_VCENTER);
    GUI_DispStringAt("BLOWME", 80, 30);
    //
    // Draw small separator line
    //
    GUI_SetColor(0xccc7c8);
    GUI_DrawHLine(ySize - 1, 80, xSize - 1);
    //
    // Draw arrow at the right
    //
    //pBm = &bmArrowRigth_15x24;
    //GUI_DrawBitmap(&bmArrowRigth_15x24, xSize - 40, (ySize - pBm->YSize) / 2);
    break;
  }
  return 0;
}
void MainTask(void)
{
    GUI_Init();
   BUTTON_SetReactOnLevel();
   temperature=60;
    state=1;
    BUTTON_Handle hButton;
    char buffer[10];

    setSkin();
    int xPos0 = 10;
    int yPos0 = 10;
    int xPos1 = 100;
    int yPos1  = 100;
    int r = 50;
     //   WM_SetCallback(WM_HBKWIN, _cbBkWin);
     //WM_SetScreenSize(480,272);
   while(1)
    {
     switch (state)
        {
        case 0:
            break;
        case 1:
//           hButton = BUTTON_CreateUser(100,100,200,100, 0, WM_CF_SHOW, 0, GUI_ID_BUTTON0, 0);
//         BUTTON_SetSkin(hButton, _ButtonSkin);

//     hButton = _CreateButton(100, 100, 170, 150, 5, 25, "Dashboard" ,
//                                  0   , GUI_ID_BUTTON0);
       //WM_SetFocus(hButton);
         CreateHomeWin();
            //GUI_DrawGradientRoundedV(0, 0, 480, 50 ,15, 0x7a5114, 0xc1842d);
            //GUI_DrawGradientV(0, 0, 480, 50 ,0x7a5114, 0xc1842d);
            //        GUI_DrawGradientV(5, 40, 314, 76, 0xffffff, 0xffebeb);
             //_DrawGradientRoundBar(xPos0 + 2, yPos0 + 2, xPos1 - 2, yPos1 - 2, 0xEEEEEE, 0x737373);


            //CreateNumericKeyboard();
//
            //BUTTON_SetDefaultBkColor( GUI_YELLOW, BUTTON_CI_UNPRESSED);
            //hButton = BUTTON_CreateUser(100,100,200,100,0,WM_CF_SHOW,0,0,0);
//               WM_SetCallback(hButton, blowme);
            //BUTTON_SetBitmapEx(hButton, 0,   &bm_1bpp_1, 10, 2);
            // BUTTON_SetSkin(hButton,BUTTON_SKIN_FLEX);
            //_DrawGradientRoundBar(100,100,200,200,0x7a5114,0xc1842d);
            //GUI_AA_FillPolygon(aPoints, countof(aPoints), 100, 150);
            //GUI_AA_DrawArc(x0 + r, y0_ + r, r - 2, r - 2,  0, 360);
            //GUI_AA_FillRoundedRect(100, 100, 200, 200, 5);
            state=0;
            break;
        case 2:
            CreateNumericKeyboard();
            state=0;
            break;
        case 3:
            CreateMode();
            GUI_Delay(100);
            state=0;
            break;
        case 4:
            CreateSettings();
            state=0;
            break;
        case 5:
            CreateFAN();
            state=0;
            break;
        case 6:
            state=0;
            break;
        case 7:
            CreateSchedule();
            state=0;
            break;
        case 8:
            CreateAlphaKeyboard();
            state=0;
            break;
        case 10:
            CreateColors();
            state=0;
            break;
        case 11:
            CreateDateTime();
            state=0;
            break;
        case 12:
            CreateScreenLockout();
            state=0;
            break;
        case 13:
            CreateSettingsSchedule();
            state=0;
            break;
        case 14:
            CreateLanguages();
            state=0;
            break;
        case 15:
            CreateProfile();
            state=0;
            break;
        case 16:
            CreatePreferences();
            state=0;
            break;
        case 17:
            CreateSystemSetup();
            state=0;
            break;
        case 20:
            CreateThermostatLocations();
            state=0;
            break;
        case 21:
            CreateSystemType();
            state=0;
            break;
        case 22:
            CreateThermostatControls();
            state=0;
            break;
        case 23:
            CreateFanControl();
            state=0;
            break;
        case 24:
            CreateWifiSetup();
            state=0;
            break;
        case 25:
            CreateBackupHeat();
            state=0;
            break;
        case 26:
            CreateCoolingStages();
            state=0;
            break;
        case 27:
            CreateHeatingStages();
            state=0;
            break;
        case 30:
            CreateSettingsSchedule();
            state=0;
            break;
        case 31:
            //CreateWeekend();
            state=0;
            break;
        case 32:
            CreateEachDay();
            state=0;
            break;
        case 33:
            //CreateVacation();
            state=0;
            break;
        case 34:
            state=0;
            break;
        case 40:
            CreateSchedulingOptions();
            state=0;
            break;
        case 41:
            CreateTempuratureScale();
            state=0;
            break;
        case 42:
            CreateClockFormat();
            state=0;
            break;
        case 43:
            CreateDaylightSavingTime();
            state=0;
            break;
        case 44:
            CreateSystemsChangeOver();
            state=0;
            break;
        case 45:
            //CreateTempuratureScale();
            state=0;
            break;
        case 46:
            CreateKeyboardLockout();
            state=0;
            break;
        case 47:
            CreateSchedulePeriods();
            state=0;
            break;
        }
        GUI_Exec();
        GUI_Delay(50);
    }
}
