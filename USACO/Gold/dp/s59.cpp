#include <iostream>
#include <string>
using namespace std;

long long dp[500][500];
long long comb[501][501];

int main(){
    string str;
    cin >> str;
    int n = str.length();

    for(int i = 0; i < n-1; i++){
        dp[i][i+1] = 0;
        if(str[i] == str[i+1]) dp[i][i+1] = 1;
    }

    comb[0][0] = 1;
    for(int i = 1; i <= 500; i++){
        for(int j = 0; j <= i; j++){
            if(j == 0 || j == i){
                comb[i][j] = 1;
            } else{
                comb[i][j] = (comb[i-1][j-1]+comb[i-1][j])%1000000007;
            }
            // cout << comb[i][j] << ' ';
        }
        // cout << '\n';
    }
    for(int sz = 3; sz < n; sz+=2){
        for(int i = 0; i < n-sz; i++){
            for(int j = 1; j <= sz; j+= 2){
                // cout << sz << ' ' << i << ' ' << j << '\n';
                if(str[i] == str[i+j]){
                    int from = i+1, to = i+j-1;
                    long long r1, r2, c, temp;
                    // cout << from << ' ' << to << '\n';
                    if(from > to){
                        r1 = 1;
                    } else{
                        r1 = dp[from][to]%1000000007;
                    }

                    r2 = dp[i+j+1][i+sz]%1000000007;
                    if(i+j+1 > i+sz){
                        r2 = 1;
                    }
                    // cout << (sz+1)/2 << ' ' << (j+1)/2 << '\n';
                    c = comb[(sz+1)/2][(j+1)/2]%1000000007;
                    // cout << "stats: " << r1 << ' ' << r2 << ' ' << c << '\n';
                    temp = (r1*r2)%1000000007*c%1000000007;
                    // cout << temp << '\n';
                    dp[i][i+sz] += temp;
                    dp[i][i+sz] %= 1000000007;
                }
                // if(str[i+j+1]==str[i+sz]){
                //     long long c = comb[(sz+1)/2][(sz-j)/2];
                //     long long temp = ( dp[i+1][i+sz-1]+dp[i][i+j]* c)%1000000007;
                //     if(dp[i][i+sz] < temp) dp[i][i+sz] = temp%1000000007;
                //     // cout << sz+1 << ' ' << i << ' ' << j << ' ' << temp << '\n';
                //     // cout << "add: " <<  dp[i+1][i+sz-1] << " mult: " << dp[i][i+j] << " c: " << c<<'\n';
                //      // cout <<  << '\n';
                // } 
                // if(str[i] == str[i+sz]){

                // } 
                // long long c = (fact[(sz+1)/2]/(fact[(sz-j)/2] *fact[(j+1)/2])) % 1000000007;

            }
        }
    }
    // for(int i = 0; i < n; i++){
    //     for(int j = 0; j < n; j++){
    //         cout << dp[i][j] << ' ';
    //     }
    //     cout << '\n';
    // }
    cout << dp[0][n-1]%1000000007 << '\n';


    return 0;
}