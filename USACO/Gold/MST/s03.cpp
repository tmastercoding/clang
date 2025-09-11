#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int p[100001] = {};

int Find(int x){
    if(x == p[x]) return x;
    return p[x] = Find(p[x]);
}

void Union(int a, int b){
    a = Find(a);
    b = Find(b);

    p[a] = b;
}

int main(){
    int n, m;
    cin >> n >> m;
    vector<int> adj[100000];
    int a, b, c;
    for(int i = 0; i < m; i++){
        cin >> a >> b >> c;
        adj[i] = {c, a, b};
    }
    for(int i = 1; i <= n; i++){
        p[i] = i;
    }

    sort(adj, adj+m);
    int sum = 0;
    for(int i = 0; i < m; i++){
        if(Find(adj[i][1]) != Find(adj[i][2])){
            Union(adj[i][1], adj[i][2]);
            sum += adj[i][0];
        }
    }

    cout << sum << '\n';

    return 0;
}