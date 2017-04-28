#include "ranger.h"

#define ID_WINDOW_0  (GUI_ID_USER + 0x00)
#define ID_TEXT_HEADER (GUI_ID_USER + 0x20)
#define ID_EDIT_TEXT  (GUI_ID_USER + 0x21)

#define ID_BUTTON_0            (GUI_ID_USER + 0x01)  // a
#define ID_BUTTON_1            (GUI_ID_USER + 0x02)  // b
#define ID_BUTTON_2            (GUI_ID_USER + 0x03)  // c
#define ID_BUTTON_3            (GUI_ID_USER + 0x04)  // etc..
#define ID_BUTTON_4            (GUI_ID_USER + 0x05)
#define ID_BUTTON_5            (GUI_ID_USER + 0x06)
#define ID_BUTTON_6            (GUI_ID_USER + 0x07)
#define ID_BUTTON_7            (GUI_ID_USER + 0x08)
#define ID_BUTTON_8            (GUI_ID_USER + 0x09)
#define ID_BUTTON_9            (GUI_ID_USER + 0x0A)
#define ID_BUTTON_10           (GUI_ID_USER + 0x0B)
#define ID_BUTTON_11           (GUI_ID_USER + 0x0C)
#define ID_BUTTON_12           (GUI_ID_USER + 0x0D)
#define ID_BUTTON_13           (GUI_ID_USER + 0x0E)
#define ID_BUTTON_14           (GUI_ID_USER + 0x0F)
#define ID_BUTTON_15           (GUI_ID_USER + 0x10)
#define ID_BUTTON_16           (GUI_ID_USER + 0x11)
#define ID_BUTTON_17           (GUI_ID_USER + 0x12)
#define ID_BUTTON_18           (GUI_ID_USER + 0x13)
#define ID_BUTTON_19           (GUI_ID_USER + 0x14)
#define ID_BUTTON_20           (GUI_ID_USER + 0x15)
#define ID_BUTTON_21           (GUI_ID_USER + 0x16)
#define ID_BUTTON_22           (GUI_ID_USER + 0x17)
#define ID_BUTTON_23           (GUI_ID_USER + 0x18)
#define ID_BUTTON_24           (GUI_ID_USER + 0x19)
#define ID_BUTTON_25           (GUI_ID_USER + 0x1A)  // z

#define ID_BUTTON_ABC  (GUI_ID_USER + 0x27)
#define ID_BUTTON_COM  (GUI_ID_USER + 0x28)

#define ID_BUTTON_123  (GUI_ID_USER + 0x29)

#define ID_BUTTON_SPACE  (GUI_ID_USER + 0x22)
#define ID_BUTTON_SHIFT  (GUI_ID_USER + 0x23)

#define ID_BUTTON_ERASE  (GUI_ID_USER + 0x24)
#define ID_BUTTON_CANCEL  (GUI_ID_USER + 0x25)
#define ID_BUTTON_DONE  (GUI_ID_USER + 0x26)

#define BUTTON_X_SIZE           37
#define BUTTON_Y_SIZE           32

#define BUTTON_X_OFFSET         2

#define BUTTON_SPACING          9

#define BUTTON_X_POS(x)         BUTTON_X_OFFSET + BUTTON_SPACING + (x * (BUTTON_X_SIZE + BUTTON_SPACING))

#define OFFSET_FIRST_ROW_Y      96
#define OFFSET_SECOND_ROW_X     BUTTON_X_SIZE / 2 + BUTTON_SPACING
#define OFFSET_SECOND_ROW_Y     BUTTON_Y_SIZE + OFFSET_FIRST_ROW_Y + 9

#define OFFSET_THIRD_ROW_X      BUTTON_X_SIZE + BUTTON_SPACING + 28
#define OFFSET_THIRD_ROW_Y      OFFSET_SECOND_ROW_Y + BUTTON_Y_SIZE + 9

static const GUI_WIDGET_CREATE_INFO keyboardDialogCreate[] =
{
    { WINDOW_CreateIndirect, "Window", ID_WINDOW_0, 0, 0, 480, 272, 0, 0x0, 0 },
    { TEXT_CreateIndirect, "", ID_TEXT_HEADER, 0, 0, 480, 50, 0, 0x64, 0 },
    { EDIT_CreateIndirect, "Edit", ID_EDIT_TEXT, 18, 60, 446, 25, 0, 0x64, 0 },
    //
    // First row
    //
    { BUTTON_CreateIndirect, "q", ID_BUTTON_0, BUTTON_X_POS(0), OFFSET_FIRST_ROW_Y, BUTTON_X_SIZE, BUTTON_Y_SIZE, 0, 0x0, 0 },
    { BUTTON_CreateIndirect, "w", ID_BUTTON_1, BUTTON_X_POS(1), OFFSET_FIRST_ROW_Y, BUTTON_X_SIZE, BUTTON_Y_SIZE, 0, 0x0, 0 },
    { BUTTON_CreateIndirect, "e", ID_BUTTON_2, BUTTON_X_POS(2), OFFSET_FIRST_ROW_Y, BUTTON_X_SIZE, BUTTON_Y_SIZE, 0, 0x0, 0 },
    { BUTTON_CreateIndirect, "r", ID_BUTTON_3, BUTTON_X_POS(3), OFFSET_FIRST_ROW_Y, BUTTON_X_SIZE, BUTTON_Y_SIZE, 0, 0x0, 0 },
    { BUTTON_CreateIndirect, "t", ID_BUTTON_4, BUTTON_X_POS(4), OFFSET_FIRST_ROW_Y, BUTTON_X_SIZE, BUTTON_Y_SIZE, 0, 0x0, 0 },
    { BUTTON_CreateIndirect, "y", ID_BUTTON_5, BUTTON_X_POS(5), OFFSET_FIRST_ROW_Y, BUTTON_X_SIZE, BUTTON_Y_SIZE, 0, 0x0, 0 },
    { BUTTON_CreateIndirect, "u", ID_BUTTON_6, BUTTON_X_POS(6), OFFSET_FIRST_ROW_Y, BUTTON_X_SIZE, BUTTON_Y_SIZE, 0, 0x0, 0 },
    { BUTTON_CreateIndirect, "i", ID_BUTTON_7, BUTTON_X_POS(7), OFFSET_FIRST_ROW_Y, BUTTON_X_SIZE, BUTTON_Y_SIZE, 0, 0x0, 0 },
    { BUTTON_CreateIndirect, "o", ID_BUTTON_8, BUTTON_X_POS(8), OFFSET_FIRST_ROW_Y, BUTTON_X_SIZE, BUTTON_Y_SIZE, 0, 0x0, 0 },
    { BUTTON_CreateIndirect, "p", ID_BUTTON_9, BUTTON_X_POS(9), OFFSET_FIRST_ROW_Y, BUTTON_X_SIZE, BUTTON_Y_SIZE, 0, 0x0, 0 },
    //
    // Second row
    //
    { BUTTON_CreateIndirect, "a", ID_BUTTON_10, OFFSET_SECOND_ROW_X + BUTTON_X_POS(0), OFFSET_SECOND_ROW_Y, BUTTON_X_SIZE, BUTTON_Y_SIZE, 0, 0x0, 0 },
    { BUTTON_CreateIndirect, "s", ID_BUTTON_11, OFFSET_SECOND_ROW_X + BUTTON_X_POS(1), OFFSET_SECOND_ROW_Y, BUTTON_X_SIZE, BUTTON_Y_SIZE, 0, 0x0, 0 },
    { BUTTON_CreateIndirect, "d", ID_BUTTON_12, OFFSET_SECOND_ROW_X + BUTTON_X_POS(2), OFFSET_SECOND_ROW_Y, BUTTON_X_SIZE, BUTTON_Y_SIZE, 0, 0x0, 0 },
    { BUTTON_CreateIndirect, "f", ID_BUTTON_13, OFFSET_SECOND_ROW_X + BUTTON_X_POS(3), OFFSET_SECOND_ROW_Y, BUTTON_X_SIZE, BUTTON_Y_SIZE, 0, 0x0, 0 },
    { BUTTON_CreateIndirect, "g", ID_BUTTON_14, OFFSET_SECOND_ROW_X + BUTTON_X_POS(4), OFFSET_SECOND_ROW_Y, BUTTON_X_SIZE, BUTTON_Y_SIZE, 0, 0x0, 0 },
    { BUTTON_CreateIndirect, "h", ID_BUTTON_15, OFFSET_SECOND_ROW_X + BUTTON_X_POS(5), OFFSET_SECOND_ROW_Y, BUTTON_X_SIZE, BUTTON_Y_SIZE, 0, 0x0, 0 },
    { BUTTON_CreateIndirect, "j", ID_BUTTON_16, OFFSET_SECOND_ROW_X + BUTTON_X_POS(6), OFFSET_SECOND_ROW_Y, BUTTON_X_SIZE, BUTTON_Y_SIZE, 0, 0x0, 0 },
    { BUTTON_CreateIndirect, "k", ID_BUTTON_17, OFFSET_SECOND_ROW_X + BUTTON_X_POS(7), OFFSET_SECOND_ROW_Y, BUTTON_X_SIZE, BUTTON_Y_SIZE, 0, 0x0, 0 },
    { BUTTON_CreateIndirect, "l", ID_BUTTON_18, OFFSET_SECOND_ROW_X + BUTTON_X_POS(8), OFFSET_SECOND_ROW_Y, BUTTON_X_SIZE, BUTTON_Y_SIZE, 0, 0x0, 0 },
    //
    // Third row
    //
    { BUTTON_CreateIndirect, "z", ID_BUTTON_19, OFFSET_THIRD_ROW_X + BUTTON_X_POS(0), OFFSET_THIRD_ROW_Y, BUTTON_X_SIZE, BUTTON_Y_SIZE, 0, 0x0, 0 },
    { BUTTON_CreateIndirect, "x", ID_BUTTON_20, OFFSET_THIRD_ROW_X + BUTTON_X_POS(1), OFFSET_THIRD_ROW_Y, BUTTON_X_SIZE, BUTTON_Y_SIZE, 0, 0x0, 0 },
    { BUTTON_CreateIndirect, "c", ID_BUTTON_21, OFFSET_THIRD_ROW_X + BUTTON_X_POS(2), OFFSET_THIRD_ROW_Y, BUTTON_X_SIZE, BUTTON_Y_SIZE, 0, 0x0, 0 },
    { BUTTON_CreateIndirect, "v", ID_BUTTON_22, OFFSET_THIRD_ROW_X + BUTTON_X_POS(3), OFFSET_THIRD_ROW_Y, BUTTON_X_SIZE, BUTTON_Y_SIZE, 0, 0x0, 0 },
    { BUTTON_CreateIndirect, "b", ID_BUTTON_23, OFFSET_THIRD_ROW_X + BUTTON_X_POS(4), OFFSET_THIRD_ROW_Y, BUTTON_X_SIZE, BUTTON_Y_SIZE, 0, 0x0, 0 },
    { BUTTON_CreateIndirect, "n", ID_BUTTON_24, OFFSET_THIRD_ROW_X + BUTTON_X_POS(5), OFFSET_THIRD_ROW_Y, BUTTON_X_SIZE, BUTTON_Y_SIZE, 0, 0x0, 0 },
    { BUTTON_CreateIndirect, "m", ID_BUTTON_25, OFFSET_THIRD_ROW_X + BUTTON_X_POS(6), OFFSET_THIRD_ROW_Y, BUTTON_X_SIZE, BUTTON_Y_SIZE, 0, 0x0, 0 },

    { BUTTON_CreateIndirect, ".com", ID_BUTTON_COM, 317, 178, 82, 32, 0, 0x0, 0 },
    { BUTTON_CreateIndirect, "back", ID_BUTTON_ERASE, 410, 178, 58, 32, 0, 0x0, 0 },
    { BUTTON_CreateIndirect, "SHIFT", ID_BUTTON_SHIFT, 10, 178, 65, 32, 0, 0x0, 0 },
    { BUTTON_CreateIndirect, "CANCEL", ID_BUTTON_CANCEL, 20, 218, 85, 32, 0, 0x0, 0 },
    { BUTTON_CreateIndirect, "ABC", ID_BUTTON_ABC, 114, 218, 70, 32, 0, 0x0, 0 },
    { BUTTON_CreateIndirect, ".?123", ID_BUTTON_123, 114, 218, 70, 32, 0, 0x0, 0 },
    { BUTTON_CreateIndirect, "SPACE", ID_BUTTON_SPACE, 192, 218, 190, 32, 0, 0x0, 0 },
    { BUTTON_CreateIndirect, "DONE", ID_BUTTON_DONE, 392, 218, 70, 32, 0, 0x0, 0 },
};

static int  shift_key = 0, room_number, alpha, key_flag;
static char from_screen[30],  txt_buffer[50],edit_title[50];
static WM_HWIN textItem;

static char en_keys[][26] =
{
    {
        'q','w','e','r','t','y','u','i','o','p',
        'a','s','d','f','g','h','j','k','l',
        'z','x','c','v','b','n','m'
    },
    {
        '1','2','3','4','5','6','7','8','9','0',
        '-','/',':',';','{','}','&','@','\'',
        '.',',','?','!','='
    },
    {
        '1','2','3','4','5','6','7','8','9','0',
        '<','>','{','}','[',']','\\','+','=',
        '#','$','%','^','*'
    }
};

static char sp_keys[][26] =
{
    {
        'q','w','e','r','t','y','u','i','o','p',
        'a','s','d','f','g','h','j','k','l',
        'z','x','c','v','b','n','m'
    },
    {
        '1','2','3','4','5','6','7','8','9','0',
        0xe1, 0xe9, 0xed, 0xf3, 0xfa, 0xf1, 0xab,'?','!',
        '.','-','&','@',':'
    },
    {
        '+','_','<','>','(',')','[',']','{','}',
        0xc1, 0xc9, 0xcd, 0xd3, 0xda, 0xd1, 0xbb, 0xbf, 0xa1,
        ';','#','$','%','*'
    }
};

static void shift_cb(WM_MESSAGE * pMsg)
{
    char buf[10];
    GUI_RECT rt;
    WM_GetClientRect(&rt);
    switch (pMsg->MsgId)
    {
    case WM_PAINT:
        if (shift_key)
        {
            GUI_DrawGradientRoundedV(1,1, rt.x1, rt.y1, 6, 0x48866c, 0x63b39b);
            GUI_SetColor(0xdbdbdb);
            GUI_SetPenSize(2);
            GUI_AA_DrawRoundedRect(0,0,rt.x1,rt.y1,10);

            BUTTON_GetText(pMsg->hWin, buf, 10);
            if (strcmp(buf,"back") == 0) return;
            GUI_SetColor(GUI_WHITE);
        }
        else
        {
            GUI_SetColor(0xf2f2f2);
            GUI_AA_FillRoundedRect(2,2,rt.x1-2,rt.y1-2,8);
            GUI_SetColor(0xdbdbdb);
            GUI_SetPenSize(2);
            GUI_AA_DrawRoundedRect(0,0,rt.x1,rt.y1,12);
            BUTTON_GetText(pMsg->hWin, buf, 10);
            GUI_SetColor(0x808080);
        }
        GUI_SetTextMode(GUI_TEXTMODE_TRANS);
        GUI_SetFont(Tahoma23B);
        GUI_DispStringInRect(buf, &rt, GUI_TA_HCENTER | GUI_TA_VCENTER);
        break;
    default:
        BUTTON_Callback(pMsg);
        break;
    }
}

static void keys_cb(WM_MESSAGE * pMsg)
{
    char buf[10];
    GUI_RECT rt;
    int idx;
    WM_GetClientRect(&rt);
    switch (pMsg->MsgId)
    {
    case WM_PAINT:
        idx = BUTTON_IsPressed(pMsg->hWin);
        if (idx)
        {
            GUI_SetColor(0xdbdbdb);
            GUI_SetPenSize(2);
            GUI_AA_DrawRoundedRect(0,0,rt.x1,rt.y1,10);

            BUTTON_GetText(pMsg->hWin, buf, 10);
            GUI_SetColor(GUI_WHITE);
        }
        else
        {
            GUI_SetColor(0xf2f2f2);
            GUI_AA_FillRoundedRect(2,2,rt.x1-2,rt.y1-2,8);
            GUI_SetColor(0xdbdbdb);
            GUI_SetPenSize(2);
            GUI_AA_DrawRoundedRect(0,0,rt.x1,rt.y1,12);
            BUTTON_GetText(pMsg->hWin, buf, 10);
            GUI_SetColor(0x808080);
        }
        if (strcmp(buf,"back") == 0)
        {
            GUI_POINT poly[] =
            {
                {0,25},{15,15},{15,22},{40,22},{40,28},{15,28},{15,35}
            };
            if (idx)
            {
                GUI_SetColor(GUI_WHITE);
                GUI_AA_FillPolygon(poly, 7,10,-10);
            }
            else
            {
                GUI_SetColor(0x808080);
                GUI_AA_FillPolygon(poly, 7,8,-8);
            }
        }
        else
        {
            GUI_SetTextMode(GUI_TEXTMODE_TRANS);
            GUI_SetFont(Tahoma23B);
            GUI_DispStringInRect(buf, &rt, GUI_TA_HCENTER | GUI_TA_VCENTER);
        }
        break;
    default:
        BUTTON_Callback(pMsg);
        break;
    }
}

static void keys_disable_cb(WM_MESSAGE * pMsg)
{
    char buf[10];
    GUI_RECT rt;
    int idx;
    WM_GetClientRect(&rt);
    switch (pMsg->MsgId)
    {
    case WM_PAINT:
        GUI_SetColor(0xf2f2f2);
        GUI_AA_FillRoundedRect(2,2,rt.x1-2,rt.y1-2,8);
        GUI_SetColor(0xdbdbdb);
        GUI_SetPenSize(2);
        GUI_AA_DrawRoundedRect(0,0,rt.x1,rt.y1,12);
        BUTTON_GetText(pMsg->hWin, buf, 10);
        GUI_SetColor(0xdedede);
        GUI_SetTextMode(GUI_TEXTMODE_TRANS);
        GUI_SetFont(Tahoma23B);
        GUI_DispStringInRect(buf, &rt, GUI_TA_HCENTER | GUI_TA_VCENTER);
        break;
    default:
        BUTTON_Callback(pMsg);
        break;
    }
}

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

        hItem = WM_GetDialogItem(pMsg->hWin, ID_TEXT_HEADER);
        TEXT_SetFont(hItem, HEADER_FONT_BOLD);
        TEXT_SetTextAlign(hItem, GUI_TA_HCENTER | GUI_TA_VCENTER);
        TEXT_SetTextColor(hItem, GUI_WHITE);
        strcpy(buf, LANG("EDIT"));
        sprintf(buf, "%s: %s", buf,LANG(edit_title));
        TEXT_SetText(hItem, buf);

        textItem = WM_GetDialogItem(pMsg->hWin, ID_EDIT_TEXT);
        EDIT_SetText(textItem, txt_buffer);
        EDIT_SetFont(textItem, Tahoma23B);
        EDIT_SetTextAlign(textItem, GUI_TA_HCENTER | GUI_TA_VCENTER);
        EDIT_SetBkColor(textItem, 1, 0xf2f2f2);
        EDIT_SetTextColor(textItem, 1, 0x808080);
        WIDGET_SetEffect(textItem, &WIDGET_Effect_None);
        //
        int i, k = 0;
        for (i=ID_BUTTON_0; i <= ID_BUTTON_25; i++)
        {
            hItem = WM_GetDialogItem(pMsg->hWin, i);
            BUTTON_SetTextColor(hItem, 0, GUI_MAKE_COLOR(0x808080));
            if (alpha)
            {
                sprintf(buf, "%c", en_keys[0][k++]);
            }
            else
            {
                sprintf(buf, "%c", en_keys[1][k++]);
            }
            BUTTON_SetText(hItem, buf);
            WM_SetCallback(hItem, keys_cb);
        }

        hItem = WM_GetDialogItem(pMsg->hWin, ID_BUTTON_COM);
        BUTTON_SetTextColor(hItem, 0, GUI_MAKE_COLOR(0x808080));
        WM_SetCallback(hItem, keys_cb);

        if (alpha)
        {
            hItem = WM_GetDialogItem(pMsg->hWin, ID_BUTTON_COM);
            WM_HideWindow(hItem);
        }
        else
        {
            hItem = WM_GetDialogItem(pMsg->hWin, ID_BUTTON_24);
            WM_HideWindow(hItem);
            hItem = WM_GetDialogItem(pMsg->hWin, ID_BUTTON_25);
            WM_HideWindow(hItem);

            hItem = WM_GetDialogItem(pMsg->hWin, ID_BUTTON_COM);
            WM_ShowWindow(hItem);
        }

        hItem = WM_GetDialogItem(pMsg->hWin, ID_BUTTON_SHIFT);
        BUTTON_SetFont(hItem, GUI_FONT_20_1);
        BUTTON_SetTextColor(hItem, BUTTON_CI_DISABLED, GUI_GRAY);
        WM_SetCallback(hItem, shift_cb);
        if (alpha)
        {
            BUTTON_SetText(hItem, LANG("SHIFT"));
        }
        else
        {
            BUTTON_SetText(hItem, LANG("MORE"));
        }
        //
        hItem = WM_GetDialogItem(pMsg->hWin, ID_BUTTON_CANCEL);
        WM_SetCallback(hItem, keys_cb);
        //
        hItem = WM_GetDialogItem(pMsg->hWin, ID_BUTTON_123);
        WM_SetCallback(hItem, keys_cb);
        if (strcmp(edit_title, LANG("Zip Code")) == 0) WM_DisableWindow(hItem);
        //
        hItem = WM_GetDialogItem(pMsg->hWin, ID_BUTTON_ABC);
        WM_SetCallback(hItem, keys_cb);
        WM_HideWindow(hItem);
        if (strcmp(edit_title, LANG("Zip Code")) == 0) WM_DisableWindow(hItem);
        //
        hItem = WM_GetDialogItem(pMsg->hWin, ID_BUTTON_DONE);
        WM_SetCallback(hItem, keys_cb);
        //
        hItem = WM_GetDialogItem(pMsg->hWin, ID_BUTTON_SPACE);
        WM_SetCallback(hItem, keys_cb);
        if (strcmp(edit_title, LANG("Zip Code")) == 0) WM_DisableWindow(hItem);

        hItem = WM_GetDialogItem(pMsg->hWin, ID_BUTTON_ERASE);
        BUTTON_SetText(hItem, "back");
        WM_SetCallback(hItem, keys_cb);

        if (strcmp(edit_title, LANG("Zip Code")) == 0)
        {
            for (i=ID_BUTTON_10; i <= ID_BUTTON_25; i++)
            {
                if (i == ID_BUTTON_10) continue;
                hItem = WM_GetDialogItem(pMsg->hWin, i);
                WM_SetCallback(hItem, keys_disable_cb);
                WM_DisableWindow(hItem);
            }

            hItem = WM_GetDialogItem(pMsg->hWin, ID_BUTTON_SHIFT);
            WM_SetCallback(hItem, keys_disable_cb);
            WM_DisableWindow(hItem);

            hItem = WM_GetDialogItem(pMsg->hWin, ID_BUTTON_123);
            WM_SetCallback(hItem, keys_disable_cb);
            WM_DisableWindow(hItem);

            hItem = WM_GetDialogItem(pMsg->hWin, ID_BUTTON_SPACE);
            WM_SetCallback(hItem, keys_disable_cb);
            WM_DisableWindow(hItem);

            hItem = WM_GetDialogItem(pMsg->hWin, ID_BUTTON_COM);
            WM_SetCallback(hItem, keys_disable_cb);
            WM_DisableWindow(hItem);
        }

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
            case ID_BUTTON_123:
                k = 0;
                for (i=ID_BUTTON_0; i <= ID_BUTTON_25; i++)
                {
                    if (strcmp(language, "english")== 0)
                    {
                        sprintf(buf, "%c", en_keys[1][k++]);
                    }
                    else
                    {
                        sprintf(buf, "%c", sp_keys[1][k++]);
                    }
                    hItem = WM_GetDialogItem(pMsg->hWin, i);
                    BUTTON_SetText(hItem, buf);
                }
                hItem = WM_GetDialogItem(pMsg->hWin, ID_BUTTON_SHIFT);
                BUTTON_SetText(hItem, LANG("MORE"));
                hItem = WM_GetDialogItem(pMsg->hWin, ID_BUTTON_123);
                WM_HideWindow(hItem);
                hItem = WM_GetDialogItem(pMsg->hWin, ID_BUTTON_ABC);
                WM_ShowWindow(hItem);
                hItem = WM_GetDialogItem(pMsg->hWin, ID_BUTTON_COM);
                WM_ShowWindow(hItem);
                break;
            case ID_BUTTON_ABC:
                k = 0;
                for (i=ID_BUTTON_0; i <= ID_BUTTON_25; i++)
                {
                    sprintf(buf, "%c", en_keys[0][k++]);
                    hItem = WM_GetDialogItem(pMsg->hWin, i);
                    BUTTON_SetText(hItem, buf);
                }
                hItem = WM_GetDialogItem(pMsg->hWin, ID_BUTTON_SHIFT);
                BUTTON_SetText(hItem, LANG("SHIFT"));
                hItem = WM_GetDialogItem(pMsg->hWin, ID_BUTTON_ABC);
                WM_HideWindow(hItem);
                hItem = WM_GetDialogItem(pMsg->hWin, ID_BUTTON_123);
                WM_ShowWindow(hItem);
                hItem = WM_GetDialogItem(pMsg->hWin, ID_BUTTON_COM);
                WM_HideWindow(hItem);
                break;
            case ID_BUTTON_CANCEL:
                WM_HideWindow(keyboardWin);
                if (strcmp(from_screen, LANG("Edit Room")) == 0)
                {
                    CreateThermostatLocations();
                }
                else if (strcmp(from_screen, "wifi") == 0)
                {
                    CreateWifiSetup();
                }
                else
                {
                    CreateProfile(-1, txt_buffer);
                }
                break;
            case ID_BUTTON_DONE:
                WM_HideWindow(keyboardWin);
                if (strcmp(from_screen, LANG("Edit Room")) == 0)
                {
                    strcpy(thermo_rooms[room_number], txt_buffer);
                    CreateThermostatLocations();
                }
                else if (strcmp(from_screen, "wifi") == 0)
                {
                    strcpy(myWifiPassword, txt_buffer);
                    CreateWifiSetup();
                }
                else
                {
                    CreateProfile(room_number, txt_buffer);
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
            case ID_BUTTON_SHIFT:
                hItem = WM_GetDialogItem(pMsg->hWin, ID_BUTTON_SHIFT);
                BUTTON_GetText(hItem, buf, sizeof(buf));
                if (strcmp(buf, LANG("MORE")) == 0)
                {
                    k = 0;
                    for (i=ID_BUTTON_0; i <= ID_BUTTON_25; i++)
                    {
                        if (strcmp(language, "english")== 0)
                        {
                            sprintf(buf, "%c", en_keys[key_flag+1][k++]);
                        }
                        else
                        {
                            sprintf(buf, "%c", sp_keys[key_flag+1][k++]);
                        }
                        hItem = WM_GetDialogItem(pMsg->hWin, i);
                        BUTTON_SetText(hItem, buf);
                    }
                    key_flag = !key_flag;
                }
                else
                {
                    for (i=ID_BUTTON_0; i <= ID_BUTTON_25; i++)
                    {
                        hItem = WM_GetDialogItem(pMsg->hWin, i);
                        BUTTON_GetText(hItem, acBuffer, sizeof(acBuffer));
                        if (shift_key == 0)
                        {
                            buf[0] = acBuffer[0]-32;
                        }
                        else
                        {
                            buf[0] = acBuffer[0]+32;
                        }
                        buf[1] = '\0';
                        BUTTON_SetText(hItem, buf );
                    }
                    shift_key = !shift_key;
                    WM_InvalidateWindow(WM_GetDialogItem(pMsg->hWin, ID_BUTTON_SHIFT));
                }
                break;
            default:
                if ((Id >= ID_BUTTON_0 && Id <= ID_BUTTON_25) || Id == ID_BUTTON_COM)
                {
                    BUTTON_GetText(pMsg->hWinSrc, acBuffer, sizeof(acBuffer));
                    hItem = WM_GetDialogItem(pMsg->hWin, ID_EDIT_TEXT);
                    EDIT_GetText(hItem, txt_buffer, 50);
                    len = strlen(txt_buffer);
                    if (len == 50) break;
                    strcat(txt_buffer, acBuffer);
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

WM_HWIN CreateKeyboardWin(int room, char * txt, char * title, char * screen);
WM_HWIN CreateKeyboardWin(int room, char * txt, char * title, char * screen)
{
    strcpy(edit_title, title);
    room_number = room;
    strcpy(txt_buffer, txt);
    strcpy(from_screen, screen);

    key_flag = 1;
    if (strcmp(title, LANG("Zip Code")) == 0)
    {
        alpha = 0;
    }
    else
    {
        alpha = 1;
    }

    keyboardWin = GUI_CreateDialogBox(keyboardDialogCreate, GUI_COUNTOF(keyboardDialogCreate), _cbDialog, WM_HBKWIN, 0, 0);
    return keyboardWin;
}
