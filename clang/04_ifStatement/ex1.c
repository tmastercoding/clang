#include <stdio.h>

int main(){
    int i;

    printf("input a number: ");
    scanf("%d", &i);

    if (i == 7) {
        printf("You have picked the lucky number 7");
    }

    return 0;
}