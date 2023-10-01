#include <stdio.h>

int main(){
    int pre  = 2;

    int post = 0;
    
    do{
        // Inner ( rows )
        do{
            if(post == 0){
                printf("%d dan \t",pre);
            } else{
                printf("%2d x %d = %2d\t", pre, post, pre*post);
            }
            pre++;
        } while(pre <= 9);
        printf("\n");
        pre =2;
        post++;
    } while (post <=9);
    // Outer ( colimns )


    return 0;
}