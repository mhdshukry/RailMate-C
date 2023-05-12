#include <stdio.h>

void Features_Services();

// Global variables
char T_username[255];

void Parcel()
{
    int parceloption;

    do
    {
        printf("\n\n\n");
        printf("\n\t\t\t  **-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**\n");
        printf("\n\t\t\t        =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=");
        printf("\n\t\t\t        =         [ 1 ]   PARCEL SERVICE            =");
        printf("\n\t\t\t        =         [ 2 ]   PARCEL HISTORY            =");
        printf("\n\t\t\t        =         [ 3 ]   MAIN MENU                 =");
        printf("\n\t\t\t        =         [ 0 ]   EXIT                      =");
        printf("\n\t\t\t        =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n");
        printf("\n\t\t\t  **-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**\n");

        printf("\n\n\t\t\t Please, Make a choice : ");
        scanf("%d", &parceloption);

        switch (parceloption)
        {
        case 1:
            
            break;
        case 2:
            
            break;
        case 3:
            Features_Services();
            break;
        case 4:
            exit(0);
            break;

        default:
            printf("wrong input...\n");
            break;
        }
    } while (parceloption != 5);
}