#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int main(){
    // prim
    int n, m;
    cin >> n >> m;
    vector<pair<int, int>> adj[100001];
    int a, b, c;
    for(int i = 0; i < m; i++){
        cin >> a >> b >> c;
        adj[a].push_back({c, b});
        adj[b].push_back({c, a});
    }

    int visit[100001] = {};
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
    q.push({0, 1});
    int cnt = 0; 
    long long sum = 0, max = 0;
    while(!q.empty()){
        if(cnt == n) break;
        int cur = q.top().second;
        if(visit[cur]){
            q.pop();
            // cnt--;
            continue;
        }
        // cout << q.top().first  << ' ' <<cur << '\n';
        sum += q.top().first;
        if(q.top().first > max){
            max = q.top().first;
        }
        visit[cur] = 1;
        cnt++;
        q.pop();

        for(int idx = 0; idx < adj[cur].size(); idx++){
            if(!visit[adj[cur][idx].second]){
                q.push(adj[cur][idx]);
            }
        }
    }
    cout << sum-max << '\n';

    return 0;
}