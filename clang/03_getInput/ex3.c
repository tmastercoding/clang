#include <stdio.h>

int main() {
    char ch; // character

    short sh; //int
    int i;
    long lo;

    float fl; //real number
    double du; 
    // character
    printf("char input: ");
    scanf("%c", &ch);


    // intiger
    printf("short input: ");
    scanf("%hd", &sh);

    printf("int input: ");
    scanf("%d", &i);

    printf("long input: ");
    scanf("%ld", &lo);
    
    // real number
    printf("float input: ");
    scanf("%f", &fl);

    printf("double input: ");
    scanf("%lf", &du);

    printf("char : %c, short: %d, int: %d ", ch, sh, i);
    printf("long : %ld, float : %f, double : %f \n", lo, fl,  du);

    return 0;
}