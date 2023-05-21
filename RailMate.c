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
#include "viewmyhistory.c"
#include "continue_function.c"
#include "admin.c"

// constants for size of char arrays to store filename, the line from the file
#define FILENAME_SIZE 1024
#define MAX_LINE 2048

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

// 17.05.2023.2.12.20
void view_trainreservation();
void view_logs_history();
void viewmyhistory();

void Parcel();
void view_details_parcel(char start[], char finish[], float parcelcost, float parcel_weight, float unit_price);
void view_parcel_history();
void calculate_price_parcel_reservation();

// 20.05.2023.1.08.49
void continue_function();
void continue_admin_function();
void ticket_cancel();

void view_admin_trainreservation();
void view_admin_logs_history();
void view_admin_supports();
void view_admin_bugs();

// Global variables
char T_username[255];
int l_r_status;
int i;
char username[255];

void welcomeMessage()
{
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

    printf("\n\t\t\t  ---------------------------------------------------------\n");
    File_Availability("db_train_details.txt");
    File_Availability("db_pricelist.txt");
    File_Availability("db_bugs.txt");
    File_Availability("db_supports.txt");
    File_Availability("db_parcel.txt");
    File_Availability("db_logs.txt");
    printf("\t\t\t  ---------------------------------------------------------\n\n");

    welcomeMessage();

    // declaration of local variable op;
    int op;
    char loginstatus[255];

    do
    {
        printf("\n\t\t\t        =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=");
        printf("\n\t\t\t        =         [ 1 ]   LOGIN                     =");
        printf("\n\t\t\t        =         [ 2 ]   REGISTER                  =");
        printf("\n\t\t\t        =         [ 3 ]   ADMIN                     =");
        printf("\n\t\t\t        =         [ 0 ]   EXIT                      =");
        printf("\n\t\t\t        =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n");
        printf("\n\t\t\t  **-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**\n");

        printf("\n\t\t\t  ---------------------------------------------------------\n");
        printf("\t\t\t                PLEASE, MAKE A CHOISE : ");
        scanf("%d", &op);
        printf("\t\t\t  ---------------------------------------------------------\n");

        // use switch statement to call an operation
        switch (op)
        {
        case 1:
            if (LoginUser() == 0)
            {
                LoginUser();
            }
            else
            {
                Features_Services();
            }

            break; // break the function

        case 2:
            if (l_r_status == 0)
            {
                CreateUser();
            }
            else
            {
                Features_Services();
            }
            break;

        case 3:
            if (admin_login() == 0)
            {
                admin_login();
            }
            else
            {
                admin();
            }
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
            printf("\n\t\t\t                         TRY AGAIN                    ");
            printf("\n\t\t\t  ---------------------------------------------------------\n");
            break;
        }
    } while (op != 0);
    return 0;
}