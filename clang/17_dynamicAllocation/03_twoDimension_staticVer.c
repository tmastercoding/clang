#include <stdio.h>

int main(){
    int arr[3][2];
    int i;

    for(int idx = 0; idx < 3; idx++){
        printf("row %d: \n", idx+1);
        for(int jdx = 0; jdx < 2; jdx++){
            // scanf("%d", &( arr[idx][jdx] ));
            arr[idx][jdx] = idx*jdx;
        }
    }

    for(int idx = 0; idx < 3; idx++){
        printf("row %d: ", idx+1);

        for(int jdx = 0; jdx < 2; jdx++){
            printf("%d ", arr[idx][jdx]);
        }

        printf("\n");
    }

    return 0;
}