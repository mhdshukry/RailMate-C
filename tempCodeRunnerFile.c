/*c program to compare two arrays*/

#include <stdio.h>
#include<string.h>  

//function to compare array elements
char compareArray(char a[],char b[],int size)	{
	int i;
	for(i=0;i<size;i++){
		if(a[i]!=b[i])
			return 1;
	}
	return 0;
}

int main(){
	char a[255];
	char b[255];
	int value;

	

	printf("Enter your password: ");
    scanf("%s", &a);

    printf("Again Password: ");
    scanf("%s", &b);
	
	if (compareArray(a, b, 255) == 0){
		printf("Arrays have same elements.\n");
	}
	else{
		printf("Arrays have different elements.\n");
	}

	value=strcmp(a,b);  
   if(value==0)  
   printf("strings are same");  
   else  
   printf("strings are not same");  
		
	return 0;
}