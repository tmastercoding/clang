// Mirrors 5857
#include <iostream>
using namespace std;

int main(){
    int size, barnX, barnY;
    cin >> size >> barnX >> barnY;
    int fences[size][3];
    char temp;

    int maxX = -1000000, maxY = -1000000, minX = 1000000, minY = 1000000;
    if(barnX > maxX){
        maxX = barnX;
    } 
    if(barnX < minX){
        minX = barnX;
    }
    if(barnY > maxY){
        maxY = barnY;
    } 
    if(barnY < minY){
        minY = barnY;
    }

    for(int idx = 0; idx < size; idx++){
        cin >> fences[idx][0] >> fences[idx][1] >> temp;    
        if(fences[idx][0] > maxX){
            maxX = fences[idx][0];
        }
        if(fences[idx][0] < minX){
            minX = fences[idx][0];
        }
        if(fences[idx][1] > maxY){
            maxY = fences[idx][1];
        }
        if(fences[idx][1] < minY){
            minY = fences[idx][1];
        }
        if(temp == '\\'){
            fences[idx][2] = 0;
        } else{
            fences[idx][2] = 1;
        }
    }  
    // cout << maxX << " " << minX << " " << maxY << " " << minY << '\n';
    
    int map[maxY-minY+1][maxX-minX+1];
    for(int idx = 0; idx < maxY-minY+1; idx++){
        for(int jdx = 0; jdx < maxX-minX+1; jdx++){
            map[idx][jdx] = -1;
        }
    }
    for(int idx = 0; idx < size; idx++){
        map[fences[idx][1]-minY][fences[idx][0]-minX] = fences[idx][2];
    }
    // for(int idx = maxY-minY; idx > -1; idx--){
    //     for(int jdx = 0; jdx < maxX-minX+1; jdx++){
    //         cout << map[idx][jdx] << ' ';
    //     }
    //     cout << '\n';
    // }

    int seeX = 0, seeY = 0;
    char dir = 'r';
    // for(int y = maxY; y > minY-1; y--){
    //     for(int x = minX; x < maxX+1; x++){
    //         cout << y << "," << x << " ";
    //     }
    //     cout << '\n';
    // }


    bool success = false;
    while(true){
        // out of range
        if(seeX < minX || seeX > maxX || seeY < minY || seeY > maxY){
            break;
        } 
        // reached barn
        if(seeX == barnX && seeY == barnY){
            success = true;
            break;
        }
        if(map[seeY-minY][seeX-minX] != -1){
            if(dir == 'r'){
                if(map[seeY-minY][seeX-minX] == 0){
                    dir = 'd';
                } else{
                    dir = 'u';
                }
            } else if(dir == 'l'){
                if(map[seeY-minY][seeX-minX] == 0){
                    dir = 'u';
                } else{
                    dir = 'd';
                }
            } else if(dir == 'u'){
                if(map[seeY-minY][seeX-minX] == 0){
                    dir = 'l';
                } else{
                    dir = 'r';
                }
            } else{
                if(map[seeY-minY][seeX-minX] == 0){
                    dir = 'r';
                } else{
                    dir = 'l';
                }
            }
        }
        
        if(dir == 'r'){
            seeX++;
        } else if(dir == 'l'){
            seeX--;
        } else if(dir == 'u'){
            seeY++;
        } else{
            seeY--;
        }
    }

    int prevDir;
    if(success){
        cout << 0 << '\n';
    } else{
        for(int idx = 0; idx < size; idx++){
            if(fences[idx][2]){
                map[fences[idx][1]-minY][fences[idx][0]-minX] = 0;
            } else{
                map[fences[idx][1]-minY][fences[idx][0]-minX] = 1;
            }
            success = false;
            seeX = 0, seeY = 0;
            dir = 'r';

            while(true){
                // out of range
                if(seeX < minX || seeX > maxX || seeY < minY || seeY > maxY){
                    break;
                } 
                // reached barn
                if(seeX == barnX && seeY == barnY){
                    success = true;
                    break;
                }

                if(map[seeY-minY][seeX-minX] != -1){
                    if(dir == 'r'){
                        if(map[seeY-minY][seeX-minX] == 0){
                            dir = 'd';
                        } else{
                            dir = 'u';
                        }
                    } else if(dir == 'l'){
                        if(map[seeY-minY][seeX-minX] == 0){
                            dir = 'u';
                        } else{
                            dir = 'd';
                        }
                    } else if(dir == 'u'){
                        if(map[seeY-minY][seeX-minX] == 0){
                            dir = 'l';
                        } else{
                            dir = 'r';
                        }
                    } else{
                        if(map[seeY-minY][seeX-minX] == 0){
                            dir = 'r';
                        } else{
                            dir = 'l';
                        }
                    }
                }

                if(dir == 'r'){
                    seeX++;
                } else if(dir == 'l'){
                    seeX--;
                } else if(dir == 'u'){
                    seeY++;
                } else{
                    seeY--;
                }
            }

            map[fences[idx][1]-minY][fences[idx][0]-minX] = fences[idx][2];

            if(success){
                cout << idx+1 << '\n';
                break;
            }     
        }
        if(!success){
            cout << -1 << '\n';
        }
    }
    return 0;
}