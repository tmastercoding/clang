#include <iostream>
using namespace std;

int main(){
    int size = 0;
    int length = 0;

    cin >> size;
    length = size*2-2;
    
    for(int row = length; row > -1; row--){
        for(int col = 0; col < length+1; col++){
            if (row - size+1 >col){
                cout << " ";
            } else if (length-row-size+1>col){
                cout << " ";
            } else if ((length+size > length-row+col) && (length+size > row+col)){
                cout << "*";
            }
        }
        cout << endl;
    }

    return 0;
}