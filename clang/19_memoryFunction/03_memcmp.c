#include <stdio.h>
#include <string.h>

int main(){
    int arr[10] = {1,2,9,4,5};
    int arr2[10] = {1,2,3,4,5};

    if(memcmp(arr, arr2, 150) == 0){
        printf("arr and arr2 are the same");
    } else{
        printf("arr and arr2 are not the same\n");
    }

    return 0;
}