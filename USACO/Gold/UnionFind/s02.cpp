// 친구비 16562
#include <iostream>
using namespace std;
int p[20000], visit[20000] = {}, leastCost[20000];

int Find(int x){
    if(x == p[x]) return x;
    return p[x] = Find(p[x]);
}

void Union(int a, int b){
    a = Find(a);
    b = Find(b);

    if(a == b) return;
    // if(sz[a] > sz[b]) swap(a, b);
    p[a] = b;
    // sz[b] += sz[a];
    if(leastCost[b] > leastCost[a]) leastCost[b] = leastCost[a];
}

int main(){
    int n, m, k;
    // int cost[10000];
    cin >> n >> m >> k;
    for(int i = 0; i < n; i++){
        cin >> leastCost[i];
        // leastCost[i] = cost[i];
        p[i] = i;
        // sz[i] = 1;
    }
    int pre, post;
    for(int i = 0; i < m; i++){
        cin >> pre >> post;
        Union(pre-1, post-1);
    }

    int need = 0;
    for(int i = 0; i < n; i++){
        int parent = Find(i);
        if(!visit[parent]){
            need += leastCost[parent];
            visit[parent] = 1;
        }
    }    
    if(need <= k){
        cout << need << '\n';
    } else{
        cout << "Oh no\n";
    }
    return 0;
}