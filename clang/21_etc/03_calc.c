// simple calculator program
#include <stdio.h>

// makes it so that when you type
// CAL_TYPE, it means int
typedef int CAL_TYPE;

int main() {
    // integer variables input, a, b
    CAL_TYPE input;
    CAL_TYPE a, b;

    // while true
    while(1){
        // choices
        printf("--- calculator --- \n");
        printf("1. add\n");
        printf("2. subtract\n");
        printf("3. exit\n");

        // user input a choice
        scanf("%d", &input);

        // if input is 1
        if(input == 1){
            // user input two numbers
            printf("two numbers: ");
            scanf("%d%d", &a, &b);
            
            // adds them together
            printf("%d and %d\'s sum: %d\n", a, b, a+b);

        // if input is 2
        } else if (input == 2){
            // user input two numbers
            printf("two numbers: ");
            scanf("%d%d", &a, &b);

            // subtracts them together
            printf("%d and %d\'s difference: %d\n", a, b, a-b);
        } else{
            // if user input is 3,
            // exit the program
            break;
        }
    }

    return 0;
}