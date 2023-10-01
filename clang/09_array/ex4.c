#include <stdio.h>

int main(){
    // declare
    const int total = 3;

    // scanf("%d", &total );
    int grade_arr[ total ];
    int grade, ave = 0;

    // user input score
    for(int count = 0; count < 10; count++){ 
        
        printf("Please input %dth students grade.\n", count + 1);
        scanf("%d", &grade);
        
        grade_arr[count] = grade;
        //input
    }

    // make average
    for(int count = 0; count < 10; count++){
        ave += grade_arr[count];
    }

    ave /= 10;

    // output
    printf("The average of the students is: %d\n", ave);

    // determine if students passed

    for(int count = 0; count < 10; count++){
        if(grade_arr[count] > ave){
            printf("The %dth student has passed!\n", count + 1);
        } else{
            printf("The %dth student has failed :(\n", count + 1);
        }
    }

    return 0;
}