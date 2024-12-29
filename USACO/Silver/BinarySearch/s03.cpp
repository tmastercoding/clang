// 숫자 카드 2
#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    int n, m, from[500000];
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> from[i];
    }
    sort(from, from+n);

    cin >> m;
    int x;
    for(int i = 0; i < m; i++){
        cin >> x;
        cout << abs(lower_bound(from, from+n, x) - upper_bound(from, from+n, x)) << ' ';
    }
    cout << '\n';
    return 0;
}