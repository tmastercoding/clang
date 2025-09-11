#include <iostream>
#include <algorithm>
#include <utility>
using namespace std;


int main(){
    int n;
    cin >> n;
    pair<int, int> arr[101];
    int dp[101] = {};    
    for(int i = 0; i < n; i++){
        int a, b;

        cin >> a >> b;
        if(a > b){
            arr[i].first = a, arr[i].second = b;
        } else{
            arr[i].first = b, arr[i].second = a;
        }
        dp[i] = 1;
    }

    sort(arr, arr+n);

    for(int i = n-1; i > -1; i--){
        int max = 1;
        for(int j = n-1; j > i; j--){
            if((arr[i].first <= arr[j].first && arr[i].second <= arr[j].second) || (arr[i].second <= arr[j].first && arr[i].first <= arr[j].second)){
                if(max < dp[j]+1){
                    max = dp[j]+1;
                }
            }
        }
        dp[i] = max;
    }

    int ans = 0;
    for(int i = 0; i < n; i++){
        // cout << dp[i] << '\n';
        if(ans < dp[i]) ans = dp[i];
    }

    cout << ans;

    return 0;
}