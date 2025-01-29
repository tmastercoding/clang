#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    int n;
    cin >> n;
    long long arr[5005];
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    sort(arr, arr+n);
    long long target, minVal = 3000000005, ansA, ansB, ansC;
    for(int i = 0; i < n; i++){
        for(int j = i+1; j < n; j++){

            target = -(arr[i]+arr[j]);
            long long lo = j+1, hi = n, mid;
            while(lo < hi){
                mid = (lo+hi)/2;
                if(arr[mid] < target){
                    lo = mid+1;
                } else{
                    hi = mid;
                }
            }

            int a = lo-1, b = lo;
            if(a != i && a != j && abs(arr[i]+arr[j]+arr[a]) < minVal){
                minVal = abs(arr[i]+arr[j]+arr[a]);
                ansA = arr[i], ansB = arr[j], ansC = arr[a];
            }
            if(b!= i && b != j && b < n && abs(arr[i]+arr[j]+arr[b]) < minVal){
                minVal = abs(arr[i]+arr[j]+arr[b]);
                ansA = arr[i], ansB = arr[j], ansC = arr[b];
            }
        }
    }
    cout << ansA << ' ' << ansB << ' ' << ansC <<'\n';
    return 0;
}