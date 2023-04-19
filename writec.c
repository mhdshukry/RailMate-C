#include <stdio.h>

int main()
{
    FILE *fptr;

    //get input from user and write on file

    int num, num2;

    printf("Enter num1: ");
    scanf("%d",&num);

    printf("Enter num2: ");
    scanf("%d", &num2);

    // Open a file in writing mode
    fptr = fopen("filename.txt", "a");

    // Write some text to the file
    fprintf(fptr, "Some text %d\n", num);
    fprintf(fptr, "Some text %d\n", num2);
    fprintf(fptr, "Some text 3\n");
    fprintf(fptr, "Some text 4\n");
    fprintf(fptr, "Some text 5\n");

    // Close the file
    fclose(fptr);

    return 0;
}