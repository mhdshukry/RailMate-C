#include <stdio.h>

void TrainList();
int PriceCalculation(int S_Station, int E_Station, int S_Class,int Person);
int main()
{
    TrainList();
    return 0;
}

int PriceCalculation(int S_Station, int E_Station, int S_Class,int Person){
    float FirstClassTicket = 3200;
    float SecondClassTicket = 1800;
    float ThirdClassTicket = 600;

    float Ticket,ClassCost;

    switch (S_Class)
    {
    case 1:
        ClassCost = FirstClassTicket;
         break;

    case 2:
         ClassCost = SecondClassTicket;
         break;

    case 3:
         ClassCost = ThirdClassTicket;
         break;

    default:
        break;
    }

    //if (S_Station == 1 && E_Station == 2){
        Ticket = Person * ClassCost;
    //}
    return Ticket;
}

    void TrainList()
{
    // Integer
    int S_Station, E_Station, S_Class,Person;
    float Ticket;

    printf("\n");
    printf("\n");
    printf("\t\t [1] Jaffna \t [2] Vavuniya \t [3] Mannar \t [4] Kandy \t [5] Colombo \n");
    printf("\n");
    printf("\t\t [1] Jaffna \t [2] Vavuniya \t [3] Mannar \t [4] Kandy \t [5] Colombo \n");
    printf("\n");
    printf("\t\t [1] Jaffna \t [2] Vavuniya \t [3] Mannar \t [4] Kandy \t [5] Colombo \n");
    printf("\n");
    printf("\t\t [1] Jaffna \t [2] Vavuniya \t [3] Mannar \t [4] Kandy \t [5] Colombo \n");
    printf("\n");
    printf("\n");

    printf("\t\t Starting station: ");
    scanf("%s", &S_Station);

    printf("\t\t Ending station: ");
    scanf("%s", &E_Station);

    printf("\n");
    printf("\n");
    printf("\t\tSelect class\n");
    printf("\n");
    printf("\t\t[1] First Class \t [2] Second Class \t [3] Third Class \n");

    printf("\n");

    printf("\t\tOption: ");
    scanf("%d", &S_Class);

    printf("\n");
    printf("\n");
    printf("\t\tHow much tickets: ");
    scanf("%d", &Person);

    printf("\n");
    printf("\n");

    Ticket = PriceCalculation(S_Station,E_Station,S_Class,Person);
    printf("\n Ticket: %0.2lf ", Ticket);
}