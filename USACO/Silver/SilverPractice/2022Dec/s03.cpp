#include <iostream>
using namespace std;

int main(){
    int n;
    int ranges[300][300];
    cin >> n;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n-i; j++){
            cin >> ranges[i][j];
        }
    }

    int out[300];
    out[0] = 0;
    out[1] = ranges[0][1];
    for(int i = 1; i < n-1; i++){
        int op1, op2;
        bool flag1 = true, flag2 = true;
        op1 = out[i]+ranges[i][1];
        op2 = out[i]-ranges[i][1];
        // cout <<op1 << ' ' << op2 << '\n';
        int start = 2;
        for(int j = i-1; j > -1; j--){
            int min = out[j], max = out[j];
            for(int k = j; k <= i; k++){
                if(out[k] < min) min = out[k];
                if(out[k] > max) max = out[k];
            }
            int tmin1 = min, tmax1 = max, tmin2 = min, tmax2 = max;
            if(op1 < tmin1) tmin1 = op1;
            if(op1 > tmax1) tmax1 = op1;
            if(op2 < tmin2) tmin2 = op2;
            if(op2 > tmax2) tmax2 = op2;
            
            // cout << tmax1-tmin1 << '\n';
            if(ranges[j][start] != tmax1-tmin1) flag1 = false;
            if(ranges[j][start++] != tmax2-tmin2) flag2 = false;
        }
        if(flag1){
            out[i+1] = op1;
        } else{
            out[i+1] = op2;
        }
    }

    for(int i = 0; i < n; i++){ 
        cout << out[i];
        if(i != n-1){
            cout << ' ';
        }
    }
    cout << '\n';

    return 0;
}