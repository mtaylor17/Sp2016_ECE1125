#include <stdio.h>

//Lab02 Part 5
//Matt Taylor

int main(void)
{
    double number = 3.4E307;
    printf("number is %e\n", number);
    number=number * 10000.0;
    printf("number multiplied by 10000 is %e\n", number);
    return 0;
}
//The number in the first print line is printed fine, using the exponential format
//The resultant number of number=number*10000.0 is 3.4e+311 which exceeds the range of double type numbers
//Thus the numeber is too big to execute
//So it is considered as infinity