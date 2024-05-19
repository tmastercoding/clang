#include <iostream>
using namespace std;

// function returning 1 or 0, checking leap year
int is_leap( int year ) {
    // if year is multiple of 4 and 
    // (multiple of 100 or not multiple of 400)
    return (!( year % 4) && ( (year % 100) || !( year % 400 ) ) ) ;
}

int main(){
    // get input
    int year;
    cin >> year;

    // call function
    cout << is_leap( year ) << endl;

    return 0;
}