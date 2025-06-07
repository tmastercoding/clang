#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int p[100001], sz[100001];
vector<int> edges[100001];

int Find(int x){
    if(x == p[x]) return x;
    return p[x] = Find(p[x]);
}

void Union(int a, int b){
    a = Find(a);
    b = Find(b);
    if(a == b) return;
    if(sz[a] > sz[b]) swap(a, b);
    p[a] = b;
    sz[b] += sz[a];
}

int main(){
    int n, m;
    cin >> n >> m;
    for(int i = 1; i <= n; i++){
        p[i] = i;
        sz[i] = 1;
    }

    long long tot = 0, cur = 0;
    int a, b, w;
    for(int i = 0; i < m; i++){
        cin >> a >> b >> w;
        edges[i] = {w, a, b};
        cur += edges[i][0];
    }
    sort(edges, edges+m);
    for(int i = m-1; i > -1; i--){
        if(Find(edges[i][1]) == Find(edges[i][2])){
            cur -= edges[i][0];
            continue;
        }

        tot += cur % 1000000000 * sz[Find(edges[i][1])] % 1000000000 * sz[Find(edges[i][2])] % 1000000000;
        tot %= 1000000000; 
        Union(edges[i][1], edges[i][2]);
        cur -= edges[i][0];
    }

    // if(tot >= 1000000000) tot %= 1000000000;
    cout << tot << '\n';
    return 0;
}