#include <stdio.h>
/*  Lab06 Part4
    Matt Taylor */
    
int find_string(char *haystack, char *needle)
{
    int i = 0;
    for(;*haystack != 0; haystack ++){
        while(*needle != 0 && *needle == *haystack){
            needle ++;
            haystack ++;
        }
        if(*needle == 0){
            return i;
        }
        i ++;
    }
    return -1;

}

int main(int argc, char *argv[])
{
    int location;
    char haystack [1000], needle[1000];
    char *H = haystack, *N = needle;
    printf("Enter haystack: ");
    scanf("%[^\n]", H);
    printf("Enter needle: ");
    scanf("%s", N);
    location = find_string(H, N);
    if(location == -1){
        printf("Needle could not be found\n");
    }
    else{
        printf("Location is %d\n", location);
    }
    return 0; 
}

/*  We do not need to pass in the size of each string because we know that the last character of the array is a "\0" which is equivalent to
    the digit 0. This is used to terminate the array. In the find_string function, I used a for loop that will run until the 
    0 in the array is reached. Therefore it will exit the loop once it has gone through the length of the array.    */