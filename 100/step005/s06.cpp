#include <iostream>
#include <vector>
using namespace std;

int isAllLower(char* str, int length){
    for(int idx = 0; idx < length; idx++){
        if(str[idx] < 'a' || str[idx] > 'z'){
            return 0;
        }
    }

    return 1;
}

int main(){
    const int size = 'z'-'a'+1;
    vector<int> v;
    const int buffer_size = 100;
    char buffer[buffer_size];
    
    cin.getline(buffer, buffer_size, '\n');

    // if buffer lowercase
    if(!isAllLower(buffer, strlen(buffer))){
        cout << "Please input only lowercase letters." << endl;
    } else{
        for(int idx = 0; idx < size; idx++){
            v.push_back(-1);
        }

        for(int idx = 0; idx < strlen(buffer); idx++){
            cout << buffer[idx] << endl;
            if(v.at(buffer[idx]-'a') == -1){
                v.at(buffer[idx]-'a') = idx;
            }
        }

        for(int i: v){
            cout << i << ' ';
        }
        cout << endl;
    }

    return 0;
}