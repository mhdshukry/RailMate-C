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

void Features_Services();

// Global variables
char T_username[255];

void Features_Services()
{
    // integer decleearage
    int FeatureOption;
    // printf("\n%s", T_username);

    do
    {

        printf("\n");
        printf("\t\t\t-------------------- Welcome Back [ %s ] -----------------\n\n", T_username);
        printf("\t\t\t-------------------[ 1 ] Trains List & Prices  -----------------\n");
        printf("\t\t\t-------------------[ 2 ] Train Seat Reservation ----------------\n");
        printf("\t\t\t-------------------[ 3 ] View My History -----------------------\n");
        printf("\t\t\t-------------------[ 4 ] Profile -------------------------------\n");
        printf("\t\t\t-------------------[ 5 ] Supports and News ---------------------\n");
        printf("\t\t\t-------------------[ 6 ] Report a Bug ---------------------\n");
        printf("\t\t\t-------------------[ 7 ] Exit ----------------------------------\n\n");

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
            Profile(T_username);
            break;
        case 5:
            support();
            break;
        case 6:
            Bugs();
            break;

        case 7:
            exit(0);
            break;

        default:
            printf("wrong input...");
            break;
        }
    } while (FeatureOption != 7);
}