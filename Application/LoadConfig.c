#include "main.h"
#include <time.h>

void loadConfig() {
    time_t rawtime;
    struct tm *info;

    serialNumber = "12345";
    dateTime =  101010101;
    currentScheme = "blue";
    statControl = 72;
    holdMode = 0;
    strcpy(selectedFanMode, "auto");
    strcpy(selectedMode, "auto");
    strcpy(language, "english");
    tempuratureScale = 1;
    strcpy(lockCode, "1234");
    strcpy(firstNameText, "Clyde");
    dst = 1;
    strcpy(keyboardLockout, "unlocked");
    selectedSchedule = "all days";
    currFwVersion = "0001";
    enableSchedule = 1;
    filterChangeDate = 0;
    filterLifeInDays = 0;
    localHumidity = 99;
    localTemp = 95;
    nextFwVersion = "1.2.4";
    securityMode = "high";
    tempSetPoint = 75;
    timeZoneOffset = -5;
    unitLocked = 1;
    resetUnit = 1;
    backupHeat = 1;
    coolingStages = 1;
    heatingStages = 1;

    insideHumidity = 30;
    insideTemp = 72;
    statControl = 72;
    heatToDegrees = 75;
    coolToDegrees = 72;
    strcpy(schedulingOption, "programmable");
    clockFormat = 24;
    strcpy(systemsChangeOver,"automatic");
    schedulePeriods = 4;
    strcpy(fanControl, "thermostat");
    thermostatControls = 3;
    strcpy(zipCode, "12345");
    metric = 0;
    strcpy(systemType, "heat pump");

    time( &rawtime );
    info = localtime( &rawtime );

    current_year = info->tm_year + 1900;
    current_day = info->tm_mday;
    current_month = info->tm_mon;
    current_wday = info->tm_wday;
    current_dst = info->tm_isdst;

    current_hour = info->tm_hour;
    current_minute = info->tm_min;
    current_ampm = (info->tm_hour <= 12) ? 0 : 1;


}
