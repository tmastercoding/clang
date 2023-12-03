#include <iostream>
using namespace std;

void solv() {
    int n;

    cin >> n;

    n = n/4;
    while( n-- > 0 ) {
        cout << "long" << " ";
    }

    cout << "int" << endl;
}

int main(){
    int bytes;
    cin >> bytes;

    for(int idx = 0; idx < bytes/4; idx++){
        cout << "long ";
    }

    cout << "int" << endl;

    return 0;
}