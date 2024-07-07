#include <iostream>
#include <string>
#include <vector>
#include <sstream>
using namespace std;

/**
 * @date ??.??.??
 * @author Tay Oh
 * @details code explaining split
 *          using istringstream
*/

int main(){
    string text = "  a      Hello    world   )_)    ";
    
    string buffer;
    char sep = ' ';

    // create isstream of text
    istringstream iss(text);

    // create vector 
    vector<string> v;

    // while( getline( iss, buffer, sep ) ) {
    //     if( !buffer.empty() )
    //         v.push_back( buffer );
    // }

    // input to buffer
    while( iss >> buffer ) {
        if( !buffer.empty() )
            // add to vector
            v.push_back( buffer );
    }

    // output
    for( int idx = 0; idx < v.size(); idx++ ) {
        cout << v[idx] << endl;
    }

    cout << v.size() << endl;

    return 0;
}
