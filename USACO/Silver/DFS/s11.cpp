#include <iostream>
#include <vector>
using namespace std;

int n, m, visit[10001];
vector<int> trustBy[10001];
int cnt = 0;

void dfs(int cur){
    // cout << cur << '\n';
    visit[cur] = 1;
    cnt++;
    int nxt;
    for(int idx = 0; idx < trustBy[cur].size(); idx++){
        nxt = trustBy[cur][idx];
        
        if(visit[nxt] == 0){
            dfs(nxt);
        }
    }
}


int main(){
    cin >> n >> m;
    int c1, c2;
    int maxCnt = 0;
    vector<int> maxComps;

    for(int idx = 0; idx < m; idx++){
        cin >> c1 >> c2;
        trustBy[c2].push_back(c1);
    }

    for(int idx = 1; idx < n+1; idx++){
        cnt = 0;
        for(int jdx = 1; jdx < n+1; jdx++){
            visit[jdx] = 0;
        }
        dfs(idx);
        // cout << cnt << '\n';
        if(cnt > maxCnt){
            maxComps.clear();
            maxCnt = cnt;
            maxComps.push_back(idx);
        } else if(cnt == maxCnt){
            maxComps.push_back(idx);
        }
        // cout << "_____________________\n";
    }

    for(int idx = 0; idx < maxComps.size(); idx++){
        cout << maxComps[idx] << ' ';
    }
    cout << '\n';
    return 0;
}