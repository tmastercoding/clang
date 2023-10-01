#include <iostream>
using namespace std;

class Employee {
    protected: // protected access specifier meaning only child class can access
        int salary;
};

// Derived class
class Programmer: public Employee{
    private:
        int bonus;
    public:
        // child class can still use salary attribute
        // setter and getter methods
        void setSalary(int salary) {
            this->salary = salary;
        }
        int getSalary(){
            return this->salary;
        }
        void setBonus(int bonus) {
            this->bonus = bonus;
        }
        int getBonus(){
            return this->bonus;
        }
};

int main(){
    // Create programmer object
    Programmer myObj;
    // set bonus and salary
    myObj.setBonus(15000);
    myObj.setSalary(500000);

    // print attributes
    cout << "Salary: " << myObj.getSalary() << endl;
    cout << "Bonus: " << myObj.getBonus() << endl;

    return 0;
}