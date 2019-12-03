#include <stdio.h>

//Lab 02 Part 1
//Matt Taylor

int main(int argc, char *argv[])
{
    int x = 35;
    int y = 14;
    
    printf("%d + %d = %d\n", x, y, x + y);
    printf("%d * %d = %d\n", x, y, x * y);
    printf("%d // %d = %d\n", x, y, x / y);
    printf("%d %% %d = %d\n", x, y, x % y);
    printf("%d / %d = %f\n", x, y, (float)x / y); //Typecasting - made x a floating point number for this command
    
    return 0;
}