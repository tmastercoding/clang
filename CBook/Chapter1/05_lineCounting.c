#include <stdio.h>

int main(){
    int c, line, tab, blank, isBlank;
    // count newlines, blanks, tabs in input

    /*
    line = 0;
    tab = 0;
    blank = 0;

    while((c = getchar()) != '-'){
        if(c == '\n'){
            ++line;
        } else if(c == '\t'){
            ++tab;
        } else if(c == ' '){
            ++blank;
        }
    }

    printf("line: %d; tab: %d; blank: %d; \n", line, tab, blank);
    */

    // replaces multiple spaces into one
    /*
    isBlank = 0;
    while((c = getchar()) != '-'){
        if(c == ' '){
            isBlank = 1;
        } else{
            if(isBlank){
                putchar(' ');
                isBlank = 0;
            }
            putchar(c);
        }
    }
    */

    // displays tab to \t, backspace to \b, backslash to \\

    while((c = getchar()) != '-'){
        if(c == '\b'){
            puts("\\b");
        } else if(c == '\t'){
            puts("\\t");
        } else if(c == '\\'){
            puts("\\\\");
        } else{
            putchar(c);
        }
    }


    return 0;
}