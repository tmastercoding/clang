#include <iostream>
using namespace std;

// solution 1
void get_time() {
    // subtracted time
    const int minutes = 45;

    int hour = 0;
    int min = 0;
    int diff = 0;
    // get hour and min
    cin >> hour >> min;

    // subtract
    diff = min - minutes;

    // if diff is negative
    if( diff < 0 ) {
        // subtract 1 hour
        hour--;
        //if hour is negative
        if( hour < 0) {
            // make hour 23
            hour = 23;
        }
    }

    // print hour
    cout << hour << endl;
    // print 60 - absolute value of diff
    cout << 60-abs(diff) << endl;
}

// sol 2
void solv_2() {
    // subtracted time
    const int minutes = 45;

    int hour = 0;
    int min = 10;
    int total_min = 0;

    // total number of mins
    total_min = hour * 60 + min-minutes;

    // if total min is negative, 23 hours
    hour = (total_min < 0)? 23: total_min%24;
    // if total min is negative, 60-absolute val of total_min
    min =  (total_min < 0)? 60 - abs( total_min ) : total_min%60;

    // output
    cout << hour << " " << min << endl;
}

// sol 3
int main(){
    // get input
    int hr, min;
    cin >> hr >> min;

    // total time in minutes
    int total_time = min;
    total_time += hr*60;

    // modified time
    int early_time = total_time - 45;

    // if neagtive
    if(early_time < 0){
        // add 24 hours
        early_time += 24 * 60;
    }   

    // get hour and min
    int early_hour = (int)(early_time/60);
    int early_min = early_time % 60;

    // output
    cout << early_hour << " " << early_min << endl;

    return 0;
}