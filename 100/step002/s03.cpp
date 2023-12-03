#include <iostream>
using namespace std;

int is_leap( int year ) {
    return (!( year % 4) && ( (year % 100) || !( year % 400 ) ) ) ;
}

int main(){
    int year;
    cin >> year;

    cout << is_leap( year ) << endl;

    return 0;
}