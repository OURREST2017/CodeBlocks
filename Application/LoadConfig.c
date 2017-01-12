#include "main.h"
#include <time.h>
#include "cJSON.h"

int getIntObject(cJSON *j, char * o)
{
    cJSON *cj = cJSON_GetObjectItem(j,o);
    if (cj == NULL)
    {
        return 0;
    }
    else
    {
        return cj->valueint;
    }
}

int getBoolObject(cJSON *j, char * o)
{
    cJSON *cj = cJSON_GetObjectItem(j,o);
    if (cj == NULL)
    {
        return 0;
    }
    else
    {
        return cj->valueint;
    }
}

char * getStringObject(cJSON *j, char * o)
{
    cJSON *cj = cJSON_GetObjectItem(j,o);
    if (cj == NULL)
    {
        return "";
    }
    else
    {
        return cj->valuestring;
    }
}

void loadConfig()
{
    time_t rawtime;
    struct tm *info;

    FILE *f;
    long len;
    char *data;

    f=fopen("config_def.json","rb");
    fseek(f,0,SEEK_END);
    len=ftell(f);
    fseek(f,0,SEEK_SET);
    data=(char*)malloc(len+1);
    fread(data,1,len,f);
    fclose(f);

    cJSON *config_root = cJSON_Parse(data);

    strcpy(myWifiNetwork, "My Wifi Network");
    strcpy(thermo_rooms[0], "Living Room");
    strcpy(thermo_rooms[1], "Master Bedroom");
    strcpy(thermo_rooms[2], "Office");
    strcpy(thermo_rooms[3], "Room 4");
    strcpy(thermo_rooms[4], "Room 5");
    strcpy(thermo_rooms[5], "Room 6");

    dateTime =  101010101;

    strcpy(changeOver, getStringObject(config_root,"changeOver"));
    clockFormat = getIntObject(config_root,"clockFormat");
    strcpy(configVersion, getStringObject(config_root,"configVersion"));
    coolToDegrees = getIntObject(config_root,"coolToDegrees");
     currFwVersion = getStringObject(config_root,"currFwVersion");
    dst = getBoolObject(config_root,"dst");
    enableSchedule = getBoolObject(config_root,"enableSchedule");
    epochTime = getIntObject(config_root,"epochTime");
    strcpy(fanControl, cJSON_GetObjectItem(config_root,"fanControl"));
    strcpy(firstNameText, getStringObject(config_root,"firstNameText"));
    strcpy(selectedFanMode, getStringObject(config_root,"fanMode"));
    filterChangeDate = getIntObject(config_root,"filterChangeDate");
    filterLifeInDays = getIntObject(config_root,"filterLifeInDays");
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
    strcpy(selectedSchedule, getStringObject(config_root,"selectedSchedule"));
    schedulePeriods = getIntObject(config_root,"schedulePeriods");
    strcpy(schedulingOption, getStringObject(config_root,"schedulingOption"));
    securityMode = getStringObject(config_root,"securityMode");

    strcpy(serialNumber, getStringObject(config_root,"serial"));
    holdMode = getBoolObject(config_root,"tempHold");
    strcpy(currentScheme, getStringObject(config_root,"themeScheme"));
    thermostatControls = getIntObject(config_root,"thermostatControls");
    tempSetPoint = getIntObject(config_root,"tempSetPoint");
    timeZoneOffset = getIntObject(config_root,"timeZoneOffset");
    unitLocked = getBoolObject(config_root,"unitLocked");
    strcpy(zipCode, getStringObject(config_root,"zipCode"));
    testing = getBoolObject(config_root,"testing");

    backupHeat = 1;
    coolingStages = 1;
    heatingStages = 1;
    //strcpy(systemType, getStringObject(config_root,"systemType"));

    insideHumidity = 30;
    insideTemp = 72;


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

    struct schedules scheds[5];
    struct days_s days;
    struct periods_s periods;

    cJSON *schedules_a = cJSON_GetObjectItem(config_root,"schedules");

    int i, j, k;
    for (i=0; i<cJSON_GetArraySize(schedules_a); i++)
    {
        cJSON *schedules = cJSON_GetArrayItem(schedules_a, i);
        scheds[i].label  = cJSON_GetObjectItem(schedules,"label")->valuestring;
        printf("schedules.label=%s\n", scheds[i].label);
        scheds[i].systemDefined = cJSON_GetObjectItem(schedules,"systemDefined")->valueint;
        cJSON *days_a = cJSON_GetObjectItem(schedules,"days");
        for (k=0; k<cJSON_GetArraySize(days_a); k++)
        {
            cJSON *d = cJSON_GetArrayItem(days_a, k);
            days.label = cJSON_GetObjectItem(d,"label")->valuestring;
            printf("  days.label=%s\n", days.label);

            cJSON *periods_a = cJSON_GetObjectItem(d,"periods");
            for (j=0; j<4; j++)
            {
                cJSON *p = cJSON_GetArrayItem(periods_a, j);
                periods.tempurature = cJSON_GetObjectItem(p,"tempurature")->valueint;
                periods.label = cJSON_GetObjectItem(p,"label")->valuestring;
                periods.startTime = cJSON_GetObjectItem(p,"startTime")->valuestring;
                periods.stopTime = cJSON_GetObjectItem(p,"stopTime")->valuestring;
                //printf("    periods.label=%s\n",  periods.label);
                days.periods[j] = periods;
            }
            scheds[i].days[k] = days;
            printf("\n");
        }
    }

    free(data);
}
