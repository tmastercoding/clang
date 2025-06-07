#include <iostream>
using namespace std;

int p[100001], rp[100001], rc[100001];
long long val[100001] = {};
int n, m;

int Find(int x){
    if(x == p[x]) return x;
    return p[x] = Find(p[x]);
}

int rpFind(int x, int dif, int type){
    if(x == rp[x]) return x;
    if(type == 0){
        val[rp[x]] += dif;
    } else{
        val[rp[x]] -= dif;
    }
    return rpFind(rp[x], dif, type);
}

int rcFind(int x, int dif, int type){
    if(x == rc[x]) return x;
    if(type == 0){
        val[rc[x]] += dif;
    } else{
        val[rc[x]] -= dif;
    }
    return rpFind(rc[x], dif, type);
}

void Union(int a, int b, int dif){
    if(Find(a) == Find(b)) return;
    val[b] += dif;
    rpFind(b, dif, 0);
    rpFind(a, dif, 1);
    rcFind(b, dif, 0);
    rcFind(a, dif, 1);
    rp[a] = b;
    rc[b] = a;
    a = Find(a);
    b = Find(b);
    p[a] = b;
}

int main(){
    cin >> n >> m;
    for(int i = 1; i <= n; i++){
        p[i] = i;
        rp[i] = i;
        rc[i] = i;
    }

    for(int i = 0; i < m; i++){
        char ch;
        int a, b;
        cin >> ch >> a >> b;
        if(ch == '!'){
            int dif;
            cin >> dif;
            Union(a, b, dif);
        }
        for(int i = 1; i <= n; i++){
            cout << i << ": " << val[i] << '\n';
        }
    }
    return 0;
}
