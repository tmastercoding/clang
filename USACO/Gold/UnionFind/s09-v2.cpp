#include <iostream>
using namespace std;

long long p[100001], rel[100001] = {};
long long n, m;
long long sum;
long long Find(long long x){
    if(x == p[x]){
        sum = 0;
        return x;
    }
    p[x] = Find(p[x]);
    rel[x] += sum;
    sum = rel[x];
    return p[x];
}        

void Union(long long a, long long b, long long dif){
    int newa = Find(a);
    int newb = Find(b);
    if(newa == newb) return;
    rel[newa] = -(dif-rel[b]+rel[a]);
    p[newa] = newb;
    // rel[a] += sum;
}

int main(){
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    while(true){
        cin >> n >> m;
        if(n == 0 && m == 0) break;
        for(long long i = 1; i <= n; i++){
            p[i] = i;
            rel[i] = 0;
        }
    
        for(long long i = 0; i < m; i++){
            char ch;
            long long a, b;
            cin >> ch >> a >> b;
            if(ch == '!'){
                long long dif;
                cin >> dif;
                // rel[a] = -dif;
                Union(a, b, dif);
                // for(long long i = 1; i <= n; i++){
                //     cout << i << ": " << rel[i] << '\n';
                // }
            } else{
                if(Find(a) == Find(b)){
                    cout << rel[b]-rel[a] << '\n';
                } else{
                    cout << "UNKNOWN\n";
                }
            }
        }
    }
    return 0;
}
