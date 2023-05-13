#include <stdio.h>

void Features_Services();
void Write_Logs(char T_username[255], char action[20]);

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

        printf("\n\t\t\t  ---------------------------------------------------------\n");
        printf("\t\t\t                PLEASE, MAKE A CHOISE : ");
        scanf("%d", &parceloption);
        printf("\t\t\t  ---------------------------------------------------------\n");

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
            printf("\n\t\t\t  ---------------------------------------------------------\n");
            printf("\t\t\t                         EXITING SERVICES                    ");
            printf("\n\t\t\t  ---------------------------------------------------------\n");
            exit(0);
            break;

        default:
            printf("\n\t\t\t  ---------------------------------------------------------\n");
            printf("\t\t\t                         WRONG INPUT                    ");
            printf("\t\t\t                         TRY AGAIN                    ");
            printf("\n\t\t\t  ---------------------------------------------------------\n");
            break;
        }
    } while (parceloption != 5);
}