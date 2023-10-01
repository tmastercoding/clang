#include<stdio.h>

void quicksort( int* numbers, int first, int last ){

    int i, j, pivot, temp;

    if(first<last){

        pivot=first;

        i=first;

        j=last;

        while(i<j){

            while(numbers[ i ]<=numbers[ pivot ]&&i<last) {
                i++;    
            }

            while(numbers[ j ]>numbers[ pivot ]) {
                j--;
            }

            if(i<j){
                temp=numbers[ i ];

                numbers[ i ]=numbers[ j ];

                numbers[ j ]=temp;
            }

        }

        temp=numbers[ pivot ];

        numbers[ pivot ]=numbers[ j ];

        numbers[ j ]=temp;

        quicksort(numbers,first,j-1);

        quicksort(numbers,j+1,last);

    }

}

int main(){

    int i, numbers[] = { 10, 5, 2, 4, 6, 8, 9, 7, 1}; 
    int count = sizeof( numbers ) / sizeof( int );

    // printf("Enter some elements (Max. - 25): ");

    // scanf("%d",&count);

    // printf("Enter %d elements: ", count);

    // for(i=0;i<count;i++) {
    //     scanf("%d",&numbers[ i ]);
    // }

    quicksort(numbers,0,count-1);

    printf("The Sorted Order is: ");

    for(i=0;i<count;i++) {
        printf(" %d",numbers[ i ]);
    }
    putchar('\n');

    return 0;

}