#include <iostream>
#include <algorithm>
#include <set>
using namespace std;

int main(){
    int size;
    cin >> size;
    
    long long int tuition[100000];
    int freq[1000000] = {0};
    set<long long int> costs;

    for(int idx = 0; idx < size; idx++){
        cin >> tuition[idx];
        costs.insert(tuition[idx]);
    }  

    sort(tuition, tuition+size);
    long long int temp = 0;
    for(int idx = size-1; idx > -1; idx--){
        temp++;
        freq[tuition[idx]] = temp;
    }
    // for(int idx = 0; idx < 10; idx++){
    //     cout << freq[idx] << '\n';
    // }

    long long int maxCost = 0, maxPer = 0;
    for(long long int cur: costs){
        temp = freq[cur] * cur;
        // for(int idx = 0; idx < size; idx++){
        //     if(cur <= tuition[idx]){
        //         temp+= cur;
        //     }
        // }
        
        if(temp > maxCost){
            maxCost = temp;
            maxPer = cur;
        }
    }
    cout << maxCost << ' ' << maxPer << '\n';
    return 0;
}