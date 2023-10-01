#include <stdio.h>

int main(){
    int a;
    int* pa = &a;

    printf("pa address: %p \n", pa);
    printf("(pa - 1) address: %p \n", pa-1);

    return 0;
}