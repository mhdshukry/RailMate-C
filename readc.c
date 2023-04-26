
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{

    FILE *inputf;
    char Username[255];
    char Name[255];
    char Password[255];
    char id[255];
        // open file for reading
        inputf = fopen("kirupan10", "r");

    // display detail
    printf("\nCustomer Details:\n");
    fscanf(inputf, "%s %s %s %s",&id, &Username, &Name, &Password);
    printf("ID: %s\n", id);
    printf("Username: %s\n", Username);
    printf("Name: %s\n", Name);
    printf("Password: %s\n", Password);

    printf("enter your password:");
char userinput[255];
scanf ("%s",&userinput);
int value;
value = strcmp(Password, userinput);
if (value == 0){
    printf("Both password are same\n");
}else{
    printf("password invalid..\n");
}
    printf("\nEnd of file.\n");

    // close connection
    fclose(inputf);

    return 0;

}