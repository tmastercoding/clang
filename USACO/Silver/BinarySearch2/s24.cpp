// XCorr 15976
#include <iostream>
#include <algorithm>
using namespace std;

pair<long long, long long> A[300000], sumB[300000];
int main(){
    int n, m;
    long long idx, num, a, b, sum = 0;
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> idx >> num;
        A[i] = {idx, num};
    }
    cin >> m;
    for(int i = 0; i < m; i++){
        cin >> idx >> num;
        sumB[i] = {idx, num};
        if(i > 0) sumB[i].second += sumB[i-1].second;
    }
    cin >> a >> b;

    // for(int i = 0; i < m; i++){
    //     cout << sumB[i].first << ' ' << sumB[i].second << '\n';
    // }


    for(int i = 0; i < n; i++){
        pair<long long, long long> temp1, temp2;
        long long xdx, ydx, with;
        temp1 = {A[i].first+b+1, 0};
        temp2 = {A[i].first+a, 0};
        xdx = lower_bound(sumB, sumB+m, temp1)-sumB-1;
        // if(xdx >= m) xdx = m-1;
        ydx = lower_bound(sumB, sumB+m, temp2)-sumB-1;
        // cout << xdx<< ' ' << ydx<< '\n';
        
        with = sumB[xdx].second;
        if(ydx > -1) with -= sumB[ydx].second;
        // ˜cout << with << '\n';
        
        sum += A[i].second*with;
    }
    cout << sum << '\n';
    return 0;
}