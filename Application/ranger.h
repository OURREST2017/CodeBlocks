#ifndef __MAIN_H
#define __MAIN_H

#define CODEBLOCK
#ifndef CODEBLOCK
#include "stm32f4xx_hal.h"
#endif

#include <stdio.h>
#include <string.h>
#include <time.h>
#include <ctype.h>
#include "DIALOG.h"

//#define DEBUG_MODE 1
#define BUTHEIGHT 32
#define HEADER_FONT &GUI_FontTahoma35hAA4
#define HEADER_FONT_BOLD &GUI_FontTahoma35hAA4B

WM_HWIN textDebug;

GUI_TIMER_HANDLE lockTimer_h;
WM_HWIN homeWin, idleWin, screenLockoutWin, dateTimeWin, settingsWin, languagesWin;
WM_HWIN settingsScheduleWin, editScheduleWin, eachDayWin, preferencesWin, systemSetupWin;
WM_HWIN mobilePairWin, profileWin, modeWin, fanModeWin, coolToWin, heatToWin, temperatureLimitsWin;
WM_HWIN alphaKeyboardWin, numericKeyboardWin, settingsHelpWin, wifiPasswordWin;
WM_HWIN hvacModeText, fanModeText, heatToText, coolToText, triacWin;

extern GUI_CONST_STORAGE GUI_BITMAP GUI_FontRounded16;
extern GUI_CONST_STORAGE GUI_FONT GUI_FontRounded22;
extern GUI_CONST_STORAGE GUI_FONT FontBig20B;
extern GUI_CONST_STORAGE GUI_FONT GUI_FontVerdana16hAA4B;
extern GUI_CONST_STORAGE GUI_FONT GUI_FontTahoma129hAA4B;
extern GUI_CONST_STORAGE GUI_FONT GUI_FontTahoma19hAA4B;
extern GUI_CONST_STORAGE GUI_FONT GUI_FontTahoma23hAA4B;
extern GUI_CONST_STORAGE GUI_FONT GUI_FontTahoma29hAA4B;
extern GUI_CONST_STORAGE GUI_FONT GUI_FontTahoma33hAA4;
extern GUI_CONST_STORAGE GUI_FONT GUI_FontTahoma33hAA4B;
extern GUI_CONST_STORAGE GUI_FONT GUI_FontTahoma35hAA4;
extern GUI_CONST_STORAGE GUI_FONT GUI_FontTahoma35hAA4B;
extern GUI_CONST_STORAGE GUI_FONT GUI_FontTahoma87hAA4B;

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
extern int degreesBigSkin(const WIDGET_ITEM_DRAW_INFO * pDrawItemInfo);

extern int color_scheme;
extern void initColors();

extern  WM_HWIN CreateHomeWin(void);
extern  WM_HWIN CreateIdleWin(void);
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
extern  WM_HWIN CreateEachDay();
extern  WM_HWIN CreateSchedulingOptions(void);
extern  WM_HWIN CreateTemperatureScale(void);
extern  WM_HWIN CreateClockFormat(void);
extern  WM_HWIN CreateDaylightSavingsTime(void);
extern  WM_HWIN CreateSystemsChangeOver(void);
extern  WM_HWIN CreateKeyboardLockout(void);
extern  WM_HWIN CreateSchedulePeriods(void);
extern  WM_HWIN CreateNumericKeyboard(int, char *,char *, char *);
extern  WM_HWIN CreateAlphaKeyboard(int, char *, char *,char *);
extern  WM_HWIN CreateEditRoom(int);
extern  WM_HWIN CreateWifiDisconnect(void);
extern  WM_HWIN CreatePassFail(char *);
extern  WM_HWIN CreateTriacPanel(void);
extern  WM_HWIN CreateFanMode(void);
extern  WM_HWIN CreateEditSchedule();
extern  WM_HWIN CreateWifiConnect(void);
extern  WM_HWIN CreateWifiDisonnect(void);
extern  WM_HWIN CreateTemperatureLimits(int);
extern  WM_HWIN CreateMobilePair(void);
extern  WM_HWIN CreateCoolTo(void);
extern  WM_HWIN CreateHeatTo(void);
extern  WM_HWIN CreateEditScheduleHelp(char *,char *);

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
    int temperature;
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

typedef struct colors
{
    GUI_COLOR start;
    GUI_COLOR middle;
    GUI_COLOR stop;
    char * color;
} colors;

struct schedules_s selectedSchedule;
struct colors color_map[3];

int screenLockDig[4];
char schedulePeriod[20];
char scheduleDay[20];
int fan_control;
int heat_control;
int cool_control;
int idleTimeOut;

int tempTimerSet;
int upperDegreeLimit;
int lowerDegreeLimit;

int screenState;
int temperature;
struct schedules_s schedules[5];

int wifi_count;
char myWifiNetwork[50];
char myWifiPassword[20];

char thermo_rooms[6][30];
char changeOver[20];
char configVersion[10];
char serialNumber[30];
char fanControl[30];
char fanMode[10];

char firmwareUrl[10];
int dateTime;
int epochTime;
char  currentScheme[10];
int statControl;
int holdMode;
char hvacMode[10];
char language[12];
int temperatureScale;
char lockCode[5];
char firstNameText[30];
char ownersName[30];
int dst;
char keyboardLock[20];
char currentSchedule[10];
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
int reset;
char *serial;
int tempHold;
int thermoControls;

int current_year;
int current_day;
int current_month;
int current_wday;
int current_dst;

int current_hour;
int current_minute;
int current_ampm;

char  propertyId[50];
char  propertyName[50];

// 1, 4, 6, or 8 periods per day, lets start with 4.
// 12am - 6am, 6am - 12pm, 12pm-6pm, etc.
char  periodStartTime[50];
char  periodEndTime[50];
int hvacFailure;

// Run times are in minutes
int compressorTotalRuntime;
int compressorLongestRuntime;
int compressorShortestRuntime;
int compressorRunCount;
int blowerTotalRuntime;
int blowerLongestRuntime;
int blowerShortestRuntime;
int blowerRunCount;
int tempHighOutside;
int tempLowOutside;
int tempHighInside;
int tempLowInside;
int tempHighSetPoint;
int tempLowSetPoint;
int humidityHighOutside;
int humidityLowOutside;
int humidityHighInside;
int humidityLowInside;

// location
char streetLine1[50];
char streetLine2 [50];
char city[50];
char state[20];
char zip[12];

char firstName[20];
char lastName[30] ;
char email[50];
char phone[20];


#endif
