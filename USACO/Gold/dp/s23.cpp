#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    freopen("nocross.in", "r", stdin);
    freopen("nocross.out", "w", stdout);
    int n;
    cin >> n;
    int dp[1000][1000];
    int arr[1000][2];
    for(int i = 0; i < n; i++){
        cin >> arr[i][0];
    }
    for(int i = 0; i < n; i++){
        cin >> arr[i][1];
    }

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            dp[i][j] = 0;
        }
    }
    
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(abs(arr[i][0]-arr[j][1])<=4){
                if(i == 0 || j == 0){
                    dp[i][j] = 1;
                } else{
                    int temp = dp[i-1][j-1]+1;
                    if(temp <  dp[i][j-1]) temp = dp[i][j-1];
                    if(temp <  dp[i-1][j]) temp = dp[i-1][j];
                    dp[i][j] = temp;
                }
            } else{
                if(i == 0 || j == 0){
                    dp[i][j] = 0;
                } else{
                    int temp = dp[i][j-1];
                    if(temp < dp[i-1][j]) temp = dp[i-1][j];
                    dp[i][j] = temp;
                }
            }
        }
    }

    int max = 0;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(dp[i][j] > max) max = dp[i][j];
        }
    }  
    cout << max << '\n';

    return 0;
}