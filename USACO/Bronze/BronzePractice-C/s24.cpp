// Mirror Field 9993
#include <iostream>
#include <string>
using namespace std;

int main(){
    int nSize = 1, mSize = 1;
    cin >> nSize >> mSize;
    char mirrors[nSize][mSize];
    string temp;

    for(int idx = 0; idx < nSize; idx++){
        cin >> temp;
        for(int jdx = 0; jdx < mSize; jdx++){
            mirrors[idx][jdx] = temp[jdx];
        }
    }

    // dir, 0 = horizontal, 1 = vertical
    int row = 0, col = 1, dir = 1;
    int y = row, x = col;
    int cnt = 1;

    bool isInfinite = false;
    int maxCnt = 0;
    dir = 0;
    for(int idx = 0; idx < nSize; idx++){
        row = idx;
        if(isInfinite){
            break;
        }
        for(int jdx = 0; jdx < 2; jdx++){
            dir = 0;
            col = jdx;
            if(jdx == 1){
                col = mSize-1;
            }
            cnt = 1;
            y = row, x = col;
            while(true){
                if(cnt > nSize * mSize){
                    cnt = -1;
                    break;
                }
                if(dir == 1){
                    if(mirrors[y][x] == '\\'){
                        if(x+1 >= mSize){
                            break;
                        } 
                        x++;
                    } else{
                        if(x-1 < 0){
                            break;
                        }
                        x--;
                    }
                    dir = 0;
                } else{
                    if(mirrors[y][x] == '\\'){
                        if(y+1 >= nSize){
                            break;
                        } 
                        y++;
                    } else{
                        if(y-1 < 0){
                            break;
                        }
                        y--;
                    }
                    dir = 1;
                }
                cnt++;
            }
            if(cnt == -1){
                maxCnt = -1;
                isInfinite = true;
                break;
            }

            if(cnt > maxCnt){
                maxCnt = cnt;
            }
        }
    }

    for(int idx = 0; idx < mSize; idx++){
        if(isInfinite){
            break;
        }
        col = idx;
        for(int jdx = 0; jdx < 2; jdx++){
            dir = 1;
            row = jdx;
            if(jdx == 1){
                row = nSize-1;
            }
            cnt = 1;
            y = row, x = col;
            while(true){
                if(cnt > (nSize * mSize)){
                    cnt = -1;
                    break;
                }
                if(dir == 1){
                    if(mirrors[y][x] == '\\'){
                        if(x+1 >= mSize){
                            break;
                        } 
                        x++;
                    } else{
                        if(x-1 < 0){
                            break;
                        }
                        x--;
                    }
                    dir = 0;
                } else{
                    if(mirrors[y][x] == '\\'){
                        if(y+1 >= nSize){
                            break;
                        } 
                        y++;
                    } else{
                        if(y-1 < 0){
                            break;
                        }
                        y--;
                    }
                    dir = 1;
                }
                cnt++;
            }
            if(cnt == -1){
                maxCnt = -1;
                isInfinite = true;
                break;
            }
            if(cnt > maxCnt){
                maxCnt = cnt;
            }
        }
    }

    cout << maxCnt << '\n';
    return 0;
}