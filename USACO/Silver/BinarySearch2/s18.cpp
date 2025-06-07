#include <iostream>
using namespace std;

int main(){
    int n, s, num;
    long long arr[100001] = {};
    cin >> n >> s;
    
    for(int i = 0; i < n; i++){
        cin >> num;
        if(i > 0){
            arr[i] = arr[i-1]+num;
        } else{
            arr[i] = num;
        }
    }

    int min = 1000001;
    for(int i = 0; i < n; i++){
        long long lo = i, hi = n-1, mid, temp;
        while(lo < hi){
            mid = (lo+hi)/2;
            if(i > 0){
                temp = arr[mid]-arr[i-1];
            } else{
                temp = arr[mid];
            }
            if(temp >= s){
                if(mid-i+1 < min) min = mid-i+1;
                hi = mid;
            } else{
                lo = mid+1;
            }
        }
        temp = arr[lo];
        if(i > 0) temp -= arr[i-1];
        if(lo-i+1 < min && temp >= s) min = lo-i+1;
    }
    if(min == 1000001) min = 0;
    cout << min << '\n';
    return 0;
}