#include <iostream>
using namespace std;

void get_time() {
    const int minutes = 45;

    int hour = 0;
    int min = 10;
    int diff = 0;
    cin >> hour >> min;

    diff = min - minutes;

    if( diff < 0 ) {
        hour--;
        if( hour < 0) {
            hour = 23;
        }
    }

    cout << hour << endl;
    cout << 60-abs(diff) << endl;
}

void solv_2() {
    const int minutes = 45;

    int hour = 0;
    int min = 10;
    int total_min = 0;

    total_min = hour * 60 + min-minutes;

    hour = (total_min < 0)? 23: total_min%24;
    min =  (total_min < 0)? 60 - abs( total_min ) : total_min%60;

    cout << hour << " " << min << endl;
    
}

int main(){
    int hr, min;
    cin >> hr >> min;

    int total_time = min;
    total_time += hr*60;

    int early_time = total_time - 45;

    if(early_time < 0){
        early_time += 24 * 60;
    }

    int early_hour = (int)(early_time/60);
    int early_min = early_time % 60;

    cout << early_hour << " " << early_min << endl;

    return 0;
}