
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

#define MAX_LENGTH 255
#define NUM_STRINGS 20

// 08.05.2023.2.16.35
void TrainList();
int TrainPriceCalculation();
void TrainReservation();
void Features_Services();

// Global variables
char T_username[255];

void TrainReservation()
{
    // TrainList();

    char *BatticoloaLine[NUM_STRINGS] = {
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

    char *TrincomaleeLine[NUM_STRINGS] = {
        "Kantale",
        "Tambalagamuwa",
        "ChinaBay",
        "Trincomalee"};

    char *TalaimannarLine[NUM_STRINGS] = {
        "Cheddikulam",
        "MaduRoad",
        "Murunkan",
        "Mannar",
        "Pesalai",
        "Talaimannar",
        "TalaimannarPier"};

    char *CoastLine[NUM_STRINGS] = {
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

    char *MainLine[NUM_STRINGS] = {
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

    char *NothernLine[NUM_STRINGS] = {
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

    // exit(EXIT_SUCCESS);

    printf("Train Lane: \n");

    printf(" [1] Nothern Lane\n [2] Matale Lane\n [3] BatticoloaLine\n [4] TrincomaleeLine\n [5] TalaimannarLine\n [6] CoastLine\n\n\n\n ");

    int selectlane;

    scanf("%d", &selectlane);
    printf("\n\n");

    switch (selectlane)
    {
    case 1:
        for (int i = 0; i < NUM_STRINGS; ++i)
        {
            printf("\t\t\t[%d]%s, \n", i + 1, NothernLine[i]);
        }
        printf("\n");

        break;
    case 2:
        for (int i = 0; i < NUM_STRINGS; ++i)
        {
            printf("%s, \n", MainLine[i]);
        }
        printf("\n");
        break;

    case 3:
        for (int i = 0; i < NUM_STRINGS; ++i)
        {
            printf("%s, \n", BatticoloaLine[i]);
        }
        printf("\n");
        break;

    case 4:
        for (int i = 0; i < NUM_STRINGS; ++i)
        {
            printf("%s, \n", TrincomaleeLine[i]);
        }
        printf("\n");
        break;

    case 5:
        for (int i = 0; i < NUM_STRINGS; ++i)
        {
            printf("%s, \n", TalaimannarLine[i]);
        }
        printf("\n");
        break;

    case 6:
        for (int i = 0; i < NUM_STRINGS; ++i)
        {
            printf("%s, \n", CoastLine[i]);
        }
        printf("\n");
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

    Write_Logs(T_username, "Train - Seat - Reservation");

    fclose(DP_TrainReservation);

    if (remove("TempSysFile.txt") == 0)
        printf("Temp file Deleted successfully");
    else
        printf("Unable to delete the file");

    Features_Services();
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

int TrainPriceCalculation()
{
    TrainList();

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
    Write_Logs(T_username, "Price - Calculation");
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
    Write_Logs(T_username, "Train-List");
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
