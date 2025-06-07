// 두 배열의 합 2143
#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    long long t, A[1000], B[1000];
    long long bSums[1000000];
    int n, m, num;
    cin >> t >> n;
    for(int i = 0; i < n; i++){
        cin >> num;
        A[i] = num;
        if(i > 0) A[i] += A[i-1];
    }
    cin >> m;
    for(int i = 0; i < m; i++){
        cin >> num;
        B[i] = num;
        if(i > 0) B[i] += B[i-1];
    }
    int bSumsSize = 0;
    for(int i = 0; i < m; i++){
        for(int j = i; j < m; j++){
            bSums[bSumsSize] = B[j];
            if(i > 0) bSums[bSumsSize] -= B[i-1];
            bSumsSize++;
        }
    }
    sort(bSums, bSums+bSumsSize);

    long long cnt = 0, temp, found;
    for(int i = 0; i < n; i++){
        for(int j = i; j < n; j++){        
            temp = A[j];
            if(i > 0) temp -= A[i-1];
            temp = t-temp;
            // cout << "left: " << temp << ' ' << i << ' ' << j << '\n';
            cnt += upper_bound(bSums, bSums+bSumsSize, temp)-lower_bound(bSums, bSums+bSumsSize, temp);

            // int lo = 0, hi = bSumsSize-1, mid;
            // while(lo < hi){
            //     mid = (lo+hi)/2;
            //     // cout << bSums[mid] << '\n';
            //     if(bSums[mid] < temp){
            //         lo = mid+1;
            //     } else{
            //         hi = mid;
            //     }
            // }
            // if(bSums[lo] == temp) cnt++;   
        }
    }
    cout << cnt << '\n';
    return 0;
}