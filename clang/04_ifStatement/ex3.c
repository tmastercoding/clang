/* fail or pass*/

#include <stdio.h>

int main() {
    int score;

    printf("input your score: ");

    scanf("%d", &score);

    if (score >= 90){
        printf("you passed!");
    }
    
    if (score <= 90) {
        printf("you failed \n");
    }

    return 0;
}