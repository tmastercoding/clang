#include <iostream>
#include <string>
using namespace std;

int main(){
    int size;
    cin >> size;
    int sensors[size][3];
    string temp;
    int start, end;
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
        if(sensors[idx][0] == -1){
            if(!hasNone){
                postStart = sensors[idx][1];
                postEnd = sensors[idx][2];
                hasNone = true;
            } else{
                if(sensors[idx][1] > postStart){
                    postStart = sensors[idx][1];
                }
                if(sensors[idx][2] < postEnd){
                    postEnd = sensors[idx][2];
                }
            }
        }
        if(sensors[idx][0] != -1 && hasNone){
            if(sensors[idx][0] == 0){
                postStart -= sensors[idx][2];
                if(postStart < 0){
                    postStart = 0;
                }
                postEnd -= sensors[idx][1];
                if(postEnd < 0){
                    postEnd = 0;
                }
            }else{
                postStart += sensors[idx][1];
                postEnd += sensors[idx][2];
            }
        }
    }

    hasNone = false;
    for(int idx = size; idx > -1; idx--){
        if(sensors[idx][0] == -1){
            if(!hasNone){
                preStart = sensors[idx][1];
                preEnd = sensors[idx][2];
                hasNone = true;
            } else{
                if(sensors[idx][1] > preStart){
                    preStart = sensors[idx][1];
                }
                if(sensors[idx][2] < preEnd){
                    preEnd = sensors[idx][2];
                }
            }
        }
        if(sensors[idx][0] != -1 && hasNone){
            if(sensors[idx][0] == 0){
                preStart += sensors[idx][1];
                preEnd += sensors[idx][2];

            }else{
                preStart -= sensors[idx][2];
                if(preStart < 0){
                    preStart = 0;
                }
                preEnd -= sensors[idx][1];
                if(preEnd < 0){
                    preEnd = 0;
                }
            }
        }
    }
    cout << preStart << ' ' << preEnd  << '\n';
    cout << postStart << ' ' << postEnd  << '\n';
    return 0;
}