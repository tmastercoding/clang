#include <stdio.h>

int main(){
    int i, sum = 0;

    for (i = 0; i < 20; i++) {
        sum += i; // adds number to the sum each time
    }

    printf("sum of 1 to 19: %d \n", sum);

    return 0;
}