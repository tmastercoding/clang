#include <iostream>
using namespace std;

// Parent class 1
class Mother {
    public:
        void showDesc(){
            cout << "I am beautiful!" << endl;
        }
};

// Parent class 2
class Father{
    public:
        string getDesc(){
            return "I'm smart!";
        }
};

// Child who is derived from both parents
class Child : public Mother, public Father{
};

int main(){
    // create child object
    Child myObj;

    // child has all methods of the mother and father
    myObj.showDesc();
    cout << myObj.getDesc() << endl;
    return 0;
}