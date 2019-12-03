#include <stdio.h>
#include <stdbool.h>
/*  Lab05 Part 4
    Matt Taylor */
    
int main(int argc, char *argv[])
{
    int p, i, primeindex = 2, x;
    bool isprime;
    printf("Enter Range:\n");
    scanf("%d", &x);
    int primes[x];
    if (x < 0){
        printf("Error: negative number entered");
        return 0;
    }
    switch(x){
        case 0: printf("No prime numbers in this range"); return 0;
        case 1: printf("No prime numbers in this range"); return 0;
        case 2: printf("Primes:\n2\n"); return 0;
    }
    primes[0] = 2;
    primes[1] = 3;
    for(p = 5; p <= x; p = p + 2){
        isprime = true;
        for(i = 0; isprime == true && p / primes[i] >= primes[i]; i ++){
            if(p % primes[i] == 0){
                isprime = false;
            }
        }
        if(isprime == true){
            primes[primeindex] = p;
            ++primeindex;
        }
    }
    printf("Primes:\n");
    for(i = 0; i < primeindex; i ++){
        printf("%d\n", primes[i]);
    }
    printf("\n");
    return 0;
    
}
