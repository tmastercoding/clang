#include <stdio.h>

int main(){
    int height, weight;

    printf(" pls input your height and weight: ");
    scanf("%d %d", &height, &weight);

    if (height >= 190 || weight >= 100) { //or is ||
        printf("you are a giant person. \n");
    }

    return 0;
}