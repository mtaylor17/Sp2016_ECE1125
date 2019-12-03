#include <stdio.h>

//Lab 04 Part 1
//Matt Taylor

int gcd(int a, int b)
{
    int c;
    while(a != 0)
    {
        c = a;
        a = b % a;
        b = c;
    }
    printf ("In GCD, u and v are: %d and %d\n", a, b);
    return b;
}

int main()
{
    int u, v;
    printf("Enter two numbers\n");
    scanf("%d %d", &u, &v);
    printf("You entered %d and %d\n", u, v);
    printf("gcd of %d and %d is %d\n", u, v, gcd(u,v));
    printf("u and v are %d and %d\n", u, v);
    return 0;
}

/*  The main function calls for 2 integers, then calls the function "gcd" to return a value to print.
    The gcd function has 2 input integers and eturns an integer.   */