/* Libraries */
#include <stdio.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>
#include <stdbool.h>

// constants for size of char arrays to store filename, the line from the file
#define FILENAME_SIZE 1024
#define MAX_LINE 2048

#define MAX_LENGTH 255
#define NUM_STRINGS 20

// functions
void Features_Services();

// 03.05.2023.2.20.29
void Bugs();
void NewBugs();
void BugsView();

void Write_Logs(char T_username[255], char action[20]);

// Global variables
char T_username[255];

void Bugs()
{
    int BugsOption;

    printf("\n\n\n");
    printf("\n\t\t\t  **-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**\n");
    printf("\n\t\t\t        =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=");
    printf("\n\t\t\t        =         [ 1 ]   REPORT A BUG              =");
    printf("\n\t\t\t        =         [ 2 ]   VIEW BUGS REPORT          =");
    printf("\n\t\t\t        =         [ 3 ]   MAIN MENU                 =");
    printf("\n\t\t\t        =         [ 0 ]   EXIT                      =");
    printf("\n\t\t\t        =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n");
    printf("\n\t\t\t  **-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**\n");

    printf("\n\t\t\t  ---------------------------------------------------------\n");
    printf("\t\t\t                PLEASE, MAKE A CHOISE : ");
    scanf("%d", &BugsOption);
    printf("\n\t\t\t  ---------------------------------------------------------\n");

    switch (BugsOption)
    {
    case 1:
        NewBugs();
        break;
    case 2:
        BugsView();
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

void NewBugs()
{
    char content[3000], c;
    int index = 0;

    char heading[3000], c1;
    int index1 = 0;

    char mailaddress[3000], c2;
    int index2 = 0;

    int no = 1;

    // Time
    time_t rawtime;
    struct tm *timeinfo;

    time(&rawtime);
    timeinfo = localtime(&rawtime);
    // printf("Current local time and date: %s", asctime(timeinfo));

    char *filename = "bugs.txt";
    FILE *BugsFile = fopen(filename, "a");

    if (BugsFile == NULL)
    {
        printf("\n\t\t\t  ---------------------------------------------------------\n");
        printf("\t\t\t                 ERROR: CLOUD NOT OPEN FILE                    ");
        printf("\n\t\t\t  ---------------------------------------------------------\n");
        exit(0);
    }
    else
    {
        printf("\n\t\t\t  ---------------------------------------------------------\n");
        printf("\t\t\t          MAIL ADDRESS: ( press ';' to end input): ");
        while ((c2 = getchar()) != ';')
        {
            mailaddress[index2++] = c2;
        }
        mailaddress[index2] = '\0';
        printf("\n\t\t\t  ---------------------------------------------------------\n");

        printf("\n\t\t\t  ---------------------------------------------------------\n");
        printf("\t\t\t          HEADING: ( press ';' to end input): ");
        while ((c1 = getchar()) != ';')
        {
            heading[index1++] = c1;
        }
        heading[index1] = '\0';
        printf("\n\t\t\t  ---------------------------------------------------------\n");


        printf("\n\t\t\t  ---------------------------------------------------------\n");
        printf("\t\t\t          CONTENT: ( press ';' to end input): ");
        while ((c = getchar()) != ';')
        {
            content[index++] = c;
        }
        content[index] = '\0';
        printf("\n\t\t\t  ---------------------------------------------------------\n");

        fprintf(BugsFile, "Mail support no. %d \n\tRequesting person name: %s \nMail address: %s \nHeading: %s \nContent: %s \n\tTime: %s", no, T_username, mailaddress, heading, content, asctime(timeinfo));
        fprintf(BugsFile, "---------------------------------------------------------------\n\n\n");
        Write_Logs(T_username, "New Bug");
        fclose(BugsFile);

        char yesorno[2];
        printf("\n\t\t\t  ---------------------------------------------------------\n");
        printf("\t\t\t          DO YOU WANT TOO CONTINUE [TYPE 'Y' OR 'N']: ");
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
}

void BugsView()
{
    char *filename = "bugs.txt";
    FILE *ViewBugFile = fopen(filename, "r");

    if (ViewBugFile == NULL)
    {
        printf("\n\t\t\t  ---------------------------------------------------------\n");
        printf("\t\t\t                 ERROR: CLOUD NOT OPEN FILE                    ");
        printf("\n\t\t\t  ---------------------------------------------------------\n");
        exit(0);
    }

    // read one character at a time and
    // display it to the output
    char ch;
    while ((ch = fgetc(ViewBugFile)) != EOF)
        putchar(ch);

    char *x[] = {"ab", "bc", "cd"};
    char *s = "kirupan";
    int len = sizeof(x) / sizeof(x[0]);
    int i;

    for (i = 0; i < len; ++i)
    {
        if (!strcmp(x[i], s))
        {
            // Do your stuff
        }
    }
    // close the file
    Write_Logs(T_username, "Bugs - View");
    fclose(ViewBugFile);

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