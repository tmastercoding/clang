#include <iostream>
#include <vector>
#include <set>
using namespace std;

vector<long long> bricks[200000], coord;
long long n, q;
set<set<vector<long long>>> tot; 
set<vector<long long>> each;

bool block[1000][1000][1000];


int main(){
    cin >> n >> q;
    long long x, y, z;
    long long cnt = 0;
    int dx[6] = {1, -1, 0, 0, 0, 0};
    int dy[6] = {0, 0, 1, -1, 0, 0};
    int dz[6] = {0, 0, 0, 0, 1, -1};
    for(long long idx = 0; idx < q; idx++){
        cin >> x >> y >> z;
        long long xx = x, yy = y, zz = z;
        block[x][y][z] = 1;
        bricks[idx] = {x, y, z};
        for(long long jdx = 0; jdx < idx; jdx++){
            for(int i = 0; i < 6; i++){
                each.clear();
                bool work = true;
                xx = bricks[jdx][0];
                yy = bricks[jdx][1];
                zz = bricks[jdx][2];
                for(int j = 0; j < n; j++){
                    xx += dx[i];
                    yy += dy[i];
                    zz += dz[i];
                    coord.clear();
                    coord.push_back(xx);
                    coord.push_back(yy);
                    coord.push_back(zz);
                    each.insert(coord);
                    if(block[xx][yy][zz] != 1){
                        work = false;
                        break;
                    }
                }
                if(work){
                    tot.insert(each);
                }
            }
        }

        cout << tot.size() << '\n';
       
    }

    return 0;
}