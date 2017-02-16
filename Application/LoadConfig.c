#include "ranger.h"
#include <stdlib.h>
#include <time.h>
#include "cJSON.h"

static cJSON *config_root;

char * toup(char *s)
{
    int i;
    static char o[100];
    for (i=0; i<strlen(s); i++)
    {
        o[i] = toupper(s[i]);
    }
    o[i] = '\0';
    return o;
}

char * tolow(char *s)
{
    int i;
    static char o[100];
    for (i=0; i<strlen(s); i++)
    {
        o[i] = tolower(s[i]);
    }
    o[i] = '\0';
    return o;
}

int  scheduleTempurature(char * tm, char *day)
{
    int i,k;
    int hh, mm, startMinutes, stopMinutes;
    struct days_s selectedDay;

    sscanf(tm, "%d:%d", &hh, &mm);
    if (strchr(tm, 'a') == NULL)  hh += 12;
    int st = hh*60+mm;

    for (k=0; k<selectedSchedule.day_count; k++)
    {
        if (strcmp(selectedSchedule.days[k].label, day) != 0) continue;
        selectedDay = selectedSchedule.days[k];

        for (i=0; i<4; i++)
        {
            sscanf(selectedDay.periods[i].startTime, "%d:%d", &hh, &mm);
            if (strchr(selectedDay.periods[i].startTime, 'a') == NULL)  hh += 12;
            startMinutes = hh*60+mm;
            sscanf(selectedDay.periods[i].stopTime, "%d:%d", &hh, &mm);
            if (strchr(selectedDay.periods[i].stopTime, 'a') == NULL) hh += 12;
            stopMinutes = hh*60+mm;
            if (stopMinutes < startMinutes)
            {
                if (st < stopMinutes || st >= startMinutes)
                {
                    return selectedDay.periods[i].tempurature;
                }
            }
            else
            {
                if (st >= startMinutes && st <= stopMinutes)
                {
                    return selectedDay.periods[i].tempurature;
                }
            }
        }
    }
    return 78;
}


int getIntObject(cJSON *j, char * o)
{
    cJSON *cj = cJSON_GetObjectItem(j,o);
    return (cj == NULL) ? 0 : cj->valueint;
}

int getBoolObject(cJSON *j, char * o)
{
    cJSON *cj = cJSON_GetObjectItem(j,o);
    return (cj == NULL) ? 0 : cj->valueint;
}

char * getStringObject(cJSON *j, char * o)
{
    cJSON *cj = cJSON_GetObjectItem(j,o);
    return (cj == NULL) ? "" : cj->valuestring;
}

void loadConfig()
{
    FILE *f;
    long len;
    char *data;

    struct days_s days;
    struct periods_s periods;
    struct hvacConfig_s hvacConfig;

    if ((f = fopen("config_def.json", "rb")) != 0)
    {
        fseek(f, 0, SEEK_END);
        len = ftell(f);
        fseek(f, 0, SEEK_SET);
        data=(char*)malloc(len+1);
        fread(data, 1, len, f);
        fclose(f);

        config_root = cJSON_Parse(data);

        dateTime =  101010101;

        strcpy(changeOver, getStringObject(config_root,"changeOver"));
        clockFormat = getIntObject(config_root,"clockFormat");
        strcpy(configVersion, getStringObject(config_root,"configVersion"));
        coolToDegrees = getIntObject(config_root,"coolToDegrees");
        currFwVersion = getStringObject(config_root,"currFwVersion");
        strcpy(currentSchedule, getStringObject(config_root,"currentSchedule"));
        dst = getBoolObject(config_root,"dst");
        enableSchedule = getBoolObject(config_root,"enableSchedule");
        epochTime = getIntObject(config_root,"epochTime");
        strcpy(fanControl, getStringObject(config_root,"fanControl"));
        strcpy(firstNameText, getStringObject(config_root,"firstNameText"));
        strcpy(fanMode, getStringObject(config_root,"fanMode"));
        filterChangeDate = getIntObject(config_root,"filterChangeDate");
        filterLifeInDays = getIntObject(config_root,"filterLifeInDays");
        firstTime = getBoolObject(config_root,"firstTime");
        strcpy(firmwareUrl, getStringObject(config_root,"firmwareUrl"));
        heatToDegrees = getIntObject(config_root,"heatToDegrees");
        strcpy(hvacMode, getStringObject(config_root,"hvacMode"));
        strcpy(keyboardLock, getStringObject(config_root,"keyboardLock"));
        strcpy(language,  getStringObject(config_root,"language"));
        localHumidity = getIntObject(config_root,"localHumidity");

        localTemp = getIntObject(config_root,"localTemp");
        strcpy(lockCode, getStringObject(config_root,"lockCode"));
        tempuratureScale = getIntObject(config_root,"metric");
        metric = getBoolObject(config_root,"metric");
        nextFwVersion = getStringObject(config_root,"nextFwVersion");
        strcpy(ownersName,  getStringObject(config_root,"ownersName"));
        resetUnit = getIntObject(config_root,"reset");
        schedulePeriods = getIntObject(config_root,"schedulePeriods");
        strcpy(schedulingOption, getStringObject(config_root,"schedulingOption"));
        securityMode = getStringObject(config_root,"securityMode");

        strcpy(serialNumber, getStringObject(config_root,"serial"));
        holdMode = getBoolObject(config_root,"tempHold");
        strcpy(currentScheme, getStringObject(config_root,"themeScheme"));
        thermostatControls = getIntObject(config_root,"thermoControls");
        tempSetPoint = getIntObject(config_root,"tempSetPoint");
        timeZoneOffset = getIntObject(config_root,"timeZoneOffset");
        unitLocked = getBoolObject(config_root,"unitLocked");
        strcpy(zipCode, getStringObject(config_root,"zipCode"));
        testing = getBoolObject(config_root,"testing");

        strcpy(myWifiNetwork, getStringObject(config_root,"myWifiNetwork"));

        strcpy(thermo_rooms[0], getStringObject(config_root,"thermo1"));
        strcpy(thermo_rooms[1], getStringObject(config_root,"thermo2"));
        strcpy(thermo_rooms[2], getStringObject(config_root,"thermo3"));
        strcpy(thermo_rooms[3], getStringObject(config_root,"thermo4"));
        strcpy(thermo_rooms[4], getStringObject(config_root,"thermo5"));
        strcpy(thermo_rooms[5], getStringObject(config_root,"thermo6"));

        cJSON *hvac = cJSON_GetObjectItem(config_root,"hvacConfig");

        hvacConfig.backupHeatingType = cJSON_GetObjectItem(hvac, "backupHeatingType")->valuestring;
        hvacConfig.hvacType = cJSON_GetObjectItem(hvac, "hvacType")->valuestring;
        hvacConfig.coolingStages = cJSON_GetObjectItem(hvac, "coolingStages")->valueint;
        hvacConfig.heatingStages = cJSON_GetObjectItem(hvac, "heatingStages")->valueint;

        strcpy(hvacType, hvacConfig.hvacType);
        coolingStages = hvacConfig.coolingStages;
        heatingStages = hvacConfig.heatingStages;
        strcpy(backupHeatingType, hvacConfig.backupHeatingType);

        cJSON *schedules_a = cJSON_GetObjectItem(config_root,"schedules");
        int i, j, k;
        for (i=0; i<cJSON_GetArraySize(schedules_a); i++)
        {
            cJSON *schedules_obj = cJSON_GetArrayItem(schedules_a, i);
            schedules[i].label  = cJSON_GetObjectItem(schedules_obj,"label")->valuestring;
            schedules[i].systemDefined = cJSON_GetObjectItem(schedules_obj,"systemDefined")->valueint;
            cJSON *days_a = cJSON_GetObjectItem(schedules_obj,"days");
            for (k=0; k<cJSON_GetArraySize(days_a); k++)
            {
                cJSON *d = cJSON_GetArrayItem(days_a, k);
                days.label = cJSON_GetObjectItem(d,"label")->valuestring;
                cJSON *periods_a = cJSON_GetObjectItem(d,"periods");
                for (j=0; j<4; j++)
                {
                    cJSON *p = cJSON_GetArrayItem(periods_a, j);
                    periods.tempurature = cJSON_GetObjectItem(p,"tempurature")->valueint;
                    periods.label = cJSON_GetObjectItem(p,"label")->valuestring;
                    periods.startTime = cJSON_GetObjectItem(p,"startTime")->valuestring;
                    periods.stopTime = cJSON_GetObjectItem(p,"stopTime")->valuestring;

                    int hh, mm;
                    sscanf(periods.startTime, "%d:%d", &hh, &mm);
                    if (strchr(periods.startTime, 'a') == NULL)  hh += 12;
                    periods.startMinutes = hh*60+mm;
                    sscanf(periods.stopTime, "%d:%d", &hh, &mm);
                    if (strchr(periods.stopTime, 'a') == NULL) hh += 12;
                    periods.stopMinutes = hh*60+mm;
                    days.periods[j] = periods;
                }
                schedules[i].days[k] = days;
            }
            schedules[i].day_count = k;
        }
        free(data);
    }
    else
    {
        strcpy(changeOver, "automatic");
        clockFormat = 12;
        strcpy(configVersion, "1.0.0");
        coolToDegrees = 72;
        currFwVersion = "1.0.0";
        dst = 1;;
        enableSchedule = 0;
        epochTime = 0;

        strcpy(fanControl, "thermostat");
        strcpy(firstNameText, "Frank");
        strcpy(fanMode, "auto");
        filterChangeDate = 0;
        filterLifeInDays = 0;
        firstTime = 0;
        strcpy(firmwareUrl, "0");
        heatToDegrees = 78;
        holdMode = 0;
        strcpy(hvacMode, "cool");
        strcpy(keyboardLock, "unlocked");
        strcpy(language,  "english");
        localHumidity = 90;

        localTemp = 72;
        strcpy(lockCode, "0000");
        tempuratureScale = 0;
        metric = 0;
        nextFwVersion = "1.0.0";
        strcpy(ownersName, "Frank");
        resetUnit = 0;
        strcpy(currentSchedule, "all days");
        schedulePeriods = 2;
        strcpy(schedulingOption, "programmable");
        securityMode = "high";

        strcpy(serialNumber, "1234567890");
        thermostatControls = 3;
        tempSetPoint = 72;
        timeZoneOffset = -5;
        unitLocked = 1;
        strcpy(zipCode, "12345");
        testing = 0;

        struct hvacConfig_s hvacConfig;
        hvacConfig.backupHeatingType = "no";
        hvacConfig.hvacType = "air";
        hvacConfig.coolingStages = 2;
        hvacConfig.heatingStages = 1;

        strcpy(hvacType, hvacConfig.hvacType);
        coolingStages = hvacConfig.coolingStages;
        heatingStages = hvacConfig.heatingStages;
        strcpy(backupHeatingType, hvacConfig.backupHeatingType);

        strcpy(myWifiNetwork, "My Wifi Network");
        strcpy(thermo_rooms[0], "Living Room");
        strcpy(thermo_rooms[1], "Master Bedroom");
        strcpy(thermo_rooms[2], "Office");
        strcpy(thermo_rooms[3], "Room 4");
        strcpy(thermo_rooms[4], "Room 5");
        strcpy(thermo_rooms[5], "Room 6");

        char *scheds[] = {"vacation", "weekday", "weekend", "all days", "each day"};

        int hh, mm;
        int i;
        for (i=0; i<4; i++)
        {
            schedules[i].label = scheds[i];
            schedules[i].systemDefined = 1;

            schedules[i].days[0].label = scheds[i];

            schedules[i].days[0].periods[0].label = "wake";
            schedules[i].days[0].periods[0].startTime = "6:00am";
            schedules[i].days[0].periods[0].stopTime = "8:00am";
            schedules[i].days[0].periods[0].tempurature = 72;
            schedules[i].days[0].periods[0].startMinutes = 360;
            schedules[i].days[0].periods[0].stopMinutes = 480;

            schedules[i].days[0].periods[1].label = "leave";
            schedules[i].days[0].periods[1].startTime = "8:00am";
            schedules[i].days[0].periods[1].stopTime = "5:00pm";
            schedules[i].days[0].periods[1].tempurature = 80;
            schedules[i].days[0].periods[1].startMinutes = 480;
            schedules[i].days[0].periods[1].stopMinutes = 1020;

            schedules[i].days[0].periods[2].label = "return";
            schedules[i].days[0].periods[2].startTime = "5:00pm";
            schedules[i].days[0].periods[2].stopTime = "10:00pm";
            schedules[i].days[0].periods[2].tempurature = 72;
            schedules[i].days[0].periods[2].startMinutes = 1020;
            schedules[i].days[0].periods[2].stopMinutes = 1200;

            schedules[i].days[0].periods[3].label = "sleep";
            schedules[i].days[0].periods[3].startTime = "10:00pm";
            schedules[i].days[0].periods[3].stopTime = "6:00am";
            schedules[i].days[0].periods[3].tempurature = 78;
            schedules[i].days[0].periods[3].startMinutes = 1200;
            schedules[i].days[0].periods[3].stopMinutes = 360;

            schedules[i].day_count = 1;
        }

        char *dow[] = {"monday", "tuesday", "wednesday",
                       "thursday", "friday", "saturday", "sunday"};

        schedules[i].label = scheds[i];
        schedules[i].systemDefined = 1;
        schedules[i].day_count = 7;

        int k;
        for (k=0; k<7; k++)
        {
            schedules[i].days[k].label = dow[k];

            schedules[i].days[k].periods[0].label = "wake";
            schedules[i].days[k].periods[0].startTime = "6:00am";
            schedules[i].days[k].periods[0].stopTime = "8:00am";
            schedules[i].days[k].periods[0].tempurature = 72;
            schedules[i].days[k].periods[0].startMinutes = 360;
            schedules[i].days[k].periods[0].stopMinutes = 480;

            schedules[i].days[k].periods[1].label = "leave";
            schedules[i].days[k].periods[1].startTime = "8:00am";
            schedules[i].days[k].periods[1].stopTime = "5:00pm";
            schedules[i].days[k].periods[1].tempurature = 80;
            schedules[i].days[k].periods[1].startMinutes = 480;
            schedules[i].days[k].periods[1].stopMinutes = 1020;

            schedules[i].days[k].periods[2].label = "return";
            schedules[i].days[k].periods[2].startTime = "5:00pm";
            schedules[i].days[k].periods[2].stopTime = "10:00pm";
            schedules[i].days[k].periods[2].tempurature = 72;
            schedules[i].days[k].periods[2].startMinutes = 1020;
            schedules[i].days[k].periods[2].stopMinutes = 1200;

            schedules[i].days[k].periods[3].label = "sleep";
            schedules[i].days[k].periods[3].startTime = "10:00pm";
            schedules[i].days[k].periods[3].stopTime = "6:00am";
            schedules[i].days[k].periods[3].tempurature = 78;
            schedules[i].days[k].periods[3].startMinutes = 1200;
            schedules[i].days[k].periods[3].stopMinutes = 360;
        }
    }

    insideHumidity = 30;
    insideTemp = 72;
    upperDegreeLimit = 82;
    lowerDegreeLimit = 70;
    idleTimeOut = 360000;

    int i;
    for (i=0; i<5; i++)
    {
        if (strcmp(schedules[i].label, currentSchedule) == 0)
        {
            selectedSchedule = schedules[i];
            break;
        }
    }

#ifdef CODEBLOCK
    time_t rawtime;
    struct tm *info;

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
#else
    RTC_TimeTypeDef tm;
    RTC_DateTypeDef dt;

    BSP_RTC_GetTime(&tm);
    BSP_RTC_GetDate(&dt);

    current_year = dt.Year + 2000;
    current_day =  dt.Date;
    current_month = dt.Month;
    current_wday = dt.WeekDay;
    //current_dst = dt.daylight;

    current_hour = tm.Hours;
    current_minute = tm.Minutes;
    //current_ampm = (tm.Hour <= 12) ? 0 : 1;
#endif

//        struct tm my_time = { .tm_year=112, // = year 2012
//                          .tm_mon=9,    // = 10th month
//                          .tm_mday=9,   // = 9th day
//                          .tm_hour=8,   // = 8 hours
//                          .tm_min=10,   // = 10 minutes
//                          .tm_sec=20    // = 20 secs
//    };
//
//    char t[50];
//    strftime(t, 50, "%A %c", &my_time);

//    int far = 20 * 1.8 + 32;
//    int cel = (72 - 32) / 1.8;


}
