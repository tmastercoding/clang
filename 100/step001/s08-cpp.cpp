#include <iostream>
using namespace std;

int main(){
    // declare buddhist + christian year
    int b_year;
    int c_year;

    // dif between year sys
    int year_dif = 2541 - 1998;

    // get input
    cin >> b_year;

    // subtract c_year with dif
    c_year = b_year - year_dif;

    // output
    cout << c_year << endl;

    return 0;
}