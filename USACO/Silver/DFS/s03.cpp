// 연결 요소의 개수 11724
#include <iostream>
#include <vector>
using namespace std;

int n, m, visit[1001];
vector<int> links[1001];

void dfs(int cur){
    visit[cur] = 1;
    for(int idx = 0; idx < links[cur].size(); idx++){
        int nxt = links[cur][idx];  
        if(visit[nxt] == 0){
            dfs(nxt);
        }
    }
}

int main(){
    cin >> n >> m;
    int c1, c2;
    for(int idx = 0; idx < m; idx++){
        cin >> c1 >> c2;
        links[c1].push_back(c2);
        links[c2].push_back(c1);
    }

    int cnt = 0;
    for(int idx = 1; idx <= n; idx++){
        if(visit[idx] == 0){
            dfs(idx);
            cnt++;
        }
    }
    cout << cnt << '\n';
    return 0;
}