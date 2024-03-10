#include <stdio.h>

// magic numbers: reader doesn't know
// symbolic const: replace magic numbers
#define LOWER 0
#define UPPER 300
#define STEP 20

// print farenheit-celsius table

int main(){
    int fahr;

    for(fahr = LOWER; fahr <= UPPER; fahr += STEP){
        printf("%3d %6.1f\n", fahr, (5.0/9.0) * (fahr-32));
    }

    return 0;
}