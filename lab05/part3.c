#include <stdio.h>
/*  Lab05 Part 3
    Matt Taylor */

int convert_base(int x, int base, char printable_digits[64])
{
    int i = 0;
    if(x <= 0 || base <= 0){
        return -1;
    }
    else{
        while(x != 0){
            printable_digits[i] = x % base;
            switch(printable_digits[i]){
                case 0: printable_digits[i] = 48; break;
                case 1: printable_digits[i] = 49; break;
                case 2: printable_digits[i] = 50; break;
                case 3: printable_digits[i] = 51; break;
                case 4: printable_digits[i] = 52; break;
                case 5: printable_digits[i] = 53; break;
                case 6: printable_digits[i] = 54; break;
                case 7: printable_digits[i] = 55; break;
                case 8: printable_digits[i] = 56; break;
                case 9: printable_digits[i] = 57; break;
                case 10: printable_digits[i] = 65; break;
                case 11: printable_digits[i] = 66; break;
                case 12: printable_digits[i] = 67; break;
                case 13: printable_digits[i] = 68; break;
                case 14: printable_digits[i] = 69; break;
                case 15: printable_digits[i] = 70; break;
                case 16: printable_digits[i] = 71; break;
                case 17: printable_digits[i] = 72; break;
                case 18: printable_digits[i] = 73; break;
                case 19: printable_digits[i] = 74; break;
                case 20: printable_digits[i] = 75; break;
                case 21: printable_digits[i] = 76; break;
                case 22: printable_digits[i] = 77; break;
                case 23: printable_digits[i] = 78; break;
                case 24: printable_digits[i] = 79; break;
                case 25: printable_digits[i] = 80; break;
                case 26: printable_digits[i] = 81; break;
                case 27: printable_digits[i] = 82; break;
                case 28: printable_digits[i] = 83; break;
                case 29: printable_digits[i] = 84; break;
                case 30: printable_digits[i] = 85; break;
                case 31: printable_digits[i] = 86; break;
                case 32: printable_digits[i] = 87; break;
                case 33: printable_digits[i] = 88; break;
                case 34: printable_digits[i] = 89; break;
                case 35: printable_digits[i] = 90; break;
                
            }
            x = x / base;
            i ++;
        }
    return i;
    }
}

int main(int argc, char *argv[])
{
    int x, i, base, y;
    char conversion_array[64];
    printf("Enter a number to convert\n");
    scanf("%d", &x);
    printf("Enter base to convert number to\n");
    scanf("%d", &base);
    convert_base(x, base, conversion_array);
    y = convert_base(x, base, conversion_array);
    if(y == -1){
        printf("Error: You have violated one of the following:\n- Base = 0\n- Base is negative\n- Number = 0\n- Number is negative\n");
    }
    else{
        for(i = y - 1; i >= 0; i --){
            printf("%c", conversion_array[i]);
        }
    }
    printf("\n");
    return 0;
}

/*  Error checking: If either the number or the base are 0 or negative, the function returns a value of -1.
    The main function checks if the convert_base function returned an i value or -1. If it returns a -1, it displays an error message.
    If it returns the i value, this is deemed as a successful conversion and thus it will print the conversion  */