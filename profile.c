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
void Features_Services();
void Profile(char T_username[]);
char EditPersonalDetails(char T_username[]);
void ViewUser(char T_username[]);
void Write_Logs(char T_username[255], char action[20]);
void view_trainreservation();
void view_logs_history();
void viewmyhistory();

// Global variables
char T_username[255];

void ViewUser(char T_username[])
{
    // open file for reading
    FILE *view_profile = fopen(T_username, "r");

    char profile_username[255];
    char profile_name[255];
    char profile_password[255];
    char profile_id[255];

    // display detail
    printf("\t\t\t Details:\n");
    fscanf(view_profile, "%s %s %s %[^\n]s", profile_id, profile_username, profile_name, profile_password);
    printf("\t\t\t---------------------------------------------------------------\n");
    printf("\t\t\t USER ID :-----------------: %s\n", profile_id);
    printf("\t\t\t USERNAME :----------------: %s\n", profile_username);
    printf("\t\t\t NAME :--------------------: %s\n", profile_name);
    printf("\t\t\t PASSWORD :----------------: %s\n", profile_password);
    printf("\t\t\t---------------------------------------------------------------\n");
    Write_Logs(T_username, "View - User");
    // close connection
    fclose(view_profile);
    Features_Services();
}

void Profile(char T_username[])
{
    int ProfileOption;

    do
    {
        printf("\n\n\n");
        printf("\n\t\t\t  **-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**\n");
        printf("\n\t\t\t        =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=");
        printf("\n\t\t\t        =         [ 1 ]   VIEW DETAILS              =");
        printf("\n\t\t\t        =         [ 2 ]   EDIT PROFILE              =");
        printf("\n\t\t\t        =         [ 3 ]   VIEW RESERVATION HISTORY  =");
        printf("\n\t\t\t        =         [ 4 ]   MAIN MENU                 =");
        printf("\n\t\t\t        =         [ 0 ]   EXIT                      =");
        printf("\n\t\t\t        =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n");
        printf("\n\t\t\t  **-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**\n");

        printf("\n\t\t\t  ---------------------------------------------------------\n");
        printf("\t\t\t                PLEASE, MAKE A CHOISE : ");
        scanf("%d", &ProfileOption);
        printf("\n\t\t\t  ---------------------------------------------------------\n");

        switch (ProfileOption)
        {
        case 1:
            ViewUser(T_username);
            break;
        case 2:
            EditPersonalDetails(T_username);
            break;
        case 3:
            viewmyhistory();
            break;
        case 4:
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
    } while (ProfileOption != 5);
}

char EditPersonalDetails(char T_username[])
{
    // open the file in read mode
    FILE *edit_profile = fopen(T_username, "r");

    // integer variable
    int value;

    // character variable
    // char EP_username[255];
    char EP_password[255];
    char EP_password_r[255];
    char EP_name[255];

    printf("\n\t\t\t  ---------------------------------------------------------\n");
    printf("\t\t\t                         EDIT PERSONAL                       ");
    printf("\n\t\t\t  ---------------------------------------------------------\n");

    if (edit_profile != NULL)
    {
        edit_profile = fopen(T_username, "w");
        char id[255] = "1";

        // get customer detail

        printf("\n\t\t\t  ---------------------------------------------------------\n");
        printf("\t\t\t                     NAME: ");
        scanf("%s", EP_name);
        printf("\t\t\t  ---------------------------------------------------------\n");

        printf("\n\t\t\t  ---------------------------------------------------------\n");
        printf("\t\t\t                     PASSWORD: ");
        scanf("%s", EP_password);
        printf("\t\t\t  ---------------------------------------------------------\n");

        printf("\n\t\t\t  ---------------------------------------------------------\n");
        printf("\t\t\t                     AGAIN PASSWORD: ");
        scanf("%s", EP_password_r);
        printf("\t\t\t  ---------------------------------------------------------\n");

        value = strcmp(EP_password, EP_password_r);
        if (value == 0)
        {
            fprintf(edit_profile, "%s %s %s %s\n", id, T_username, EP_name, EP_password);
            Write_Logs(T_username, "Edit - Profile");
        }

        else
        {
            printf("\n\t\t\t  ---------------------------------------------------------\n");
            printf("\t\t\t                         PASSWORD DOESN'T MATCH                       ");
            printf("\n\t\t\t  ---------------------------------------------------------\n");

            printf("\n\t\t\t  ---------------------------------------------------------\n");
            printf("\t\t\t                     PASSWORD: ");
            scanf("%s", EP_password);
            printf("\t\t\t  ---------------------------------------------------------\n");

            printf("\n\t\t\t  ---------------------------------------------------------\n");
            printf("\t\t\t                     AGAIN PASSWORD: ");
            scanf("%s", EP_password_r);
            printf("\t\t\t  ---------------------------------------------------------\n");

            value = strcmp(EP_password, EP_password_r);
            if (value == 0)
            {
                fprintf(edit_profile, "%s %s %s %s\n", id, T_username, EP_name, EP_password);
                Write_Logs(T_username, "Edit - Profile");
            }
            else
            {
                printf("\n\t\t\t  ---------------------------------------------------------\n");
                printf("\t\t\t                         PASSWORD DOESN'T MATCH                ");
                printf("\t\t\t                                TRY AGAIN                      ");
                printf("\n\t\t\t  ---------------------------------------------------------\n");
                Features_Services();
            }
        }

        // close connection
        fclose(edit_profile);
    }
    else
    {

        printf("\n\t\t\t  ---------------------------------------------------------\n");
        printf("\t\t\t                         FILE MISSING                       ");
        printf("\t\t\t                            EXITING...                      ");
        printf("\n\t\t\t  ---------------------------------------------------------\n");
        Features_Services();
        exit(0);
    }
}