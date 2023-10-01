#include <stdio.h>

int main(){
    // stdout and stdin are both files
    // meaning you can close them
    fclose(stdout);
    fclose(stdin);

    int var;

    // these do not work because you have
    // closed both files
    printf("aaa");
    scanf("%d", &var);
    
    return 0;
}