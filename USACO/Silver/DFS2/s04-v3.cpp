#include <iostream>
#include <vector>
using namespace std;

int n;
int adj[200001], visit[200001] = {}, output[200001] = {};
vector<int> path;
int visitTo = 0;

void dfs(int cur){
    visit[cur] = visitTo;
    if(!visit[adj[cur]]){
        path.push_back(adj[cur]);
        dfs(adj[cur]);
    } else if (visit[adj[cur]] == visitTo){
        int loopsize = 0, i, loc;
        for(i = path.size()-1; i > -1; i--){
            loopsize++;
            if(path[i] == adj[cur]) break;
        }
        if(i < 0) i = 0;
        loc = i;
        for(; i < path.size(); i++){
            output[path[i]] = loopsize;
        }
        for(i = loc-1; i > -1; i--){
            output[path[i]] = ++loopsize;
        }
    } else if(visit[adj[cur]] < visitTo){
        int j = 1;
        for(int i = path.size()-1; i > -1; i--){
            output[path[i]] = output[adj[cur]]+j++;
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
            visitTo++;
            path.clear();
            path.push_back(i);
            dfs(i);
        }
    }
    for(int i = 1; i <= n; i++) cout << output[i] << ' ';
    cout << '\n';


    return 0;
}