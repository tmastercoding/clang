#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct _Scores{
    float mark;
    float grade;
} Scores;


int main(){
    const int size = 20;
    int idx = 0;
    Scores score[size];
    char* buffer = NULL;
    size_t buffer_size = 0;
    const char sep = ' ';
    const int size_of_grade = 9;
    float total = 0;
    float total_of_mark = 0;
    
    while(idx < size){
        printf("idx: %d ", idx);
        buffer = NULL;
        buffer_size = 0;

        score[idx].grade = 0.0f;
        score[idx].mark = 0.0f;

        getline(&buffer, &buffer_size, stdin);

        strtok(buffer, &sep);
        score[idx].mark = atoi(strtok(NULL, &sep));
        char* temp = strtok(NULL, &sep);

        switch(temp[0]){
            case 'A':
                score[idx].grade = (temp[1] == '+')? 4.5: 4.0;
                break;
            case 'B':
                score[idx].grade = (temp[1] == '+')? 3.5: 3.0;
                break;
            case 'C':
                score[idx].grade = (temp[1] == '+')? 2.5: 2.0;
                break;
            case 'D':
                score[idx].grade = (temp[1] == '+')? 1.5: 1.0;
                break;
            case 'P':
                score[idx].mark = 0.0;
                break;
            default:
                break;
        };
        // printf("%f %f\n", score[idx].mark, score[idx].grade);

        idx++;
    }

    idx = 0;
    while(idx < size){
        total += (score[idx].mark*score[idx].grade);
        total_of_mark += score[idx].mark;
        idx++;
    }

    printf("%f", total/total_of_mark);
    
    return 0;
}