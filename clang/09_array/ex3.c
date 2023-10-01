#include <stdio.h>

int main(){
    // declare
    int grade_arr[5];
    int grade, ave = 0;

    // user input score
    for(int count = 0; count < 5; count++){ 
        
        printf("Please input %dth students grade.\n", count + 1);
        scanf("%d", &grade);
        
        grade_arr[count] = grade;
        //input
    }

    // make average
    for(int count = 0; count < 5; count++){
        ave += grade_arr[count];
    }

    ave /= 5;

    // output
    printf("The average of the students is: %d\n", ave);

    return 0;
}