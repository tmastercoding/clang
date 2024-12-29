// 보석 상자 2792
#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    long long n, m, colours[300000];
    cin >> n >> m;
    for(int i = 0; i < m; i++){
        cin >> colours[i];
    }
    sort(colours, colours+m);
    long long lo = 0, hi = 1000000000, mid, sum, temp, eL, maxEL;
    while(lo < hi){
        mid = (lo+hi+1)/2;
        sum = 0;
        maxEL = 0;
        for(int i = 0; i < m; i++){
            if(mid < colours[i]){
                temp = colours[i]/mid;
                sum+= temp;
                if(temp != (float)colours[i]/(float)mid ){
                    eL = colours[i]-temp*mid;
                } else{
                    eL = mid;
                }
                cout << eL << ' ';
                if(eL > maxEL){
                    maxEL = eL;
                }
            }
        
        }
        cout << "adf: " << lo << ' ' <<mid << '\n';
        if(sum < n){
            hi = mid-1;
        } else{
            lo = mid;
        }
    }

    cout << maxEL << '\n';
    return 0;
}