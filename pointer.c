#include <stdio.h>

int foo(char *a)
{
    
    *a = "100";
}

void main()
{
    char de[255];
    foo(de);

    // prints 11
    printf("%s", de);
}
