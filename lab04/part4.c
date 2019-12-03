#include <stdio.h>
#include <math.h>

/*  Lab04 Part 4
    Matt Taylor */
    
double absolute(double y)
{
    if(y < 0){
        y = -y;
    }
        return y;
}
 
double mysqrt(double x)
{
    double precision = 0.0000000000001;
    double num, x1;
    if (x <= 0){
        if (x == 0){
            return 0;
        }
        else{
            return NAN;
        }        
    }
    else{
        x1 = x;
        num = x / 2;
        while(1){
            x1 = num - (num * num - x) / (2 * num);
            if(absolute(num - x1) < precision){
                break;
            }
            num = x1;
            }
        return x1;
        }
}

int main(int argc, char *argv[])
{
    double x;
    printf("Enter a number\n");
    scanf("%lf", &x);
    printf("Root is %.14f\n", mysqrt(x));
    return 0;
}

/*  In main, I prompt the user to input a number. The program then reads this input into a double. It then calls for the 
    mysqrt function to print the root.
    
    In the mysqrt function, I initiate the precision to be to the 14th decimal, equivalent to a double's normal precision. 
    I then check if the number is either zero (where the function then returns a value of 0 and then terminates), or a negative
    (where the function then returns a value of -1 and then terminates). If the number is not zero, nor less than zero, then it
    enters a 'while true' loop, where the only way to exit the loop and return a number is when the precision has reached the
    14th decimal. 
    
    I then carry out the Newton Raphson method, where x1 = x0 - (f(x)) / (df(x)). For f(x), this is the original function,
    being f(x) = x^2 - x. The derivative, df(x) is df(x) = 2x. I then compute the sum in the while true loop until the 
    precision is equal to 14 decimals. After this, it returns the root which is printed in main*/