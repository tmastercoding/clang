// 예산 2512
#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    long long n, areas[10000];
    long long budget, sum = 0;
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> areas[i];
        sum += areas[i];
    }
    cin >> budget;
    sort(areas, areas+n);
    if(sum <= budget){
        cout << areas[n-1] << '\n';
    } else{
        long long lo = 0, hi = 1000000001, mid;
        while(lo < hi){
            mid = (lo+hi+1)/2;
            long long sum = 0;
            for(int i = 0; i < n; i++){
                if(mid < areas[i]){
                    sum += mid;
                } else{
                    sum += areas[i];
                }
            }
            if(sum > budget){
                hi = mid-1;
            } else{
                lo = mid;
            }
        }
        cout << lo << '\n';
    }

    return 0;
}