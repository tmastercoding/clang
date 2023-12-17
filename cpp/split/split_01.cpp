#include <iostream>
#include <string>
using namespace std;

int main() {

    // origin
    string str = "20 12 6 1";

    int size = str.length() + 1;
    char sep[] = " ";

    // copy
    // generate 
    char* cstr = new char[ size ];

    strcpy( cstr, str.c_str());

    // for( int idx = 0; idx < size; idx ++ ) {
    //     cout << cstr[idx] << endl;
    // }
 
    // char* p = strtok( cstr, sep );
    // int seperator_count = 0;

    // while( p != 0) {
    //     // cout << p << endl;
    //     p = strtok( NULL, sep );
    //     seperator_count++;
    // }

    // cout << seperator_count << endl;

    const int arrSize = 4;
    int* coinTypes = (int* )malloc( sizeof(int) * arrSize);

    char* p = strtok( cstr, sep);
    int idx = 0;

    while(p != 0){
        // cout << stoi(p) << endl;
        coinTypes[idx++] = stoi(p);
        p = strtok( NULL, sep );
    }
    
    for(int idx = 0; idx < arrSize; idx++){
        cout << coinTypes[idx] << endl;
    }

    return 0;
}