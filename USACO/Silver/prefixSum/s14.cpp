#include <iostream>
using namespace std;

long long arr[1003][1003];
int main(){
    // freopen("paintbarn.in", "r", stdin);
    // freopen("paintbarn.out", "w", stdout);

    int n, k, x1, y1, x2, y2;
    cin >> n >> k;
    for(int y = 0; y < 1003; y++){
        for(int x = 0; x < 1003; x++){
            arr[y][x] = 0;
        }
    }
    for(int i = 0; i < n; i++){
        cin >> x1 >> y1 >> x2 >> y2;
        y1 = 1000-y1-1;
        y2 = 1000-y2;
        x2--;
        arr[y1][x1]++;
        arr[y2-1][x1]--;
        arr[y2-1][x2+1]++;
        arr[y1][x2+1]--;
    }
    for(int y = 1000; y > -1; y--){
        for(int x = 0; x < 1001; x++){
            arr[y][x] = arr[y][x-1]+arr[y+1][x]-arr[y+1][x-1]+arr[y][x];
            // cout << arr[y][x] << ' ';
        }
        // cout << '\n';
    }
    // for(int y = 990; y < 1001; y++){
    //     for(int x = 0; x < 10; x++){
    //         cout << arr[y][x] << ' ';
    //     }
    //     cout << '\n';
    // }

    int cnt = 0;
    for(int y = 0; y < 1001; y++){
        for(int x = 0; x < 1001; x++){
            if(arr[y][x] == k){
                cnt++;
            }
        }
    }
    cout << cnt << '\n';

    return 0;
}