#include <iostream>
using namespace std;

int main() {
    // get input
    int height = 4;
    // cin >> height;

    // for triangle facing to the right:
    // loop for height
    for(int idx = 0; idx < height; idx++){
        // loop for idx (row number)
        for(int jdx = 0; jdx < idx+1; jdx++){
            cout << "* ";
        }
        cout << endl;
    }

    // for triangle facing to the left:
    // loop for height
    for(int idx = 0; idx < height; idx++){
        // loop for height-idx times
        for(int jdx = height; jdx > idx+1; jdx--){
            // blank spaces
            cout << "  ";
        }
        // fill the rest with *
        for(int jdx = 0; jdx < idx+1; jdx++){
            cout << "* ";
        }
        cout << endl;
    }

    // pyramid facing up
    // temp for col
    int temp = height*2-1;
    // loop for rows
    for(int idx = 0; idx < height; idx++){
        // loop for col (temp)
        for(int jdx = 0; jdx < (temp); jdx++){
            // if temp/2 - current row no. is <= than current col no.
            // AND temp/2 + current row no. is >= than current col no.
            if( (((int)(temp/2)-idx) <= jdx) && (((int)(temp/2)+idx) >= jdx)){
                cout << "* ";
            } else{
                cout << "  ";
            }
        }
        // go to next line
        cout << endl;
    }    
    cout << endl;

    // pyramid facing down
    // temp for col
    temp = height*2-1;

    // loop for row reverse
    for(int idx = height-1; idx > -1; idx--){
        // loop for col
        for(int jdx = 0; jdx < (temp); jdx++){
            // if temp/2 - current row no. is <= than current col no.
            // AND temp/2 + current row no. is >= than current col no.
            if( (((int)(temp/2)-idx) <= jdx) && (((int)(temp/2)+idx) >= jdx)){
                cout << "* ";
            } else{
                cout << "  ";
            }
        }
        cout << endl;
    }    
    return 0;
}