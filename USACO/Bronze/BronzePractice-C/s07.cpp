// Modern Art (Bronze) 14532
#include <iostream>

using namespace std;

int main(){
    int size = 0;
    cin >> size;
    int canvas[size][size];
    int numbers[9][4];
    int minX, maxX, minY, maxY;
    string buffer;
    bool isBottom = true;
    int cnt = 0;
    for(int idx = 0; idx < size; idx++){
        cin >> buffer;
        for(int jdx = 0; jdx < size; jdx++){
            canvas[idx][jdx] = buffer[jdx]-'0'; 
        }
    }

    // for(int idx = 0; idx < size; idx++){
    //     for(int jdx = 0; jdx < size; jdx++){
    //         cout << canvas[idx][jdx] << ' ';
    //     }
    //     cout << '\n';
    // }

    for(int kdx = 0; kdx < 9; kdx++){
        minX = 11, maxX = 0, minY =11, maxY =0;
        for(int idx = 0; idx < size; idx++){
            for(int jdx = 0; jdx < size; jdx++){
                if(kdx+1 == canvas[idx][jdx]){
                    if(minX > idx){
                        minX = idx;
                    } 
                    if(maxX < idx){
                        maxX = idx;
                    }
                    if(minY > jdx){
                        minY = jdx;
                    }
                    if(maxY < jdx){
                        maxY = jdx;
                    }
                }
            }

        }
        if(minX == 11 && minY == 11){
            minX = 0;
            minY = 0;
        }
        numbers[kdx][0] = minX;
        numbers[kdx][1] = maxX;
        numbers[kdx][2] = minY;
        numbers[kdx][3] = maxY;

        // cout << minX << ' ' << maxX << ' ' << minY << ' '<< maxY <<'\n';
    }

    for(int idx = 0; idx < 9; idx++){
        if(!((numbers[idx][0] == 0) && (numbers[idx][1] == 0) && (numbers[idx][2] == 0) && (numbers[idx][3] == 0))){
            // cout <<  numbers[idx][0] << ' ' << numbers[idx][1] << ' ' << numbers[idx][2] << ' ' << numbers[idx][3] << endl;
            // cout << idx << endl;
            isBottom = true;
            for(int jdx = 0; jdx < 9; jdx++){
                if(jdx == idx){
                    continue;
                }
                // cout << "idx: " << idx+1 << " jdx: " << jdx+1 << endl;
                if(!((numbers[jdx][0] == 0) && (numbers[jdx][1] == 0) && (numbers[jdx][2] == 0) && (numbers[jdx][3] == 0))){
                    // cout <<  numbers[jdx][0] << ' ' << numbers[jdx][1] << ' ' << numbers[jdx][2] << ' ' << numbers[jdx][3] << endl;
                    for(int kdx = numbers[jdx][0]; kdx <= numbers[jdx][1]; kdx++){
                        if(!isBottom){
                            break;
                        }
                        for(int ldx = numbers[jdx][2]; ldx <= numbers[jdx][3]; ldx++){
                            // cout << canvas[kdx][ldx];
                            if(canvas[kdx][ldx] == (idx+1)){
                                isBottom = false;
                                break;
                            }
                        }
                        // cout << '\n';
                    }
                }
            }
            if(isBottom){
                cnt++;
            }
        }
    }

    cout << cnt << '\n';
    return 0;
}