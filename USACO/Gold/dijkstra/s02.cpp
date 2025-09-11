#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int main(){
    int n, m;
    cin >> n >> m;
    vector<pair<int, int>> adj[1001];
    int a, b, c;
    for(int i = 0; i < m; i++){
        cin >> a >> b >> c;
        adj[a].push_back({c, b});
        adj[b].push_back({c, a});
    }

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    int visit[1001] = {}, mins[1001][3];
    for(int i = 1; i<=n; i++){
        mins[i][0] = 1000000000;
        mins[i][1] = -1;
        mins[i][2] = -1;
    }

    pq.push({0, 1});
    while(!pq.empty()){
        int w = pq.top().first, cur = pq.top().second;
        pq.pop();
        if(visit[cur]) continue;
        visit[cur] = 1;

        for(int i = 0; i < adj[cur].size(); i++){
            if(!visit[adj[cur][i].second]){
                if(mins[adj[cur][i].second][0] > adj[cur][i].first+w){
                    mins[adj[cur][i].second][0] = adj[cur][i].first+w;
                    mins[adj[cur][i].second][1] = cur;
                    mins[adj[cur][i].second][2] = adj[cur][i].second;
                    pq.push({adj[cur][i].first+w, adj[cur][i].second});
                }
            }
        }
    }

    cout << n-1 << '\n';
    for(int i = 2; i <= n; i++){
        cout << mins[i][1] << ' ' << mins[i][2] << '\n';
    }

    return 0;
}