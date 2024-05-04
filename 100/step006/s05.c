#include <stdio.h>
#include <string.h>

void lower(char** str, int size);

int main(){
    char* buffer = NULL;
    int alphabet[26] = {0, };
    size_t size = 0;
    getline(&buffer, &size, stdin);
    size = strlen(buffer)-1;
    int max = 0;
    int maxCount = 0;
    char maxLetter;


    lower(&buffer, size);

    for (int idx = 0; idx < size; idx++){
        alphabet[buffer[idx]-'a'] +=1;
    }

    max = alphabet[0];
    maxLetter = 0 + 'A';
    maxCount = 1;
    for(int idx = 1; idx < 26; idx++){
        if(alphabet[idx] == max){
            maxCount +=1;
        } else if (alphabet[idx] > max){
            maxCount = 1;
            max = alphabet[idx];
            maxLetter = idx + 'A';
        }
    } 
    if(maxCount > 1){
        printf("?\n");
    } else{
        printf("%c\n", maxLetter);
    }

    return 0;
}

void lower(char** str, int size){
    for(int idx = 0; idx < size; idx++){
        if((*str)[idx] < 'a'){
            (*str)[idx] += ('a' - 'A');
        }
    }
}