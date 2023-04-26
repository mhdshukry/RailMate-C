/* Libraries */
#include <stdio.h>
#include <string.h>
#include <time.h>

void ViewUser(char T_username[]);
int LoginUser();
int CreateUser(void);
int MainView();
void Features_Services(char T_username);
void ViewReservation();
void support();

void TrainReservation();

void Profile(char T_username[]);
char EditPersonalDetails(char T_username[]);

void TrainList();
int PriceCalculation(int S_Station, int E_Station, int S_Class, int Person);

int PriceCalculation(int S_Station, int E_Station, int S_Class, int Person)
{
    float FirstClassTicket = 3200;
    float SecondClassTicket = 1800;
    float ThirdClassTicket = 600;

    float Ticket, ClassCost;

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

    // if (S_Station == 1 && E_Station == 2){
    Ticket = Person * ClassCost;
    //}
    return Ticket;
}

void TrainList()
{
    // Integer
    int S_Station, E_Station, S_Class, Person;
    float Ticket;

    printf("\n");
    printf("\n");
    printf("\t\t [1] Jaffna \t [2] Vavuniya \t [3] Mannar \t [4] Kandy \t [5] Colombo \n");
    printf("\n");
    printf("\t\t [6] Jaffna \t [5] Vavuniya \t [8] Mannar \t [9] Kandy \t [10] Colombo \n");
    printf("\n");
    printf("\t\t [11] Jaffna \t [12] Vavuniya \t [13] Mannar \t [14] Kandy \t [15] Colombo \n");
    printf("\n");
    printf("\t\t [16] Jaffna \t [17] Vavuniya \t [18] Mannar \t [19] Kandy \t [20] Colombo \n");
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

    Ticket = PriceCalculation(S_Station, E_Station, S_Class, Person);
    printf("\n Ticket: %0.2lf ", Ticket);
}

void TrainReservation()
{
    printf("\n");
    printf("\t\t\t----------------------[ # ] Train Reservation  ---------------------------n");
    printf("\t\t\t-------------------- Hello [ USERNAME ] ------------------\n\n");
    printf("\t\t\t-------------------[ 1 ] Train list and prices   -----------------\n");
    printf("\t\t\t-------------------[ 2 ] Train Reservation------------------------\n");
    printf("\t\t\t-------------------[ 3 ] View Reservations -----------------------\n");
    printf("\t\t\t-------------------[ 4 ] Main menu -------------------------------\n");
    printf("\t\t\t-------------------[ 5 ] Exit ------------------------------------\n\n");
}

void ViewUser(char T_username[])
{
    // creating a FILE variable
    /// FILE *inputf;
    FILE *inputf;
    // reading section

    char r_username[255];
    char r_Name[255];
    char r_Password[255];
    char r_userID[255];

    // open file for reading
    inputf = fopen(T_username, "r");

    // display detail
    printf("\nCustomer Details:\n");
    fscanf(inputf, "%s %s %s %[^\n]s", r_userID, &r_username, &r_Name, &r_Password);
    printf("\tUserID: %s\n", r_userID);
    printf("\tUsername: %s\n", r_username);
    printf("\tName: %s\n", r_Name);
    printf("\tPassword: %s\n", r_Password);

    printf("\nEnd of file.\n");

    // close connection
    fclose(inputf);
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
    scanf("%d", &userDashMenu);
    do
    {
        switch (userDashMenu)
        {
        case 1:
        LoginUser();
            break;

        case 2:
            /* Register Function */
            CreateUser();
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

int CreateUser(void)
{
    // creating a FILE variable
    /// FILE *inputf;
    FILE *inputf;

    // integer variable
    int value;

    // character variable
    char T_username[255];
    char PassWord[255];
    char PassWordC[255];
    char NameOfUser[255];

    // Get username from user and create a new file name as user's username
    printf("Welcome to TRS-Application...!!");
    printf("\tUsername: ");
    scanf("%s", T_username);

    // open the file in write mode
    inputf = fopen(T_username, "w");

    if (inputf != NULL)
    {
        // printf("File created successfully!\n");
    }
    else
    {
        printf("Failed to create the file.\n");
        // exit status for OS that an error occured
        return -1;
    }

    char id[255] = "TRS_UR_001";

    // get customer detail
    printf("\tEnter name: ");
    scanf("%s", &NameOfUser);

    printf("\tEnter your password: ");
    scanf("%s", &PassWord);

    printf("\tAgain Password: ");
    scanf("%s", &PassWordC);

    value = strcmp(PassWord, PassWordC);
    if (value == 0)
    {
        fprintf(inputf, "%s %s %s %s\n", id, T_username, NameOfUser, PassWord);
    }

    else
    {
        printf("\tPasswords doesn't match...\n");

        printf("\tEnter your password: ");
        scanf("%s", &PassWord);

        printf("\tAgain Password: ");
        scanf("%s", &PassWordC);
        value = strcmp(PassWord, PassWordC);
        if (value == 0)
        {
            fprintf(inputf, "%s %s %s %s\n", id, T_username, NameOfUser, PassWord);
        }
        else
        {
            printf("Passwords doesn't match...\n");
            printf("Try again later...\n");
            return -1;
        }
    }

    // close connection
    fclose(inputf);

    Features_Services(T_username);
    return 0;
}

int LoginUser()
{
    // creating a FILE variable
    /// FILE *inputf;
    FILE *inputf;

    char T_username[255];
    char l_name[255];
    char l_userID[255];
    char l_Password[255];

    char PassWordFromUser[255];

    char AccountCreateOption[2];

    int value;

    printf("Enter your username: ");
    scanf("%s", &T_username);

    inputf = fopen(T_username, "r");

    if (inputf != NULL)
    {
        // display detail
        printf("\nCustomer Details:\n");
        fscanf(inputf, "%s %s %s %[^\n]s", l_userID, &T_username, &l_name, &l_Password);
        // printf("\tUserID: %s\n", r_userID);
        // printf("\tUsername: %s\n", r_username);
        printf("\t Hello %s\n", l_name);
        // printf("\tPassword: %s\n", l_Password);

        printf("Enter your password: ");
        scanf("%s", &PassWordFromUser);

        value = strcmp(l_Password, PassWordFromUser);
        if (value == 0)
        {
            printf("You have successfully loggedin");
        }
        else
        {
            printf("your password is wrong...\n");
            printf("try again...\n");

            printf("Enter your password: ");
            scanf("%s", &PassWordFromUser);

            value = strcmp(l_Password, PassWordFromUser);
            if (value == 0)
            {
                printf("You have successfully loggedin");
            }
            else
            {
                return -1;
            }
        }
    }
    else
    {
        printf("There are no exicting user...\n");
        printf("do you want to create an account..? [ Y / N ] : ");
        scanf("%s", &AccountCreateOption);

        if (AccountCreateOption == 'Y')
        {
            CreateUser();
        }
        else
        {
            // exit status for OS that an error occured
            printf("Terminating....\n");
            return -1;
        }
    }
    Features_Services(T_username);
}

void Features_Services(char T_username)
{
    // integer decleearage
    int FeatureOption;

    printf("\n");
    printf("\t\t\t-------------------- Welcome Back [ USERNAME ] -----------------\n\n");
    printf("\t\t\t-------------------[ 1 ] Trains List & Prices  -----------------\n");
    printf("\t\t\t-------------------[ 2 ] Train Seat Reservation ----------------\n");
    printf("\t\t\t-------------------[ 3 ] Parcel Services -----------------------\n");
    printf("\t\t\t-------------------[ 4 ] View My History -----------------------\n");
    printf("\t\t\t-------------------[ 5 ] Profile -------------------------------\n");
    printf("\t\t\t-------------------[ 6 ] Supports and News ---------------------\n");
    printf("\t\t\t-------------------[ 7 ] Exit ----------------------------------\n\n");

    printf("\t\t\tFeature Option: ");
    scanf("%d", &FeatureOption);

    switch (FeatureOption)
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
    case 5:
        Profile(T_username);
        break;
    case 6:
        /* support();
         */
        break;
    case 7:
        /* code */
        break;

    default:
        break;
    }
}

void Profile(char T_username[])
{

    int ProfileOption;

    printf("\n");
    printf("\t\t\t----------------------[ # ] Profile  ---------------------------n");
    printf("\t\t\t-------------------- Welcome Back [ USERNAME ] -----------------\n\n");
    printf("\t\t\t-------------------[ 1 ] Edit personal details  -----------------\n");
    printf("\t\t\t-------------------[ 2 ] View history ---------------------------\n");
    printf("\t\t\t-------------------[ 3 ] Logs -----------------------------------\n");
    printf("\t\t\t-------------------[ 4 ] Main menu ------------------------------\n");
    printf("\t\t\t-------------------[ 5 ] Exit -----------------------------------\n\n");

    printf("\t\t\tFeature Option: ");
    scanf("%d", &ProfileOption);

    switch (ProfileOption)
    {
    case 1:
        EditPersonalDetails(T_username);
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
    case 5:
        /* Profile(); */
        break;

    default:
        break;
    }
}

// -------- EditPersonalDetails --------//
int main()
{
    MainView();

    return 0;
}
char EditPersonalDetails(char T_username[])
{

    // creating a FILE variable
    /// FILE *inputf;
    FILE *file;

    // integer variable
    int value;

    // character variable
    // char EP_username[255];
    char EP_password[255];
    char EP_password_r[255];
    char EP_name[255];

    // Get username from user and create a new file name as user's username
    printf("Welcome to TRS-Application...!!");

    // open the file in read mode
    file = fopen(T_username, "r");

    if (file != NULL)
    {
        file = fopen(T_username, "w");
        char id[255] = "TRS_UR_001";

        // get customer detail
        printf("\tEnter name: ");
        scanf("%s", &EP_name);

        printf("\tEnter your password: ");
        scanf("%s", &EP_password);

        printf("\tAgain Password: ");
        scanf("%s", &EP_password_r);

        value = strcmp(EP_password, EP_password_r);
        if (value == 0)
        {
            fprintf(file, "%s %s %s %s\n", id, T_username, EP_name, EP_password);
        }

        else
        {
            printf("\tPasswords doesn't match...\n");

            printf("\tEnter your password: ");
            scanf("%s", &EP_password);

            printf("\tAgain Password: ");
            scanf("%s", &EP_password_r);
            value = strcmp(EP_password, EP_password_r);
            if (value == 0)
            {
                fprintf(file, "%s %s %s %s\n", id, T_username, EP_name, EP_password);
            }
            else
            {
                printf("Passwords doesn't match...\n");
                printf("Try again later...\n");
                return -1;
            }
        }

        // close connection
        fclose(file);
    }
    else
    {
        printf("issue on system.\n");
        // exit status for OS that an error occured
        return -1;
    }
}

void ViewHistory()
{
}

void ViewLogs()
{
}

void ViewReservation()
{

    int ProfileOption;

    printf("\n");
    printf("\t\t\t----------------------[ # ] View Reservation  ---------------------------n");
    printf("\t\t\t-------------------- Welcome Back [ USERNAME ] -----------------\n\n");
    printf("\t\t\t-------------------[ 1 ] View history ---------------------------\n");
    printf("\t\t\t-------------------[ 2 ] Logs -----------------------------------\n");
    printf("\t\t\t-------------------[ 3 ] Main menu ------------------------------\n");
    printf("\t\t\t-------------------[ 4 ] Exit -----------------------------------\n\n");

    printf("\t\t\tFeature Option: ");
    scanf("%d", &ProfileOption);

    switch (ProfileOption)
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

void support()
{
    int ProfileOption;

    printf("\n");
    printf("\t\t\t----------------------[ # ] support  ---------------------------n");
    printf("\t\t\t-------------------- Welcome Back [ USERNAME ] -----------------\n\n");
    printf("\t\t\t-------------------[ 1 ] Create New Mail Support ---------------------------\n");
    printf("\t\t\t-------------------[ 2 ] View my support mails-----------------------------------\n");
    printf("\t\t\t-------------------[ 3 ] Main menu ------------------------------\n");
    printf("\t\t\t-------------------[ 4 ] Exit -----------------------------------\n\n");

    printf("\t\t\tFeature Option: ");
    scanf("%d", &ProfileOption);

    switch (ProfileOption)
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