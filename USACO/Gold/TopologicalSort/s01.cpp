#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int main(){
    int n, m;
    cin >> n >> m;
    int in[32001] = {};
    vector<int> adj[32001];
    queue<int> q;

    int a, b;
    for(int i = 0; i < m; i++){
        cin >> a >> b;
        in[b]++;
        adj[a].push_back(b);
    }

    for(int i = 1; i <= n; i++){
        if(!in[i]) q.push(i);
    }

    while(!q.empty()){
        int num = q.front();
        cout << num << ' ';
        q.pop();
        for(int nxt: adj[num]){
            in[nxt]--;
            if(!in[nxt]) q.push(nxt);
        }
    }
    cout << '\n';
    return 0;
}