// Counting Haybales 14170
#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    long long n, q, bushes[100000];
    cin >> n >> q;
    for(int i = 0; i < n; i++){
        cin >> bushes[i];
    }

    sort(bushes, bushes+n);
    long long start, end; 
    for(int i = 0; i < q; i++){
        cin >> start >> end;
        cout << upper_bound(bushes, bushes+n, end) - lower_bound(bushes, bushes+n, start) << '\n';
    }
    return 0;
}