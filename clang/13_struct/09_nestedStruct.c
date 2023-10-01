#include <stdio.h>

typedef struct employee {
    int age;
    int salary;
} EMP;

struct company {
    EMP data;
    char name[10];
};

int main(){
    struct company Kim;

    Kim.data.age = 31;
    Kim.data.salary = 3000000;

    printf("Kim's age: %d \n", Kim.data.age);
    printf("Kim's salary: $%d/year \n", Kim.data.salary);

    return 0;
}