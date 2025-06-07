#include <iostream>
#include <vector>
using namespace std;
int n, r, q;
vector<int> adj[100001];
int visit[100001] = {0,}, child[100001] = {};

void dfs(int cur){
    visit[cur] = 1;
    child[cur] = 1;
    for(int i = 0; i < adj[cur].size(); i++){
        if(!visit[adj[cur][i]]){
            dfs(adj[cur][i]);
            child[cur] += child[adj[cur][i]];
        }
    }
}

int main(){
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    cin >> n >> r >> q;
    int pre, post;
    for(int i = 0; i < n-1; i++){
        cin >> pre >> post;
        adj[pre].push_back(post);
        adj[post].push_back(pre);
    }

    dfs(r);
    for(int i = 0; i < q; i++){
        cin >> pre;
        cout << child[pre] << '\n';
    }
    return 0;
}