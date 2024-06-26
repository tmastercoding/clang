#include <iostream>
using namespace std;

void toArray() {
    int numSize = 3;

    int num1;
    char num2[numSize];
    cout << "Input two numbers." << endl;
    cin >> num1 >> num2;
    cout << num2 << endl;
    
    int num2ToInt = 1;
    for( int i = numSize-1; i >-1 ; i-- ) {
        //  cout << num2[ i ] << endl;
            cout << (num1 * (num2[i]-'0')) << endl;
            num2ToInt += (( i == 0 )? (num1 * (num2[i]-'0')) : num2ToInt + (num1 * (num2[i]-'0')));

    }
    cout << num2ToInt << endl;

}

int main(){
    int a, b;

    // get input
    cin >> a >> b;
    
    // power 10^0
    int exponentValue = 1;
    
    // loop 3 times as always 3 digit
    for( int i = 0; i < 3; i++ ) {
        // multiply a to a digit of b
        // digit of b = (b / exponentValue) % 10)
        cout << a * ( (int)(b / exponentValue) % 10) << endl;
        
        // increase power by 1 (e.g. 10^2)
        exponentValue *= 10;
    }

    // example:
    // 472
    // 385/1 % 10 = 385 % 10 = 5
    // 5 * a
    // 385/10 % 10 = 38 % 10 = 8
    // 8 * a
    // 385 / 100 % 10 = 3 % 10 = 3
    // 3 * a
    
    // cout << a * ((int)(b / 10 ) % 10) << endl;
    

    // cout << a * ((int)( b / 10 ) % 10  ) << endl;

    // print last row
    cout << a * b << endl;
    
    return 0;
}