
/* Libraries */
#include <stdio.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>
#include <stdbool.h>
// #include <dos.h>

// files and functions

// constants for size of char arrays to store filename, the line from the file
#define FILENAME_SIZE 1024
#define MAX_LINE 2048

// 08.05.2023.2.16.35
void TrainList();
int TrainPriceCalculation();
void TrainReservation();
void Features_Services();
void Write_Logs(char T_username[255], char action[20]);
int main();

// Global variables
char T_username[255];
i = 0;

void TrainReservation()
{
    // TrainList();

    char *BatticoloaLine[] = {
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

    char *TrincomaleeLine[] = {
        "Kantale",
        "Tambalagamuwa",
        "ChinaBay",
        "Trincomalee"};

    char *TalaimannarLine[] = {
        "Cheddikulam",
        "MaduRoad",
        "Murunkan",
        "Mannar",
        "Pesalai",
        "Talaimannar",
        "TalaimannarPier"};

    char *CoastLine[] = {
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

    char *MainLine[] = {
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

    char *NothernLine[] = {
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

    printf("\n\t\t\t  ---------------------------------------------------------\n");
    printf("\n\t\t\tTrain Lane: \n");
    printf("\n\t\t\t  ---------------------------------------------------------\n");

    printf("\t\t\t [1] Nothern Lane\n");

    //[2] Matale Lane\n [3] BatticoloaLine\n [4] TrincomaleeLine\n [5] TalaimannarLine\n [6] CoastLine\n\n\n\n ");

    printf("\n\t\t\t  ---------------------------------------------------------\n");
    printf("\t\t\t                 [1]: NOTHERN LANE                             \n");
    printf("\t\t\t                 [2]: MATALE LANE                              \n");
    printf("\t\t\t                 [3]: BACTICALO LANE                           \n");
    printf("\t\t\t                 [4]: TRINCOMALEE LANE                         \n");
    printf("\t\t\t                 [5]: TALAIMANNAR LANE                         \n");
    printf("\t\t\t                 [6]: COAST LANE                               ");
    printf("\n\t\t\t  ---------------------------------------------------------\n");

    int selectlane;
    printf("\n\t\t\t  ---------------------------------------------------------\n");
    printf("\t\t\t                 SELECT LANE :  ");
    scanf("%d", &selectlane);
    printf("\n\t\t\t  ---------------------------------------------------------\n");
    printf("\n\n");

    switch (selectlane)
    {
    case 1:
        for (i = 0; i < 11; ++i)
        {
            printf("\t\t\t\t[%d] %s, \n", i + 1, NothernLine[i]);
        }
        printf("\n");
        printf("\n\t\t\t  ---------------------------------------------------------\n");

        break;
    case 2:
        for (i = 0; i < 12; ++i)
        {
            printf("\t\t\t\t[%d] %s, \n", i + 1, MainLine[i]);
        }
        printf("\n");
        printf("\n\t\t\t  ---------------------------------------------------------\n");
        break;

    case 3:
        for (i = 0; i < 10; ++i)
        {
            printf("\t\t\t\t[%d] %s, \n", i + 1, BatticoloaLine[i]);
        }
        printf("\n");
        printf("\n\t\t\t  ---------------------------------------------------------\n");
        break;

    case 4:
        for (i = 0; i < 4; ++i)
        {
            printf("\t\t\t\t[%d] %s, \n", i + 1, TrincomaleeLine[i]);
        }
        printf("\n");
        printf("\n\t\t\t  ---------------------------------------------------------\n");
        break;

    case 5:
        for (i = 0; i < 6; ++i)
        {
            printf("\t\t\t\t[%d] %s, \n", i + 1, TalaimannarLine[i]);
        }
        printf("\n");
        printf("\n\t\t\t  ---------------------------------------------------------\n");
        break;

    case 6:
        for (i = 0; i < 20; ++i)
        {
            printf("\t\t\t\t[%d] %s, \n", i + 1, CoastLine[i]);
        }
        printf("\n");
        printf("\n\t\t\t  ---------------------------------------------------------\n");
        break;

    default:
        printf("\t\t\t---------------------------------------------------------------\n");
        printf("\t\t\t                           WRONG INPUT          ");
        printf("\n\t\t\t---------------------------------------------------------------\n");
        TrainReservation();
        break;
    }

    int startingstation, endingstation, tickets, class;
    float ticketcost;

    printf("\n\t\t\t  ---------------------------------------------------------\n");
    printf("\t\t\t                     STARTING POINT: ");
    scanf("%d", &startingstation);
    printf("\t\t\t  ---------------------------------------------------------\n");
    printf("\t\t\t                     ENDING POINT: ");
    scanf("%d", &endingstation);
    printf("\t\t\t  ---------------------------------------------------------\n");
    printf("\t\t\t                     TICKETS: ");
    scanf("%d", &tickets);
    printf("\t\t\t  ---------------------------------------------------------\n");
    printf("\t\t\t             [1] - FIRST/LUXURY                            \n");
    printf("\t\t\t             [2] - SECOND/ECONOMY                          \n");
    printf("\t\t\t             [3] - THIRD/BUDGET                            \n");

    printf("\t\t\t  ---------------------------------------------------------\n");

    printf("\n\t\t\t  ---------------------------------------------------------\n");
    printf("\t\t\t                 SELECT CLASS :  ");
    scanf("%d", &class);
    printf("\n\t\t\t  ---------------------------------------------------------\n");
    printf("\n\n");

    // file pointer will be used to open/read the file
    FILE *file;
    FILE *TempFile;

    // used to store the filename and each line from the file
    char filename[FILENAME_SIZE] = "db_pricelist.txt";
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
        printf("\n\t\t\t  ---------------------------------------------------------\n");
        printf("\t\t\t                 ERROR: CLOUD NOT OPEN FILE                    ");
        printf("\n\t\t\t  ---------------------------------------------------------\n");
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
            printf("F\t\t\tile %d lines.\n", current_line - 1);
            printf("\t\t\tCouldn't find line %d.\n", read_line);
        }
        // if we've found the line the user is looking for, prit out
        else if (current_line == read_line)
        {
            keep_reading = false;
            // printf("\t\t\tLine:\n%s", buffer);
        }

        // continue to keep track of the current line we are reading
        current_line++;

    } while (keep_reading);

    // close our access to the file
    fclose(file);

    fprintf(TempFile, "%s", buffer);

    fclose(TempFile);

    // notably at this poin the code, buffer will contain the line of the
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

    fscanf(inputf, "%d %s %s %s %s", &r_userID, starting_station, ending_station, TrainName, train_price);

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
        printf("\t\t\t---------------------------------------------------------------\n");
        printf("\t\t\t                           WRONG INPUT          ");
        printf("\n\t\t\t---------------------------------------------------------------\n");

        printf("\t\t\t  ---------------------------------------------------------\n");
        printf("\t\t\t             [1] - FIRST/LUXURY                            \n");
        printf("\t\t\t             [2] - SECOND/ECONOMY                          \n");
        printf("\t\t\t             [3] - THIRD/BUDGET                            \n");

        printf("\t\t\t  ---------------------------------------------------------\n");

        printf("\n\t\t\t  ---------------------------------------------------------\n");
        printf("\t\t\t                 SELECT CLASS :  ");
        scanf("%d", &class);
        printf("\n\t\t\t  ---------------------------------------------------------\n");
        printf("\n\n");

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
        }
    }

    printf("\n\t\t\t  ---------------------------------------------------------\n");
    printf("\t\t\t                 TOTAL COST: %.2lf                    ", TotalCost);
    printf("\n\t\t\t  ---------------------------------------------------------\n");

    printf("\n\t\t\t  ---------------------------------------------------------\n");
    printf("\t\t\t                 TRAIN SEAT RESERVATION                    ");
    printf("\n\t\t\t  ---------------------------------------------------------\n");

    char PhoneNumber[3000], c;
    int index = 0;

    printf("\n\t\t\t  ---------------------------------------------------------\n");
    printf("\t\t\t        PHONE NUMBER: ( press ';' to end input):- ");
    while ((c = getchar()) != ';')
    {
        PhoneNumber[index++] = c;
    }
    PhoneNumber[index] = '\0';
    printf("\n\t\t\t  ---------------------------------------------------------\n");

    //

    char FullName[3000], c1;
    int index1 = 0;

    printf("\n\t\t\t  ---------------------------------------------------------\n");
    printf("\t\t\t    FULL NAME: ( press ';' to end input):- ");
    while ((c1 = getchar()) != ';')
    {
        FullName[index1++] = c1;
    }
    FullName[index1] = '\0';
    printf("\n\t\t\t  ---------------------------------------------------------\n");

    //

    char EmailAddress[3000], c2;
    int index2 = 0;

    printf("\n\t\t\t  ---------------------------------------------------------\n");
    printf("\t\t\t    EMAIL ADDRESS: ( press ';' to end input):- ");
    while ((c2 = getchar()) != ';')
    {
        EmailAddress[index2++] = c2;
    }
    EmailAddress[index2] = '\0';
    printf("\n\t\t\t  ---------------------------------------------------------\n");

    //

    char Address[3000], c3;
    int index3 = 0;

    printf("\n\t\t\t  ---------------------------------------------------------\n");
    printf("\t\t\t    HOME ADDDRESS: ( press ';' to end input):- ");
    while ((c3 = getchar()) != ';')
    {
        Address[index3++] = c3;
    }
    Address[index3] = '\0';
    printf("\n\t\t\t  ---------------------------------------------------------\n");

    //

    FILE *db_TrainReservation;

    db_TrainReservation = fopen("db_trainreservation.txt", "a+");

    if (db_TrainReservation == NULL)
    {
        printf("file missing...\n");
        exit(0);
    }

    fprintf(db_TrainReservation, "username: %s\n", T_username);
    fprintf(db_TrainReservation, "Train details:\nstarting_station: %s\nending_station: %s\ntrain_price: %s\nTrainName: %s\n", starting_station, ending_station, train_price, TrainName);
    fprintf(db_TrainReservation, "User details:\nName: %s\nPhone Number: %s\nEmail Address: %s\nAddress %s\n", FullName, PhoneNumber, EmailAddress, Address);
    fprintf(db_TrainReservation, "\t\t\t---------------------------------------------------------------\n");

    Write_Logs(T_username, "Train - Seat - Reservation");

    fclose(db_TrainReservation);

    if (remove("TempSysFile.txt") == 0)
    {
        printf("\n\t\t\t  ---------------------------------------------------------\n");
        printf("\t\t\t                          TEMPRORARY FILE DELETED                    ");
        printf("\n\t\t\t  ---------------------------------------------------------\n");
    }
    else
    {
        printf("\n\t\t\t  ---------------------------------------------------------\n");
        printf("\t\t\t                     UNABLE DELETE THE FILE                    ");
        printf("\n\t\t\t  ---------------------------------------------------------\n");
    }

    // display detail
    printf("\n\t\t\t---------------------------------------------------------------\n");
    printf("\t\t\t                     RESERVATION DETAILS          ");
    printf("\n\t\t\t---------------------------------------------------------------\n");

    printf("\t\t\t---------------------------------------------------------------\n");
    printf("\t\t\t                 Username: %s\n", T_username);
    printf("\n\t\t\t---------------------------------------------------------------\n");
    printf("\t\t\t                 Start: %s\n", starting_station);
    printf("\t\t\t---------------------------------------------------------------\n");
    printf("\t\t\t                 End: %s\n", ending_station);
    printf("\t\t\t---------------------------------------------------------------\n");
    printf("\t\t\t                 Train: %s\n", TrainName);
    printf("\t\t\t---------------------------------------------------------------\n");
    printf("\t\t\t                 Trickets %d\n", tickets);
    printf("\t\t\t---------------------------------------------------------------\n");
    printf("\n\t\t\t  ---------------------------------------------------------\n");
    printf("\t\t\t                 TOTAL COST: %.2lf   ", TotalCost);
    printf("\n\t\t\t  ---------------------------------------------------------\n");

    printf("\t\t\t---------------------------------------------------------------\n");
    printf("\t\t\t                 Full Name: %s\n", FullName);
    printf("\t\t\t---------------------------------------------------------------\n");
    printf("\t\t\t                 Phone Number:: %s\n", PhoneNumber);
    printf("\t\t\t---------------------------------------------------------------\n");
    printf("\t\t\t                 Email Address:: %s\n", EmailAddress);
    printf("\t\t\t---------------------------------------------------------------\n");
    printf("\t\t\t                 Address: %s\n", Address);
    printf("\t\t\t---------------------------------------------------------------\n");
    printf("\n\t\t\t  ---------------------------------------------------------\n");

    Write_Logs(T_username, "Price - Reservation");
    Features_Services();
}

int TrainPriceCalculation()
{
    // TrainList();

    char *BatticoloaLine[] = {
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

    char *TrincomaleeLine[] = {
        "Kantale",
        "Tambalagamuwa",
        "ChinaBay",
        "Trincomalee"};

    char *TalaimannarLine[] = {
        "Cheddikulam",
        "MaduRoad",
        "Murunkan",
        "Mannar",
        "Pesalai",
        "Talaimannar",
        "TalaimannarPier"};

    char *CoastLine[] = {
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

    char *MainLine[] = {
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

    char *NothernLine[] = {
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

    printf("\n\t\t\t  ---------------------------------------------------------\n");
    printf("\n\t\t\tTrain Lane: \n");
    printf("\n\t\t\t  ---------------------------------------------------------\n");

    printf("\t\t\t [1] Nothern Lane\n");

    //[2] Matale Lane\n [3] BatticoloaLine\n [4] TrincomaleeLine\n [5] TalaimannarLine\n [6] CoastLine\n\n\n\n ");

    printf("\n\t\t\t  ---------------------------------------------------------\n");
    printf("\t\t\t                 [1]: NOTHERN LANE                             \n");
    printf("\t\t\t                 [2]: MATALE LANE                              \n");
    printf("\t\t\t                 [3]: BACTICALO LANE                           \n");
    printf("\t\t\t                 [4]: TRINCOMALEE LANE                         \n");
    printf("\t\t\t                 [5]: TALAIMANNAR LANE                         \n");
    printf("\t\t\t                 [6]: COAST LANE                               ");
    printf("\n\t\t\t  ---------------------------------------------------------\n");

    int selectlane;
    printf("\n\t\t\t  ---------------------------------------------------------\n");
    printf("\t\t\t                 SELECT LANE :  ");
    scanf("%d", &selectlane);
    printf("\n\t\t\t  ---------------------------------------------------------\n");
    printf("\n\n");

    switch (selectlane)
    {
    case 1:
        for (i = 0; i < 11; ++i)
        {
            printf("\t\t\t\t[%d] %s, \n", i + 1, NothernLine[i]);
        }
        printf("\n");
        printf("\n\t\t\t  ---------------------------------------------------------\n");

        break;
    case 2:
        for (i = 0; i < 12; ++i)
        {
            printf("\t\t\t\t[%d] %s, \n", i + 1, MainLine[i]);
        }
        printf("\n");
        printf("\n\t\t\t  ---------------------------------------------------------\n");
        break;

    case 3:
        for (i = 0; i < 10; ++i)
        {
            printf("\t\t\t\t[%d] %s, \n", i + 1, BatticoloaLine[i]);
        }
        printf("\n");
        printf("\n\t\t\t  ---------------------------------------------------------\n");
        break;

    case 4:
        for (i = 0; i < 4; ++i)
        {
            printf("\t\t\t\t[%d] %s, \n", i + 1, TrincomaleeLine[i]);
        }
        printf("\n");
        printf("\n\t\t\t  ---------------------------------------------------------\n");
        break;

    case 5:
        for (i = 0; i < 6; ++i)
        {
            printf("\t\t\t\t[%d] %s, \n", i + 1, TalaimannarLine[i]);
        }
        printf("\n");
        printf("\n\t\t\t  ---------------------------------------------------------\n");
        break;

    case 6:
        for (i = 0; i < 20; ++i)
        {
            printf("\t\t\t\t[%d] %s, \n", i + 1, CoastLine[i]);
        }
        printf("\n");
        printf("\n\t\t\t  ---------------------------------------------------------\n");
        break;

    default:
        printf("\t\t\t---------------------------------------------------------------\n");
        printf("\t\t\t                           WRONG INPUT          ");
        printf("\n\t\t\t---------------------------------------------------------------\n");
        TrainPriceCalculation();
        break;
    }

    int startingstation, endingstation, tickets, class;
    float ticketcost;

    printf("\n\t\t\t  ---------------------------------------------------------\n");
    printf("\t\t\t                     STARTING POINT: ");
    scanf("%d", &startingstation);
    printf("\t\t\t  ---------------------------------------------------------\n");
    printf("\t\t\t                     ENDING POINT: ");
    scanf("%d", &endingstation);
    printf("\t\t\t  ---------------------------------------------------------\n");
    printf("\t\t\t                     TICKETS: ");
    scanf("%d", &tickets);
    printf("\t\t\t  ---------------------------------------------------------\n");
    printf("\t\t\t             [1] - FIRST/LUXURY                            \n");
    printf("\t\t\t             [2] - SECOND/ECONOMY                          \n");
    printf("\t\t\t             [3] - THIRD/BUDGET                            \n");

    printf("\t\t\t  ---------------------------------------------------------\n");

    printf("\n\t\t\t  ---------------------------------------------------------\n");
    printf("\t\t\t                 SELECT CLASS :  ");
    scanf("%d", &class);
    printf("\n\t\t\t  ---------------------------------------------------------\n");
    printf("\n\n");

    // file pointer will be used to open/read the file
    FILE *file;
    FILE *TempFile;

    // used to store the filename and each line from the file
    char filename[FILENAME_SIZE] = "db_pricelist.txt";
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
        printf("\n\t\t\t  ---------------------------------------------------------\n");
        printf("\t\t\t                 ERROR: CLOUD NOT OPEN FILE                    ");
        printf("\n\t\t\t  ---------------------------------------------------------\n");
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
            printf("\t\t\tFile %d lines.\n", current_line - 1);
            printf("\t\t\tCouldn't find line %d.\n", read_line);
        }
        // if we've found the line the user is looking for, print it out
        else if (current_line == read_line)
        {
            keep_reading = false;
            // printf("\t\t\tLine:\n%s", buffer);
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
    char train_name[255];

    // open file for reading
    inputf = fopen("TempSysFile.txt", "r");

    fscanf(inputf, "%d %s %s %s %s", &r_userID, starting_station, ending_station, train_name, train_price);

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
        printf("\t\t\t---------------------------------------------------------------\n");
        printf("\t\t\t                           WRONG INPUT          ");
        printf("\n\t\t\t---------------------------------------------------------------\n");

        printf("\t\t\t  ---------------------------------------------------------\n");
        printf("\t\t\t             [1] - FIRST/LUXURY                            \n");
        printf("\t\t\t             [2] - SECOND/ECONOMY                          \n");
        printf("\t\t\t             [3] - THIRD/BUDGET                            \n");

        printf("\t\t\t  ---------------------------------------------------------\n");

        printf("\n\t\t\t  ---------------------------------------------------------\n");
        printf("\t\t\t                 SELECT CLASS :  ");
        scanf("%d", &class);
        printf("\n\t\t\t  ---------------------------------------------------------\n");
        printf("\n\n");

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
        }
    }

    // display detail

    printf("\t\t\t---------------------------------------------------------------\n");
    printf("\t\t\t                           DETAILS          ");
    printf("\n\t\t\t---------------------------------------------------------------\n");

    fscanf(inputf, "%d %s %s %s %s", &r_userID, starting_station, ending_station, train_name, train_price);
    printf("\t\t\t---------------------------------------------------------------\n");
    printf("\t\t\t                 Username: %s\n", T_username);
    printf("\t\t\t---------------------------------------------------------------\n");
    printf("\t\t\t                 Start: %s\n", starting_station);
    printf("\t\t\t---------------------------------------------------------------\n");
    printf("\t\t\t                 End: %s\n", ending_station);
    printf("\t\t\t---------------------------------------------------------------\n");
    printf("\t\t\t                 Train: %s\n", train_name);
    printf("\t\t\t---------------------------------------------------------------\n");
    printf("\t\t\t                 Trickets %d\n", tickets);
    printf("\t\t\t---------------------------------------------------------------\n");
    printf("\n\t\t\t  ---------------------------------------------------------\n");
    printf("\t\t\t                 TOTAL COST: %.2lf                    ", TotalCost);
    printf("\n\t\t\t  ---------------------------------------------------------\n");
    Write_Logs(T_username, "Price - Calculation");

    Features_Services();
}

void TrainList()
{
    char *filename = "TrainsDetails.txt";
    FILE *TrainsDetails = fopen(filename, "r");

    if (TrainsDetails == NULL)
    {
        printf("\n\t\t\t  ---------------------------------------------------------\n");
        printf("\t\t\t                 ERROR: CLOUD NOT OPEN FILE                    ");
        printf("\n\t\t\t  ---------------------------------------------------------\n");
        exit(0);
    }

    // read one character at a time and
    // display it to the output
    char ch;
    while ((ch = fgetc(TrainsDetails)) != EOF)
    {
        putchar(ch);
    }

    // close the file
    fclose(TrainsDetails);
    Write_Logs(T_username, "Train-List");
}
