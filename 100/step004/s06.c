#include <stdio.h>
#include <stdlib.h>

void c_ver();

void swap(int *basket, int first, int second);

int main(){
    c_ver();
    return 0;
}

void c_ver(){
    // declare variables
    int sizeBasket = 0;
    int noOfSwitch = 0;
    int one, other = 0;
    // input variables
    scanf("%d %d", &sizeBasket, &noOfSwitch);

    // malloc a list and set
    int* baskets = (int *)malloc(sizeof(int) * sizeBasket);
    for(int idx = 0; idx < sizeBasket; idx++){
        baskets[idx] = idx+1;
    }

    int idx = 0;
    // loop noOfSwitch times
    while(idx < noOfSwitch){
        // input one, other
        scanf("%d %d", &one, &other);
        // swap when one, other are different
        if(one!=other){
            swap(baskets, one-1, other-1);
        }
        idx++;
    }

    // output
    for(int idx = 0; idx < sizeBasket; idx++){
        printf("%d ", baskets[idx]);
    }
    printf("\n");

    free(baskets);
}

void swap(int *basket, int first, int second){
    int temp = basket[first];
    basket[first] = basket[second];
    basket[second] = temp;
}


// #include <stdio.h>
// #include <stdlib.h>

// void swap( int* basket, int one, int other  );

// int main() {

//     int one, other;
//     const int size_basket = 5;
//     int count_of_change = 4;

//     int* basket = ( int * )malloc( sizeof( int ) * size_basket );

//     // init basket
//     for( int idx = 0; idx < size_basket; idx++ ) {
//         basket[idx] = idx+1;
//     }

//     while( 1 ) {

//         scanf( "%d %d", &one, &other );

//         if( one != other ) {
//             swap( basket, one-1, other-1 );
//         }

//         printf( "one : %d, other: %d\n", one, other );

//         count_of_change--;

//         if( !count_of_change ) break;

//     }

//     // init basket
//     for( int idx = 0; idx < size_basket; idx++ ) {\
//         printf( "%d ", basket[idx] );
//     }
//     printf( "\n" );

//     return 0;
// }

// void swap( int* basket, int one, int other  ) {
//     int temp = basket[ one ];
//     basket[ one ] = basket[ other ];
//     basket[ other ] = temp;
// }