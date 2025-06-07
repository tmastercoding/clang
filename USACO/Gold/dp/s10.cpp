#include <iostream>
using namespace std;

int main(){
    int dp[1001] = {};
    dp[1] = 1;
    dp[0] = 2;
    int n;
    cin >> n;
    int sub[3] = {1, 3, 4};

    for(int i = 2; i <= n; i++){
        dp[i] = 2;
        for(int j = 0; j < 3; j++){
            if(i-sub[j]>= 0){
                if(dp[i-sub[j]] == 2){
                    dp[i] = 1;
                    break;
                }
            }
        }
    }

    if(dp[n] == 1){
        cout << "SK\n";
    } else{
        cout << "CY\n";
    }

    return 0;
}