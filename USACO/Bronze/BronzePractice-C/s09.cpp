// Taming the Herd 15753

#include <iostream>
#include <string>
using namespace std;

int main(){
    int size = 0; 
    cin >> size;
    int actualLog[size];
    int predictLog[size];
    int temp;
    int minCnt = 1, maxCnt = 1;
    int prev = 0;
    bool isValid = true;
    for(int idx = 0; idx < size; idx++){
        cin >> temp;
        actualLog[idx] = temp;
        predictLog[idx] = temp;
    }

    predictLog[0] = 0;

    for(int idx = 0; idx < size; idx++){
        if(actualLog[idx]>0){
            temp = actualLog[idx];
            for(int jdx = idx-1; jdx >= idx-actualLog[idx]; jdx--){
                if (predictLog[jdx] == -1){
                    predictLog[jdx] = --temp;
                }
            }
        }
    }

    prev = predictLog[0];
    if(prev != 0){
        cout << -1 << '\n';
    } else{

        for(int idx = 1; idx < size; idx++){
            // cout << predictLog[idx] << endl;
            if((prev != -1) && (predictLog[idx] != -1) && (predictLog[idx] != 0)){
                if( (predictLog[idx] - prev != 1) || ((prev == 0 )&& (predictLog[idx]-prev != predictLog[idx]))){
                    cout << -1 << '\n';
                    isValid = false;
                    break;
                }
            }
            if(predictLog[idx] == 0){
                minCnt++;
                maxCnt++;
            } else if(predictLog[idx] == -1){
                maxCnt++;
            }
            prev = predictLog[idx];
        } 
        if (isValid){
            cout << minCnt << ' ' << maxCnt << '\n';
        }
    }
    

    return 0;
}