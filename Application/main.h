#ifndef __MAIN_H
#define __MAIN_H

#include <stdio.h>
#include <string.h>
#include <time.h>
#include <ctype.h>

#include "DIALOG.h"
extern GUI_CONST_STORAGE GUI_BITMAP GUI_FontRounded16;
extern GUI_CONST_STORAGE GUI_FONT GUI_FontRounded22;
extern GUI_CONST_STORAGE GUI_FONT FontBig20B;
extern GUI_CONST_STORAGE GUI_BITMAP bmwatermark;

extern void drawButton16(char *, int, int, int, int);
extern void drawButton(char *, int);
extern void drawProfileButton(char *, int, int, int);
extern void drawButton20(char *, int,int,int,int);
extern void drawButton22(char *, int,int,int,int);
extern void drawButtonOn16(char *, int,int,int);
extern void drawButtonOff16(char *, int,int,int);
extern void drawButtonOn22(char *, int,int,int);
extern void drawButtonOff22(char *, int,int,int);
extern void drawCoolButton(char *, int,int,int,int);

extern GUI_CONST_STORAGE GUI_BITMAP bmup_b;
extern GUI_CONST_STORAGE GUI_BITMAP bmup_nb;
extern GUI_CONST_STORAGE GUI_BITMAP bmdn_b;
extern GUI_CONST_STORAGE GUI_BITMAP bmdn_nb;
extern GUI_CONST_STORAGE GUI_BITMAP bmdn_r;
extern GUI_CONST_STORAGE GUI_BITMAP bmup_r;

extern void return_cb(WM_MESSAGE *);
extern void return_cb(WM_MESSAGE *);
extern void buttonOn16_cb(WM_MESSAGE *);
extern void buttonOff16_cb(WM_MESSAGE *);
extern void buttonOn22_cb(WM_MESSAGE *);
extern void buttonOff22_cb(WM_MESSAGE *);
extern void edit_text_cb(WM_MESSAGE *);
extern void buttonOn20_cb(WM_MESSAGE *);
extern void scheduleButton(WM_MESSAGE * pMsg, char *nm, int on);
extern void buttonPush16_cb(WM_MESSAGE *);
extern void buttonPush22_cb(WM_MESSAGE *);
extern void button22_cb(WM_MESSAGE *);
extern void button20_cb(WM_MESSAGE *);
extern int returnSkin(const WIDGET_ITEM_DRAW_INFO * pDrawItemInfo);

extern int color_scheme;
extern void initColors();

extern  WM_HWIN CreateHomeWin(void);
extern  WM_HWIN CreateMode(void);
extern  WM_HWIN CreateSettings(void);
extern  WM_HWIN CreateFanControl(void);
extern  WM_HWIN CreateSchedule(void);
extern  WM_HWIN CreateColors(void);
extern  WM_HWIN CreateDateTime(void);
extern  WM_HWIN CreateScreenLockout(void);
extern  WM_HWIN CreateSettingsSchedule(void);
extern  WM_HWIN CreateLanguages(void);
extern  WM_HWIN CreateProfile(int, char *);
extern  WM_HWIN CreatePreferences(void);
extern  WM_HWIN CreateSystemSetup(void);
extern  WM_HWIN CreateThermostatLocations(void);
extern  WM_HWIN CreateHvacType(void);
extern  WM_HWIN CreateThermostatControls(void);
extern  WM_HWIN CreateFanControl(void);
extern  WM_HWIN CreateWifiSetup(void);
extern  WM_HWIN CreateBackupHeat(void);
extern  WM_HWIN CreateCoolingStages(void);
extern  WM_HWIN CreateHeatingStages(void);
extern  WM_HWIN CreateEachDay(void);
extern  WM_HWIN CreateSchedulingOptions(void);
extern  WM_HWIN CreateTempuratureScale(void);
extern  WM_HWIN CreateClockFormat(void);
extern  WM_HWIN CreateDaylightSavingTime(void);
extern  WM_HWIN CreateSystemsChangeOver(void);
extern  WM_HWIN CreateKeyboardLockout(void);
extern  WM_HWIN CreateSchedulePeriods(void);
extern  WM_HWIN CreateNumericKeyboard(int, char *,char *, char *);
extern  WM_HWIN CreateAlphaKeyboard(int, char *, char *,char *);
extern  WM_HWIN CreateEditRoom(int);
extern  WM_HWIN CreateWifiDisconnect(void);
extern  WM_HWIN CreatePassFail(char *);
extern  WM_HWIN CreateTriacPanelWin(void);
extern  WM_HWIN CreateFanMode(void);
extern  WM_HWIN CreateEditSchedule(char *);
extern  WM_HWIN CreateWifiConnect(void);
extern  WM_HWIN CreateTempuratureLimits(void);
extern  WM_HWIN CreateMobilePair();

extern void loadConfig();
char * updateTime(char *tm, int dr);

typedef struct
{
    WM_HWIN           hWin;
    GUI_MEMDEV_Handle hMemOverlay;
    GUI_MEMDEV_Handle hMemRBorder;
    GUI_MEMDEV_Handle hMemLBorder;
    const GUI_FONT GUI_UNI_PTR * pFont;
} WHEEL;


typedef struct periods_s
{
    int tempurature;
    char *label;
    char *startTime;
    char *stopTime;
    int startMinutes;
    int stopMinutes;
} periods_s;

typedef struct days_s
{
    struct periods_s periods[4];
    char *label;
} days_s;

typedef struct schedules_s
{
    struct days_s days[7];
    char *label;
    int systemDefined;
    int day_count;

} schedules_s;

typedef struct hvacConfig_s
{
    char *hvacType;
    char *backupHeatingType;
    int coolingStages;
    int heatingStages;
} hvacConfig_s;

int tempTimerSet;
int upperDegreeLimit;
int lowerDegreeLimit;

int state;
int temperature;
struct schedules_s schedules[5];

//char ** wifi_networks;
int wifi_count;
char myWifiNetwork[50];
char myWifiPassword[20];

char thermo_rooms[6][30];
char changeOver[20];
char configVersion[10];
char serialNumber[30];
char fanControl[30];
char firmwareUrl[10];
int dateTime;
int epochTime;
char  currentScheme[10];
int statControl;
int holdMode;
char selectedFanMode[5];
char hvacMode[10];
char language[12];
int tempuratureScale;
char lockCode[5];
char firstNameText[30];
char ownersName[30];
int dst;
char keyboardLock[20];
char selectedSchedule[10];
char *currFwVersion;
int enableSchedule;
int filterChangeDate;
int filterLifeInDays;
int firstTime;
int localHumidity;
int localTemp;
char *nextFwVersion;
char *securityMode;
int tempSetPoint;
int timeZoneOffset;
int unitLocked;
int resetUnit;
int insideHumidity;

int heatToDegrees;
int coolToDegrees;
char schedulingOption[30];
int clockFormat;
char systemsChangeOver[20];
int schedulePeriods;
int thermostatControls;
char zipCode[12];
int metric;
int backupHeat;
char hvacType[20];
int coolingStages;
int heatingStages;
char backupHeatingType[10];

int testing;
int insideTemp;

int current_year;
int current_day;
int current_month;
int current_wday;
int current_dst;

int current_hour;
int current_minute;
int current_ampm;



#endif
