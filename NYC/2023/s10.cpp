#include <iostream>
#include <string>
#include <sstream>
#include <vector>
using namespace std;

bool isSort(vector<pair<int, int>> numbers){
    vector<pair<int, int>>::iterator iter;
    iter = numbers.begin();
    int prevY = (*iter).second;
    iter++;

    for(; iter != numbers.end(); iter++){
        if (prevY > (*iter).second){
            return false;
        }
        prevY = (*iter).second;
    }
    return true;
}

bool compareInterval(pair<int, int> i1, pair<int, int> i2){ 
    return (i1.first < i2.first); 
} 

int main(){
    int size = 5;
    string temp;
    string buffer;
    pair<int, int> inputPair;
    vector<pair<int, int>> numbers;
    vector<pair<int, int>>::iterator iter;
    int store = 0;
    int cnt = 0;
    bool flag = false;
    int prevY = 0;

    getline(cin, buffer);
    size = stoi(buffer);
    for(int idx = 0; idx < size; idx++){
        getline(cin, buffer);
        istringstream iss(buffer);
        iss >> temp;
        inputPair.first = stoi(temp);
        iss >> temp;
        inputPair.second = stoi(temp);
        numbers.push_back(inputPair);
    }

    while (true){
        if(isSort(numbers)){
            break;
        }
        iter = numbers.begin();
        prevY = (*iter).second;
        iter++;
        for(; iter!= numbers.end(); iter++){
            // cout << (*iter).first << " " << (*iter).second << endl;
            if(prevY > (*iter).second){
                for(int idx = 1; idx < size; idx++){
                    cout << numbers.at(idx-1).second << " " << (*iter).second << endl;
                    if( numbers.at(idx-1).second < (*iter).second){
                        store = numbers.at(idx-1).first;
                        numbers.at(idx-1).first = (*iter).first;
                        (*iter).first = store;
                        cnt++;
                        sort(numbers.begin(), numbers.end(), compareInterval);
                        // flag =8 true;
                        break;
                    }
                }
            }
            if(flag){
                break;
            }
            prevY = (*iter).second;
        }
    }

    cout << cnt << endl;
     
    // for(iter = numbers.begin(); iter != numbers.end(); iter++){
    //     cout << (*iter).first <<  " " << (*iter).second << endl;
    // }
    return 0;
}