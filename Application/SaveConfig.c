#include "ranger.h"
#include <stdlib.h>

void writeString(char *s, char *x, char *c, FILE *f)
{
    char buf[100];
    sprintf(buf, "\"%s\": \"%s\"%s\n", s, x, c);
    fputs(buf, f);
}

void writeInt(char *s, int x, char *c, FILE *f)
{
    char buf[100];
    sprintf(buf, "\"%s\": %d%s\n", s, x, c);
    fputs(buf, f);
}

void writeBool(char *s, int x, char *c, FILE *f)
{
    char buf[100];
    sprintf(buf, "\"%s\": %s%s\n", s, (x ? "true" : "false"), c);
    fputs(buf, f);
}

void saveStats() {
   FILE *f;

   if ((f = fopen("stats.json", "w")) == 0)
    {
        return;
    }

    fputs("{\n", f);
    writeInt("compressorTotalRuntime", compressorTotalRuntime, ",", f);
    writeInt("compressorLongestRuntime", compressorLongestRuntime, ",", f);
    writeInt("compressorShortestRuntime", compressorShortestRuntime, ",", f);
    writeInt("compressorRunCount", compressorRunCount, ",", f);

    writeInt("blowerTotalRuntime", blowerTotalRuntime, ",", f);
    writeInt("blowerLongestRuntime", blowerLongestRuntime, ",", f);
    writeInt("blowerShortestRuntime", blowerShortestRuntime, ",", f);
    writeInt("blowerRunCount", blowerRunCount, ",", f);

    writeInt("tempHighOutside", tempHighOutside, ",", f);
    writeInt("tempLowOutside", tempLowOutside, ",", f);
    writeInt("tempLowSetPoint", tempLowSetPoint, ",", f);

    writeInt("humidityHighOutside", humidityHighOutside, ",", f);
    writeInt("humidityLowOutside", humidityLowOutside, ",", f);
    writeInt("humidityHighInside", humidityHighInside, ",", f);
    writeInt("humidityLowInside", humidityLowInside, "", f);

    fputs("}\n", f);
    fclose(f);
}

void saveConfig()
{
    FILE *f;

    if ((f = fopen("config_def5.json", "w")) == 0)
    {
        return;
    }

    fputs("{\n", f);
    writeString("changeOver", changeOver, ",", f);
    writeString("configVersion", configVersion, ",", f);
    writeInt("coolToDegrees", coolToDegrees, ",", f);
    writeString("currFwVersion", currFwVersion, ",", f);
    writeBool("dst", dst, ",", f);
    writeInt("epochTime", epochTime, ",", f);
    writeString("fanControl", fanControl, ",", f);
    writeString("firstNameText", firstNameText, ",", f);
    writeString("fanMode", fanMode, ",", f);
    writeInt("filterChangeDate", filterChangeDate, ",", f);
    writeInt("filterLifeInDays", filterLifeInDays, ",", f);
    writeBool("firstTime", firstTime, ",", f);
    writeString("firmwareUrl", firmwareUrl, ",", f);
    writeInt("heatToDegrees", heatToDegrees, ",", f);
    fprintf(f, "\"hvacConfig\": {\n");
    writeString("backupHeatingType", backupHeatingType, ",", f);
    writeString("hvacType", hvacType, ",", f);
    writeInt("coolingStages", coolingStages, ",", f);
    writeInt("heatingStages", heatingStages, "", f);
    fprintf(f, "},\n");

    writeString("hvacMode", hvacMode, ",", f);
    writeString("keyboardLock", keyboardLock, ",", f);
    writeString("language", language, ",", f);
    writeInt("localHumidity", localHumidity, ",", f);
    writeInt("localTemp", localTemperature, ",", f);
    writeString("lockCode", lockCode, ",", f);
    writeBool("metric", metric, ",", f);
    writeString("nextFwVersion", nextFwVersion, ",", f);
    writeString("ownersName", ownersName, ",", f);
    writeInt("reset", reset, ",", f);
    writeBool("testing", testing, ",", f);

    fprintf(f, "\"schedules\": [\n");
    int i, p;
    for (i=0; i<4; i++)
    {
        fprintf(f, "  {\n    \"days\": [\n      {\n");
        fprintf(f, "        \"label\": \"%s\",\n", schedules[i].days[0].label);
        fprintf(f, "        \"periods\": [\n");

        for (p=0; p<4; p++)
        {
            fprintf(f,"          {\n            \"label\": \"%s\",\n",
                    schedules[i].days[0].periods[p].label);
            fprintf(f,"            \"heat\": %d,\n",
                    schedules[i].days[0].periods[p].heat);
            fprintf(f,"            \"cool\": %d,\n",
                    schedules[i].days[0].periods[p].cool);
            fprintf(f,"            \"startTime\": %d,\n",
                    schedules[i].days[0].periods[p].startTime);
            fprintf(f,"            \"stopTime\": %d\n",
                    schedules[i].days[0].periods[p].stopTime);
            fprintf(f,"          }");
            if (p != 3)
            {
                fprintf(f,",\n");
            }
            else
            {
                fprintf(f,"\n");
            }
        }

        fprintf(f,"        ]\n");
        fprintf(f,"      }\n");
        fprintf(f,"   ],\n");
        fprintf(f,"  \"label\": \"%s\",\n", schedules[i].label);
        fprintf(f,"  \"systemDefined\": %s\n",
                (schedules[i].systemDefined) ? "true" : "false");
        fprintf(f,"  },\n");
    }

    fprintf(f, "  {\n    \"days\": [\n");
    int k;
    for (k=0; k<7; k++)
    {
        fprintf(f, "     {\n        \"label\": \"%s\",\n", schedules[i].days[k].label);
        fprintf(f, "        \"periods\": [\n");

        for (p=0; p<4; p++)
        {
            fprintf(f,"          {\n            \"label\": \"%s\",\n",
                    schedules[i].days[k].periods[p].label);
            fprintf(f,"            \"heat\": %d,\n",
                    schedules[i].days[k].periods[p].heat);
            fprintf(f,"            \"cool\": %d,\n",
                    schedules[i].days[k].periods[p].cool);
            fprintf(f,"            \"startTime\": %d,\n",
                    schedules[i].days[k].periods[p].startTime);
            fprintf(f,"            \"stopTime\": %d\n",
                    schedules[i].days[k].periods[p].stopTime);
            fprintf(f,"          }");
            if (p != 3)
            {
                fprintf(f,",\n");
            }
            else
            {
                fprintf(f,"\n");
            }
        }

        fprintf(f,"        ]\n");
        if (k != 6)
        {
            fprintf(f,"     },\n");
        }
    }

    fprintf(f,"      }\n");
    fprintf(f,"   ],\n");
    fprintf(f,"  \"label\": \"%s\",\n", schedules[i].label);
    fprintf(f,"  \"systemDefined\": %s\n",
            (schedules[i].systemDefined) ? "true" : "false");
    fprintf(f,"  }\n],\n");

    writeString("currentSchedule", currentSchedule, ",", f);
    writeString("securityMode", securityMode, ",", f);
    writeString("serial", serialNumber, ",", f);
    writeBool("tempHold", tempHold, ",", f);
    writeInt("thermoControls", thermoControls, ",", f);
    writeInt("temperatureSetPoint", temperatureSetPoint, ",", f);
    writeInt("timeZoneOffset", timeZoneOffset, ",", f);
    writeBool("unitLocked", unitLocked, ",", f);
    writeString("zipCode", zipCode, "", f);

    fputs("}\n", f);
    fclose(f);

}

