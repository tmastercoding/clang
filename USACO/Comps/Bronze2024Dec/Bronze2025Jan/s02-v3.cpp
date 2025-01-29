#include <iostream>
using namespace std;

int main(){
    long long n, A[500000] = {}, B[500000] = {};
    // long long out[7501] = {};
    cin >> n;
    
    for(long long i = 0; i < n; i++){
        cin >> A[i];
    }
    long long noChange = 0;
    for(long long i = 0; i < n; i++){
        cin >> B[i];
        if(A[i] == B[i]){
            noChange++;
        }
    }

    long long cnt = 0, sum = 0;
    for(long long i = 0; i < n; i++){
        long long curL = i, curR = i;
        cnt = noChange;
        while(true){
            // cout << curL << ' ' << curR << '\n';
            if(0 > curL || curL >= n || 0 > curR || curR >= n) break;
            if(A[curL] == B[curL]) cnt--;
            if(A[curR] == B[curR]) cnt--;
            if(A[curR] == B[curL]) cnt++;
            if(A[curL] == B[curR]) cnt++;
            // cout << cnt << '\n';
            sum += cnt;
            curL--, curR++;
        }
        cnt = noChange;
        curL = i, curR = i+1;
        while(true){
            // cout << curL << ' ' << curR << '\n';
            if(0 > curL || curL >= n || 0 > curR || curR >= n) break;
            if(A[curL] == B[curL]) cnt--;
            if(A[curR] == B[curR]) cnt--;
            if(A[curR] == B[curL]) cnt++;
            if(A[curL] == B[curR]) cnt++;
            // cout << cnt << '\n';
            sum += cnt;
            curL--, curR++;
        }
  
    }

    cout << sum << '\n';
    return 0;
}