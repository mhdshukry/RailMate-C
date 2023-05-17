#include <stdio.h>

void Features_Services();
void Write_Logs(char T_username[255], char action[20]);
void view_details_parcel(char start[], char finish[], float parcelcost, float parcel_weight, float unit_price);
void Parcel();
void view_parcel_history();
void calculate_price_parcel_reservation();
// Global variables
char T_username[255];

void Parcel()
{
    int parceloption;

    do
    {
        printf("\n\n\n");
        printf("\n\t\t\t  **-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**\n");
        printf("\n\t\t\t        =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=");
        printf("\n\t\t\t        =         [ 1 ]   PARCEL                    =");
        printf("\n\t\t\t        =         [ 2 ]   PARCEL HISTORY            =");
        printf("\n\t\t\t        =         [ 3 ]   MAIN MENU                 =");
        printf("\n\t\t\t        =         [ 0 ]   EXIT                      =");
        printf("\n\t\t\t        =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n");
        printf("\n\t\t\t  **-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**\n");

        printf("\n\t\t\t  ---------------------------------------------------------\n");
        printf("\t\t\t                PLEASE, MAKE A CHOISE : ");
        scanf("%d", &parceloption);
        printf("\t\t\t  ---------------------------------------------------------\n");

        switch (parceloption)
        {
        case 1:
            calculate_price_parcel_reservation();
            break;
        case 2:
            view_parcel_history();
            break;
        case 3:
            Features_Services();
            break;
        case 4:
            printf("\n\t\t\t  ---------------------------------------------------------\n");
            printf("\t\t\t                         EXITING SERVICES                    ");
            printf("\n\t\t\t  ---------------------------------------------------------\n");
            exit(0);
            break;

        default:
            printf("\n\t\t\t  ---------------------------------------------------------\n");
            printf("\t\t\t                         WRONG INPUT                    ");
            printf("\t\t\t                         TRY AGAIN                    ");
            printf("\n\t\t\t  ---------------------------------------------------------\n");
            break;
        }
    } while (parceloption != 5);
}

void calculate_price_parcel_reservation()
{
    float parcel_weight, unit_price;

    printf("\n\t\t\t  ---------------------------------------------------------\n");
    printf("\t\t\t                ENTER THE WEIGHT OF THE PARCEL : ");
    scanf("%f", &parcel_weight);
    printf("\t\t\t  ---------------------------------------------------------\n");

    if (parcel_weight < 1.0)
    {
        unit_price = parcel_weight * 125.00;
    }
    else if (parcel_weight < 5.0 || parcel_weight >= 1.00)
    {
        unit_price = parcel_weight * 100.00;
    }
    else if (parcel_weight < 10.0 || parcel_weight >= 5.00)
    {
        unit_price = parcel_weight * 75.00;
    }
    else if (parcel_weight > 10.0)
    {
        unit_price = parcel_weight * 65.00;
    }
    else
    {
        printf("\n\t\t\t  ---------------------------------------------------------\n");
        printf("\t\t\t                         WRONG INPUT                    ");
        printf("\t\t\t                         TRY AGAIN                    ");
        printf("\n\t\t\t  ---------------------------------------------------------\n");
    }

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

    int startingstation, endingstation;
    float parcelcost;
    float fixed_parcel_cost = 100.00;
    parcelcost = fixed_parcel_cost * unit_price;

    switch (selectlane)
    {
    case 1:
        for (i = 0; i < 11; ++i)
        {
            printf("\t\t\t\t[%d] %s, \n", i + 1, NothernLine[i]);
        }
        printf("\n");
        printf("\n\t\t\t  ---------------------------------------------------------\n");

        printf("\n\t\t\t  ---------------------------------------------------------\n");
        printf("\t\t\t                     STARTING POINT: ");
        scanf("%d", &startingstation);
        printf("\t\t\t  ---------------------------------------------------------\n");
        printf("\t\t\t                     ENDING POINT: ");
        scanf("%d", &endingstation);
        printf("\t\t\t  ---------------------------------------------------------\n");
        view_details_parcel(NothernLine[startingstation], NothernLine[endingstation], parcelcost, parcel_weight, unit_price);

        break;
    case 2:
        for (i = 0; i < 12; ++i)
        {
            printf("\t\t\t\t[%d] %s, \n", i + 1, MainLine[i]);
        }
        printf("\n");
        printf("\n\t\t\t  ---------------------------------------------------------\n");

        printf("\n\t\t\t  ---------------------------------------------------------\n");
        printf("\t\t\t                     STARTING POINT: ");
        scanf("%d", &startingstation);
        printf("\t\t\t  ---------------------------------------------------------\n");
        printf("\t\t\t                     ENDING POINT: ");
        scanf("%d", &endingstation);
        printf("\t\t\t  ---------------------------------------------------------\n");
        view_details_parcel(MainLine[startingstation], MainLine[endingstation], parcelcost, parcel_weight, unit_price);

        break;

    case 3:
        for (i = 0; i < 10; ++i)
        {
            printf("\t\t\t\t[%d] %s, \n", i + 1, BatticoloaLine[i]);
        }
        printf("\n");
        printf("\n\t\t\t  ---------------------------------------------------------\n");

        printf("\n\t\t\t  ---------------------------------------------------------\n");
        printf("\t\t\t                     STARTING POINT: ");
        scanf("%d", &startingstation);
        printf("\t\t\t  ---------------------------------------------------------\n");
        printf("\t\t\t                     ENDING POINT: ");
        scanf("%d", &endingstation);
        printf("\t\t\t  ---------------------------------------------------------\n");
        view_details_parcel(BatticoloaLine[startingstation], BatticoloaLine[endingstation], parcelcost, parcel_weight, unit_price);

        break;

    case 4:
        for (i = 0; i < 4; ++i)
        {
            printf("\t\t\t\t[%d] %s, \n", i + 1, TrincomaleeLine[i]);
        }
        printf("\n");
        printf("\n\t\t\t  ---------------------------------------------------------\n");

        printf("\n\t\t\t  ---------------------------------------------------------\n");
        printf("\t\t\t                     STARTING POINT: ");
        scanf("%d", &startingstation);
        printf("\t\t\t  ---------------------------------------------------------\n");
        printf("\t\t\t                     ENDING POINT: ");
        scanf("%d", &endingstation);
        printf("\t\t\t  ---------------------------------------------------------\n");
        view_details_parcel(TrincomaleeLine[startingstation], TrincomaleeLine[endingstation], parcelcost, parcel_weight, unit_price);

        break;

    case 5:
        for (i = 0; i < 6; ++i)
        {
            printf("\t\t\t\t[%d] %s, \n", i + 1, TalaimannarLine[i]);
        }
        printf("\n");
        printf("\n\t\t\t  ---------------------------------------------------------\n");

        printf("\n\t\t\t  ---------------------------------------------------------\n");
        printf("\t\t\t                     STARTING POINT: ");
        scanf("%d", &startingstation);
        printf("\t\t\t  ---------------------------------------------------------\n");
        printf("\t\t\t                     ENDING POINT: ");
        scanf("%d", &endingstation);
        printf("\t\t\t  ---------------------------------------------------------\n");

        view_details_parcel(TalaimannarLine[startingstation], TalaimannarLine[endingstation], parcelcost, parcel_weight, unit_price);
        break;

    case 6:
        for (i = 0; i < 20; ++i)
        {
            printf("\t\t\t\t[%d] %s, \n", i + 1, CoastLine[i]);
        }
        printf("\n");
        printf("\n\t\t\t  ---------------------------------------------------------\n");

        printf("\n\t\t\t  ---------------------------------------------------------\n");
        printf("\t\t\t                     STARTING POINT: ");
        scanf("%d", &startingstation);
        printf("\t\t\t  ---------------------------------------------------------\n");
        printf("\t\t\t                     ENDING POINT: ");
        scanf("%d", &endingstation);
        printf("\t\t\t  ---------------------------------------------------------\n");
        view_details_parcel(CoastLine[startingstation], CoastLine[endingstation], parcelcost, parcel_weight, unit_price);
        break;

    default:
        printf("\t\t\t---------------------------------------------------------------\n");
        printf("\t\t\t                           WRONG INPUT          ");
        printf("\n\t\t\t---------------------------------------------------------------\n");
        break;
    }
}

void view_details_parcel(char start[], char finish[], float parcelcost, float parcel_weight, float unit_price)
{
    printf("\n\n\n\t\t\t  ---------------------------------------------------------\n");
    printf("\n\t\t\t                                DETAILS                      ");
    printf("\n\t\t\t  -----------------------------------------------------------");
    printf("\n\t\t\t                 STARTING AREA    : %s", start);
    printf("\n\t\t\t                 ENDING AREA      : %s", finish);
    printf("\n\t\t\t                 PARCEL WEIGHT    : %.2lf", parcel_weight);
    printf("\n\t\t\t                 UNIT PRICE       : %.2lf", unit_price);
    printf("\n\t\t\t                 TOTAL COST       : %.2lf", parcelcost);
    printf("\n\t\t\t  ---------------------------------------------------------\n");

    FILE *parcel_ = fopen("db_parcel.txt", "a");
    // Time
    time_t rawtime;
    struct tm *timeinfo;
    if (parcel_ == NULL)
    {
        printf("\n\t\t\t  ---------------------------------------------------------\n");
        printf("\t\t\t                         FILE MISSING                          ");
        printf("\n\t\t\t  ---------------------------------------------------------\n");
        exit(0);
    }
    time(&rawtime);
    timeinfo = localtime(&rawtime);
    // printf("Current local time and date: %s", asctime(timeinfo));
    fprintf(parcel_, "username: %s \nFrom: %s\nTo: %s\n Parcel weight: %.2lf\nUnit Price: %.2lf\n\nTotal Cost: %.2lf\n time: %s\n", T_username, start, finish, parcel_weight, unit_price, parcelcost, asctime(timeinfo));
    fclose(parcel_);

    Write_Logs(T_username, "Parcel reserved");
}

void view_parcel_history()
{
    char *filename = "db_parcel.txt";
    FILE *parcel_view = fopen(filename, "r");

    if (parcel_view == NULL)
    {
        printf("\n\t\t\t  ---------------------------------------------------------\n");
        printf("\t\t\t                 ERROR: CLOUD NOT OPEN FILE                    ");
        printf("\n\t\t\t  ---------------------------------------------------------\n");
        exit(0);
    }

    // read one character at a time and
    // display it to the output
    char ch;
    while ((ch = fgetc(parcel_view)) != EOF)
        putchar(ch);

    // close the file
    Write_Logs(T_username, "Parcel - View");
    fclose(parcel_view);

    char yesorno[2];

    printf("\n\t\t\t  ---------------------------------------------------------\n");
    printf("\t\t\t          DO YOU WANT TOO CONTINUE [TYPE 'Y' OR 'N'] : ");
    scanf("%s", yesorno);
    printf("\t\t\t  ---------------------------------------------------------\n");

    int value_y, value_Y;
    int value_n, value_N;
    value_y = strcmp(yesorno, "y");
    value_Y = strcmp(yesorno, "Y");
    value_N = strcmp(yesorno, "N");
    value_n = strcmp(yesorno, "n");
    if (value_y == 0 || value_Y == 0)
    {
        Features_Services();
    }
    else if (value_N == 0 || value_n == 0)
    {
        printf("\n\t\t\t  ---------------------------------------------------------\n");
        printf("\t\t\t                                SYSTEM EXIT                    ");
        printf("\n\t\t\t  ---------------------------------------------------------\n");
        exit(0);
    }
    else
    {
        printf("\n\t\t\t  ---------------------------------------------------------\n");
        printf("\t\t\t                         WRONG INPUT                           ");
        printf("\n\t\t\t                      REDIRECT MAIN MENU                       ");
        printf("\n\t\t\t  ---------------------------------------------------------\n");
        Features_Services();
    }
}