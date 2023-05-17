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

/* Functions */
// 03.05.2023.2.19.49
void support();
void NewMail();
void ViewSupport(void);


void Write_Logs(char T_username[255], char action[20]);

// Global variables
char T_username[255]; // constants for size of char arrays to store filename, the line from the file
#define FILENAME_SIZE 1024
#define MAX_LINE 2048

#define MAX_LENGTH 255
#define NUM_STRINGS 20

/* Functions */
int LoginUser();
int CreateUser(void);

void Features_Services();

// 03.05.2023.2.19.49
void support();
void NewMail();
void ViewSupport(void);


// Global variables
char T_username[255];

void support()
{
    int support_option;
    printf("\n\n\n");
    printf("\n\t\t\t  **-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**\n");
    printf("\n\t\t\t        =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=");
    printf("\n\t\t\t        =         [ 1 ]   CREATE NEW SUPPORT        =");
    printf("\n\t\t\t        =         [ 2 ]   VIEW SUPPORT MAILS        =");
    printf("\n\t\t\t        =         [ 3 ]   MAIN MENU                 =");
    printf("\n\t\t\t        =         [ 0 ]   EXIT                      =");
    printf("\n\t\t\t        =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n");
    printf("\n\t\t\t  **-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**\n");

    printf("\n\t\t\t  ---------------------------------------------------------\n");
    printf("\t\t\t                PLEASE, MAKE A CHOISE : ");
    scanf("%d", &support_option);
    printf("\n\t\t\t  ---------------------------------------------------------\n");

    switch (support_option)
    {
    case 1:
        NewMail();
        break;
    case 2:
        ViewSupport();
        break;
    case 3:
        Features_Services();
        break;
    case 4:
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

void NewMail()
{
    FILE *MailFile;
    char content[3000], c;
    int index = 0;

    char heading[3000], c1;
    int index1 = 0;

    int no = 1;

    // Time
    time_t rawtime;
    struct tm *timeinfo;

    time(&rawtime);
    timeinfo = localtime(&rawtime);
    // printf("Current local time and date: %s", asctime(timeinfo));

    MailFile = fopen("db_supports.txt", "a");

    if (MailFile == NULL)
    {
        printf("\n\t\t\t  ---------------------------------------------------------\n");
        printf("\t\t\t                         FILE MISSING                          ");
        printf("\n\t\t\t  ---------------------------------------------------------\n");
        exit(0);
    }
    else
    {
        char mailaddress[3000], c2;
        int index2 = 0;

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

        fprintf(MailFile, "Mail support no. %d \n\tRequesting person name: %s \nMail address: %s \nHeading: %s \nContent: %s \n\tTime: %s", no, T_username, mailaddress, heading, content, asctime(timeinfo));
        fprintf(MailFile, "---------------------------------------------------------------\n\n\n");
        Write_Logs(T_username, "New - Support - Mail");

        fclose(MailFile);

        char yesorno[2];
        printf("\n\t\t\t  ---------------------------------------------------------\n");
        printf("\t\t\t          DO YOU WANT TOO CONTINUE [TYPE 'YES' OR 'NO']        ");
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

void ViewSupport()
{
    char *filename = "db_supports.txt";
    FILE *ViewFile = fopen(filename, "r");

    if (ViewFile == NULL)
    {
        printf("\n\t\t\t  ---------------------------------------------------------\n");
        printf("\t\t\t                 ERROR: CLOUD NOT OPEN FILE                    ");
        printf("\n\t\t\t  ---------------------------------------------------------\n");
        exit(0);
    }

    // read one character at a time and
    // display it to the output
    char ch;
    while ((ch = fgetc(ViewFile)) != EOF)
        putchar(ch);

    Write_Logs(T_username, "View - Support - Mail");
    // close the file
    fclose(ViewFile);

    char yesorno[20];
    printf("\n\t\t\t  ---------------------------------------------------------\n");
    printf("\t\t\t          DO YOU WANT TOO CONTINUE [TYPE 'Y' OR 'N'] ");
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