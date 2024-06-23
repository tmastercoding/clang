#include <iostream>
#include <string>
using namespace std;

int main(){
    int size = 0;
    string buffer;
    string binary; 
    int num = 0;
    int count = 0;

    // input
    getline(cin, buffer);
    size = stoi(buffer);
    getline(cin, buffer);
    binary.assign(buffer);

    // string to binary
    num = stoi(binary, nullptr, 2);
    
    while(true){
        // if num is odd or binary does not end with 00
        if( ( (num & 1) == 1 ) || ((num & 3) != 0)){
            // pre calculation
            num = (num + 1) % (1 << size);
        } else{
            // post calculation
            num = (num << 1) % (1 << size);
        }

        count++;
        // if num is 0
        if(!num){
            break;
        }
    }

    // output   
    cout << count << endl;

    return 0;
}