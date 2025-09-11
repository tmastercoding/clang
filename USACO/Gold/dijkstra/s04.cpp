#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int main(){
    int n, m;
    cin >> n >> m;

    vector<pair<int, int>> adj[1001];
    for(int i = 0; i < m; i++){
        int a, b, c;
        cin >> a >> b >> c;
        adj[a].push_back({c, b});
        // adj[b].push_back({c, a});
    }  

    int visit[1001] = {}; 
    long long mins[1001];
    for(int i = 1; i<=n; i++){
        mins[i] = 100000000000;
    }

    priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq;
    int a, b;
    cin >> a >> b;
    pq.push({0, a});
    while(!pq.empty()){
        long long w = pq.top().first;
        int cur = pq.top().second;
        pq.pop();
        if(visit[cur]) continue;
        visit[cur] = 1;

        for(int i = 0; i < adj[cur].size(); i++){
            if(!visit[adj[cur][i].second]){
                if(mins[adj[cur][i].second] > adj[cur][i].first+w){
                    mins[adj[cur][i].second] = adj[cur][i].first+w;
                    pq.push({adj[cur][i].first+w, adj[cur][i].second});
                    // cout << adj[cur][i].first+w << ' '<< adj[cur][i].second << ' ' << cur << '\n';
                }
            }
        }
    }

    cout << mins[b] << '\n';
    return 0;
}