// The last battle 19747
#include <iostream>
#include <vector>
using namespace std;

int main(){
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    
    int size = 0;
    int temp;
    cin >> size;
    vector<int> people, martian;

    for(int idx = 0; idx < size; idx++){
        cin >> temp;
        martian.push_back(temp);
        people.push_back(idx+1);
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
        people.pop_back();
        people.insert(people.begin(), temp);
        cnt++;
    }
    if(cnt == size){
        cout << -1 << '\n';
    }

    return 0;
}   
