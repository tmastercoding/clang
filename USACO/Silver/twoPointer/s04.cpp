// Why Did the Cow Cross the Road II (Silver) 14465
#include <iostream>
using namespace std;

int main(){
    freopen("maxcross.in", "r", stdin);
    freopen("maxcross.out", "w", stdout);

    int n, works[100002] = {}, k, b, j;
    cin >> n >> k >> b;
    for(int i = 0; i < b; i++){
        cin >> j; 
        works[j] = 1;
    }

    int lo = 0, hi = -1, cnt = 0, fixed = 0, min = 100000;
    while(true){
        hi++;
        if(hi >= n) break;
        if(works[hi]) fixed++;
        cnt++;
        if(cnt == k){
            if(min > fixed) min = fixed;
            while(true){
                if(works[lo]){
                    lo++;
                    cnt--;
                    fixed--;
                    break;
                }
                cnt--;
                lo++;
            }
        }
    }
    cout << min << '\n';
    return 0;
}