#include <iostream>
#include <algorithm>
using namespace std;

bool comp(int a, int b){
    return a > b;
}

int main(){
    long long n, heights[20], stalls[20];
    cin >> n;
    for(int idx = 0; idx < n; idx++){
        cin >> heights[idx];
    }
    for(int idx = 0; idx < n; idx++){
        cin >> stalls[idx];
    }

    sort(heights, heights+n, comp);
    sort(stalls, stalls+n, comp);
    long long cnt = 0, subtract = 0, tot = 1;
    for(int idx = 0; idx < n; idx++){
        cnt = 0;
        for(int jdx = 0; jdx < n; jdx++){
            if(heights[idx] <= stalls[jdx]){
                cnt++;
            }
        }
        tot *= cnt -subtract;
        subtract++;
    }
    cout << tot << '\n';
    return 0;
}