/* Libraries */
#include <stdio.h>

int MainView();

int main()
{
    MainView();
    return 0;
}

int MainView() 
{
    int userDashMenu;
    printf("\n\n\n");
    printf("\t-------------------------------------------------------------------------------------\n");
    printf("\t\t---------------------- Welcome To - RailMate Lanka ------------------\n");
    printf("\t\t------------------- Advanved online reservation system --------------\n");
    printf("\t-------------------------------------------------------------------------------------\n\n\n");

    printf("\t\t------------------------------ Menu ---------------------------------\n\n");
    printf("\t\t\t-------------------[ 1 ] Login -------------------\n");
    printf("\t\t\t-------------------[ 2 ] Register ----------------\n");
    printf("\t\t\t-------------------[ 0 ] Exit --------------------\n\n");

    printf("\tOption: ");
    scanf("%d",&userDashMenu);
do
{
    switch (userDashMenu)
    {
    case 1:
        /* LoginFunction */
        break;

    case 2:
        /* Register Function */
        break;

    case 0:
        printf("\n\tExit\n\n\n");
        return 0;

    default:
        printf("\tinvalid number\n");
        printf("\tOption: ");
        scanf("%d", &userDashMenu);
        break;
    }
} while (userDashMenu != 0);
}