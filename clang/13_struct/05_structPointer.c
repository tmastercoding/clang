#include <stdio.h>

int add_one(int *a);

struct TEST {
    int c;
};

int main(){
    struct TEST t;
    struct TEST *pt = &t;

    // changes the var c that pt is pointing to to 0
    pt->c = 0;
    
    // add one to t's c
    add_one(&t.c);

    printf("t.c: %d \n", t.c);

    return 0;
}

int add_one(int *a) {
    *a += 1;

    return 0;
}