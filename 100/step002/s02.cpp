#include <iostream>
using namespace std;

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