
#include <stdio.h>

int main(void)
{

    FILE *inputf;
    char Username[255];
    char Name[255];
    char Password[255];
        // open file for reading
        inputf = fopen("kirupan10", "r");

    // display detail
    printf("\nCustomer Details:\n");
    fscanf(inputf, "%[^\n]s %[^\n]s %[^\n]s", &Username, &Name, &Password);
    printf("Username: %d\n", Username);
    printf("Name: %d\n", Name);
    printf("Password: %s\n", Password);

    printf("\nEnd of file.\n");

    // close connection
    fclose(inputf);

    return 0;

}