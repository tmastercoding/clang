// Gates 10775
#include <iostream>
#include <algorithm>
using namespace std;

int p[100001], planes[100001];

int Find(int x){
    if(x == p[x]) return x;
    return p[x] = Find(p[x]);
}

int main(){
    int g, n;
    cin >> g >> n;

    for(int i = 1; i <= g; i++){
        p[i] = i;
    }
    int cnt = 0;
    for(int i = 0; i < n; i++) cin >> planes[i];
    // sort(planes, planes+n);

    for(int i = 0; i < n; i++){
        int val = Find(planes[i]);
        if(val > 0){
            cnt++;
            p[val] = val-1;
            // cout << val << '\n';
        } else{
            break;
        }
    }
    cout << cnt << '\n';
    return 0;
}