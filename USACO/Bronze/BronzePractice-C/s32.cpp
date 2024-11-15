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

    for(int idx = 0; idx < n; idx++){
        cnt += abs(arr[idx]);
        int multiply = 2;
        for(int jdx = idx+1; jdx < n; jdx++){
            arr[jdx] += multiply*arr[idx]*-1;
            multiply++;
        }
        arr[idx] = 0;
        // for(int jdx = 0; jdx < n; jdx++){
        //     cout << arr[jdx] << ' ';
        // }
        // cout << '\n';
    }
    cout << cnt << '\n';
    return 0;
}