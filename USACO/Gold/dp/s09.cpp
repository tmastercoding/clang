#include <iostream>
using namespace std;

int main(){
    int n;
    cin >> n;
    if(n & 1){
        cout << "CY\n";
    } else{
        cout << "SK\n";
    }

    return 0;
}