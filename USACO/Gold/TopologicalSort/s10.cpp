#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int main(){
    int t;
    cin >> t;
    for(int c = 0; c < t; c++){

        int n, m;
        int adj[501][501];
        int og[501], in[501] = {};
        cin >> n;
        for(int i = 0; i < n; i++){
            cin >> og[i];
        }
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= n; j++){
                adj[i][j] = 0;
            }
        }
    
        for(int i = 0; i < n; i++){
            for(int j = i+1; j < n; j++){
                adj[og[i]][og[j]] = 1;
            }
        }
        cin >> m;
        int a, b;
        for(int i = 0; i < m; i++){
            cin >> a >> b;
            if(adj[a][b]){
                adj[a][b] = 0;
                adj[b][a] = 1;
            } else{
                adj[a][b] = 1;
                adj[b][a] = 0;
            }
        }
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= n; j++){
                if(adj[i][j]){
                    in[j]++;
                }
            }
        }
    
        queue<int> q;
        for(int i = 1; i <= n; i++){
            if(!in[i]) q.push(i);
        }
        vector<int> out;
        while(!q.empty()){
            int cur = q.front();
            out.push_back(cur);
            q.pop();
            for(int j = 1; j <= n; j++){
                if(adj[cur][j]){
                    in[j]--;
                    if(!in[j]) q.push(j);
                }
            }
        }
        bool flag = false;
        for(int i = 1; i <= n; i++){
            if(in[i]) flag = true;
        }
    
        if(flag){
            cout << "IMPOSSIBLE\n";
        } else{
            for(int i = 0; i < out.size(); i++){
                cout << out[i] << ' ';
            }
            cout << '\n';
        }
    }
    return 0;
}