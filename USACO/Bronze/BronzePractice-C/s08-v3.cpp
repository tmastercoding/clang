#include <iostream>
using namespace std;

int main(){
    int size;
    cin >> size;
    string name;
    string charac;
    int charSize;
    string animals[size][100];
    int maxCnt = 0, cnt = 0;

    for(int idx = 0; idx < size; idx++){
        cin >> name >> charSize;
        for(int jdx = 0; jdx < charSize; jdx++){
            cin >> charac;
            animals[idx][jdx] = charac;
        }
    }

    for(int idx = 0; idx < size; idx++){
        for(int jdx = 0; jdx < size; jdx++){
            // cout << "--------" << idx << " "<< jdx << endl;
            cnt = 1;
            if(idx == jdx){
                continue;
            }
            for(int kdx = 0; kdx < 100; kdx++){
                if(!animals[idx][kdx].size()){
                    break;
                }
                for(int ldx = 0; ldx < 100; ldx++){
                    if(!animals[jdx][ldx].size()){
                        break;
                    }
                    if(animals[idx][kdx] == animals[jdx][ldx]){
                        // cout << animals[idx][kdx] << '\n';
                        cnt++;    
                    }
                    
                }
            }
            if(maxCnt < cnt){
                maxCnt = cnt;
            }
        }
    }

    cout << maxCnt << '\n';

    return 0;
}