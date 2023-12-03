#include <iostream>
using namespace std;

void solv() {
    int hour = 23;
    int min = 50;

    int duration = 155;

    min = (min + duration) % 60; 
    hour  = (hour +  (min + duration) / 60)%24;

    cout << hour << " " << min << endl;

}

int main(){
    int hr;
    int min;
    int cooking_time;

    cin >> hr >> min >> cooking_time;

    int total_time = min;
    total_time += hr * 60;

    int final_time = total_time + cooking_time;
    final_time %= 24 * 60;

    int final_hr = final_time/60;
    int final_min = final_time%60;

    cout << final_hr << " " << final_min << endl;

    return 0;
}