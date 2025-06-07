#include <iostream>
using namespace std;

int main(){
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    int n, num;
    long long arr[50001] = {};
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> num;
        arr[i+1] = arr[i]+num;
    }
    int max = 0;
    for(int i = 1; i <= n; i++){
        for(int j = i; j <= n; j++){
            if(((arr[j]-arr[i-1]) % 7) == 0){
                if(max < j-i+1) max = j-i+1;
            }
        }
    }
    cout << max << '\n';
    return 0;
}