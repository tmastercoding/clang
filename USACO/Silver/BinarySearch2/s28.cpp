// 로봇 프로젝트 3649
#include <iostream>
#include <algorithm>
using namespace std;

long long x, arr[1000000] = {};
int main(){
    int n;
    while(cin >> x){
        x*= 10000000;
        cin >> n;
        for(int i = 0; i < n; i++) cin >> arr[i];
    
        sort(arr, arr+n);
        
        bool printed = false;
        for(int i = 0; i < n; i++){
            int idx = lower_bound(arr, arr+n, x-arr[i])-arr;
            // cout << arr[i] << ' ' << idx << '\n';
            if(0 <= idx && idx < n && idx != i){
                if(arr[idx]+arr[i] == x){
                    cout << "yes ";
                    printed = true;
                    if(arr[idx] < arr[i]){
                        cout << arr[idx] << ' ' << arr[i] << '\n';
                    } else{
                        cout << arr[i] << ' ' << arr[idx] << '\n';
                    }
                    break;
    
                }
            }
        }
        if(!printed){
            cout <<"danger\n";
        }

    }
    return 0;
}