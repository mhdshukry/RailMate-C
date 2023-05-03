/* Libraries */
#include <stdio.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>

/* Functions */
void ViewUser(char T_username[]);
int LoginUser();
int CreateUser(void);
void Features_Services();
void ViewReservation();
void TrainReservation();
void Profile(char T_username[]);
char EditPersonalDetails(char T_username[]);
void TrainList();
int PriceCalculation(int S_Station, int E_Station, int S_Class, int Person);

// 03.05.2023.2.19.49
void support();
void NewMail();
void ViewSupport(void);

// Global variables
char T_username[255];
char LoginStatus[255];
int RegisterStatus;

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

    char TrainList[] = {
        "Jaffna",
        "Vavuniya",
        "Mannar",
        "Kandy",
        "Colombo",
        "Vavuniya",
        "Vavuniya",
    };

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
    scanf("%s", S_Station);

    printf("\t\t Ending station: ");
    scanf("%s", E_Station);

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

    Features_Services();
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
    printf("\t\t\t Details:\n");
    fscanf(inputf, "%s %s %s %[^\n]s", r_userID, &r_username, &r_Name, &r_Password);
    printf("\t\t\t---------------------------------------------------------------\n");
    printf("\t\t\tUserID: %s\n", r_userID);
    printf("\t\t\t---------------------------------------------------------------\n");
    printf("\t\t\tUsername: %s\n", r_username);
    printf("\t\t\t---------------------------------------------------------------\n");
    printf("\t\t\tName: %s\n", r_Name);
    printf("\t\t\t---------------------------------------------------------------\n");
    printf("\t\t\tPassword: %s\n", r_Password);
    printf("\t\t\t---------------------------------------------------------------\n");

    // close connection
    fclose(inputf);
    Features_Services();
}

int CreateUser(void)
{
    // creating a FILE variable
    /// FILE *inputf;
    FILE *C_file;
    FILE *R_file;

    // integer variable
    int value;

    // character variable
    char T_username[255];
    char PassWord[255];
    char PassWordC[255];
    char NameOfUser[255];

    // Get username from user and create a new file name as user's username
    // printf("Welcome to TRS-Application...!!");
    printf("\n\n\t\tUnique username, please: ");
    scanf("%s", T_username);

    R_file = fopen(T_username, "r");
    if (R_file != NULL)
    {
        printf("\n\t\tUsername already exicts...\n\t\tPlease,Choose another one.");
        CreateUser();
    }
    if (R_file == NULL)
    {
        // open the file in write mode
        C_file = fopen(T_username, "w");

        if (C_file != NULL)
        {
            // printf("File created successfully!\n");
        }
        else
        {
            printf("Failed to create the file.\n");
            // exit status for OS that an error occured
            exit(0);
        }

        char id[255] = "TRS_UR_001";

        // get customer detail
        printf("\tEnter name: ");
        scanf("%s", NameOfUser);

        printf("\tEnter your password: ");
        scanf("%s", PassWord);

        printf("\tAgain Password: ");
        scanf("%s", PassWordC);

        value = strcmp(PassWord, PassWordC);
        if (value == 0)
        {

            fprintf(C_file, "%s %s %s %s\n", id, T_username, NameOfUser, PassWord);
            return T_username;
        }

        else
        {
            printf("\tPasswords doesn't match...\n");

            printf("\tEnter your password: ");
            scanf("%s", PassWord);

            printf("\tAgain Password: ");
            scanf("%s", PassWordC);
            value = strcmp(PassWord, PassWordC);
            if (value == 0)
            {
                fprintf(C_file, "%s %s %s %s\n", id, T_username, NameOfUser, PassWord);
                RegisterStatus = 1;
                return T_username;
            }
            else
            {
                printf("Passwords doesn't match...\n");
                printf("Try again later...\n");
                return "null";
            }
        }

        // close connection
        fclose(C_file);
        fclose(R_file);
        return 0;
    }
}

int LoginUser()
{
    // creating a FILE variable
    /// FILE *inputf;
    FILE *F_login;

    char *P_username;

    // char T_username[255];
    char l_name[255];
    char l_userID[255];
    char l_Password[255];

    char PassWordFromUser[255];

    char AccountCreateOption[2];

    int value;

    printf("\n\n\t\t\tEnter your username: ");
    scanf("%s", T_username);

    P_username = T_username;

    F_login = fopen(T_username, "r");

    if (F_login != NULL)
    {
        // display detail
        fscanf(F_login, "%s %s %s %[^\n]s", l_userID, &T_username, &l_name, &l_Password);
        // printf("\tUserID: %s\n", r_userID);
        // printf("\tUsername: %s\n", r_username);
        printf("\t\t Hello %s\n", l_name);
        // printf("\tPassword: %s\n", l_Password);

        printf("\t\tEnter your password: ");
        scanf("%s", PassWordFromUser);

        value = strcmp(l_Password, PassWordFromUser);
        if (value == 0)
        {
            printf("\t\tYou have successfully loggedin");

            return T_username;
        }
        else
        {
            printf("\t\tyour password is wrong...\n");
            printf("\t\ttry again...\n");

            printf("\t\tEnter your password: ");
            scanf("%s", PassWordFromUser);

            value = strcmp(l_Password, PassWordFromUser);
            if (value == 0)
            {
                printf("\t\tYou have successfully loggedin");

                return T_username;
            }
            else
            {
                return "null";
            }
        }
    }
    else
    {
        printf("There are no exicting user...\n");
        printf("do you want to create an account..? [ Y / N ] : ");
        scanf("%s", AccountCreateOption);

        if (AccountCreateOption == 'Y')
        {
            CreateUser();
        }
        else
        {
            // exit status for OS that an error occured
            printf("Existing Services....\n");
            exit(0);
        }
    }
    fclose(F_login);

    // Features_Services(T_username);
}

void Features_Services()
{
    // integer decleearage
    int FeatureOption;
    // printf("\n%s", T_username);

    printf("\n");
    printf("\t\t\t-------------------- Welcome Back [ %s ] -----------------\n\n", T_username);
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
        TrainList();
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
        support();
        break;
    case 7:
        exit(0);
        break;

    default:
        break;
    }
}

void Profile(char T_username[])
{

    int ProfileOption;

    printf("\n");
    printf("\t\t\t----------------------[ # ] Profile  ---------------------------\n");
    printf("\t\t\t-------------------- Welcome Back [ %s ] -----------------\n\n", T_username);
    printf("\t\t\t-------------------[ 1 ] View Details ---------------------------\n");
    printf("\t\t\t-------------------[ 2 ] Edit personal details  -----------------\n");
    printf("\t\t\t-------------------[ 3 ] View Reservation history ---------------\n");
    printf("\t\t\t-------------------[ 4 ] Main menu ------------------------------\n");
    printf("\t\t\t-------------------[ 5 ] Exit -----------------------------------\n\n");

    printf("\t\t\tFeature Option: ");
    scanf("%d", &ProfileOption);

    switch (ProfileOption)
    {
    case 1:
        ViewUser(T_username);
        break;
    case 2:
        EditPersonalDetails(T_username);
        break;
    case 3:
        /* code */
        break;
    case 4:
        Features_Services();
        break;
    case 5:
        exit(0);
        break;

    default:
        break;
    }
}

// -------- EditPersonalDetails --------//
int main()
{
    // declaration of local variable op;
    int op;
    char loginstatus[255];

    do
    {
        // welcome message
        printf("\n\n\n");
        printf("\t-------------------------------------------------------------------------------------\n");
        printf("\t\t---------------------- Welcome To - RailMate Lanka ------------------\n");
        printf("\t\t------------------- Advanved online reservation system --------------\n");
        printf("\t-------------------------------------------------------------------------------------\n\n\n");

        printf("\t\t\t-------------------[ 1 ] Login -------------------\n");
        printf("\t\t\t-------------------[ 2 ] Register ----------------\n");
        printf("\t\t\t-------------------[ 0 ] Exit --------------------\n\n");

        printf("\n\n\t\t Please, Make a choice : ");

        scanf("%d", &op); // accepts a numeric input to choose the operation

        // use switch statement to call an operation
        switch (op)
        {
        case 1:
            if (LoginUser() != "null")
            {
                // printf("\n%s", T_username);

                Features_Services();
            }

            break; // break the function

        case 2:
            if (CreateUser() != "null")
            {
                // printf("\n%s", T_username);

                Features_Services();
            }
            break; // break the function

        case 0:
            printf(" You chose: Exit");
            exit(0);
            break; // break the function

        default:
            printf(" Something is wrong!! ");
            break;
        }
        printf(" \n \n ---------------------------- \n \n");
    } while (op != 7);
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
        scanf("%s", EP_name);

        printf("\tEnter your password: ");
        scanf("%s", EP_password);

        printf("\tAgain Password: ");
        scanf("%s", EP_password_r);

        value = strcmp(EP_password, EP_password_r);
        if (value == 0)
        {
            fprintf(file, "%s %s %s %s\n", id, T_username, EP_name, EP_password);
        }

        else
        {
            printf("\tPasswords doesn't match...\n");

            printf("\tEnter your password: ");
            scanf("%s", EP_password);

            printf("\tAgain Password: ");
            scanf("%s", EP_password_r);
            value = strcmp(EP_password, EP_password_r);
            if (value == 0)
            {
                fprintf(file, "%s %s %s %s\n", id, T_username, EP_name, EP_password);
            }
            else
            {
                printf("Passwords doesn't match...\n");
                printf("Try again later...\n");
                Features_Services();
            }
        }

        // close connection
        fclose(file);
    }
    else
    {
        printf("issue on system.\n");
        // exit status for OS that an error occured
        exit(0);
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
    int support_option;

    printf("\n");
    printf("\t\t\t----------------------[ # ] support  ---------------------------\n");
    printf("\t\t\t-------------------- Support [ %s ] -----------------\n\n", T_username);
    printf("\t\t\t-------------------[ 1 ] Create New Mail Support ---------------------------\n");
    printf("\t\t\t-------------------[ 2 ] View my support mails-----------------------------------\n");
    printf("\t\t\t-------------------[ 3 ] Main menu ------------------------------\n");
    printf("\t\t\t-------------------[ 4 ] Exit -----------------------------------\n\n");

    printf("\t\t\tFeature Option: ");
    scanf("%d", &support_option);

    switch (support_option)
    {
    case 1:
        NewMail();
        break;
    case 2:
        ViewSupport();
        break;
    case 3:
        Features_Services();
        break;
    case 4:
        exit(0);
        break;

    default:
        break;
    }
}

void NewMail()
{
    FILE *MailFile;
    char content[3000], c;
    int index = 0;

    char heading[3000], c1;
    int index1 = 0;

    char mailaddress[3000], c2;
    int index2 = 0;

    int no = 1;

    // Time
    time_t rawtime;
    struct tm *timeinfo;

    time(&rawtime);
    timeinfo = localtime(&rawtime);
    // printf("Current local time and date: %s", asctime(timeinfo));

    MailFile = fopen("supports.txt", "a");

    if (MailFile == NULL)
    {
        printf("System files missing...\n");
        exit(0);
    }
    else
    {
        printf("Enter Mail Address( press ';' to end input)\n");
        while ((c2 = getchar()) != ';')
        {
            mailaddress[index2++] = c2;
        }
        mailaddress[index2] = '\0';

        printf("Enter the heading( press ';' to end input)\n");
        while ((c1 = getchar()) != ';')
        {
            heading[index1++] = c1;
        }
        heading[index1] = '\0';

        printf("Enter the content( press ';' to end input)\n");
        while ((c = getchar()) != ';')
        {
            content[index++] = c;
        }
        content[index] = '\0';

        fprintf(MailFile, "Mail support no. %d \n\tRequesting person name: %s \nMail address: %s \nHeading: %s \nContent: %s \n\tTime: %s", no, T_username, mailaddress, heading, content, asctime(timeinfo));
        fprintf(MailFile, "---------------------------------------------------------------\n\n\n");

        fclose(MailFile);

        char yesorno[20];
        printf("Do you want to continue...? [Type 'yes' or 'no']");
        scanf("%s", yesorno);
        int value, value1;
        value = strcmp(yesorno, "yes");
        value1 = strcmp(yesorno, "no");
        if (value == 0)
        {
            Features_Services();
        }
        else if (value1 == 0)
        {
            printf("System exits\n");
            exit(0);
        }
        else
        {
            printf("Wrong input...\n System goes to mainmenu page...\n");
            Features_Services();
        }
    }
}

void ViewSupport()
{
    char *filename = "supports.txt";
    FILE *ViewFile = fopen(filename, "r");

    if (ViewFile == NULL)
    {
        printf("Error: could not open file %s", filename);
        exit(0);
    }

    // read one character at a time and
    // display it to the output
    char ch;
    while ((ch = fgetc(ViewFile)) != EOF)
        putchar(ch);

    char *x[] = {"ab", "bc", "cd"};
    char *s = "kirupan";
    int len = sizeof(x) / sizeof(x[0]);
    int i;

    for (i = 0; i < len; ++i)
    {
        if (!strcmp(x[i], s))
        {
            // Do your stuff
        }
    }
    // close the file
    fclose(ViewFile);

    char yesorno[20];
    printf("Do you want to continue...? [Type 'yes' or 'no']");
    scanf("%s", yesorno);
    int value, value1;
    value = strcmp(yesorno, "yes");
    value1 = strcmp(yesorno, "no");
    if (value == 0)
    {
        Features_Services();
    }
    else if (value1 == 0)
    {
        printf("System exits\n");
        exit(0);
    }
    else
    {
        printf("Wrong input...\n System goes to mainmenu page...\n");
        Features_Services();
    }
}