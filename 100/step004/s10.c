#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int max(int* numbers, int size);

int main(){
    int count = 3;
    char buffer[100];
    char sep[] = {' '};
    char c = 0;
    int idx = 0;
    float total = 0;
    float avg;
    int* scores = (int* )malloc(sizeof(int) * count);

    while(c != '\n'){
        c = getchar();
        buffer[idx++] = c;
    }

    char* p = strtok(buffer, sep);
    idx = 0;

    while(idx < count){
        scores[idx++] = atoi(p);
        p  = strtok(NULL, sep);
    }
    
    int max_num = max(scores, count);
    // printf("%d\n", max_num);

    for(idx = 0; idx < count; idx++){
        // printf("%f\n", (double)scores[idx]/max_num*100);
        total += (double)scores[idx]/max_num*100;
    }

    avg = total/count;
    printf("%f\n", avg);
    free(scores);

    return 0;
}

int max(int* numbers, int size){
    int max_num = numbers[0];
    for(int idx = 1; idx < size; idx++){
        if(max_num < numbers[idx]){
            max_num = numbers[idx];
        }
    }
    return max_num;
}