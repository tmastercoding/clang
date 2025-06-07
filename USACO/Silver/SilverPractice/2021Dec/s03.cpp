#include <iostream>
using namespace std;

int main(){
    int n, m;
    cin >> n >> m;
    long long aSums[10001] = {}, bSums[10001] = {};
    long long aCnt[10001], bCnt[10001], a, b;
    for(int i = 0; i < n; i++){
        cin >> a >> b;
        aCnt[a]++;
        bCnt[b]++;
    }

    for(int i = 0; i < 5001; i++){
        for(int j = 0; j < 5001; j++){
            aSums[i+j] += aCnt[i]*aCnt[j];
            bSums[i+j] += bCnt[i]*bCnt[j];
        }
    }
    
    long long tot = 0;

    for(int k = 0; k <= 2*m; k++){
        tot += aSums[k];
        if(k > 0){
            tot -= bSums[k-1];
        }
        cout << tot << '\n';
    }
    return 0;
}