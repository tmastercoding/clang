// Moocast 14167
#include <iostream>
#include <vector>
using namespace std;

int n, x, y;
pair<int, int> cows[1000];
vector<pair<int, long long>> adj[1000];
int visit[1000] = {};

void dfs(int cur, long long lim){
    visit[cur] = 1;
    for(int i = 0; i < adj[cur].size(); i++){
        pair<int, long long> nxt = adj[cur][i];
        if(!visit[nxt.first] && nxt.second <= lim) dfs(nxt.first, lim);
    }
}

int main(){
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> x >> y;
        cows[i] = {x, y};
    }

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(i == j) continue;
            adj[i].push_back({j, (cows[i].first-cows[j].first)*(cows[i].first-cows[j].first) + (cows[i].second - cows[j].second)*(cows[i].second - cows[j].second)});
        }
    }

    int lo = 0, hi = 2000000000, mid;
    while(lo < hi){
        mid = (lo+hi+1)/2;
        for(int i = 0; i < n; i++){
            visit[i] = 0;
        }
        dfs(0, mid);
        bool flag = true;
        for(int i = 0; i < n; i++){
            if(!visit[i]){
                flag = false;
                break;
            }
        }
        // cout << mid << '\n';
        if(flag){
            hi = mid-1;
        } else{
            lo = mid;
        }
    }
    cout << lo+1 << '\n';
    return 0;
}