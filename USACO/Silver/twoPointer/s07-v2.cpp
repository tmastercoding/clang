//  두 개의 탑 2118
#include <iostream>
using namespace std;

int main(){
    int n;
    long long arr[100001] = {}, tot = 0;
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> arr[i];
        tot += arr[i];
    }
    for(int i = 0; i < n; i++){
        arr[i+n] = arr[i];
    }

    long long lo = -1, hi = 0, max = 0, dist = 0, temp;
    while(true){
        lo++;
        if(lo >= n) break;
        if(lo > 0) dist -= arr[lo-1];
        // cout << "JERE" << ' ' << arr[lo]-arr[lo-1] << '\n';
        // cout << lo << ' ' << hi << ' ' << dist << '\n';
        temp = dist;
        if(dist > tot-dist) temp = tot-dist;
        if(temp > max) max = temp;
        // cout << dist << ' ' << temp << '\n';
        while(dist <= tot/2){
            dist += arr[hi];
            temp = dist;
            if(dist > tot-dist) temp = tot-dist;
            if(temp > max) max = temp;
            // cout << lo << ' ' << hi << ' ' << temp << '\n';
            hi++;
        }
    }
    cout << max << '\n';
    return 0;
}