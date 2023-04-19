/* Libraries */
#include <stdio.h>

int MainView();
void Login();
void Register();
int Exit();

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
        Login();
        break;

    case 2:
        /* Register Function */
        Register();
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

void Login(){
    printf("login function\n");
    char username[] = "";
    char password []= "";
    Exit();
}

void Register(){
    printf("Register function\n");
    char firstName[]="";
    char lastName[]="";
    char mailAddress[]="";
    char password[]="";
    char conformPassword[]="";
    char address[]="";
    double phoneNumber;

    FILE *fptr;
    fptr = fopen("program.txt","w");

    printf("Hey, Warmly welcome to our Train Reservation Systen...!!\n");

    printf("Do you have an account...? \n\n");
    printf("\t 1. Yes\n");
    printf("\t 2. No\n");
    printf("\t 3. Back to Main Menu\n\n\n");

    int loginSelection;

    scanf("%d",&loginSelection);

    switch(loginSelection){
        case 1:
            login() ;
            break;
        case 2:

printf("User Registration form\n\n");

printf("\t First name:");
scanf("%s",&firstName);

printf("\t Last name:");
scanf("%s",&lastName);

printf("\t Mail Address:");
scanf("%s",&mailAddress);

printf("\t Password:");
scanf("%s",&password);

printf("\t Confirm your Password:");
scanf("%s",&conformPassword);

printf("\t Address:");
scanf("%s",&address);

printf("\t Phone Number:");
scanf("%s", &phoneNumber);

if(fptr == NULL)
   {
      printf("Error!");   
      exit(1);             
   }

   fprintf(fptr,"%s\n",firstName);
   fprintf(fptr,"%s\n",lastName);
   fprintf(fptr,"%s\n",mailAddress);
   fprintf(fptr,"%s\n",password);
   fprintf(fptr,"%s\n",conformPassword);
   fprintf(fptr,"%s\n",address);
   fprintf(fptr, "%s\n", phoneNumber);

   fclose(fptr);

            break;

        case 3: 
        MainView();
        break;

        default:
        printf("Invalid input...\n");

    }



    Exit();
}

int Exit(){
    return 0;
}





