#include <iostream>
#include <string>
using namespace std;

// switch
void ex00(){
    int day = 4;
    string output_str;
    // switch(variable){}
    switch(day) {
        // case number (if variable is this number)
        case 1:
            output_str = "Monday";
            // always break the case
            break;
        case 2:
            output_str = "Tuesday";
            break;
        case 3:
            output_str = "Wednesday";
            break;
        case 4:
            output_str = "Thursday";
            break;
        case 5:
            output_str = "Friday";
            break;
        case 6:
            output_str = "Saturday";
            break;
        case 7:
            output_str = "Sunday";
            break; 
        // if variable is none of the cases above
        // do:
        default:
            output_str = "Looking forward to the Weekend! I HATE MONDAYS";
    }
    // print outpur string
    cout << output_str << endl;
}

int main(){
    // switch
    ex00();

    return 0;
}