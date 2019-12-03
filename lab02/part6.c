#include <stdio.h>

//Lab02 Part 6
//Matt Taylor

int main(void)
{
	int x, y;
	char c;
	
	printf("enter first number:\n");
	scanf("%d", &x);
	
	printf("enter second number:\n");
	scanf("%d", &y);

	printf("enter an operator:\n");
	scanf("\n%c", &c);

	if (c == '*') {
		printf("%d %c %d is %d \n", x, c, y, x * y);
	}
	else if (c == '/') {
		printf("%d %c %d is %d \n", x, c, y, x / y);
	}
	else if (c == '+') {
		printf("%d %c %d is %d \n", x, c, y, x + y);
	}
	else if (c == '-') {
		printf("%d %c %d is %d \n", x, c, y, x - y);
	}
	else if (c == '%') {
		printf("%d %c %d is %d \n", x, c, y, 
		x % y);
	}
	else {
		printf("Unknown operator %c\n", c);
		printf("%d %c %d is 0\n", x, c, y);
	}
	return 0;
}

/*When an integer is entered, the program rounds it down to the nearest integer and then skips the rest of the commands
leaving variables y and c undefined */
