/*
 * @details - Reads a set of text lines
 *            Prints the longest one
*/

#include <stdio.h>
#define MAXLINE 1000 // max input line size

int get_line(char line[], int maxline);
void copy(char to[], char from[]);

int main(){
    int len; // current line length
    int max; // max line length
    char line[MAXLINE]; // current input line
    char longest[MAXLINE]; // largest input line

    max = 0;
    while((len = get_line(line, MAXLINE)) > 0){
        if(len > max){
            max = len;
            copy(longest, line);
        }
    }
    if(max > 0){
        printf("%s", longest);
    }

    return 0;
}

// read a line into s, return length
int get_line(char s[], int lim){
    int c,i;

    for(i = 0; i < lim-1 && (c = getchar()) != EOF && c!='\n'; ++i){
        s[i] = c;
    }
    if(c == '\n'){
        s[i] = c;
        ++i;
    }
    s[i] = '\0';
    
    return i;
}

// copu 'from into' 'to'; assuming to is larger than from
void copy(char to[], char from[]){
    int i;

    i = 0;
    while((to[i] = from[i]) != '\0')
        i++;
}
