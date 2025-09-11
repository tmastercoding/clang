#include <iostream>
using namespace std;

int main(){
    int n, dp[1000][2], num[1000];
    cin >> n;

    for(int i = 0; i < n; i++){
        cin >> num[i];
        dp[i][0] = num[i];
        dp[i][1] = num[i];
    }

    for(int i = 1; i < n; i++){
        for(int j = 0; j < i; j++){
            if(dp[j][0]+num[i] > dp[i][0]){
                if(dp[j][1] < num[i]){
                    dp[i][0] = dp[j][0]+num[i];
                    dp[i][1] = num[i];
                }
            }
        }
    }
    
    int max = 0;
    for(int i = 0; i < n; i++){
        if(dp[i][0] > max) max = dp[i][0];
    }

    cout << max << '\n';
    return 0;
}