#include <stdio.h>
#include <time.h>

int main()
{
    int i;
    for(i = 10; i >= 0; i--)
    {
        printf("%i\n",i); // Write the current 'countdown' number
        delay(1000); // Wait a second
    }
    return 0;
}