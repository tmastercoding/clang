#include <iostream>
using namespace std;

int main(){
    int n;
    long long a, b;
    cin >> n >> a >> b;
    long long cows[200000][2];
    for(int i = 0; i < n; i++){
        cin >> cows[i][0] >> cows[i][1];
    }

    long long cnt = 0;
    for(int i = 0; i < n; i++){
        if(cows[i][0] <= 0) continue;
        for(int j = i; j < n; j++){
            if(cows[j][0] <= 0) continue;
            if(cows[i][1] + cows[j][1] == a || cows[i][1]+cows[j][1] == b){
                if(i == j){
                    long long temp = cows[i][0]/2;
                    cows[i][0] -= temp*2;
                    cnt += temp;
                }
                if(cows[i][0] <= cows[j][0]){
                    cows[j][0] -= cows[i][0];
                    cnt += cows[i][0];
                    cows[i][0] = 0;
                    break;
                } else{
                    cows[i][0] -= cows[j][0];
                    cnt += cows[j][0];
                    cows[j][0] = 0;
                }
            }
        }
    }
    cout << cnt << '\n';
    return 0;
}