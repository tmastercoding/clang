#include <stdio.h>
#include "str.h"

int main(){
    char str1[20] = {"hi"};
    char str2[20] = {"hello every1"};

    copy_str(str1, str2);
    printf("str1 : %s \n", str1);

    return 0;
}