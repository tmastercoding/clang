#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    int frameSize;
    cin >> frameSize;
    int studentSize;
    cin >> studentSize;
    int students[100][2] = {0,}; // votes, time
    int time = 0;
    int curStudent;
    int minVotes;
    vector<vector<int>> frames;
    vector<vector<int>>::iterator iter;
    vector<int> temp;
    vector<vector<vector<int>>::iterator> minTemp;
    int minTime, minPos;
    bool isFound = false;
    vector<vector<int>>::iterator findIter;

    for(int idx = 0; idx < studentSize; idx++){
        cin >> curStudent;
        temp.clear();
        if(frames.size() < frameSize){
            temp.push_back(curStudent);
            temp.push_back(1);
            temp.push_back(time);
            frames.push_back(temp);
        } else{
            isFound = false;
            for(iter = frames.begin(); iter!= frames.end(); iter++){
                if((*iter)[1] && (*iter)[0]== curStudent){
                    isFound = true;
                    findIter = iter;
                }
            }
            if(isFound){
                cout << "ASF" << endl;
                (*findIter)[1] += 1;
            } else{
                minVotes = 1001;
                minTemp.clear();
                for(iter = frames.begin(); iter!= frames.end(); iter++){
  
                    if((*iter)[1] < minVotes){
                        minTemp.clear();
                        minVotes = (*iter)[1];
                        minTemp.push_back(iter);
                        // cout << minVotes << endl;
                    } else if((*iter)[1] == minVotes){
                        minTemp.push_back(iter);
                    }

                }
                cout << "MinTemp: "; 
                for(int jdx = 0; jdx < minTemp.size();jdx++){
                    cout << (*minTemp[jdx])[0] << ' ' <<( *minTemp[jdx])[1] << '\n';
                }
                if(minTemp.size() == 1){
                    temp.clear();
                    temp.push_back(curStudent);
                    temp.push_back(1);
                    temp.push_back(time);
                    frames.erase(minTemp[0]);
                    frames.push_back(temp);
                } else{
                    minTime = studentSize+1;
                    for(int idx = 0; idx <= minTemp.size(); idx++){
                        if(minTime > (*(minTemp[idx]))[2]){
                            findIter = minTemp[idx];
                            minTime = (*(minTemp[idx]))[2];
                        }
                    }
                    temp.clear();
                    temp.push_back(curStudent);
                    temp.push_back(1);
                    temp.push_back(time);
                    frames.erase(find(frames.begin(), frames.end(), *findIter));
                    frames.push_back(temp);
                }
            }

        }
        // for(int idx = 0; idx < studentSize; idx++){
        //     if(students[idx][0] > 0){
        //         cout << idx+1 << ' ';
        //     }
        // }
        // cout << endl;
        for(iter = frames.begin(); iter!= frames.end(); iter++){
            cout << (*iter)[0] << ' ';
        }
        cout << '\n';
        time++;
    }
    // for(int idx = 0; idx < studentSize; idx++){
    //     if(students[idx][0] > 0){
    //         cout << idx+1 << ' ';
    //     }
    // }
    sort(frames.begin(), frames.end());
    for(iter = frames.begin(); iter!= frames.end(); iter++){
        cout << (*iter)[0] << ' ';
    }
    cout << '\n';
    return 0;
}