#include <stdio.h>
/*  Lab06 Part 3
    Matt Taylor */

struct time             //Global variable
{
    int hour;
    int minutes;
    int seconds;
};

struct time elapsed_time(struct time time1, struct time time2)
{
    struct time elapsed;
    elapsed.hour = time2.hour - time1.hour;
    elapsed.minutes = time2.minutes - time1.minutes;
    elapsed.seconds = time2.seconds - time1.seconds;
    
    if(elapsed.seconds < 0){
        elapsed.seconds = 60 + (time2.seconds - time1.seconds);
        elapsed.minutes -= 1;
    }
    
    if(elapsed.minutes < 0){
        elapsed.minutes = 60 + elapsed.minutes;
        elapsed.hour -= 1;
    }
    
    if(elapsed.hour < 0){                       //Midnight crossing subtraction
        elapsed.hour = 23 + elapsed.hour;
    }

    return elapsed;
}

int main(int argc, char *argv[])
{
    struct time time1, time2, elapsed;
    printf("Enter time1 (h:m:s):    ");
    scanf("%d:%d:%d", &time1.hour, &time1.minutes, &time1.seconds);
    if(time1.hour > 24 || time1.hour < 0 || time1.minutes > 60 || time1.minutes < 0 || time1.seconds > 60 || time1.seconds < 0){
        printf("Invalid time entered");
        return 0;
    }
    printf("Enter time2 (h:m:s):    ");
    scanf("%d:%d:%d", &time2.hour, &time2.minutes, &time2.seconds);
    if(time2.hour > 24 || time2.hour < 0 || time2.minutes > 60 || time2.minutes < 0 || time2.seconds > 60 || time2.seconds < 0){
        printf("Invalid time entered\n");
        return 0;
    }
    elapsed = elapsed_time(time1, time2);
    printf("Time 2 - Time 1 = %02d:%02d:%02d\n", elapsed.hour, elapsed.minutes, elapsed.seconds);
    return 0;
}
/*  NOTE: time must be entered with colons between numbers, e.g. 3:25:59, NOT 3 25 59
    Negative times or times that exceed the limit of the category (e.g. 61 minutes) are treated as errors and will return an error
    message     */