#include <iostream>
using namespace std;

int main(){
    int x;
    cin >> x;
    int dp[1000001] = {};

    for(int i = 2; i <= x; i++){
        dp[i] = 1e9;
        if(i % 3 == 0){
            if(dp[i] > dp[i/3]+1) dp[i] = dp[i/3]+1;
        }
        if(i % 2 == 0){
            if(dp[i] > dp[i/2]+1) dp[i] = dp[i/2]+1;
        }
        
        if(dp[i] > dp[i-1]+1) dp[i] = dp[i-1]+1;
    }

    cout << dp[x] << '\n';

    return 0;
}