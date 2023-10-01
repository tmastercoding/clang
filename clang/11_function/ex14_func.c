#include <stdio.h>

int add1_element(int (*arr)[2], int row);
int output_element(int (*arr)[2], int row, char* title );

int main(){
    const int size = 3;
    int arr[ size ][2];
    
    int num = 0;

    // input or initialize arr 
    for(int i = 0; i < size; i++){
        for(int j = 0; j < 2; j++){
            arr[i][j] = num++;
        }
    }

    // output arr
    output_element(arr,  size, "before\n" );

    // add 1 element
    add1_element(arr,  size );

    // output arr
    output_element(arr,  size, "after\n" );

    return 0;   
}

int add1_element(int (*arr)[2], int row){
    for(int i = 0; i < row; i++) {
        for(int j = 0; j < 2; j++){
            arr[i][j]++;
        }
    }
    return 0;
}

int output_element(int (*arr)[2], int row, char* title ) {
    printf("%s", title );

    for(int i = 0; i < row; i++) {
        for(int j = 0; j < 2; j++){
            printf( "%d\n", arr[i][j]);
        }
    }
    
    return 0;
}
