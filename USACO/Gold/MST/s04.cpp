#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

int p[1001];
int Find(int x){
    if(x == p[x]) return x;
    return p[x] = Find(p[x]);
}

void Union(int a, int b){
    a = Find(a);
    b = Find(b);
    p[a] = b;
}
vector<double> adj[1000001];

int main(){
    int n, m;
    pair<int, int> farms[1001];

    cin >> n >> m;
    for(int i = 1; i <= n; i++){
        cin >> farms[i].first >> farms[i].second;
        p[i] = i;
    }
    for(int i = 0; i < m; i++){
        int a, b;
        cin >> a >> b;
        Union(a, b);
    }

    double sum = 0;
    int idx = 0;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            adj[idx++] = {sqrt(pow(farms[i].first-farms[j].first, 2) + pow(farms[i].second-farms[j].second, 2)),(double)i,(double)j};
        }
    }
    // if(idx == 0) break;
    sort(adj, adj+idx);
    for(int i = 0; i < idx; i++){
        if(Find((int)adj[i][1]) != Find((int)adj[i][2])){
            sum += adj[i][0];
            Union((int)adj[i][1], (int)adj[i][2]);
        }
    }

    double value = (int)(sum * 100 + .5);
    value = (double)value / 100;
    printf("%.2f\n", value);
    return 0;
}