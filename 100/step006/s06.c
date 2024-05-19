#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// char* getToken(int size, int idx, char* src);

int main(){
    char* buffer = NULL;
    size_t size = 0;
    const int croat_size = 8;
    char croat[croat_size][4] = {"c=", "c-", "dz=", "d-", "lj", "nj", "s=", "z="};
    int idx = 0;
    int cnt = 0;
    int count = 0;
    // char token[3] = {'\0',};
    getline(&buffer, &size, stdin);
    size = strlen(buffer);

    while(*(buffer+idx) != '\0'){
        for(int jdx = 0; jdx < croat_size; jdx++){
            if(*(buffer+idx) == croat[jdx][cnt]){
                cnt++;
                if(*(buffer+idx+1) == croat[jdx][cnt]){
                    cnt++;
                    if(croat[jdx][cnt] && *(buffer+idx+2) == croat[jdx][cnt]){
                        count++;
                        idx += 3;
                        break;
                    } else if(!croat[jdx][cnt]){
                        count++;
                        idx += 2;
                        break;
                    }
                }
            }
        }

    }

    printf("%d\n", count);
    // for(int idx = 0; idx < size-1; idx++){
    //     // if (idx < size-2){
    //     //     strcpy(token, getToken(2, idx, buffer));
    //     // } 
    //     // printf("%s\n", token);
    // }


    return 0;
}

// char* getToken(int size, int idx, char* src){
//     char* token;
//     token = (char *)malloc(size * sizeof(char));
    
//     for(int jdx = 0; jdx < size; jdx++){
//         token[idx+jdx] = src[idx+jdx];
//     }

//     return token;
// }