// 볼 모으기 17615
#include <iostream>
#include <string>
using namespace std;

int main(){
    int size = 0; 
    cin >> size;
    char balls[size];
    string temp;
    cin >> temp;
    for(int idx = 0; idx < size; idx++){
        balls[idx] = temp[idx];
    }

    // moving red to left
    int minCnt = 500000;
    int cnt = 0;
    bool correct = true;
    for(int idx = 0; idx < size; idx++){
        if(balls[idx] == 'B'){
            correct = false;
        }
        if(!correct && balls[idx] == 'R'){
            cnt++;
        }
    }
    if (cnt < minCnt){
        minCnt = cnt;
    }

    // moving red to right
    cnt = 0;
    correct = true;
    for(int idx = size-1; idx > -1; idx--){
        if(balls[idx] == 'B'){
            correct = false;
        }
        if(!correct && balls[idx] == 'R'){
            cnt++;
        }
    }
    if (cnt < minCnt){
        minCnt = cnt;
    }

    // moving blue to right
    cnt = 0;
    correct = true;
    for(int idx = size-1; idx > -1; idx--){
        if(balls[idx] == 'R'){
            correct = false;
        }
        if(!correct && balls[idx] == 'B'){
            cnt++;
        }
    }
    if (cnt < minCnt){
        minCnt = cnt;
    }

    // moving blue to left
    cnt = 0;
    correct = true;
    for(int idx = 0; idx < size; idx++){
        if(balls[idx] == 'R'){
            correct = false;
        }
        if(!correct && balls[idx] == 'B'){
            cnt++;
        }
    }
    if (cnt < minCnt){
        minCnt = cnt;
    }
    cout << minCnt << '\n';
    
    return 0;
}