// 구슬 찾기 2617
#include <iostream>
#include <vector>
using namespace std;

int n, m, visit[100];
vector<int> lesser[100], bigger[100];
int lcnt = 0, gcnt = 0;

void ldfs(int cur){
    visit[cur] = 1;
    lcnt++;
    int nxt;
    for(int idx = 0; idx < lesser[cur].size(); idx++){
        nxt = lesser[cur][idx];
        if(visit[nxt] == 0){
            ldfs(nxt);
        }
    }
}

void gdfs(int cur){
    visit[cur] = 1;
    gcnt++;
    int nxt;
    for(int idx = 0; idx < bigger[cur].size(); idx++){
        nxt = bigger[cur][idx];
        if(visit[nxt] == 0){
            gdfs(nxt);
        }
    }
}

int main(){
    cin >> n >> m;

    int m1, m2;
    for(int idx = 0; idx < m; idx++){
        cin >> m1 >> m2;
        lesser[m1].push_back(m2);
        bigger[m2].push_back(m1);
    }
    int tot = 0;
    for(int idx = 1; idx <= n; idx++){
        for(int jdx = 0; jdx <= n; jdx++){
            visit[jdx] = 0;
        }
        lcnt = 0;
        ldfs(idx);

        for(int jdx = 0; jdx <= n; jdx++){
            visit[jdx] = 0;
        }
        gcnt = 0;
        gdfs(idx);
        if(gcnt > (int)n/2+1 || lcnt > (int)n/2+1){
            tot++;
        }
        // cout << lcnt << ' ' << gcnt << '\n';
    }
    cout << tot << '\n';

    return 0;
}