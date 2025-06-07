#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int main(){
    int n, m;
    cin >> n >> m;
    vector<int> adj[1001];
    queue<int> q;
    vector<int> out;
    int in[1001] = {};
    int num;
    for(int i = 0; i < m; i++){
        cin >> num;
        int prev, cur;
        cin >> prev;
        for(int j = 1; j < num; j++){
            cin >> cur;
            adj[prev].push_back(cur);
            in[cur]++;
            prev = cur;
        }
    }

    for(int i = 1; i <= n; i++){
        if(!in[i]) q.push(i);
    }

    while(!q.empty()){
        int cur = q.front();
        out.push_back(cur);
        q.pop();
        
        for(int nxt: adj[cur]){
            in[nxt]--;
            if(!in[nxt]) q.push(nxt);
        }
    }

    if(out.size() != n){
        cout << 0 << '\n';
    } else{
        for(int i: out){
            cout << i << '\n';
        }
    }
    return 0;
}