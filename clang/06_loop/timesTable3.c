#include <stdio.h>

int main(){
    int pre = 2;


        // Outer 
    int post = 0;
    while (post <= 9){
        // Inner
        pre = 2;
        while (pre <=9){

            if (post == 0){
                printf("%d dan\t", pre);
            } else {
                printf("%d x %d = %2d\t",pre,post, pre * post);

            }
            pre++;
        }
        printf("\n");
        post++;
    }
    return 0;
}