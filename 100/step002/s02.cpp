#include <iostream>
using namespace std;

void print_flag() {

    int record;
    char flag;

    cin >> record;

    record /=10;

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

    cout << flag << endl;
}

int main(){ 
    int grade;
    cin >> grade;

    cout << ((grade < 101 && 89 < grade)? 'A':
            (grade < 90 && 79 < grade)? 'B':
            (grade < 80 && 69 < grade)? 'C':
            (grade < 70 && 59 < grade)? 'D':
            'F') << endl;

    return 0;
}