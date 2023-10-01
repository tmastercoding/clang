> ##### __String concat__ - my study.

```c
#include <stdio.h>

// len
int len(char *pre);
// cat
int cat(char *pre, char *post, int size);

int main(){
    const int size = 10;
    char pre[size] = "abcd";
    char post[] = "absadfsdfads";

    int result = 0;

    // printf("%d\n", len(pre));

    result = cat(pre, post, size);

    if(result)printf("%s\n", pre);
    else printf("copy was not succesful. :(\n");

    return 0;
}

int len(char *pre){
    int len = 0;
    while(*pre != '\0'){
        len++;
        pre++;
    }
    return len + 1;
}

int cat(char *pre, char *post, int size){
    if ( size < len(pre)+ len(post) ){
        return 0;
    }

    while(*(pre++)!='\0');

    pre--;

    while(*post!='\0'){
        *(pre++) = *(post++);
    }
    *pre='\0';

    return 1;
}
```