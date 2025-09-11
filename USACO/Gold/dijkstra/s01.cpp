#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int main(){
    int v, e, k;
    cin >> v >> e >> k;
    vector<pair<int, int>> adj[20001];

    int a, b, w;
    for(int i = 0; i < e; i++){
        cin >> a >> b >> w;
        adj[a].push_back({w, b});       
        // adj[b].push_back({w, a});     
    }

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    int mins[20001], visit[20001] = {};
    for(int i = 1; i <= v; i++){
        mins[i] = 1000000000;
    }
    pq.push({0, k});
    mins[k] = 0;
    
    while(!pq.empty()){
        int w = pq.top().first, cur = pq.top().second;
        pq.pop();
        if(visit[cur]){
            continue;
        }
        visit[cur] = 1;

        for(int i = 0; i < adj[cur].size(); i++){
            if(!visit[adj[cur][i].second]){
                if(mins[adj[cur][i].second] > adj[cur][i].first+w){
                    mins[adj[cur][i].second] = adj[cur][i].first+w;
                    pq.push({adj[cur][i].first+w, adj[cur][i].second});
                }
            }
        }

    }
    for(int i = 1; i <= v; i++){
        if(mins[i] == 1000000000){
            cout << "INF\n";
        } else{
            cout << mins[i] << '\n';
        }
    }
    return 0;
}