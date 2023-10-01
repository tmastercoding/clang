#include <stdio.h>

int main() {
    int a;
    a = 127;

    printf("a is %o in %d. \n", 8, a);
    printf("a is the same as %d, being %d. \n", 10, a);
    printf("a is the same as %d, being %x. \n", 16, a);

    return 0;
}