#include <stdio.h>

// prototype
int customer(int bank);

int shop( int money, int* bank ) {

    *bank -= money;


    return 0;
}

int main(){

    int bank = -11100;

    bank = customer(bank);

    printf("today deposit: US$%d \n", bank );

    shop( 1000, &bank );

    /*

    int a = 10;
    int* p;

    p = &a;
    */

    printf("today deposit: US$%d \n", bank );

    return 0;
}

int customer(int bank){
    bank += 10000;
    return bank;
}
