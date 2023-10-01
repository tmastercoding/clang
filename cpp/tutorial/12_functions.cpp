#include <iostream>
#include <string>
using namespace std;

// call a function
void ex00();
void myFunction();
void myFunction2(string fname = "Tay", int age= 12);

// parameters and arguments
void ex01();

// return values
int ex02(int x);

// addition
int addition(int x, int y);

// pass by references
void ex03();
void swapNums(int &x, int &y);

// pass arrays as function parameters
void myFunction3(int* myNumbers, int size);

void myFunction4(int myNumbers[5]);

int main(){
    // call a function
    // ex00();

    // parameters and arguments
    ex01();

    // return values
    // cout << ex02(1) << endl;

    // addition
    // cout << addition(12341234, 12341) << endl;

    // pass by references
    // ex03();
    
    // pass arrays as function parameters
    const int size = 5;
    int myNumbers[size] = {1, 2, 3, 4, 5};
    myFunction3(myNumbers, size);
    myFunction4(myNumbers);
    return 0;
}

// call a function
void ex00(){
    myFunction();
    myFunction();
    myFunction();
}

void myFunction(){
    cout << "I just got called" << endl;
}

// parameters and arguments
void ex01(){
    myFunction2("liam", 99);
    myFunction2("jenny", 0);
    myFunction2("anja", 8);
    myFunction2();
}

void myFunction2(string fname, int age){
    cout << "my name is " << fname << " I am " << age << endl;
}

// addition values
int addition(int x, int y){
    return x+y;    
}

// return values
int ex02(int x){
    return 5+x;
}

void swapNums(int &x, int &y){
    int z = x;
    x = y;
    y = z;
}

// pass by references
void ex03(){
    int firstNum = 10;
    int secondNum = 20;

    cout << "Before swap: " << endl;
    cout << firstNum << endl;
    cout << secondNum << endl;

    swapNums(firstNum, secondNum);

    cout << "After swap: " << endl;
    cout << firstNum << endl;
    cout << secondNum << endl;
}

// pass arrays as function parameters
void myFunction3(int* myNumbers, int size){
    for(int i = 0; i < size; i++){
        cout << myNumbers[i] << endl;
    }



    // for(int number: *myNumbers){
    //     cout << number;
    // }

    // int *temp = new int(10);
}

void myFunction4(int myNumbers[5]){
    for (int i = 0; i < 5; i++){
        cout << myNumbers[i] << endl;
    }

    for(int number : myNumbers){
        cout << number << endl;
    }
}