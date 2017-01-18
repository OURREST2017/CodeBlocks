#include "main.h"


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

/*********************************************************************
*
*   	_OwnerDraw
*
* Function description
*   This is the owner draw function.
*   It allows complete customization of how the items in the listbox are
*   drawn. A command specifies what the function should do;
*   The minimum is to react to the draw command (WIDGET_ITEM_DRAW);
*   If the item x-size differs from the default, then this information
*   needs to be returned in reaction to WIDGET_ITEM_GET_XSIZE.
*   To insure compatibility with future version, all unhandled commands
*   must call the default routine LISTBOX_OwnerDraw.
* LISTBOX_SetOwnerDraw(hListBox, drawRoundedListBox);
*/
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

			GUI_SetBkColor(GUI_BLACK);
			GUI_SetColor(GUI_WHITE);
			YSize = _GetItemSizeY(hWin, Index);
			
			YOffset = 3;

			WM_GetInsideRectEx(pDrawItemInfo->hWin, &rInside);
			rFocus.x0 = pDrawItemInfo->x0;
			rFocus.y0 = pDrawItemInfo->y0 + YOffset;
			rFocus.x1 = rInside.x1;
			rFocus.y1 = pDrawItemInfo->y0 + YSize - YOffset;			
			
			LISTBOX_GetItemText(pDrawItemInfo->hWin, pDrawItemInfo->ItemIndex, acBuffer, sizeof(acBuffer));
			GUI_Clear();
			// Draw focus rectangle if item is selected
			if ((pDrawItemInfo->ItemIndex == Sel)) {
				rFocus.y0-=3;
				rFocus.y1-=1;
				GUI_SetColor(GUI_GREEN);
				// Refer to page 948 of Manual
				GUI_AA_FillRoundedRectEx(&rFocus, (int)floor((rFocus.y1 - rFocus.y0)/2));
				GUI_SetTextMode(GUI_TEXTMODE_TRANS);
				GUI_SetBkColor(GUI_TRANSPARENT);
				GUI_SetColor(GUI_BLACK);
				FontDistY = GUI_GetFontDistY();
				FontDistX = GUI_GetStringDistX(acBuffer);
				// Center text
				GUI_DispStringAt(acBuffer, pDrawItemInfo->x0 + (pDrawItemInfo->x0 + rFocus.x1)/2 - (FontDistX/2), pDrawItemInfo->y0 + ((YSize - FontDistY) / 2) - YOffset);
			}
			else {
				YSize = YSize - 8;
				GUI_SetBkColor(GUI_BLACK);
				GUI_SetColor(GUI_WHITE);
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