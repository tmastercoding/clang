#include <stdio.h>

int main(){
    int a;
    int b;
    int* const pa = &a;

    *pa = 3;
    // pa = &b; error

    return 0;
}