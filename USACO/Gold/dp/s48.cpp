#include <iostream>
using namespace std;

long long dp[100][21];
int main(){
    int n, result;
    cin >> n;
    int input[100];
    for(int i = 0; i < n; i++){
        cin >> input[i];
    }
    result = input[n-1];

    dp[0][input[0]] = 1;

    for(int i = 1; i <= n-1; i++){
        for(int j = 0; j <= 20; j++){
            if(j-input[i] >= 0){
                dp[i][j-input[i]] += dp[i-1][j];
            }
            
            if(j+input[i] <= 20){
                dp[i][j+input[i]] += dp[i-1][j];
            }
        }
    }

    cout << dp[n-2][result] << '\n';
    return 0;
}