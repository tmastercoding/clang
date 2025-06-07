#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main(){
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    int n, k, m;
    cin >> n >> k >> m;
    int svisit[100001] = {}, tvisit[1001] = {};
    queue<int> q;
    vector<int> adj[100001];
    vector<int> tubes[100001];
    for(int tube = 1; tube <= m; tube++){
        for(int i = 0; i < k; i++){
            int station;
            cin >> station;
            adj[station].push_back(tube);
            tubes[tube].push_back(station);
        }
    }
    q.push(1);
    svisit[1] = 1;
    
    while(!q.empty()){
        int cur = q.front();
        q.pop();
        if(cur == n) break;
        for(int tube = 0; tube < adj[cur].size(); tube++){
            if(tvisit[adj[cur][tube]]) continue;
            bool used = false;
            for(int station = 0; station < k; station++){
                if(!svisit[tubes[adj[cur][tube]][station]]){
                    used = true;
                    svisit[tubes[adj[cur][tube]][station]] = svisit[cur]+1;
                    q.push(tubes[adj[cur][tube]][station]);
                }
            }
            if(used){
                tvisit[adj[cur][tube]] = 1;
            }
        }
    }
    if(!svisit[n]){
        cout << -1 << '\n';
    } else{
        cout << svisit[n] << '\n';
    }
    return 0;
}