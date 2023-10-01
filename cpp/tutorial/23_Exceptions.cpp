#include <iostream>
using namespace std;

int main(){
    // try this code:
    try{
        int age = 15;
        // if age is greater than 18
        if (age >= 18){
            // access granted
            cout << "Access granted - you are old enough." << endl;
        } else{
            // if not throw an exception
            throw(age);
        }  
    }
    // catch the exception, getting an integer as a parameter
    catch(int myNum){
        // print access denied
        cout << "Access denied - " 
             << "You must be at least 18 years old!" << endl;
    }

    // try this code
    try{
        int age = 15;
        // if age is larger or equal to 18
        if (age >= 18){
            // allow access
            cout << "Access granted - you are old enough." << endl;
        } else{
            // else throw an exepction of 505
            throw 505;
        }  
    }
    // catch an exception taking a number as a parameter
    catch(int myNum){
        // print access denied
        cout << "Access denied - " 
             << "You must be at least 18 years old!" << endl;
        // print error number
        cout << "Error number " << myNum << endl;
    }

    try{
        int age = 15;
        if (age >= 18){
            cout << "Access granted - you are old enough." << endl;
        } else{
            throw 505;
        }  
    }
    // catches any exception
    catch(...){
        cout << "Access denied - " 
             << "You must be at least 18 years old!" << endl;
    }
    return 0;
}