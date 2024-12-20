#include <iostream>
#include <vector>
using namespace std;

int main(){
    int n = 0, temp;
    cin >> n;
    int arr[100000], want[100001], move[100000];
    for(int idx = 0; idx < n; idx++){
        cin >> arr[idx];
    }
    for(int idx = 0; idx < n; idx++){
        cin >> temp;
        want[temp] = idx;
    }

    for(int idx = 0; idx < n; idx++){
        move[idx] = want[arr[idx]];
        // cout << move[idx] << ' ';
    }
    
    int maxTil = -1, cnt = 0;
    for(int idx = 0; idx < n; idx++){
        if(maxTil > move[idx]){
            cnt++;
        }
        if(move[idx] > maxTil){
            maxTil = move[idx];
        }
    }
    cout << cnt << '\n';
    return 0;
}