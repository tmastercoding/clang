#include <iostream>
#include <vector>
using namespace std;

int n;
vector<int> adj[100001];
int visit[100001] = {}, parent[100001] = {};

void dfs(int cur){
    visit[cur] = 1;
    for(int i = 0; i < adj[cur].size(); i++){
        if(!visit[adj[cur][i]]){
            parent[adj[cur][i]] = cur;
            dfs(adj[cur][i]);
        }
    }
}

int main(){
    cin >> n;
    int pre, post;
    for(int i = 0; i < n-1; i++){
        cin >> pre >> post;
        adj[pre].push_back(post);
        adj[post].push_back(pre);
    }
    dfs(1);
    for(int i = 2; i <= n; i++){
        cout << parent[i] << '\n';
    }
    return 0;
}