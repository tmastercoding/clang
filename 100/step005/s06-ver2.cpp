#include <iostream>
#include <string>
using namespace std;

int main() {
    string buffer = "";

    size_t findit = 0;

    getline( cin, buffer );
    // cin.ignore();

    cout << buffer << endl;

    for( char ch = 'a'; ch < 'z'+1; ch++ ) {
        findit = buffer.find( ch );
        if( findit != string::npos ) {
            cout << findit << ' ';

        } else {
            cout << -1 << ' ';
        }
    }
    cout << endl;

    return 0;
}