#include <iostream>
using namespace std;

int dp[10000];

int main(){
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    int n; 
    int arr[10000];
    cin >> n;
    for(int i = 0; i < n; i++) cin >> arr[i];

    for(int i = 0; i < n; i++){
        int add = 0;
        if(i > 0) add = dp[i-1];
        int min = arr[i], max = arr[i];
        
        for(int j = i; j < n; j++){
            if(min > arr[j]) min = arr[j];
            if(max < arr[j]) max = arr[j];
            if(dp[j] < max-min+add){
                dp[j] = max-min+add;
            }
        }
    }
    
    // for(int i = 0; i < n; i++) cout << dp[i] << ' ';
    // cout << '\n';
    cout << dp[n-1] << '\n';

    return 0;
}