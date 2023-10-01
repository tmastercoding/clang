#include <stdio.h>

int main() {
    const int size = 5;
    int arr[size] = { 99, 77, 66, 88, 55 };

    int t_size = size;
    int temp;

    for( int idx = 0; idx < t_size-1; idx++ ) {
        for( int jdx = idx+1; jdx < t_size; jdx++ ) {
            if( arr[ idx ] > arr[ jdx ] ) {
                // swap
                temp = arr[ idx ];
                arr[ idx ] = arr[ jdx ];
                arr[ jdx ] = temp;
                // t_size--;
            }
        }
    }

//   const int n = 5;
//   int list[size] = { 99, 77, 66, 88, 55 };
//   int i, j, temp;

//   for(i=n-1; i>0; i--){
//     // 0 ~ (i-1)까지 반복
//     for(j=0; j<i; j++){
//       // j번째와 j+1번째의 요소가 크기 순이 아니면 교환
//       if(list[j]<list[j+1]){
//         temp = list[j];
//         list[j] = list[j+1];
//         list[j+1] = temp;
//       }
//     }
//   }


    for( int i = 0; i< size; i++ ) {
        printf(" %d nth : %d \n", i, arr[ i]);
    }

    return 0;
}