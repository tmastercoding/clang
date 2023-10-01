#include <stdio.h>

int main(){
    // `oh tay : 96 : -----
    // `goh tay : 50 : --
    // declare values
    int grade_arr[5] = {100, 50, 90, 1, 99};

    // make bar chart
    for(int count = 0; count < 5; count++){
        printf("student%d : ", count + 1);

        for(int tens = 0; tens < grade_arr[count]/10; tens++){
            printf("- ");
        }

        printf("\n");
    }


    return 0;
}