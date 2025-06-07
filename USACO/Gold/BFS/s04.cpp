#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int main(){
    int n, m, a, b;
    vector<int> adj[101];
    int visit[101] = {};
    cin >> n >> a >> b >> m;

    int x, y;
    for(int i = 0; i < m; i++){
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    queue<int> q;
    q.push(a);
    visit[a] = 1;
    while(!q.empty()){
        int cur = q.front();
        q.pop();

        for(int i: adj[cur]){
            if(!visit[i]){
                visit[i] = visit[cur]+1;
                q.push(i);
            }
        }
    }
    cout << visit[b]-1 << '\n';
    return 0;
}