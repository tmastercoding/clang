#include <stdio.h>

struct HUMAN {
    int age;
    int height;
    int weight;
    int gender;
};

int Print_Status(struct HUMAN human);


int main(){
    struct HUMAN Adam = {31, 182, 75, 0};
    struct HUMAN Eve = {27, 166, 48, 1};

    Print_Status(Adam);
    Print_Status(Eve);

    return 0;
}

int Print_Status(struct HUMAN human){
    if( human.gender ){
        printf("FEMALE\n");
    } else{
        printf("MALE\n");
    }

    printf("AGE: %d / HEIGHT: %d / WEIGHT : %d \n", human.age, human.height, human.weight);

    if (human.gender == 0 && human.height >= 170) {
        printf("HE IS A WINNER!!\n");
    } else if (human.gender == 0 && human.height < 170){
        printf("Height doesn\'t matter :)\n");
    }

    printf("---------------------------------------\n");

    return 0;
}

