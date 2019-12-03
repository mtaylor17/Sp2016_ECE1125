#include <stdio.h>

//Lab02 Part 3
//Matt Taylor

int main(int argc, char *argv[])
{
    char C = 'r';
    printf("%c %d\n", C, C);
    C = C + 1;
    printf("%c %d\n", C, C);
    return 0;
}
//C = C + 1 adds a value of 1 to the integer value of the character
//Then when we print it, we are printing a character of value 115, which corresponds to "s"