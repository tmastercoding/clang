#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
    char buffer[100];
    int idx = 0;
    char c;
    // Scanf method:
    // scanf("%s", buffer);

    // getchar method
    while((c = getchar()) != '\n'){
        buffer[idx++] = c;
    }

    // put buffer into malloc
    char* text = (char* )malloc(idx+1 * sizeof(char));
    strcpy(text, buffer);

    idx = 0;
    scanf("%d", &idx);

    printf("%c\n", text[idx-1]);

    return 0;
}