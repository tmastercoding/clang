#include <stdio.h>

int global = 0;

int function(){
    global++;
    return 0;
}

int main(){
    global = 10;
    function();
    printf("%d \n", global);
    
    return 0;
}