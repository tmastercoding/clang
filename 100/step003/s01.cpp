#include <iostream>
using namespace std;

int main(){
    int timesTable = 2;
    cin >> timesTable;

    for(int idx = 1; idx < 10; idx++){
        cout << timesTable << " * " << idx << " = " << idx * timesTable << endl;
    }

    return 0;
}