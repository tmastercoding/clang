#include <iostream>
#include <string>
using namespace std;

int isPalin(string text){
    for(int idx = 0; idx < (int)(text.size()/2); idx++){
        if(text[text.size()-idx-1] != text[idx]){
            return false;
        }
    }
    return true;
}

int main(){
    int case_size;
    cin >> case_size;
    int size;
    string temp;
    bool isFound = false;
    string words[case_size][100];
    
    for(int idx = 0; idx < case_size; idx++){
        cin >> size;
        for(int jdx = 0; jdx < size; jdx++){
            cin >> temp;
            words[idx][jdx] = temp;
        }
    }

    for(int idx = 0; idx < case_size; idx++){
        isFound = false;
        for(int jdx = 0; jdx < 100; jdx++){
            if((words[idx][jdx]).empty()){
                break;
            }
            if(isFound){
                break;
            }
            for(int kdx = 0; kdx < 100; kdx++){
                if(jdx == kdx){
                    continue;
                }
                if((words[idx][kdx]).empty()){
                    break;
                }
                temp = words[idx][jdx]+words[idx][kdx];
                // cout << temp << " " << isPalin(temp) << endl;
                if(isPalin(temp)){
                    cout << temp << '\n';
                    isFound = true;
                    break;
                } 
            }
        }
        if(!isFound){
            cout << 0 << '\n';
        }
    }
    return 0;
}