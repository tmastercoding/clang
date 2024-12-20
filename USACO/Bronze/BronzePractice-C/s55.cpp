#include <iostream>
#include <vector>
using namespace std;

int main(){
    int n = 0, temp;
    cin >> n;
    vector <int> v, want;
    for(int idx = 0; idx < n; idx++){
        cin >> temp;
        v.push_back(temp);
    }
    for(int idx = 0; idx < n; idx++){
        cin >> temp;
        want.push_back(temp);
    }

    // v.pop_back();
    // v.insert(v.begin(), 5);
    for(int idx =0; idx < n; idx++){
        
        if(want[idx] == n){
            break;
        }
    }


    return 0;
}