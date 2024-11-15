#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    // declare variables
    vector<int> v;
    const int size = 10;
    int idx = 0;
    int num = 0;
    vector<int>::iterator it;

    // loop for input
    while(idx < size){

        // input
        cin >> num;   

        // if first
        if( v.empty() ){
            v.push_back(num % 42);
        } else{
            // find num in v
            it = find(v.begin(), v.end(), num % 42);
            if(it == v.end()){
                v.push_back(num%42);
            }
        }
        // it = find(v.begin(), v.end(), num % 42);
        // if(it == v.end()){
        //     v.push_back(num%42);
        // }
        idx++;
    }
    // output
    cout << v.size() << endl;

    return 0;
}