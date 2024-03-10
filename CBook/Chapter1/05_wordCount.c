#include <stdio.h>

#define IN 1 // inside a word
#define OUT 0 // outside a word

int main(){
    int c, nl, nw, nc, state;

    state = OUT;
    nl = nw = nc = 0;

    /* count words
    while((c = getchar()) != '-'){
        ++nc;
        if(c == '\n')
            ++nl;
        if(c == ' ' || c == '\n' || c == '\t')
            state = OUT;
        else if (state == OUT){
            state = IN;
            ++nw;
        } 
    }

    printf("%d %d %d\n", nl, nw, nc);
    */

    // sep words with '\n'
    while((c = getchar()) != '-'){
        state = IN;
        if(c == ' ' || c == '\n' || c == '\t')
            state = OUT;
        if (state == IN){
            putchar(c);
        } else{
            putchar('\n');
        }
            
    }
    return 0;
}