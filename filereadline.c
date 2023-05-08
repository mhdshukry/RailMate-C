#include <stdio.h>

#define MAX_LINE_LENGTH 1000

int main()
{
    FILE *textfile;
    char line[MAX_LINE_LENGTH];

    textfile = fopen("TrainsDetails.txt", "r");
    if (textfile == NULL)
        return 1;
int count = 0;
    while (fgets(line, sizeof textfile, textfile) != NULL)
    {
        if (count == 7)
        {
            // use line or in a function return it
            // in case of a return first close the file with "fclose(file);"
            printf("Hello..!");
            break;
        }
        else
        {
            count++;
        }

        printf(line);
    }

    fclose(textfile);
    return 0;
}