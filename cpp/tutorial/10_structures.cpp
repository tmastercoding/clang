#include <iostream>
#include <string>
using namespace std;

// create struct members
void ex00();

// access struct members
void ex01();

// one structure in multiple variables
void ex02();

// named structures
void ex03();

int main(){
    // create struct members
    // ex00();

    // access struct members
    // ex01();
    
    // one structure in multiple variables
    // ex02();

    // named structures
    ex03();

    return 0;
}


// create struct members
void ex00(){
    struct {                // structure declare
        int myNum;          // int member
        string myString;    // string member
    } myStructure;          // structure name/variable
}

// access struct members
void ex01(){
    // create a structure and create a variable of the struct
    struct {
        int myNum;
        string myString;
    } myStructure;

    // assign values to variable
    myStructure.myNum = 1;
    myStructure.myString = "Hello world!";

    // print both variables
    cout << myStructure.myNum << endl;
    cout << myStructure.myString << endl;
}


// one structure in multiple variables
void ex02(){
    // create a structure and create two variables
    struct{
        string brand;
        string model;
        int year;
    } myCar1, myCar2;

    // put data to first structure
    myCar1.brand = "BMW";
    myCar1.model = "X5";
    myCar1.year = 1999;

    // put data to second structure
    myCar2.brand = "Ford";
    myCar2.model = "Mustang";
    myCar2.year = 1969;

    // print the structure members
    cout << myCar1.brand << " " << myCar1.model << " " << myCar1.year << "\n";
    cout << myCar2.brand << " " << myCar2.model << " " << myCar2.year << endl;

}

// named structures
void ex03(){
    // create a structure called CAR
    struct CAR{
        string brand;
        string model;
        int year;
    };

    // create two CAR variables
    CAR myCar1;
    CAR myCar2;

    // put data to first structure
    myCar1.brand = "BMW";
    myCar1.model = "X5";
    myCar1.year = 1999;

    // put data to second structure
    myCar2.brand = "Ford";
    myCar2.model = "Mustang";
    myCar2.year = 1969;

    // print the structure members
    cout << myCar1.brand << " " << myCar1.model << " " << myCar1.year << "\n";
    cout << myCar2.brand << " " << myCar2.model << " " << myCar2.year << endl;

}