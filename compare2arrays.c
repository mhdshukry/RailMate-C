#include <stdio.h>

char compareArray(char a[],b[], int size);

    // function to compare array elements
    char compareArray(int a[], int b[], int size)
{
    int i;
    for (i = 0; i < size; i++)
    {
        if (a[i] != b[i])
            return 1;
    }
    return 0;
}

int main(void)
{

    char PassWord[255] = "hello";
    char PassWordC[255] = "hello";

    /* to compare two arrays*/
    if (compareArray(PassWord, PassWordC, 255) == 0)
    {
        printf("Arrays have same elements.\n");
    }
    else
    {
        printf("Arrays have different elements.\n");
    }

    return 0;
}
