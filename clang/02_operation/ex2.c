#include <stdio.h>

int main() {

    int a,b;
    a = 10;
    b = 3;

    printf("a / b is: %.10f \n", ((float)a) / b); //해서는안될짓

    return 0;
}