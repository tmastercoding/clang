#include <stdio.h>

int main(){
    int a;
    int* pa;
    pa = &a;

    printf("pa\'s address: %p \n", pa);
    printf("(pa+1)\'s address: %p \n", pa + 1);

    return 0;
}