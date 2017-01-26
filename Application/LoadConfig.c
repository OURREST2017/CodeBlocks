#include "main.h"
#include <stdlib.h>
#include <time.h>
#include "cJSON.h"

static cJSON *config_root;

char * toup(char *s)
{
    int i;
    char *t;
    static char o[100];
    for (i=0; i<strlen(s); i++)
    {
        o[i] = toupper(s[i]);
    }
    o[i] = '\0';
    return o;
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
    time_t rawtime;
    struct tm *info;

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
        dst = getBoolObject(config_root,"dst");
        enableSchedule = getBoolObject(config_root,"enableSchedule");
        epochTime = getIntObject(config_root,"epochTime");

        strcpy(fanControl, getStringObject(config_root,"fanControl"));
        strcpy(firstNameText, getStringObject(config_root,"firstNameText"));
        strcpy(selectedFanMode, getStringObject(config_root,"fanMode"));
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
        strcpy(selectedSchedule, getStringObject(config_root,"selectedSchedule"));
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
            printf("schedules.label=%s\n", schedules[i].label);
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

    insideHumidity = 30;
    insideTemp = 72;
    upperDegreeLimit = 82;
    lowerDegreeLimit = 70;

    strcpy(myWifiNetwork, "My Wifi Network");
    strcpy(thermo_rooms[0], "Living Room");
    strcpy(thermo_rooms[1], "Master Bedroom");
    strcpy(thermo_rooms[2], "Office");
    strcpy(thermo_rooms[3], "Room 4");
    strcpy(thermo_rooms[4], "Room 5");
    strcpy(thermo_rooms[5], "Room 6");

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

void saveConfig()
{
    FILE *f;
    char *out;

    if ((f = fopen("config_def1.json", "w")) != 0)
    {
        out = cJSON_Print(config_root);
        fputs(out, f);
        free(out);

        fclose(f);
    }
}
