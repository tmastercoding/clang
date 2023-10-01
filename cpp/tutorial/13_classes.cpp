#include <iostream>
#include <string>
using namespace std;

class ClassTemp {       // The class        
    public:             // Access specifier
        int num;        // Attributes
        string text;
};

class Car {       
    public:             
        string brand;
        string model;        
        int year;
    

    public:
        void printInfo(){
            cout << "Car Info: " << endl;
            cout << "Brand: " << brand << endl;
            cout << "Model: " << model << endl;
            cout << "Year: " << year << endl;
        }
        string getModel();
        int speed(int maxSpeed);
};

string Car::getModel(){
    return model;
}
int Car::speed(int maxSpeed){
    return maxSpeed;
}

// create an object
void ex00();

// multiple objects
void ex01();

int main(){
    // create an object
    // ex00();

    // multiple objects
    ex01();

    

    return 0;
}

// create an object
void ex00(){
    ClassTemp obj;
    
    obj.num = 14;
    obj.text = "asldjfh";

    cout << obj.num << endl;
    cout << obj.text << endl;
}


// multiple objects
void ex01(){
    Car car1;
    Car car2;

    car1.brand = "Kia";
    car1.model = "Sorento";
    car1.year = 1000;

    car2.brand = "Tesla";
    car2.model = "X";
    car2.year = 2999;

    // cout << "Car1: " << endl;
    // cout << "Brand: " << car1.brand << endl;
    // cout << "Model: " << car1.model << endl;
    // cout << "Year: " << car1.year << endl;
    car1.printInfo();
    // cout << "Car2: " << endl;
    // cout << "Brand: " << car2.brand << endl;
    // cout << "Model: " << car2.model << endl;
    // cout << "Year: " << car2.year << endl;
    car2.printInfo();

    cout << car1.getModel() << endl;
    cout << car1.speed(12312) << endl;
}