#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<vector<long long>> adj[1001];
priority_queue<vector<long long>, vector<vector<long long>>, greater<vector<long long>>> pq;

int main(){
	freopen("12.in", "r", stdin);
	// freopen("cowroute.out", "w", stdout);
    int a, b, n;
    cin >> a >> b >> n;

    for(int i = 0; i < n; i++){
        long long cost;
        int m;
        cin >> cost >> m;
        int cities[100];
        for(int j = 0; j < m; j++){
            cin >> cities[j];
        }
        for(int j = 0; j < m-1; j++){
            for(int k = j+1; k < m; k++){
                adj[cities[j]].push_back({cost, cities[k], k-j});
            }
        }
    }

    int visit[1001] = {};
    long long mins[1001][2];
    for(int i = 0; i < 1001; i++){
        mins[i][0] = 1000000000000000000;
        mins[i][1] = 0;
    }
    pq.push({0, 0, a});
    while(!pq.empty()){
        long long w = pq.top()[0];
        int f = (int)pq.top()[1];
        int cur = (int)pq.top()[2];
        pq.pop();
        if(visit[cur]) continue;
        visit[cur] = 1;

        for(int i = 0; i < adj[cur].size(); i++){
            if(!visit[adj[cur][i][1]]){
                if(mins[adj[cur][i][1]][0] > adj[cur][i][0]+w){
                    mins[adj[cur][i][1]][0] = adj[cur][i][0]+w;
                    mins[adj[cur][i][1]][1] = f+adj[cur][i][2];
                    pq.push({w+adj[cur][i][0], f+adj[cur][i][2], adj[cur][i][1]});
                } else if(mins[adj[cur][i][1]][0] == adj[cur][i][0]+w){
                    if(f+adj[cur][i][2] < mins[adj[cur][i][1]][1]){
                        mins[adj[cur][i][1]][1] = f+adj[cur][i][2];
                    }
                    pq.push({w+adj[cur][i][0], f+adj[cur][i][2], adj[cur][i][1]});
                }
            }
        }
    }
    if(mins[b][0] == 1000000000000000000){
        cout << "-1 -1\n";
    } else{
        cout << mins[b][0] << ' ' << mins[b][1] << '\n';
    }
    return 0;
}