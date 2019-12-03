#include <stdio.h>
/*  Lab05 Part 2
    Matt Taylor */

int factorial(int x)
{
    int c, fact = 1;
    for(c = 1; c <= x; c ++){
    fact = fact * c;
    }
    return fact;
}

int main(int argc, char *argv[])
{
    int n, y;
    printf("Enter a number\n");
    scanf("%d", &n);
    if(n < 0){
        printf("Error: negative number entered\n");
    }
    else{
    for(y = 0; y <= n; y ++){
        printf("%d %d %d %d\n", y, y*y, y*y*y, factorial(y));
    }
    
    y = 0;
    while(y <= n){
        printf("%d %d %d %d\n", y, y*y, y*y*y, factorial(y));
        y ++;
    }
    
    y = 0;
    do{
        printf("%d %d %d %d\n", y, y*y, y*y*y, factorial(y));
        y ++;
    } while(y <= n);
    
    y = 0;
    here:
    if(y > n){
        goto done;
    }
    else{
        printf("%d %d %d %d\n", y, y*y, y*y*y, factorial(y));
        if(y <= n){
            y ++;
            goto here;
        }
    }
    }
    done:
    return 0;
}