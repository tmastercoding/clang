#include <stdio.h>

// sort to largest to smallest
void reverse_bubble_sort(int *arr, int count){
    int inner_count = count;

    for(int idx = 0; idx < count; idx++){

        printf( "count : %d  inner_count %d\n", count, inner_count);
        for(int jdx = 0; jdx < inner_count-1; jdx++){

            // if arr[jdx] is smaller than next
            if( arr[jdx] < arr[jdx+1] ){
                // swap
                int temp = arr[jdx];
                arr[jdx] = arr[jdx+1];
                arr[jdx+1] = temp;    
                // smaller ones moves to the end
                // bigger one moves to the start
            }   
        }
        inner_count--;
    }

}

int main(){
    int arr[] = {1, 2, 3, 4, 5, 6};
    reverse_bubble_sort(arr, 6);

    for(int idx = 0; idx < 6; idx++){
        printf("%d ", arr[idx]);
    }

    printf("\n");
    return 0;
}