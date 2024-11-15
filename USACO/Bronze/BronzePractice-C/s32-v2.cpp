// Balancing Bacteria 31560
#include <iostream>
using namespace std;

int main(){
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    int n;
    long long int cnt = 0;
    cin >> n;
    long long int arr[200000] = {0, };

    for(int idx = 0; idx < n; idx++){
        cin >> arr[idx];
    }

    long long int curSum = 0, curEffect= 0, need = 0, newSum = 0, totEffect = 0;
    for(int idx = 0; idx < n; idx++){
        // cout << curSum << ' ' << curEffect << ' ' << need << '\n';
        need = (arr[idx]+curEffect)*-1;
        cnt+= abs(need);
        newSum = curSum+need;
        totEffect = arr[idx]*-1;

        curSum = newSum;
        curEffect = newSum + totEffect;
    }

    cout << cnt << '\n';
    return 0;
}