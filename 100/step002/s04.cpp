#include <iostream>
using namespace std;

// checks if positive
int isPos(int number){
    // returns 1 if positive
    return (number > 0) ? 1: 0;
}

// int isNeg(int number){
//     return (number < 0) ? 1: 0;
// }

// returns quadrant string
string print_quadrant2( int x, int y ) {
    // tenary returning quadrant
    return  ( x > 0 && y > 0 )? "Quadrant 1" :
            ( x < 0 && y > 0 )? "Quadrant 2" :
            ( x < 0 && y < 0 )? "Quadrant 3" : "Quadrant 4";
}

// printing quadrant using if
void print_quadrant() {
    int x, y;

    // get input
    cin >> x >> y;

    // if statement for quadrant
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
    // get input
    int x, y;
    cin >> x >> y;

    // checks if pos    
    int x_state = isPos(x);
    int y_state = isPos(y);

    // if statement using states
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