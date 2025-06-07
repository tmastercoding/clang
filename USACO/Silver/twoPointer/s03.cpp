// Herd Sums 2018
#include <iostream>
using namespace std;

int main(){
    long long n, lo = 1, hi = 0, sum = 0, cnt = 0;
    cin >> n;
    while(true){
        if(sum < n){
            hi++;
            if(hi > n) break;
            sum += hi;
        }
        if(sum >= n){
            if(sum == n) cnt++;
            sum -= lo;
            lo++;
        }
    }
    cout << cnt << '\n';

    return 0;
}