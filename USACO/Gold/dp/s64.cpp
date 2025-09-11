#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

long long n, arr[1000000];
int dp[1000000];
int main(){
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    } 

    vector<long long> v;
    for(int i = 0; i < n; i++){
        auto pos = lower_bound(v.begin(), v.end(), arr[i]);
        if(pos != v.end()){
            *pos = arr[i];
            dp[i] = pos-v.begin()+1;
        } else{
            v.push_back(arr[i]);
            dp[i] = v.size();
        }
    }

    cout << v.size() << '\n';
    // for(int i = 0; i < n; i++) cout << dp[i] << ' ';
    // cout << '\n';
    vector<int> out;
    int idx = v.size()+1;
    for(int i = n-1; i > -1; i--){
        if(idx == -1) break;
        if(idx-1 == dp[i]){
            out.push_back(arr[i]);
            idx--;
        }
    }

    for(int i = out.size()-1; i > -1; i--) cout << out[i] << ' ';
    cout << '\n';
    return 0;
}