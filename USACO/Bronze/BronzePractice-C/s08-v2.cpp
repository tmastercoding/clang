// Guess the Animal 17029
#include <iostream>
#include <string>
using namespace std;

int main(){
    int size;
    cin >> size;
    string name;
    string charac;
    int charSize;
    string animals[size][100];
    int maxCnt = 0;
    int totCnt = 0, cnt = 0;

    for(int idx = 0; idx < size; idx++){
        cin >> name >> charSize;
        for(int jdx = 0; jdx < charSize; jdx++){
            cin >> charac;
            animals[idx][jdx] = charac;
        }
    }

    for(int idx = 0; idx < size; idx++){
        totCnt = 0;
        // cout << "__________" << endl;
        for(int jdx = 0; jdx < 100; jdx++){
            cnt = 0;
            if(!(animals[idx][jdx].size())){
                break;
            }
            // cout << animals[idx][jdx] << ":\n";
            for(int kdx = 0; kdx < size; kdx++){
                if(kdx == idx){
                    continue;
                }
                for(int ldx = 0; ldx < size; ldx++){
                    if(!(animals[idx][jdx].size())){
                        break;
                    }
                    if(animals[idx][jdx] == animals[kdx][ldx]){
                        // cout << animals[idx][jdx] << '\n';
                        cnt++;
                        break;
                    }
                }
            }
            if(cnt){
                totCnt++;
            }
        }
        if(totCnt > maxCnt){
            maxCnt = totCnt;
        }
    }
    cout << maxCnt+1 << '\n';

    return 0;
}