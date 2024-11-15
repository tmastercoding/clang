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
    int maxSize = 0;
    int maxCharac = 0;
    int totCnt = 0, cnt = 0;

    for(int idx = 0; idx < size; idx++){
        cin >> name >> charSize;
        for(int jdx = 0; jdx < charSize; jdx++){
            cin >> charac;
            animals[idx][jdx] = charac;
        }
        if (charSize > maxSize){
            maxSize = charSize;
            maxCharac = idx;
        }
    }

    // for(int idx = 0; idx < size; idx++){
    //     for(int jdx =0 ; jdx < 100; jdx++){
    //         if( !( animals[idx][jdx].size() ) ){
    //             break;
    //         }
    //         cout << animals[idx][jdx] << " ";
    //     }
    //     cout << '\n';
    // }

    for(int idx = 0; idx < maxSize; idx++){
        cnt = 0;
        for(int jdx = 0; jdx < size; jdx++){
            if(jdx == maxCharac){
                continue;
            }
            for(int kdx = 0; kdx < 100; kdx++){
                if(animals[jdx][kdx].size()){
                    if(!animals[jdx][kdx].compare(animals[maxCharac][idx])){
                        cnt++;
                        break;
                    }
                } else{
                    break;
                }
            }
        }
        if(cnt){
            totCnt++;
        }
    }

    cout << totCnt+1 << endl;

    return 0;
}