#ifndef __MAIN_H
#define __MAIN_H

#include <stdio.h>
#include <string.h>
#include "DIALOG.h"

extern GUI_CONST_STORAGE GUI_BITMAP GUI_FontRounded16;
extern GUI_CONST_STORAGE GUI_FONT GUI_FontRounded22;
extern GUI_CONST_STORAGE GUI_BITMAP bmup;
extern GUI_CONST_STORAGE GUI_BITMAP bmupt;

extern void drawButton16(char *, int, int, int);
extern void drawButton(char *, int);
extern void drawProfileButton(char *, int, int, int);
extern void cancel_cb(WM_MESSAGE *);
extern void done_cb(WM_MESSAGE *);
extern void save_cb(WM_MESSAGE *);

extern int color_scheme;
extern void initColors();

typedef int uint8_t;
typedef int uint16_t;
typedef int uint32_t;

int state;
int temperature;

char *serialNumber;
int dateTime;
char *currentScheme;
int statControl;
int holdMode;
char selectedFanMode[5];
char selectedMode[10];
char language[12];
int tempuratureScale;
char lockCode[5];
char firstNameText[30];
int dst;
char keyboardLockout[20];
char *selectedSchedule;
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
char fanControl[15];
int thermostatControls;
char zipCode[12];
int metric;
int backupHeat;
char systemType[20];
int coolingStages;
int heatingStages;

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
