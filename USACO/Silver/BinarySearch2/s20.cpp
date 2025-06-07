// 중량제한 1939
#include <iostream>
#include <vector>
using namespace std;

vector<pair<int, long long>> arr[10001]; 
int n, m, from, to;
int visit[10001] = {};
bool reached = false;
void dfs(int cur, long long limit){
    if(cur == to) reached = true;
    visit[cur] = 1;
    for(int i = 0; i < arr[cur].size(); i++){
        pair<int, long long> next = arr[cur][i];
        if(visit[next.first] == 0 && next.second >= limit) dfs(next.first, limit);
    }
}

int main(){
    cin >> n >> m;
    long long a, b, c;
    for(int i = 0; i < m; i++){
        cin >> a >> b >> c;
        arr[a].push_back({b, c});
        arr[b].push_back({a, c});
    }
    cin >> from >> to;

    long long lo = 1, hi = 1000000000, mid;
    while(lo < hi){
        mid = (lo+hi+1)/2;
        reached = false;
        for(int i = 1; i <= n; i++) visit[i] = 0;
        dfs(from, mid);
        // cout << mid << ' ' <<reached << '\n';
        if(reached){
            lo = mid;
        } else{
            hi = mid-1;
        }
    }
    cout << lo << '\n';
    return 0;
}