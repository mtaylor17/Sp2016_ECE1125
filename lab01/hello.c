#include <stdio.h>

/* Hello world 
 * by Matt Taylor.
 * Then compute a sum. 
 * Then calculate volume for a box.
 */
 

int main(int argc, char *argv[])
{
	printf("Hello world!\nWritten by Matt Taylor\n");
	printf("Now I will compute a sum...\n");
	int x,y,z;
	x=10;
	y=20;
	z=x+y;
	printf("x is %d, y is %d, and z is %d\n", x,y,z);
	int h, w, d, vol;
	h = 11;
	w = 7;
	d = 14;
	vol = h * w * d;
	printf("The dimensions of the box are\nh = %dcm, w = %dcm, d = %dcm\n", h, w, d);
	printf("The volume of the box is %dcm^3\n", vol);
	return 0;
}