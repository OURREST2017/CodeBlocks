#include "ranger.h"

#define ID_WINDOW_0  (GUI_ID_USER + 0x00)
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

/*********************************************************************
*
*       _aDialogCreate
*/
static const GUI_WIDGET_CREATE_INFO _aDialogCreate[] =
{
    { WINDOW_CreateIndirect, "Window", ID_WINDOW_0, 0, 0, 480, 272, 0, 0x0, 0 },
    { TEXT_CreateIndirect, "", ID_TEXT_HEADER, 0, 0, 480, 50, 0, 0x64, 0 },
    { EDIT_CreateIndirect, "Edit", ID_EDIT_TEXT, 18, 60, 446, 25, 0, 0x64, 0 },
    { BUTTON_CreateIndirect, "1", ID_BUTTON_Q, 10, 96, 35, 32, 0, 0x0, 0 },
    { BUTTON_CreateIndirect, "2", ID_BUTTON_W, 57, 96, 35, 32, 0, 0x0, 0 },
    { BUTTON_CreateIndirect, "3", ID_BUTTON_E, 104, 96, 35, 32, 0, 0x0, 0 },
    { BUTTON_CreateIndirect, "4", ID_BUTTON_R, 151, 96, 35, 32, 0, 0x0, 0 },
    { BUTTON_CreateIndirect, "5", ID_BUTTON_T, 198, 96, 35, 32, 0, 0x0, 0 },
    { BUTTON_CreateIndirect, "6", ID_BUTTON_Y, 245, 96, 35, 32, 0, 0x0, 0 },
    { BUTTON_CreateIndirect, "7", ID_BUTTON_U, 291, 96, 35, 32, 0, 0x0, 0 },
    { BUTTON_CreateIndirect, "8", ID_BUTTON_I, 339, 96, 35, 32, 0, 0x0, 0 },
    { BUTTON_CreateIndirect, "9", ID_BUTTON_O, 386, 96, 35, 32, 0, 0x0, 0 },
    { BUTTON_CreateIndirect, "0", ID_BUTTON_P, 433, 96, 35, 32, 0, 0x0, 0 },
    { BUTTON_CreateIndirect, "-", ID_BUTTON_A, 34, 136, 35, 32, 0, 0x0, 0 },
    { BUTTON_CreateIndirect, "/", ID_BUTTON_S, 81, 136, 35, 32, 0, 0x0, 0 },
    { BUTTON_CreateIndirect, ":", ID_BUTTON_D, 128, 136, 35, 32, 0, 0x0, 0 },
    { BUTTON_CreateIndirect, ";", ID_BUTTON_F, 175, 136, 35, 32, 0, 0x0, 0 },
    { BUTTON_CreateIndirect, "(", ID_BUTTON_G, 222, 136, 35, 32, 0, 0x0, 0 },
    { BUTTON_CreateIndirect, ")", ID_BUTTON_H, 269, 136, 35, 32, 0, 0x0, 0 },
    { BUTTON_CreateIndirect, "$", ID_BUTTON_J, 316, 136, 35, 32, 0, 0x0, 0 },
    { BUTTON_CreateIndirect, "@", ID_BUTTON_K, 363, 136, 35, 32, 0, 0x0, 0 },
    { BUTTON_CreateIndirect, "&", ID_BUTTON_L, 410, 136, 35, 32, 0, 0x0, 0 },
    { BUTTON_CreateIndirect, "SHIFT", ID_BUTTON_SHIFT, 10, 176, 65, 32, 0, 0x0, 0 },
    { BUTTON_CreateIndirect, ".", ID_BUTTON_Z, 82, 176, 35, 32, 0, 0x0, 0 },
    { BUTTON_CreateIndirect, ",", ID_BUTTON_X, 129, 176, 35, 32, 0, 0x0, 0 },
    { BUTTON_CreateIndirect, "?", ID_BUTTON_C, 176, 176, 35, 32, 0, 0x0, 0 },
    { BUTTON_CreateIndirect, "!", ID_BUTTON_V, 223, 176, 35, 32, 0, 0x0, 0 },
    { BUTTON_CreateIndirect, "'", ID_BUTTON_B, 270, 176, 35, 32, 0, 0x0, 0 },
    { BUTTON_CreateIndirect, ".com", ID_BUTTON_N, 317, 176, 82, 32, 0, 0x0, 0 },
    { BUTTON_CreateIndirect, "", ID_BUTTON_ERASE, 410, 176, 58, 32, 0, 0x0, 0 },
    { BUTTON_CreateIndirect, "CANCEL", ID_BUTTON_CANCEL, 20, 216, 85, 32, 0, 0x0, 0 },
    { BUTTON_CreateIndirect, "ABC", ID_BUTTON_ABC, 114, 216, 70, 32, 0, 0x0, 0 },
    { BUTTON_CreateIndirect, "SPACE", ID_BUTTON_SPACE, 192, 216, 190, 32, 0, 0x0, 0 },
    { BUTTON_CreateIndirect, "DONE", ID_BUTTON_DONE, 392, 216, 70, 32, 0, 0x0, 0 },
};

/*********************************************************************
*
*       _cbDialog
*/
static WM_HWIN textItem;
static char txt_buffer[50], edit_title[30], from_screen[20];
static int text_index;

extern GUI_CONST_STORAGE GUI_BITMAP back_space_white;
extern GUI_CONST_STORAGE GUI_BITMAP back_space_black;

extern void shift_cb(WM_MESSAGE * pMsg);
extern void keys_cb(WM_MESSAGE * pMsg);
extern void keys_disable_cb(WM_MESSAGE * pMsg);

static void _cbDialog(WM_MESSAGE * pMsg)
{
    WM_HWIN hItem;
    int     NCode;
    int     Id;
    char buf[30];
    switch (pMsg->MsgId)
    {
    case WM_PAINT:
        GUI_DrawGradientV(0, 0, 480, 50, color_map[0].stop, color_map[0].start);
        GUI_SetColor(0xf2f2f2);
        GUI_AA_FillRoundedRect(10,57,465,85, 6);
        GUI_SetColor(0xdbdbdb);
        GUI_SetPenSize(3);
        GUI_AA_DrawRoundedRect(10,57,465,85, 6);
        break;
    case WM_INIT_DIALOG:
        hItem = pMsg->hWin;
        BUTTON_SKINFLEX_PROPS Props;
        BUTTON_GetSkinFlexProps(&Props, BUTTON_SKINFLEX_PI_ENABLED);
        Props.aColorUpper[0] = 0xf2f2f2;//0x48866c;
        Props.aColorLower[1] = 0xf2f2f2;//0x62b29a;
        BUTTON_SetSkinFlexProps(&Props, BUTTON_SKINFLEX_PI_PRESSED);

        hItem = WM_GetDialogItem(pMsg->hWin, ID_TEXT_HEADER);
        TEXT_SetFont(hItem, GUI_FONT_32B_1);
        TEXT_SetTextAlign(hItem, GUI_TA_HCENTER | GUI_TA_VCENTER);
        TEXT_SetTextColor(hItem, GUI_MAKE_COLOR(0x00FFFFFF));
        sprintf(buf, "EDIT: %s", edit_title);
        TEXT_SetText(hItem, buf);

        textItem = WM_GetDialogItem(pMsg->hWin, ID_EDIT_TEXT);
        EDIT_SetText(textItem, txt_buffer);
        EDIT_SetFont(textItem, GUI_FONT_20_1);
        EDIT_SetTextAlign(textItem, GUI_TA_HCENTER | GUI_TA_VCENTER);
        EDIT_SetBkColor(textItem, 1, 0xf2f2f2);
        EDIT_SetTextColor(textItem, 1, 0x808080);
        WIDGET_SetEffect(textItem, &WIDGET_Effect_None);
        //
        int i;
        for (i=2051; i<2077; i++)
        {
            hItem = WM_GetDialogItem(pMsg->hWin, i);
            BUTTON_SetFont(hItem, &GUI_FontRounded22);
            if (i > 2061)
            {
                WM_DisableWindow(hItem);
                WM_SetCallback(hItem, keys_disable_cb);
            }
            else
            {
                WM_SetCallback(hItem, keys_cb);
            }
        }

        hItem = WM_GetDialogItem(pMsg->hWin, ID_BUTTON_ERASE);
        BUTTON_SetText(hItem, "back");
        WM_SetCallback(hItem, keys_cb);

        hItem = WM_GetDialogItem(pMsg->hWin, ID_BUTTON_SHIFT);
        WM_SetCallback(hItem, keys_disable_cb);
        WM_DisableWindow(hItem);

        hItem = WM_GetDialogItem(pMsg->hWin, ID_BUTTON_CANCEL);
        WM_SetCallback(hItem, keys_cb);
        //
        hItem = WM_GetDialogItem(pMsg->hWin, ID_BUTTON_ABC);
        if (strcmp(from_screen, "Profile") == 0)
        {
            WM_SetCallback(hItem, keys_disable_cb);
            WM_DisableWindow(hItem);
        }
        else
        {
            WM_SetCallback(hItem, keys_cb);
        }
        //
        hItem = WM_GetDialogItem(pMsg->hWin, ID_BUTTON_DONE);
        WM_SetCallback(hItem, keys_cb);
        //
        hItem = WM_GetDialogItem(pMsg->hWin, ID_BUTTON_SPACE);
        BUTTON_SetFont(hItem, GUI_FONT_20_1);
        WM_SetCallback(hItem, keys_disable_cb);
        WM_DisableWindow(hItem);

        break;
    case WM_NOTIFY_PARENT:
        Id    = WM_GetId(pMsg->hWinSrc);
        NCode = pMsg->Data.v;
        int len;
        char buf[10], acBuffer[10];
        switch(NCode)
        {
        case WM_NOTIFICATION_RELEASED:
            switch (Id)
            {
            case ID_BUTTON_ABC:
                CreateAlphaKeyboard(text_index, txt_buffer, edit_title, from_screen);
                break;
            case ID_BUTTON_CANCEL:
                if (strcmp(from_screen, "Edit Room") == 0)
                {
                    CreateEditRoom(text_index);
                }
                else if (strcmp(from_screen, "wifi") == 0)
                {
                    strcpy(myWifiPassword, txt_buffer);
                    CreateWifiSetup();
                }
                else
                {
                    CreateProfile(-1, txt_buffer);
                }
                break;
            case ID_BUTTON_DONE:
                if (strcmp(from_screen, "Edit Room") == 0)
                {
                    strcpy(thermo_rooms[text_index], txt_buffer);
                    CreateEditRoom(text_index);
                }
                else if (strcmp(from_screen, "wifi") == 0)
                {
                    strcpy(myWifiPassword, txt_buffer);
                    CreateWifiSetup();
                }
                else
                {
                    CreateProfile(text_index, txt_buffer);
                }
                break;
            case ID_EDIT_TEXT:
                break;
            case ID_BUTTON_ERASE:
                hItem = WM_GetDialogItem(pMsg->hWin, ID_EDIT_TEXT);
                EDIT_GetText(hItem, txt_buffer, 50);
                len = strlen(txt_buffer);
                if (len == 0) break;
                txt_buffer[len-1] = '\0';
                EDIT_SetText(hItem, txt_buffer);
                break;
            case ID_BUTTON_SPACE:
                hItem = WM_GetDialogItem(pMsg->hWin, ID_EDIT_TEXT);
                EDIT_GetText(hItem, txt_buffer, 50);
                len = strlen(txt_buffer);
                if (len == 50) break;
                txt_buffer[len] = ' ';
                txt_buffer[len+1] = '\0';
                EDIT_SetText(hItem, txt_buffer);
                break;
            default:
                if ((Id >= GUI_ID_USER) && (Id <= (GUI_ID_USER + GUI_COUNTOF(_aDialogCreate) - 1)))
                {
                    BUTTON_GetText(pMsg->hWinSrc, acBuffer, sizeof(acBuffer));
                    hItem = WM_GetDialogItem(pMsg->hWin, ID_EDIT_TEXT);
                    EDIT_GetText(hItem, txt_buffer, 50);
                    len = strlen(txt_buffer);
                    if (len == 50) break;
                    txt_buffer[len] = acBuffer[0];
                    txt_buffer[len+1] = '\0';
                    EDIT_SetText(hItem, txt_buffer);
                }
                break;
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
WM_HWIN CreateNumericKeyboard(int room, char * txt, char * title, char * screen);
WM_HWIN CreateNumericKeyboard(int room, char * txt, char * title, char * screen)
{
    WM_HWIN hWin;

    text_index = room;
    strcpy(edit_title, title);
    strcpy(txt_buffer, txt);
    strcpy(from_screen, screen);
    hWin = GUI_CreateDialogBox(_aDialogCreate, GUI_COUNTOF(_aDialogCreate), _cbDialog, WM_HBKWIN, 0, 0);
    return hWin;
}

/*************************** End of file ****************************/
