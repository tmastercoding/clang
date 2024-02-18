#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    vector<int> v;
    const int size = 10;
    int idx = 0;
    int num = 0;
    vector<int>::iterator it;

    while(idx < size){

        // first
        cin >> num;   

        if( v.empty() ){
            v.push_back(num % 42);
        } else{
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
    cout << v.size() << endl;

    return 0;
}