#include <iostream>
#include <string>
using namespace std;

// creating references 
void ex00();

// creating and modifying pointers 
void ex01();

int main(){
    // creating references
    // ex00();

    // creating  and modifying pointers 
    ex01();
    return 0;
}

// creating references 
void ex00(){
    string food = "pizza";
    string &meal = food; // meal is refrencing food variable

    food = "hamburger";
    meal = "cereal";

    cout << food << endl;
    cout << meal << endl;
}


// creating  and modifying pointers 
void ex01(){
    string food = "pizza"; // variable
    string* ptr = &food; // pointer storing the address of variable

    cout << food << "\n";
    cout << &food << endl;
    cout << ptr << endl;
    cout << *ptr << endl;
    // cout << *(++ptr) << endl;

    *ptr = "hamburger";
    cout << *ptr << endl;
    cout << food << endl;
}