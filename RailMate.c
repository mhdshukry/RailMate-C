/* Libraries */
#include <stdio.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>
#include <stdbool.h>

// files and functions

// constants for size of char arrays to store filename, the line from the file
#define FILENAME_SIZE 1024
#define MAX_LINE 2048

/* Functions */
int LoginUser();
int CreateUser(void);

void Features_Services();

void ViewReservation();
void Reservation();

void Profile(char T_username[]);
char EditPersonalDetails(char T_username[]);
void ViewUser(char T_username[]);

// 03.05.2023.2.19.49
void support();
void NewMail();
void ViewSupport(void);

// 03.05.2023.2.20.29
void Bugs();
void NewBugs();
void BugsView();

// 08.05.2023.2.16.35
void TrainList();
int TrainPriceCalculation();
void TrainReservation();

// Global variables
char T_username[255];

void TrainReservation()
{
    TrainList();

    char MainLine[250][20] = {
        "Maradana",
        "Kelaniya",
        "Ragama",
        "Gampaha",
        "Nawalapitiya",
        "Hatton",
        "Talawakele",
        "Ohiya",
        "Haputale",
        "Idalgasinna",
        "Elle",
        "Demodara",
        "Badulla"};

    char NothernLine[255] = {
        "Kurunegala",
        "Anuradhapura",
        "Medawachchiya",
        "Vavuniya",
        "Medawachchiya",
        "Vavuniya",
        "Omantai",
        "Kilinochchi",
        "Kodikamam",
        "Paranthan",
        "Jaffna",
        "Kankesanthurei"};

    char MataleLine[255] = {
        "Kandy",
        "Mahaiyawa",
        "Udatalawinna",
        "Pathanpha",
        "Ukuwela",
        "Matale"};

    char BatticoloaLine[255] = {
        "Moragollagama",
        "kekirawa",
        "Higurakgoda",
        "Polonnaruwa",
        "Manampitiya",
        "Welikanda",
        "Punani",
        "Valachchenai",
        "Eravur",
        "Batticaloa"};

    char TrincomaleeLine[255] = {
        "Kantale",
        "Tambalagamuwa",
        "ChinaBay",
        "Trincomalee"};

    char TalaimannarLine[255] = {
        "Cheddikulam",
        "MaduRoad",
        "Murunkan",
        "Mannar",
        "Pesalai",
        "Talaimannar",
        "TalaimannarPier"};

    char CoastLine[255] = {
        "Fort",
        "Kompnnavidiya",
        "Kollupitiya",
        "Bambalapitiya",
        "Dehiwala",
        "MountLaviniya",
        "Beruwala",
        "Aluthgama",
        "Bentota",
        "Induruwa",
        "MhaInduruwa",
        "kosgoda",
        "Balapitiya",
        "Ambalangoda",
        "Hikkaduwa",
        "Boossa",
        "Katugoda",
        "Habaraduwa",
        "Kumbalgama",
        "Matara"};

    printf("[1] - Main Lane\n[2] - Batticoloa Line\n[3] - Nothern Line\n[4] - Matale Line \n[5] - TrincomaleeLine\n[6] - TalaimannarLine\n[7] - Coast Line\n\n");
    printf("Select the Lane: \n");
    int Lane;
    scanf("%d", &Lane);
    switch (Lane)
    {
    case 1:
        for (int i = 0; i < 14; i++)
        {
            printf("\t\t [%d.] %s\n", i + 1, MainLine[i]);
        }
        break;

    case 2:
        for (int i = 0; i < 14; i++)
        {
            printf("\t\t [%d.] %s\n", i, MainLine[i]);
        }
        break;

    case 3:
        for (int i = 0; i < 14; i++)
        {
            printf("\t\t [%d.] %s\n", i + 1, MainLine[i]);
        }
        break;

    case 4:
        for (int i = 0; i < 14; i++)
        {
            printf("\t\t [%d.] %s\n", i + 1, MainLine[i]);
        }
        break;

    case 5:
        for (int i = 0; i < 14; i++)
        {
            printf("\t\t [%d.] %s\n", i + 1, MainLine[i]);
        }
        break;

    case 6:
        for (int i = 0; i < 14; i++)
        {
            printf("\t\t [%d.] %s\n", i + 1, MainLine[i]);
        }
        break;

    case 7:
        for (int i = 0; i < 14; i++)
        {
            printf("\t\t [%d.] %s\n", i + 1, MainLine[i]);
        }
        break;

    default:

        break;
    }

    int startingstation, endingstation, tickets, class;
    float ticketcost;

    printf("Enter the starting point: ");
    scanf("%d", &startingstation);

    printf("Enter the starting point: ");
    scanf("%d", &endingstation);

    printf("Enter the Tickets: ");
    scanf("%d", &tickets);

    printf("[1] - First/Luxary\n[2] - Second/Economy\n[3] - Third/Budget\n\n");
    scanf("%d", &class);

    // file pointer will be used to open/read the file
    FILE *file;
    FILE *TempFile;

    // used to store the filename and each line from the file
    char filename[FILENAME_SIZE] = "dp_pricelist.txt";
    char buffer[MAX_LINE];

    // stores the line number of the line the user wants to read from the file
    int read_line = 2;

    // prompt the user for the filename, store it into filename
    // printf("File: ");
    // scanf("%s", filename);

    // prompt the user for the line to read, store it into read_line
    // printf("Read Line: ");
    // scanf("%d", &read_line);

    // open the the file in read mode
    file = fopen(filename, "r");
    TempFile = fopen("TempSysFile.txt", "w");

    // if the file failed to open, exit with an error message and status
    if (file == NULL)
    {
        printf("Error opening file.\n");
        exit(0);
    }

    // we'll keep reading the file so long as keep_reading is true, and we'll
    // keep track of the current line of the file using current_line
    bool keep_reading = true;
    int current_line = 1;
    do
    {
        // read the next line from the file, store it into buffer
        fgets(buffer, MAX_LINE, file);

        // if we've reached the end of the file, we didn't find the line
        if (feof(file))
        {
            // stop reading from the file, and tell the user the number of lines in
            // the file as well as the line number they were trying to read as the
            // file is not large enough
            keep_reading = false;
            printf("File %d lines.\n", current_line - 1);
            printf("Couldn't find line %d.\n", read_line);
        }
        // if we've found the line the user is looking for, print it out
        else if (current_line == read_line)
        {
            keep_reading = false;
            printf("Line:\n%s", buffer);
        }

        // continue to keep track of the current line we are reading
        current_line++;

    } while (keep_reading);

    // close our access to the file
    fclose(file);

    fprintf(TempFile, "%s", buffer);

    fclose(TempFile);

    // notably at this point in the code, buffer will contain the line of the
    // file we were looking for if it was found successfully, so it could be
    // used for other purposes at this point as well...

    // creating a FILE variable
    /// FILE *inputf;
    FILE *inputf;
    // reading section

    char starting_station[255];
    char ending_station[255];
    char train_price[255];
    int r_userID;
    char TrainName[255];

    // open file for reading
    inputf = fopen("TempSysFile.txt", "r");

    // display detail
    printf("\t\t\t Details:\n");
    fscanf(inputf, "%d %s %s %s %s", &r_userID, starting_station, ending_station, TrainName, train_price);
    printf("\t\t\t---------------------------------------------------------------\n");
    printf("\t\t\tUserID: %d\n", r_userID);
    printf("\t\t\t---------------------------------------------------------------\n");
    printf("\t\t\tStart: %s\n", starting_station);
    printf("\t\t\t---------------------------------------------------------------\n");
    printf("\t\t\tEnd: %s\n", ending_station);
    printf("\t\t\t---------------------------------------------------------------\n");
    printf("\t\t\tPrice %s\n", train_price);
    printf("\t\t\t---------------------------------------------------------------\n");
    printf("\t\t\tTrain: %s\n", TrainName);
    printf("\t\t\t---------------------------------------------------------------\n");

    // close connection
    fclose(inputf);

    float basic_price = atoi(train_price);
    // printf("%.2lf", basic_price);

    float TotalCost;

    switch (class)
    {
    case 1:
        TotalCost = tickets * (basic_price + 2000);
        break;

    case 2:
        TotalCost = tickets * (basic_price + 1000);
        break;

    case 3:
        TotalCost = basic_price * tickets;
        break;

    default:
        break;
    }

    printf("%.2lf\n\n\n", TotalCost);

    // char PhoneNumber[255], FullName[255], EmailAddress[255], Address[255];

    printf("Train seat reservation.");

    char PhoneNumber[3000], c;
    int index = 0;
    printf("Enter Phone Number( press ';' to end input)\n");
    while ((c = getchar()) != ';')
    {
        PhoneNumber[index++] = c;
    }
    PhoneNumber[index] = '\0';

    //

    char FullName[3000], c1;
    int index1 = 0;
    printf("Enter Full Name( press ';' to end input)\n");
    while ((c1 = getchar()) != ';')
    {
        FullName[index1++] = c1;
    }
    FullName[index1] = '\0';

    //

    char EmailAddress[3000], c2;
    int index2 = 0;
    printf("Enter Mail Address( press ';' to end input)\n");
    while ((c2 = getchar()) != ';')
    {
        EmailAddress[index2++] = c2;
    }
    EmailAddress[index2] = '\0';

    //

    char Address[3000], c3;
    int index3 = 0;
    printf("Enter Your Address( press ';' to end input)\n");
    while ((c3 = getchar()) != ';')
    {
        Address[index3++] = c3;
    }
    Address[index3] = '\0';

    //

    FILE *DP_TrainReservation;

    DP_TrainReservation = fopen("dp_trainreservation.txt", "a+");

    if (DP_TrainReservation == NULL)
    {
        printf("file missing...\n");
        exit(0);
    }

    fprintf(DP_TrainReservation, "username: %s\n", T_username);
    fprintf(DP_TrainReservation, "Train details:\nstarting_station: %s\nending_station: %s\ntrain_price: %s\nTrainName: %s\n", starting_station, ending_station, train_price, TrainName);
    fprintf(DP_TrainReservation, "User details:\nName: %s\nPhone Number: %s\nEmail Address: %s\nAddress %s\n", FullName, PhoneNumber, EmailAddress, Address);
    fprintf(DP_TrainReservation, "\t\t\t---------------------------------------------------------------\n");

    fclose(DP_TrainReservation);

    if (remove("TempSysFile.txt") == 0)
        printf("Temp file Deleted successfully");
    else
        printf("Unable to delete the file");

    Features_Services();
}

int TrainPriceCalculation()
{
    TrainList();

    char MainLine[250][20] = {
        "Maradana",
        "Kelaniya",
        "Ragama",
        "Gampaha",
        "Nawalapitiya",
        "Hatton",
        "Talawakele",
        "Ohiya",
        "Haputale",
        "Idalgasinna",
        "Elle",
        "Demodara",
        "Badulla"};

    char NothernLine[255] = {
        "Kurunegala",
        "Anuradhapura",
        "Medawachchiya",
        "Vavuniya",
        "Medawachchiya",
        "Vavuniya",
        "Omantai",
        "Kilinochchi",
        "Kodikamam",
        "Paranthan",
        "Jaffna",
        "Kankesanthurei"};

    char MataleLine[255] = {
        "Kandy",
        "Mahaiyawa",
        "Udatalawinna",
        "Pathanpha",
        "Ukuwela",
        "Matale"};

    char BatticoloaLine[255] = {
        "Moragollagama",
        "kekirawa",
        "Higurakgoda",
        "Polonnaruwa",
        "Manampitiya",
        "Welikanda",
        "Punani",
        "Valachchenai",
        "Eravur",
        "Batticaloa"};

    char TrincomaleeLine[255] = {
        "Kantale",
        "Tambalagamuwa",
        "ChinaBay",
        "Trincomalee"};

    char TalaimannarLine[255] = {
        "Cheddikulam",
        "MaduRoad",
        "Murunkan",
        "Mannar",
        "Pesalai",
        "Talaimannar",
        "TalaimannarPier"};

    char CoastLine[255] = {
        "Fort",
        "Kompnnavidiya",
        "Kollupitiya",
        "Bambalapitiya",
        "Dehiwala",
        "MountLaviniya",
        "Beruwala",
        "Aluthgama",
        "Bentota",
        "Induruwa",
        "MhaInduruwa",
        "kosgoda",
        "Balapitiya",
        "Ambalangoda",
        "Hikkaduwa",
        "Boossa",
        "Katugoda",
        "Habaraduwa",
        "Kumbalgama",
        "Matara"};

    printf("[1] - Main Lane\n[2] - Batticoloa Line\n[3] - Nothern Line\n[4] - Matale Line \n[5] - TrincomaleeLine\n[6] - TalaimannarLine\n[7] - Coast Line\n\n");
    printf("Select the Lane: \n");
    int Lane;
    scanf("%d", &Lane);
    switch (Lane)
    {
    case 1:
        for (int i = 0; i < 14; i++)
        {
            printf("\t\t [%d.] %s\n", i + 1, MainLine[i]);
        }
        break;

    case 2:
        for (int i = 0; i < 14; i++)
        {
            printf("\t\t [%d.] %s\n", i, MainLine[i]);
        }
        break;

    case 3:
        for (int i = 0; i < 14; i++)
        {
            printf("\t\t [%d.] %s\n", i + 1, MainLine[i]);
        }
        break;

    case 4:
        for (int i = 0; i < 14; i++)
        {
            printf("\t\t [%d.] %s\n", i + 1, MainLine[i]);
        }
        break;

    case 5:
        for (int i = 0; i < 14; i++)
        {
            printf("\t\t [%d.] %s\n", i + 1, MainLine[i]);
        }
        break;

    case 6:
        for (int i = 0; i < 14; i++)
        {
            printf("\t\t [%d.] %s\n", i + 1, MainLine[i]);
        }
        break;

    case 7:
        for (int i = 0; i < 14; i++)
        {
            printf("\t\t [%d.] %s\n", i + 1, MainLine[i]);
        }
        break;

    default:

        break;
    }

    int startingstation, endingstation, tickets, class;
    float ticketcost;

    printf("Enter the starting point: ");
    scanf("%d", &startingstation);

    printf("Enter the starting point: ");
    scanf("%d", &endingstation);

    printf("Enter the Tickets: ");
    scanf("%d", &tickets);

    printf("[1] - First/Luxary\n[2] - Second/Economy\n[3] - Third/Budget\n\n");
    scanf("%d", &class);

    // file pointer will be used to open/read the file
    FILE *file;
    FILE *TempFile;

    // used to store the filename and each line from the file
    char filename[FILENAME_SIZE] = "dp_pricelist.txt";
    char buffer[MAX_LINE];

    // stores the line number of the line the user wants to read from the file
    int read_line = 2;

    // prompt the user for the filename, store it into filename
    // printf("File: ");
    // scanf("%s", filename);

    // prompt the user for the line to read, store it into read_line
    // printf("Read Line: ");
    // scanf("%d", &read_line);

    // open the the file in read mode
    file = fopen(filename, "r");
    TempFile = fopen("TempSysFile.txt", "w");

    // if the file failed to open, exit with an error message and status
    if (file == NULL)
    {
        printf("Error opening file.\n");
        return 1;
    }

    // we'll keep reading the file so long as keep_reading is true, and we'll
    // keep track of the current line of the file using current_line
    bool keep_reading = true;
    int current_line = 1;
    do
    {
        // read the next line from the file, store it into buffer
        fgets(buffer, MAX_LINE, file);

        // if we've reached the end of the file, we didn't find the line
        if (feof(file))
        {
            // stop reading from the file, and tell the user the number of lines in
            // the file as well as the line number they were trying to read as the
            // file is not large enough
            keep_reading = false;
            printf("File %d lines.\n", current_line - 1);
            printf("Couldn't find line %d.\n", read_line);
        }
        // if we've found the line the user is looking for, print it out
        else if (current_line == read_line)
        {
            keep_reading = false;
            printf("Line:\n%s", buffer);
        }

        // continue to keep track of the current line we are reading
        current_line++;

    } while (keep_reading);

    // close our access to the file
    fclose(file);

    fprintf(TempFile, "%s", buffer);
    fclose(TempFile);

    // notably at this point in the code, buffer will contain the line of the
    // file we were looking for if it was found successfully, so it could be
    // used for other purposes at this point as well...

    // creating a FILE variable
    /// FILE *inputf;
    FILE *inputf;
    // reading section

    char starting_station[255];
    char ending_station[255];
    char r_Password[255];
    int r_userID;
    char price[255];

    // open file for reading
    inputf = fopen("TempSysFile.txt", "r");

    // display detail
    printf("\t\t\t Details:\n");
    fscanf(inputf, "%d %s %s %s %s", &r_userID, starting_station, ending_station, price, r_Password);
    printf("\t\t\t---------------------------------------------------------------\n");
    printf("\t\t\tUserID: %d\n", r_userID);
    printf("\t\t\t---------------------------------------------------------------\n");
    printf("\t\t\tStart: %s\n", starting_station);
    printf("\t\t\t---------------------------------------------------------------\n");
    printf("\t\t\tEnd: %s\n", ending_station);
    printf("\t\t\t---------------------------------------------------------------\n");
    printf("\t\t\tPrice %s\n", r_Password);
    printf("\t\t\t---------------------------------------------------------------\n");
    printf("\t\t\tTrain: %s\n", price);
    printf("\t\t\t---------------------------------------------------------------\n");

    // close connection
    fclose(inputf);

    float basic_price = atoi(r_Password);
    // printf("%.2lf", basic_price);

    float TotalCost;

    switch (class)
    {
    case 1:
        TotalCost = tickets * (basic_price + 2000);
        break;

    case 2:
        TotalCost = tickets * (basic_price + 1000);
        break;

    case 3:
        TotalCost = basic_price * tickets;
        break;

    default:
        break;
    }

    printf("%.2lf\n\n\n", TotalCost);
    Features_Services();
}

void TrainList()
{
    char *filename = "TrainsDetails.txt";
    FILE *ViewBugFile = fopen(filename, "r");

    if (ViewBugFile == NULL)
    {
        printf("Error: could not open file %s", filename);
        exit(0);
    }

    // read one character at a time and
    // display it to the output
    char ch;
    while ((ch = fgetc(ViewBugFile)) != EOF)
    {
        putchar(ch);
    }

    // close the file
    fclose(ViewBugFile);
}

void Reservation()
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
    char username[255];
    char PassWord[255];
    char PassWordC[255];
    char NameOfUser[255];

    const char returnValue[255];

    // Get username from user and create a new file name as user's username
    // printf("Welcome to TRS-Application...!!");
    printf("\n\n\t\tUnique username, please: ");
    scanf("%s", username);

    R_file = fopen(username, "r");
    if (R_file != NULL)
    {
        printf("\n\t\tUsername already exicts...\n\t\tPlease,Choose another one.");
        CreateUser();
    }
    if (R_file == NULL)
    {
        // open the file in write mode
        C_file = fopen(username, "w");

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

            fprintf(C_file, "%s %s %s %s\n", id, username, NameOfUser, PassWord);
            fclose(C_file);
            strcat(returnValue, username);
            strcpy(T_username, username);
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
                fclose(C_file);
                strcat(returnValue, T_username);
                strcpy(T_username, username);
            }
            else
            {
                printf("Passwords doesn't match...\n");
                printf("Try again later...\n");
                strcat(returnValue, "null");
                strcpy(T_username, username);
            }
        }

        // close connection
        fclose(C_file);
        fclose(R_file);
    }
    Features_Services();
    strcpy(T_username, username);
    return returnValue;
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

        int vallue;
        value = strcmp(AccountCreateOption, 'Y');
        if (value == 0)
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

    do
    {

        printf("\n");
        printf("\t\t\t-------------------- Welcome Back [ %s ] -----------------\n\n", T_username);
        printf("\t\t\t-------------------[ 1 ] Trains List & Prices  -----------------\n");
        printf("\t\t\t-------------------[ 2 ] Train Seat Reservation ----------------\n");
        printf("\t\t\t-------------------[ 3 ] View My History -----------------------\n");
        printf("\t\t\t-------------------[ 4 ] Profile -------------------------------\n");
        printf("\t\t\t-------------------[ 5 ] Supports and News ---------------------\n");
        printf("\t\t\t-------------------[ 6 ] Report a Bug ---------------------\n");
        printf("\t\t\t-------------------[ 7 ] Exit ----------------------------------\n\n");

        printf("\t\t\tFeature Option: ");
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

        case 7:
            exit(0);
            break;

        default:
            printf("wrong input...");
            break;
        }
    } while (FeatureOption != 7);
}

void Profile(char T_username[])
{

    int ProfileOption;

    do
    {

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
            printf("wrong input...\n");
            break;
        }
    } while (ProfileOption != 5);
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
        char mailaddress[3000], c2;
        int index2 = 0;
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

void Bugs()
{
    int BugsOption;

    printf("\n");
    printf("\t\t\t----------------------[ # ] Bugs reports  ---------------------------\n");
    printf("\t\t\t-------------------- Hello [ %s ] -----------------\n\n", T_username);
    printf("\t\t\t-------------------[ 1 ] Report Bugs ---------------------------\n");
    printf("\t\t\t-------------------[ 2 ] View Bugs-----------------------------------\n");
    printf("\t\t\t-------------------[ 3 ] Main menu ------------------------------\n");
    printf("\t\t\t-------------------[ 4 ] Exit -----------------------------------\n\n");

    printf("\t\t\tFeature Option: ");
    scanf("%d", &BugsOption);

    switch (BugsOption)
    {
    case 1:
        NewBugs();
        break;
    case 2:
        BugsView();
        break;
    case 3:
        // Features_Services();
        break;
    case 4:
        exit(0);
        break;

    default:
        break;
    }
}

void NewBugs()
{
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

    char *filename = "bugs.txt";
    FILE *BugsFile = fopen(filename, "a");

    if (BugsFile == NULL)
    {
        printf("Error: could not open file %s", filename);
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

        fprintf(BugsFile, "Mail support no. %d \n\tRequesting person name: %s \nMail address: %s \nHeading: %s \nContent: %s \n\tTime: %s", no, T_username, mailaddress, heading, content, asctime(timeinfo));
        fprintf(BugsFile, "---------------------------------------------------------------\n\n\n");

        fclose(BugsFile);

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

void BugsView()
{
    char *filename = "bugs.txt";
    FILE *ViewBugFile = fopen(filename, "r");

    if (ViewBugFile == NULL)
    {
        printf("Error: could not open file %s", filename);
        exit(0);
    }

    // read one character at a time and
    // display it to the output
    char ch;
    while ((ch = fgetc(ViewBugFile)) != EOF)
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
    fclose(ViewBugFile);

    char yesorno[20];
    printf("Do you want to continue...? [Type 'yes' or 'no']");
    scanf("%s", yesorno);
    int value, value1;
    value = strcmp(yesorno, "yes");
    value1 = strcmp(yesorno, "no");
    if (value == 0)
    {
        printf("Wrong input...\n System goes to mainmenu page...\n");
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