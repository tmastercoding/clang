#include <stdio.h>

int main(){
    float ave_score;
    float math, english, science, programming;

    printf("pls input each score: ");

    scanf("%f %f %f %f", &math, &english,
     &science, &programming); //input assigns to variables

    ave_score = 
        (math + english + science + programming) /4; // gets average score

    printf(" your average score is %f \n", ave_score);

    if (ave_score >= 90) { 
        printf("you are a great student \n");
    } else if (ave_score >= 30){
        printf("try harder! \n");
    } else {
        printf("howd u study!!! \n");
    }

    return 0;
}