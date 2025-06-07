#include <iostream>
#include <vector>
using namespace std;

int n, m;
vector<int> adj[100001];
int praise[100001] = {}, level;

void dfs(int cur, int prev){
    praise[cur] += prev;
    for(int i = 0; i < adj[cur].size(); i++){
        if(adj[cur][i] >0) dfs(adj[cur][i], praise[cur]);
    }
}

int main(){
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    cin >> n >> m;
    int boss, root;
    for(int i = 1; i <= n; i++){
        cin >> boss;
        if(boss > 0){
            adj[boss].push_back(i);
        } else{
            root = i;
        }
    }
    
    int r;
    for(int i = 0; i < m; i++){
        cin >> r >> level;
        praise[r] += level;
    }
    dfs(root, 0);
    
    for(int i = 1; i <= n; i++){
        cout << praise[i];
        if(i != n){
            cout << ' ';
        } else{
            cout << '\n';
        }
    }

    return 0;
}