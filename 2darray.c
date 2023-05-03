#include<stdio.h>
int main(){
   /* 2D array declaration*/
   char disp[2][2];
   /*Counter variables for the loop*/
   int i, j;
   for(i=0; i<2; i++) {
      for(j=0;j<2;j++) {
         printf("Enter value for disp[%d][%d]:", i, j);
         scanf("%s", disp[i][j]);
      }
   }
   //Displaying array elements
   printf("Two Dimensional array elements:\n");
   for(i=0; i<2; i++) {
      for(j=0;j<2;j++) {
         printf("%s ", disp[i][j]);
         if(j==2){
            printf("\n");
         }
      }
   }
   return 0;
}