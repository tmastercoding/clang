#include <iostream>
using namespace std;

int main(){
    int n, x;
    int books[1000][2];
    int dp[1000][100001];
    cin >> n >> x;

    for(int i = 0; i < n; i++){
        cin >> books[i][0];
    }
    for(int i = 0; i < n; i++){
        cin >> books[i][1];
    }
    
    for(int j = 0; j <= x; j++){
        if(books[0][0] <= j) dp[0][j] = books[0][1];
    }

    for(int i = 1; i < n; i++){
        for(int j = 0; j <= x; j++){
            dp[i][j] = dp[i-1][j];
            if(j >= books[i][0]){
                if(books[i][1]+dp[i-1][j-books[i][0]] > dp[i][j]){
                    dp[i][j] = books[i][1]+dp[i-1][j-books[i][0]];
                }
            }
        }
    }
    
    // for(int i = 0; i < n; i++){
    //     for(int j = 0; j <= x; j++){
    //         cout << dp[i][j] << ' ';
    //     }
    //     cout << '\n';
    // }

    int max = 0;
    for(int j = 0; j <= x; j++){
        if(max < dp[n-1][j]){
            max = dp[n-1][j];
        }
    }

    cout << max << '\n';

    return 0;
}