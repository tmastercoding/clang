#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int main(){
    int n, m;
    cin >> n >> m;
    int in[101] = {}, bneed[101][101], need[101][101];
    vector<int> adj[101];

    int x, y, k;
    for(int i = 0; i < m; i++){
        cin >> x >> y >> k;
        in[x]++;
        adj[y].push_back(x);
        need[x][y] = k;
    }
    queue<int> q;
    for(int i = 1; i <= n; i++){
        if(!in[i]){
            q.push(i);
            bneed[i][i] = 1;
        }  
    }

    while(!q.empty()){
        int cur = q.front();
        // cout << cur << '\n';
        q.pop();
        for(int nxt: adj[cur]){
            for(int i = 1; i <= n; i++){
                bneed[nxt][i] += bneed[cur][i]*need[nxt][cur];
                // cout << bneed[nxt][i] << ' ';
            }
            // cout << '\n';
            in[nxt]--;
            if(!in[nxt]) q.push(nxt);
        }
    }
    for(int i = 1; i <= n; i++){
        if(bneed[n][i]){ 
            cout << i << ' ' << bneed[n][i] << '\n';
        }
    }
    
    return 0;
}