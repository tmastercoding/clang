#include <stdio.h>

int str_search(char *source, char *keyword);
int str_len(char *str);

int main(){
    char source[] = {"apple agatha arnold age"};
    char keyword[] = {"age"};

    printf("%d\n", str_len(keyword));
    int pos = str_search(source, keyword);
    printf("%d\n", pos);

    return 0;
}

int str_search(char *source, char *keyword){
    // compare length
    int source_len = str_len(source);
    int keyword_len = str_len(keyword);
    int flag = 0;

    if(source_len < keyword_len){
        return -1;
    }
    for(int s_char = 0; s_char < source_len; s_char++){
        printf("== outer : s_char: %c, char num: %d\n", source[s_char], s_char);

        flag = 1;
        for(int k_char = 0; k_char < keyword_len; k_char++){
            printf("== inner :k_char: %c, char num: %d\n", keyword[k_char], k_char);
            if( source[s_char+k_char]!= keyword[k_char]){
                printf("========= breaking ==========\n");
                flag = 0;
                break;
            }
        }
        if (flag){
            return s_char;
        }

    }
    return -1;
}

int str_len(char *str){
    int len = 0;

    while(*str!='\0'){
        str++;
        len++;
    }

    return len;
}
