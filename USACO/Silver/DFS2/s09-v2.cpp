#include <iostream>
using namespace std;

int n, m;
int adj[100001] = {};
int praise[100001] = {}, level;

void dfs(int cur){
    praise[cur] += level;
    if(adj[cur] != 0) dfs(adj[cur]);
}

int main(){
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    cin >> n >> m;
    int boss;
    for(int i = 1; i <= n; i++){
        cin >> boss;
        if(boss > 0){
            adj[boss] = i;
        }
    }
    
    int r;
    for(int i = 0; i < m; i++){
        cin >> r >> level;
        dfs(r);
    }
    
    for(int i = 1; i <= n; i++){
        cout << praise[i] << ' ';
    }
    cout << '\n';

    return 0;
}