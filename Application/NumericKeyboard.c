/*********************************************************************
*                                                                    *
*                SEGGER Microcontroller GmbH & Co. KG                *
*        Solutions for real time microcontroller applications        *
*                                                                    *
**********************************************************************
*                                                                    *
* C-file generated by:                                               *
*                                                                    *
*        GUI_Builder for emWin version 5.32                          *
*        Compiled Oct  8 2015, 11:59:02                              *
*        (c) 2015 Segger Microcontroller GmbH & Co. KG               *
*                                                                    *
**********************************************************************
*                                                                    *
*        Internet: www.segger.com  Support: support@segger.com       *
*                                                                    *
**********************************************************************
*/


#include "main.h"

#define ID_WINDOW_0  (GUI_ID_USER + 0x00)
#define ID_HEADER_0  (GUI_ID_USER + 0x01)
#define ID_TEXT_HEADER (GUI_ID_USER + 0x23)
#define ID_EDIT_TEXT  (GUI_ID_USER + 0x02)
#define ID_BUTTON_Q  (GUI_ID_USER + 0x03)
#define ID_BUTTON_W  (GUI_ID_USER + 0x04)
#define ID_BUTTON_E  (GUI_ID_USER + 0x05)
#define ID_BUTTON_R  (GUI_ID_USER + 0x06)
#define ID_BUTTON_T  (GUI_ID_USER + 0x07)
#define ID_BUTTON_Y  (GUI_ID_USER + 0x08)
#define ID_BUTTON_U  (GUI_ID_USER + 0x09)
#define ID_BUTTON_I  (GUI_ID_USER + 0x0A)
#define ID_BUTTON_O  (GUI_ID_USER + 0x0B)
#define ID_BUTTON_P  (GUI_ID_USER + 0x0C)
#define ID_BUTTON_A  (GUI_ID_USER + 0x0D)
#define ID_BUTTON_S  (GUI_ID_USER + 0x0E)
#define ID_BUTTON_D  (GUI_ID_USER + 0x0F)
#define ID_BUTTON_F  (GUI_ID_USER + 0x10)
#define ID_BUTTON_G  (GUI_ID_USER + 0x11)
#define ID_BUTTON_H  (GUI_ID_USER + 0x12)
#define ID_BUTTON_J  (GUI_ID_USER + 0x13)
#define ID_BUTTON_K  (GUI_ID_USER + 0x14)
#define ID_BUTTON_L  (GUI_ID_USER + 0x15)
#define ID_BUTTON_SHIFT  (GUI_ID_USER + 0x16)
#define ID_BUTTON_Z  (GUI_ID_USER + 0x17)
#define ID_BUTTON_X  (GUI_ID_USER + 0x18)
#define ID_BUTTON_C  (GUI_ID_USER + 0x19)
#define ID_BUTTON_V  (GUI_ID_USER + 0x1A)
#define ID_BUTTON_B  (GUI_ID_USER + 0x1B)
#define ID_BUTTON_N  (GUI_ID_USER + 0x1C)
#define ID_BUTTON_ERASE  (GUI_ID_USER + 0x1E)
#define ID_BUTTON_CANCEL  (GUI_ID_USER + 0x1F)
#define ID_BUTTON_ABC  (GUI_ID_USER + 0x20)
#define ID_BUTTON_DONE  (GUI_ID_USER + 0x21)
#define ID_BUTTON_SPACE  (GUI_ID_USER + 0x22)

static GUI_CONST_STORAGE unsigned char back_space_img[] =
{
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x11, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x11, 0x11, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x11, 0x11, 0x11, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x11, 0x11, 0x11, 0x11, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x01, 0x11, 0x11, 0x11, 0x11, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x01, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x00,
    0x01, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x00,
    0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x00,
    0x01, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x00,
    0x00, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x00,
    0x00, 0x00, 0x11, 0x11, 0x11, 0x11, 0x11, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x01, 0x11, 0x11, 0x11, 0x11, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x01, 0x11, 0x11, 0x11, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x01, 0x11, 0x11, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x11, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
};

static const GUI_COLOR Colors[] = { 0x000000, 0x000000 };
static const GUI_LOGPALETTE Palette = { 2, 1, Colors };

GUI_CONST_STORAGE GUI_BITMAP back_space2 =
{
    44, // xSize
    16, // ySize
    22, // BytesPerLine
    4, // BitsPerPixel
    back_space_img,  // Pointer to picture data (indices)
    &Palette   // Pointer to palette
};
/*********************************************************************
*
*       _aDialogCreate
*/
static const GUI_WIDGET_CREATE_INFO _aDialogCreate[] =
{
    { WINDOW_CreateIndirect, "Window", ID_WINDOW_0, 0, 0, 480, 272, 0, 0x0, 0 },
    { HEADER_CreateIndirect, "Header", ID_HEADER_0, 0, 0, 480, 50, 0, 0x0, 0 },
    { TEXT_CreateIndirect, "NUMERIC/SPECIAL KEYBOARD", ID_TEXT_HEADER, 0, 0, 480, 50, 0, 0x64, 0 },
    { EDIT_CreateIndirect, "Edit", ID_EDIT_TEXT, 18, 60, 446, 25, 0, 0x64, 0 },
    { BUTTON_CreateIndirect, "1", ID_BUTTON_Q, 10, 96, 35, 32, 0, 0x0, 0 },
    { BUTTON_CreateIndirect, "2", ID_BUTTON_W, 57, 96, 35, 32, 0, 0x0, 0 },
    { BUTTON_CreateIndirect, "3", ID_BUTTON_E, 104, 96, 35, 32, 0, 0x0, 0 },
    { BUTTON_CreateIndirect, "4", ID_BUTTON_R, 152, 96, 35, 32, 0, 0x0, 0 },
    { BUTTON_CreateIndirect, "5", ID_BUTTON_T, 200, 96, 35, 32, 0, 0x0, 0 },
    { BUTTON_CreateIndirect, "6", ID_BUTTON_Y, 247, 96, 35, 32, 0, 0x0, 0 },
    { BUTTON_CreateIndirect, "7", ID_BUTTON_U, 291, 96, 35, 32, 0, 0x0, 0 },
    { BUTTON_CreateIndirect, "8", ID_BUTTON_I, 338, 96, 35, 32, 0, 0x0, 0 },
    { BUTTON_CreateIndirect, "9", ID_BUTTON_O, 382, 96, 35, 32, 0, 0x0, 0 },
    { BUTTON_CreateIndirect, "0", ID_BUTTON_P, 428, 95, 35, 32, 0, 0x0, 0 },
    { BUTTON_CreateIndirect, "-", ID_BUTTON_A, 33, 140, 35, 32, 0, 0x0, 0 },
    { BUTTON_CreateIndirect, "/", ID_BUTTON_S, 83, 140, 35, 32, 0, 0x0, 0 },
    { BUTTON_CreateIndirect, ":", ID_BUTTON_D, 129, 140, 35, 32, 0, 0x0, 0 },
    { BUTTON_CreateIndirect, ";", ID_BUTTON_F, 180, 140, 35, 32, 0, 0x0, 0 },
    { BUTTON_CreateIndirect, "'", ID_BUTTON_B, 275, 182, 35, 32, 0, 0x0, 0 },
    { BUTTON_CreateIndirect, ".com", ID_BUTTON_N, 317, 182, 70, 32, 0, 0x0, 0 },
    { BUTTON_CreateIndirect, "(", ID_BUTTON_G, 226, 140, 35, 32, 0, 0x0, 0 },
    { BUTTON_CreateIndirect, ")", ID_BUTTON_H, 273, 140, 35, 32, 0, 0x0, 0 },
    { BUTTON_CreateIndirect, "$", ID_BUTTON_J, 316, 140, 35, 32, 0, 0x0, 0 },
    { BUTTON_CreateIndirect, "@", ID_BUTTON_K, 362, 140, 35, 32, 0, 0x0, 0 },
    { BUTTON_CreateIndirect, "&", ID_BUTTON_L, 405, 140, 35, 32, 0, 0x0, 0 },
    { BUTTON_CreateIndirect, "SHIFT", ID_BUTTON_SHIFT, 11, 182, 65, 32, 0, 0x0, 0 },
    { BUTTON_CreateIndirect, ".", ID_BUTTON_Z, 83, 182, 35, 32, 0, 0x0, 0 },
    { BUTTON_CreateIndirect, ",", ID_BUTTON_X, 129, 182, 35, 32, 0, 0x0, 0 },
    { BUTTON_CreateIndirect, "?", ID_BUTTON_C, 182, 182, 35, 32, 0, 0x0, 0 },
    { BUTTON_CreateIndirect, "!", ID_BUTTON_V, 229, 182, 35, 32, 0, 0x0, 0 },
    { BUTTON_CreateIndirect, "", ID_BUTTON_ERASE, 400, 182, 60, 32, 0, 0x0, 0 },
    { BUTTON_CreateIndirect, "CANCEL", ID_BUTTON_CANCEL, 28, 225, 85, 32, 0, 0x0, 0 },
    { BUTTON_CreateIndirect, "ABC", ID_BUTTON_ABC, 122, 225, 70, 32, 0, 0x0, 0 },
    { BUTTON_CreateIndirect, "DONE", ID_BUTTON_DONE, 400, 225, 70, 32, 0, 0x0, 0 },
    { BUTTON_CreateIndirect, "SPACE", ID_BUTTON_SPACE, 200, 225, 190, 32, 0, 0x0, 0 },
};

/*********************************************************************
*
*       _cbDialog
*/
WM_HWIN textItem;
static void _cbDialog(WM_MESSAGE * pMsg)
{
    WM_HWIN hItem;
    int     NCode;
    int     Id;

    switch (pMsg->MsgId)
    {
    case WM_INIT_DIALOG:
        hItem = pMsg->hWin;
        WINDOW_SetBkColor(hItem, 0x00FFFFFF);
        BUTTON_SKINFLEX_PROPS Props;
        BUTTON_GetSkinFlexProps(&Props, BUTTON_SKINFLEX_PI_ENABLED);
        Props.aColorFrame[0] = 0xbbbbbb;
        Props.aColorFrame[1] = 0xeeeeee;
        Props.aColorFrame[2] = 0xeeeeee;
        Props.aColorUpper[0] = 0xcfc4d8;
        Props.aColorUpper[1] = 0xdfd4d8;
        Props.aColorLower[0] = 0xdfd4d8;
        Props.aColorLower[1] = 0xdfdfdf;
        Props.Radius = 2;
        BUTTON_SetSkinFlexProps(&Props, BUTTON_SKINFLEX_PI_ENABLED);
        Props.aColorUpper[0] = 0x48866c;
        //Props.aColorUpper[1] = 0xcccccc;
        //Props.aColorLower[0] = 0xdddddd;
        Props.aColorLower[1] = 0x62b29a;
        BUTTON_SetSkinFlexProps(&Props, BUTTON_SKINFLEX_PI_PRESSED);
        Props.aColorUpper[0] = 0xeeeeee;
        Props.aColorUpper[1] = 0xeeeeee;
        Props.aColorLower[0] = 0xeeeeee;
        Props.aColorLower[1] = 0xeeeeee;
        BUTTON_SetSkinFlexProps(&Props, BUTTON_SKINFLEX_PI_DISABLED);

        hItem = WM_GetDialogItem(pMsg->hWin, ID_TEXT_HEADER);
        TEXT_SetFont(hItem, GUI_FONT_32B_1);
        TEXT_SetTextAlign(hItem, GUI_TA_HCENTER | GUI_TA_VCENTER);
        TEXT_SetTextColor(hItem, GUI_MAKE_COLOR(0x00FFFFFF));

        /* Store new skin properties to enabled button */
        textItem = WM_GetDialogItem(pMsg->hWin, ID_EDIT_TEXT);
        EDIT_SetText(textItem, "123");
        EDIT_SetFont(textItem, GUI_FONT_20_1);
        EDIT_SetTextAlign(textItem, GUI_TA_LEFT | GUI_TA_VCENTER);
        //
        int i;
        for (i=2051; i<2077; i++)
        {
            hItem = WM_GetDialogItem(pMsg->hWin, i);
            BUTTON_SetFont(hItem, GUI_FONT_20B_1);
            if (i > 2061) WM_DisableWindow(hItem);
        }

        hItem = WM_GetDialogItem(pMsg->hWin, ID_BUTTON_ERASE);
        BUTTON_SetBitmapEx(hItem, 0,  &back_space2, 10, 8);

        hItem = WM_GetDialogItem(pMsg->hWin, ID_BUTTON_SHIFT);
        BUTTON_SetFont(hItem, GUI_FONT_20_1);
        BUTTON_SetTextColor(hItem, BUTTON_CI_DISABLED, GUI_GRAY);
        WM_DisableWindow(hItem);

        hItem = WM_GetDialogItem(pMsg->hWin, ID_BUTTON_CANCEL);
        BUTTON_SetFont(hItem, GUI_FONT_20_1);
        //
        hItem = WM_GetDialogItem(pMsg->hWin, ID_BUTTON_ABC);
        BUTTON_SetFont(hItem, GUI_FONT_20_1);
        //
        hItem = WM_GetDialogItem(pMsg->hWin, ID_BUTTON_DONE);
        BUTTON_SetFont(hItem, GUI_FONT_20_1);
        //
        hItem = WM_GetDialogItem(pMsg->hWin, ID_BUTTON_SPACE);
        BUTTON_SetFont(hItem, GUI_FONT_20_1);
        WM_DisableWindow(hItem);

        break;
    case WM_NOTIFY_PARENT:
        Id    = WM_GetId(pMsg->hWinSrc);
        NCode = pMsg->Data.v;
        switch(NCode)
        {
        case WM_NOTIFICATION_RELEASED:
            if ((Id >= GUI_ID_USER) && (Id <= (GUI_ID_USER + GUI_COUNTOF(_aDialogCreate) - 1)))
            {
                char buf[10], txt_buffer[50], acBuffer[10];
                BUTTON_GetText(pMsg->hWinSrc, acBuffer, sizeof(acBuffer));
                if (Id == ID_BUTTON_ERASE)
                {
                    hItem = WM_GetDialogItem(pMsg->hWin, ID_EDIT_TEXT);
                    EDIT_GetText(hItem, txt_buffer, 50);
                    int l = strlen(txt_buffer);
                    if (l == 0) break;
                    txt_buffer[l-1] = '\0';
                    EDIT_SetText(hItem, txt_buffer);
                }
                else if (Id == ID_BUTTON_ABC)
                {
                    state = 8;
                    break;
                }
                else if (Id == ID_BUTTON_CANCEL)
                {
                    setSkin();
                    state = 15;
                    break;
                }
                else if (Id == ID_BUTTON_DONE)
                {
                    setSkin();
                    state = 15;
                    break;
                }
                else
                {
                    EDIT_GetText(textItem, txt_buffer, 50);
                    int l = strlen(txt_buffer);
                    if (l == 50) break;
                    int l2 = strlen(acBuffer);
                    txt_buffer[l] = acBuffer[0];
                    txt_buffer[l+1] = '\0';
                    EDIT_SetText(textItem, txt_buffer);
                }
            }
            WM_SetFocus(textItem);
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
WM_HWIN CreateNumericKeyboard(void);
WM_HWIN CreateNumericKeyboard(void)
{
    WM_HWIN hWin;

    hWin = GUI_CreateDialogBox(_aDialogCreate, GUI_COUNTOF(_aDialogCreate), _cbDialog, WM_HBKWIN, 0, 0);
    return hWin;
}

/*************************** End of file ****************************/
