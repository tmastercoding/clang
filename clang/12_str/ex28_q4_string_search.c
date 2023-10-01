//
#include <stdio.h>
// 문자열을 두 개 입력 받아서 
// 먼저 입력받은 문자열에서 나중에 입력받은 문자열의 위치를 검색하는 함수를 만들어보세요.
// 만일 없다면 -1 을 리턴하고 있다면 그 위치를 리턴합니다. (난이도 : 中)

// 예를 들어먼저 처음 입력한 것이 I_am_a_boy 이고, 
// 나중에 입력한 것이 am 이였다면 컴퓨터는 I_am_a_boy 에서 am 의 위치를 찾는다. 
// 이 경우에는 am 의 위치는 2 (처음에서 세번째) 이므로 2를리턴한다. 만일am이라는문자열이없다면-1을리턴한다.

int pos(char *str, char *find);
int string_comp(char *pre, char *post);
int string_len(char *pre);

int main(){
    printf("%d", pos("abcde", "cd"));

    return 0;
}

int pos(char *str, char *find){
    int len = string_len(find);
    char temp[len];

    printf("%d", len);

    for(int idx = 0; idx < string_len(str); idx++){
        for(int jdx = idx; jdx< jdx+len; jdx++){
            temp[jdx-idx] = str[jdx];
        }
        if(string_comp(find, temp)){
            return idx;
        }
    }

    return -1;
}

int string_comp(char *pre, char *post){

    while(*pre != '\0'){
        if(*(pre++) != *(post++)){
            return 0;
        }
    }
    return 1;
}

int string_len(char *pre){
    int len = 0;
    // while(*(pre++) != '\0'){
    //     len++;
    // }
    while(*(pre + (len++) ) != '\0');

    return len-1;
}


