#include <iostream>
#include <vector>
using namespace std;

int n, m;
int dp[100001], visit[100001];
vector<int> adj[100001];

void dfs(int cur){
    visit[cur] = 1;
    // cout << cur << '\n';
    for(int i = 0; i < adj[cur].size(); i++){
        if( !visit[adj[cur][i]]){
            dfs(adj[cur][i]);
            if(dp[cur] < dp[adj[cur][i]]+1) dp[cur] = dp[adj[cur][i]]+1;
        } else{
            if(dp[cur] < dp[adj[cur][i]]+1) dp[cur] = dp[adj[cur][i]]+1;
        }
    }
}

int main(){
    cin >> n >> m;
    int from, to;
    for(int i = 0; i < m; i++){
        cin >> from >> to;
        adj[from].push_back(to);
    }
    for(int i = 1; i <= n; i++) dp[i] = 0;
    for(int i = 1; i <= n; i++){
        if(!visit[i]) dfs(i);
    }

    int max = 0;
    for(int i = 1; i <= n; i++){
        // cout << dp[i] << ' ';
        if(max < dp[i]) max = dp[i];
    }
    // cout << '\n';

    cout << max << '\n';
    return 0;
}