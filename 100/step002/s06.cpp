#include <iostream>
using namespace std;

// sol 1
void solv() {
    int hour = 23;
    int min = 50;

    int duration = 155;

    // min + duration and remainder when divided by 60
    min = (min + duration) % 60; 
    // similar thing with hour
    hour  = (hour +  (min + duration) / 60)%24;

    // output
    cout << hour << " " << min << endl;
}

// sol 2
int main(){
    // declare variables
    int hr;
    int min;
    int cooking_time;

    // get input
    cin >> hr >> min >> cooking_time;

    // total time
    int total_time = min;
    total_time += hr * 60;

    // add cooking time
    int final_time = total_time + cooking_time;
    // make final time within a day
    final_time %= 24 * 60;

    //  get final hr and min
    int final_hr = final_time/60;
    int final_min = final_time%60;

    // output
    cout << final_hr << " " << final_min << endl;

    return 0;
}