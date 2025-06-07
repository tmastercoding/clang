#include <iostream>
#include <set>
#include <vector>
#include <algorithm>
using namespace std;

set<vector<int>> s;
int n, q;
vector<vector<int>> queries;
int p[100001], sz[100001], out[100001];

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
    cin >> n >> q;
    int a, b, r;
    for(int i = 1; i < n; i++){
        cin >> a >> b >> r;
        s.insert({a, r, b});
        s.insert({b, r, a});
        p[i] = i;
        sz[i] = 1;
    }
    p[n] = n;
    sz[n] = 1;

    int k, v;
    for(int i = 0; i < q; i++){
        cin >> k >> v;
        queries.push_back({k, v, i});
    }
    sort(queries.rbegin(), queries.rend());
    
    set<vector<int>>::iterator it;
    for(int i = 0; i < q; i++){
        cout << queries[i][0] << ' ' << queries[i][1] << ' ' << queries[i][2] << '\n';
        while(true){
            it = s.lower_bound({queries[i][1], queries[i][0], 0});
            if((*it)[0] == queries[i][1] && (*it)[1] >= queries[i][0]){
                Union((*it)[0], (*it)[2]);
                s.erase({(*it)[2], (*it)[1], (*it)[0]});
                s.erase({(*it)[0], (*it)[1], (*it)[2]});
            } else{
                break;
            }
        }
        out[queries[i][2]] = sz[p[queries[i][1]]]-1;
    }

    for(int i = 0; i < q; i++){
        cout << out[i] << '\n';
    }
    return 0;
}