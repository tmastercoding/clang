#include <iostream>
using namespace std;

// solution using switch case
void print_flag() {
    int record;
    // flag for grade
    char flag;

    // get input
    cin >> record;

    // becomes int not float
    // between 0-10
    record /=10;
    cout << record << endl;
    
    // switch case
    switch(record) {
        case 10:
            flag = 'A';
            break;
        case 9:
            flag = 'A';
            break;
        case 8:
            flag = 'B';
            break;
        case 7:
            flag = 'C';
            break;
        case 6:
            flag = 'D';
            break;
        default:
            flag = 'F';
            break;
    }

    // print flag
    cout << flag << endl;
}

int main(){ 
    // get input
    int grade;
    cin >> grade;

    // sol using tenary
    // (grade boundary)? 'letter grade':
    cout << ((grade < 101 && 89 < grade)? 'A':
            (grade < 90 && 79 < grade)? 'B':
            (grade < 80 && 69 < grade)? 'C':
            (grade < 70 && 59 < grade)? 'D':
            'F') << endl;

    return 0;
}