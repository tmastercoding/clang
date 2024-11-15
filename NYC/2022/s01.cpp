#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <algorithm> 
using namespace std;

int main(){
    int size = 7;
    string buffer;
    string temp;
    vector<int> numbers;
    vector<int> v;
    int cnt;
    int maxCnt = 0;

    getline(cin, buffer);
    size = stoi(buffer);

    getline(cin, buffer);
    istringstream iss(buffer);

    while(iss >> temp){
        numbers.push_back(stoi(temp));
    }

    // auto print = []( const int &n ) { cout << n << ' '; };
    // for_each(numbers.begin(), numbers.end(), print);

    for(int start = 0; start < size; start++){
        cnt = 0;
        v.clear();
        if(start+maxCnt > size){
            break;
        }
        // cout << start << endl;
        for(int idx = start; idx < size; idx++){
            // cout << numbers.at(idx) << " ";
            if(!count(v.begin(), v.end(), numbers.at(idx))){
                v.push_back(numbers.at(idx));
            } else{
                break;
            }
            cnt++;
        }
        // cout << endl;
        // for_each(v.begin(), v.end(), print);
        // cout << cnt << endl;
        if(cnt > maxCnt){
            maxCnt = cnt;
        }
    }

    cout << maxCnt << endl;
    return 0;
}