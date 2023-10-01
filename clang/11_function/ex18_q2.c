// 유클리도 호제법을 이용해서 N 개의 수들의 최대공약수를 구하는 함수를 만들어보세요. 

#include <stdio.h>

int swap(int *pre, int *post);
int euc_algo(int pre, int post);
int gcd(int *arr, int size);



int main(){
    // int pre = 54;
    // int post = 888;
    int arr[3] = {30, 4050, 23884};

    // if (post < pre){
    //     swap(&pre, &post);
    // }

    // int rmd = euc_algo(pre, post);
    // printf("%d\n", rmd);

    printf("%d\n", gcd(arr,3));
    return 0;
}

int swap(int *pre, int *post){
    int temp = *pre;
    *pre = *post;
    *post = temp;

    return 0;
}

int euc_algo(int pre, int post){

    int rmd = pre;

    if (post%pre > 0){
        rmd = post%pre;

        // printf("%d\n", rmd);

        return rmd = euc_algo(rmd, pre);

    } else{
        return rmd;
    }
}

int gcd(int *arr, int size){
    if (size > 1){
        size--;
        int temp_arr[size];
        temp_arr[0] = euc_algo(arr[0], arr[1]);

        for(int idx = 1; idx < size; idx++){
            temp_arr[idx] = arr[idx+1];
        }

        return gcd(temp_arr, size);
    }

    return arr[0];

}