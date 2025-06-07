#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

long long n;
vector<long long> adj[200000];
pair<long long, long long> cows[200000];
long long visit[200000] = {};
long long cnt = 0;
void dfs(long long cur){
    visit[cur] = 1;
    for(long long i = 0; i < adj[cur].size(); i++){
        if(!visit[adj[cur][i]]){
            if(adj[cur][i] != cur){
                if(cows[cur].second <= cows[adj[cur][i]].second){
                    cows[adj[cur][i]].second -= cows[cur].second;
                    cnt += cows[cur].second;
                    cows[cur].second = 0;
                } else{
                    cows[cur].second -= cows[adj[cur][i]].second;
                    cnt += cows[adj[cur][i]].second;
                    cows[adj[cur][i]].second = 0;
                }
                dfs(adj[cur][i]);
            }
        }
    }
}


int main(){
    long long a, b;
    cin >> n >> a >> b;
    for(long long i = 0; i < n; i++){
        cin >> cows[i].second >> cows[i].first;
    }

    sort(cows, cows+n);
    // for(long long i = 0; i < n; i++){

    //     cout << cows[i].first << ' ' <<  cows[i].second << '\n';
    // }
    vector<long long> cowHalf[200000];
    for(long long i = 0; i < n; i++){
        int half = 0;
        pair<long long, long long> findPair = { a-cows[i].first, -1};
        auto found = lower_bound(cows, cows+n, findPair);
        // cout << "SETUP: " << i << '\n';
        if(found != cows+n){
            // cout << "A: " << found->first << ' ' << found->second << '\n';
            if(found->first+cows[i].first == a){
                // cout << found->first << ' ' << found-cows << '\n';
                if(found->first == cows[i].first){
                    half = 1;
                }
                adj[i].push_back(found-cows);
            }
        }
        findPair = {b-cows[i].first, 0};
        found = lower_bound(cows, cows+n, findPair);
        // cout << b-cows[i].first << '\n';
        if(found != cows+n){
            // cout << "B: " << found->first << ' ' << found->second << '\n';
            if(found->first+cows[i].first == b){
                // cout << found->first << ' ' << found-cows << '\n';
                if(found->first == cows[i].first){
                    half = 1;
                }
                adj[i].push_back(found-cows);
            }
        }
        cowHalf[i] = {cows[i].second, half, i};
    }

    sort(cowHalf, cowHalf+n);
    for(long long i = 0; i < n; i++){
        if(!visit[cowHalf[i][2]]) dfs(cowHalf[i][2]);
        // cout << i << '\n';
    }
    for(long long i = 0; i < n; i++){
        for(long long j = 0; j < adj[i].size(); j++){
            if(adj[i][j] == i){
                long long temp = cows[i].second/2;
                cows[i].second -= temp*2;
                cnt += temp;
            }
        }
    }
    cout << cnt << '\n';
    return 0;
}