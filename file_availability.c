#include <stdio.h>
void File_Availability(char filename[30])
{

    // char *filename = "bugs.txt";
    FILE *file_availability = fopen(filename, "r");
    if (file_availability == NULL)
    {
        printf("file %s is missing\n", file_availability);
    }
    else
    {
        printf("SELF TEST : File Availability : %s - [OK] \n", filename);
    }
}