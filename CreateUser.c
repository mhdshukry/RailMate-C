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

int CreateUser(void)
{
    // creating a FILE variable
    /// FILE *inputf;
    FILE *C_file;
    FILE *R_file;

    // integer variable
    int value;

    // character variable
    char T_username[255];
    char PassWord[255];
    char PassWordC[255];
    char NameOfUser[255];

    // Get username from user and create a new file name as user's username
    // printf("Welcome to TRS-Application...!!");
    printf("\n\n\t\tUnique username, please: ");
    scanf("%s", T_username);

    R_file = fopen(T_username, "r");
    if (R_file != NULL)
    {
        printf("\n\t\tUsername already exicts...\n\t\tPlease,Choose another one.");
        CreateUser();
    }
    if (R_file == NULL)
    {
        // open the file in write mode
        C_file = fopen(T_username, "w");

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

        char id[255] = "TRS_UR_001";

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

            fprintf(C_file, "%s %s %s %s\n", id, T_username, NameOfUser, PassWord);
            return T_username;
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
                RegisterStatus = 1;
                return T_username;
            }
            else
            {
                printf("Passwords doesn't match...\n");
                printf("Try again later...\n");
                return "null";
            }
        }

        // close connection
        fclose(C_file);
        fclose(R_file);
        return 0;
    }
}
