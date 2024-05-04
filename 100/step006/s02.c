#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(){
    // const int size = 6;
    int correctArr[] = {1, 1, 2, 2, 2, 8};

    char* buffer = NULL;
    size_t size = 0;

    char sep[] = " ";
    char* p;
    int temp = 0;
    int count = 0;
    getline(&buffer, &size, stdin);

    p = strtok(buffer, sep);

    while(p != 0){
        temp = atoi(p);
        printf("%d ", correctArr[count]-temp);

        count++;
        p = strtok(NULL, sep);
    }

    printf("\n");
    

    /*
    scanf ver

    int temp = 0;
    // int input[size] = {0,};

    for (int idx = 0; idx < size; idx++){
        scanf("%d", &temp);
        printf("%d ", correctArr[idx] - temp);
    }

    printf("\n");
    */

    return 0;
}