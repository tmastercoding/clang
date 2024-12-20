#include <iostream>
#include <vector>
#include <map>
using namespace std;

// long long factorial(int n){
//     long long ans = 1;
//     for(int idx = 1; idx <=n; idx++){
//         ans *= idx;
//     }

//     return ans;
// }

int main(){
    map<vector<long long>, int> bricks;
    map<vector<long long>, int>::iterator it;
    vector<long long> key, coord;
    long long n, q;
    cin >> n >> q;
    long long x, y, z;
    long long cnt = 0;
    for(long long idx = 0; idx < q; idx++){
        cin >> x >> y >> z;
        key = {x, y, z};
        coord = {x, y, z};
        cnt = 0;
        for(it = bricks.begin(); it!=bricks.end(); it++){
            long long overlap = 0;
            if(x == (it->first)[0]) overlap++;
            if(y == (it->first)[1]) overlap++;
            if(z == (it->first)[2]) overlap++;
            if(overlap == 2){
                (it->second)++;
                
                int tot = (it->second)+1;

                cout << tot-n+1 << '\n';
                cnt += tot-n+1;
                // cnt += factorial(tot)/ (factorial(n) * factorial(tot-n));
            }
        }
        bricks[key] = 0;
        cout << cnt << '\n';
    }

    return 0;
}