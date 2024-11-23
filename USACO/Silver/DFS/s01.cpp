// 바이러스 2606
#include <iostream>
#include <vector>
using namespace std;

int csize, psize;
vector<int> adj[101];
int visit[101];
int cnt = 0;

void dfs(int cur){
    visit[cur] = 1;
    cnt++;
    for(int idx = 0; idx < adj[cur].size(); idx++){
        int nxt = adj[cur][idx];
        if(visit[nxt] == 0){
            dfs(nxt);
        }
    }

}


int main(){
    cin >> csize >> psize;
    
    int c1, c2;
    for(int idx = 0; idx < psize; idx++){
        cin >> c1 >> c2;
        adj[c1].push_back(c2);
        adj[c2].push_back(c1);
    }

    dfs(1);
    cout << cnt-1 << '\n';
    return 0;
}