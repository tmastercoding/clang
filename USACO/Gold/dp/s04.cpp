#include <iostream>
using namespace std;

int main(){
    int n, x, coins[100];
    long long dp[1000001] = {};

    cin >> n >> x;
    for(int i = 0; i < n; i++){
        cin >> coins[i];
    }
    for(int i = 1; i <= x; i++){
        dp[i] = 1e9+8;
        for(int j = 0; j < n; j++){
            if(i-coins[j] > -1){
                long long temp =  dp[i-coins[j]] + dp[coins[j]];
                if(i <= coins[j]) temp = dp[i-coins[j]]+1;
                if(dp[i] > temp) dp[i] = temp;
            }
        }
    }
    // for(int i = 1; i <= x; i++){
    //     cout << dp[i] << ' ';
    // }
    // cout << '\n';
    if(dp[x] == 1e9+8){
        cout << "-1\n";
    } else{
        cout << dp[x] << '\n';
    }
    return 0;
}