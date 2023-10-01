// N 진법에서 M 진법으로 변환하는 프로그램을 만들어보세요. (난이도 : 中)

#include <stdio.h>

int change_nsys(int num, int from, int to, int *arr, int size);

int main(){
    int arr[1];
    change_nsys(8,10,2,arr, 1);
    return 0;
}

int change_nsys(int num, int from, int to, int *arr, int size){
    if(num > 0){
        arr[size-1] = num%to;
        printf("%d", num%to);
        num/=to;
        return change_nsys(num, from, to, arr, size++);
    } else{
        return arr;
    }


    return 0;
}