#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main(){
    int a, b, n;
    cin >> a >> b >> n;

    vector<vector<long long>> adj[1001];
    for(int i = 0; i < n; i++){
        long long cost;
        int m;
        cin >> cost >> m;
        int cities[100];
        for(int j = 0; j < m; j++){
            cin >> cities[j];
        }
        for(int j = 0; j < m; j++){
            for(int k = j+1; k < m; k++){
                adj[cities[j]].push_back({cost, cities[k], k-j});
            }
        }
    }

    int visit[1001] = {};
    long long mins[1001][2];
    for(int i = 0; i < 1001; i++){
        mins[i][0] = 1000000000000000;
        mins[i][1] = 0;
    }
    priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq;
    pq.push({0, a});
    while(!pq.empty()){
        long long w = pq.top().first;
        int cur = pq.top().second;
        pq.pop();
        if(visit[cur]) continue;
        visit[cur] = 1;

        for(int i = 0; i < adj[cur].size(); i++){
            if(!visit[adj[cur][i][1]]){
                if(mins[adj[cur][i][1]][0] > adj[cur][i][0]+w){
                    mins[adj[cur][i][1]][0] = adj[cur][i][0]+w;
                    mins[adj[cur][i][1]][1] = mins[cur][1]+adj[cur][i][2];
                    pq.push({w+adj[cur][i][0], adj[cur][i][1]});
                }
            }
        }
    }
    if(mins[b][0] == 1000000000000000){
        cout << "-1 -1\n";
    } else{
        cout << mins[b][0] << ' ' << mins[b][1] << '\n';
    }
    return 0;
}