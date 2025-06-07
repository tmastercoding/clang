// Wormhole Sort 18321
#include <iostream>
#include <vector>
using namespace std;

vector<pair<int, long long>> adj[100000];
int visit[100000] = {};
int arr[100000] = {};

void dfs(int cur, long long minw, int changeTo){
    visit[cur] = changeTo;
    for(int i = 0; i < adj[cur].size(); i++){
        if(visit[adj[cur][i].first] < changeTo && adj[cur][i].second >= minw){
            dfs(adj[cur][i].first, minw, changeTo);
        }
    }
}

int main(){
    int n, m;
    int a, b;
    long long w;
    cin >> n >> m;
    
    bool aldSort = true;
    for(int i = 0; i < n; i++){
        cin >> arr[i];
        if(i != --arr[i]) aldSort = false;
    }
    for(int i = 0; i < m; i++){
        cin >> a >> b >> w;
        a--, b--;
        adj[a].push_back({b, w});
        adj[b].push_back({a, w});
    }

    if(aldSort){
        cout << -1 << '\n';
    } else{
        long long lo = 1, hi = 1000000000, mid;
        while(lo < hi){
            mid = (lo+hi+1)/2;
            for(int i = 0; i < n; i++){
                visit[i] = -1;
            }
            for(int i = 0; i < n; i++){
                if(visit[i] == -1){
                    dfs(i, mid, i);
                }
                
                // cout << mid << ' ' << found<< '\n';
            }
            bool found = true;
            for(int i = 0; i < n; i++){
                if(visit[arr[i]] != visit[i]){
                    found = false;
                    break;
                }
            }
            if(found){
                lo = mid;
            } else{
                hi = mid-1;
            }
        }
        cout << lo << '\n';
    }

    return 0;  
}