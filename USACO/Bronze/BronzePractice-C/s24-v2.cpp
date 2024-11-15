// Mirror Field 9993
#include <iostream>
#include <string>
using namespace std;

int howManyHits(int x, int y, char dir, char** mirrors);

int nSize = 1, mSize = 1;
int main(){
    cin >> nSize >> mSize;
    char** mirrors;
    mirrors = (char** )malloc(sizeof(char* ) * nSize);
    string temp;

    for(int idx = 0; idx < nSize; idx++){
        cin >> temp;
        mirrors[idx] = (char* )malloc(sizeof(char) * mSize);
        for(int jdx = 0; jdx < mSize; jdx++){
            mirrors[idx][jdx] = temp[jdx];
        }
    }
    // cout << howManyHits(0, 0, 'D', mirrors) << endl;
    int maxCnt = 0, cnt = 0;
    char dir;
    for(int idx = 0; idx < nSize; idx++){
        for(int jdx = 0; jdx < mSize; jdx++){
            if(idx == 0){
                if(jdx == 0){
                    cnt = howManyHits(jdx, idx, 'R', mirrors);
                    if(cnt > maxCnt){
                        maxCnt = cnt;
                    }
                }
                if(jdx == mSize-1){
                    cnt = howManyHits(jdx, idx, 'L', mirrors);
                    if(cnt > maxCnt){
                        maxCnt = cnt;
                    }
                }
                cnt = howManyHits(jdx, idx, 'D', mirrors);
                if(cnt > maxCnt){
                    maxCnt = cnt;
                }
            } else if (idx == nSize-1){
                if(jdx == 0){
                    cnt = howManyHits(jdx, idx, 'R', mirrors);
                    if(cnt > maxCnt){
                        maxCnt = cnt;
                    }
                }
                if(jdx == mSize-1){
                    cnt = howManyHits(jdx, idx, 'L', mirrors);
                    if(cnt > maxCnt){
                        maxCnt = cnt;
                    }
                }
                cnt = howManyHits(jdx, idx, 'U', mirrors);
                if(cnt > maxCnt){
                    maxCnt = cnt;
                }

            } else{
                if(jdx == 0){
                    cnt = howManyHits(jdx, idx, 'R', mirrors);
                    if(cnt > maxCnt){
                        maxCnt = cnt;
                    }
                }
                if(jdx == mSize-1){
                    cnt = howManyHits(jdx, idx, 'L', mirrors);
                    if(cnt > maxCnt){
                        maxCnt = cnt;
                    }
                }
            }
        }
    }
    if(maxCnt == 10000000){
        maxCnt = -1;
    }
    cout << maxCnt << '\n';
    return 0;
}

int howManyHits(int x, int y, char dir, char** mirrors){
    int cnt = 0;
    while(true){
        // cout << x << " " << y<< " " << dir << '\n';
        // out of range
        if(x < 0 || x > mSize-1 || y < 0 || y > nSize-1 ){
            break;
        } 
        // infinite
        if(cnt > mSize*nSize){
            cnt = 10000000;
            break;
        }

        if(dir == 'R'){
            if(mirrors[y][x] == '\\'){
                dir = 'D';
            } else{
                dir = 'U';
            }
        } else if(dir == 'L'){
            if(mirrors[y][x] == '\\'){
                dir = 'U';
            } else{
                dir = 'D';
            }
        } else if(dir == 'U'){
            if(mirrors[y][x] == '\\'){
                dir = 'L';
            } else{
                dir = 'R';
            }
        } else{
            if(mirrors[y][x] == '\\'){
                dir = 'R';
            } else{
                dir = 'L';
            }
        }

        if(dir == 'R'){
            x++;
        } else if(dir == 'L'){
            x--;
        } else if(dir == 'U'){
            y--;
        } else{
            y++;
        }
        cnt++;
    }
    return cnt++;
}