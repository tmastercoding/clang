#include <stdio.h>

int main(){
    int i;
    int subject, score;
    double sum_score = 0;

    printf("how many subjects' score will you input? ");
    scanf("%d", &subject);

    printf("\n pls input the score for each subject");

    for (i = 1; i <= subject; i++){ // loops for every subject
        printf("subject %d: ", i);
        scanf("%d", &score);

        sum_score += score;
    }

    printf("your average score for all subjects is : %.2f \n", 
            sum_score/subject);

    return 0;
}