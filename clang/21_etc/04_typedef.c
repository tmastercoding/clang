#include <stdio.h>

// function that adds two variables together
int add(int a, int b) {return a+b;}

// CAL_TYPE means int
typedef int CAL_TYPE;

// Padd means int* function(int parameter, int parameter)
typedef int (*Padd)(int, int);

// Arrays means int arr[10]
typedef int Arrays[10];

int main() {
    // assign a integer
    CAL_TYPE a = 10;

    // create an int array with 10 items
    Arrays arr = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 0 };
    
    // create an pointer pointing to a 
    // integer function that has two integer vars
    Padd ptr = add;

    // print results/data of the variables
    printf( "a: %d\n", a );
    printf( "arr[3] : %d\n", arr[3] );
    printf( "add(3, 5) : %d \n", ptr(3, 5) );

    return 0;
}