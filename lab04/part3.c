#include <stdio.h>
/*  Lab04 Part 3
    Matt Taylor */
    
long array_sum(int A[], unsigned int n)
{
    int i;
    long sum = 0;
    for(i = 0; i < n; i++){                                 //Sums the digits in each place of array from index (0) to index (n-1)
       sum += A[i]; 
    }
    return sum;
}

int main(int argc, char *argv[])
{
    int array[1000], i, n;                                  //Declares array of size 1000 
    printf("Enter number of integers\n");
    scanf("%d", &n);
    if(n > 1000){                                           //Error message if n exceeds 1000
        printf("Error: number of integers exceeds 1000\n");
        goto done;                                          //Terminates rest of program if n exceeds 1000
    }
    printf("\nEnter integers\n");
    for(i = 0; i < n; i++)
    {
        scanf("%d", &array[i]);                             //Allows n amount of integer inputs
    }
    printf("Sum of integers is %li", array_sum(array, n));   //Calls function array_sum with inputs: array, n
    printf("\n");
    done:
    return 0;
}

/*  This program prompts the user for number of integers they will enter. Then gets user to input the integers
    It then calls the function 'array_sum' which has two inputs: integer array and unsigned integer.
    The array_sum function then computes the sum of all of the numbers in the array, using a for loop. The function then returns a
    long integer    */