/* Libraries */
#include <stdio.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>
#include <stdbool.h>

// files and functions
#include "file_availability.c"
#include "TrainReservation.c"
#include "supports.c"
#include "bugs.c"
#include "user.c"
#include "profile.c"
#include "services.c"
#include "parcelservices.c"
#include "write_logs.c"

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

// 12.05.2023.2.23.19
void Parcel();
void Write_Logs(char T_username[255], char action[20]);

// Global variables
char T_username[255];

void welcomeMessage()
{
    printf("\n\n\n\n\n");
    printf("\n\t\t\t  **-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**\n");
    printf("\n\t\t\t        =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=");
    printf("\n\t\t\t        =                 WELCOME                   =");
    printf("\n\t\t\t        =                   TO                      =");
    printf("\n\t\t\t        =                RAILMATE                   =");
    printf("\n\t\t\t        =          TICKET - RESERVATION             =");
    printf("\n\t\t\t        =                 SYSTEM                    =");
    printf("\n\t\t\t        =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n");
}
int main()
{
    printf("\n\n");
    File_Availability("TrainsDetails.txt");
    File_Availability("dp_pricelist.txt");
    File_Availability("bugs.txt");
    File_Availability("supports.txt");
    File_Availability("dp_parcel.txt");
    File_Availability("dp_logs.txt");

    welcomeMessage();

    // declaration of local variable op;
    int op;
    char loginstatus[255];

    do
    {
        printf("\n\t\t\t        =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=");
        printf("\n\t\t\t        =         [ 1 ]   LOGIN                     =");
        printf("\n\t\t\t        =         [ 2 ]   REGISTER                  =");
        printf("\n\t\t\t        =         [ 0 ]   EXIT                      =");
        printf("\n\t\t\t        =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n");
        printf("\n\t\t\t  **-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**\n");

        printf("\n\n\t\t\t Please, Make a choice : ");
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
            printf("\n\n\t\t\tYou chose: Exit");
            exit(0);
            break;

        default:
            printf("\n\n\t\t\tSomething is wrong!! ");
            break;
        }
    } while (op != 0);
    return 0;
}