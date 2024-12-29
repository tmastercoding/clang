#include <iostream>
#include <vector>
using namespace std;

int n, m;
vector<int> adj[100001];
int visit[100001];
int maxCnt= 0, cnt=0;

void dfs(int cur){
    visit[cur] =1;
    if(cnt > maxCnt){
        maxCnt = cnt;
    }
    for(int idx = 0; idx < adj[cur].size(); idx++){
        if(visit[adj[cur][idx]] == 0){
            cnt++;
            dfs(adj[cur][idx]);
            cnt--;
        }
    }
}

int main(){
    int from; 
    cin >> n >> m >> from;
    int x, y;
    for(int idx = 0; idx < m; idx++){
        cin >> x >> y;
        adj[x].push_back(y);
    }

    dfs(from);
    cout << maxCnt << '\n';
    return 0;
}