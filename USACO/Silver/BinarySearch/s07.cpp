// 수 찾기 1920
#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    int n, m, from[100000];
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> from[i];
    }

    sort(from, from+n);
    cin >> m;
    int x;
    for(int i = 0; i < m; i++){
        cin >> x;
        if(upper_bound(from, from+n, x) - lower_bound(from, from+n, x)){
            cout << "1\n";
        } else{
            cout << "0\n";
        }
    }
    return 0;
}