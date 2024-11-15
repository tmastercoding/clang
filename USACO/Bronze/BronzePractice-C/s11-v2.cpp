// Out of Place 15594
#include <iostream>
#include <set>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    int size;
    cin >> size;
    int heights[size];
    int temp;
    int outIdx = 0, orgIdx = 0;
    int cnt = 0;
    set<int> types;
    vector<int> org;

    for(int idx =0 ; idx < size; idx++){
        cin >> temp;
        heights[idx] = temp;
        org.push_back(temp);
    }

    sort(org.begin(), org.end());

    for(int idx = 0; idx < size; idx++){

        if(heights[idx]!= org[idx]){
            outIdx = idx;
            break;
        }
    }    
    for(int idx = size-1; idx > -1; idx--){

        if(heights[idx]!= org[idx]){
            orgIdx = idx;
            break;
        }

    }    
    // orgIdx = org.end()-find(org.begin(), org.end(), heights[outIdx]);
    // cout << outIdx << ' ' << orgIdx << endl;

    if(outIdx == orgIdx){
        cout << 0 << '\n';
    } else{
        for(int idx = outIdx; idx <= orgIdx; idx++){
            types.insert(heights[idx]);
        }
        cout << types.size()-1 << '\n';
    }

    return 0;
}
