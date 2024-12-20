#include <iostream>
using namespace std;

int main(){
    int t;
    cin >> t;
    for(int i = 0; i < t; i++){

        long long int arr[100000], dif[100000], n, need = 0;
        cin >> n;
        long long int oddSum = 0, evenSum = 0;
        for(int idx = 0; idx < n; idx++){
            cin >> arr[idx];
            if(idx+1 & 1){
                oddSum += arr[idx];
            } else{
                evenSum += arr[idx];
            }
        }
        // if odd
        if(n & 1){
            long long int want = oddSum - evenSum;
            // long long int min = 1000000000;
            // for(int idx = 0; idx < n; idx++){
            //     if(min > arr[idx]){
            //         min = arr[idx];
            //     }
            // }
            bool work = true;
            for(int idx = 0; idx < n-1; idx++){
                if(arr[idx] < 0 || arr[idx] < want){
                    work = false;
                    break;
                }
                arr[idx+1] -= arr[idx]-want;
                arr[idx] = want;  
            }
            if(arr[n-1] != want){
                work = false;
            }
            if(want < 0 || !work){
                cout << "-1\n";
            } else{
                cout << oddSum + evenSum - want*n << '\n';
            }
        } else{
            bool work = true;
            if(oddSum - evenSum == 0){
                for(int idx = 0; idx < n-1; idx++){
                    if(arr[idx] < 0){
                        work = false;
                        break;
                    }
                    dif[idx] = arr[idx];
                    arr[idx+1] -= arr[idx];
                    arr[idx] = 0;  
                }
            } else{
                work = false;
            }
            if(arr[n-1] != 0){
                work = false;
            }
            long long int min = 1000000000;
            if(work == true){
                for(int idx =0 ; idx < n-1; idx++){
                    if(dif[idx] < 0){
                        work = false;
                        break;
                    }
                    if(idx+1 &1){
                        if(min > dif[idx]){
                            min = dif[idx];
                        }
                    }
                }
            }
            if(work == true){
                cout << oddSum + evenSum - min * n << '\n';
            } else{
                cout << "-1\n";
            }
        }
        
    }
    return 0;
}