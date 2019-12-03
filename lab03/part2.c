#include <stdio.h>

/*  Lab03 Part3
    Matt Taylor */
    
int main(int argc, char *argv[])
{
    int x, negativecheck = 0, singledigit;
    printf("Enter a number\n");
    scanf("%d", &x);
    if(x < 0){
        x = x * -1;
        negativecheck = 1;
    }

    while (x != 0)
    {
        singledigit = x % 10;
        x = x / 10;
        switch(singledigit)
        {
            case 0: printf("zero "); break;
            case 1: printf("one "); break;
            case 2: printf("two "); break;
            case 3: printf("three "); break;
            case 4: printf("four "); break;
            case 5: printf("five "); break;
            case 6: printf("six "); break;
            case 7: printf("seven "); break;
            case 8: printf("eight "); break;
            case 9: printf("nine "); break;
        }
    }
    if(negativecheck){
        printf("negative");
    }
    printf("\n");        
    return 0;
    
}