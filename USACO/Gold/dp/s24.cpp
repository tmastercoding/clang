#include <iostream>
using namespace std;

int main(){
    int n;
    cin >> n;
    int happy[100000][3];
    int dp[100000][3];

    for(int i = 0; i < n; i++){
        cin >> happy[i][0] >> happy[i][1] >> happy[i][2];
    }

    for(int i = 0; i < n; i++){
        if(i == 0){
            dp[i][0] = happy[i][0];
            dp[i][1] = happy[i][1];
            dp[i][2] = happy[i][2];
        } else{
            dp[i][0] = max(dp[i-1][1], dp[i-1][2])+happy[i][0];
            dp[i][1] = max(dp[i-1][0], dp[i-1][2])+happy[i][1];
            dp[i][2] = max(dp[i-1][0], dp[i-1][1])+happy[i][2];
        } 
    }

    cout << max(max(dp[n-1][0], dp[n-1][1]), dp[n-1][2]) << '\n';

    return 0;
}