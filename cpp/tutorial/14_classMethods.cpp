#include <iostream>
#include <string>
using namespace std;

/*
// create class
class MyClass{
    // access specifier, methods can be accessed from outside
    public:
        // basically a function of a class
        void myMethod(){
            // prints hello world
            cout << "HELLO WORLD!" << endl;
        }
};
*/

class MyClass{
    public:
        // just a prototype of the method
        void myMethod();
};

// definiton outside of the class
// classname::methodname
void MyClass::myMethod(){
    // prints hello world
    cout << "HELLO WORLD" << endl;
}

class Car{
    public:
        // prototype of method with an integer parameter
        int speed(int maxSpeed);
};

// method defintion outside with the parameter
int Car::speed(int maxSpeed){
    // returns maxSpeed
    return maxSpeed;
}

int main(){
    // create object
    MyClass myObj;
    // methods can be accessed by putting a decimal point mark
    myObj.myMethod();

    // create object
    Car myCar;
    // just add the parameter as you would do for a function
    cout << myCar.speed(100) << endl;

    return 0;
}