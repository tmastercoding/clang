// Contanminated Milk 11972
#include <iostream>
#include <string>
#include <set>
using namespace std;

int main(){
    int pSize, mSize, drinkInputSize, sickInputSize;
    int person, milk, time;
    int maxDoses = 0, doses = 0;

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

    bool isSick = false;
    bool isValid = false;
    for(milk = 1; milk < mSize+1; milk++){
        doses = 0;
        for(int idx = 0; idx < sickInputSize; idx++){
            isValid = false;
            for(int jdx = 0; jdx < drinkInputSize; jdx++){
                if(sickLog[idx][0] == drinkLog[jdx][0]){
                    if(drinkLog[jdx][2] >= sickLog[idx][1]){
                        continue;
                    }
                    if(drinkLog[jdx][1] == milk){
                        isValid = true;
                        break;
                    }
                }
            }
            if(!isValid){
                break;
            }
        }

        if(isValid){
            for(int jdx = 1; jdx <= pSize; jdx++){
                for(int idx = 0; idx < drinkInputSize; idx++){
                    if(drinkLog[idx][0] == jdx){
                        if(drinkLog[idx][1] == milk){
                            doses++;
                            break;
                        }
                    }
                }
            }
            // cout << milk << " "<< doses << endl;
            if(doses > maxDoses){
                maxDoses = doses;
            }
        }
    }
    cout << maxDoses << '\n';

    return 0;
}