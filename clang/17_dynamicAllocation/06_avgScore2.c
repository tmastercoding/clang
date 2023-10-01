#include <stdio.h>
#include <stdlib.h>

void get_subject_average(int **arr, int numStudent, int numSubject);
void get_student_average(int **arr, int numStudent, int numSubject, int* avg);
void get_rank( int* avgs, int* rank, int size );

int main(int argc, char **argv){
    int i, j, input, sum = 0;
    int subject, students;
    int **arr;
    int* rank;
    int* avg;
    
    // going to make arr[subject][students]

    printf("Number of Subjects: ");
    scanf("%d", &subject);
    
    printf("Number of Students: ");
    scanf("%d", &students);

    arr = (int**)malloc(sizeof(int *) * subject); // sizeof(int *) = 8
    // (how many bytes between)malloc(how long is array)

    for(i = 0; i < subject; i++){
        arr[i] = (int *)malloc(sizeof(int) * students);
    }

    for(i = 0; i < subject; i++){
        printf("----------- subject %d score ------------\n", i);
        
        for(j = 0; j < students; j++){
            printf("student %d score input : ", j);
            scanf("%d", &input);

            arr[i][j] = input;
        }
    }

    rank = (int*)malloc(sizeof(int) * students); 
    avg = (int*)malloc(sizeof(int) * students); 

    for(int idx = 0; idx < students; idx++){
        rank[idx] = 1;
    }


    get_subject_average(arr, students, subject);
    get_student_average(arr, students, subject, avg);
    get_rank(avg, rank, students);

    printf("-----------ranking----------\n");

    for(int idx = 0; idx < students; idx++){
        printf("%d. student %d\n", rank[idx], idx+1);
    }

    for(i = 0; i < subject; i++){
        free(arr[i]);
    }
    free(arr);
    free(avg);
    free(rank);
    
    return 0;
}

void get_subject_average(int **arr, int numStudent, int numSubject){
    int i, j, sum;
    printf("---------- subject averages -----------\n");
    for(i = 0; i < numSubject; i++){
        sum = 0;
        for(j = 0; j < numStudent; j++){
            sum += arr[i][j];
        }
        printf("subject %d average score : %d \n", i, sum / numStudent);
    }

}

void get_student_average(int **arr, int numStudent, int numSubject, int* avg){
    int i, j, sum;
    for(i = 0; i < numStudent; i++){
        sum = 0;
        for(j = 0; j < numSubject; j++){
            sum += arr[i][j];
        }
        avg[i]= sum / numSubject;
    }
}

void get_rank( int* avgs, int* rank, int size ){
    for(int idx = 0; idx < size; idx++){
        for(int jdx = idx+1; jdx < size; jdx++){
            if(avgs[idx]< avgs[jdx]){
                rank[idx]++;
            }
        }
    }
}