#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(){
    int inputTimes = 0;
    char buffer[1000] = {'\0',};

    scanf("%d", &inputTimes);
    fflush(stdin);

    char** outputArr = (char** )malloc(inputTimes * sizeof(char* ));
    for(int idx = 0; idx < inputTimes; idx++){
        scanf("%s", buffer);
        fflush(stdin);

        char* valArr = (char* )malloc(2 * sizeof(char));    
        
        valArr[0] = buffer[0];
        valArr[1] = buffer[strlen(buffer)-1];

        outputArr[idx] = valArr;
    }

    for(int idx = 0; idx < inputTimes; idx++){
        printf("%s\n", outputArr[idx]);
    }

    return 0;
}