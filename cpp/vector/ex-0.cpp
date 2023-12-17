#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main(){

    int i_arr[] = { 1, 2, 3, 4, 5};
    vector<int> v { 1, 2, 3, 4, 5};

    for( int i : i_arr ) {
        cout << i << endl;
    }

    for( int i : v ) {
        cout << i << endl;
    }

    cout << sizeof(i_arr)/sizeof(int) << endl;
    cout << v.size() << endl;

    for(int idx = 0; idx < v.size(); idx++){
        cout << v.at( idx ) << endl;
    }
    
    return 0;
}