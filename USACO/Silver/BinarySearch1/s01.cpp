// 숫자 카드 10815
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
    cin >> m;

    sort(from, from+n);
    int x;
    for(int i = 0; i < m; i++){
        int lo = 0, hi = n, mid = (lo+hi)/2;
        cin >> x;
        while(hi != lo){
            mid = (lo+hi)/2;
            if(from[mid] < x){
                lo = mid+1;
            } else{
                hi = mid;
            }
        }

        if(from[hi] == x && hi < n){
            cout << "1 ";
        } else{
            cout << "0 ";
        }
    }
    cout << '\n';
    return 0;
}
