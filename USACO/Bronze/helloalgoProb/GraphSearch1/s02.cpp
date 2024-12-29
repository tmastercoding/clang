#include <iostream>
#include <vector>
using namespace std;

int n, m;
vector<int> adj[100001];
int visit[100001];

void dfs(int cur){
    cout << cur << '\n';
    visit[cur] = 1;
    for(int idx = 0; idx < adj[cur].size(); idx++){
        if(visit[adj[cur][idx]] == 0){
            dfs(adj[cur][idx]);
        }
    }
}

int main(){
    cin >> n >> m;
    int from, to;
    for(int idx = 0; idx < m; idx++){
        cin >> from >> to;
        adj[from].push_back(to);
    }


    dfs(1);
    return 0;
}