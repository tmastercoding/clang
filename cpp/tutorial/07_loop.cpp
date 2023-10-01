#include <iostream>
using namespace std;

// while loop
void ex00();

// do while loop
void ex01();

// for loop
void ex02();

// for loop
void ex03();

// nested loop
void ex04();

// foreach loop
void ex05();

int main(){
    // while loop
    // ex00();

    // do while loop
    // ex01();

    // for loop
    // ex02();

    // for loop
    // ex03();

    // nested loop
    // ex04();

    // foreach loop
    ex05();

    return 0;
}

// while loop
void ex00(){
    int i = 0;

    // while (statement) is true
    while( i < 5 ){
        // do:
        // print i
        cout << i << "\n";
        // increase idx
        i++;
    }
}

// do while loop
void ex01(){
    int i = 0;
    
    // do this first
    do {
        // print idx
        cout << i << endl;
        // increase idx
        i++;
    // keep going if statement is true
    } while( i < 5 );
}

// for loop
void ex02(){
    // (set idx; statement; change idx)
    for(int i = 0; i < 5; i++){
        // print i
        cout << i << "\n";
    }
}

// for loop
void ex03(){
    // you can change the idx in any way
    for(int i = 0; i < 10; i = i+2){
        cout << i << endl;
    }
}

// nested loop
void ex04(){
   // you can put outer: and inner:
    // to differentiate the nested loops

    // outer is done 2 times
    outer:
    for(int idx = 1; idx <= 2; ++idx){
        // print idx
        cout << "Outer: " << idx << endl;

        // inner is done 3 times each outer
        inner:
        for(int jdx = 1; jdx <= 3; ++jdx){
            // print jdx
            cout << "Inner: " << jdx << endl;
        }
    }
    // 2 x 3 = 6
    // inner is done 6 times in total 
}

// foreach loop
void ex05(){
    // array to loop
    int myNumbers[5] = {10, 20, 30, 40, 50};

    // for(variable: array){
    for(int i : myNumbers){
        // each variable is a variable from array
        cout << i << endl;
    }
}