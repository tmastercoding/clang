#include <stdio.h>
#include <string.h>

char to_lower( char ch );
// void lower(char* str);

int main(){
    // char* buffer = NULL;
    int alphabet[26] = {0, };
    const int max_size = 1000000;
    int idx = 0;
    // getline(&buffer, &size, stdin);
    // size = strlen(buffer)-1;
    int max = 0;
    int maxCount = 0;
    char maxLetter;
    char ch;

    while((ch = getchar()) != '\n' && idx < max_size){
        // buffer[size++] = to_lower(ch);
        alphabet[ to_lower(ch) -'a']++;
        idx++;
    }
    
    // lower(buffer);
    // printf("%s\n", buffer);
    for (int idx = 0; idx < 26; idx++){
        if( alphabet[idx] ){
            printf("%c: %d\n", idx + 'A', alphabet[idx]);
        }
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

// void lower(char* str){
//     int idx = 0;
//     while(*(str+idx) != '\0'){
//         *(str+idx) = to_lower(*(str+idx));
//         idx++;
//     }
// }

char to_lower(char ch){
    return ( 'A' <= ch && ch <= 'Z')? ch + 'a' - 'A' : ch;
}