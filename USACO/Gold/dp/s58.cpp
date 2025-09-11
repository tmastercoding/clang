#include <iostream>
using namespace std;

int dp[301][300];

int main(){
    int n, arr[300];
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> arr[i];
        dp[1][i] = 1;
    }
    
    for(int i = 0; i < n-1; i++){
        dp[2][i] = 2;
        if(arr[i] == arr[i+1]){
            dp[2][i] = 1;
        }
    }

    for(int k = 3; k <= n; k++){
        for(int i = 0; i <= n-k; i++){
            if(arr[i] == arr[i+k-1]){
                dp[k][i] = dp[k-2][i+1]+1;
                for(int j = i+1; j < i+k; j++){
                    if(arr[j] == arr[i]){
                        dp[k][i] = dp[][i+1]+2;
                    }
                }
            } else{
                dp[k][i] = dp[k-1][i]+1;
            }
        }
    }

    cout << dp[n][0] << '\n';

    return 0;   
}