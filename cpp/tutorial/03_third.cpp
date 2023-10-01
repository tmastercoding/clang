#include <iostream>
// include string and math library
#include <string>
#include <cmath>
using namespace std;

int main(){
    // create a string var
    string greeting = "Hello";
    // print this string
    cout << greeting << endl;

    // create two string variables 
    string firstName = "John ";
    string lastName = "Doe";

    // concat them together
    string fullName = firstName + lastName;
    // print full name
    cout << fullName << endl;

    // create another fullname variable
    // use append method to add firstName and lastName
    string fullName2 = firstName.append(lastName);

    // print fullName2
    cout << fullName2 << endl;
    // print firstName
    cout << firstName << endl;

    // append ALSO changes firstName

    // create 2 integers x, y
    int x = 10;
    int y = 20;

    // add them together
    // sum = z
    int z = x + y;

    // print this sum
    cout << z << endl; 

    // bitwise operators
    // & AND
    // sets each bit to 1 if both bits are 1
    int x2 = 5; // 101 in binary
    x2 &= 3; // 3 = 11 in binary

    cout << x2 << endl;
    // result: 1 (1)

    // | OR
    // sets each bit to 1 if one of two bits is 1
    int x4 = 5; // 101 in binary
    x4 |= 3; // 3 = 11 in binary

    cout << x4 << endl;
    // result: 7 (111)

    // ^ XOR
    // sets each bit to 1 ONLY if one of two bits is 1
    int x5 = 5; // 101 in binary
    x5 ^= 3; // 3 = 11 in binary

    cout << x5 << endl;
    // result: 6 (110)

    // >> signed right shift
    // shift all bits to the right deleting the end bit
    int x6 = 5; // 101 in binary
    x6 >>= 3; // 3 = 11 in binary

    // >> zerofill left shift
    // shift all bits to the left creating 0 in the end
    int x7 = 5; // 101 in binary
    x7 <<= 3; // 3 = 11 in binary

    cout << x7 << endl;
    // result: 40 (101000)

    // create two strings
    string a = "10";
    string b = "20";

    // concat them and print
    string c = a + b;
    cout << c << endl;

    // store alphabet in a string
    string txt = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

    // get the length using the length() method
    cout << "The length of the txt string is: " << txt.length() << endl;
    // get the length using the size() method
    cout << "The length of the txt string is: " << txt.size() << endl;

    // create a string
    string myString = "Hello";

    // access individual chars using index
    cout << myString[0] << endl;
    // Outputs H

    // get the second
    cout << myString[1] << endl;
    // Outputs e

    // change the first char into J
    myString[0] = 'J';
    cout << myString << endl;
    // Outputs Jello instead of Hello

    // Escape character: \"
    string txt2 = "We are the so-called \"Viking\" from the north.";
    cout << txt2 << endl;

    // Escape character: \'
    string txt3 = "It\'s alright.";
    cout << txt3 << endl;

    // Escape character: \\ asdf
    // string txt4 = "The character \\ is called backslash.";
    // cout << txt4 << endl;

    // string firstName2;
    // cout << "Type your first name: ";
    // cin >> firstName2; // get user input from the keyboard
    // cout << "Your name is: " << firstName2 << endl;

    // Type your first name : John
    // Your name is : John

    // create a string
    string fullName3;

    // get input using getline
    cout << "Type your full name: ";
    getline(cin, fullName3);

    // print input
    cout << "Your name is " << fullName3 << endl;

    // use sqrt to get the square root
    cout << sqrt(64) << endl;

    // use round to round numbers
    cout << round(2.6) << endl;

    cout << log(2) << endl;


    // create bools, either true or false
    bool isCodingFun = true;
    bool isFishTasty = false;
    cout << isCodingFun << endl; // Outputs 1(true)
    cout << isFishTasty << endl; // Outputs 0(false)

    // conditions
    int x3= 10;
    int y3 = 9;
    cout <<(x3 > y3); // returns 1 (true), because 10 is higher than 9
    return 0;
}