#include <iostream>
using namespace std;

int main(){
    int n;
    cin >> n;
    if(n & 1){
        cout << "SK\n";
    } else{
        cout << "CY\n";
    }

    return 0;
}