#include <stdio.h>

int main(){
    int height, weight;

    printf("pls input height and weight: ");
    scanf("%d %d", &height, &weight);

    if (height >= 190 || weight >= 100){
        printf("you are a giant person. \n");
    } 
    if (!(height >= 190 || weight >= 100)){ // ! = not
        printf("You are not a giant person.");
    }

    return 0;
}