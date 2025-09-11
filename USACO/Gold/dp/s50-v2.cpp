#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main(){
    int n;
    cin >> n;
    vector<int> arr[101];
    int dp[101] = {};    
    for(int i = 0; i < n; i++){
        int a, b;
        cin >> a >> b;
        arr[i].push_back(a);
        arr[i].push_back(b);
        dp[i] = 1;
    }

    sort(arr, arr+n);

    for(int i = n-1; i > -1; i--){
        int max = 1;
        for(int j = n-1; j > i; j--){
            if((arr[i][0] <= arr[j][0] && arr[i][1] <= arr[j][1]) || (arr[i][1] <= arr[j][0] && arr[i][0] <= arr[j][1])){
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