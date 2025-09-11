#include <iostream>
using namespace std;

int main(){
    int n;
    cin >> n;
    int wine[10000], dp[10000][3];
    for(int i = 0; i < n; i++) cin >> wine[i];

    int mwine = 0;
    for(int i = 0; i < n; i++){
        if(i == 0){
            dp[i][0] = wine[i];
            dp[i][1] = 0;
            dp[i][2] = 0;
        } else if(i == 1){
            dp[i][0] = wine[i];
            dp[i][1] = dp[i-1][0]+wine[i];
            dp[i][2] = max(max(dp[i-1][0],dp[i-1][1]),dp[i-1][2]);
        } else{
            dp[i][0] = dp[i-1][2]+wine[i];
            dp[i][1] = dp[i-1][0]+wine[i];
            dp[i][2] = max(max(dp[i-1][0],dp[i-1][1]),dp[i-1][2]);
        }
        
        if(mwine < dp[i][0]) mwine = dp[i][0];
        if(mwine < dp[i][1]) mwine = dp[i][1];
        if(mwine < dp[i][2]) mwine = dp[i][2];
    }

    cout << mwine << '\n';

    return 0;
}