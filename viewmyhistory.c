/* Libraries */
#include <stdio.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>
#include <stdbool.h>

void Features_Services();
void continue_function();

void view_trainreservation();
void view_logs_history();
void view_bugs();
void view_supports();

// Global variables
char T_username[255];
// Global variables
char T_username[255];
int l_r_status;
int i;
char username[255];
char reservation[255];

void viewmyhistory()
{
    int viewmyhistory_options;

    printf("\n\n\n");
    printf("\n\t\t\t  **-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**\n");
    printf("\n\t\t\t        =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=");
    printf("\n\t\t\t        =         [ 1 ]   VIEW RESERVATION HISTORY  =");
    printf("\n\t\t\t        =         [ 2 ]   VIEW LOGS                 =");
    printf("\n\t\t\t        =         [ 3 ]   VIEW BUGS                 =");
    printf("\n\t\t\t        =         [ 4 ]   VIEW SUPPORT              =");
    printf("\n\t\t\t        =         [ 5 ]   MAIN MENU                 =");
    printf("\n\t\t\t        =         [ 0 ]   EXIT                      =");
    printf("\n\t\t\t        =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n");
    printf("\n\t\t\t  **-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**\n");

    printf("\n\t\t\t  ---------------------------------------------------------\n");
    printf("\t\t\t                PLEASE, MAKE A CHOISE : ");
    scanf("%d", &viewmyhistory_options);
    printf("\n\t\t\t  ---------------------------------------------------------\n");

    switch (viewmyhistory_options)
    {
    case 1:
        view_trainreservation();
        break;
    case 2:
        view_logs_history();
        break;
    case 3:
        view_bugs();
        break;
    case 4:
        view_supports();
        break;
    case 5:
        l_r_status = 1;
        Features_Services();
        break;
    case 0:

        printf("\n\t\t\t  ---------------------------------------------------------\n");
        printf("\t\t\t                         EXITING SERVICES                    ");
        printf("\n\t\t\t  ---------------------------------------------------------\n");
        exit(0);
        break;

    default:
        printf("\n\t\t\t  ---------------------------------------------------------\n");
        printf("\t\t\t                         WRONG INPUT                    ");
        printf("\t\t\t                         TRY AGAIN                    ");
        printf("\n\t\t\t  ---------------------------------------------------------\n");
        break;
    }
}

void view_trainreservation()
{
    char user_viewmyhistory[255];
    strcpy(user_viewmyhistory, "");
    strcat(user_viewmyhistory, "db_reservation_");
    strcat(user_viewmyhistory, username);

    char *filename = user_viewmyhistory;
    FILE *_trainreservation = fopen(filename, "r");

    if (_trainreservation == NULL)
    {
        printf("\n\t\t\t  ---------------------------------------------------------\n");
        printf("\t\t\t                 THERE ARE NO RESERVATIONS                     ");
        printf("\n\t\t\t  ---------------------------------------------------------\n");
        continue_function();
    }

    // read one character at a time and
    // display it to the output
    char ch;
    while ((ch = fgetc(_trainreservation)) != EOF)
        putchar(ch);

    // close the file
    Write_Logs(T_username, "Train Reservation - View");
    fclose(_trainreservation);

    continue_function();
}

void view_logs_history()
{

    char user_viewmyhistory[255];
    strcpy(user_viewmyhistory, "");
    strcat(user_viewmyhistory, "db_logs_");
    strcat(user_viewmyhistory, username);

    char *filename = user_viewmyhistory;
    FILE *_logs = fopen(filename, "r");

    if (_logs == NULL)
    {
        printf("\n\t\t\t  ---------------------------------------------------------\n");
        printf("\t\t\t                       NO LOGS FOUND                           ");
        printf("\n\t\t\t  ---------------------------------------------------------\n");
        continue_function();
    }

    // read one character at a time and
    // display it to the output
    char ch;
    while ((ch = fgetc(_logs)) != EOF)
        putchar(ch);

    // close the file
    Write_Logs(T_username, "Logs - View");
    fclose(_logs);

    continue_function();
}

void view_bugs()
{
    char user_viewmyhistory[255];
    strcpy(user_viewmyhistory, "");
    strcat(user_viewmyhistory, "db_bugs_");
    strcat(user_viewmyhistory, username);

    char *filename = user_viewmyhistory;
    FILE *_trainreservation = fopen(filename, "r");

    if (_trainreservation == NULL)
    {
        printf("\n\t\t\t  ---------------------------------------------------------\n");
        printf("\t\t\t                 ERROR: CLOUD NOT OPEN FILE                    ");
        printf("\n\t\t\t  ---------------------------------------------------------\n");
        continue_function();
    }

    // read one character at a time and
    // display it to the output
    char ch;
    while ((ch = fgetc(_trainreservation)) != EOF)
        putchar(ch);

    // close the file
    Write_Logs(T_username, "Bugs - View");
    fclose(_trainreservation);

    continue_function();
}

void view_supports()
{
    char user_viewmyhistory[255];
    strcpy(user_viewmyhistory, "");
    strcat(user_viewmyhistory, "db_supports_");
    strcat(user_viewmyhistory, username);

    char *filename = user_viewmyhistory;
    FILE *_trainreservation = fopen(filename, "r");

    if (_trainreservation == NULL)
    {
        printf("\n\t\t\t  ---------------------------------------------------------\n");
        printf("\t\t\t                 ERROR: CLOUD NOT OPEN FILE                    ");
        printf("\n\t\t\t  ---------------------------------------------------------\n");
        continue_function();
    }

    // read one character at a time and
    // display it to the output
    char ch;
    while ((ch = fgetc(_trainreservation)) != EOF)
        putchar(ch);

    // close the file
    Write_Logs(T_username, "Supports - View");
    fclose(_trainreservation);

    continue_function();
}