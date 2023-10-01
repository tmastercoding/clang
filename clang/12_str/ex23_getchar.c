#include <stdio.h>

int main(){
    int num;
    char ch;
    
    while( ( ch = getchar() ) != '\0' ) {
        if( ch == 'q' ) {
            break;
        }
        putchar( ch );
    }

    return 0;
}