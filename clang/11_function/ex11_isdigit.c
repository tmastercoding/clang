#include <stdio.h>

int main(){
    char input;
    scanf("%c", &input);

    if( 48 <= input && input <= 57 ) {
        printf("%c is a digit\n", input);
    } else {
        printf("%c is not a digit :(\n", input);
    }

    return 0;
}