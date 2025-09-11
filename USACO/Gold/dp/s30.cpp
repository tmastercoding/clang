#include <iostream>
using namespace std;

int main(){
    int n;
    cin >> n;
    int dp[1000000][2][3];

    for(int i = 0; i < n; i++){
        if(i == 0){
            dp[i][0][0] = 1;
            dp[i][0][1] = 1;
            dp[i][0][2] = 1;
            dp[i][1][0] = 1;
            dp[i][1][1] = 1;
            dp[i][1][2] = 1;
            if(n == 1){
                dp[i][0][1] = 0;
                dp[i][1][1] = 0;
            }
        } else if(i == n-1){
            dp[i][0][0] = dp[i-1][1][0]+dp[i-1][1][]
        }

        }
    }

    return 0;
}