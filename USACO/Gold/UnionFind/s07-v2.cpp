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
    // freopen("mootube.in", "r", stdin);
    // freopen("mootube.out", "w", stdout);    
    cin >> n >> q;
    int a, b, r;
    for(int i = 1; i < n; i++){
        cin >> a >> b >> r;
        s.insert({r, a, b});
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
        // if(queries[i][2] == 0){
        //     cout << queries[i][0] << ' ' << queries[i][1] << ' ' << queries[i][2] << '\n';
        // }
        while(true){
            it = s.lower_bound({queries[i][0], -1, -1});
            if(it != s.end()){
                if((*it)[0] >= queries[i][0]){
                    Union((*it)[1], (*it)[2]);
                    s.erase(it);
                } else{
                    break;
                }
            } else{
                break;
            }
        }
        // Find()
        out[queries[i][2]] = sz[Find(queries[i][1])]-1;
    }
    // cout << sz[p[133]] << '\n';

    for(int i = 0; i < q; i++){
        // cout << p[i+1] << '\n';
        cout << out[i] << '\n';
    }
    return 0;
}