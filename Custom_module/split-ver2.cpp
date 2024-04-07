#include <iostream>
#include <string>
#include <vector>
#include <sstream>
using namespace std;

int main(){
    string text = "  a      Hello    world   )_)    ";
    
    string buffer;
    char sep = ' ';

    istringstream iss(text);

    vector<string> v;

    // while( getline( iss, buffer, sep ) ) {
    //     if( !buffer.empty() )
    //         v.push_back( buffer );
    // }

    while( iss >> buffer ) {
        if( !buffer.empty() )
            v.push_back( buffer );
    }

    for( int idx = 0; idx < v.size(); idx++ ) {
        cout << v[idx] << endl;
    }

    cout << v.size() << endl;

    return 0;
}
