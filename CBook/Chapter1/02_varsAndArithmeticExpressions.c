#include <stdio.h>

void fahrCels();
void celsFahr();

/* print Farenheit-Celsius table
   for fahr = 0, 20, ... , 300 */

int main(){
    fahrCels();
    celsFahr();
    return 0;
}

void fahrCels(){
       // int fahr, celsius;
    // float for accuracy
    float fahr, celsius;

    int lower, upper, step;

    lower = 0;
    upper = 300;
    step = 20;

    printf("Farenheit-Celsius Conversion Table\n");
    printf("-------------------------------------\n");
    printf("%3s %6s\n", "F", "C");

    fahr = lower;

    while(fahr <= upper){
        // cannot do 5/9: truncation
        // celsius = 5 * (fahr-32) / 9;

        // float can:
        celsius = (5.0/9.0) * (fahr-32);

        // printf("%d\t%d\n", fahr, celsius);

        // makes numbers have a length of %_d
        // printf("%3d %6d\n", fahr, celsius);

        // makes numbers have a length of %_d
        // then makes decimal numbers have a length of %nd._

        printf("%3.0f %6.1f\n", fahr, celsius);

        fahr += step;
    }

    /*
        %o : octal
        %x : hexadecimal
        %c : character
        %s : character string
        %% : percentage
    */
}

void celsFahr(){
    float celsius, fahr;
    int lower, upper, step;

    lower = 0;
    upper = 300;
    step = 20;

    printf("Celsius-Fahrenheit Conversion Table\n");
    printf("-------------------------------------\n");
    printf("%3s %6s\n", "C", "F");

    celsius = lower;

    while(celsius <= upper){
        fahr = ( (5.0/9.0) * celsius ) + 32;

        printf("%3.0f %6.1f\n", celsius, fahr);

        celsius += step;
    }
}