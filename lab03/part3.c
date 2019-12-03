#include <stdio.h>

/*  Lab03 Part 2
    Matt taylor */

int main(int argc, char *argv[])
{
    int n, y = 0, factorial = 1, c = 1;
    printf("Enter a number\n");
    scanf("%d", &n);
    if(n < 0)
    {
        printf("error: negative number entered\n");
    }
    else{
    while(y <= n)
    {
            while(c <= y){
            factorial = factorial * c;
            c++;
            }
        printf("%d %d %d %d\n", y, y*y, y*y*y, factorial);
        y = y + 1;
        factorial = 1;
        c = 1;
    }
    }
    return 0;
}