/* Libraries */
#include <stdio.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>
#include <stdbool.h>

// files and functions
#include "TrainReservation.c"
#include "TrainPriceCalculation.c"
#include "TrainList.c"
#include "Reservation.c"
#include "ViewUser.c"
#include "CreateUser.c"
#include "LoginUser.c"
#include "Features_Services.c"
#include "support.c"
#include "Bugs.c"

// constants for size of char arrays to store filename, the line from the file
#define FILENAME_SIZE 1024
#define MAX_LINE 2048

/* Functions */
void ViewUser(char T_username[]);
int LoginUser();
int CreateUser(void);
void Features_Services();
void ViewReservation();
void Reservation();
void Profile(char T_username[]);
char EditPersonalDetails(char T_username[]);
void TrainList();
int PriceCalculation(int S_Station, int E_Station, int S_Class, int Person);

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
char LoginStatus[255];
int RegisterStatus;

