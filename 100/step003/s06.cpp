#include <iostream>
using namespace std;

int main() {
    int height = 4;
    // cin >> height;

    for(int idx = 0; idx < height; idx++){
        for(int jdx = 0; jdx < idx+1; jdx++){
            cout << "* ";
        }
        cout << endl;
    }

    for(int idx = 0; idx < height; idx++){
        for(int jdx = height; jdx > idx+1; jdx--){
            cout << "  ";
        }
        for(int jdx = 0; jdx < idx+1; jdx++){
            cout << "* ";
        }
        cout << endl;
    }

    int temp = height*2-1;
    
    for(int idx = 0; idx < height; idx++){
        for(int jdx = 0; jdx < (temp); jdx++){
            if( (((int)(temp/2)-idx) <= jdx) && (((int)(temp/2)+idx) >= jdx)){
                cout << "* ";
            } else{
                cout << "  ";
            }
        }
        cout << endl;
    }    
    cout << endl;

    temp = height*2-1;

    for(int idx = height-1; idx > -1; idx--){
        for(int jdx = 0; jdx < (temp); jdx++){
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