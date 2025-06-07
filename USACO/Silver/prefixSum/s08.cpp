// 어두운 건 무서워 16507
#include <iostream>
using namespace std;

int main(){
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    
    int r, c, q, cur;
    long long arr[1001][1001];
    cin >> r >> c >> q;
    for(int x = 0; x <= c; x++){
        arr[0][x] = 0;
    }
    for(int y = 1; y <= r; y++){
        arr[y][0] = 0;
        for(int x = 1; x <= c; x++){
            cin >> cur;
            arr[y][x] = arr[y][x-1]+arr[y-1][x]-arr[y-1][x-1]+cur;
        }
    }

    int x1, y1, x2, y2;
    long long tot;
    for(int i = 0; i < q; i++){
        cin >> y1 >> x1 >> y2 >> x2;
        tot = arr[y2][x2]-arr[y2][x1-1]-arr[y1-1][x2]+arr[y1-1][x1-1];
        cout << (long long)(tot/((y2-y1+1)*(x2-x1+1))) << '\n';
    }
    return 0;
}