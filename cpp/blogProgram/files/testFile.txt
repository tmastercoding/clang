#include <iostream>
using namespace std;

// break
void ex00();

// continue
void ex01();

// break in while loop
void ex02();

// continue in while loop
void ex03();

int main(){
    // break
    // ex00();

    // continue
    // ex01();

    // break in while loop
    // ex02();

    // continue in while loop
    ex03();

    return 0;
}

// break
void ex00(){
    // loop if number is less than ten while increasing number each time
    for(int number = 0; number < 10; number++){
        // if number is 4
        if(number == 4){
            // end the whole loop completely
            break;
        }

        // print the number
        cout << number << endl;
    }
}

// continue
void ex01(){
    // loop if number is less than ten while increasing number each time
    for(int number = 0; number < 10; number++){
        // if number is 4
        if(number == 4){
            // skip this cycle of the loop
            continue;
        }

        // print the number
        cout << number << endl;
    }
}

// break in while loop
void ex02(){
    int number = 0;

    // while number is less than 10
    while(number < 10){
        // if number is 4
        if(number == 4){
            // end the loop completely
            break;
        }
        
        // print the number
        cout << number << endl;

        // add 1 to the number
        number++;
    }
}

// continue in while loop
void ex03(){
    int number = 0;

    // while number is less than 10
    while(number < 10){
        // if number is 4
        if(number == 4){
            // add 1 to number, since 
            // there will be an infinite loop otherwise
            number++;

            // skip this loop
            continue;
        }

        // print number
        cout << number << endl;

        // add 1 to number
        number++;
    }
}