#include <stdio.h>

int main(){
    int arr[3] = {1, 2, 3};

    printf("arr\'s identity : %p \n", arr);
    printf("arr[0]\'s address: %p \n", &arr[0]);

    // arr = &arr[0]
    return 0;
}