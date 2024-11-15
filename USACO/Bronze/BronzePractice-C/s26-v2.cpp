// Mirrors 5857
#include <iostream>
using namespace std;

int main(){
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    int size, barnX, barnY;
    cin >> size >> barnX >> barnY;
    int fences[size+1][3];
    char temp;

    for(int idx = 0; idx < size; idx++){
        cin >> fences[idx][0] >> fences[idx][1] >> temp;    
        if(temp == '\\'){
            fences[idx][2] = 0;
        } else{
            fences[idx][2] = 1;
        }
    }
    fences[size][0] = barnX;  
    fences[size][1] = barnY;  
    fences[size][2] = 2;  
    
    int seeX = 0, seeY = 0;
    char dir = 'r';

    bool success = false;
    int fenceIdx = -1, fenceMinPos;
    int iteration = 0;
    for(int idx = -1; idx < size; idx++){
        iteration = 0;
        seeX = 0, seeY = 0;
        dir = 'r';
        success = false;
        if(idx!= -1){
            fences[idx][2] = !fences[idx][2];
        }
        
        while(true){
            if(iteration > 500){
                break;
            }
            if(dir == 'r'){
                fenceIdx = -1, fenceMinPos = 1000000;
                for(int jdx = 0; jdx < size+1; jdx++){
                    if(fences[jdx][1] == seeY){
                        if(seeX < fences[jdx][0]){
                            if(fences[jdx][0] < fenceMinPos){
                                fenceMinPos = fences[jdx][0];
                                fenceIdx = jdx;
                            }
                        }
                    }
                }
                if(fenceIdx == -1){
                    break;
                } else{
                    seeX = fences[fenceIdx][0];
                    seeY = fences[fenceIdx][1];
                    if(fences[fenceIdx][2] == 0){
                        dir = 'd';
                    } else if(fences[fenceIdx][2] == 1){
                        dir = 'u';
                    } else{
                        success = true;
                        break;
                    }
                }
            } else if(dir == 'l'){
                fenceIdx = -1, fenceMinPos = -1000000;
                for(int jdx = 0; jdx < size+1; jdx++){
                    if(fences[jdx][1] == seeY){
                        if(fences[jdx][0] < seeX){
                            if(fences[jdx][0] > fenceMinPos){
                                fenceMinPos = fences[jdx][0];
                                fenceIdx = jdx;
                            }
                        }
                    }
                }
                if(fenceIdx == -1){
                    break;
                } else{
                    seeX = fences[fenceIdx][0];
                    seeY = fences[fenceIdx][1];
                    if(fences[fenceIdx][2] == 0){
                        dir = 'u';
                    } else if(fences[fenceIdx][2] == 1){
                        dir = 'd';
                    } else{
                        success = true;
                        break;
                    }
                }
            } else if(dir == 'u'){
                fenceIdx = -1, fenceMinPos = 1000000;
                for(int jdx = 0; jdx < size+1; jdx++){
                    if(fences[jdx][0] == seeX){
                        if(fences[jdx][1] > seeY){
                            if(fences[jdx][1] < fenceMinPos){
                                fenceMinPos = fences[jdx][1];
                                fenceIdx = jdx;
                            }
                        }
                    }
                }
                if(fenceIdx == -1){
                    break;
                } else{
                    seeX = fences[fenceIdx][0];
                    seeY = fences[fenceIdx][1];
                    if(fences[fenceIdx][2] == 0){
                        dir = 'l';
                    } else if(fences[fenceIdx][2] == 1){
                        dir = 'r';
                    } else{
                        success = true;
                        break;
                    }
                }
            } else{
                fenceIdx = -1, fenceMinPos = -1000000;
                for(int jdx = 0; jdx < size+1; jdx++){
                    if(fences[jdx][0] == seeX){
                        if(fences[jdx][1] < seeY){
                            if(fences[jdx][1] > fenceMinPos){
                                fenceMinPos = fences[jdx][1];
                                fenceIdx = jdx;
                            }
                        }
                    }
                }
                if(fenceIdx == -1){
                    break;
                } else{
                    seeX = fences[fenceIdx][0];
                    seeY = fences[fenceIdx][1];
                    if(fences[fenceIdx][2] == 0){
                        dir = 'r';
                    } else if(fences[fenceIdx][2] == 1){
                        dir = 'l';
                    } else{
                        success = true;
                        break;
                    }
                }
            }   
            iteration++;
        }
        if(idx!= -1){
            fences[idx][2] = !fences[idx][2];
        }
        if(success){
            cout << idx+1 << '\n';
            break;
        }

    }
    if(!success){
        cout << -1 << '\n';
    }

    return 0;
}