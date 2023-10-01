#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv){
    int i, j, input, sum = 0;
    int subject, students;
    int **arr;
    // arr[subject][students]

    printf("Number of subjects: ");
    scanf("%d", &subject);

    printf("Number of students: ");
    scanf("%d", &students);

    arr = (int **)malloc(sizeof(int) * students);

    for(i = 0; i < subject; i++){
        arr[i] = (int *)malloc(sizeof(int) * students);
    }

    for(i = 0; i < subject; i++){
        printf("--------- subject %d score ---------- \n", i);
        printf("[ Debug ] i: %d\n", i);
        for(j = 0; j < students; j++){
            printf("[ Debug ] j: %d\n", j);

            printf("student %d score input: ", j);
            scanf("%d", &input);

            arr[i][j] = input;
        }
    }

    for(i = 0; i < subject; i++){
        sum = 0;
        for(j = 0; j < students; j++){
            sum += arr[i][j];
        }
        printf("subject%d avg score : %d\n", i, sum /students);
    }

    for(i = 0; i < subject; i++){
        free(arr[i]);
    }

    free(arr);

    return 0;
}