#include <iostream>
using namespace std;

int xy[1000][1000];
int yz[1000][1000];
int xz[1000][1000];
int main(){
    int n, m;
    cin >> n >> m;
    int x, y, z, cnt = 0;
    for(int idx = 0; idx < m; idx++){
        cin >> x >> y >> z;
        xy[x][y]++;
        yz[y][z]++;
        xz[x][z]++;
        if(xy[x][y] == n){
            cnt++;
        }
        if(yz[y][z] == n){
            cnt++;
        }
        if(xz[x][z] == n){
            cnt++;
        }
        cout << cnt << '\n';
    }

    return 0;
}