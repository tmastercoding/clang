#include <iostream>
#include <vector>
using namespace std;

int n;
int adj[200001], cvisit[200001] = {}, visit[200001] = {}, cycle[200001] = {};
vector<int> temp;
int cnt = 0, visitTo = -1;
void cdfs(int cur){
    if(!cvisit[cur]) cvisit[cur] = visitTo;
    if(cvisit[adj[cur]] == visitTo){
        cvisit[adj[cur]] = visitTo+1;
        cnt++;
        temp.push_back(adj[cur]);
        cdfs(adj[cur]);
    } else if(!cvisit[adj[cur]]){
        cdfs(adj[cur]);
    }
}

void dfs(int cur){
    visit[cur] = visitTo;
    if(visit[adj[cur]] < visitTo){
        if(cycle[adj[cur]]){
            cnt += cycle[adj[cur]];
        } else{
            cnt++;
            dfs(adj[cur]);
        }
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
        if(!visit[i]){
            visitTo+=2;
            cnt = 0;
            temp.clear();
            cdfs(i);
            for(int j = 0; j < temp.size(); j++){
                cycle[temp[j]] = cnt;
            }
        }
    }
    // for(int i = 1; i <= n; i++) cout << cycle[i] << ' ';
    // cout << '\n';

    visitTo = -1;
    for(int i = 1; i <= n; i++){
        visitTo+=2;
        cnt = 0;
        if(cycle[i]){
            cnt = cycle[i];
        } else{
            cnt = 1;
            dfs(i);
        }
        cout << cnt << ' ';
    }
    cout << '\n';

    return 0;
}