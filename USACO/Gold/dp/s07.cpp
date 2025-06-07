#include <iostream>
#include <set>
using namespace std;

int main(){
    int n;
    cin >> n;
    int dp[1000001] = {};
    for(int i = 1; i <= n; i++){
        dp[i] = 1e9;
        set<int> digits;
        int num = i;
        while(num > 0){
            digits.insert(num%10);
            num/=10;
        }
        for(auto digit: digits){
            if(i-digit > -1){
                if(dp[i] > dp[i-digit]+1){
                    dp[i] = dp[i-digit]+1;
                }
            }
        }
    }
    // for(int i = 1; i <= n; i++){
    //     cout << dp[i] << ' ';
    // }
    // cout << '\n';
    cout << dp[n] << '\n';
    return 0;
}