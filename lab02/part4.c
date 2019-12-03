#include <stdio.h>

//Lab02 Part 4
//Matt Taylor

int main(void)
{
    double a, b;
    b = 2.0e20 + 1.0;
    a = b - 2.0e20;
    printf("%f \n", a);
    return 0;
}
    /*Declares 2 double type variables
    However the computer cannot keep track of enough decimal places to do the command correctly
    b has 21 digits in it, and the computer cannot store these many digits
    Therefore when it prints a, it cannot print the true number because it cannot store one that big
    So it only prints zero because that is the result of 2.0e20 - 2.0e20. The 1 gets left off
    Therefore the program prints 0.000000*/