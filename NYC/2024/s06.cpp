#include <iostream>
#include <string>
#include <sstream>
#include <vector>

using namespace std;

vector<vector<int>> getComb(vector<int> numbers, int size, int curSize){
    vector<vector<int>> output;
    vector<int> temp;
    for (int idx = 0; idx < size-curSize+1; idx++){
        temp.clear();
        for(int jdx = idx; jdx < idx+curSize; jdx++){
            temp.push_back(numbers.at(jdx));
        }

        output.push_back(temp);
    }
    
    return output;
}

int main(){
    int size = 10;
    string str = "10 2 9 3 8 4 7 5 6 1";
    vector<int> numbers;
    vector<vector<int>> combinations;
    int curSize;
    bool isFound;
    int preOdd;
    int preEven;

    string buffer;
    
    getline(cin, buffer);
    size = stoi(buffer);
    getline(cin, str);
    
    istringstream iss(str);
    char sep = ' ';
    
    
    while(iss >> buffer){
        numbers.push_back(stoi(buffer));
    }

    curSize = size;
    
    // vector<vector<int>>::iterator iter;
    // vector<int>::iterator iter2;
    // combinations = getComb(numbers, size, curSize);
    // for(iter = combinations.begin(); iter!=combinations.end(); iter++){
    //     for(iter2 = (*iter).begin(); iter2!=(*iter).end(); iter2++){
    //         cout << (*iter2) << " ";    
    //     }
    //     cout << endl;
    // }

    while (curSize > 2){
        combinations = getComb(numbers, size, curSize);
        for(vector<int>comb: combinations){
            isFound = true;
            preOdd = comb.at(0);
            preEven = comb.at(1);
            // cout << preOdd << " " << preEven << endl;
            for (int idx = 2; idx < curSize; idx++){
                // cout << comb.at(idx) << endl;
                if((idx+1)&1){
                    if(preOdd > comb.at(idx)){
                        isFound = false;
                        break;
                    } else{
                        preOdd = comb.at(idx);
                    }
                } else{
                    if(preEven < comb.at(idx)){
                        isFound = false;
                        break;
                    } else{
                        preEven = comb.at(idx);
                    }
                }
            }
            // cout << "isFound " << isFound << endl;
            if (isFound){
                break;
            }
            
        }
        if (isFound){
            break;
        }
        curSize--;
    }

    cout << curSize << endl;

    return 0;
}

    