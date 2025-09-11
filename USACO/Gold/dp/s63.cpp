#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main(){
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    int n, arr[1000000];
    
    cin >> n;
    for(int i = 0; i < n; i++) cin >> arr[i];

    vector<int> v;
    for(int i = 0; i < n; i++){
        auto pos = lower_bound(v.begin(), v.end(), arr[i]);
        if(pos != v.end()){
            *pos = arr[i];
        } else{
            v.push_back(arr[i]);
        }
    }

    cout << v.size() << '\n';


    return 0;
}