#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int main()
{
    // declaration of local variable op;
    int op;
    
    do
    {
        // welcome message
        printf("\n\n\n");
        printf("\t-------------------------------------------------------------------------------------\n");
        printf("\t\t---------------------- Welcome To - RailMate Lanka ------------------\n");
        printf("\t\t------------------- Advanved online reservation system --------------\n");
        printf("\t-------------------------------------------------------------------------------------\n\n\n");

        printf("\t\t------------------------------ Menu ---------------------------------\n\n");
        printf("\t\t\t-------------------[ 1 ] Login -------------------\n");
        printf("\t\t\t-------------------[ 2 ] Register ----------------\n");
        printf("\t\t\t-------------------[ 0 ] Exit --------------------\n\n");

        printf("\n\n\t\t Please, Make a choice : ");

        
        scanf("%d", &op); // accepts a numeric input to choose the operation

        // use switch statement to call an operation
        switch (op)
        {
        case 1:
            // Add two numbers
            
            break; // break the function

        case 2:
            // Subtract two numbers
            
            break; // break the function

        case 3:
            // Multiplication of the numbers
            
            break; // break the function

        case 4:
            // Division of the numbers
            
            break; // break the function

        case 5:
            // getting square of a number
            
            break; // break the function

        case 6:
            // getting the square root of the number
            
            break; // break the function

        case 7:
            printf(" You chose: Exit");
            exit(0);
            break; // break the function

        default:
            printf(" Something is wrong!! ");
            break;
        }
        printf(" \n \n ********************************************** \n \n");
    } while (op != 7);

    return 0;
}