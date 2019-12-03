#include <stdio.h>
/*  Lab04 part 2
    Matt Taylor */

void print_int(int x) 
{
    if (x < 0) {                    //Checks for negative number
        putchar('-');
        x = -x;
    }
    if (x / 10 != 0){               //Nested function
        print_int(x / 10);
    }
    putchar((x % 10) + '0');        //putchar: adding integer number to numerical equivalent of '0'
}

int main(int argc, char *argv[])
{
    int n;
    printf("Enter an Integer\n");
    scanf("%d", &n);
    print_int(n);                   //calls for print_int function
    printf("\n");
    return 0;
}

/*  For the print_int function, I nested the print_int function within itself so that it could keep dividing the integer
    by 10 until, if it was divided once more by 10, it would equal zero. Then it would exit the 'if' statement and continue
    with the nested program. This would give me the first digit of the integer which I could then use the modulus operator on (% 10) 
    to find the digit to use in the 'putchar' function. It would then exit that nested function and continue with the outside 
    print_int function.
    For the 'putchar' function, I used the integer from the modulus operator that I found before and added it to the 
    numerical equivalent of "0." This only works for C because the numbers 0-9 line up next to each other. */
