#include <stdio.h>
#include <string.h>

int main(){
    // char buffer[100] = {'\0', };
    int size = 0;
    char c;
    int idx = 0;
    int sum = 0;

    scanf("%d", &size);
    fflush(stdin);

    while(( c = getchar() ) != '\n' ){
        sum += ( c - '0' );
        idx++;

        if(idx > size) break;
    }

    printf("%d\n", sum);

    return 0;
}