#include <stdio.h>
// string.h for strlen
#include <string.h>

// get_input() ?
// is_int() ? 
// to_int() ?

// func that gets input and puts into num
void getNumInput(int *num){
    // cdhar buffer all set to '\0'
    char buffer[10] = {'\0', };
    char *p_buffer;
    char ch;
    
    // ptr pointing to buffer
    p_buffer = buffer;   
    fflush(stdin);

    // get input
    while((ch = getchar()) != '\n'){
        // if ch is number
        if('0' <= ch && ch <= '9'){
            // add to buffer
            *p_buffer++ = ch;
        } else{
            // print error
            printf("Please only input numbers!\n");
        }
    }
    
    // get length using strlen
    int str_size = strlen(buffer);
    // printf("buffer: %s\n", buffer);
    // printf("str_size: %d\n", str_size);

    // loop buffer from last to start
    for(int idx = str_size-1; idx >= 0; idx--){
        // printf("idx: %d\n", idx);
        int pow = 1;
        // get power needed
        for(int jdx = str_size-idx-1; jdx > 0; jdx--){
            // printf("jdx: %d\n", jdx);
            pow *= 10;
        }

        printf("pow: %d\n", pow);
        printf("number: %d\n", (buffer[idx]-'0'));
        // multiply digit and number and add to num
        *(num) += ((buffer[idx]-'0') * pow);
    }
    printf("num : %d\n", *num);
}

int main(){
    // two ints
    int pre = 0;
    int post = 0;

    // get input 
    getNumInput(&pre);
    getNumInput(&post);

    // print each value
    printf("pre: %d\n", pre);
    printf("post: %d\n", post);

    // do +, -, *, /, % for two numbers
    printf("%d + %d = %d\n", pre, post, pre+post);
    printf("%d - %d = %d\n", pre, post, pre-post);
    printf("%d * %d = %d\n", pre, post, pre*post);
    printf("%d / %d = %d\n", pre, post, pre/post);
    printf("%d %% %d = %d\n", pre, post, pre%post);

    return 0;
}