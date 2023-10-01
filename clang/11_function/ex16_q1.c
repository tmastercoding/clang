// 사용자로 부터 5 명의 학생의 수학, 국어, 영어 점수를 입력 받아서
// 평균이 가장 높은 사람 부터 평균이 가장 낮은 사람까지 정렬되어 출력하도록 하세요.
// 특히, 평균을 기준으로 평균 이상인 사람 옆에는 ’합격’,
// 아닌 사람은 ’불합격’ 을 출력하게 해보세요 (난이도 : 中上).

#include <stdio.h>

int avg(int (*parr)[3], int row, int *avg_arr);
int avg_print(int *arr, int row);
int swap(int *pre, int *post);
int avg_sort(int *arr, int row, int asc);


int main(){
    const int students = 5;
    const int subjects = 3;

    int arr[students][subjects] = { {19, 99, 0}, 
                                    {10, 10, 10},
                                    {100, 100, 100}, 
                                    {45, 67, 34}, 
                                    {50, 60, 70}
                                    };

    // int arr[2][2] = { {1,1}, {2,2}};
    // int (*parr)[2] = arr;
    
    int avg_arr[5];

    avg(arr, students, avg_arr);
    avg_print(avg_arr, students);

    avg_sort(avg_arr, students, 0);
    avg_print(avg_arr, students);

    avg_sort(avg_arr, students, 1);
    avg_print(avg_arr, students);

    return 0;
}

int avg(int (*parr)[3], int row, int *avg_arr ){
    int total;

    // average
    for(int idx = 0; idx < row; idx++){
        total = 0;

        for(int jdx = 0; jdx < 3; jdx++){
            total += parr[idx][jdx];
        }

        avg_arr[idx] = total/3;
    }

    return 0;
}

int avg_print(int *arr, int row){
    for(int idx = 0; idx < row; idx++){
        printf("%d, ", *(idx + arr));
    }
    printf("\n");

    return 0;
}

int swap(int *pre, int *post){
    int temp = *pre;
    *pre = *post;
    *post = temp;

    return 0;
}

int avg_sort(int *arr, int row, int asc){

    for(int idx = 0; idx < row-1; idx++){
        for(int jdx = idx+1; jdx<row; jdx++){
            // if( arr[idx] < arr[jdx]){
            //     swap(&arr[idx], &arr[jdx]);
            // }
            if( asc ) {
                if( arr[idx] < arr[jdx] ){
                    swap(&arr[idx], &arr[jdx]);
                }
            } else {
                if( arr[idx] > arr[jdx] ){
                    swap(&arr[idx], &arr[jdx]);
                }

            }
        }
    }

    return 0;
}