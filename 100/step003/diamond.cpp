#include <iostream>
using namespace std;
//     *     2
//   * * *   1
// * * * * * 0
//   * * *   1
//     *     2

void solv() {
    int size = 5;
    int col_size;
    // int rate = 0;
    int point;

    scanf( "%d", &size );
    col_size = size * 2 - 1;

    for( int row = size-1, rate = 0; row > -1 ; row--, rate++  )   {
        
        point = ( rate > size / 2 ) ? rate : row;

        for( int col = 0; col < col_size ; col++ )   {
            
            if( ( point > col ) || ( ( col_size - point - 1 ) < col ) )    {
                cout << "  " ;
            } else {
                cout << "* " ;
            }
        }
        cout << "\n" ;
    }

}

int main(){
    int height = 5;
    int row = 0;
    int col = 0;

    int gap = height/2;
    cout << gap << endl;

    for( ; row < height; row++){
        // cout << "gap: " << gap << endl;
        // cout << gap << endl;
        for(col = 0; col < height; col++){
            // cout << "col: " << col << endl;

            if( ( gap <= col) && (col <= (height-gap-1))){
                cout << "* ";
            } else{
                cout << "--";
            }
        }
        cout << endl;
         if((row >= height/2)){
            gap++;
        } else{
            gap--;
        }
    }
    
    return 0;
}