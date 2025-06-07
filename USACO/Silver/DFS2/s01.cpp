// 이분 그래프 1707
#include <iostream>
#include <vector>
using namespace std;

int v, e;
vector<int> adj[20002];
int visit[20002] = {};
int type[20002] = {};
bool flag = true;

void dfs(int cur){
    visit[cur] = 1;
    for(int i = 0; i < adj[cur].size(); i++){
        if(type[cur] == type[adj[cur][i]]) flag = false;
        if(!visit[adj[cur][i]]){
            if(type[cur] == 1){
                type[adj[cur][i]] = 2;
            } else{
                type[adj[cur][i]] = 1;
            }
            dfs(adj[cur][i]);
        }
    }
}

int main(){
    int k;
    cin >> k;
    for(int c = 0; c < k; c++){
        cin >> v >> e;
        int v1, v2;
        for(int i = 0; i < e; i++){
            cin >> v1 >> v2;
            adj[v1].push_back(v2);
            adj[v2].push_back(v1);
        }
        
        flag = true;
        for(int i = 1; i <= v; i++){
            if(!visit[i]){
                type[i] = 2;
                dfs(i);
            }
        }
    
        if(flag){
            cout << "YES\n";
        } else{
            cout << "NO\n";
        }
    
        for(int i = 0; i <= v; i++){
            visit[i] = 0;
            type[i] = 0;
            adj[i].clear();
        }

    }
    return 0;
}
