#include <iostream>
#include <string>
#include <cmath>
using namespace std;

// class called number with various functions
class Number{
    // attributes are private
    private:
        double number;
        
    // methods are public
    public:
        // return number
        double getNumberInfo(){
            return number;
        }

        // replace number with another
        void inputNumber(double input){
            number = input;
        }

        // return sum of number and other object's number
        double add(Number number2){
            return number + number2.getNumberInfo();
        }

        // return difference of number and other object's number
        double subtract(Number number2){
            return number - number2.getNumberInfo();
        }

        // return product of number and other object's number
        double multiply(Number number2){
            return number * number2.getNumberInfo();
        }

        // return quotient of number and other object's number
        double divide(Number number2){
            return number / number2.getNumberInfo();
        }

        // return number to the power of other object's number
        double powerOf(Number number2){
            // double originalNumber = number;
            // if(number2.getNumberInfo == 1){
            //     return number;
            // } else if(number2.getNumberInfo() == 0){
            //     return 1;
            // } else if(number2 < 0){
            //     cout << "Please input positive integers only!" << endl;
            //     return -1;
            // }

            // for(int i = 0; i < number2.getNumberInfo()-1; i++){
            //     number *= originalNumber;
            // }
            // uses pow function from cmath
            return pow(number, number2.getNumberInfo());
        }
};

// gets input of a double and returns a Number object
Number getNumberInput();

// main code
int main(){
    // flag
    bool flag = true;
    // choice variable
    int userChoice;

    cout << "Calculator program: " << endl;
    // input starting number
    cout << "First input a number you want to calculate:" << endl;
    Number userNumber = getNumberInput();

    // while flag is true
    while(flag){
        // print choices
        cout << "What would you like to do?" << endl;
        cout << "1. Add" << endl;
        cout << "2. Subtract" << endl;
        cout << "3. Multiply" << endl;
        cout << "4. Divide" << endl;
        cout << "5. Power of" << endl;
        cout << "6. Reset number" << endl;
        cout << "7. Quit program" << endl;
        // get input from user
        cin >> userChoice;

        switch(userChoice){
            // addition
            case 1:
                // print current number
                cout << userNumber.getNumberInfo() << " + ";
                // change the userNumber to the sum of existing number with another number
                userNumber.inputNumber(userNumber.add(getNumberInput()));
                // print answer
                cout << "= " << userNumber.getNumberInfo() << endl;
                break;

            // subtraction
            case 2:
                // print current number
                cout << userNumber.getNumberInfo() << " - ";
                // change the userNumber to the difference of existing number with another number
                userNumber.inputNumber(userNumber.subtract(getNumberInput()));
                // print answer
                cout << "= " << userNumber.getNumberInfo() << endl;
                break;

            // multiplication
            case 3:
                // print current number
                cout << userNumber.getNumberInfo() << " x ";
                // change the userNumber to the product of existing number with another number
                userNumber.inputNumber(userNumber.multiply(getNumberInput()));
                // print answer
                cout << "= " << userNumber.getNumberInfo() << endl;
                break;

            // division
            case 4: 
                // print current number
                cout << userNumber.getNumberInfo() << " / ";
                // change the userNumber to the quotient of existing number with another number
                userNumber.inputNumber(userNumber.divide(getNumberInput()));
                // print answer
                cout << "= " << userNumber.getNumberInfo() << endl;
                break;

            // power of
            case 5: 
                // print current number
                cout << userNumber.getNumberInfo() << "^";
                // change the userNumber to the existing number to the power of another number
                userNumber.inputNumber(userNumber.powerOf(getNumberInput()));
                // print answer
                cout << "= " << userNumber.getNumberInfo() << endl;
                break;  

            // reset number
            case 6:
                // replace a userNumber with new input
                cout << "Please input number to replace: ";
                userNumber = getNumberInput();
                break;

            // quit program
            case 7:
                // switch flag
                flag = false;
                break;

            default:
                cout << "Please input a number between 1 and 7" << endl;
        }
    }

    return 0;
}

// gets input of a double and returns a Number object
Number getNumberInput(){
    // create new object
    Number userNumber;

    // create double variable
    double number;

    // get input for the double
    cin >> number;

    // assign this number as the object's number
    userNumber.inputNumber(number);

    // return object
    return userNumber;
}