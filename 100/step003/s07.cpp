#include <iostream>
using namespace std;

int main(){
    int a = 1;
    int b = 1;

    // 101
    // 010

    while(1){
        cin >> a >> b;
        if(!(a | b)) break;
        cout << a + b << endl;
    }

    return 0;
}