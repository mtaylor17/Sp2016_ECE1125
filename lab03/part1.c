#include <stdio.h>

//Lab 03 Part 1
//Matt Taylor

int main(int argc, char *argv[])
{
    int x, y, i = 1, gcd;
    printf("Enter two integers:\n");
    scanf("%d %d", &x, &y);
    while(i<=x || i<=y)
    {
        if(x % i == 0 && y % i == 0){    //Checking whether i is a factor of both numbers
        gcd = i;
        }
        
        i = i + 1;
    }
    printf("GCD of %d and %d is %d\n", x, y, gcd);
    return 0;
}