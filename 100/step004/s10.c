#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * @author Tay Oh
 * @date 18.02.24 
 * @implements |
 *    - max :  gets a max value from a
 *             array
 *    - main : gets an array of scores
 *             gets max value of arr
 *             fakes scores with formula
 *             gets fake avg using fake scores
*/

int max(int* numbers, int size);

int main(){
    // set variables
    int count = 3;
    char buffer[100];
    char sep[] = {' '};
    char c = 0;

    int idx = 0;
    float total = 0;
    float avg;

    // set up scores arr
    int* scores = (int* )malloc(sizeof(int) * count);

    // get input
    while(c != '\n'){
        c = getchar();
        buffer[idx++] = c;
    }

    // split string
    char* p = strtok(buffer, sep);
    idx = 0;

    while(idx < count){
        scores[idx++] = atoi(p);
        p  = strtok(NULL, sep);
    }
    
    // gets max of arr
    int max_num = max(scores, count);
    // printf("%d\n", max_num);

    // uses formula to get avg
    for(idx = 0; idx < count; idx++){
        // printf("%f\n", (double)scores[idx]/max_num*100);
        total += (double)scores[idx]/max_num*100;
    }

    avg = total/count;

    // output
    printf("%f\n", avg);
    free(scores);

    return 0;
}

int max(int* numbers, int size){
    // set max as first
    int max_num = numbers[0];

    // loops arr
    for(int idx = 1; idx < size; idx++){
        // if greater, set as max
        if(max_num < numbers[idx]){
            max_num = numbers[idx];
        }
    }

    return max_num;
}