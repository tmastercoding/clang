#include <iostream>
using namespace std;

class Vehicle{
    // private attributes
    private:
        // a string with the value Ford
        string brand = "Ford";
    public:
        // get function
        string getBrand(){
            return this->brand;
        }

        // honk function that prints tuut tuut
        void honk(){
            cout << "Tuut, tuut! \n";
        }
};


// Derived class
// create class derived from vehicle
// class Child class name: public Parent class name{
class Car: public Vehicle {
    // private attributes
    private:
        // string with the value Mustard
        string model = "Mustard";
    public:
        // getFunction
        string getModel(){
            return this->model;
        }

};


int main(){
    // create an object of Car
    Car myCar;

    // object has the methods and attributes of vehicle since 
    // Car inherited from Vehicle
    myCar.honk();

    // print brand and model
    cout << "Brand: " << myCar.getBrand() << endl;
    cout << "Model: " << myCar.getModel() << endl;

    return 0;
}