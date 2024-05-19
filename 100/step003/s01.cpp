#include <iostream>
using namespace std;

int main(){
    // get input
    int timesTable = 2;
    cin >> timesTable;

    // loop from 1 - 10
    for(int idx = 1; idx < 10; idx++){
        // print times table
        cout << timesTable << " * " << idx << " = " << idx * timesTable << endl;
    }

    return 0;
}