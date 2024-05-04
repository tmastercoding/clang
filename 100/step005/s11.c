#include <stdio.h>
#include <string.h>

int main(){
    char* buffer = NULL;
    size_t size = 0;
    int count = 0;

    while(1){
        getline(&buffer, &size, stdin);
        puts(buffer);
        count++;

        if((strlen(buffer)> 100) || (count > 2)){
            break;
        }
    }

    return 0;
}