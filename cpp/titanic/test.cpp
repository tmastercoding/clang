#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include <sstream>
using namespace std;

vector<string> split( string str, char separator ) {

    istringstream iss(str);
    string buffer;

    vector<string> result;

    while( getline( iss, buffer, separator ) ) {
        result.push_back( buffer );
    }

    return result;
}

int main() {

    ifstream file("./titanic.csv");
    string buffer;
    string head, body;
    int line_cnt = 0;

    while( getline( file, buffer ) )  {
        if( !line_cnt ) {
            head = buffer;
        } 
        // cout << buffer << endl;
        line_cnt++;
    }

    cout << "==== head ====" << endl;
    cout << head << endl;

    cout << "==== body ====" << endl;
    cout << body << endl;

    vector<string> result = split( head, ',' );

    for( int idx = 0; idx < result.size(); idx++ ) {
        cout << result[idx] << endl;
    }

    file.close();

    return 0;
}