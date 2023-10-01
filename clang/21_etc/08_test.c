// main code
#include <stdio.h>

// include header file 3 times
#include "07_weird_once.h"
#include "07_weird_once.h"
#include "07_weird_once.h"

int main(){
    struct Weird a;
    a.i = 3;

    // print valuie of struct
    printf("Weird Structure a.i : %d \n", a.i);

    return 0;
}