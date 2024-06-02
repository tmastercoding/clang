#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
* 
    @ author :
        - name  : Tay Oh
        - email : tmastercubing@gmail.com
    @ since : Sunday 26th May 2024
    @ function name : add_matrix
    @ params : 
        - int** matrix      : stores values in a matrix
        - int size_of_row   : row numbers in matrix
        - int size_of_col   : col numbers in matrix
        - int flag          : 0 if init, 1 if adding to existing
    @ return_value : none
    @ desc: |
        gets a 2D array, 
        and inputs/adds to according to
        flag
*/

void add_matrix(int** matrix, int size_of_row, int size_of_col, int flag);

int main(){
    // declare variables
    int size_of_row = 3;
    int size_of_col = 3;
    int idx = 0;
    int jdx = 0;
    // char* buffer = NULL;
    // size_t size = 0;
    // const char* sep = " ";
    // char* temp;

    // construct matrix
    int** matrix = (int** )malloc(size_of_row * sizeof(int* ));
   
    for(idx = 0; idx < size_of_row; idx++){
        matrix[idx] = (int* )malloc(size_of_col * sizeof(int));
    }

    // // input values
    // buffer = NULL;
    // size = 0;

    // for(idx = 0; idx < size_of_row; idx++){
    //     // get line
    //     getline(&buffer, &size, stdin);

    //     // tokenise
    //     jdx = 0;
    //     temp = strtok(buffer, sep);
    //     matrix[idx][jdx++]= 0 + atoi(temp);

    //     while(jdx < size_of_col){
    //         temp = strtok(NULL, sep);
    //         matrix[idx][jdx++]= 0 + atoi(temp);
    //     }
    // }

    // for(idx = 0; idx < size_of_row; idx++){
    //     // get line
    //     getline(&buffer, &size, stdin);

    //     // tokenise
    //     jdx = 0;
    //     temp = strtok(buffer, sep);
    //     matrix[idx][jdx] = matrix[idx][jdx] + atoi(temp);
    //     jdx += 1;

    //     while(jdx < size_of_col){
    //         temp = strtok(NULL, sep);
    //         matrix[idx][jdx]= matrix[idx][jdx] + atoi(temp);
    //         jdx += 1;
    //     }
    // }

    // add matrix
    add_matrix(matrix, size_of_row, size_of_col, 0);
    add_matrix(matrix, size_of_row, size_of_col, 1);

    // view matrix
    for(idx = 0; idx < size_of_row; idx++){
        for(jdx = 0; jdx < size_of_col; jdx++){
            printf("%d ", matrix[idx][jdx]);
        }
        printf("\n");
    }

    // destroy matrix
    for(idx = 0; idx < size_of_row; idx++){
        free(matrix[idx]);
    }
    free(matrix);

    return 0;   
}

void add_matrix(int** matrix, int size_of_row, int size_of_col, int flag){
    int idx = 0;
    int jdx = 0;
    char* buffer = NULL;
    size_t size = 0;
    const char* sep = " ";
    char* temp;
    int previous_value;

    for(idx = 0; idx < size_of_row; idx++){
        // get line
        getline(&buffer, &size, stdin);

        // tokenise
        jdx = 0;
        temp = strtok(buffer, sep);

        previous_value = ( flag ) ? matrix[idx][jdx]: 0;
        
        matrix[idx][jdx]= previous_value + atoi(temp);
        jdx++;

        while(jdx < size_of_col){
            temp = strtok(NULL, sep);

            previous_value = ( flag ) ? matrix[idx][jdx]: 0;
            
            matrix[idx][jdx]= previous_value + atoi(temp);
            jdx++;

        }
    }

}