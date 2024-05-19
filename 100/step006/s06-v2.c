#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char* getToken(int size, int idx, char* src);

int main(){
    char* buffer = NULL;
    size_t size = 0;
    const int croat_size = 8;
    char croat[croat_size][4] = {"c=", "c-", "dz=", "d-", "lj", "nj", "s=", "z="};

    int count = 0;
    char* token;
    getline(&buffer, &size, stdin);
    size = strlen(buffer);

    for(int idx = 0; idx < size-1; idx++){
        // if (idx < size-3){
        //     token = getToken(3, idx, buffer);
        //     printf("\'%s\'\n", token);
        //     for(int jdx = 0; jdx < croat_size; jdx++){
        //         if(strcmp(token, croat_size)){

        //         }

        //     }
        //     free(token);
        // }
        token = getToken(3, idx, buffer);
        printf("%d")
    }


    return 0;
}

char* getToken(int size, int idx, char* src){
    char* token;
    token = (char *)malloc(size * sizeof(char));
    // printf("size: %d\n", size);
    // printf("idx: %d\n", idx);
    // printf("src: %s\n", src);
    // printf("token: %s\n", token);

    for(int jdx = 0; jdx < size; jdx++){
        // printf("jdx: %c\n", src[idx+jdx]);
        token[jdx] = src[idx+jdx];
    }
    // printf("token: %s\n", token);
    return token;
}