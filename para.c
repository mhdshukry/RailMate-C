#include<stdio.h>
 
int main() {
   char inputString[128], c;
   int index = 0;
  
   printf("Enter a multi line string( press ';' to end input)\n");
   while((c = getchar()) != ';'){
       inputString[index++] = c;
   }
   inputString[index] = '\0';
 
   printf("Input String = %s", inputString);
  
   return 0;
}