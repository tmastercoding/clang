#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int main(){
    priority_queue<int, vector<int>, greater<int>> pq;
    int n, m;
    cin >> n >> m;
    vector<int> adj[32001];
    int in[32001] = {};
    
    int a, b;
    for(int i = 0; i < m; i++){
        cin >> a >> b;
        in[b]++;
        adj[a].push_back(b);
    }

    for(int i = 1; i <= n; i++){
        if(!in[i]) pq.push(i);
    }

    while(!pq.empty()){
        int cur = pq.top();
        cout << cur << ' ';
        pq.pop();

        for(int nxt: adj[cur]){
            in[nxt]--;
            if(!in[nxt]) pq.push(nxt);
        }
    }
    cout << '\n';
    return 0;
}