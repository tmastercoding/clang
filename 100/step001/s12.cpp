#include <iostream>
using namespace std;

int main(){

    string cat[] = {
        "\\    /\\ ",
        " )  ( ')", 
        "(  /  ) ",
        " \\(__)|" 
        };

    string dog[] = {
        "|\\_/|",
        "|q p|   /}", 
        "( 0 )\"\"\"\\",
        "|\"^\"`    |",
        "||_/=\\\\__|"
        };

    for (int idx = 0; idx < 4; idx++){
        cout << cat[idx] << endl;
    }
    cout << endl;
    for (int idx = 0; idx < 5; idx++){
        cout << dog[idx] << endl;
    }
    return 0;
}