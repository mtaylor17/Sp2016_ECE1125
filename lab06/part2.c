#include <stdio.h>
#include <float.h> 
/*  Lab06 Part 2
    Matt Taylor */

float x_to_the_n(int x, int n)
{
    int i;
    float y;
    y = (float)x;
    
    if (n == 0){
        return 1.0;
    }
    
    if(n < 0){     
        n = -n;
        for(i = 1; i < n; i ++){
            y = y * x;
        }
        return 1 / y;
    }
    
    else{
        for(i = 1; i < n; i ++){
            y = y * x;
        }
    return y;
    }
}

int main(int argc, char *argv[])
{
    int x, n;
    float y;
    printf("Enter an integer and its power\n");
    scanf("%d %d", &x, &n);
    y = x_to_the_n(x, n);
    if(y > FLT_MAX){                                //Checking if number is too large to calculate
        printf("Number too large to calculate\n");    //Printing error message
    }  
    else{
        printf("= %f\n", y);
    }
    return 0;
}

/*  I used an if statement in the main function such that if the result is larger than the maximum float number (FLT_MAX) then it would
    print an error message. I ran an if statement in the x_to_the_n function such that if the power was negative, it would convert it
    to a positive, run the calculation, then take the inverse of the number. If the power is zero, the program will automatically return
    a value of 1.   */