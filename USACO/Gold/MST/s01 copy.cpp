#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int p[1000001];
int Find(int x){
    if(p[x] == x) return x;
    return p[x] = Find(p[x]);
}

void Union(int a, int b){
    a = Find(a);
    b = Find(b);

    p[b] = a;
}

vector<int> adj[1000000];
int main(){
    // kruskal
    int v, e;
    cin >> v >> e;

    int a, b, c;
    for(int i = 0; i < e; i++){
        cin >> a >> b >> c;
        adj[i] = {c, a, b};       
    }
    for(int i = 1; i <= v; i++){
        p[i] = i;
    }

    sort(adj, adj+e);
    long long sum = 0, max = 0;
    for(int i = 0; i < e; i++){
        if(Find(adj[i][1]) != Find(adj[i][2])){
            Union(adj[i][1], adj[i][2]);
            sum += adj[i][0];
            if(max < adj[i][0]){
                max = adj[i][0];
            }
        }
    }
    cout << sum-max << '\n';
    return 0;
}