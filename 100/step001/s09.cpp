#include <iostream>
using namespace std;

int main(){
    int a, b, c;

    cout << "Input 3 numbers" << endl;
    cin >> a >> b >> c;

    cout << ( a + b ) % c << endl;
    cout << ( ( a % c )+( b % c ) ) % c << endl;
    cout << ( a * b ) % c << endl;
    cout << ( ( a % c) * (b % c ) ) % c << endl;

    return 0;
}