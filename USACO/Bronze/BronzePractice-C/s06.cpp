// Contanminated Milk 11972
#include <iostream>
#include <string>
#include <set>
using namespace std;

int main(){
    int pSize, mSize, drinkInputSize, sickInputSize;
    int person, milk, time;
    set<pair<int, int>> posMilks;
    pair<int, int> temp;
    int maxDoses = 0;
    // input
    cin >> pSize >> mSize >> drinkInputSize >> sickInputSize;

    // drinkLog
    int drinkLog[drinkInputSize][3];
    for(int idx = 0; idx < drinkInputSize; idx++){
        cin >> person >> milk >> time;
        drinkLog[idx][0] = person;
        drinkLog[idx][1] = milk;
        drinkLog[idx][2] = time;
    }
    
    // sickLog
    int sickLog[sickInputSize][2];
    for(int idx = 0; idx < sickInputSize; idx++){
        cin >> person >> time;
        sickLog[idx][0] = person;
        sickLog[idx][1] = time;
    }

    
    for(int idx = 0; idx < drinkInputSize; idx++){
        if (drinkLog[idx][0] == sickLog[0][0]){
            if(sickLog[0][1] > drinkLog[idx][2]){
                temp.first = drinkLog[idx][1];
                temp.second = 0;
                posMilks.insert(temp);
            }
        }
    }

    int sickTime = 0;
    for(auto p: posMilks){
        for(int idx = 0; idx < drinkInputSize; idx++){
            if(drinkLog[idx][1] == p.first){
                if(p.second == -1){
                    continue;
                }
                sickTime = 0;
                for(int jdx = 0; jdx < sickInputSize; jdx++){
                    if(sickLog[jdx][0] == drinkLog[idx][0]){
                        sickTime = sickLog[jdx][1];
                    }
                }

                if(sickTime){
                    if(drinkLog[idx][2] < sickTime){
                        p.second++;
                    }
                } else{
                    p.second++;
                }

                if(p.second > maxDoses){
                    maxDoses = p.second;
                }
            } else{
                p.second = -1;
            }
        } 
    }
    
    cout << maxDoses << endl;


    return 0;
}