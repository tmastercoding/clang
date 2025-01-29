#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    int n;
    long long arr[100000];
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    long long minVal = 2000000005, ansA, ansB;
    sort(arr, arr+n);
    for(int i = 0; i < n; i++){
        int target = -arr[i];
        int lo = i+1, hi = n;
        while(lo < hi){
            int mid = (lo+hi)/2;

            if(arr[mid] < target){
                lo = mid+1;
            } else{
                hi = mid;
            }
            
        }

        int a = lo-1, b= lo;
        if(a != i && abs(arr[a] + arr[i]) < minVal){
            minVal = abs(arr[a]+arr[i]);
            ansA = arr[i];
            ansB = arr[a];
        }
        if(b < n && abs(arr[b] + arr[i]) < minVal){
            minVal = abs(arr[b]+arr[i]);
            ansA = arr[i];
            ansB = arr[b];
        }
    }

    cout << ansA << ' ' << ansB << '\n';


    return 0;
}