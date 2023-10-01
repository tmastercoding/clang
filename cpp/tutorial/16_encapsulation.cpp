#include <iostream>
using namespace std;

// class definitons
class Employee {
    private:
        // Private attributes, to increase security
        int salary;

    public:
        // setter
        void setSalary(int salary){
            // this->attribute, accesses the attribute of the object
            // object's salary is salary 
            this->salary = salary;
        }

        // getter
        int getSalary(){
            // returns object's salary
            return this->salary;
        }
};

int main(){
    // creates an employee called worker
    Employee worker;

    // set worker's salary to -123
    worker.setSalary(-123);

    // print worker's salary
    cout << worker.getSalary() << endl;

    return 0;
}