#include <stdio.h>

// prototype
int add_num(int *parr);

// main
int main(){
    int arr[3];
    int i;

    // user input

    for(i = 0; i < 3; i++){
        printf("input num\n");
        scanf("%d", &arr[i]);
        fflush( stdin );
    }

    add_num(arr);

    printf("array item: %d, %d, %d\n", arr[0], arr[1],arr[2]);

    return 0;
}


// func
int add_num(int *parr){

    for(int i = 0; i < 3; i++){
        // parr[i]++;
        (*(parr + i ))++;

        // add 1 to every item
    }
    
    int i = 0;

    while(i < 3){
        (*( parr + i ))++;

        i++;
    }

    while( i < 3 ) {
        i++;
        (*( parr++ ))++;

    }

    return 0;
}
