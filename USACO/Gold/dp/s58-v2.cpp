#include <iostream>
using namespace std;

int dp[300][300];

int main(){
    int n, arr[300];
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> arr[i];
        dp[i][i] = 1;
    }
    
    for(int i = 0; i < n-1; i++){
        dp[i][i+1] = 2;
        if(arr[i] == arr[i+1]){
            dp[i][i+1] = 1;
        }
    }

    for(int sz = 2; sz < n; sz++){
        for(int i = 0; i < n-sz; i++){ 
            int j = i+sz;
            int from = i, to = j;
            int add = 0;
            if(arr[i] == arr[j]){
                add = 1;
                int dif = 0;
                while(true){
                    if(from > to) break;
                    if(arr[i+dif] == arr[j-dif] && arr[i+dif] == arr[i]){
                        from++;
                        to--;
                    } else{
                        break;
                    }
                    dif++;
                }

                if(from > to){
                    dp[i][j] = 1;
                } else{
                    int temp = 1, st = 0;
                    for(int k = from; k <= to; k++){
                        if(arr[k] == arr[i]){
                            if(arr[k-1] != arr[i]){
                                temp += dp[st][k-1];
                            } 
                        } else{
                            if(k-1 > 0){
                                if(arr[k-1] == arr[i]){
                                    st = k;
                                }
                            } else{
                                st = k;
                            }
                        }
                    }
                    temp += dp[st][to];
                    dp[i][j] = temp;
                }
                if(!dp[i][j] || dp[i][j] > dp[from][to]+add){
                    dp[i][j] = dp[from][to]+add;
                }
            }
            // cout << "{" << from << ' ' << to << "} ";

            for(int k = 0; k < to-from; k++){
                if(!dp[i][j] || dp[i][j] > dp[from][from+k] + dp[from+k+1][to]+add){
                    dp[i][j] = dp[from][from+k] + dp[from+k+1][to]+add;
                }
            }
            // cout << dp[i][j] << ' ';
        }
        // cout << '\n';
    }

    // for(int i = 0; i < n; i++){
    //     for(int j = 0; j < n; j++){
    //         cout << dp[i][j] << ' ';
    //     }
    //     cout << '\n';
    // }

    cout << dp[0][n-1] << '\n';

    return 0;   
}