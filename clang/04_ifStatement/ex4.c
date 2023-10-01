#include <stdio.h>

int main() {
    int num;

    printf("input any number");

    scanf("%d", &num);

    if (num == 7) {
        printf("it is a lucky number 7! \n ");
    } else {
        printf("its just a normal number %d \n", num);
    }

    return 0;
}