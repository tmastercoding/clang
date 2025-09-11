#include <iostream>
#include <vector>
using namespace std;

int dp[300][300];

int main(){
    // freopen("5.in", "r", stdin);
    vector<int> arr;
    int n;
    cin >> n;
    int num, idx = 0;
    cin >> num;
    arr.push_back(num);
    for(int i = 1; i < n; i++){
        cin >> num;
        if(num != arr[idx]){
            arr.push_back(num);
            idx++;
        }
    }
    idx++;

    for(int i = 0; i < idx; i++){
        // cout << arr[i] << ' ';
        dp[i][i] = 1;
    }
    // cout << '\n';
    // for(int i = 0; i < n-1; i++){
    //     dp[i][i+1] = 2;
    //     if(arr[i] == arr[i+1]){
    //         dp[i][i+1] = 1;
    //     }
    // }

    for(int sz = 1; sz < idx; sz++){
        for(int i = 0; i < idx-sz; i++){ 
            int j = i+sz;
            int from = i, to = j;
            if(arr[i] == arr[j]){
                dp[i][j] = dp[from+1][to-1]+1;
                for(int k = from+1; k <= to-1; k++){
                    if(arr[k] == arr[i]){
                        if(dp[i][j] > dp[from][k]+dp[k][to]-1){
                            dp[i][j] = dp[from][k]+dp[k][to]-1;
                        }
                    } 
                }

            } else{
                for(int k = 0; k < to-from; k++){
                    if(!dp[i][j] || dp[i][j] > dp[from][from+k] + dp[from+k+1][to]){
                        dp[i][j] = dp[from][from+k] + dp[from+k+1][to];
                    }
                }
            }
            // cout << "{" << from << ' ' << to << "} ";
            // b b b c c b 5
            // b b b c c b b b 5 * 4C1 = 20
            // dp[0][7] = 20 + dp[1][6]
            
            // cout << dp[i][j] << ' ';
        }
        // cout << '\n';
    }

    // for(int i = 0; i < idx; i++){
    //     for(int j = 0; j < idx; j++){
    //         cout << dp[i][j] << ' ';
    //     }
    //     cout << '\n';
    // }

    cout << dp[0][idx-1] << '\n';

    return 0;   
}