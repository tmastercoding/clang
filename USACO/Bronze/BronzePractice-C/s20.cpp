// Moocryption 10764
#include <iostream>
#include <string>
using namespace std;

int main(){
    int hSize, vSize;
    cin >> vSize >> hSize;
    char puzzle[vSize][hSize];
    string temp;
    for(int idx = 0; idx < vSize; idx++){
        cin >> temp;
        for(int jdx = 0; jdx < hSize; jdx++){
            puzzle[idx][jdx] = temp[jdx];
        }
    }

    // for(int idx = 0; idx < vSize; idx++){
    //     for(int jdx = 0; jdx < hSize; jdx++){
    //         cout << puzzle[idx][jdx];
    //     }   
    //     cout << '\n';
    // }
    int cnt = 0, maxCnt = 0;
    char m, o;
    for(int idx = 0; idx < 26; idx++){
        m = idx+'A';
        if (m == 'M'){
            continue;
        }
        for(int jdx = 0; jdx < 26; jdx++){
            o = jdx+'A';
            if(o == 'O'){
                continue;
            }
            if(m == o){
                continue;
            }
            cnt = 0;
            for(int y = 0; y < vSize; y++){
                for(int x = 0; x < hSize; x++){
                    if(puzzle[y][x] == m){
                        // moo
                        if(x + 2 < hSize){
                            if(puzzle[y][x+1] == o && puzzle[y][x+2] == o){
                                cnt++;
                            }
                        }
                        // oom
                        if(x - 2 > -1){
                            if(puzzle[y][x-1] == o && puzzle[y][x-2] == o){
                                cnt++;
                            }
                        }
                        // m 
                        // o
                        // o
                        if(y + 2 < vSize){
                            if(puzzle[y+1][x] == o && puzzle[y+2][x] == o){
                                cnt++;
                            }
                        }
                        // o
                        // o
                        // m
                        if(y - 2 > -1){
                            if(puzzle[y-1][x] == o && puzzle[y-2][x] == o){
                                cnt++;
                            }
                        }

                        if(y +2 < vSize && x+2 < hSize){
                            if(puzzle[y+1][x+1] == o && puzzle[y+2][x+2] == o){
                                cnt++;
                            }
                        }

                        if(y -2 > -1 && x-2 > -1){
                            if(puzzle[y-1][x-1] == o && puzzle[y-2][x-2] == o){
                                cnt++;
                            }
                        }
                    
                        if(y +2 < vSize && x-2 > -1){
                            if(puzzle[y+1][x-1] == o && puzzle[y+2][x-2] == o){
                                cnt++;
                            }
                        }

                        if(y -2 > -1 && x+2 < hSize){
                            if(puzzle[y-1][x+1] == o && puzzle[y-2][x+2] == o){
                                cnt++;
                            }
                        }

                    }
                }
            }
            if(cnt > maxCnt){
                // cout << m << o << endl;
                // cout << cnt << endl;
                maxCnt = cnt;
            }
        }
    }
    cout << maxCnt << '\n';

    return 0;
}