#include <stdio.h>

int main()
{
    FILE *Sample;

    Sample = fopen("sample.txt", "w");

    fscanf(Sample,"Hello world");

    fclose(Sample);
    
    return 0;
}