// Angry Cows 11977
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main(){
    int size;
    cin >> size;
    vector<int> bales, copy, cur, prev, tempV;
    vector<int>::iterator iter;
    int temp;
    for(int idx = 0; idx < size; idx++){
        cin >> temp;
        bales.push_back(temp); 
    }
    sort(bales.begin(), bales.end());

    int time = 1;
    int cnt = 0;
    int maxCnt = 0;
    for(int idx = 0; idx < size; idx++){
        time = 1;
        copy = bales;
        copy.erase(find(copy.begin(), copy.end(), bales[idx]));
        prev.clear();
        prev.push_back(bales[idx]);

        while(true){
            cnt = 0;
            tempV.clear();
            for(int base: prev){
                cur.clear();
                for(int idx = base-time; idx < base+time+1; idx++){
                    if(find(copy.begin(), copy.end(), idx) != copy.end()){
                        cur.push_back(idx);
                        tempV.push_back(idx);
                        cnt++;
                    }
                }
                for(int idx: cur){
                    copy.erase(find(copy.begin(), copy.end(), idx));
                }
            }

            if(!cnt){
                break;
            }
            prev = tempV;
            time++;
        }

        if(size - copy.size() > maxCnt){
            maxCnt = size - copy.size();
        }
    }

    cout << maxCnt << '\n';


    return 0;
}