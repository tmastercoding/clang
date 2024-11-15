// Milking Order 15764
#include <iostream>
using namespace std;

int main(){
    int totSize, hSize, pSize;
    cin >> totSize >> hSize >> pSize;
    int cows[100] = {0, };
    int hirearchy[100] = {0, };
    int fixedHire[100] = {0, };
    int cow, pos;
    int fixedHireSize = 0;
    int temp;

    for(int idx = 0; idx < hSize; idx++){
        cin >> hirearchy[idx];
    }

    for(int idx = 0; idx < pSize; idx++){
        cin >> cow >> pos;
        cows[pos-1] = cow;
    }

    for(int idx = 0; idx < totSize; idx++){
        if(!cows[idx]){
            for(int jdx = 0; jdx < hSize; jdx++){
                if(cows[idx] == hirearchy[jdx]){
                    fixedHire[fixedHireSize++] = cow;
                }
            }
        }
    }

    if (fixedHireSize > 1){
        for(int idx = 0; idx < fixedHireSize; idx++){
            int middle[100] = {0, };
            int middleSize = 0;
            bool isMiddle = false;
            for(int jdx = 0; jdx < hSize; jdx++){
                if(hirearchy[jdx] == fixedHire[idx+1]){
                    break;
                }
                if(isMiddle){
                    middle[middleSize++] = hirearchy[jdx];
                }
                if(hirearchy[jdx] == fixedHire[idx]){
                    isMiddle = true;
                }
            }
            int cnt = middleSize-1;
            for(int jdx = 0; jdx < totSize; jdx++){
                if(cows[jdx] == fixedHire[idx+1]){
                    for(int kdx = jdx; kdx > -1; kdx--){
                        if(!cows[kdx]){
                            cows[kdx] = middle[cnt--];
                        }
                    }
                    break;
                }
            }

        }
    } else{
        int middle[100] = {0, };
        int middleSize = 0;
        
        for(int jdx = 0; jdx < hSize; jdx++){
            if(hirearchy[jdx] == fixedHire[0]){
                break;
            }
            middle[middleSize++] = hirearchy[jdx];

        }

        int cnt = middleSize-1;
        for(int jdx = 0; jdx < totSize; jdx++){
            if(cows[jdx] == fixedHire[0]){
                for(int kdx = jdx; kdx > -1; kdx--){
                    if(!cows[kdx]){
                        cows[kdx] = middle[cnt--];
                    }
                }
                
            }
        }
    }

    for(int idx = 0; idx < totSize; idx++){
        if((!cows[idx]) || cows[idx] == 1){
            cout << idx+1 << '\n';
            break;
        }
    }
    return 0;
}