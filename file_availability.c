#include <stdio.h>
#include <time.h>
void File_Availability(char filename[30])
{
    FILE *file_availability = fopen(filename, "r");
    if (file_availability == NULL)
    {
        printf("file %s is missing\n", filename);
    }
    else
    {
        printf("\t\t\tSELF TEST : File Availability : %s - [OK] \n", filename);
    }
}

