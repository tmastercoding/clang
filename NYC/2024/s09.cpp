#include <iostream>
#include <string>
#include <sstream>
#include <vector>
using namespace std;

int main(){
    int size;
    string buffer;
    string temp;
    int rangeSize;
    vector<int> numbers;
    vector<pair<int, int>> ranges;
    pair<int, int> range;
    
    getline(cin, buffer);
    size = stoi(buffer);
    getline(cin, buffer);
    

    istringstream iss(buffer);
    while(iss >> temp){
        numbers.push_back(stoi(temp));
    }
    getline(cin, buffer);
    rangeSize = stoi(buffer);

    for(int idx = 0; idx < rangeSize; idx++){
        getline(cin, buffer);
        istringstream iss(buffer);
        iss >> temp;
        range.first = stoi(temp);
        iss >> temp;
        range.second = stoi(temp);
        ranges.push_back(range);
    }

    // for(int num: numbers){
    //     cout << num << endl;
    // }

    for(pair<int, int> temp: ranges){
        int found = 0;
        for(int idx = temp.first-1; idx < temp.second; idx++){
            if (count(numbers.begin()+temp.first-1, numbers.end()+temp.second, numbers.at(idx)) == 1){
                found = numbers.at(idx);
                break;
            }
        }
        cout << found << endl;
    }


    return 0;
}