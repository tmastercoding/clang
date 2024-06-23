#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(){
    char* binary;
    char ch;
    int size = 10;
    int idx = 0;
    int num = 0;
    int pow = 1;
    int count = 0;

    char* buffer = NULL;
    size_t temp_size = 0;

    getline(&buffer, &temp_size, stdin);
    size = atoi(buffer);

    binary = (char*)malloc(size * sizeof(char));

    while((ch = getchar()) != '\n'){
        binary[idx++] = ch;
    }

    // printf("%s\n", binary);
    idx = size-1;
    while(idx > -1){
        num += (binary[idx] - '0') * pow;
        pow *= 2;
        idx--;
    }
    
    // printf("%d\n", num);

    while(1){
        if(((num & 1) == 1) || ((num & 3) != 0)){
            // first operation
            // 1 << size = 2^size
            num = (num + 1) % (1 << size);
        } else{
            num = (num << 1) % (1 << size);
        }

        count++;
        if(!num){
            break;
        }
    }

    printf("%d\n", count);

    free(binary);
    return 0;
}