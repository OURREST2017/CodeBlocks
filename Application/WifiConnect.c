#include "ranger.h"

#define ID_WINDOW_0 (GUI_ID_USER + 0x02)
#define ID_LISTBOX_0  (GUI_ID_USER + 0x01)
#define ID_BUTTON_CANCEL (GUI_ID_USER + 0x05)
#define ID_BUTTON_SAVE (GUI_ID_USER + 0x06)
#define ID_BUTTON_LATER (GUI_ID_USER + 0x03)
#define ID_BUTTON_RESCAN (GUI_ID_USER + 0x04)
#define ID_TEXT_HEADER (GUI_ID_USER + 0x08)
#define GUI_ID_LISTWHEEL0  (GUI_ID_USER + 0x1F)

static const GUI_WIDGET_CREATE_INFO _aDialogCreate[] =
{
    { WINDOW_CreateIndirect, "Window", ID_WINDOW_0, 0, 0, 480, 272, 0, 0x0, 0 },
    { TEXT_CreateIndirect, "SELECT WIFI NETWORK", ID_TEXT_HEADER, 0, 0, 480, 50, 0, 0x64, 0 },
    { LISTBOX_CreateIndirect, "Listbox", ID_LISTBOX_0, 62, 70, 350, 140, 0, 0x0, 0 },
    { BUTTON_CreateIndirect, "CANCEL", ID_BUTTON_CANCEL, 20, 230, BUT_WIDTH, BUT_HEIGHT, 0, 0x0, 0 },
    { BUTTON_CreateIndirect, "RESCAN", ID_BUTTON_RESCAN, 140, 230, BUT_WIDTH, BUT_HEIGHT, 0, 0x0, 0 },
    { BUTTON_CreateIndirect, "LATER", ID_BUTTON_LATER, 260, 230, 80, BUT_HEIGHT, 0, 0x0, 0 },
    { BUTTON_CreateIndirect, "SAVE", ID_BUTTON_SAVE, 350, 230,BUT_WIDTH, BUT_HEIGHT, 0, 0x0, 0 },
};

static char *wifi_networks[] =
{
    "Pinnacle", "FFI-HDQ", "BHN Secure", "CableWifi", "Direct-7c-HP M452 LaserJet",
    "BSCWireless", "INTEGO GROUP", "Other Network", "BrightHouse Wireless"
};

static WM_HWIN listBox_h, wifiConnectWin;
static int wifi;

/*********************************************************************
*
*   	_GetItemSizeX
*/
static int _GetItemSizeX(WM_HWIN hWin, int ItemIndex) {
  char acBuffer[100];
  int  DistX;

  LISTBOX_GetItemText(hWin, ItemIndex, acBuffer, sizeof(acBuffer));
  DistX = GUI_GetStringDistX(acBuffer);
  return DistX + 16;
}

/*********************************************************************
*
*   	_GetItemSizeY
*/
static int _GetItemSizeY(WM_HWIN hWin, int ItemIndex) {
  int DistY;

  DistY = GUI_GetFontDistY();

  return DistY;
}

// Refer to page 598 in Manual
int drawRoundedListBox(const WIDGET_ITEM_DRAW_INFO * pDrawItemInfo) {
  WM_HWIN hWin;
  int 	Index;

	hWin 	= pDrawItemInfo->hWin;
	Index	= pDrawItemInfo->ItemIndex;
	switch (pDrawItemInfo->Cmd) {
		case WIDGET_ITEM_GET_XSIZE:
			return _GetItemSizeX(hWin, Index);
		case WIDGET_ITEM_GET_YSIZE:
			return _GetItemSizeY(hWin, Index);
		case WIDGET_ITEM_DRAW:
		{
			int Sel;
			int YSize;
			int FontDistX;
			int FontDistY;
			int YOffset;
			char acBuffer[100];
			GUI_RECT rFocus;
			GUI_RECT rInside;

			Sel = LISTBOX_GetSel(hWin);

			GUI_SetBkColor(0xf2f2f2);
			GUI_SetColor(GUI_WHITE);
			YSize = _GetItemSizeY(hWin, Index);

			YOffset = 1;

			WM_GetInsideRectEx(pDrawItemInfo->hWin, &rInside);
			rFocus.x0 = pDrawItemInfo->x0+1;
			rFocus.y0 = pDrawItemInfo->y0 + YOffset;
			rFocus.x1 = rInside.x1-21;
			rFocus.y1 = pDrawItemInfo->y0 + YSize - YOffset;

			LISTBOX_GetItemText(pDrawItemInfo->hWin, pDrawItemInfo->ItemIndex, acBuffer, sizeof(acBuffer));
			GUI_Clear();
			// Draw focus rectangle if item is selected
			if ((pDrawItemInfo->ItemIndex == Sel)) {
				rFocus.y0-=3;
				rFocus.y1-=1;
				GUI_SetColor(0x009e5a);
				// Refer to page 948 of Manual
				GUI_AA_FillRoundedRectEx(&rFocus, 2);
				GUI_SetTextMode(GUI_TEXTMODE_TRANS);
				//GUI_SetBkColor(GUI_TRANSPARENT);
				GUI_SetColor(GUI_WHITE);
				FontDistY = GUI_GetFontDistY();
				FontDistX = GUI_GetStringDistX(acBuffer);
				// Center text
				GUI_DispStringAt(acBuffer, pDrawItemInfo->x0 + (pDrawItemInfo->x0 + rFocus.x1)/2 - (FontDistX/2), pDrawItemInfo->y0 + ((YSize - FontDistY) / 2) - YOffset);
			}
			else {
				YSize = YSize - 2;
				GUI_SetBkColor(0xf2f2f2);
				GUI_SetColor(0x707070);
				FontDistY = GUI_GetFontDistY();
				FontDistX = GUI_GetStringDistX(acBuffer);
				GUI_DispStringAt(acBuffer, pDrawItemInfo->x0 + (pDrawItemInfo->x0 + rFocus.x1)/2 - (FontDistX/2), pDrawItemInfo->y0 + ((YSize - FontDistY) / 2));
				GUI_DispCEOL();
			}
		}
		break;
		default:
			return LISTBOX_OwnerDraw(pDrawItemInfo);
	}
	return 0;
}
static void _cbDialog(WM_MESSAGE * pMsg)
{
    WM_HWIN hItem, spinner;
    int     NCode;
    int     Id;
    int i;
    wifi_count =  GUI_COUNTOF(wifi_networks);

    switch (pMsg->MsgId)
    {
    case WM_PAINT:
        GUI_DrawGradientV(0, 0, 480, 50, color_map[0].stop, color_map[0].start);
        GUI_DrawBitmap(&bmwatermark,45,52);
        break;
    case WM_INIT_DIALOG:
        //
        hItem = WM_GetDialogItem(pMsg->hWin, ID_TEXT_HEADER);
        TEXT_SetFont(hItem, HEADER_FONT_BOLD);
        TEXT_SetTextAlign(hItem, GUI_TA_HCENTER | GUI_TA_VCENTER);
        TEXT_SetTextColor(hItem, GUI_MAKE_COLOR(0x00FFFFFF));
        TEXT_SetText(hItem, LANG("SELECT WIFI NETWORK"));
        //
        listBox_h = WM_GetDialogItem(pMsg->hWin, ID_LISTBOX_0);
        LISTBOX_SetFont(listBox_h, Tahoma23B);
        LISTBOX_SetAutoScrollV(listBox_h, 1);
        LISTBOX_SetScrollbarWidth(listBox_h, 20);
        LISTBOX_SetOwnerDraw(listBox_h, drawRoundedListBox);

        for (i=0; i<wifi_count; i++)
        {
            LISTBOX_AddString(listBox_h, wifi_networks[i]);
        }
        LISTBOX_SetItemSel(listBox_h, 2, 0);

        hItem = WM_GetDialogItem(pMsg->hWin, ID_BUTTON_CANCEL);
        WM_SetCallback(hItem, buttonOn_cb);
        if (firstTime)
        {
            BUTTON_SetText(hItem, "BACK");
        }
        else
        {
            BUTTON_SetText(hItem, "CANCEL");
        }
        //
        hItem = WM_GetDialogItem(pMsg->hWin, ID_BUTTON_RESCAN);
        WM_SetCallback(hItem, buttonOn_cb);
        if (firstTime)
        {
            WM_MoveTo(hItem, 140, 230);
        }
        else
        {
            WM_MoveTo(hItem, 200, 230);
        }

        hItem = WM_GetDialogItem(pMsg->hWin, ID_BUTTON_LATER);
        WM_SetCallback(hItem, buttonOn_cb);
        if (!firstTime)
        {
            WM_HideWin(hItem);
        }

        hItem = WM_GetDialogItem(pMsg->hWin, ID_BUTTON_SAVE);
        WM_SetCallback(hItem, buttonOn_cb);
        if (firstTime)
        {
            BUTTON_SetText(hItem, "NEXT");
        }
        else
        {
            BUTTON_SetText(hItem, "SAVE");
        }

        break;
    case WM_NOTIFY_PARENT:
        Id    = WM_GetId(pMsg->hWinSrc);
        NCode = pMsg->Data.v;
        char room[30];
        switch(Id)
        {
        case ID_LISTBOX_0:
            break;

        case ID_BUTTON_CANCEL:
            switch(NCode)
            {
            case WM_NOTIFICATION_RELEASED:
                GUI_Delay(100);
                WM_DeleteWindow(wifiConnectWin);
                if (firstTime)
                {
                    CreateHvacType();
                }
                else
                {
                    CreateWifiSetup();
                }
            }
            break;
        case ID_BUTTON_RESCAN:
            switch(NCode)
            {
            case WM_NOTIFICATION_RELEASED:
                GUI_Delay(100);
                //CreateRescan();
            }
            break;
        case ID_BUTTON_LATER:
            switch(NCode)
            {
            case WM_NOTIFICATION_RELEASED:
                GUI_Delay(100);
                firstTime = 0;
                WM_DeleteWindow(wifiConnectWin);
                screenState = HOMEWIN;
            }
            break;
        case ID_BUTTON_SAVE:
            switch(NCode)
            {
            case WM_NOTIFICATION_RELEASED:
                wifi = LISTBOX_GetSel(listBox_h);
                strcpy(myWifiNetwork, wifi_networks[wifi]);
                WM_DeleteWindow(wifiConnectWin);
                GUI_Delay(100);
                CreateKeyboardWin(-2, "", "Wifi Password", "wifi");
            }
            break;
        }
        break;
    default:
        WM_DefaultProc(pMsg);
        break;
    }
}

WM_HWIN CreateWifiConnect(void);
WM_HWIN CreateWifiConnect(void)
{
    WM_HWIN hWin;

    wifiConnectWin = GUI_CreateDialogBox(_aDialogCreate, GUI_COUNTOF(_aDialogCreate), _cbDialog, WM_HBKWIN, 0, 0);
    return hWin;
}
