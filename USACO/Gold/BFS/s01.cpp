#include <iostream>
#include <set>
#include <queue>
#include <vector>
using namespace std;

int n, m, start;
set<int> adj[1001];
int dv[1001] = {}, bv[1001] = {};
vector<int> dfsout, bfsout;

void dfs(int x){
    dfsout.push_back(x);
    dv[x] = 1;
    for(auto i: adj[x]){
        if(dv[i] == 0) dfs(i);
    }
}

int main(){
    cin >> n >> m >> start;
    for(int i = 0; i < m; i++){
        int a, b;
        cin >> a >> b;
        adj[a].insert(b);
        adj[b].insert(a);
    }

    dfs(start);
    queue<int> q;
    q.push(start);
    bv[start] = 1;
    bfsout.push_back(start);

    while(!q.empty()){
        int cur = q.front();
        q.pop();
        for(int i: adj[cur]){
            if(!bv[i]){
                bv[i] = 1;
                q.push(i);
                bfsout.push_back(i);
            }
        }
    }
    for(auto i: dfsout){
        cout << i << ' ';
    }
    cout << '\n';
    for(auto i: bfsout){
        cout << i << ' ';
    }
    cout << '\n';

    return 0;
}