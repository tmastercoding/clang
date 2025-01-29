#include <iostream>
using namespace std;

long long sums[1050][1050] = {};
int main(){
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    int n, m;
    cin >> n >> m;
    int num;
    sums[1][0] = 0;
    for(int x = 1; x <= n; x++){
        for(int y = 1; y <= n; y++){
            cin >> num;  
            sums[x][y] = sums[x][y-1]+num;
        }
        sums[x+1][0] = sums[x][n];
    }
    // for(int x = 1; x <= n; x++){
    //     for(int y = 1; y <= n; y++){
    //         cout << sums[x][y] << ' ';
    //     }
    //     cout << '\n';
    //     // sums[x+1][0] = sums[x][n];
    // }
    int x1, y1, x2, y2;
    long long subtract;
    for(int i = 0; i < m; i++){
        cin >> x1 >> y1 >> x2 >> y2;
        
        subtract = 0;
        if((x1 == 1) && (y1 == 1)){
            subtract = 0;
        } else if((x1 == x2) && (y1 == y2)){
            subtract = sums[x1][y1-1];
        } else{
            subtract = sums[x1][y1];
        }
        // cout << x1 << ' ' << y1 << ' ' << sums[x1][y1] << '\n';
        // cout << x2 << ' ' << y2 << ' ' << sums[x2][y2] << '\n';
        cout << sums[x2][y2] << '\n';
        // cout << sums[x2][y2] - subtract<< '\n';
    }
    return 0;
}