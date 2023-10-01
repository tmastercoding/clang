#include <stdio.h>

int main(){
    int a;

    printf("input any number: ");

    scanf("%d", &a);

    if (a>= 10 && a < 20) {
        printf("%d is over 10 and under 20 \n", a); // and is &&
    }
    
    return 0;
}