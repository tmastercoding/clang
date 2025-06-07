#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int n, arr[1000000] = {};
int main(){
    int t = 0;
    cin >> t;
    for(int c = 0; c < t; c++){

        vector<int> comp, cur, out;
        cin >> n;
    
        for(int i = 0; i < n; i++){
            cin >> arr[i];
            comp.push_back(arr[i]);
        }
        sort(comp.rbegin(), comp.rend());
        
        if(n > 1){
            int loc = -1;
            // val, i
            pair<int, int> insertat = {0,0};
            bool start = false, ordered = true;
            int j = 0, max = 0, maxI, startI;
            for(int i = 0; i < n; i++){
                if(arr[i] == comp[0]){
                    if(loc != -1){
                        insertat = {arr[i], 0};
                        maxI = i;
                    } else{
                        start = true;
                    }
                } else if(!start){
                    // if 2nd max is found before max
                    if(arr[i] == comp[1] && loc == -1) loc = i;
                    if(loc != -1){
                        cur.push_back(arr[i]);
                    }
                } 
                // if max is found before 2nd max
                if(start){
                    cur.push_back(arr[i]);        
                    if(cur[j] != comp[j] && ordered){
                        startI = j;
                        ordered = false;    
                    }
                    if(!ordered){
                        if(arr[i] > max) max = arr[i], maxI = j;
                    }
                    j++;
                }
    
            }
            if(start){
                insertat = {max, startI};
                // cout << max << ' ' << startI << '\n';
            }
            j =0;
            // may have to get another sorted vector with cur
            for(int i = 0; i < cur.size(); i++){
                if(i == maxI) continue; 
                int temp = cur[i];
                if(i == insertat.second){
                    temp = insertat.first;
                }
                // cout << temp << ' ' << j << ' ' << comp[j] << '\n';
                if(temp == comp[j]){
                    out.push_back(comp[j]);
                    j++;
                }
                if(i == insertat.second){
                    i--;
                    insertat.second = -1;
                }
                // j++;
            
            }
            for(int i = 0; i < out.size(); i++){
                cout << out[i];
                if(i != out.size()-1) cout << ' ';
            }
            cout << '\n';
            
        } else{
    
            cout << arr[0] << '\n';
        }
    }
    return 0;
}