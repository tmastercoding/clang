#include <iostream>
using namespace std;

int main(){
    // get input
    int a, b;
    cin >> a >> b;

    // if a greater than b
    if (a > b){
        cout << '>' << endl;
    // if a less than b
    } else if (a < b){
        cout << '<' << endl;
    // if none of the above
    } else{
        cout << '=' << endl;
    }

    // short had form using tenary:
    cout << ((a > b)? '>' :
            (a < b)? '<' : '=' )<< endl;

    return 0;
}