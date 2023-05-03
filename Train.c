#include <stdio.h>
#include <stdlib.h>

void TrainList();
void PriceCalculation();

int main()
{
    TrainList();
    PriceCalculation();
    return 0;
}

void PriceCalculation()
{
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
            printf("\t\t [%d.] %s\n", i+1, MainLine[i]);
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