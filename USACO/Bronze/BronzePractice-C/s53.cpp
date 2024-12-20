#include <iostream>
using namespace std;

int main(){
    freopen("2.in", "r", stdin);

    int t;
    cin >> t;
    for(int i = 0; i < t; i++){

        long long int arr[100000], n, need = 0;
        cin >> n;
        for(int idx = 0; idx < n; idx++){
            cin >> arr[idx];
        }
        bool valid;
        for(int j = 0; j < 10; j++){

            for(int idx = n-1; idx > 1; idx--){
                if( arr[idx-1] > arr[idx-2]){
                    need +=( arr[idx-1]-arr[idx-2])*2;
                    arr[idx] -= arr[idx-1]-arr[idx-2];
                    arr[idx-1] = arr[idx-2];
                }
            }
            long long int min = 1000000000;
            for(int idx = 0; idx < n; idx++){
                if(arr[idx] < min){
                    min = arr[idx];
                }
            }
            for(int idx = 0; idx < n-1; idx++){
                if(arr[idx] == arr[idx+1] && arr[idx] != min){
                    need += (arr[idx] - min) * 2;
                    arr[idx] = min;
                    arr[idx+1] = min;
                }
            }

            valid = true;
            for(int idx = 0; idx < n; idx++){
                if(i == 6){
                    cout << arr[idx] << ' ';
                }
                if(arr[idx]< 0){
                    valid = false;
                }
                if(arr[idx] != arr[0]){
                    valid = false;
                }
            }
            if(i == 6){
                cout << need << '\n';
            }
            if(valid){
                break;
            }
        }
        
        if(valid){
            cout << need << '\n';
        } else{
            cout << "-1\n";
        }
    }
    return 0;
}