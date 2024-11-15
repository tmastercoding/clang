#include <iostream>
#include <string>
#include <sstream>
#include <algorithm>
#include <vector>
using namespace std;

int main(){
    int size = 0;
    int sum = 0;
    string buffer;
    string temp;
    vector<int> v;
    vector<int> want;
    vector<int> pos;
    vector<int>::iterator iter;
    vector<int>::iterator fIter;

    getline(cin, buffer);
    size = stoi(buffer);
    getline(cin, buffer);
    istringstream iss(buffer);
    while(iss >> temp){
        v.push_back(stoi(temp));
    }

    for(int idx = 1; idx < size+1; idx++){
        want.push_back(idx);
        pos.push_back(idx);
    }

    // for(iter = pos.begin(); iter!= pos.end(); iter++){
    //     cout << *iter << endl;
    // }

    // cout << size << endl;
    for(iter = v.end()-1; iter!=v.begin()-1; iter--){
        // cout << iter-v.begin() << endl;
        // cout << find(want.begin(), want.end(), *iter) - want.begin() << endl;
        
        fIter = find(want.begin(), want.end(), *iter);
        // cout << *fIter << " ";
        if(fIter != want.end()){
            *fIter = 0;
            fIter = find(pos.begin(), pos.end(), *iter);
            *fIter = 0;
        }
        // cout << *fIter << endl;
    }

    for(iter = pos.begin(); iter != pos.end(); iter++){
        // cout << *iter << endl;
        sum += (*iter);
    }
    cout << sum << endl;
    

    return 0;
}