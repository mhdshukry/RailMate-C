#include <stdio.h>

int main()
{
    FILE *fptr;

    // Create a file on your computer (filename.txt)
    fptr = fopen("filename.txt", "r");

    //fprintf(fptr,"Hello saji \n");
    //fprintf(fptr, "Saji");
    //char readfile[255];

    //fscanf(fptr,"%s",&readfile);
    //printf("%s",readfile);

    // Close the file
    fclose(fptr);

    return 0;

    //scanf("%d",&name)
}