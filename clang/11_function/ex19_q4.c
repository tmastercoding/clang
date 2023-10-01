// 계산기를 만들어보세요. 사용자가 1을 누르면 +,2 를 누르면 -와 같은방식으로 해서 만들면 됩니다. 
// 물론 이전의 계산 결과는 계속 누적되어야 하고, 
// 지우기 기능도 있어야 합니다. (물론 하나의 함수에 구현하는 것이 아니라 여러개의 함수로 분할해서 만들어야겠죠?) 

#include <stdio.h>

int add(int pre);
int minus(int pre);
int calc(int pre, int flag);

int main(){
    calc(123,1);

    return 0;
}

int add(int pre){
    int post;
    printf("\nplease input a number.\n");
    scanf("> %d", &post);
    printf("%d + %d = %d", pre, post, pre+post);

    return pre+post;
}

int minus(int pre){
    int post;
    printf("\nplease input a number.\n");
    scanf("> %d", &post);
    printf("%d - %d = %d", pre, post, pre-post);

    return pre-post;
}

int calc(int pre, int flag){
    // int flag = 1;
    // int pre;
    int op;
    int post;
    int ans;
    int temp;
    // printf("please input a number.\n");
    // scanf("> %d", &pre);

    if(flag== 1){
        printf("do you wish to clear?\n0 for clear, 1 for not");
        scanf("> %d", &temp);
        if(temp>1){
            ans = 0;
        }
        printf("select an operator:\n 1 for addition, 2 for subtraction.\n");
        scanf("> %d", &op);

        if(op==1){
            ans = add(pre);
        } else if(op == 2){
            ans = minus(pre);
        }

        printf("%d\n", ans);
        printf("keep going?\ntype 0 if you want to exit, 1 if you want to continue\n");
        scanf("> %d", &flag);
        return calc(ans, flag);
    } else{
        return ans;
    }
    return 0;
}