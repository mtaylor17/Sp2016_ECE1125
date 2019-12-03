#include <stdio.h>
#include <stdlib.h>
#include <time.h>
/*  Lab06 Part 1
    Matt Taylor */

void find_maximum(int A[], int n, int *idx_max, int *max_val)
{
    *max_val = A[0];
    int i;
    for(i = 1; i < n; i ++){
        if(A[i] > *max_val){
            *max_val = A[i];
            *idx_max = i;
        }
    }
}

void find_minimum(int A[], int n, int *idx_min, int *min_val)
{
    *min_val = A[0];
    int i;
    for(i = 1; i < n; i ++){
        if(A[i] < *min_val){
            *min_val = A[i];
            *idx_min = i;
        }
    }   
}

int main(int argc, char *argv[])
{
    srandom(time(NULL)); 
    int max_value, max_index, min_value, min_index, i;
    int random_numbers[10000];
    printf("Generating 10000 random numbers...\n\n");
    for(i = 0; i < 10000; i++){
        random_numbers[i] = random();
        printf("%d ", random_numbers[i]);
    }
    find_maximum(random_numbers, 10000, &max_index, &max_value);
    find_minimum(random_numbers, 10000, &min_index, &min_value);
    printf("\n\nMax location: %d Max value: %d\n", max_index, max_value);
    printf("Min location: %d Min value: %d\n\n", min_index, min_value);
    return 0;
}