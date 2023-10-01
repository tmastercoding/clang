#include <stdio.h>

int main(){
    int user_answer;

    printf("guess the number! \n");

    for (;;) {
        scanf("%d", &user_answer);;

        if (user_answer == 3) {

            printf("ur correct! \n");

            break;

        } else {

            printf("correct");

        }
    }
    return 0;
}