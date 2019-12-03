#include <stdio.h>

int is_prime(int k)
{
    int i, test;
    for(i = 2;i <= k / 2; ++i)
    {
        if(k % i == 0)
        {
            test = 1;
            break;
        }
    }
    if (test == 0){
        return 1;
    }
    else{
        return 0;
    }
}

int main(int argc, char *argv[])
{
    int x;
    printf("Enter a positive integer: ");
    scanf("%d",&x);
    if((is_prime(x)) == 1){
        printf("%d is a prime number\n", x);
    }
    else{
        printf("%d is not a prime number\n", x);
    }
    return 0;
}

/*  My code did not require the use of an array. It simply finds the remainder the input number dividedby every possible integer 
    up to k / 2. If the remainder is 0 at any time during the loop, this means that the input number is divisible by a number and 
    is therefore not a prime number. If it gets through the whole loop without finding a remainder of 0, it is a prime number */