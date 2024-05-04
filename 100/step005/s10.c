#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
    char* buffer = NULL;
    // char ch;
    int time = 0;
    size_t size = 0;
    int str_size = 0;

    do{
        getline(&buffer, &size, stdin);
        str_size = strlen(buffer)-1;
        if ( str_size > 15 || str_size < 2) {
            printf("Input a string from 2-15 comrade!\n");
        } else {
            for(int idx = 0; idx < str_size; idx++){
                time += (buffer[idx]-'A')/3 + 3;
            }

            printf("time: %d\n", time);

            break;
        }
    } while (1);
    

    // free(buffer);

    return 0;
}