#include <iostream>
#include <vector>
using namespace std;

int n, m, c;
int dp[1001][1010]; // where, time
int earn[1001];
// int visit[1001][1001];
vector<int> adj[1001];

void dfs(int cur, int t){
    // visit[cur][t] = 1;  
    // cout << cur << ' ' << t << '\n';
    
    for(int i = 0; i < adj[cur].size(); i++){
        long long temp = dp[cur][t]+c*t*t+earn[adj[cur][i]]-c*(t+1)*(t+1);
        if(temp > dp[adj[cur][i]][t+1]){
            dp[adj[cur][i]][t+1] = temp;
            dfs(adj[cur][i], t+1);
        }
    }
}

int main(){
    freopen("time.in", "r", stdin);
    freopen("time.out", "w", stdout);

    cin >> n >> m >> c;
    for(int i = 1; i <= n; i++) cin >> earn[i];
    int from, to;
    for(int i = 0; i < m; i++){
        cin >> from >> to;
        adj[from].push_back(to);
    }

    dfs(1, 0);

    int maxc = 0;
    for(int t = 1; t <= 1001; t++){
        if(maxc < dp[1][t]){
            maxc = dp[1][t];
            // cout << maxc << '\n';
        }
    }
    cout << maxc << '\n';
    return 0;
}