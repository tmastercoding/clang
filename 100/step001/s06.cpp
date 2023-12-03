#include <stdio.h>
#include <string.h>

// get_input() ?
// is_int() ? 
// to_int() ?

void getNumInput(int *num){
    char buffer[10] = {'\0', };
    char *p_buffer;
    char ch;

    p_buffer = buffer;   
    fflush(stdin);

    while((ch = getchar()) != '\n'){
        if('0' <= ch && ch <= '9'){
            *p_buffer++ = ch;
        } else{
            printf("Please only input numbers!\n");
        }
    }
    
    int str_size = strlen(buffer);
    // printf("buffer: %s\n", buffer);
    // printf("str_size: %d\n", str_size);

    for(int idx = str_size-1; idx >= 0; idx--){
        // printf("idx: %d\n", idx);
        int pow = 1;
        for(int jdx = str_size-idx-1; jdx > 0; jdx--){
            // printf("jdx: %d\n", jdx);
            pow *= 10;
        }
        printf("pow: %d\n", pow);
        printf("number: %d\n", (buffer[idx]-'0'));
        *(num) += ((buffer[idx]-'0') * pow);
    }
    printf("num : %d\n", *num);
}

int main(){
    int pre = 0;
    int post = 0;

    getNumInput(&pre);
    getNumInput(&post);

    printf("pre: %d\n", pre);
    printf("post: %d\n", post);

    printf("%d + %d = %d\n", pre, post, pre+post);
    printf("%d - %d = %d\n", pre, post, pre-post);
    printf("%d * %d = %d\n", pre, post, pre*post);
    printf("%d / %d = %d\n", pre, post, pre/post);
    printf("%d %% %d = %d\n", pre, post, pre%post);

    return 0;
}