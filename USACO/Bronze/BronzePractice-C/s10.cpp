// 아이폰 9S 5883

#include <iostream>
#include <string>
using namespace std;

int main(){
    int size = 0;
    cin >> size;
    int storages[size];
    int types[1000] = {-1,};
    int temp = 0;
    bool isFound = false;
    int uniqSize = 0;

    for(int idx = 0; idx < size; idx++){
        cin >> temp;
        storages[idx] = temp;
        isFound = false;
        for(int jdx = 0; jdx < size; jdx++){
            if(types[jdx] == -1){
                break;
            }
            if(types[jdx] == storages[idx]){
                isFound = true;
                break;
            }
        }
        if(!isFound){
            types[uniqSize++] = temp;
        }
    }

    int curStorage, curSize, maxSize, totMaxSize = 0;
    for(int idx = 0; idx < uniqSize; idx++){
        curStorage = -1;
        curSize = 0;
        maxSize = 0;
        for(int jdx = 0; jdx < size; jdx++){
            if(types[idx] == storages[jdx]){
                continue;
            }
            if(storages[jdx] != curStorage){
                curStorage = storages[jdx];
                curSize = 1;
            } else{
                curSize++;
            }
            if(curSize > maxSize){
                maxSize = curSize;
            }
        }
        if(maxSize > totMaxSize){
            totMaxSize = maxSize;
        }
    }

    cout << totMaxSize << '\n';

    return 0;
}