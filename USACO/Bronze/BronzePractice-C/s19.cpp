// Hoofball 15752
#include <iostream>
#include <set>
#include <vector>
#include <algorithm>
using namespace std;


int main(){
    int size = 0;
    cin >> size;
    vector<int> cows;
    int temp;
    for(int idx = 0; idx < size; idx++){
        cin >> temp;
        cows.push_back(temp);
    }

    sort(cows.begin(), cows.end());
    int totalCnt = 0;
    int ball = 1;
    int ballIdx = 0;
    set<int> ballPath;
    vector<set<int>> paths;

    for(int idx = 0; idx < size; idx++){
        ball = cows[idx];
        ballIdx = idx;
        ballPath.clear();

        ballPath.insert(ball);
        int prevSize = 0;
        while(true){
            if(ballIdx == 0){
                ball = cows[1];
                ballIdx += 1;
                ballPath.insert(cows[1]);
            } else if(ballIdx == size-1){
                ball = cows[ballIdx-1];
                ballIdx -= 1;
                ballPath.insert(cows[ballIdx]);
            } else{
                // dist between left is smaller
                if(ball-cows[ballIdx-1] < cows[ballIdx+1]-ball ){
                    ball = cows[ballIdx-1];
                    ballIdx -= 1;
                    ballPath.insert(cows[ballIdx]);
                // dist between right is smaller
                } else if(ball-cows[ballIdx-1] > cows[ballIdx+1]- ball ){
                    ball = cows[ballIdx+1];
                    ballIdx += 1;
                    ballPath.insert(cows[ballIdx]);
                } else{
                    ball = cows[ballIdx-1];
                    ballIdx -= 1;
                    ballPath.insert(cows[ballIdx]);
                }
            }
            if(prevSize == ballPath.size()){
                break;
            }
            prevSize = ballPath.size();
        }
        paths.push_back(ballPath);
    }

    int maxSize = 0;
    set<int> maxPath;
    for(set<int> path: paths){
        if(path.size() > maxSize){
            maxSize = path.size();
            maxPath = path;
        }
    }

    vector<int> remaining, tempSet;
    for(int idx = 0; idx < size; idx++){
        if(find(maxPath.begin(), maxPath.end(), cows[idx]) == maxPath.end()){
            remaining.push_back(cows[idx]);
        }
    }
    paths.erase(find(paths.begin(), paths.end(), maxPath));
    totalCnt++;

    while(true){
        int overlap = 0, maxOverlap = 0;
        set<int> maxOverPath;
        for(set<int> path: paths){
            overlap = 0;
            for(int idx = 0; idx < remaining.size(); idx++){
                if(find(path.begin(), path.end(), remaining[idx]) != path.end()){
                    overlap++;
                }
            }
            if(overlap > maxOverlap){
                maxOverPath = path;
                maxOverlap = overlap;
            }
        }

        totalCnt++;
        if(maxOverlap == remaining.size()){
            break;
        } else{
            tempSet.clear();
            for(int idx = 0; idx < remaining.size(); idx++){
                if(find(maxOverPath.begin(), maxOverPath.end(), remaining[idx]) == maxOverPath.end()){
                    tempSet.push_back(remaining[idx]);
                }
            }
            remaining = tempSet;
            paths.erase(find(paths.begin(), paths.end(), maxOverPath));
        }
    }

    cout << totalCnt << endl;

    return 0;
}   
