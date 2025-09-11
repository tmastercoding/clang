#include <iostream>
using namespace std;

long long dp[1500000];
int arr[1500000][2];

int main(){
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    int n;
    cin >> n;
    for(int i = 0; i < n; i++) cin >> arr[i][0] >> arr[i][1];

    long long max = 0;
    for(int i = 0; i < n; i++){
        if(i+arr[i][0]-1 < n){
            if(max+arr[i][1] > dp[i+arr[i][0]-1]) dp[i+arr[i][0]-1] = max+arr[i][1];
        }
        if(max < dp[i]) max = dp[i];
        // cout << dp[i] << '\n';
    }

    cout << max << '\n';

    return 0;
}