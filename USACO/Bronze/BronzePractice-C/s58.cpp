#include <iostream>
using namespace std;

int main(){
    int n = 0;
    cin >> n;

    int arr[100], sums[100]; 
    for(int idx = 0; idx < n; idx++){
        cin >> arr[idx];
    }

    int tot = 0;
    for(int idx = 0; idx < n; idx++){
        tot += arr[idx];
        sums[idx] = tot;
    }

    int cnt = 0;
    for(int i = 0; i < n; i++){
        for(int j = i; j < n; j++){
            double avg = sums[j];
            if(i!= 0){
                avg -= sums[i-1];
            }
            avg /= j-i+1;
            // cout << i << ' ' << j << ' ' << avg << '\n';
            for(int idx = i; idx <= j; idx++){
                if(arr[idx] == avg){
                    cnt++;
                    break;
                }
            }
        }
    }
    cout<< cnt << '\n';
    return 0;
}