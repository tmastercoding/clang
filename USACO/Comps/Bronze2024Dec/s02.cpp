#include <iostream>
#include <vector>
#include <map>
using namespace std;

// void f(){ 


int main(){
    map<vector<long long>, vector<vector<long long>>> bricks;
    map<vector<long long>, vector<vector<long long>>>::iterator it;
    vector<long long> key, coord;
    vector<vector<long long>> val;
    long long n, q;
    cin >> n >> q;
    long long x, y, z;
    long long cnt = 0;
    for(long long idx = 0; idx < q; idx++){
        cin >> x >> y >> z;
        key = {x, y, z};
        coord = {x, y, z};
        for(it = bricks.begin(); it!=bricks.end(); it++){
            long long overlap = 0;
            if(x == (it->first)[0]) overlap++;
            if(y == (it->first)[1]) overlap++;
            if(z == (it->first)[2]) overlap++;
            if(overlap == 2){
                val = it->second;
                for(int idx = 0; idx < val.size(); idx++){
                    
                }
                cnt++;
                (it->second).push_back(coord);
            }
        }
        val.clear();
        bricks[key] = val;
        cout << cnt << '\n';
    }

    return 0;
}