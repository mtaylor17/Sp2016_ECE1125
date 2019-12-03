#include <stdio.h>
#include <stdlib.h>
#include <time.h>
/*  Lab06 Part 5
    Matt Taylor */

int func(void)
{
    int roll, status = 1, test = 0;
    while(status != 0 && status <= 1001){
        if(status == 1001){
            test = 1;
        }        
        roll = random() % 6;
        if(roll < 2){
            status -= 1;
        }
        else{
            status += 1;
        }
    }
    if(test == 1){
        return 1;
    }
    else{
        return -1;
    }
}


int main(int argc, char *argv[])
{
    srandom(time(NULL));
    int success = 0, failure = 0, return_val, N = 10000, i;
    float probability;
    for(i = 0; i < N; i ++){
        return_val = func();
        if(return_val == -1){
            failure += 1;
        }
        else
            success += 1;
        }
    probability = (float)success / ((float)success +(float)failure);
    printf("You succeeded %d times\nYou failed %d times\nYour probablility of success is %f\n", success, failure, probability);
    return 0;
}

/*  In main I seeded my random number generator as NULL. I then called the experimental function 10000 times in a "for" loop.
    Within this loop, I checked whether or not the function returned a value of -1 or 1. If it returns -1, then the variable "failure"
    increments by +1 and if it returns a 1, the variable "success" increments by +1. After this I then calculated the probability of 
    success and a float variable "probability" to this value. Then I printed the results.
    
    In the experimental function, "func()," I set the status of the person to 1 i.e. the first rung on the ladder. I ran a while loop
    such that as long as the person hasn't reached the 1001st rung (success) or the 0th rung (failure), they continue to draw random 
    numbers using the random() function. I use the modulus operator to turn the long integer random number into a value of 0-6 which 
    corresponds to the values of 1-6 on a dice. I then use if-else statements to either increment the status (up 1 rung) or decrement
    it (down one rung) dependent on which number they drew. I also run another if statement such that if the person has reached the 1000th
    rung, the value of 1 is assigned to the variable test. Once it exits this while loop, I run an if statement to see if the value of 
    test is 1 or 0. If it is 1, the function returns a value of 1. If it is zero, the function returns a value of 0.    */