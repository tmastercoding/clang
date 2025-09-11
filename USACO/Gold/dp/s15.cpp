#include <iostream>
using namespace std;

int main(){
    int n, m;
    cin >> n >> m;
    long long dp[41] = {};
    dp[1] = 1;
    dp[2] = 2;
    for(int i = 3; i <= n; i++){
        dp[i] = dp[i-1]+dp[i-2];
    }

    int prev = 0, vip;
    long long sum = 1;
    for(int i = 0; i < m; i++){
        cin >> vip;
        if(dp[vip-prev-1] > 0){
            sum *= dp[vip-prev-1];
        }
        prev = vip;
    }
    if(dp[n-prev] > 0){
        sum *= dp[n-prev];
    }

    cout << sum << '\n';
    return 0;
}