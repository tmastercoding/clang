#include <stdio.h>

// human structure
struct HUMAN{
    int age;
    int height;
    int weight;
    int gender;
};

// print general info of human struct
int print_status(struct HUMAN human);

int main(){
    // create Adam and Eve variables
    struct HUMAN Adam = {31, 182, 75, 0};
    struct HUMAN Eve = {27, 166, 48, 1};

    // print status of both people
    print_status(Adam);
    print_status(Eve);

    return 0;
}

// print general info of human struct
int print_status(struct HUMAN human){
    printf("-----------------------------------\n");
    
    // prints gender of human
    if(human.gender == 0){
        printf("MALE\n");
    } else{
        printf("FEMALE\n");
    }

    // prints age, height and weight of human
    printf("AGE: %d\n", human.age);
    printf("HEIGHT: %d\n", human.height);
    printf("WEIGHT: %d\n", human.weight);

    // if the human is male and 
    // is taller than 180cm, he wins
    // if not he loses
    if(human.gender == 0 && human.height >= 180) {
        printf("HE IS A WINNER!!\n");
    } else if (human.gender == 0 && human.height < 180){
        printf("HE IS A LOSER!! \n");
    }

    printf("-----------------------------------\n");

    return 0;
}