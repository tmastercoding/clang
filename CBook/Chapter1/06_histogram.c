#include <stdio.h>
#include <stdlib.h>
#define END '-'

int main(){
    int length, idx;
    char c;

    idx = 0;

    scanf("%d", &length);
    fflush(stdin);
    int* wordLens = (int *)malloc(length*sizeof(int));

    for( int i = 0; i < length; i++){
        wordLens[i] = 0;
    }

    while((c = getchar()) != END){
        if(c == '\n' || c == '\t' || c == ' '){
            idx++;
        } else{
            ++wordLens[idx];
        }
    }

    for( idx = 0; idx < length; idx++){
        printf("%d: ", idx+1);
        for(int jdx = 0; jdx < wordLens[idx]; jdx++){
            putchar('-');
        }

        putchar('\n');
    }

    return 0;
}