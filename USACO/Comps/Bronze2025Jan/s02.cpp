#include <iostream>
using namespace std;

int main(){
    int n, A[7500] = {}, B[7500] = {};
    long long out[7500] = {};
    cin >> n;
    
    for(int i = 0; i < n; i++){
        cin >> A[i];
    }
    for(int i = 0; i < n; i++){
        cin >> B[i];
    }

    for(int l = 0; l < n; l++){
        for(int r = l; r < n; r++){
            int cnt = 0;
            for(int i = l; i <= r; i++){
                if(B[i] == A[r-i+1]){
                    cnt++;
                }
            }
            out[cnt]++;
        }
    }

    for(int c = 0; c <= n; c++){
        cout << out[c] << '\n';
    }
    return 0;
}