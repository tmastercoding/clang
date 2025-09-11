#include <iostream>
using namespace std;

int dp[10000001] = {};

int main(){
    int n;
    dp[1] = 1;
    dp[2] = 2;
    cin >> n;
    for(int i = 3; i <= n; i++){
        dp[i] = dp[i-1]+dp[i-2];
        if(dp[i]>9){
            dp[i]-=10;
        }
    }

    cout << dp[n] << '\n';
    return 0;
}