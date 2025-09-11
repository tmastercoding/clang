#include <iostream>
using namespace std;

int main(){
    int n;
    cin >> n;
    int h[1000000];
    long long dp[1000000];
    for(int i = 0; i < n; i++){
        cin >> h[i];
        dp[i] = 100000000000;
    }

    dp[0] = 0;
    for(int i = 1; i < n; i++){
        if(i > 1){ 
            if(dp[i] > dp[i-2] + abs(h[i]-h[i-2])) dp[i] = dp[i-2] + abs(h[i]-h[i-2]);
            if(dp[i] > dp[i-1] + abs(h[i]-h[i-1])) dp[i] = dp[i-1] + abs(h[i]-h[i-1]);
        } else{

            dp[i] = dp[i-1] + abs(h[i]-h[i-1]);
        }
    }
    cout << dp[n-1] << '\n';
    return 0;
}