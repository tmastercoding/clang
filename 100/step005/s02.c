#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(){
    char buffer[100] = {'\0',};
    char c;
    int idx = 0;

    // strlen method
    scanf("%s", buffer);
    fflush(stdin);
    printf("%lu\n", strlen(buffer));

    // getchar method
    while((c = getchar())!= '\n'){
        idx++;
    }
    printf("%d\n", idx);

    // sizeof method
    char* text = (char* )malloc(idx * sizeof(char));
    strcpy(text, buffer);

    printf("%lu\n", sizeof(text));


    return 0;
}