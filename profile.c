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

// Global variables
char T_username[255];

void ViewUser(char T_username[])
{
    // creating a FILE variable
    /// FILE *inputf;
    FILE *inputf;
    // reading section

    char r_username[255];
    char r_Name[255];
    char r_Password[255];
    char r_userID[255];

    // open file for reading
    inputf = fopen(T_username, "r");

    // display detail
    printf("\t\t\t Details:\n");
    fscanf(inputf, "%s %s %s %[^\n]s", r_userID, &r_username, &r_Name, &r_Password);
    printf("\t\t\t---------------------------------------------------------------\n");
    printf("\t\t\tUserID: %s\n", r_userID);
    printf("\t\t\t---------------------------------------------------------------\n");
    printf("\t\t\tUsername: %s\n", r_username);
    printf("\t\t\t---------------------------------------------------------------\n");
    printf("\t\t\tName: %s\n", r_Name);
    printf("\t\t\t---------------------------------------------------------------\n");
    printf("\t\t\tPassword: %s\n", r_Password);
    printf("\t\t\t---------------------------------------------------------------\n");
    Write_Logs(T_username, "View - User");
    // close connection
    fclose(inputf);
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

        printf("\n\n\t\t\t Please, Make a choice : ");

        scanf("%d", &ProfileOption);

        switch (ProfileOption)
        {
        case 1:
            ViewUser(T_username);
            break;
        case 2:
            EditPersonalDetails(T_username);
            break;
        case 3:
            /* code */
            break;
        case 4:
            Features_Services();
            break;
        case 0:
            exit(0);
            break;

        default:
            printf("wrong input...\n");
            break;
        }
    } while (ProfileOption != 5);
}

char EditPersonalDetails(char T_username[])
{

    // creating a FILE variable
    /// FILE *inputf;
    FILE *file;

    // integer variable
    int value;

    // character variable
    // char EP_username[255];
    char EP_password[255];
    char EP_password_r[255];
    char EP_name[255];

    // Get username from user and create a new file name as user's username
    printf("Welcome to TRS-Application...!!");

    // open the file in read mode
    file = fopen(T_username, "r");

    if (file != NULL)
    {
        file = fopen(T_username, "w");
        char id[255] = "TRS_UR_001";

        // get customer detail
        printf("\tEnter name: ");
        scanf("%s", EP_name);

        printf("\tEnter your password: ");
        scanf("%s", EP_password);

        printf("\tAgain Password: ");
        scanf("%s", EP_password_r);

        value = strcmp(EP_password, EP_password_r);
        if (value == 0)
        {
            fprintf(file, "%s %s %s %s\n", id, T_username, EP_name, EP_password);
            Write_Logs(T_username, "Edit - Profile");
        }

        else
        {
            printf("\tPasswords doesn't match...\n");

            printf("\tEnter your password: ");
            scanf("%s", EP_password);

            printf("\tAgain Password: ");
            scanf("%s", EP_password_r);
            value = strcmp(EP_password, EP_password_r);
            if (value == 0)
            {
                fprintf(file, "%s %s %s %s\n", id, T_username, EP_name, EP_password);
            }
            else
            {
                printf("Passwords doesn't match...\n");
                printf("Try again later...\n");
                Features_Services();
            }
        }

        // close connection
        fclose(file);
    }
    else
    {
        printf("issue on system.\n");
        // exit status for OS that an error occured
        exit(0);
    }
}