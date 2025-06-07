#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    int n, k;
    int sums[1000003] = {};
    cin >> n >> k;
    int from, to;
    for(int i = 0; i < k; i++){
        cin >> from >> to;
        sums[from]++;
        sums[to+1]--;
    }

    for(int i = 1; i <= n; i++){
        sums[i] += sums[i-1];
    }
    sort(sums+1, sums+n+1);
    cout << sums[n/2+1] << '\n';

    return 0;
}