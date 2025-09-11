#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main(){
    int n, m, d, e;
    cin >> n >> m >> d >> e;
    int heights[100001], visit[100001] = {};
    long long minsHome[100001], minsSchool[100001];
    for(int i = 1; i <= n; i++){
        cin >> heights[i];
        minsHome[i] = 10000000000000;
        minsSchool[i] = 10000000000000;
    }

    vector<pair<int, int>> adj[100001];
    int a, b, c;
    for(int i = 0; i < m; i++){
        cin >> a >> b >> c;
        adj[a].push_back({c, b});
        adj[b].push_back({c, a});
    }

    priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq;
    pq.push({0, 1});
    while(!pq.empty()){
        long long w = pq.top().first;
        int cur = pq.top().second;
        pq.pop();
        if(visit[cur]) continue;
        visit[cur] = 1;

        for(int i = 0; i < adj[cur].size(); i++){
            if(!visit[adj[cur][i].second] && heights[cur] < heights[adj[cur][i].second]){
                if(minsHome[adj[cur][i].second] > adj[cur][i].first+w){
                    minsHome[adj[cur][i].second] = adj[cur][i].first+w;
                    pq.push({adj[cur][i].first+w, adj[cur][i].second});
                }
            }
        }
    }
    
    for(int i = 1; i <= n; i++){
        visit[i] = 0;
    }
    pq.push({0, n});
    while(!pq.empty()){
        long long w = pq.top().first;
        int cur = pq.top().second;
        pq.pop();
        if(visit[cur]) continue;
        visit[cur] = 1;

        for(int i = 0; i < adj[cur].size(); i++){
            if(!visit[adj[cur][i].second] && heights[cur] < heights[adj[cur][i].second]){
                if(minsSchool[adj[cur][i].second] > adj[cur][i].first+w){
                    minsSchool[adj[cur][i].second] = adj[cur][i].first+w;
                    pq.push({adj[cur][i].first+w, adj[cur][i].second});
                }
            }
        }
    }

    long long max = -10000000000000;
    for(int i = 2; i < n; i++){
        if(minsHome[i] != 10000000000000 && minsSchool[i] != 10000000000000){
            long long temp = 0;
            temp += heights[i]*e;
            temp -= minsHome[i]*d;
            temp -= minsSchool[i]*d;

            if(temp > max) max = temp;
        }
    }

    if(max == -10000000000000){
        cout << "Impossible\n";
    } else{
        cout << max << '\n';
    }
    return 0;
}