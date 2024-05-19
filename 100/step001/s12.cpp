#include <iostream>
using namespace std;

int main(){
    // extra cat
    string cat[] = {
        "\\    /\\ ",
        " )  ( ')", 
        "(  /  ) ",
        " \\(__)|" 
        };

    // string array for dog
    string dog[] = {
        "|\\_/|",
        "|q p|   /}", 
        "( 0 )\"\"\"\\",
        "|\"^\"`    |",
        "||_/=\\\\__|"
        };

    // loop array for each line
    for (int idx = 0; idx < 4; idx++){
        // print
        cout << cat[idx] << endl;
    }
    cout << endl;
    for (int idx = 0; idx < 5; idx++){
        cout << dog[idx] << endl;
    }
    return 0;
}