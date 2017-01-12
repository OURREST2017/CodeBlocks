#ifndef __MAIN_H
#define __MAIN_H

#include <stdio.h>
#include <string.h>
#include "DIALOG.h"

extern GUI_CONST_STORAGE GUI_BITMAP GUI_FontRounded16;
extern GUI_CONST_STORAGE GUI_FONT GUI_FontRounded22;
extern GUI_CONST_STORAGE GUI_FONT FontBig20B;

extern void drawButton16(char *, int, int, int);
extern void drawButton(char *, int);
extern void drawProfileButton(char *, int, int, int);

extern void return_cb(WM_MESSAGE *);
extern void small_up_button(WM_MESSAGE *);
extern void small_dn_button(WM_MESSAGE *);
extern void big_up_button(WM_MESSAGE *);
extern void big_dn_button(WM_MESSAGE *);
extern void buttonOn16_cb(WM_MESSAGE *);
extern void buttonOff16_cb(WM_MESSAGE *);
extern void buttonOn22_cb(WM_MESSAGE *);
extern void buttonOff22_cb(WM_MESSAGE *);
extern void edit_text_cb(WM_MESSAGE *);
extern void buttonOn20_cb(WM_MESSAGE *);
extern GUI_CONST_STORAGE GUI_BITMAP bmwatermark;

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
extern  WM_HWIN CreateSystemType(void);
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
extern  WM_HWIN CreateWifiDisconnect();
extern  WM_HWIN CreatePassFail(char *);

typedef int uint8_t;
typedef int uint16_t;
typedef int uint32_t;

typedef struct periods_s
{
    int tempurature;
    char *label;
    char *startTime;
    char *stopTime;
} periods_s;

typedef struct days_s
{
    struct periods_s periods[4];
    char *label;
} days_s;

typedef struct schedules
{
    struct days_s days[7];
    char *label;
    int systemDefined;
} schedules;

typedef struct hvacConfig
{
    char *hvacType;
    char *backupHeatingType;
    int coolingStages;
    int heatingStages;
} hvacConfig;

int state;
int temperature;

char thermo_rooms[6][30];
char myWifiNetwork[50];
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
char systemType[20];
int coolingStages;
int heatingStages;

int testing;

int insideTemp;
int statControl;

int current_year;
int current_day;
int current_month;
int current_wday;
int current_dst;

int current_hour;
int current_minute;
int current_ampm;



#endif
