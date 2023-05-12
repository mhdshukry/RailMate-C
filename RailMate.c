/* Libraries */
#include <stdio.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>
#include <stdbool.h>

// files and functions
#include "TrainReservation.c"
#include "supports.c"
#include "bugs.c"
#include "user.c"
#include "profile.c"
#include "services.c"
#include "file_availability.c"

// constants for size of char arrays to store filename, the line from the file
#define FILENAME_SIZE 1024
#define MAX_LINE 2048

#define MAX_LENGTH 255
#define NUM_STRINGS 20

/* Functions */
int LoginUser();
int CreateUser(void);

void Features_Services();

void ViewReservation();
void Reservation();

void Profile(char T_username[]);
char EditPersonalDetails(char T_username[]);
void ViewUser(char T_username[]);

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

int main()
{
    printf("\n\n");
    File_Availability("TrainsDetails.txt");
    File_Availability("dp_pricelist.txt");
    File_Availability("bugs.txt");
    File_Availability("supports.txt");

    // declaration of local variable op;
    int op;
    char loginstatus[255];

    do
    {
        // welcome message
        printf("\n\n\n");
        printf("\t-------------------------------------------------------------------------------------\n");
        printf("\t\t---------------------- Welcome To - RailMate Lanka ------------------\n");
        printf("\t\t------------------- Advanved online reservation system --------------\n");
        printf("\t-------------------------------------------------------------------------------------\n\n\n");

        printf("\t\t\t-------------------[ 1 ] Login -------------------\n");
        printf("\t\t\t-------------------[ 2 ] Register ----------------\n");
        printf("\t\t\t-------------------[ 0 ] Exit --------------------\n\n");

        printf("\n\n\t\t Please, Make a choice : ");
        scanf("%d", &op); // accepts a numeric input to choose the operation

        // use switch statement to call an operation
        switch (op)
        {
        case 1:
            if (LoginUser() != "null")
            {
                Features_Services();
            }

            break; // break the function

        case 2:
            if (CreateUser() != "null")
            {
                Features_Services();
            }
            break;
        case 0:
            printf(" You chose: Exit");
            exit(0);
            break;

        default:
            printf(" Something is wrong!! ");
            break;
        }
        printf(" \n \n ---------------------------- \n \n");
    } while (op != 7);
    return 0;
}