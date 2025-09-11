#include <iostream>
#include <string>
using namespace std;

long long dp[2500][2500];
int flag[2500][2500];

int main(){
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    string str;
    cin >> str;
    int n = str.length();

    for(int sz = 0; sz < n; sz++){
        for(int i = 0; i < n-sz; i++){
            if(!sz){
                flag[i][i+sz] = 1; 
                continue;
            }
            if(i+1 > i+sz-1){
                if(str[i] == str[i+sz]) flag[i][i+sz] = 1;
            } else{
                if(flag[i+1][i+sz-1]){
                    if(str[i] == str[i+sz]) flag[i][i+sz] = 1;
                }
            }
            // cout << flag[i][i+sz] << ' ';
        }
        // cout << '\n';
    }

    for(int sz = 0; sz < n; sz++){
        if(flag[0][sz] || !sz){
            dp[0][sz] = 1;
        }  else{
            for(int j = 0; j < sz; j++){
                // cout << sz << ' ' << j << '\n';
                int comp = dp[0][j];
                if(flag[j+1][sz]){
                    comp += 1;
                } else{
                    comp += sz-j;
                }
                if(!dp[0][sz] || dp[0][sz] > comp){
                    dp[0][sz] = comp;
                }
            }
        }
    }
    
    cout << dp[0][n-1] << '\n';
    return 0;
}