#include <iostream>
using namespace std;

// Boolean Values
void ex00() {
    // assign boolean values true and false
    bool isCodingFun = true;
    bool isFishTasty = false;

    // print variables
    cout << isCodingFun << "\n";
    cout << isFishTasty << endl;
}

// Boolean Expression 
void ex01() {
    int x = 10;
    int y = 9;

    // print if x is greater than y
    cout << (x > y) << endl;
    // printf("%d\n", (x > y));
}

// Boolean Expression 
void ex02() {
    int x = 10;
    int y = 9;

    // Print if x is less than y
    cout << (x < y) << endl;
    // printf("%d\n", (x > y));
}

// Boolean Expression 
void ex03() {
    int x = 10;
    int y = 9;

    // print if x is equal to y
    cout << (x == y) << endl;
    // print if x is equal to 10
    cout << (x == 10) << endl;
}

// Real Life Example 
void ex04() {
    int myAge = 11;
    int votingAge = 18;
    
    // cout << (myAge >= votingAge) << endl;

    // if myAge is greater than or equal to votingAge
    if(myAge >= votingAge){
        // Print:
        cout << "Old enough to vote!";
    // else
    } else{
        cout << "Not old enough to vote BABY!";
    }
}

int main() {
    // Boolean Values
    // ex00();

    // Boolean Expressions
    // ex01();

    // Boolean Expressions
    ex02();

    // Boolean Expressions
    // ex03();

    // Real life example
    // ex04();

    return 0;
}