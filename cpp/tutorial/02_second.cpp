#include <iostream>
using namespace std;

int main(){
    // create variable
    int a;
    cout << "Type a number: "; // Type a number and press enter
    cin >> a; // Get user input from the keyboard to put into a
    cout << "Your number is: " << a << endl; // Display the input value

    // create 2 integer variables
    int x, y;

    // create a int called sum
    int sum;

    // get input for x
    cout << "Type a number: ";
    cin >> x;

    // get input for y
    cout << "Type another number: ";
    cin >> y;

    // add x and y, and put it into sum
    sum = x+y;
    
    // print sum
    cout << "Sum is: " << sum;

    return 0;
}