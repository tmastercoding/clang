// 텀 프로젝트 9466
#include <iostream>
using namespace std;

int n;
int adj[100002] = {};
int visit[100002] = {};
int cnt = 0, visitTo = -1;
void dfs(int cur){
    if(!visit[cur]) visit[cur] = visitTo;

    if(visit[adj[cur]] == visitTo){
        visit[adj[cur]] = visitTo+1;
        cnt++;
        dfs(adj[cur]);
    } else if(visit[adj[cur]] == 0){
        dfs(adj[cur]);
    }

}

int main(){
    int t = 0;
    cin >> t;
    for(int c = 0; c < t; c++){

        cin >> n;
        int x;
        for(int i = 1; i <= n; i++){
            cin >> x;
            adj[i] = x; 
        }
        
        int tot = 0;
        for(int i = 1; i <= n; i++){
            if(!visit[i]){
                visitTo += 2;
                cnt = 0;
                dfs(i);
                tot += cnt;
                // cout << tot << '\n';
            }
        }
        cout << n-tot << '\n';
        visitTo = -1;
        for(int i = 1; i <= n; i++){
            visit[i] = 0;
        }
    }

    return 0;
}