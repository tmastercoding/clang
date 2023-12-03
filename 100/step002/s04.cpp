#include <iostream>
using namespace std;

int isPos(int number){
    return (number > 0) ? 1: 0;
}

// int isNeg(int number){
//     return (number < 0) ? 1: 0;
// }

string print_quadrant2( int x, int y ) {
    return  ( x > 0 && y > 0 )? "Quadrant 1" :
            ( x < 0 && y > 0 )? "Quadrant 2" :
            ( x < 0 && y < 0 )? "Quadrant 3" : "Quadrant 4";
}
void print_quadrant() {
    int x, y;

    cin >> x >> y;

    if( x > 0 && y > 0 ) {
        cout << "Quadrant 1" << endl;

    } else if( x < 0 && y >> 0 ) {

        cout << "Quadrant 2" << endl;
    } else if( x < 0 && y < 0 ) {

        cout << "Quadrant 3" << endl;

    } else {
        cout << "Quadrant 4" << endl;
    }
}

int main(){
    int x, y;
    cin >> x >> y;
    
    int x_state = isPos(x);
    int y_state = isPos(y);

    if( x_state && y_state){
        cout << '1';
    } else if(!(x_state) && y_state){
        cout << '2';
    } else if(!(x_state) && !(y_state)){
        cout << '3';
    } else {
        cout << '4';
    }

    cout << endl;

    return 0;
}