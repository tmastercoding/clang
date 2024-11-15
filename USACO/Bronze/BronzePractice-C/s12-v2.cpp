// Measuring Traffic 17041
#include <iostream>
#include <string>
using namespace std;

int main(){
    int size;
    cin >> size;
    int sensors[size][3];
    string temp;
    int start, end;
    int curStart, curEnd;
    int curBeginIdx, curEndIdx = size; 
    int preStart, preEnd;
    int postStart, postEnd;
    bool hasNone = false;

    for(int idx = 0; idx < size; idx++){
        cin >> temp >> start >> end;
        if(temp == "on"){
            sensors[idx][0] = 1;
        } else if(temp == "off"){
            sensors[idx][0] = 0;
        } else{
            sensors[idx][0] = -1;
        }
        sensors[idx][1] = start;
        sensors[idx][2] = end;
    }

    for(int idx = 0; idx < size; idx++){
        // cout << sensors[idx][0] << ' ' << sensors[idx][1] << ' ' << sensors[idx][2] << '\n';
        if(sensors[idx][0] == -1){
            if(!hasNone){
                curStart = sensors[idx][1];
                curEnd = sensors[idx][2];
                curBeginIdx = idx;
                hasNone = true;
            } else{
                if(sensors[idx][1] > curStart){
                    curStart = sensors[idx][1];
                }
                if(sensors[idx][2] < curEnd){
                    curEnd = sensors[idx][1];
                }
            }
        } else if(hasNone){
            curEndIdx = idx;
            break;
        }
    }
    preStart = curStart, preEnd = curEnd;
    postStart = curStart, postEnd = curEnd;
    if(curBeginIdx-1 >= 0){
        for(int idx = curBeginIdx-1; idx > -1; idx--){
            if(sensors[idx][0] == 0){
                preStart += sensors[idx][2];
                preEnd += sensors[idx][1];
            } else if(sensors[idx][0] == 1){
                preStart -= sensors[idx][2];
                preEnd -= sensors[idx][1];
            } else{
                if(sensors[idx][1] > preStart){
                    preStart = sensors[idx][1];
                }
                if(sensors[idx][2] < preEnd){
                    preEnd = sensors[idx][2];
                }

            }
        }
    }
    if(curEndIdx != size){
        // cout << curEndIdx << endl;
        for(int idx = curEndIdx; idx < size; idx++){
            // cout << sensors[idx][0] << ' ' << sensors[idx][1] << ' ' << sensors[idx][2] << '\n';
            // cout << postStart << ' ' << postEnd << '\n';
            if(sensors[idx][0] == 0){
                postStart -= sensors[idx][2];
                postEnd -= sensors[idx][1];
            } else if(sensors[idx][0] == 1){
                postStart += sensors[idx][2];
                postEnd += sensors[idx][1];
            } else{
                if(sensors[idx][1] > postStart){
                    postStart = sensors[idx][1];
                }
                if(sensors[idx][2] < postEnd){
                    postEnd = sensors[idx][2];
                }

            }
        }
    }
    cout << preStart << ' ' << preEnd  << '\n';
    cout << postStart << ' ' << postEnd  << '\n';
    return 0;
}