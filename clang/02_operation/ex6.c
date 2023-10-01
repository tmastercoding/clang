#include <stdio.h>

int main() {
    int a = 2147483647; // 4 bytes all filled

    printf("a : %d\n", a);

    a++;
    printf("a : %d \n", a); 

    return 0;
}