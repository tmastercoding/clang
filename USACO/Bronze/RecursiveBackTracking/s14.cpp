// 연산자 끼워넣기 14888
#include <iostream>
using namespace std;

int n, m;
int org[20], arr[20];
int ops[4];
int maxVal = -1000000000, minVal = 1000000000;

void f(int i){
    if(i == m){
        int cur = org[0];
        for(int j = 0; j < m; j++){
            // cout << arr[j] << ' ';
            if(arr[j] == 0){
                cur += org[j+1];
            } else if(arr[j] == 1){
                cur -= org[j+1];
            } else if(arr[j] == 2){
                cur *= org[j+1];
            } else{
                if(cur > 0){
                    cur = cur/org[j+1];
                } else{
                    cur = cur/org[j+1];
                }
            }
        }
        // cout << " - " << cur << '\n';
        if(cur < minVal){
            minVal = cur;
        }
        if(cur > maxVal){
            maxVal = cur;
        }
        return;
    }
    for(int x = 0; x < 4; x++){
        if(ops[x] > 0){
            ops[x]--;
            arr[i] = x;
            f(i+1);
            ops[x]++;
        }
    }
}

int main(){
    cin >> n;
    m = n-1;
    for(int i = 0; i < n; i++){
        cin >> org[i]; 
    }
    cin >> ops[0] >> ops[1] >> ops[2] >> ops[3];
    f(0);
    cout << maxVal << '\n' << minVal << '\n';
    return 0;
}