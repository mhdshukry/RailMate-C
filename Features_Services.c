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



void Features_Services()
{
    // integer decleearage
    int FeatureOption;
    // printf("\n%s", T_username);

    printf("\n");
    printf("\t\t\t-------------------- Welcome Back [ %s ] -----------------\n\n", T_username);
    printf("\t\t\t-------------------[ 1 ] Trains List & Prices  -----------------\n");
    printf("\t\t\t-------------------[ 2 ] Train Seat Reservation ----------------\n");
    printf("\t\t\t-------------------[ 3 ] Parcel Services -----------------------\n");
    printf("\t\t\t-------------------[ 4 ] View My History -----------------------\n");
    printf("\t\t\t-------------------[ 5 ] Profile -------------------------------\n");
    printf("\t\t\t-------------------[ 6 ] Supports and News ---------------------\n");
    printf("\t\t\t-------------------[ 7 ] Report a Bug ---------------------\n");
    printf("\t\t\t-------------------[ 8 ] Exit ----------------------------------\n\n");

    printf("\t\t\tFeature Option: ");
    scanf("%d", &FeatureOption);

    switch (FeatureOption)
    {
    case 1:
        TrainPriceCalculation();
        break;
    case 2:
        TrainReservation();
        break;
    case 3:
        /* code */
        break;
    case 4:
        /* ReservationHistory();
         */
        break;
    case 5:
        Profile(T_username);
        break;
    case 6:
        support();
        break;

    case 7:
        Bugs();
        break;
    case 8:
        exit(0);
        break;

    default:
        break;
    }
}