#include <iostream>
using namespace std;

long long sums[1026][1026] = {};
int main(){
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    int n, m;
    cin >> n >> m;
    int num;
    long long prev = 0;
    for(int y = 0; y < n; y++){
        for(int x = 0; x < n; x++){
            cin >> num;  
            sums[y][x] = prev+num;
            prev = sums[y][x];      
        }
    }
    
    // for(int y = 0; y < n; y++){
    //     for(int x = 0; x < n; x++){
    //         cout << sums[y][x] << ' ';  
    //     }
    //     cout << '\n';
    // }
    int x1, y1, x2, y2;
    for(int i = 0; i < m; i++){
        cin >> x1 >> y1 >> x2 >> y2;
        x1--;
        y1--;
        x2--;
        y2--;
        
        if(x1 == 0 && y1 == 0){
            prev = 0;
        } else if(x1 == x2 && y1 == y2){
            if(y1 == 0){
                y1 = n-1;
                x1--;
            } else{
                y1--;
            }
            prev = sums[x1][y1];
        } else{
            prev = sums[x1][y1];
        }
        // cout << x1 << ' ' << y1 << ' ' << sums[x1][y1] << '\n';
        // cout << x2 << ' ' << y2 << ' ' << sums[x2][y2] << '\n';
        cout << sums[x2][y2] - prev  << '\n';
    }
    return 0;
}