// Milk Factory 17199
#include <iostream>
#include <vector>
using namespace std;

int n, visit[101];
vector<int> belts[101];
int freq[101] = {0};

void dfs(int cur){
    visit[cur] = 1;
    freq[cur]++;

    for(int idx =0; idx < belts[cur].size(); idx++){
        int nxt = belts[cur][idx];
        if(visit[nxt] == 0){
            dfs(nxt);
        }
    }
}

int main(){
    // freopen("factory.in", "r", stdin);
    // freopen("factory.out", "w", stdout);
    cin >> n;
    int c1, c2;

    for(int idx = 0; idx < n-1; idx++){
        cin >> c1 >> c2;
        belts[c1].push_back(c2);
    }

    for(int i = 1; i < n+1; i++){
        for(int idx = 0; idx < n+1; idx++){
            visit[idx] = 0;
        }
        dfs(i);
    }

    bool found = false;
    for(int idx = 0; idx <= n; idx++){
        // cout << freq[idx] << '\n';
        if(freq[idx] == n){
            cout << idx << '\n';
            found = true;
            break;
        }
    }
    if(!found){
        cout << "-1\n";
    }
    return 0;
}