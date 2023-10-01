#include <stdio.h>

// last element = pivot, 
// place smaller elements to left, bigger elements to right
int partition (int arr[], int start, int end){
    // pivot is last element
    int pivot = arr[end];
    int i = (start - 1);

    // loop array
    for(int j = start; j <= end - 1; j++){
        // if current element is smaller than pivot
        if(arr[j] < pivot){
            // increase i by 1
            i++;

            // swap i's element with j's element
            int t = arr[i];
            arr[i] = arr[j];
            arr[j] = t;
        }
    }
    
    // swap array's i+1 element and last element
    int t = arr[i+1];
    arr[i+1] = arr[end];
    arr[end] = t;

    // return i+1 element
    return (i+1);
}

// print an array
void printArr(int arr[], int length){
    // loop through arr, print each element
    for(int idx = 0; idx < length; idx++){
        printf("%d ", arr[idx]);
    }
    printf("\n");
}

// implement quick sort
void quick(int arr[], int start, int end){
    // if start is smaller than end
    if(start < end){
        // printf("Before partition:\n");
        // printArr(arr, end+1);

        // partition array
        int p = partition(arr, start, end);

        // printf("After partition:\n");
        // printArr(arr, end+1);       
        // printf("P: %d\n", p);

        // recursion
        // quicksort left array (smaller values than p)
        quick(arr, start, p - 1);
        // quicksort right array (bigger values than p)
        quick(arr, p + 1, end);
    }
}

int main(){
    int arr[] = {24, 9, 29, 14, 19, 27};
    int length = sizeof(arr)/sizeof(int);
    printf("Before: \n");
    printArr(arr, length);

    // int p = partition(arr, 0, length-1);
    printf("After: \n");
    quick(arr, 0, length-1);
    printArr(arr, length);
    return 0;
}