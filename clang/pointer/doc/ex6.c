#include <stdio.h>

int main(){
    int a;
    int b;
    const int* pa = &a;

    // *pa = 3; error
    pa = &b; // correct
    
    return 0;
}