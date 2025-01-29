// 먹을 것인가 먹힐 것인가 7795
#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    int t;
    cin >> t;
    for(int i = 0; i < t; i++){
        int n, m;
        cin >> n >> m;
        int a[20000], b[20000];
        for(int j = 0; j < n; j++){
            cin >> a[j];
        }
        for(int j = 0; j < m; j++){
            cin >> b[j];
        }

        sort(b, b+m);
        int sum = 0, temp;
        for(int j = 0; j < n; j++){
            temp = lower_bound(b, b+m, a[j])-b;
            // cout << temp << ' ';
            sum += temp;
            // if(temp == m || temp == 0){
            //     sum += temp;
            // } else{
            //     sum += temp-1;
            // }
        }
        cout << sum << '\n';

    }
    return 0;
}