#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int find(char* str, int len, char c){
    for(int idx = 0; idx < len; idx++){
        if(str[idx] == c){
            return idx;
        }
    }
    return -1;
}

int main(){
    // char lower_alpha[26] = {'\0', };
    char c = 'a';
    int idx = 0;
    char* line = NULL;
    size_t len = 0;

    getline(&line, &len, stdin);
    // printf("%lu\n", strlen(line));

    for(int idx = 0; idx < 26; idx++){
        printf("%d ", find(line, strlen(line), c));
        c++;
    }

    printf("\n");

    free(line);

    return 0;
}