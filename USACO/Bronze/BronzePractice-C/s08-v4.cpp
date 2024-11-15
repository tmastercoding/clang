#include <iostream>
#include <set>
using namespace std;

int main(){
    int size;
    cin >> size;
    string name;
    string charac;
    int charSize;
    string animals[size][100];
    set<string> characs;
    set<string>::iterator iter;
    int feasible[size];
    
    int maxCnt = 0, cnt = 0;

    for(int idx = 0; idx < size; idx++){
        cin >> name >> charSize;
        for(int jdx = 0; jdx < charSize; jdx++){
            cin >> charac;
            animals[idx][jdx] = charac;
            characs.insert(charac);
        }
    }

    bool isFound = false;
    for(iter = characs.begin(); iter!=characs.end(); iter++){
        for(int idx = 0; idx < size; idx++){
            feasible[idx] = idx+1;
        }
        for(int idx = 0; idx < size; idx++){
            isFound = false;
            for(int jdx =0; jdx <100; jdx++){
                if(!animals[idx][jdx].size()){
                    break;
                }
                if(!animals[idx][jdx].compare(*iter)){
                    isFound = true;
                    break;
                }
            }
            if(!isFound){
                feasible[idx] = -1;
            }
        }
        cnt = 0;
        for(int idx =0; idx < size; idx++){
            if(feasible[idx] != -1){
                cnt++;
            }
        }
        if(cnt > maxCnt){
            maxCnt = cnt;
        }
    }

    cout << maxCnt << '\n';
    return 0;
}