#include <iostream>
using namespace std;

int main(){
    // two numbers
    int a = 1;
    int b = 1;

    // 101
    // 010

    // forever
    while(1){
        // get input
        cin >> a >> b;
        // if both false break
        if(!(a | b)) break;
        // print sum
        cout << a + b << endl;
    }

    return 0;
}