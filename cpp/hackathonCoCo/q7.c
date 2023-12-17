#include <stdio.h>
#include <stdlib.h>

void str_cpy(char* dest, int dest_size, char* src, int src_size){
    if(dest_size >= src_size){
        for(int idx = 0; idx < src_size; idx++){
            dest[idx] = src[idx];
        } 
        dest[src_size] = '\0';
    } else{
        printf("Size of destination must be greater or equal to size of src\n");
    }
}

int strToInt(char *str, int str_size){
    int num = 0;
    int expo = 0;
    int mult = 1;
    int idx = str_size-1;
    while(str[idx] == '\0'){
        // printf("here\n");
        idx--;
    }

    for(; idx > -1; idx--){
        // printf("%c", str[idx]);
        mult = 1;
        for(int jdx = 0; jdx < expo; jdx++){
            mult *= 10;
        }
        // printf(": %d\n", mult);

        num += mult * (str[idx]-'0');
        expo++;
    }

    return num;
}

void split(int *dest, int dest_size, char *str, int str_size, char sep){
    int count = 0;
    char buffer[10] = {'\0',};
    char empty[10] = {'\0',};
    char* p_buffer = buffer;

    for(int idx = 0; idx < str_size; idx++){
        if((str[idx] == sep ) || (str[idx] == '\n')){
            dest[count] = strToInt(buffer, sizeof(buffer));
            // printf("dest[%d]: %d\n", count, dest[count]);
            str_cpy(buffer, sizeof(buffer), empty, sizeof(empty));  
            // printf("buffer: %s\n", buffer);

            count++;
            p_buffer = buffer;
            continue;
        }
        *(p_buffer++) = str[idx];
        // printf("count: %d\n", count);
        if((count) == dest_size){
            break;
        }
    }

}

int main(){
    int numOfTypes = 0;
    scanf("%d", &numOfTypes);
    int targetVal = 0;
    scanf("%d", &targetVal);

    int* typesOfCoins;
    typesOfCoins = (int*)malloc(numOfTypes * sizeof(int));


    char ch;
    char buffer[100] = {'\0', };
    char* p_buffer = buffer;

    // for(int idx = 0; idx < numOfTypes; idx++){
    //     fflush(stdin);
    //     // while( ( (ch = getchar()) !=' ' ) || (( ch = getchar())!='\n')){
    //     while( (ch = getchar())){
    //         if(( ch == ' ') || (ch == '\n')){
    //             break;
    //         }
    //         *(p_buffer++) = ch;
    //     }    
    //     // printf("\'%s\'\n", buffer);
    //     typesOfCoins[idx] = strToInt(buffer, sizeof(buffer));
    //     // printf("%d\n", typesOfCoins[idx]);
    //     str_cpy(buffer, sizeof(buffer), "\0", sizeof("\0"));
    //     p_buffer = buffer;
    // }
    
    fflush(stdin);
    while((ch = getchar()) != '\n'){
        *(p_buffer++) = ch;
    }
    *p_buffer = '\n';
    split(typesOfCoins, numOfTypes, buffer, sizeof(buffer), ' ');

    int count = 0;
    int minCount = 0;
    int tempTarget = targetVal;

    for(int start = 0; start < numOfTypes; start++){
        count = 0;
        tempTarget = targetVal;
        for(int idx = start; idx < numOfTypes; idx++){
            count += tempTarget / typesOfCoins[idx];
            tempTarget %= typesOfCoins[idx];
        }
        if(count < minCount){
            minCount = count;
        } else if(start == 0){
            minCount = count;
        }
    }

    free(typesOfCoins);

    printf("%d\n", minCount);
    return 0;
}