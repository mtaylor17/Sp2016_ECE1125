#include <stdio.h>

/*  Lab03 Part 4
    Matt taylor */
    
int main(int argc, char *argv[])
{
    int x, total = 0, reverse, singledigit;
    printf("enter a number\n");
    scanf("%d", &x);
    if(x < 0){
        x = x * -1;
    }
    while (x != 0)
    {
       reverse = reverse * 10;
       reverse = reverse + x % 10;
       x = x / 10;
    }
    while(reverse != 0)
    {
        singledigit = reverse % 10;
        reverse = reverse / 10;
        switch(singledigit)
        {
            case 0: total = total + 0; printf("0"); break;
            case 1: total = total + 1; printf("1"); break;
            case 2: total = total + 2; printf("2"); break;
            case 3: total = total + 3; printf("3"); break;
            case 4: total = total + 4; printf("4"); break;
            case 5: total = total + 5; printf("5"); break;
            case 6: total = total + 6; printf("6"); break;
            case 7: total = total + 7; printf("7"); break;
            case 8: total = total + 8; printf("8"); break;
            case 9: total = total + 9; printf("9"); break;
        }
    if(reverse != 0){
        printf(" + ");
    }
    else{
    printf(" = %d\n", total);
    }
    }
    return 0;
}