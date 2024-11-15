#include <iostream>
#include <string>
#include <sstream>
using namespace std;

int main(){
    int size = 0;
    string text;
    string buffer;
    int* arr;
    int* logList;
    int idx = 0;
    int tot = 0;

    // get input
    getline(cin, buffer);
    size = stoi(buffer);

    // malloc arr
    arr = (int*)malloc(sizeof(int) * size);    
    logList = (int*)malloc(sizeof(int) * size);    

    // input
    getline(cin, text);
    istringstream iss(text);

    // add val
    while(iss >> buffer){
        logList[idx] = 0;
        arr[idx++] = stoi(buffer);
    }

    // change logList
    for(int idx = 0; idx < size; idx++){
        if (arr[idx] <= size){
            logList[arr[idx]-1] = -1;
        }
    }

    // for(int idx = 0; idx < size; idx++){
    //     cout << logList[idx] << endl;
    // }

    for(int idx = 0; idx < size; idx++){
        if (logList[idx] == 0){
            tot += idx+1;
        }
    }

    cout << tot << endl;
    return 0;
}


// for num in arr:
//     if num <= size:
//         logList[num-1] = -1

// tot = 0
// for idx, num in enumerate(logList):
//     if num == 0:
//         tot += (idx+1)

// print( f'tot : {tot}')