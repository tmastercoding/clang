#include <iostream>
#include <vector>
using namespace std;

int n;
vector<int> adj[100];
int visit[100];

void dfs(int cur){
    visit[cur] = 1;
    cout << cur+1 << '\n';
    for(int idx = 0; idx < adj[cur].size(); idx++){
        if(visit[adj[cur][idx]] == 0){
            dfs(adj[cur][idx]);
        }
    }
}

int main(){
    cin >> n;

    for(int idx = 0; idx < n; idx++){
        for(int jdx = 0; jdx < n; jdx++){
            int temp;
            cin >> temp;
            if(temp){
                adj[idx].push_back(jdx);
            }
        }
    }

    dfs(0);
    return 0;
}