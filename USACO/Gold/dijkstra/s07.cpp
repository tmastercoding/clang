#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main(){
    int n, m;
    cin >> n >> m;
    int a, b, c;
    vector<pair<int, int>> adj[50001];
    int visit[50001] = {}, mins[50001];
    for(int i = 0; i < m; i++){
        cin >> a >> b >> c;
        adj[a].push_back({c, b});
        adj[b].push_back({c, a});
    }

    for(int i = 1; i <= n; i++){
        mins[i] = 1000000000;
    }

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, 1});

    while(!pq.empty()){
        int w = pq.top().first, cur = pq.top().second;
        pq.pop();
        if(visit[cur]) continue;
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

    cout << mins[n] << '\n';

    return 0;
}