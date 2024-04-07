#include <stdio.h>

int fahr_to_celsius(int fahr);

int main(){
    int fahr;
    int lower, upper, step;

    lower = 0;
    upper = 300;
    step = 20;

    fahr = lower;
    while(fahr <= upper){
        printf("%d\t%d\n", fahr, fahr_to_celsius(fahr));
        fahr += step;
    }

    return 0;
}

// call by value, doesn't recieve actual var
int fahr_to_celsius(int fahr){
    int celsius;
    celsius = 5 * (fahr-32) / 9;

    return celsius;
}