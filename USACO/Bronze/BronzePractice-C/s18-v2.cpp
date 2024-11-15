// The last battle 19747
#include <iostream>
using namespace std;

int main(){
    int size = 0;
    int temp;
    cin >> size;
    int people[size];
    int martian[size];

    for(int idx = 0; idx < size; idx++){
        cin >> martian[idx];
        people[idx] = idx+1;
    }

    bool lose = false;
    int cnt = 0;

    for(int idx = 0; idx < size; idx++){
        lose = false;
        for(int jdx = 0; jdx < size; jdx++){
            if(martian[jdx] == people[jdx]){
                lose = true;
                break;
            }
        }
        if(!lose){
            cout << cnt << '\n';
            break;
        } 
        temp = people[size-1];
        for(int idx = size-2; idx > -1; idx--){
            people[idx+1] = people[idx];
        }
        people[0] = temp;
        cnt++;
    }
    if(cnt == size){
        cout << -1 << '\n';
    }

    return 0;
}   
