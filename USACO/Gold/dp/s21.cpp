#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    int n;
    cin >> n;
    pair<int, int> arr[100], dp[100];
    for(int i = 0; i < n; i++){
        cin >> arr[i].first >> arr[i].second;
    }
    
    // sort(arr, arr+n);
    for(int i = 0; i < n; i++){
        dp[i].first = 1;
        dp[i].second = arr[i].second;
    }

    for(int i = 0; i < n; i++){
        for(int j = 0; j < i; j++){
            if(dp[j].first+1 > dp[i].first){
                if(dp[j].second < dp[i].second){
                    dp[i].first = dp[j].first+1;
                }
            }
        }
    }

    int max = 1;
    for(int i = 0; i < n; i++){
        // cout << arr[i].first << ' ' << arr[i].second << ' ' << dp[i].first << ' ' << dp[i].second << '\n';
        if(dp[i].first > max) max = dp[i].first;
    }
    cout << n-max <<'\n';
    return 0;
}