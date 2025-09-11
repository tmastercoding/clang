#include <iostream>
using namespace std;

int main(){
    int t;
    cin >> t;
    for(int c = 0; c < t; c++){

        int n;
        cin >> n;
        int score[100000][2];
        int dp[100000][2];
        for(int i = 0; i < n; i++){
            cin >> score[i][0];
        }
        for(int i = 0; i < n; i++){
            cin >> score[i][1];
        }
        
        for(int i = 0; i < n; i++){
            if(i == 0){
                dp[i][0] = score[i][0];
                dp[i][1] = score[i][1];
            } else if (i == 1){
                dp[i][0] = dp[i-1][1]+score[i][0];
                dp[i][1] = dp[i-1][0]+score[i][1];
            } else{
                dp[i][0] = max(max(dp[i-2][1], dp[i-2][0]), dp[i-1][1])+score[i][0];
                dp[i][1] = max(max(dp[i-2][1], dp[i-2][0]), dp[i-1][0])+score[i][1];
            }
        }
    
        cout << max(dp[n-1][0], dp[n-1][1]) << '\n';
    }
    return 0;
}