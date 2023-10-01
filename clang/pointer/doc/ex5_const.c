#include <stdio.h>

int main(){
    int a = 10;
    int b = 89;

    int* ptr = a;

    int* p;
    p = &a;

    int const *ptr2 = a;

    // wrong
    // *ptr2 = 3;

    // right
    ptr2 = &b;

    a = 90;
    b = 1000;

    int* const ptr3 = &a;

    *ptr3 = 10;

    ptr3 = &b;

    const int* const ptr4=&a;
    ptr4 = &b;
    *ptr4 = 11;
    



    return 0;
}