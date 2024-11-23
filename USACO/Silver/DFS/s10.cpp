// 키 순서 2458
#include <iostream>
#include <vector>
using namespace std;

int n, m, visit[501], lower[501], higher[501];
vector<int> adj[501];
int hCnt = 0;

void dfs(int cur){
    visit[cur] = 1;
    lower[cur]++;
    hCnt++;

    for(int idx = 0; idx < adj[cur].size(); idx++){
        if(visit[adj[cur][idx]] == 0){
            dfs(adj[cur][idx]);
        }
    }

}

int main(){
    cin >> n >> m;
    int h1, h2;
    for(int idx = 0; idx < m; idx++){
        cin >> h1 >> h2;
        adj[h1].push_back(h2);
    }
    
    for(int idx = 1; idx < n+1; idx++){
        for(int idx = 1; idx < n+1; idx++){
            visit[idx] = 0;
        }
        dfs(idx);
        higher[idx] = hCnt;
        hCnt = 0;
    }

    int pre, post, cnt = 0;
    for(int idx = 1; idx < n+1; idx++){
        pre = lower[idx];
        post = higher[idx];
        if(pre+post-1 == n){
            cnt++;
        }
    }
    cout << cnt << '\n';
    return 0;
}