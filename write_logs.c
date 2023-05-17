#include <stdio.h>
#include <time.h>
// Global variables
char T_username[255];
char action[255];

void Write_Logs(char T_username[255], char action[255])
{
    FILE *write_logs = fopen("db_logs.txt", "a");
    // Time
    time_t rawtime;
    struct tm *timeinfo;

    time(&rawtime);
    timeinfo = localtime(&rawtime);
    // printf("Current local time and date: %s", asctime(timeinfo));
    fprintf(write_logs, "username: %s | action: %s | time: %s\n", T_username, action, asctime(timeinfo));
    fclose(write_logs);
}