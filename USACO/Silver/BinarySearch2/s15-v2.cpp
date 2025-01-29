#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
 
vector<long long> AB, CD, ABrepeat, CDrepeat;

int main(){
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    long long A[4000], B[4000], C[4000], D[4000], cnt = 0;
    int n;
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> A[i] >> B[i] >> C[i] >> D[i];
    }
    // sort(A, A+n);
    // sort(B, B+n);
    // sort(C, C+n);
    // sort(D, D+n);

    for(int a = 0; a < n; a++){
        for(int b = 0; b < n; b++){
            AB.push_back(A[a]+B[b]);
        }
    }
    sort(AB.begin(), AB.end());

    long long sum = 0, jdx;
    for(int c = 0; c < n; c++){
        for(int d = 0; d < n; d++){
            sum = -(C[c]+D[d]);
            jdx = lower_bound(AB.begin(), AB.end(), sum)-AB.begin();
            if(AB[jdx] == sum){
                cnt += (upper_bound(AB.begin(), AB.end(), sum) - AB.begin())-jdx;
            }
        }
    }
    // sort(CD.begin(), CD.end());
    
    // long long prev = AB[0];
    // ABrepeat.push_back(1);
    // for(long long idx = 1; idx < n*n; idx++){
    //     if(prev == AB[idx]){
    //         ABrepeat.push_back(ABrepeat[idx-1]+1);
    //     } else{
    //         ABrepeat.push_back(1);
    //         prev = AB[idx];
    //     } 
    // }
    // prev = CD[0];
    // CDrepeat.push_back(1);
    // for(long long idx = 1; idx < n*n; idx++){
    //     if(prev == CD[idx]){
    //         CDrepeat.push_back(CDrepeat[idx-1]+1);
    //     } else{
    //         CDrepeat.push_back(1);
    //         prev = CD[idx];
    //     } 
    // }

    // // cout << AB.size() << ' ' << ABrepeat.size() << '\n';
    // long long jdx = 1;
    // prev = AB[0];
    // for(long long idx = 1; idx < n*n; idx++){
    //     if(AB[jdx] == prev){
    //         AB.erase(AB.begin()+jdx-1);
    //         ABrepeat.erase(ABrepeat.begin()+jdx-1);
    //     } else{
    //         prev = AB[jdx];
    //         jdx++;
    //     }
    // }

    // jdx = 1, prev = CD[0];
    // for(long long idx = 1; idx < n*n; idx++){
    //     if(CD[jdx] == prev){
    //         CD.erase(CD.begin()+jdx-1);
    //         CDrepeat.erase(CDrepeat.begin()+jdx-1);
    //     } else{
    //         prev = CD[jdx];
    //         jdx++;
    //     }
    // }

    // for(long long ab = 0; ab < AB.size(); ab++){
    //     long long lo = 0, hi = CD.size(), mid;
    //     while(lo < hi){
    //         mid = (lo+hi)/2;
    //         if(CD[mid] < -AB[ab]){
    //             lo = mid+1;
    //         } else{
    //             hi = mid;
    //         }
    //     }

    //     // cout << CD[lo] << ' ' << AB[ab] << '\n';
    //     if(CD[lo] + AB[ab] == 0){
    //         // cout << ABrepeat[AB[ab]] << ' ' << CDrepeat[CD[lo]] << "\n";
    //         cnt+= ABrepeat[ab] * CDrepeat[lo];
    //     }
    //     // if(lo+1 < n){
    //     //     if(CD[lo+1] + AB[ab] == 0) cnt++;
    //     // }
    // }
    cout << cnt << '\n';
    return 0;
}