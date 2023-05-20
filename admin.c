/* Libraries */
#include <stdio.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>
#include <stdbool.h>

void Features_Services();
void continue_function();

void view_admin_trainreservation();
void view_admin_logs_history();
void view_admin_supports();
void view_admin_bugs();

// Global variables
char T_username[255];

void admin()
{
    int admin_options;

    printf("\n\n\n");
    printf("\n\t\t\t  **-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**\n");
    printf("\n\t\t\t        =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=");
    printf("\n\t\t\t        =         [ 1 ]   VIEW RESERVATION HISTORY  =");
    printf("\n\t\t\t        =         [ 2 ]   VIEW LOGS                 =");
    printf("\n\t\t\t        =         [ 3 ]   VIEW BUGS                 =");
    printf("\n\t\t\t        =         [ 4 ]   VIEW SUPPORTS             =");
    printf("\n\t\t\t        =         [ 0 ]   EXIT                      =");
    printf("\n\t\t\t        =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n");
    printf("\n\t\t\t  **-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**\n");

    printf("\n\t\t\t  ---------------------------------------------------------\n");
    printf("\t\t\t                PLEASE, MAKE A CHOISE : ");
    scanf("%d", &admin_options);
    printf("\n\t\t\t  ---------------------------------------------------------\n");

    switch (admin_options)
    {
    case 1:
        view_admin_trainreservation();
        break;
    case 2:
        view_admin_logs_history();
        break;
    case 3:
        view_admin_bugs();
        break;
    case 4:
        view_admin_supports();
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

void view_admin_trainreservation()
{
    char *filename = "db_trainreservation.txt";
    FILE *_trainreservation = fopen(filename, "r");

    if (_trainreservation == NULL)
    {
        printf("\n\t\t\t  ---------------------------------------------------------\n");
        printf("\t\t\t                 ERROR: CLOUD NOT OPEN FILE                    ");
        printf("\n\t\t\t  ---------------------------------------------------------\n");
        exit(0);
    }

    // read one character at a time and
    // display it to the output
    char ch;
    while ((ch = fgetc(_trainreservation)) != EOF)
        putchar(ch);

    // close the file
    Write_Logs(T_username, "Train Reservation - View");
    fclose(_trainreservation);

    continue_admin_function();
}

void view_admin_bugs()
{
    char *filename = "db_bugs.txt";
    FILE *_trainreservation = fopen(filename, "r");

    if (_trainreservation == NULL)
    {
        printf("\n\t\t\t  ---------------------------------------------------------\n");
        printf("\t\t\t                 ERROR: CLOUD NOT OPEN FILE                    ");
        printf("\n\t\t\t  ---------------------------------------------------------\n");
        exit(0);
    }

    // read one character at a time and
    // display it to the output
    char ch;
    while ((ch = fgetc(_trainreservation)) != EOF)
        putchar(ch);

    // close the file
    Write_Logs(T_username, "Train Reservation - View");
    fclose(_trainreservation);

    continue_admin_function();
}

void view_admin_supports()
{
    char *filename = "db_supports.txt";
    FILE *_trainreservation = fopen(filename, "r");

    if (_trainreservation == NULL)
    {
        printf("\n\t\t\t  ---------------------------------------------------------\n");
        printf("\t\t\t                 ERROR: CLOUD NOT OPEN FILE                    ");
        printf("\n\t\t\t  ---------------------------------------------------------\n");
        exit(0);
    }

    // read one character at a time and
    // display it to the output
    char ch;
    while ((ch = fgetc(_trainreservation)) != EOF)
        putchar(ch);

    // close the file
    Write_Logs(T_username, "Train Reservation - View");
    fclose(_trainreservation);

    continue_admin_function();
}

void view_admin_logs_history()
{
    char *filename = "db_logs.txt";
    FILE *_logs = fopen(filename, "r");

    if (_logs == NULL)
    {
        printf("\n\t\t\t  ---------------------------------------------------------\n");
        printf("\t\t\t                 ERROR: CLOUD NOT OPEN FILE                    ");
        printf("\n\t\t\t  ---------------------------------------------------------\n");
        exit(0);
    }

    // read one character at a time and
    // display it to the output
    char ch;
    while ((ch = fgetc(_logs)) != EOF)
        putchar(ch);

    // close the file
    Write_Logs(T_username, "Logs - View");
    fclose(_logs);

    continue_admin_function();
}