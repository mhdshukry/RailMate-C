/*
This function write check the file availability
simple file read "r" can check the file 
File is missing then program exicts

*/
#include <stdio.h>
#include <time.h>
void File_Availability(char filename[30])
{
    FILE *file_availability = fopen(filename, "r");
    if (file_availability == NULL)
    {
        printf("\n\t\t\t  ---------------------------------------------------------\n");
        printf("\t\t\t              SELF TEST : %s : FILE MISSING                   ", filename);
        printf("\n\t\t\t  ---------------------------------------------------------\n");
        exit(0);
    }
    else
    {
        printf("\t\t\t              SELF TEST : %s : FILE [OK]                   \n", filename);
    }
}

