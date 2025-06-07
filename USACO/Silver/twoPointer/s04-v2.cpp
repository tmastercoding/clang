// Why Did the Cow Cross the Road II (Silver) 14465
#include <iostream>
using namespace std;

int main(){
    // freopen("maxcross.in", "r", stdin);
    // freopen("maxcross.out", "w", stdout);

    int n, works[100002] = {}, k, b, j;
    cin >> n >> k >> b;
    for(int i = 0; i < b; i++){
        cin >> j; 
        works[j] = 1;
    }

    int lo = 1, hi = k, cnt = k, fixed = 0, min = 100000;
    for(int i = lo; i <= hi; i++){
        if(works[i]) fixed++;
    }
    min = fixed;
    while(true){
        hi++;
        if(hi > n) break;
        if(works[hi]) fixed++;
        if(works[lo]) fixed--;
        lo++;
        if(min > fixed) min = fixed;
    }
    cout << min << '\n';
    return 0;
}