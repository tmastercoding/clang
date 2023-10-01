#include <stdio.h>

struct Human {
    int age;
    int height;
    int weight;
};

int main(){
    struct Human Psi[2];

    Psi[0].age = 99;
    Psi[0].height = 185;
    Psi[0].weight = 80;

    Psi[1].age = 10;
    Psi[1].height = 18;
    Psi[1].weight = 9999;

    printf("\n");
 
    printf("== Psi [0] info ==\n");
    printf("- age:     %4d \n", Psi[0].age);
    printf("- height:  %4d \n", Psi[0].height);
    printf("- weight:  %4d \n", Psi[0].weight);

    printf("\n");

    printf("== Psi [1] info ==\n");
    printf("- age:     %4d \n", Psi[1].age);
    printf("- height:  %4d \n", Psi[1].height);
    printf("- weight:  %4d \n", Psi[1].weight);

    return 0;
}