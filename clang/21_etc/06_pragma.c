#include <stdio.h>

// processes bytes in 1s not 4s
#pragma pack(1)

// structure called Weird
struct Weird {
    char arr[2];
    int i;
};

int main(){
    struct Weird a;
    // prints the size of struct
    printf("size of a : %lu \n", sizeof(a));
    return 0;
}