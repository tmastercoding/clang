#include <stdio.h>

int main(){
    int input;

    printf("Mypet upgrade\n");
    printf("What will u do?\n");
    printf("1. feed\n");
    printf("2. wash\n");
    printf("3. sleep\n");

    scanf("%d", &input);

    switch (input) {
        case 1:
            printf("delicious!\n");
            
        case 2:
            printf("so freshening!\n");
            
        case 3:
            printf("zzz...\n");
            
        default:
            printf("i dont get ur command. BarkBark!\n");
            
    }
 

    return 0;
}