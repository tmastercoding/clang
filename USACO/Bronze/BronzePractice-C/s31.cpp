// Cannonball 31559
#include <iostream>
using namespace std;

int main(){
    int n, s;
    cin >> n >> s;
    int line[100000][2];
    for(int idx = 0; idx < n; idx++){
        cin >> line[idx][0] >> line[idx][1];
    }

    s--;
    int power = 1, cnt = 0;
    int iter = 0;
    while( -1 < s && s < n){
        if(iter > n*4){
            break;
        }
        // cout << s << ' ' << power << '\n';
        if(line[s][0] == 0){
            if(power > 0){
                power += line[s][1];
                power *= -1;
            } else{
                power -= line[s][1];
                power *= -1;
            }
        } else{
            if(line[s][1] > -1){
                if(abs(power) >= line[s][1]){
                    cnt++;
                    line[s][1] = -1;
                }
            }
        }
        s += power;
        iter++;
    }

    cout << cnt << '\n';
    return 0;
}