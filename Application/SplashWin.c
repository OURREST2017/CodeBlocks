#include "ranger.h"
#ifndef CODEBLOCK
#include "stm324x9i_REST_HWv2_hvac.h"
#endif
#define ID_SPLASH_WINDOW     (GUI_ID_USER + 0x00)
#define ID_TEXT_SPLASH     (GUI_ID_USER + 0x20)

static const GUI_WIDGET_CREATE_INFO _aDialogCreate[] = { {
		WINDOW_CreateIndirect, "splash", ID_SPLASH_WINDOW, 0, 0, 480, 272, 0,
		0x0, 0 }, { TEXT_CreateIndirect, "", ID_TEXT_SPLASH, 0, 0, 480, 270, 0, 0x64, 0 },
};

static WM_HWIN splashWin;
extern GUI_CONST_STORAGE GUI_BITMAP bmsplash;
static GUI_TIMER_HANDLE light_timer, splash_timer;

/*********************************************************************
 *
 *       _cbDialog
 */
static void _cbDialog(WM_MESSAGE * pMsg) {
	int NCode;

	switch (pMsg->MsgId) {
	case WM_PAINT:
		GUI_SetColor(GUI_WHITE);
		GUI_FillRect(0, 0, 479, 271);
		GUI_DrawBitmap(&bmwatermark, 10, 0);
		GUI_DrawBitmap(&bmsplash, 142, 36);

		GUI_SetColor(0x808080);
		GUI_SetTextMode(GUI_TEXTMODE_TRANS);
		GUI_SetFont(&GUI_Font16B_ASCII);
		GUI_DispStringAt("Initializing......", 200, 210);
		break;
	case WM_INIT_DIALOG:
		break;
	case WM_NOTIFY_PARENT:
		NCode = pMsg->Data.v;
		if (NCode == 1) {
			GUI_TIMER_Delete(light_timer);
			WM_DeleteWindow(splashWin);
			screenState = HOMEWIN;
		}
		break;
	default:
		WM_DefaultProc(pMsg);
		break;
	}
}
#ifndef CODEBLOCK
int light, lc;
#define TLC 14

int light_array[TLC][8] = {
		{1,3,5,7,8,6,4,2},{1,3,5,7,8,6,4,2},
		{1,3,5,7,8,6,4,2},{1,3,5,7,8,6,4,2},
		{1,2,4,3,5,6,8,7},{1,2,4,3,5,6,8,7},
		{1,2,4,3,5,6,8,7},{1,2,4,3,5,6,8,7},
		{9,10,11,12,13,14,15,16},{9,10,11,12,13,14,15,16},
		{17,18,19,20,21,22,23,24},{17,18,19,20,21,22,23,24},
		{25,26,27,28,29,30,31,32},{25,26,27,28,29,30,31,32}
};

static void lightTimer(GUI_TIMER_MESSAGE * pTM) {
    int delay = 50;
	switch (light_array[lc][light]) {
	case 1:
		BSP_HVAC_request_cool_Y(HVAC_FUNCTION_SET);
		GUI_Delay(delay);
		BSP_HVAC_request_cool_Y(HVAC_FUNCTION_RESET);
		break;
	case 2:
		BSP_HVAC_request_cool_Y2(HVAC_FUNCTION_SET);
		GUI_Delay(delay);
		BSP_HVAC_request_cool_Y2(HVAC_FUNCTION_RESET);
		break;
	case 3:
		BSP_HVAC_request_heat_W(HVAC_FUNCTION_SET);
		GUI_Delay(delay);
		BSP_HVAC_request_heat_W(HVAC_FUNCTION_RESET);
		break;
	case 4:
		BSP_HVAC_request_heat_W2(HVAC_FUNCTION_SET);
		GUI_Delay(delay);
		BSP_HVAC_request_heat_W2(HVAC_FUNCTION_RESET);
		break;
	case 5:
		BSP_HVAC_request_fan_G(HVAC_FUNCTION_SET);
		GUI_Delay(delay);
		BSP_HVAC_request_fan_G(HVAC_FUNCTION_RESET);
		break;
	case 6:
		BSP_HVAC_request_xxx_O(HVAC_FUNCTION_SET);
		GUI_Delay(delay);
		BSP_HVAC_request_xxx_O(HVAC_FUNCTION_RESET);
		break;
	case 7:
		BSP_HVAC_request_xxx_X(HVAC_FUNCTION_SET);
		GUI_Delay(delay);
		BSP_HVAC_request_xxx_X(HVAC_FUNCTION_RESET);
		break;
	case 8:
		BSP_HVAC_request_xxx_B(HVAC_FUNCTION_SET);
		GUI_Delay(delay);
		BSP_HVAC_request_xxx_B(HVAC_FUNCTION_RESET);
		break;
	case 9:
		BSP_HVAC_request_cool_Y(HVAC_FUNCTION_SET);
		BSP_HVAC_request_cool_Y2(HVAC_FUNCTION_SET);
		GUI_Delay(delay);
		BSP_HVAC_request_cool_Y(HVAC_FUNCTION_RESET);
		BSP_HVAC_request_cool_Y2(HVAC_FUNCTION_RESET);
		break;
	case 10:
		BSP_HVAC_request_heat_W(HVAC_FUNCTION_SET);
		BSP_HVAC_request_heat_W2(HVAC_FUNCTION_SET);
		GUI_Delay(delay);
		BSP_HVAC_request_heat_W(HVAC_FUNCTION_RESET);
		BSP_HVAC_request_heat_W2(HVAC_FUNCTION_RESET);
		break;
	case 11:
		BSP_HVAC_request_fan_G(HVAC_FUNCTION_SET);
		BSP_HVAC_request_xxx_O(HVAC_FUNCTION_SET);
		GUI_Delay(delay);
		BSP_HVAC_request_fan_G(HVAC_FUNCTION_RESET);
		BSP_HVAC_request_xxx_O(HVAC_FUNCTION_RESET);
		break;
	case 12:
		BSP_HVAC_request_xxx_X(HVAC_FUNCTION_SET);
		BSP_HVAC_request_xxx_B(HVAC_FUNCTION_SET);
		GUI_Delay(delay);
		BSP_HVAC_request_xxx_X(HVAC_FUNCTION_RESET);
		BSP_HVAC_request_xxx_B(HVAC_FUNCTION_RESET);
		break;
	case 13:
		BSP_HVAC_request_cool_Y(HVAC_FUNCTION_SET);
		BSP_HVAC_request_cool_Y2(HVAC_FUNCTION_SET);
		GUI_Delay(delay);
		BSP_HVAC_request_cool_Y(HVAC_FUNCTION_RESET);
		BSP_HVAC_request_cool_Y2(HVAC_FUNCTION_RESET);
		break;
	case 14:
		BSP_HVAC_request_heat_W(HVAC_FUNCTION_SET);
		BSP_HVAC_request_heat_W2(HVAC_FUNCTION_SET);
		GUI_Delay(delay);
		BSP_HVAC_request_heat_W(HVAC_FUNCTION_RESET);
		BSP_HVAC_request_heat_W2(HVAC_FUNCTION_RESET);
		break;
	case 15:
		BSP_HVAC_request_fan_G(HVAC_FUNCTION_SET);
		BSP_HVAC_request_xxx_O(HVAC_FUNCTION_SET);
		GUI_Delay(delay);
		BSP_HVAC_request_fan_G(HVAC_FUNCTION_RESET);
		BSP_HVAC_request_xxx_O(HVAC_FUNCTION_RESET);
		break;
	case 16:
		BSP_HVAC_request_xxx_X(HVAC_FUNCTION_SET);
		BSP_HVAC_request_xxx_B(HVAC_FUNCTION_SET);
		GUI_Delay(delay);
		BSP_HVAC_request_xxx_X(HVAC_FUNCTION_RESET);
		BSP_HVAC_request_xxx_B(HVAC_FUNCTION_RESET);
		break;
	case 17:
		BSP_HVAC_request_cool_Y(HVAC_FUNCTION_SET);
		BSP_HVAC_request_cool_Y2(HVAC_FUNCTION_SET);
		BSP_HVAC_request_heat_W(HVAC_FUNCTION_SET);
		BSP_HVAC_request_heat_W2(HVAC_FUNCTION_SET);
		GUI_Delay(delay);
		BSP_HVAC_request_cool_Y(HVAC_FUNCTION_RESET);
		BSP_HVAC_request_cool_Y2(HVAC_FUNCTION_RESET);
		BSP_HVAC_request_heat_W(HVAC_FUNCTION_RESET);
		BSP_HVAC_request_heat_W2(HVAC_FUNCTION_RESET);
		break;
	case 18:
		BSP_HVAC_request_heat_W(HVAC_FUNCTION_SET);
		BSP_HVAC_request_heat_W2(HVAC_FUNCTION_SET);
		BSP_HVAC_request_fan_G(HVAC_FUNCTION_SET);
		BSP_HVAC_request_xxx_O(HVAC_FUNCTION_SET);
		GUI_Delay(delay);
		BSP_HVAC_request_heat_W(HVAC_FUNCTION_RESET);
		BSP_HVAC_request_heat_W2(HVAC_FUNCTION_RESET);
		BSP_HVAC_request_fan_G(HVAC_FUNCTION_RESET);
		BSP_HVAC_request_xxx_O(HVAC_FUNCTION_RESET);
		break;
	case 19:
		BSP_HVAC_request_fan_G(HVAC_FUNCTION_SET);
		BSP_HVAC_request_xxx_O(HVAC_FUNCTION_SET);
		BSP_HVAC_request_xxx_X(HVAC_FUNCTION_SET);
		BSP_HVAC_request_xxx_B(HVAC_FUNCTION_SET);
		GUI_Delay(delay);
		BSP_HVAC_request_fan_G(HVAC_FUNCTION_RESET);
		BSP_HVAC_request_xxx_O(HVAC_FUNCTION_RESET);
		BSP_HVAC_request_xxx_X(HVAC_FUNCTION_RESET);
		BSP_HVAC_request_xxx_B(HVAC_FUNCTION_RESET);
		break;
	case 20:
		BSP_HVAC_request_heat_W(HVAC_FUNCTION_SET);
		BSP_HVAC_request_heat_W2(HVAC_FUNCTION_SET);
		BSP_HVAC_request_fan_G(HVAC_FUNCTION_SET);
		BSP_HVAC_request_xxx_O(HVAC_FUNCTION_SET);
		GUI_Delay(delay);
		BSP_HVAC_request_heat_W(HVAC_FUNCTION_RESET);
		BSP_HVAC_request_heat_W2(HVAC_FUNCTION_RESET);
		BSP_HVAC_request_fan_G(HVAC_FUNCTION_RESET);
		BSP_HVAC_request_xxx_O(HVAC_FUNCTION_RESET);
		break;
	case 21:
		BSP_HVAC_request_cool_Y(HVAC_FUNCTION_SET);
		BSP_HVAC_request_cool_Y2(HVAC_FUNCTION_SET);
		BSP_HVAC_request_heat_W(HVAC_FUNCTION_SET);
		BSP_HVAC_request_heat_W2(HVAC_FUNCTION_SET);
		GUI_Delay(delay);
		BSP_HVAC_request_cool_Y(HVAC_FUNCTION_RESET);
		BSP_HVAC_request_cool_Y2(HVAC_FUNCTION_RESET);
		BSP_HVAC_request_heat_W(HVAC_FUNCTION_RESET);
		BSP_HVAC_request_heat_W2(HVAC_FUNCTION_RESET);
		break;
	case 22:
		BSP_HVAC_request_heat_W(HVAC_FUNCTION_SET);
		BSP_HVAC_request_heat_W2(HVAC_FUNCTION_SET);
		BSP_HVAC_request_fan_G(HVAC_FUNCTION_SET);
		BSP_HVAC_request_xxx_O(HVAC_FUNCTION_SET);
		GUI_Delay(delay);
		BSP_HVAC_request_heat_W(HVAC_FUNCTION_RESET);
		BSP_HVAC_request_heat_W2(HVAC_FUNCTION_RESET);
		BSP_HVAC_request_fan_G(HVAC_FUNCTION_RESET);
		BSP_HVAC_request_xxx_O(HVAC_FUNCTION_RESET);
		break;
	case 23:
		BSP_HVAC_request_fan_G(HVAC_FUNCTION_SET);
		BSP_HVAC_request_xxx_O(HVAC_FUNCTION_SET);
		BSP_HVAC_request_xxx_X(HVAC_FUNCTION_SET);
		BSP_HVAC_request_xxx_B(HVAC_FUNCTION_SET);
		GUI_Delay(delay);
		BSP_HVAC_request_fan_G(HVAC_FUNCTION_RESET);
		BSP_HVAC_request_xxx_O(HVAC_FUNCTION_RESET);
		BSP_HVAC_request_xxx_X(HVAC_FUNCTION_RESET);
		BSP_HVAC_request_xxx_B(HVAC_FUNCTION_RESET);
		break;
	case 24:
		BSP_HVAC_request_heat_W(HVAC_FUNCTION_SET);
		BSP_HVAC_request_heat_W2(HVAC_FUNCTION_SET);
		BSP_HVAC_request_fan_G(HVAC_FUNCTION_SET);
		BSP_HVAC_request_xxx_O(HVAC_FUNCTION_SET);
		GUI_Delay(delay);
		BSP_HVAC_request_heat_W(HVAC_FUNCTION_RESET);
		BSP_HVAC_request_heat_W2(HVAC_FUNCTION_RESET);
		BSP_HVAC_request_fan_G(HVAC_FUNCTION_RESET);
		BSP_HVAC_request_xxx_O(HVAC_FUNCTION_RESET);
		break;
	case 25:
		BSP_HVAC_request_cool_Y(HVAC_FUNCTION_SET);
		BSP_HVAC_request_heat_W(HVAC_FUNCTION_SET);
		BSP_HVAC_request_fan_G(HVAC_FUNCTION_SET);
		BSP_HVAC_request_xxx_X(HVAC_FUNCTION_SET);
		GUI_Delay(delay);
		BSP_HVAC_request_cool_Y(HVAC_FUNCTION_RESET);
		BSP_HVAC_request_heat_W(HVAC_FUNCTION_RESET);
		BSP_HVAC_request_fan_G(HVAC_FUNCTION_RESET);
		BSP_HVAC_request_xxx_X(HVAC_FUNCTION_RESET);
		break;
	case 26:
		BSP_HVAC_request_xxx_X(HVAC_FUNCTION_SET);
		BSP_HVAC_request_xxx_B(HVAC_FUNCTION_SET);
		GUI_Delay(delay);
		BSP_HVAC_request_xxx_X(HVAC_FUNCTION_RESET);
		BSP_HVAC_request_xxx_B(HVAC_FUNCTION_RESET);
		break;
	case 27:
		BSP_HVAC_request_cool_Y2(HVAC_FUNCTION_SET);
		BSP_HVAC_request_heat_W2(HVAC_FUNCTION_SET);
		BSP_HVAC_request_xxx_O(HVAC_FUNCTION_SET);
		BSP_HVAC_request_xxx_B(HVAC_FUNCTION_SET);
		GUI_Delay(delay);
		BSP_HVAC_request_cool_Y2(HVAC_FUNCTION_RESET);
		BSP_HVAC_request_heat_W2(HVAC_FUNCTION_RESET);
		BSP_HVAC_request_xxx_O(HVAC_FUNCTION_RESET);
		BSP_HVAC_request_xxx_B(HVAC_FUNCTION_RESET);
		break;
	case 28:
		BSP_HVAC_request_cool_Y(HVAC_FUNCTION_SET);
		BSP_HVAC_request_cool_Y2(HVAC_FUNCTION_SET);
		GUI_Delay(delay);
		BSP_HVAC_request_cool_Y(HVAC_FUNCTION_RESET);
		BSP_HVAC_request_cool_Y2(HVAC_FUNCTION_RESET);
		break;
	case 29:
		BSP_HVAC_request_cool_Y(HVAC_FUNCTION_SET);
		BSP_HVAC_request_heat_W(HVAC_FUNCTION_SET);
		BSP_HVAC_request_fan_G(HVAC_FUNCTION_SET);
		BSP_HVAC_request_xxx_X(HVAC_FUNCTION_SET);
		GUI_Delay(delay);
		BSP_HVAC_request_cool_Y(HVAC_FUNCTION_RESET);
		BSP_HVAC_request_heat_W(HVAC_FUNCTION_RESET);
		BSP_HVAC_request_fan_G(HVAC_FUNCTION_RESET);
		BSP_HVAC_request_xxx_X(HVAC_FUNCTION_RESET);
		break;
	case 30:
		BSP_HVAC_request_xxx_X(HVAC_FUNCTION_SET);
		BSP_HVAC_request_xxx_B(HVAC_FUNCTION_SET);
		GUI_Delay(delay);
		BSP_HVAC_request_xxx_X(HVAC_FUNCTION_RESET);
		BSP_HVAC_request_xxx_B(HVAC_FUNCTION_RESET);
		break;
	case 31:
		BSP_HVAC_request_cool_Y2(HVAC_FUNCTION_SET);
		BSP_HVAC_request_heat_W2(HVAC_FUNCTION_SET);
		BSP_HVAC_request_xxx_O(HVAC_FUNCTION_SET);
		BSP_HVAC_request_xxx_B(HVAC_FUNCTION_SET);
		GUI_Delay(delay);
		BSP_HVAC_request_cool_Y2(HVAC_FUNCTION_RESET);
		BSP_HVAC_request_heat_W2(HVAC_FUNCTION_RESET);
		BSP_HVAC_request_xxx_O(HVAC_FUNCTION_RESET);
		BSP_HVAC_request_xxx_B(HVAC_FUNCTION_RESET);
		break;
	case 32:
		BSP_HVAC_request_cool_Y(HVAC_FUNCTION_SET);
		BSP_HVAC_request_cool_Y2(HVAC_FUNCTION_SET);
		GUI_Delay(delay);
		BSP_HVAC_request_cool_Y(HVAC_FUNCTION_RESET);
		BSP_HVAC_request_cool_Y2(HVAC_FUNCTION_RESET);
		break;
	}
	light++;
	if (light == 8) {
		light = 0;
		lc++;
		if (lc == TLC) lc = 0;
	}
	GUI_TIMER_SetPeriod(pTM->hTimer, 250);
	GUI_TIMER_Restart(pTM->hTimer);
}
#endif
static void splashTimer(GUI_TIMER_MESSAGE * pTM) {
    GUI_TIMER_Delete(splash_timer);
    WM_DeleteWindow(splashWin);
    screenState = HOMEWIN;
}
/*********************************************************************
 *
 *       CreateHomeWin
 */
WM_HWIN CreateSplashWin(void);
WM_HWIN CreateSplashWin(void) {
	WM_HWIN hWin;

#ifndef CODEBLOCK
	light_timer = GUI_TIMER_Create(lightTimer, 300, 0, 0);
#endif
#ifndef DEBUG_MODE
    splash_timer = GUI_TIMER_Create(splashTimer, 5000, 0, 0);
#endif
	splashWin = GUI_CreateDialogBox(_aDialogCreate, GUI_COUNTOF(_aDialogCreate),
			_cbDialog, WM_HBKWIN, 0, 0);

	return hWin;
}

/*************************** End of file ****************************/
