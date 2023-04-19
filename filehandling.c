#include <stdio.h>
#include <stdlib.h>

int main()
{
   char firstName[] = "";

   printf("First Name: ");
   scanf("%s", firstName);
   printf("%s\n", firstName);

   char lastName[] = "";

   printf("Last Name: ");
   scanf("%s", lastName);
   printf("%s\n", lastName);

   /*
   
   char mailAddress[] = "";
   char password[] = "";
   char conformPassword[] = "";
   char address[] = "";
   double phoneNumber;
   FILE *fptr;

   // use appropriate location if you are using MacOS or Linux
   fptr = fopen("program.txt", "w");

   if (fptr == NULL)
   {
      printf("Error!");
      exit(1);
   }

   

   
   printf("Mail Address: ");
   scanf("%s", mailAddress);
   printf("%s\n", mailAddress);

   printf("Password: ");
   scanf("%s", password);
   printf("%s\n", password);

   printf("RE-Password: ");
   scanf("%s", conformPassword);
   printf("%s\n", conformPassword);

   printf("Address: ");
   scanf("%s", address);
   printf("%s\n", address);

   printf("Phone Number: ");
   scanf("%lf", &phoneNumber);
   printf("%lf\n", phoneNumber);

   //fputs(fptr, "01.\tFist name: %s\t\n02.\tLast name: %s\r\n03.\tMail Address: %s\r\n04.\tPassword: %s\r\n05.\tAddress: %s\r\n06.\tPhone Number: %lf\n", firstName, lastName, mailAddress, password, address, phoneNumber);
   //fputs("01.\tFist name: %s\r\n", fptr);
   fprintf(fptr, "%s", firstName);

   fclose(fptr);*/

   FILE *fp;

   fp = fopen("test.txt", "w+");
   fprintf(fp, "This is testing for fprintf: %s %s\r\n", firstName,lastName);
   fputs("This is testing for fputs...\n", fp);
   fclose(fp);

   return 0;
}