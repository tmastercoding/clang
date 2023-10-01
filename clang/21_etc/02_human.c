#include <stdio.h>

// human structure
struct HUMAN{// human structure

    int age;
    int height;
    int weight;
    int gender;

};

// struct HUMAN has been shortened to Human
// using typedef
typedef struct HUMAN Human;

// print general info of human struct
int print_status(Human human);

int main(){
    // create Adam and Eve variables
    // Does't need to type struct HUMAN
    Human Adam = {31, 182, 75, 0};
    Human Eve = {27, 166, 48, 1};

    // print status of both people
    print_status(Adam);
    print_status(Eve);

    return 0;
}

// print general info of human struct
int print_status(Human human){
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