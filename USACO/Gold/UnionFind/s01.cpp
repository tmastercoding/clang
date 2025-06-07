// Virtual Friends 4195
#include <iostream>
#include <map>
using namespace std;

int f, t;
int p[200000], sz[200000];
map<string, int> convert;

int Find(int x){
    if(x == p[x]) return x;
    return p[x] = Find(p[x]);
}

void Union(int a, int b){
    // cout << a << ' '<< b << '\n';
    a = Find(a);
    b = Find(b);
    // cout << a << ' '<< b << '\n';
    
    if(a == b) return;

    if(sz[a] > sz[b]) swap(a, b);
    p[a] = b;
    sz[b] += sz[a];
    // cout << sz[b] << '\n';
}

int main(){
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    cin >> t;
    for(int c = 0; c < t; c++){
        convert.clear();
        cin >> f;
        string pre, post;
        int cur = 0;
        for(int i = 0; i < f; i++){
            cin >> pre >> post;
            if(convert.find(pre) == convert.end()){
                convert[pre] = cur++;
                p[convert[pre]] = convert[pre];
                sz[convert[pre]] = 1;
            }
            if(convert.find(post) == convert.end()){
                convert[post] = cur++;
                p[convert[post]] = convert[post];
                sz[convert[post]] = 1;
            }
            
            Union(convert[pre], convert[post]);
            int preSz = sz[Find(convert[pre])], postSz = sz[Find(convert[post])];
            if(preSz > postSz){
                cout << preSz << '\n';
            } else{
                cout << postSz << '\n';
            }
        }
    }
    return 0;
}