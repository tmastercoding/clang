#include <iostream>
#include <string>
#include <sstream>
#include <vector>

using namespace std;

int main(){
    int size = 10;
    string str = "10 2 9 3 8 4 7 5 6 1";
    vector<int> numbers;
    int curSize;
    int maxSize;
    bool isFound;
    int preOdd;
    int preEven;

    string buffer;
    
    // getline(cin, buffer);
    // size = stoi(buffer);
    // getline(cin, str);
    
    istringstream iss(str);
    char sep = ' ';
    
    while(iss >> buffer){
        numbers.push_back(stoi(buffer));
    }

    
    maxSize = 0;
    for(int start = 0; start < size; start++){
        curSize = 0;
        // cout << "start: " << start << endl;
        for(int idx = start; idx < size; idx+=2){
            // cout << idx << " " << numbers.at(idx) << endl;
            // odd
            if((idx != start) && (preOdd > numbers.at(idx))){
                break;
            } 
            preOdd = numbers.at(idx);
            curSize++;

            // even
            if((idx+1) != size){
                // cout << idx+1 << " " << numbers.at(idx+1) << endl;
                if((idx != start) && (preEven < numbers.at(idx+1))){
                    break;
                } 
                preEven = numbers.at(idx+1);
                curSize++;
            }
        }
        // cout << curSize << " " << maxSize << endl;
        if(curSize > maxSize){
            maxSize = curSize;
        }
        if (maxSize > size/2){
            break;
        }
    }

    cout << maxSize << endl;

    return 0;
}

    