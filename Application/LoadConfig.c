#include "ranger.h"
#include <stdlib.h>
#include <time.h>
#include "cJSON.h"

static cJSON *config_root;

char *LANG(char *s)
{
    static char o[100];
    int i;
    o[0] = '\0';
    if (strcmp(language, "english") == 0)
    {
        strcpy(o, s);
    }
    else
    {
        if (strcmp(s, "AUTO") == 0) strcpy(o, "AUTO");
        else if (strcmp(s, "ALL DAYS") == 0) strcpy(o, "TODOS LOS DÍAS");
        else if (strcmp(s, "AUTO TEMPERATURE SETTINGS") == 0) strcpy(o, "TEMPERATURA DE AUTO");
        else if (strcmp(s, "BACK") == 0) strcpy(o, "PREVIO");
        else if (strcmp(s, "BACKUP HEAT") == 0) strcpy(o, "CALOR DE RESPALDO");
        else if (strcmp(s, "CANCEL") == 0) strcpy(o, "CANCELAR");
        else if (strcmp(s, "CLOSE") == 0) strcpy(o, "CERRAR");
        else if (strcmp(s, "COOL\nTO") == 0) strcpy(o, "QUAY\nA");
        else if (strcmp(s, "CLOCK FORMAT") == 0) strcpy(o, "FORMATO DEL RELOJ");
        else if (strcmp(s, "CHANGE NAME") == 0) strcpy(o, "CAMBIO DE NOMBRE");
        else if (strcmp(s, "COOL") == 0) strcpy(o, "GUAY");
        else if (strcmp(s, "COOL TO SETTINGS") == 0) strcpy(o, "ENFRIAMIENTO A CONFIGURACIONES");
        else if (strcmp(s, "COOLING STAGES") == 0) strcpy(o, "ETAPAS DE ENFRIAMIENTO");
        else if (strcmp(s, "DAYLIGHT SAVING TIME") == 0) strcpy(o, "EL HORARIO DE VERANO");
        else if (strcmp(s, "DELETE THERMOSTAT") == 0) strcpy(o, "ELIMINAR TERMOSTATO");
        else if (strcmp(s, "DONE") == 0) strcpy(o, "TERMINADO");
        else if (strcmp(s, "E-HEAT") == 0) strcpy(o, "E-HEAT");
        else if (strcmp(s, "EDIT") == 0) strcpy(o, "EDITAR");
        else if (strcmp(s, "EDIT SCHEDULE:") == 0) strcpy(o, "HORARIO DE EDICIÓN:");
        else if (strcmp(s, "FAN MODE") == 0) strcpy(o, "MODO DE VENTILADOR");
        else if (strcmp(s, "FAN") == 0) strcpy(o, "FAN");
        else if (strcmp(s, "FAN CONTROL") == 0) strcpy(o, "CONTROL DEL VENTILADOR");
        else if (strcmp(s, "FORCED AIR") == 0) strcpy(o, "AIRE FORZADO");
        else if (strcmp(s, "HEAT") == 0) strcpy(o, "CALOR");
        else if (strcmp(s, "HEAT\nTO") == 0) strcpy(o, "CALOR\nA");
        else if (strcmp(s, "HEAT TO SETTINGS") == 0) strcpy(o, "CALOR A LOS AJUSTES");
        else if (strcmp(s, "HEATING STAGES") == 0) strcpy(o, "ETAPAS DE CALEFACCION");
        else if (strcmp(s, "HEAT PUMP") == 0) strcpy(o, "BOMBA DE CALEFACCION");
        else if (strcmp(s, "HELP") == 0) strcpy(o, "AYUDA");
        else if (strcmp(s, "HOLD") == 0) strcpy(o, "SOSTENER");
        else if (strcmp(s, "HOME") == 0) strcpy(o, "CASA");
        else if (strcmp(s, "HOT WATER OR STEAM") == 0) strcpy(o, "AGUA CALIENTE O VAPOR");
        else if (strcmp(s, "HUMIDITY") == 0) strcpy(o, "HUMEDAD");
        else if (strcmp(s, "INDOOR") == 0) strcpy(o, "INTERIORES");
        else if (strcmp(s, "KEYBOARD LOCKOUT") == 0) strcpy(o, "BLOQUEO DEL TECLADO");
        else if (strcmp(s, "LATER") == 0) strcpy(o, "MÁS TARDE");
        else if (strcmp(s, "LEAVE") == 0) strcpy(o, "SALIR");
        else if (strcmp(s, "MODE") == 0) strcpy(o, "MODO");
        else if (strcmp(s, "MORE") == 0) strcpy(o, "MÁS");
        else if (strcmp(s, "NEXT") == 0) strcpy(o, "SEQUIENTE");
        else if (strcmp(s, "OFF") == 0) strcpy(o, "APAGADO");
        else if (strcmp(s, "OUTSIDE") == 0) strcpy(o, "FUERA DE");
        else if (strcmp(s, "ON") == 0) strcpy(o, "EN");
        else if (strcmp(s, "ON SCHED") == 0) strcpy(o, "EN PROG");
        else if (strcmp(s, "PAIR STATUS") == 0) strcpy(o, "ESTADO DEL PAIR");
        else if (strcmp(s, "PROFILE") == 0) strcpy(o, "PERFIL");
        else if (strcmp(s, "PREFERENCES") == 0) strcpy(o, "PREFERENCIAS");
        else if (strcmp(s, "RETURN") == 0) strcpy(o, "REGRESO");
        else if (strcmp(s, "RESCAN") == 0) strcpy(o, "REESCANEAR");
        else if (strcmp(s, "RESET") == 0) strcpy(o, "REINICIAR");
        else if (strcmp(s, "SAVE") == 0) strcpy(o, "SALVAR");
        else if (strcmp(s, "SAVINGS") == 0) strcpy(o, "AHORROS");
        else if (strcmp(s, "SCALE") == 0) strcpy(o, "ESCALA");
        else if (strcmp(s, "SCHEDULE HELP") == 0) strcpy(o, "CALENDARIO AYUDA");
        else if (strcmp(s, "SCHEDULE PERIODS") == 0) strcpy(o, "PERÍODOS DE CALENDARIO");
        else if (strcmp(s, "SCHEDULING OPTIONS") == 0) strcpy(o, "OPCIONES DE PROGRAMACIÓN");
        else if (strcmp(s, "SCREEN LOCK") == 0) strcpy(o, "BLOQUEO DE PANTALLA");
        else if (strcmp(s, "SELECT WIFI NETWORK") == 0) strcpy(o, "SELECCIONAR WIFI RED");
        else if (strcmp(s, "SET TIME") == 0) strcpy(o, "CONFIGURE LA FECHA");
        else if (strcmp(s, "SET DATE") == 0) strcpy(o, "CONFIGURE LA HORA");
        else if (strcmp(s, "SET SCHEDULE") == 0) strcpy(o, "HORARIO");
        else if (strcmp(s, "SAVE SCHEDULE") == 0) strcpy(o, "GUARDAR EL HORARIO");
        else if (strcmp(s, "SET TO") == 0) strcpy(o, "AJUSTAR A");
        else if (strcmp(s, "SETTINGS") == 0) strcpy(o, "AJUSTES");
        else if (strcmp(s, "SETTINGS:") == 0) strcpy(o, "AJUSTES:");
        else if (strcmp(s, "SETUP") == 0) strcpy(o, "PREPARAR");
        else if (strcmp(s, "SHIFT") == 0) strcpy(o, "CAMBIO");
        else if (strcmp(s, "SLEEP") == 0) strcpy(o, "DORMIR");
        else if (strcmp(s, "SPACE") == 0) strcpy(o, "ESPACIO");
        else if (strcmp(s, "SYSTEM SETUP") == 0) strcpy(o, "CONFIGURACIÓN DEL SISTEMA");
        else if (strcmp(s, "SYSTEMS CHANGE OVER") == 0) strcpy(o, "CAMBIO DE SISTEMAS");
        else if (strcmp(s, "SYSTEM TYPE") == 0) strcpy(o, "TIPO DE SISTEMA");
        else if (strcmp(s, "TEMPERATURE SCALE") == 0) strcpy(o, "LA ESCALA DEL TEMPERATURA");
        else if (strcmp(s, "THERMOSTAT") == 0) strcpy(o, "TERMOSTATO");
        else if (strcmp(s, "THERMOSTAT CONTROLS") == 0) strcpy(o, "TERMOSTATO CONTROLES");
        else if (strcmp(s, "THERMOSTAT LOCATION") == 0) strcpy(o, "LOCALES DEL TERMOSTATO");
        else if (strcmp(s, "TIME") == 0) strcpy(o, "HORA");
        else if (strcmp(s, "VACATION") == 0) strcpy(o, "VACACIONES");
        else if (strcmp(s, "WAKE") == 0) strcpy(o, "DESPERTAR");
        else if (strcmp(s, "WEEKDAY") == 0) strcpy(o, "DÍA LABORABLE");
        else if (strcmp(s, "WEEKEND") == 0) strcpy(o, "FIN DE SEMANA");
        else if (strcmp(s, "WIFI SETUP") == 0) strcpy(o, "CONFIGURACIÓN WIFI");

        else if (strcmp(s, "Mon") == 0) strcpy(o, "Lun");
        else if (strcmp(s, "Tue") == 0) strcpy(o, "Mar");
        else if (strcmp(s, "Wed") == 0) strcpy(o, "Mie");
        else if (strcmp(s, "Thu") == 0) strcpy(o, "Jue");
        else if (strcmp(s, "Fri") == 0) strcpy(o, "Vie");
        else if (strcmp(s, "Sat") == 0) strcpy(o, "Sab");
        else if (strcmp(s, "Sun") == 0) strcpy(o, "Dom");

        else if (strcmp(s, "JAN") == 0) strcpy(o, "ENE");
        else if (strcmp(s, "FEB") == 0) strcpy(o, "FEB");
        else if (strcmp(s, "MAR") == 0) strcpy(o, "MAR");
        else if (strcmp(s, "APR") == 0) strcpy(o, "ABR");
        else if (strcmp(s, "MAY") == 0) strcpy(o, "MAY");
        else if (strcmp(s, "JUN") == 0) strcpy(o, "JUN");
        else if (strcmp(s, "JUL") == 0) strcpy(o, "JUL");
        else if (strcmp(s, "AUG") == 0) strcpy(o, "AGO");
        else if (strcmp(s, "SEP") == 0) strcpy(o, "SEP");
        else if (strcmp(s, "OCT") == 0) strcpy(o, "OCT");
        else if (strcmp(s, "NOV") == 0) strcpy(o, "NOV");
        else if (strcmp(s, "DEC") == 0) strcpy(o, "DIC");

        else if (strcmp(s, "12 Hour") == 0) strcpy(o, "12 Horas");
        else if (strcmp(s, "24 Hour") == 0) strcpy(o, "24 Horas");
        else if (strcmp(s, "1 Stage") == 0) strcpy(o, "1 etapa");
        else if (strcmp(s, "2 Stage") == 0) strcpy(o, "2 etapa");
        else if (strcmp(s, "2 Per Day") == 0) strcpy(o, "2 por día");
        else if (strcmp(s, "4 Per Day") == 0) strcpy(o, "4 por día");
        else if (strcmp(s, "All Days") == 0) strcpy(o, "Todos los días");
        else if (strcmp(s, "Automatic") == 0) strcpy(o, "Automático");
        else if (strcmp(s, "Backup Heat") == 0) strcpy(o, "Apoyo Calor");
        else if (strcmp(s, "Celsius") == 0) strcpy(o, "Centígrados");
        else if (strcmp(s, "Centigrade") == 0) strcpy(o, "Centígrados");
        else if (strcmp(s, "Clock Format") == 0) strcpy(o, "Reloj Formato");
        else if (strcmp(s, "Cooling") == 0) strcpy(o, "Refrigeración");
        else if (strcmp(s, "Cooling Stages") == 0) strcpy(o, "Enfriamiento Etapas");
        else if (strcmp(s, "Day") == 0) strcpy(o, "Día");
        else if (strcmp(s, "Daylight Saving Time") == 0) strcpy(o, "Luz Ahorros Hora");
        else if (strcmp(s, "Each Day") == 0) strcpy(o, "Cada día");
        else if (strcmp(s, "English") == 0) strcpy(o, "Inglés");
        else if (strcmp(s, "Español") == 0) strcpy(o, "Español");
        else if (strcmp(s, "Expiration Date:") == 0) strcpy(o, "Fecha de caducidad:");
        else if (strcmp(s, "Fan Control") == 0) strcpy(o, "Fan Controlar");
        else if (strcmp(s, "Fahrenheit") == 0) strcpy(o, "Fahrenheit");
        else if (strcmp(s, "Heat") == 0) strcpy(o, "Calor");
        else if (strcmp(s, "Heating") == 0) strcpy(o, "Calefacción");
        else if (strcmp(s, "Heating Stages") == 0) strcpy(o, "Calefacción Etapas");
        else if (strcmp(s, "Hour") == 0) strcpy(o, "Hora");
        else if (strcmp(s, "Keyboard Lockout") == 0) strcpy(o, "Bloqueo del teclado");
        else if (strcmp(s, "Languages") == 0) strcpy(o, "Idiomas");
        else if (strcmp(s, "Lock") == 0) strcpy(o, "Bloquear");
        else if (strcmp(s, "Locked") == 0) strcpy(o, "Bloqueado");
        else if (strcmp(s, "MAC Address:") == 0) strcpy(o, "Dirección MAC:");
        else if (strcmp(s, "Manual") == 0) strcpy(o, "Manual");
        else if (strcmp(s, "Minute") == 0) strcpy(o, "Minuto");
        else if (strcmp(s, "Mobile Pair") == 0) strcpy(o, "Móvil Par");
        else if (strcmp(s, "Month") == 0) strcpy(o, "Mes");
        else if (strcmp(s, "Name") == 0) strcpy(o, "Nombre");
        else if (strcmp(s, "Name:") == 0) strcpy(o, "Nombre:");
        else if (strcmp(s, "No") == 0) strcpy(o, "No");
        else if (strcmp(s, "Non-Programmable") == 0) strcpy(o, "No programable");
        else if (strcmp(s, "Off") == 0) strcpy(o, "Apagado");
        else if (strcmp(s, "On") == 0) strcpy(o, "En");
        else if (strcmp(s, "Personal") == 0) strcpy(o, "Personal");
        else if (strcmp(s, "Preferences") == 0) strcpy(o, "Preferencias");
        else if (strcmp(s, "Profile") == 0) strcpy(o, "Perfil");
        else if (strcmp(s, "Programmable") == 0) strcpy(o, "Programable");
        else if (strcmp(s, "Schedule") == 0) strcpy(o, "Programar");
        else if (strcmp(s, "Schedule Periods") == 0) strcpy(o, "Programar Períodos");
        else if (strcmp(s, "Scheduling Options") == 0) strcpy(o, "Programación Opciones");
        else if (strcmp(s, "Set Time") == 0) strcpy(o, "Fijar tiempo");
        else if (strcmp(s, "Set Temp") == 0) strcpy(o, "Set Temp");
        else if (strcmp(s, "Set to") == 0) strcpy(o, "Ajustar a");
        else if (strcmp(s, "Setup") == 0) strcpy(o, "Preparar");
        else if (strcmp(s, "Select WIFI Network") == 0) strcpy(o, "Seleccionar red WIFI");
        else if (strcmp(s, "Status:") == 0) strcpy(o, "Estado");
        else if (strcmp(s, "System Change Over") == 0) strcpy(o, "Sistema Cambio Encima");
        else if (strcmp(s, "System Type") == 0) strcpy(o, "Sistema Tipo");
        else if (strcmp(s, "Temperature") == 0) strcpy(o, "Temperatura");
        else if (strcmp(s, "Temperature Limits") == 0) strcpy(o, "Temperatura Límites");
        else if (strcmp(s, "Temperature Scale") == 0) strcpy(o, "Temperatura Escala");
        else if (strcmp(s, "Thermostat") == 0) strcpy(o, "Termostato");
        else if (strcmp(s, "Thermostat Controls") == 0) strcpy(o, "Controles de termostato");
        else if (strcmp(s, "Thermostat Location") == 0) strcpy(o, "Localizaciones del termostato");
        else if (strcmp(s, "Thermostat MAC:") == 0) strcpy(o, "Termostato MAC:");
        else if (strcmp(s, "Time") == 0) strcpy(o, "Hora");
        else if (strcmp(s, "Time/Date") == 0) strcpy(o, "Hora/Fecha");
        else if (strcmp(s, "Unlocked") == 0) strcpy(o, "Desbloqueado");
        else if (strcmp(s, "Vacation") == 0) strcpy(o, "Vacaciones");
        else if (strcmp(s, "WIFI Setup") == 0) strcpy(o, "WIFI Preparar");
        else if (strcmp(s, "WIFI Network:") == 0) strcpy(o, "Red WIFI:");
        else if (strcmp(s, "Weekday/Weekend") == 0) strcpy(o, "Día de la semana / Fin de semana");
        else if (strcmp(s, "Working") == 0) strcpy(o, "Trabajando");
        else if (strcmp(s, "Year") == 0) strcpy(o, "Año");
        else if (strcmp(s, "Yes") == 0) strcpy(o, "Sí");
        else if (strcmp(s, "Zip Code") == 0) strcpy(o, "Código postal");
        else if (strcmp(s, "Zip Code:") == 0) strcpy(o, "Código postal:");
        else if (strcmp(s, "Please visit") == 0) strcpy(o, "Por favor, visite");
        else if (strcmp(s, "to setup your") == 0) strcpy(o, "para configurar su");
        else if (strcmp(s, "thermostat for remote access") == 0) strcpy(o, "termostato para el acceso remoto");
        else if (strcmp(s, "Press the PERIOD button to select desired \nscheduling period.") == 0) strcpy(o, "Presione el botón período para seleccionar el período\nde programación deseado.");
        else if (strcmp(s, "Press the START, STOP or TEMP buttons change\n current settings.") == 0) strcpy(o, "Pulse Inicio, parada o temperatura botones cambian\najustes actuales.");
        else if (strcmp(s, "Use the Set Schedule button to set the desired schedule.") == 0) strcpy(o, "Pulse Inicio, parada o temperatura botones cambian\najustes actuales.");
        else if (strcmp(s, "To edit a schedule select the desired schedule") == 0) strcpy(o, "Para editar una selección de horario el horario deseado");
        else if (strcmp(s, "and press the Edit button.") == 0) strcpy(o, "y pulse el botón Edit.");
        else {
            o[0] = '\0';
        }

    }
    return o;
}

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

void getCurrentTime()
{
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
}

int  scheduleTemperature(int tod, char *day, char *mode)
{
    int i,k;
    int startTime, stopTime;
    struct days_s selectedDay;

    int st = tod;
    char buf[50];

    for (k=0; k<selectedSchedule.day_count; k++)
    {
        if (strcmp(selectedSchedule.days[k].label, day) != 0) continue;
        selectedDay = selectedSchedule.days[k];

        for (i=0; i<4; i++)
        {
            startTime = selectedDay.periods[i].startTime;
            stopTime = selectedDay.periods[i].stopTime;

            sprintf(buf, "%s, tod=%d, S=%d, E=%d, T=%d",
                    selectedDay.periods[i].label, tod, startTime,
                    stopTime, selectedDay.periods[i].cool);
//GUI_ErrorOut(buf);
            if (stopTime < startTime)
            {
                if (st < stopTime || st >= startTime)
                {
                    if (strcmp(mode, "cool") == 0) {
                        return selectedDay.periods[i].cool;
                    } else {
                        return selectedDay.periods[i].heat;
                    }
                }
            }
            else
            {
                if (st >= startTime && st <= stopTime)
                {
                    if (strcmp(mode, "cool") == 0) {
                        return selectedDay.periods[i].cool;
                    } else {
                        return selectedDay.periods[i].heat;
                    }
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

double getDoubleObject(cJSON *j, char * o)
{
    cJSON *cj = cJSON_GetObjectItem(j,o);
    return (cj == NULL) ? 0 : cj->valuedouble;
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

        strcpy(changeOver, getStringObject(config_root,"changeOver"));
        strcpy(configVersion, getStringObject(config_root,"configVersion"));
        coolToDegrees = (float)getDoubleObject(config_root,"coolToDegrees");
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
        heatToDegrees = (float)getDoubleObject(config_root,"heatToDegrees");
        strcpy(hvacMode, getStringObject(config_root,"hvacMode"));
        strcpy(keyboardLock, getStringObject(config_root,"keyboardLock"));
        strcpy(language,  getStringObject(config_root,"language"));
        strcpy(lockCode, getStringObject(config_root,"lockCode"));
        metric = getBoolObject(config_root,"metric");
        nextFwVersion = getStringObject(config_root,"nextFwVersion");
        strcpy(ownersName,  getStringObject(config_root,"ownersName"));
        resetUnit = getIntObject(config_root,"reset");
        schedulePeriods = getIntObject(config_root,"schedulePeriods");
        strcpy(schedulingOption, getStringObject(config_root,"schedulingOption"));
        securityMode = getStringObject(config_root,"securityMode");

        strcpy(serialNumber, getStringObject(config_root,"serialNumber"));
        holdMode = getBoolObject(config_root,"tempHold");
        strcpy(currentScheme, getStringObject(config_root,"themeScheme"));
        thermostatControls = getIntObject(config_root,"thermostatControls");
        temperatureSetPoint = getIntObject(config_root,"temperatureSetPoint");
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
                    periods.label = cJSON_GetObjectItem(p,"label")->valuestring;
                    periods.heat = cJSON_GetObjectItem(p,"heat")->valueint;
                    periods.cool = cJSON_GetObjectItem(p,"cool")->valueint;
                    periods.startTime = cJSON_GetObjectItem(p,"startTime")->valueint;
                    periods.stopTime = cJSON_GetObjectItem(p,"stopTime")->valueint;
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
        strcpy(configVersion, "1.0.0");
        coolToDegrees = 78;
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
        heatToDegrees = 68;
        holdMode = 0;
        strcpy(hvacMode, "cool");
        strcpy(keyboardLock, "unlocked");
        strcpy(language,  "english");

        strcpy(lockCode, "0000");
        temperatureScale = 0;
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
        temperatureSetPoint = 72;
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

        int hh, mm, i, k = 0;
        for (i=0; i<4; i++)
        {
            schedules[i].label = scheds[i];
            schedules[i].systemDefined = 1;

            schedules[i].days[0].label = scheds[i];

            schedules[i].days[k].periods[0].label = "wake";
            schedules[i].days[k].periods[0].cool = 74;
            schedules[i].days[k].periods[0].heat = 68;
            schedules[i].days[k].periods[0].startTime = 615;
            schedules[i].days[k].periods[0].stopTime = 845;

            schedules[i].days[k].periods[1].label = "leave";
            schedules[i].days[k].periods[1].cool = 74;
            schedules[i].days[k].periods[1].heat = 68;
            schedules[i].days[k].periods[1].startTime = 800;
            schedules[i].days[k].periods[1].stopTime = 1700;

            schedules[i].days[k].periods[2].label = "return";
            schedules[i].days[k].periods[2].cool = 72;
            schedules[i].days[k].periods[2].heat = 68;
            schedules[i].days[k].periods[2].startTime = 1700;
            schedules[i].days[k].periods[2].stopTime = 2000;

            schedules[i].days[k].periods[3].label = "sleep";
            schedules[i].days[k].periods[3].cool = 76;
            schedules[i].days[k].periods[3].heat = 70;
            schedules[i].days[k].periods[3].startTime = 2000;
            schedules[i].days[k].periods[3].stopTime = 600;

            schedules[i].day_count = 1;
        }

        char *dow[] = {"monday", "tuesday", "wednesday",
                       "thursday", "friday", "saturday", "sunday"
                      };

        schedules[i].label = scheds[i];
        schedules[i].systemDefined = 1;
        schedules[i].day_count = 7;

        for (k=0; k<7; k++)
        {
            schedules[i].days[k].label = dow[k];

            schedules[i].days[k].periods[0].label = "wake";
            schedules[i].days[k].periods[0].cool = 74;
            schedules[i].days[k].periods[0].heat = 68;
            schedules[i].days[k].periods[0].startTime = 615;
            schedules[i].days[k].periods[0].stopTime = 845;

            schedules[i].days[k].periods[1].label = "leave";
            schedules[i].days[k].periods[1].cool = 74;
            schedules[i].days[k].periods[1].heat = 68;
            schedules[i].days[k].periods[1].startTime = 800;
            schedules[i].days[k].periods[1].stopTime = 1700;

            schedules[i].days[k].periods[2].label = "return";
            schedules[i].days[k].periods[2].cool = 72;
            schedules[i].days[k].periods[2].heat = 68;
            schedules[i].days[k].periods[2].startTime = 1700;
            schedules[i].days[k].periods[2].stopTime = 2000;

            schedules[i].days[k].periods[3].label = "sleep";
            schedules[i].days[k].periods[3].cool = 76;
            schedules[i].days[k].periods[3].heat = 70;
            schedules[i].days[k].periods[3].startTime = 2000;
            schedules[i].days[k].periods[3].stopTime = 600;
        }
    }

    localHumidity = 99;
    localTemperature = 90;

    insideHumidity = 30;
    insideTemperature = 72.5f;

//    if (strcmp(hvacMode, "auto") == 0) {
//        heatToDegrees = lowerDegreeLimit;
//        coolToDegrees = upperDegreeLimit;
//    }

    upperDegreeLimit = coolToDegrees;
    lowerDegreeLimit = heatToDegrees;
    temperatureScale = metric;

    idleTimeOut = 360000;

    heat_control = 0;
    fan_control = 0;
    cool_control = 0;

    getCurrentTime();

    int i;
    for (i=0; i<5; i++)
    {
        if (strcmp(schedules[i].label, currentSchedule) == 0)
        {
            selectedSchedule = schedules[i];
            break;
        }
    }

    tempHighOutside = 0;
    tempLowOutside = 999999;

    tempHighInside = 0;
    tempLowInside = 999999;

    tempHighSetPoint = 0;
    tempLowSetPoint = 999999;

    humidityHighOutside = 0;
    humidityLowOutside = 999999;

    humidityHighInside = 0;
    humidityLowInside = 999999;

    compressorTotalRuntime = 0;
    compressorLongestRuntime = 0;
    compressorShortestRuntime = 999999;
    compressorRunCount = 0;

    blowerTotalRuntime = 0;
    blowerLongestRuntime = 0;
    blowerShortestRuntime  = 999999;
    blowerRunCount = 0;
}

