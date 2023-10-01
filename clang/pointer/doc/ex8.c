#include <stdio.h>

int main(){
    int a;
    int b;
    const int* const pa = &a;

    // *pa = 3; error
    // pa = &b; error

    return 0;
}