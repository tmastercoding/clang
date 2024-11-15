// Social Distancing I 18880
#include <iostream>
#include <string>
#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;

int main(){
    freopen("socdist1.in", "r", stdin);
	freopen("socdist1.out", "w", stdout);
    int size;
    cin >> size;
    string temp;
    int stalls[size];

    cin >> temp;
    for(int idx = 0; idx < size; idx++){
        stalls[idx] = temp[idx]-'0';
    }

    int prev = 0;
    int minDist = 100000;

    vector<vector<int>> gaps;
    vector<vector<int>>::iterator i;
    vector<int> gap;
    // {totGap, start end}
    gap.push_back(0);
    for(int idx = 0; idx < size; idx++){
        if(stalls[idx]){
            gap.push_back(idx);
            gap.insert(gap.begin(), idx-prev);
            gaps.push_back(gap);
            gap.clear();
            gap.push_back(idx);
            prev = idx;
        }
    }
    gap.push_back(size-1);
    gap.insert(gap.begin(), size-1-prev);
    gaps.push_back(gap);


    sort(gaps.rbegin(), gaps.rend());
    // for(i = gaps.begin(); i != gaps.end(); i++){
    //     cout << (*i)[0] << " " << (*i)[1] << " "<<(*i)[2] << '\n';
    // }


    if(gaps.size() >= 3){
        if(gaps[1][0]){
            // cout << gaps[0][2] - gaps[0][1] << '\n';

            if(stalls[gaps[0][1]]){
                if((float)(gaps[0][2] - gaps[0][1])/2 == (int)((gaps[0][2] - gaps[0][1])/2)){
                    stalls[(int)((gaps[0][2] - gaps[0][1])/2) + gaps[0][1]] = 1;

                } else{
                    stalls[(int)((gaps[0][2] - gaps[0][1])/2) + gaps[0][1]+1] = 1;

                }
            } else{
                if((float)(gaps[0][2] - gaps[0][1])/2 == (int)((gaps[0][2] - gaps[0][1])/2)){
                    stalls[(int)((gaps[0][2] - gaps[0][1])/2) + gaps[0][1]-1] = 1;

                } else{
                    stalls[(int)((gaps[0][2] - gaps[0][1])/2) + gaps[0][1]] = 1;

                }
            }
            if(stalls[gaps[1][1]]){
                if(((float)gaps[1][2] - gaps[1][1])/2 == (int)((gaps[1][2] - gaps[1][1])/2)){
                    stalls[(int)((gaps[1][2] - gaps[1][1])/2) + gaps[1][1]] = 1;

                } else{
                    stalls[(int)((gaps[1][2] - gaps[1][1])/2) + gaps[1][1]+1] = 1;

                }
            } else{
                if(((float)gaps[1][2] - gaps[1][1])/2 == (int)((gaps[1][2] - gaps[1][1])/2)){
                    stalls[0] = 1;

                } else{
                    stalls[0] = 1;

                }

            }
        } else{
            float mid = (float)(gaps[0][0]-1)/2;
            stalls[(int)(mid/2) + gaps[0][1]+1] = 1;
            stalls[gaps[0][2] - (int)(mid/2) - 1] = 1;
        }
    } else{
        if(stalls[0]==0 && stalls[size-1] == 0){
            stalls[0] = 1;
            stalls[size-1] = 1;
        } else if(stalls[0] == 1){
            float mid = (float)(gaps[0][0]-1)/2;
            stalls[(int)(mid/2) + gaps[0][1]+1] = 1;
            stalls[gaps[0][2] - (int)(mid/2)] = 1;

        } else{
            float mid = (float)(gaps[0][0])/2;
            stalls[0] = 1;
            stalls[gaps[0][1]+(int)(mid)] = 1;

        }
    }

    // for(int idx = 0; idx < size; idx++){
    //     cout << stalls[idx] << ' ';
    // }
    // cout << '\n';

    prev = -1;
    minDist = 100000;
    for(int idx = 0; idx < size; idx++){
        // cout << stalls[idx] << '\n';
        if(stalls[idx]){
            if(prev == -1){
                prev = idx;
            } else{
                if(idx - prev < minDist){
                    minDist = idx - prev;
                }
                prev = idx;
            }
        }
    }
    cout << minDist << '\n';
    return 0;
}