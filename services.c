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
int main();
void viewmyhistory();

// Global variables
char T_username[255];

void Features_Services()
{
    // integer decleearage
    int FeatureOption;
    // printf("\n%s", T_username);

    if (l_r_status == 0)
    {
        main();
    }

    do
    {
        printf("\n\n\n");
        printf("\n\t\t\t  **-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**\n");
        printf("\n\t\t\t        =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=");
        printf("\n\t\t\t        =         [ 1 ]   TRAIN LIST & PRICE        =");
        printf("\n\t\t\t        =         [ 2 ]   TRAIN SEAT RESERVATION    =");
        printf("\n\t\t\t        =         [ 3 ]   VIEW MY HISTORY           =");
        printf("\n\t\t\t        =         [ 4 ]   PROFILE                   =");
        printf("\n\t\t\t        =         [ 5 ]   SUPPORTS & NEWS           =");
        printf("\n\t\t\t        =         [ 6 ]   REPORT A BUG              =");
        printf("\n\t\t\t        =         [ 7 ]   LOGOUT                    =");
        printf("\n\t\t\t        =         [ 0 ]   EXIT                      =");
        printf("\n\t\t\t        =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n");
        printf("\n\t\t\t  **-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**\n");

        printf("\n\t\t\t  ---------------------------------------------------------\n");
        printf("\t\t\t                PLEASE, MAKE A CHOISE : ");
        scanf("%d", &FeatureOption);
        printf("\n\t\t\t  ---------------------------------------------------------\n");

        switch (FeatureOption)
        {
        case 1:
            TrainPriceCalculation();
            break;
        case 2:
            TrainReservation();
            break;
        case 3:
            viewmyhistory();
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
            l_r_status = 0;
            Features_Services();
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
    } while (FeatureOption != 0);
}