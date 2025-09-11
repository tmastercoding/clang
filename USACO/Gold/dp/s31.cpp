#include <iostream>
using namespace std;

int dp[20000000][3];
int main(){
    freopen("feast.in", "r", stdin);
    freopen("feast.out", "w", stdout);
    int t, a, b;
    cin >> t >> a >> b;

    dp[0][0] = a;
    dp[0][1] = b;
    dp[0][2] = 0;
    int m = b;
    if(a > b) m = a;
    for(int i = 1; i < 20000000; i++){
        if(dp[i-1][0] > dp[i-1][1]){
            dp[i][2] = dp[i-1][0]/2;
            dp[i][0] = dp[i-1][0]+a;
            if(dp[i][0] > t){
                dp[i][0] = dp[i-1][1]+a;
            }
            if(dp[i][0] > t){
                dp[i][0] = dp[i-1][2]+a;
            }
            if(dp[i][0] > t){
                dp[i][0] = dp[i-1][0];
            }

            dp[i][1] = dp[i-1][0]+b;
            if(dp[i][1] > t){
                dp[i][1] = dp[i-1][1]+b;
            }
            if(dp[i][1] > t){
                dp[i][1] = dp[i-1][2]+b;
            }
            if(dp[i][1] > t){
                dp[i][1] = dp[i-1][0];
            }
        } else{
            dp[i][2] = dp[i-1][1]/2;
            dp[i][0] = dp[i-1][1]+a;
            if(dp[i][0] > t){
                dp[i][0] = dp[i-1][0]+a;
            }
            // cout << dp[i][0] << '\n';
            if(dp[i][0] > t){
                dp[i][0] = dp[i-1][2]+a;
            }
            // cout << dp[i][0] << '\n';
            if(dp[i][0] > t){
                dp[i][0] = dp[i-1][1];
            }
            // cout << dp[i][0] << '\n';

            dp[i][1] = dp[i-1][1]+b;
            if(dp[i][1] > t){
                dp[i][1] = dp[i-1][0]+b;
            }
            if(dp[i][1] > t){
                dp[i][1] = dp[i-1][2]+b;
            }
            if(dp[i][1] > t){
                dp[i][1] = dp[i-1][1];
            }
        }
        // cout << dp[i][0] << ' ' << dp[i][1] << ' ' << dp[i][2] << '\n';
        if(m < max(dp[i][0], dp[i][1])){
            m = max(dp[i][0], dp[i][1]);
        }
    }
    cout << m << '\n';
    return 0;
}