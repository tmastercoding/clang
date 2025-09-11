#include <iostream>
#include <vector>
#include <queue>
using namespace std;

pair<long long, int> adj[1001][1001];
priority_queue<vector<long long>, vector<vector<long long>>, greater<vector<long long>>> pq;

int main(){
	// freopen("cowroute.in", "r", stdin);
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
                if(!adj[cities[j]][cities[k]].first && !adj[cities[j]][cities[k]].second) adj[cities[j]][cities[k]] = {cost, k-j};
                if(adj[cities[j]][cities[k]] > make_pair(cost,k-j)){
                    adj[cities[j]][cities[k]] = {cost, k-j};
                }
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

        for(int i = 1; i <= 1000; i++){
            if(!visit[i] && adj[cur][i].first > 0){
                if(mins[i][0] > adj[cur][i].first+w){
                    mins[i][0] = adj[cur][i].first+w;
                    mins[i][1] = f+adj[cur][i].second;
                    pq.push({adj[cur][i].first+w, f+adj[cur][i].second, i});
                } else if(mins[i][0] == adj[cur][i].first+w){
                    if(f+adj[cur][i].second < mins[i][1]){
                        mins[i][1] = f+adj[cur][i].second;
                    }
                    pq.push({adj[cur][i].first+w, f+adj[cur][i].second, i});
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