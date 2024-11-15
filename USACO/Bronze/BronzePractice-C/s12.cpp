// Measuring Traffic 17041
#include <iostream>
#include <string>
using namespace std;

int main(){
    int size = 0;
    cin >> size;
    int sensors[size][3];
    string typeStr;
    int typeInt;
    int start, end;
    int totStart = -1, totEnd=-1;
    int beforeStart = 0, beforeEnd = 0;
    int afterStart = 0, afterEnd = 0;

    for(int idx = 0; idx < size; idx++){
        cin >> typeStr >> start >> end;
        if(typeStr == "on"){
            typeInt = 1;
        } else if(typeStr == "off"){
            typeInt = 0;
        } else{
            typeInt = -1;
        }

        sensors[idx][0] = typeInt;
        sensors[idx][1] = start;
        sensors[idx][2] = end;
    }
    bool hasntAdded = false;
    bool hasStart = false;

    for(int idx = 0; idx < size; idx++){
        if(sensors[idx][0] != -1){
            if(!hasStart){
                beforeStart = - sensors[idx][2];
                beforeEnd = - sensors[idx][1];
                hasntAdded = true;
                hasStart = true;
            }  else{
                afterStart = totStart - sensors[idx][2];
                afterEnd = totEnd - sensors[idx][1];
                totStart = afterStart;
                totEnd = afterEnd;
            }
        }
        
        if(sensors[idx][0] == -1){
            if(hasntAdded){
                while(sensors[idx][0] == -1){
                    if(totStart == -1){
                        // cout << "asdf " << totStart << ' ' << totEnd << endl;
                        totStart = sensors[idx][1];
                        totEnd = sensors[idx][2];
                        // cout << "asdf " << totStart << ' ' << totEnd << endl;
                    } else{
                        if(totStart < sensors[idx][1]){
                            totStart = sensors[idx][1];
                        }
                        if(totEnd > sensors[idx][2]){
                            totEnd = sensors[idx][2];
                        }
                    }
                    idx++;
                }
                idx--;

                // cout << beforeStart << ' ' << beforeEnd << endl;
                // cout << totStart << ' ' << totEnd << endl;
                beforeStart += totStart;
                beforeEnd += totEnd;
                // cout << beforeStart << ' ' << beforeEnd << endl;
                hasntAdded = false;
            } else{
                if(totStart == -1){
                    totStart = sensors[idx][1];
                    totEnd = sensors[idx][2];
                } else{
                    if(totStart < sensors[idx][1]){
                        totStart = sensors[idx][1];
                    }
                    if(totEnd > sensors[idx][2]){
                        totEnd = sensors[idx][2];
                    }
                }
            }

        }
        
    }

    // beforeStart = totStart, beforeEnd = totEnd;
    // afterStart = totStart, afterEnd = totEnd;
    // for(int idx = 0; idx < size; idx++){
    //     if(sensors[idx][0] == 1){
    //         beforeStart -= sensors[idx][1];
    //         beforeEnd -= sensors[idx][2];
    //     }
    //     if(sensors[idx][0] == 0){
    //         afterStart -= sensors[idx][2];
    //         afterEnd -= sensors[idx][1];
    //     }
    // }

    cout << beforeStart<< ' ' << beforeEnd << endl;
    cout << afterStart << ' ' << afterEnd << endl;
    return 0;
}