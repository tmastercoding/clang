#include <iostream>
using namespace std;

int main(){
    int n; 
    cin >> n;
    int dp[100001] = {};
    dp[0] = 0;
    for(int i = 1; i <= n; i++){
        dp[i] = 1e9;
        for(int j = 0; j <= 317; j++){
            if(i-j*j > -1){
                if(dp[i-j*j] < dp[i]) dp[i] = dp[i-j*j]+1;
            }
        }
    }

    cout << dp[n] << '\n';

    return 0;
}