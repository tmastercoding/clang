#include <iostream>
using namespace std;

int n;
int adj[200001], visit[200001] = {}, cycle[200001] = {};
int cnt = 0, visitTo = 0, ccnt = 0;
void dfs(int cur){
    visit[cur] = visitTo;
    if(visit[adj[cur]] != visitTo){
        if(cycle[adj[cur]]){
            cnt += cycle[adj[cur]];
        } else{
            cnt++;
            dfs(adj[cur]);
        }
    } else{
        visit[adj[cur]] = visitTo+1;
        ccnt++;
        dfs(adj[cur]);
    }
}

int main(){
    cin >> n;
    int v;
    for(int i = 1; i <= n; i++){
        cin >> v;
        adj[i] = v;
    }
    
    for(int i = 1; i <= n; i++){
        visitTo++;
        cnt = 1;
        dfs(i);
        cout << cnt << ' ';
    }
    cout << '\n';

    return 0;
}