#include <iostream>
using namespace std;

// sol 1
void solv() {
    // declare integer
    int n;

    // get input
    cin >> n;

    // divide by 4 (adding long is 4 bytes)
    n = n/4;
    
    // loop n times
    while( n-- > 0 ) {
        cout << "long" << " ";
    }

    cout << "int" << endl;
}

int main(){
    // get input
    int bytes;
    cin >> bytes;

    // loop for bytes/4 times
    for(int idx = 0; idx < bytes/4; idx++){
        cout << "long ";
    }

    cout << "int" << endl;

    return 0;
}