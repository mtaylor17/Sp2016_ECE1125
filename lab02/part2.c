#include <stdio.h>

//Lab 02 Part 2
//Matt Taylor

int main(int argc, char *argv[])
{
    int x = 123456789;
    int y = 1000;
    
    printf("%d + %d = %d\n", x, y, x + y);
    printf("%d * %d = %f\n", x, y, (double)x * y);
    printf("%d // %d = %f\n", x, y, (double)x / y);
    printf("%d %% %d = %d\n", x, y, x % y);
    printf("%d / %d = %f\n", x, y, (double)x / y);      
    
    //Running this program without using typecasting causes significant figures for the results to be limited
    //Because the variables are all in the integer data type
    //To modify the program, I converted the data type of some of the numbers to double type 
    //For the print functions 2, 3, and 5, I used typecasting - made x a double type number
    //This is to increase the computer's precision to 14 digits to not cut off numbers
    //I left print line 1 as integer numbers because adding 1000 to 123456789 does not exceed the limit of integer numbers
    //I left print line 3 as integer numbers because modulus operator is only applicable with integer division
    
    return 0;
}