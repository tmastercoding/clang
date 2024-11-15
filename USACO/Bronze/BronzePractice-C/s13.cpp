#include <iostream>
#include <vector>
using namespace std;

int main(){
    int frameSize;
    cin >> frameSize;
    int studentSize;
    cin >> studentSize;
    int students[100][2] = {0,}; // votes, time
    int fullFrames = 0;
    int time = 0;
    int curStudent;
    int minVotes;
    vector<int> temp;
    int minTime, minPos;

    for(int idx = 0; idx < studentSize; idx++){
        cin >> curStudent;
        if(fullFrames < frameSize){
            if(students[curStudent-1][0]){
                students[curStudent-1][0] += 1;
            } else{
                students[curStudent-1][0] = 1;
                students[curStudent-1][1] = time;
                fullFrames++;

            }
        } else{
            if(students[curStudent-1][0] > 0){
                students[curStudent-1][0] += 1;
                // students[curStudent-1][1] = time;
            } else{
                minVotes = 1001;
                temp.clear();
                for(int jdx = 0; jdx < 100; jdx++){
                    if(students[jdx][0] != 0){
                        if(students[jdx][0] < minVotes){
                            temp.clear();
                            minVotes = students[jdx][0];
                            temp.push_back(jdx);
                            // cout << minVotes << endl;
                        } else if(students[jdx][0] == minVotes){
                            temp.push_back(jdx);
                        }
                    }
                }
                // cout << "asdf "; 
                // for(int jdx = 0; jdx < temp.size();jdx++){
                //     cout << temp.at(jdx) << ' ';
                // }
                // cout << '\n';
                if(temp.size() == 1){
                    students[temp[0]][0] = 0;
                    students[curStudent-1][0] = 1;
                    students[curStudent-1][1] = time;
                } else{
                    minTime = 1001;
                    minPos = -1;
                    for(int jdx = 0; jdx < temp.size(); jdx++){
                        if(students[temp[jdx]][1] < minTime){
                            minTime = students[temp[jdx]][1];
                            minPos = temp[jdx];
                        }
                    }
                    students[minPos][0] = 0;
                    students[curStudent-1][0] = 1;
                    students[curStudent-1][1] = time;
                }
            }

        }
        time++;
    }
    for(int idx = 0; idx < 100; idx++){
        if(students[idx][0] > 0){
            cout << idx+1 << ' ';
        }
    }
    // cout << '\n';
    return 0;
}