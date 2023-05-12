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
int LoginUser();
int CreateUser(void);

void Features_Services();

// Global variables
char T_username[255];

int CreateUser(void)
{
    // creating a FILE variable
    /// FILE *inputf;
    FILE *C_file;
    FILE *R_file;

    // integer variable
    int value;

    // character variable
    char username[255];
    char PassWord[255];
    char PassWordC[255];
    char NameOfUser[255];

    const char returnValue[255];

    // Get username from user and create a new file name as user's username
    // printf("Welcome to TRS-Application...!!");
    printf("\n\n\t\tUnique username, please: ");
    scanf("%s", username);

    R_file = fopen(username, "r");
    if (R_file != NULL)
    {
        printf("\n\t\tUsername already exicts...\n\t\tPlease,Choose another one.");
        CreateUser();
    }
    if (R_file == NULL)
    {
        // open the file in write mode
        C_file = fopen(username, "w");

        if (C_file != NULL)
        {
            // printf("File created successfully!\n");
        }
        else
        {
            printf("Failed to create the file.\n");
            // exit status for OS that an error occured
            exit(0);
        }

        char id[255] = "1";

        // get customer detail
        printf("\tEnter name: ");
        scanf("%s", NameOfUser);

        printf("\tEnter your password: ");
        scanf("%s", PassWord);

        printf("\tAgain Password: ");
        scanf("%s", PassWordC);

        value = strcmp(PassWord, PassWordC);
        if (value == 0)
        {

            fprintf(C_file, "%s %s %s %s\n", id, username, NameOfUser, PassWord);
            fclose(C_file);
            strcat(returnValue, username);
            strcpy(T_username, username);
        }

        else
        {
            printf("\tPasswords doesn't match...\n");

            printf("\tEnter your password: ");
            scanf("%s", PassWord);

            printf("\tAgain Password: ");
            scanf("%s", PassWordC);
            value = strcmp(PassWord, PassWordC);
            if (value == 0)
            {
                fprintf(C_file, "%s %s %s %s\n", id, T_username, NameOfUser, PassWord);
                fclose(C_file);
                strcat(returnValue, T_username);
                strcpy(T_username, username);
            }
            else
            {
                printf("Passwords doesn't match...\n");
                printf("Try again later...\n");
                strcat(returnValue, "null");
                strcpy(T_username, username);
            }
        }

        // close connection
        fclose(C_file);
        fclose(R_file);
    }
    Features_Services();
    strcpy(T_username, username);
    return returnValue;
}

int LoginUser()
{
    // creating a FILE variable
    /// FILE *inputf;
    FILE *F_login;

    char *P_username;

    // char T_username[255];
    char l_name[255];
    char l_userID[255];
    char l_Password[255];

    char PassWordFromUser[255];

    char AccountCreateOption[2];

    int value;

    printf("\n\n\t\t\tEnter your username: ");
    scanf("%s", T_username);

    P_username = T_username;

    F_login = fopen(T_username, "r");

    if (F_login != NULL)
    {
        // display detail
        fscanf(F_login, "%s %s %s %[^\n]s", l_userID, &T_username, &l_name, &l_Password);
        // printf("\tUserID: %s\n", r_userID);
        // printf("\tUsername: %s\n", r_username);
        printf("\t\t Hello %s\n", l_name);
        // printf("\tPassword: %s\n", l_Password);

        printf("\t\tEnter your password: ");
        scanf("%s", PassWordFromUser);

        value = strcmp(l_Password, PassWordFromUser);
        if (value == 0)
        {
            printf("\t\tYou have successfully loggedin");

            return T_username;
        }
        else
        {
            printf("\t\tyour password is wrong...\n");
            printf("\t\ttry again...\n");

            printf("\t\tEnter your password: ");
            scanf("%s", PassWordFromUser);

            value = strcmp(l_Password, PassWordFromUser);
            if (value == 0)
            {
                printf("\t\tYou have successfully loggedin");

                return T_username;
            }
            else
            {
                return "null";
            }
        }
    }
    else
    {
        printf("There are no exicting user...\n");
        printf("do you want to create an account..? [ Y / N ] : ");
        scanf("%s", AccountCreateOption);

        int vallue;
        value = strcmp(AccountCreateOption, 'Y');
        if (value == 0)
        {
            CreateUser();
        }
        else
        {
            // exit status for OS that an error occured
            printf("Existing Services....\n");
            exit(0);
        }
    }
    fclose(F_login);

    // Features_Services(T_username);
}