// 트리 13306
#include <iostream>
using namespace std;
int p[200001] = {}, connect[200001] = {}, queries[400000][3], output[200001];

int Find(int x){
    if(p[x] == x) return x;
    return p[x] = Find(p[x]);
}

int main(){
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    int n, q;
    cin >> n >> q;
    p[1] = 1;
    
    for(int i = 2; i <= n; i++){
        cin >> connect[i];
        p[i] = i;
    }

    for(int i = 0; i < q+n-1; i++){
        cin >> queries[i][0] >> queries[i][1];
        if(queries[i][0] == 1) cin >> queries[i][2];
    }
    
    int cnt = q-1;
    for(int i = q+n-2; i > -1; i--){
        if(!queries[i][0]){
            p[queries[i][1]] = connect[queries[i][1]];
        } else{
            if(Find(queries[i][1]) == Find(queries[i][2])){
                output[cnt--] = 1;
            } else{
                output[cnt--] = 0;
            }
        }
    }
    
    for(int i = 0; i < q; i++){
        if(output[i]){
            cout << "YES\n";
        } else{
            cout << "NO\n";
        }
    }
    return 0;
}