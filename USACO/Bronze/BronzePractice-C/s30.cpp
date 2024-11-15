// Majority Opinion 31558
#include <iostream>
#include <set>
#include <algorithm>
// #include <cstdio>
using namespace std;

int main(){
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    // freopen("s30input.in", "r", stdin);
	// freopen("s30output.out", "w", stdout);
    int t, n;
    int arr[100000] = {0,};
    set<int> hays;
    cin >> t;
    for(int idx = 0; idx < t; idx++){
        cin >> n;
        for(int jdx = 0; jdx < n; jdx++){
            cin >> arr[jdx];
        }
        int prevPrev = arr[0];
        int prev = arr[1];
        hays.clear();
        if(prevPrev == prev){
            hays.insert(prev);
        }
        for(int jdx = 2; jdx < n; jdx++){
            if((prev == arr[jdx]) || (prevPrev == arr[jdx])){
                hays.insert(arr[jdx]);
            } 
            prevPrev = prev;
            prev = arr[jdx];
        }
        if(!hays.size()){
            cout << -1;
        }
        for(int i : hays){
            cout << i << ' ';
        }
        cout << '\n';
    }
    return 0;
}