/* Libraries */
#include <stdio.h>

void Register();

int main()
{
    Register();
    return 0;
}

void Register()
{
    printf("Register function\n");
    char firstName[] = "";
    char lastName[] = "";
    char mailAddress[] = "";
    char password[] = "";
    char conformPassword[] = "";
    char address[] = "";
    double phoneNumber;

    FILE *fptr;
    fptr = fopen("program.txt", "w");

    printf("Hey, Warmly welcome to our Train Reservation Systen...!!\n");

    printf("Do you have an account...? \n\n");
    printf("\t 1. Yes\n");
    printf("\t 2. No\n");
    printf("\t 3. Back to Main Menu\n\n\n");

    int loginSelection;

    scanf("%d", &loginSelection);

    switch (loginSelection)
    {
    case 1:
        //login();
        break;
    case 2:

        printf("User Registration form\n\n");

        printf("\t First name:");
        scanf("%s", &firstName);

        printf("\t Last name:");
        scanf("%s", &lastName);

        printf("\t Mail Address:");
        scanf("%s", &mailAddress);

        printf("\t Password:");
        scanf("%s", &password);

        printf("\t Confirm your Password:");
        scanf("%s", &conformPassword);

        printf("\t Address:");
        scanf("%s", &address);

        printf("\t Phone Number:");
        scanf("%lf", &phoneNumber);

        if (fptr == NULL)
        {
            printf("Error!");
            //return 0;
        }

        fprintf(fptr, "%s\n", firstName);
        fprintf(fptr, "%s\n", lastName);
        fprintf(fptr, "%s\n", mailAddress);
        fprintf(fptr, "%s\n", password);
        fprintf(fptr, "%s\n", conformPassword);
        fprintf(fptr, "%s\n", address);
        fprintf(fptr, "%s\n", phoneNumber);

        fclose(fptr);

        break;

    case 3:

        break;

    default:
        printf("Invalid input...\n");
    }
}