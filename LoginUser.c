/* Libraries */
#include <stdio.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>
#include <stdbool.h>



// constants for size of char arrays to store filename, the line from the file
#define FILENAME_SIZE 1024
#define MAX_LINE 2048

/* Functions */
void ViewUser(char T_username[]);
int LoginUser();
int CreateUser(void);
void Features_Services();
void ViewReservation();
void Reservation();
void Profile(char T_username[]);
char EditPersonalDetails(char T_username[]);
void TrainList();

// 03.05.2023.2.19.49
void support();
void NewMail();
void ViewSupport(void);

// 03.05.2023.2.20.29
void Bugs();
void NewBugs();
void BugsView();

// 08.05.2023.2.16.35
void TrainList();
int TrainPriceCalculation();
void TrainReservation();

// Global variables
char T_username[255];
char LoginStatus[255];
int RegisterStatus;


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

        if (AccountCreateOption == 'Y')
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