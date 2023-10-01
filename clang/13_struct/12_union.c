#include <stdio.h>

union A {
    int i;
    char j;
    short s;
};

int main(){
    union A a;

    a.i = 0x12345678;
    printf("%c\n", a.j);
    printf("%d\n", a.s);

    printf("%d\n", sizeof(a));

    return 0;
}