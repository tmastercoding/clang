#include <stdio.h>

int main(){

    int max = 1000;
    int sum = 0;

    for(int num = 1; num < max; num++){
        if ((num % 3) || (num % 5)){
            sum += num;
        }
    }

    printf("%d\n", sum);

    return 0;
}