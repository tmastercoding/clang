#include <iostream>
using namespace std;

int main(){
    int n;
    cin >> n;
    int stairs[300];
    int dp[300][2];
    for(int i = 0; i < n; i++){
        cin >> stairs[i];
    }

    for(int i = 0; i < n; i++){
        if(i == 0){
            dp[i][0] = stairs[i];
            dp[i][1] = 0;
        } else if(i == 1){
            dp[i][0] = stairs[i];
            dp[i][1] = dp[i-1][0]+stairs[i];
        } else{
            dp[i][0] = max(dp[i-2][1], dp[i-2][0])+stairs[i];
            dp[i][1] = dp[i-1][0]+stairs[i];
        }
        // cout << dp[i][0] << ' ' << dp[i][1] << '\n';
    }

    cout << max(dp[n-1][0],dp[n-1][1]) << '\n';

    return 0;
}