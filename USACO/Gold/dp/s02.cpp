#include <iostream>
using namespace std;

long long dp[1005] = {};
int f(int cur){
    if(cur<= 1){
        return cur;
    }

    if(dp[cur-1] == -1){
        dp[cur-1] = f(cur-1)%10007;
    }
    if(dp[cur-2] == -1){
        dp[cur-2] = f(cur-2)%10007;
    }

    return dp[cur-1]+dp[cur-2]*2;
}
int main(){ 
    int n;
    for(int i = 0; i < 1005; i++){
        dp[i] = -1;
    }
    cin >> n;
    cout << f(n+1)%10007 << '\n';
    return 0;
}