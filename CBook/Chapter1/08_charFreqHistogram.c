#include <stdio.h>
#define END '-'
#define CHARMAX 255

int main(){
    int freq_char[CHARMAX] = {0,};
    int idx = 0;
    char c;

    while( (c = getchar()) != END){
        freq_char[c] += 1;
    }

    for(idx = 0; idx < CHARMAX; idx++){
        if(freq_char[idx]){
            printf("'%c': %d\n", idx, freq_char[idx]);
        }
    }

    return 0;
}