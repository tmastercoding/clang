#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void resetHasFound(int* hasFound, int size);

int main(){
    // get size
    int size = 0;
    scanf("%d", &size);
    fflush(stdin);

    // create 2d array with malloc
    char** text = ( char** )malloc( sizeof(char*) *  size);
    
    char* line = NULL;
    size_t line_size = 0;

    char prevChar = '\0';
    int isGroup = 1;
    int count = 0;
    int hasFound[26] = {0, };

    // get each line and put into malloc
    for (int idx = 0; idx < size; idx++){
        line = NULL;
        line_size = 0;
        getline(&line, &line_size, stdin);
        text[idx] = line;
    }

    // loop each line
    for (int idx = 0; idx < size; idx++){
        prevChar = '\0';
        isGroup = 1;
        resetHasFound(hasFound, 26);

        // loop char
            for(int jdx = 0; jdx < strlen(text[idx])-1; jdx++){
                // printf("%c", text[idx][jdx]);
                // if not equal to prevChar
                if(prevChar != text[idx][jdx]){
                    // if in foundChar
                    if(hasFound[text[idx][jdx]-'a']){
                        isGroup = 0;
                        break;
                    } else{
                        prevChar = text[idx][jdx];
                        hasFound[text[idx][jdx]-'a'] = 1;
                    }
                }
            }
            if(isGroup){
                count++;
            }

    }

    printf("%d\n", count);


    
    for (int idx = 0; idx < size; idx++){
        // printf("%s\n", text[idx]);
        free(text[idx]);
    }
    free(text);

    return 0;
}

void resetHasFound(int* hasFound, int size){
    for(int idx = 0; idx < size; idx++){
        hasFound[idx] = 0;
    }
}