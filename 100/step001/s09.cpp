#include <iostream>
using namespace std;

int main(){
    // declare variables
    int a, b, c;

    cout << "Input 3 numbers" << endl;
    // get input
    cin >> a >> b >> c;

    // do calculations
    // with % getting remainder
    cout << ( a + b ) % c << endl;
    cout << ( ( a % c )+( b % c ) ) % c << endl;
    cout << ( a * b ) % c << endl;
    cout << ( ( a % c) * (b % c ) ) % c << endl;

    return 0;
}