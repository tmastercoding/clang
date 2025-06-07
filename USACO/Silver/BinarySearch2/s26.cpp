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
    long long a = 0, b = 0;
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
        long long lo = lower_bound(X, X+n, a)-X;
        // while(lo < hi){
        //     mid = (lo+hi)/2;
        //     if(X[mid] >= a){
        //         hi = mid;
        //     } else{
        //         lo = mid+1;
        //     }
        // }
        // cout << lo << '\n';
        cnt += a*(lo)-sumX[lo-1];
        cnt += sumX[n-1]-sumX[lo-1]-a*(n-lo);

        lo = lower_bound(Y, Y+n, b)-Y;
        // lo = 0, hi = n-1;
        // while(lo < hi){
        //     mid = (lo+hi)/2;
        //     if(Y[mid] >= b){
        //         hi = mid;
        //     } else{
        //         lo = mid +1;
        //     }
        // }
    
        cnt += b*(lo)-sumY[lo-1];
        cnt += sumY[n-1]-sumY[lo-1]-b*(n-lo);
    
        // cout << lo << '\n';
        // cout << b*(lo+1)-sumY[lo] << ' ' <<sumY[n-1]-sumY[lo]-b*(n-lo-1) << '\n';
        
        cout << cnt << '\n';
    }

    return 0;
}