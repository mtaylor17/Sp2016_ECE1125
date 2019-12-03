#include <stdio.h>
/*  Lab05 Part 1
    Matt Taylor */
    
int fibonacci(int n)
{
    int fib[n + 1], i, y;
    fib[0] = 1;
    fib[1] = 1;
    if(n < 2)
    {
        goto done;
    }
    else{
        for(i = 2; i <= n; ++ i)
        {
            fib[i] = fib[i - 2] + fib[i - 1];
        }
    }
    done:
    y = fib[n];
    return y;
}

int main(int argc, char *argv[])
{
    int x, i;
    printf("Enter an integer\n");
    scanf("%d", &x);
    for(i = 0; i < x; i ++)
    {
        printf("Fibonacci[%d] = %d\n", i, fibonacci(i));
    }
    return 0;
}