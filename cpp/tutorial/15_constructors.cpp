#include <iostream>
#include <string>
using namespace std;

// define class
class MyClass {
    public:
        // public constructor:
        // every time object created
        // constructor name same as class name
        MyClass(){
            // this code is executed
            cout << "Hello World!" << endl;
        }
};

class Car {
    // attributes that are private
    private:
        string brand;
        string model;
        int year;

    public:
    /*
        // constructor has parameters
        Car(string brand, string model, int year){
            // sets the attributes
            this->brand = brand;
            this->model = model;
            this->year = year;
        // }
    */
        // just the prototypes
        Car(string brand, string model, int year);

        // get functions that return the value of the attribrutes

        string getBrand() {
            return this->brand;
        }
        string getModel() {
            return this->model;
        }
        int getYear() {
            return this->year;
        }
};

// actual main body of method, with parameters
Car::Car(string brand, string model, int year){
    this->brand = brand;
    this->model = model;
    this->year = year;
}

int main(){
    MyClass myObj;

    // open bracket, input parameters when creating object
    Car myCar("BMW", "X5", 1999);
    // check if attributes are inputted correctly
    cout << "Brand: " << myCar.getBrand() << endl;
    cout << "Model: " << myCar.getModel() << endl;
    cout << "Year: " << myCar.getYear() << endl;

    Car tayCar("TTesla", "Model T", 888);
    cout << "Brand: " << tayCar.getBrand() << endl;
    cout << "Model: " << tayCar.getModel() << endl;
    cout << "Year: " << tayCar.getYear() << endl;    

    return 0;
}