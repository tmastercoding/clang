// Milking Order 15764
#include <iostream>
using namespace std;

// case 1: 1 is fixed
// case 2: 1 is in hirearchy, put hirearchy from left
// case 3: 1 is not in hireachy, put hirearchy from right

int main(){
    int totSize, hSize, pSize;
    cin >> totSize >> hSize >> pSize;
    int cows[100] = {0, };
    int hirearchy[100] = {0, };
    int gaps[100][4] = {0, };
    int cow, pos;
    int gSize = 0;
    int temp;
    bool inFixed = false;
    bool inHire = false;
    bool startGap = false;

    for(int idx = 0; idx < hSize; idx++){
        cin >> hirearchy[idx];
        if(hirearchy[idx] == 1){
            inHire = true;
        }
    }

    for(int idx = 0; idx < pSize; idx++){
        cin >> cow >> pos;
        cows[pos-1] = cow;
    }

    // case 1
    for(int idx = 0; idx < totSize; idx++){
        if(cows[idx] == 1){
            cout << idx+1 << '\n';
            inFixed = true;
        }
    }
    

    if(!inFixed){
        gSize = 0;
        for(int idx = 0; idx < totSize; idx++){
            if(cows[idx] && startGap){
                gaps[gSize][2] = idx;
                gaps[gSize][3] = cows[idx];
                startGap = false;
                gSize++;
            } else if(idx == totSize-1 && startGap){
                gaps[gSize][2] = idx;
                gaps[gSize][3] = cows[idx];
                gSize++;
            }
            if(cows[idx] && !startGap){
                gaps[gSize][0] = idx;
                gaps[gSize][1] = cows[idx];
                startGap = true;
            }
        }

        // for(int idx = 0; idx < gSize; idx++){
        //     cout << gaps[idx][0] << " " << gaps[idx][1] << " " << gaps[idx][2] << " " << gaps[idx][3] << "\n";
        // }

        // case 2
        if(inHire){
            pos = 0;
            for(int idx = 0; idx < gSize; idx++){
                // check if start = hirearchy
                for(int jdx = 0; jdx < hSize; jdx++){
                    if(hirearchy[jdx] == gaps[idx][1]){
                        pos++;
                        break;
                    }
                }
                for(int jdx = gaps[idx][0]+1; jdx < gaps[idx][2]; jdx++){
                    if(hirearchy[pos] == gaps[idx][3]){
                        break;
                    }
                    cows[jdx] = hirearchy[pos++];
                }
                // check if end = hirearchy
                // for(int jdx = 0; jdx < hSize; jdx++){
                //     if(hirearchy[jdx] == gaps[idx][3]){
                //         pos++;
                //         break;
                //     }
                // }
            }
        // case 3
        } else{
            pos = hSize-1;
            for(int idx = gSize-1; idx > -1; idx--){
                // cout << "pos: " << pos << '\n';
                // check if end = hirearchy
                for(int jdx = 0; jdx < hSize; jdx++){
                    if(hirearchy[jdx] == gaps[idx][3]){
                        pos--;
                        break;
                    }
                }
                // cout << "pos: " << pos << '\n';
                if(!gaps[idx][3]){
                    cows[gaps[idx][2]] = hirearchy[pos--];
                }
                // cout << "pos: " << pos << '\n';
                for(int jdx = gaps[idx][2]-1; jdx > gaps[idx][0]; jdx--){
                    if(hirearchy[pos] == gaps[idx][1]){
                        break;
                    }
                    cows[jdx] = hirearchy[pos--];
                }
                // cout << "pos: " << pos << '\n';
                // check if start = hirearchy
                // for(int jdx = 0; jdx < hSize; jdx++){
                //     if(hirearchy[jdx] == gaps[idx][1]){
                //         pos--;
                //         break;
                //     }
                // }
                // cout << "pos: " << pos << '\n';
            }
        }
        // cout << '\n';
        for(int idx = 0; idx < totSize; idx++){
            // cout << cows[idx] << ' ';
            if(cows[idx] == 1 || !cows[idx]){
                cout << idx+1 << '\n';
                break;
            }
        }
    }
    return 0;
}