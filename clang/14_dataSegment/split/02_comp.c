#include <stdio.h>
#include "ohstring.h"

int main(){
    char pre[20];
    char post[20];

    scanf("%s", pre);
    scanf("%s", post);

    if(compare(pre,post)){
        printf("%s and %s are the same. \n", pre, post);
    } else{
        printf("%s and %s are different. \n", pre, post);
        }

    return 0;
}

