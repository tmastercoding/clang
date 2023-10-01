#include <iostream>
#include <string>
using namespace std;

int len(char *array);

int main(){
    char operation[100];
    gets(operation);
    printf("%s\n", operation);

    int size = len(operation);

    int jdx = 0;
    for(int idx = 0; idx < 3; idx++){
        for(int jdx = 0; jdx < size; jdx++){
            operationArray[idx]
        }
    }

    return 0;
}

int len(char *array){
    int size = 0;
    while (*array != '\0'){
        array++;
        size++;
    }
    return size;
}