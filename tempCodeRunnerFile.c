/* Libraries */
#include <stdio.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>
#include <stdbool.h>

// files and functions
#include "file_availability.c"
#include "TrainReservation.c"
#include "supports.c"
#include "bugs.c"
#include "user.c"
#include "profile.c"
#include "services.c"
#include "parcelservices.c"
#include "write_logs.c"

// constants for size of char arrays to store filename, the line from the file
#define FILENAME_SIZE 1024
#define MAX_LINE 2048

#define MAX_LENGTH 255
#define NUM_STRINGS 20

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