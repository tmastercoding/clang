#include <stdio.h>

int main(){
    const int len = 5;
    int arr[len] = {0,};

    for(int idx = 0; idx < len; idx++){
        printf("%dth address: %p\n",idx, &arr[idx]);
    }

    return 0;
}