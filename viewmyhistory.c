/* Libraries */
#include <stdio.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>
#include <stdbool.h>

void Features_Services();

// Global variables
char T_username[255];

void viewmyhistory()
{
    int viewmyhistory_options;

    printf("\n\n\n");
    printf("\n\t\t\t  **-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**\n");
    printf("\n\t\t\t        =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=");
    printf("\n\t\t\t        =         [ 1 ]   VIEW RESERVATION HISTORY  =");
    printf("\n\t\t\t        =         [ 2 ]   VIEW LOGS                 =");
    printf("\n\t\t\t        =         [ 3 ]   MAIN MENU                 =");
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
    char *filename = "dp_trainreservation.txt";
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

    char yesorno[2];

    printf("\n\t\t\t  ---------------------------------------------------------\n");
    printf("\t\t\t          DO YOU WANT TOO CONTINUE [TYPE 'Y' OR 'N'] : ");
    scanf("%s", yesorno);
    printf("\t\t\t  ---------------------------------------------------------\n");

    int value_y, value_Y;
    int value_n, value_N;
    value_y = strcmp(yesorno, "y");
    value_Y = strcmp(yesorno, "Y");
    value_N = strcmp(yesorno, "N");
    value_n = strcmp(yesorno, "n");
    if (value_y == 0 || value_Y == 0)
    {
        
        Features_Services();
    }
    else if (value_N == 0 || value_n == 0)
    {
        printf("\n\t\t\t  ---------------------------------------------------------\n");
        printf("\t\t\t                                SYSTEM EXIT                    ");
        printf("\n\t\t\t  ---------------------------------------------------------\n");
        exit(0);
    }
    else
    {
        printf("\n\t\t\t  ---------------------------------------------------------\n");
        printf("\t\t\t                         WRONG INPUT                           ");
        printf("\n\t\t\t                      REDIRECT MAIN MENU                       ");
        printf("\n\t\t\t  ---------------------------------------------------------\n");
        Features_Services();
    }
}

void view_logs_history()
{
    char *filename = "dp_logs.txt";
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

    char yesorno[2];

    printf("\n\t\t\t  ---------------------------------------------------------\n");
    printf("\t\t\t          DO YOU WANT TOO CONTINUE [TYPE 'Y' OR 'N'] : ");
    scanf("%s", yesorno);
    printf("\t\t\t  ---------------------------------------------------------\n");

    int value_y, value_Y;
    int value_n, value_N;
    value_y = strcmp(yesorno, "y");
    value_Y = strcmp(yesorno, "Y");
    value_N = strcmp(yesorno, "N");
    value_n = strcmp(yesorno, "n");
    if (value_y == 0 || value_Y == 0)
    {
        Features_Services();
    }
    else if (value_N == 0 || value_n == 0)
    {
        printf("\n\t\t\t  ---------------------------------------------------------\n");
        printf("\t\t\t                                SYSTEM EXIT                    ");
        printf("\n\t\t\t  ---------------------------------------------------------\n");
        exit(0);
    }
    else
    {
        printf("\n\t\t\t  ---------------------------------------------------------\n");
        printf("\t\t\t                         WRONG INPUT                           ");
        printf("\n\t\t\t                      REDIRECT MAIN MENU                       ");
        printf("\n\t\t\t  ---------------------------------------------------------\n");
        Features_Services();
    }
}