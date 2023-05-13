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

void Write_Logs(char T_username[255], char action[20]);

// Global variables
char T_username[255];
int l_r_status;

int CreateUser(void)
{

    // integer variable
    int value;

    char create_password[255];
    char create_password_verify[255];
    char nameofuser[255];

    const char returnValue[255];

    // Get username from user and create a new file name as user's username
    // printf("Welcome to TRS-Application...!!");
    printf("\n\n\t\\ttUnique username, please: ");
    scanf("%s", T_username);

    // open file for reading
    FILE *read_file = fopen(T_username, "r");
    FILE *create_user = fopen(T_username, "w");

    if (read_file != NULL)
    {
        printf("\n\t\t\tUsername already exicts...\n\t\tPlease,Choose another one.");
        CreateUser();
    }
    if (read_file == NULL)
    {

        if (create_user != NULL)
        {
            // printf("File created successfully!\n");
        }
        else
        {
            printf("\t\t\tFailed to create the file.\n");
            // exit status for OS that an error occured
            exit(0);
        }

        char id[255] = "1";

        // get customer detail
        printf("\t\t\tEnter name: ");
        scanf("%s", nameofuser);

        printf("\t\t\tEnter your password: ");
        scanf("%s", create_password);

        printf("\t\t\tAgain Password: ");
        scanf("%s", create_password_verify);

        value = strcmp(create_password, create_password_verify);
        if (value == 0)
        {

            fprintf(create_user, "%s %s %s %s\n", id, T_username, nameofuser, create_password);
            fclose(create_user);
            l_r_status = 1;
            Write_Logs(T_username, "user - register");
        }

        else
        {
            printf("\t\t\tPasswords doesn't match...\n");

            printf("\t\t\tEnter your password: ");
            scanf("%s", create_password);

            printf("\t\t\tAgain Password: ");
            scanf("%s", create_password_verify);
            value = strcmp(create_password, create_password_verify);
            if (value == 0)
            {
                fprintf(create_user, "%s %s %s %s\n", id, T_username, nameofuser, create_password);
                fclose(create_user);
                l_r_status = 1;
                Write_Logs(T_username, "user - register");
            }
            else
            {
                printf("\t\t\tPasswords doesn't match...\n");
                printf("\t\t\tTry again later...\n");
                l_r_status = 0;
            }
        }

        // close connection
        fclose(create_user);
        fclose(read_file);
    }
    Features_Services();
    return l_r_status;
}

int LoginUser()
{
    char l_name[255];
    char l_userID[255];
    char l_Password[255];

    char PassWordFromUser[255];

    char AccountCreateOption[2];

    int value;

    printf("\n\t\t\t  ---------------------------------------------------------\n");
    printf("\t\t\t                    ENTER YOUR USERNAME : ");
    scanf("%s", T_username);
    printf("\t\t\t  -----------------------------------------------------------\n");

    FILE *login_file = fopen(T_username, "r");

    if (login_file != NULL)
    {
        // display detail
        fscanf(login_file, "%s %s %s %[^\n]s", l_userID, T_username, l_name, l_Password);

        printf("\n\n\n");
        printf("\n\t\t\t  **-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**\n");
        printf("\n\t\t\t                     HELLO %s      ", l_name);
        printf("\n\t\t\t  ---------------------------------------------------------\n");
        printf("\t\t\t                     PASSWORD: ");
        scanf("%s", PassWordFromUser);
        printf("\n\t\t\t  **-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**\n");

        value = strcmp(l_Password, PassWordFromUser);
        if (value == 0)
        {
            printf("\n\t\t\t  ---------------------------------------------------------\n");
            printf("\t\t\t                YOU HAVE SUCCESSFULLY LOGGED-IN               ");
            printf("\n\t\t\t  ---------------------------------------------------------\n");
            Write_Logs(T_username, "user - login");
            l_r_status = 1;
        }
        else
        {

            printf("\n\t\t\t  ---------------------------------------------------------\n");
            printf("\t\t\t                         PASSWORD WRONG                      ");
            printf("\t\t\t                            TRY AGAIN                        ");
            printf("\n\t\t\t  ---------------------------------------------------------\n");

            printf("\n\t\t\t  ---------------------------------------------------------\n");
            printf("\t\t\t                     PASSWORD: ");
            scanf("%s", PassWordFromUser);
            printf("\t\t\t  ---------------------------------------------------------\n");

            value = strcmp(l_Password, PassWordFromUser);
            if (value == 0)
            {
                printf("\n\t\t\t  ---------------------------------------------------------\n");
                printf("\t\t\t                YOU HAVE SUCCESSFULLY LOGGED-IN               ");
                printf("\n\t\t\t  ---------------------------------------------------------\n");
                Write_Logs(T_username, "user - login");
                l_r_status = 1;
            }
            else
            {
                l_r_status = 0;
            }
        }
    }
    else
    {
        printf("\n\n\t\t\tThere are no exicting user...\n");
        printf("\n\t\t\tdo you want to create an account..? [ Y / N ] : ");
        scanf("%c", AccountCreateOption);

        printf("\n\t\t\t  ---------------------------------------------------------\n");
        printf("\t\t\t                   THERE'RE NO EXITING USERS                  ");
        printf("\n\t\t\t  ---------------------------------------------------------\n");

        printf("\n\t\t\t  ---------------------------------------------------------\n");
        printf("\t\t\t                DO YOU WANT TO CREATE AN ACCOUNT:            ");
        scanf("%c", AccountCreateOption);
        printf("\t\t\t  ---------------------------------------------------------\n");

        int vallue;
        value = strcmp(AccountCreateOption, "Y");
        if (value == 0)
        {
            CreateUser();
        }
        else
        {
            // exit status for OS that an error occured
            printf("\n\t\t\t  ---------------------------------------------------------\n");
            printf("\t\t\t                         EXITING SERVICES                    ");
            printf("\n\t\t\t  ---------------------------------------------------------\n");
            exit(0);
        }
    }
    fclose(login_file);

    return l_r_status;

    // Features_Services(T_username);
}