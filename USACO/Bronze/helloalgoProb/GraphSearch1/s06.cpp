#include <iostream>
#include <vector>
using namespace std;

int n, m;
vector<int> adj[1001];
// int visit[1001];
int visited[1111], vdx = 0;
int cnt = 0;
void dfs(int cur){
    // visit[cur] = 1;
    // visited[vdx++] = cur;
    for(int idx = 0; idx < adj[cur].size(); idx++){
        cnt++;
        // for(int jdx = 0; jdx < vdx; jdx++){

        // }
    }
}

int main(){
    cin >> n >> m;
    int from, to;
    for(int idx = 0; idx < m; idx++){
        cin >> from >> to;
        adj[from].push_back(to);
    }
    return 0;
}