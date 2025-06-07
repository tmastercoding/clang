// 상근이의 로봇 2819
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int main(){
    int n, m;
    cin >> n >> m;
    long long X[100000], Y[100000], sumX[100000], sumY[100000];
    string commands;
    int a = 0, b = 0;
    for(int i = 0; i < n; i++){
        cin >> X[i] >> Y[i];
        sumX[i] = X[i];
        sumY[i] = Y[i];
    }
    cin >> commands;
    sort(X, X+n);
    sort(Y, Y+n);
    sort(sumX, sumX+n);
    sort(sumY, sumY+n);
    for(int i = 1; i < n; i++){
        sumX[i] += sumX[i-1];
        sumY[i] += sumY[i-1];
    }

    for(char ch: commands){
        if(ch == 'S') b++;
        if(ch == 'J') b--;
        if(ch == 'I') a++;
        if(ch == 'Z') a--;
        // cout << "COORDS: " << a << ' ' << b << '\n';
        long long cnt = 0;
        int lo = 0, hi = n-1, mid;
        while(lo < hi){
            mid = (lo+hi)/2;
            if(X[mid] >= a){
                hi = mid;
            } else{
                lo = mid+1;
            }
        }
        // cout << lo << '\n';
        cnt += a*(lo+1)-sumX[lo];
        // cout << a*(lo+1)-sumX[lo] << ' ' << sumX[n-1]-sumX[lo]-a*(n-lo-1) << '\n';
        cnt += sumX[n-1]-sumX[lo]-a*(n-lo-1);
        lo = 0, hi = n-1;
        while(lo < hi){
            mid = (lo+hi)/2;
            if(Y[mid] >= b){
                hi = mid;
            } else{
                lo = mid +1;
            }
        }
        // cout << lo << '\n';
        cnt += b*(lo+1)-sumY[lo];
        cnt += sumY[n-1]-sumY[lo]-b*(n-lo-1);
        // cout << b*(lo+1)-sumY[lo] << ' ' <<sumY[n-1]-sumY[lo]-b*(n-lo-1) << '\n';
        
        cout << cnt << '\n';
    }

    return 0;
}