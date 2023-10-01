
#include <stdio.h>
int main(){
    int num;

    printf("input a number: ");

    scanf("%d", &num);

    if (num == 7) {
        printf("its a lucky number 7! \n");
    } else if (num ==4) {
        printf("its a deadly number 4 \n");
    } else {
        printf("its just a number %d \n", num);
    
    }
    
    return 0;
}