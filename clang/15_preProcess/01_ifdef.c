#include <stdio.h>
#define MAC

int main() {

//
#ifdef MAC
    printf("I's Machintoch \n");
#endif

//
#ifdef WINDOW
    printf("I's WINDOW \n");
#endif

    return 0;
}