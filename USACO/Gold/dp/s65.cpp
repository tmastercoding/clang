#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    int n;
    int arr[200000];
    cin >> n; 
    for(int i = 0; i < n; i++) cin >> arr[i];

    vector<int> v;
    for(int i = 0; i < n; i++){
        auto pos = upper_bound(v.begin(), v.end(), arr[i]);
        if(pos != v.end()){
            *pos = arr[i];
        } else{
            v.push_back(arr[i]);
        }
    }

    // for(int i = 0; i < v.size(); i++) cout << v[i] << ' ';
    // cout << '\n';
    cout << v.size() << '\n';
    return 0;   
}