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
void Write_Logs(char T_username[255], char action[20]);

// Global variables
char T_username[255];

void Features_Services()
{
    // integer decleearage
    int FeatureOption;
    // printf("\n%s", T_username);

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
        printf("\n\t\t\t        =         [ 0 ]   EXIT                      =");
        printf("\n\t\t\t        =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n");
        printf("\n\t\t\t  **-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**\n");

        printf("\n\n\t\t\t Please, Make a choice : ");

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

        case 0:
            exit(0);
            break;

        default:
            printf("\n\t\t\twrong input...\n\n");
            break;
        }
    } while (FeatureOption != 0);
}