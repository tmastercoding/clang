#include <stdio.h>
#include <stdlib.h>
#include <string.h>

size_t len(const char *s);
int strToInt(const char *s);

int main(){
    // declare variables

    char* number = (char *)malloc(10);
    scanf("%s", number);
    // printf("%s", number);
    printf("%d\n", strToInt(number));
    // number of times
    int times = 0;

    // size needed for getline
    size_t size = 0;

    // how many repeats
    int* repeat_arr = NULL;

    // input lines
    char* line = NULL;
    char** lines = NULL; 

    // tokenised data
    char* buffer;

    // seperator
    char sep[] = " ";
  
    // get input for times
    scanf("%d", &times);
    fflush(stdin);

    // malloc lines
    repeat_arr = (int*)malloc(times * sizeof( int ));
    // malloc lines
    lines = (char**)malloc(times * sizeof( char * ));

    // input
    for(int idx = 0; idx < times; idx++){
        getline(&line, &size, stdin);
        // tokenise
        buffer = strtok(line, sep);
        repeat_arr[idx] = atoi(buffer);
        // printf("repeat_arr[idx]: %d\n", repeat_arr[idx]);
        buffer = strtok(NULL, sep);

        // put into lines
        // printf("%zu %zu\n", len(buffer), strlen(buffer));
        lines[idx] = (char*)malloc(strlen(buffer) * sizeof(char));
        strcpy(lines[idx], buffer);
        // printf("size: %lu, strlen: %lu\n", size, strlen(line));
        lines[idx][strlen(buffer)-1] = '\0';
    }

    // output
    for(int idx = 0; idx < times; idx++){
        for(int jdx = 0; jdx < strlen(lines[idx]); jdx++){
            for(int kdx = 0; kdx < repeat_arr[idx]; kdx++){
                printf("%c", lines[idx][jdx]);
            }
        }
        printf("\n");
    }

    // free memory
    free(repeat_arr);

    for(int idx = 0; idx < times; idx++){
        free(lines[idx]);
    }

    free(lines);

    return 0;
}

size_t len(const char *s){
    size_t size = 0;

    while(*(s++) != '\0')
        size++;
    
    return size;
}

int strToInt(const char *s){
    int num = 0;
    int exponent = 0;
    int power = 1;
    for(int idx = len(s)-1; idx >= 0; idx++){
        power = 1;
        for(int jdx = 0; jdx < exponent; jdx++){
            power *= 10;
        }
        num += s[idx]-'0' * power;
        exponent++;
    }

    return num;
}