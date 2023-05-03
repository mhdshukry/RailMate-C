#include <stdio.h>
void support();

char T_username[255];
int main(){
    support();
    return 0;
}

void support()
{
    int support_option;

    printf("\n");
    printf("\t\t\t----------------------[ # ] support  ---------------------------\n");
    printf("\t\t\t-------------------- Support [ %s ] -----------------\n\n",T_username);
    printf("\t\t\t-------------------[ 1 ] Create New Mail Support ---------------------------\n");
    printf("\t\t\t-------------------[ 2 ] View my support mails-----------------------------------\n");
    printf("\t\t\t-------------------[ 3 ] Main menu ------------------------------\n");
    printf("\t\t\t-------------------[ 4 ] Exit -----------------------------------\n\n");

    printf("\t\t\tFeature Option: ");
    scanf("%d", &support_option);

    switch (support_option)
    {
    case 1:
        // TrainList();
        break;
    case 2:
        /* TrainReservation();
         */
        break;
    case 3:
        /* code */
        break;
    case 4:
        /* ReservationHistory();
         */
        break;

    default:
        break;
    }
}