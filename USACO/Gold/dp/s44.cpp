#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int dp[4000][3][3];
int main(){
    int n;
    int left[2000], right[2000];
    
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> left[i];
    }
    for(int i = 0; i < n; i++){
        cin >> right[i];
    }

    dp[0][0][0] = 0;
    dp[0][0][1] = -1;
    if(n > 1) dp[0][0][1] = 1;
    dp[0][0][2] = 0;
    
    dp[0][1][0] = 0;
    dp[0][1][1] = -1;
    dp[0][1][2] = -1;
    if(n > 1) dp[0][1][1] = 1;
    if(n > 1) dp[0][1][2] = 1;
    
    if(left[0] > right[0]){
        dp[0][2][0] = right[0];
        dp[0][2][1] = 0;
        dp[0][2][2] = -1;
        if(n > 1) dp[0][2][2] = 1;
    } else{
        dp[0][2][0] = -1;
    }

    int i = 1;
    vector<vector<int>> temp;
    while(i){
        bool op1, op2, op3;
        op1 = (dp[i-1][0][0] == -1 || dp[i-1][0][1] == -1 || dp[i-1][0][2] == -1);
        op2 = (dp[i-1][1][0] == -1 || dp[i-1][1][1] == -1 || dp[i-1][1][2] == -1);
        op3 = (dp[i-1][2][0] == -1 || dp[i-1][2][1] == -1 || dp[i-1][2][2] == -1);
        if(op1 && op2 && op3) break;
        temp.clear();
        if(!op1){
            temp.push_back({dp[i-1][0][0], dp[i-1][0][1], dp[i-1][0][2]});
        }
        if(!op2){
            temp.push_back({dp[i-1][1][0], dp[i-1][1][1], dp[i-1][1][2]});
        }
        if(!op3){
            temp.push_back({dp[i-1][2][0], dp[i-1][2][1], dp[i-1][2][2]});
        }

        sort(temp.rbegin(), temp.rend());
        
        dp[i][0][0] = temp[0][0];
        dp[i][0][1] = -1;
        if(temp[0][1] < n-1) dp[i][0][1] = temp[0][1]+1;
        dp[i][0][2] = temp[0][2];

        dp[i][1][0] = temp[0][0];
        dp[i][1][1] = -1;
        dp[i][1][2] = -1;
        if(temp[0][1] < n-1) dp[i][1][1] = temp[0][1]+1;
        if(temp[0][2] < n-1) dp[i][1][2] = temp[0][2]+1;

        dp[i][2][0] = -1;
        dp[i][2][1] = -1;
        dp[i][2][2] = -1;
        for(int j = 0; j < temp.size(); j++){
            if(left[temp[j][1]] > right[temp[j][2]]){
                dp[i][2][0] = temp[j][0]+right[temp[j][2]];
                dp[i][2][1] = temp[j][1];
                if(temp[j][2] < n-1) dp[i][2][2] = temp[j][2]+1;
                break;
            }
        }
        i++;
    }

    for(int idx = 0; idx < i; idx++){
        for(int j = 0; j < 3; j++){
            int l = -1, r = -1;
            if(dp[idx][j][1] != -1)  l = left[dp[idx][j][1]];
            if(dp[idx][j][2] != -1)  r = right[dp[idx][j][2]];
            cout << dp[idx][j][0] << ' ' << l << ' ' << r << " : ";
        }
        cout << '\n';
    }
    return 0;
}