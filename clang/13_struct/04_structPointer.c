#include <stdio.h>

struct TEST{
    int c;
    int *pointer;
};

int main(){
    struct TEST t;
    struct TEST *pt = &t;
    int i = 0;

    // change the c member that is pointed to by pt to 0
    // (*pt).c = 0;

    // printf("t.c: %d \n", t.c);
    t.pointer = &i;

    *t.pointer = 3;

    printf("i: %d \n", i);

    // change the c member that is pointed to by pt to 1
    // pt->c = 1;

    // printf("t.c : %d \n", t.c);
    *(pt->pointer) = 4;

    printf("i : %d \n", i);
    
    return 0;
}