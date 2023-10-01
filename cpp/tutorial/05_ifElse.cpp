#include <iostream>
#include <string>
using namespace std;

// if statement
void ex00(){
    int x = 20;
    int y = 18;

    // if(statement){
    // if x is greater than y
    if(x > y){
        // do:
        // print 20 is greater than 18
        cout << "20 is greater than 18" << endl;
    }
}

// else statement
void ex01(){
    int time = 20;

    // if(statement){}
    // time is less than 18
    if(time < 18){
        cout << "Good day" << endl;
    // else{
    } else {
        // if all other statements are false:
        cout << "Good evening." << endl;
    }
}

// else if statement
void ex02(){
    int time = 22;

    // if(statement){
    // if time is greater than 10
    if(time < 10){
        cout << "Good morning." << endl;

    // else if(statement){}
    } else if (time < 20) {
        // if other statements before this was false
        // and if this statement is true
        cout << " Good day." << endl;

    // else{
    } else {
        // if all other statements are false:
        cout << "Good evening." << endl;
    }

    // in tenary form or short form
    // (statement) ? (if true do this) : (else)

    // if else in tenary form
    // add another statement after : (else)
    string greeting = (time < 10) ? "Good morning." : 
                      (time < 20) ? "Good day."     :
                                    "Good evening.";
                                    
    cout << greeting << endl;
}

int main(){
    // if statement
    // ex00();

    // else statement
    // ex01();

    // else if
    ex02();

    return 0;
}