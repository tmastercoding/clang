#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


long long n, q, curQ;
long long arr[1000], temp[1000] , check[200000];
vector<vector<long long>> brick;
bool xO, yO, zO;
long long cnt = 0;

bool comp(long long pre, long long post){
    if(!xO){
        if(brick[arr[pre]][0] < brick[arr[post]][0]) return true;
    }
    if(!yO){
        if(brick[arr[pre]][1] < brick[arr[post]][1]) return true;
    }
    if(!zO){
        if(brick[arr[pre]][2] < brick[arr[post]][2]) return true;
    }
    return false;
}

void f(int cur){
    // cout << "CUR: "<<  cur << '\n';
    if(cur == n){
        for(int idx = 0; idx < n; idx++){
            // cout << arr[idx] << ' ';
            temp[idx] = arr[idx];
        }
        // cout << '\n';
        int oCnt = 0;
        xO = false, yO = false, zO = false;
        if(brick[arr[0]][0] == brick[arr[1]][0]){
            oCnt++;
            xO = true;
        }
        if(brick[arr[0]][1] == brick[arr[1]][1]){
            oCnt++;
            yO = true;
        }
        if(brick[arr[0]][2] == brick[arr[1]][2]){
            oCnt++;
            zO = true;
        }
        bool valid = false;
        if(oCnt == 2){
            valid = true;
            sort(temp, temp+n, comp);
        }
        for(int idx = 2; (idx < n) && (valid); idx++){
            if(xO){
                if(brick[temp[0]][0] != brick[temp[idx]][0]) valid = false;
            }
            if(yO){
                if(brick[temp[0]][1] != brick[temp[idx]][1]) valid = false;
            }
            if(zO){
                if(brick[temp[0]][2] != brick[temp[idx]][2]) valid = false;
            }
            if(!xO){
                if(brick[temp[0]][0] - brick[temp[idx]][0] == -1) valid = false;
            }
            if(!yO){
                if(brick[temp[0]][1] - brick[temp[idx]][1] == -1) valid = false;
            }
            if(!zO){
                if(brick[temp[0]][2] - brick[temp[idx]][2] == -1) valid = false;
            }
        }
        if(valid){
            cnt++;
        }
        return;
    }
    int start = 0;
    if(cur > 0){
        start = arr[cur-1];
    }
    for(int idx = start; idx <= curQ; idx++){
        if(!check[idx]){
            check[idx] = 1;
            // cout << idx << '\n';
            arr[cur] = idx;
            f(cur+1);
            check[idx] = 0;
        }
        
    }
}

int main(){
    cin >> n >> q;
    long long x, y, z;
    vector<long long> coord;
    for(curQ=0; curQ < q; curQ++){
        cin >> x >> y >> z;
        coord = {x, y, z};
        brick.push_back(coord);
        cnt = 0;
        if(curQ+1 >= n){
            for(int idx = 0; idx < q; idx++){
                check[idx] = 0;
            }
            // cout << "RECUR\n";
            f(0);
        }
        cout << cnt << '\n';
        
    }

    return 0;
}