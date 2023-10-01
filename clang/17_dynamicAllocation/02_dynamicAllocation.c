#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv) {
    int student; // how many students
    int i, input;
    int *score; // students score arr
    int sum = 0; // total

    printf("Number of Students? : ");
    scanf("%d", &student);

    score = (int *)malloc(student * sizeof(int));
    // sizeof(int) = 4 bytes

    for(i = 0; i < student; i++){
        printf("Student %d's score : ", i);
        scanf("%d", &input);

        score[i] = input;
    }

    for(i = 0; i < student; i++){
        sum += score[i];
    }

    printf("total student's avg score : %d \n", sum / student);

    free(score);

    return 0; 
}