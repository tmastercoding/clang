#include <stdio.h>

int main(){
    double i, j;

    printf("pls input 2 numbers to divide: ");

    scanf("%lf %lf", &i, &j);

    if (j == 0){
        printf("you cannot divide 0. \n");
        return 0;
    }
    printf("%f divided by %f is: %f \n", i, j, i/j);

    return 0;
}