#include <stdio.h>

enum { RED, BLUE, WHITE, BLACK };

int main(){
    int pallete = RED;

    switch (pallete) {
        case RED:
            printf("pallete : RED \n");
            break;

        case BLUE:
            printf("pallete : BLUE \n");
            break;
    }
    return 0;
}