// Hungry Cow
#include <iostream>
using namespace std;

int main(){
    int n;
    long long int t;
    cin >> n >> t;

    long long int day = 0, bales = 0, eaten = 0, prevDay = 0, prevBales = 0;

    for(int idx = 0; idx < n; idx++){
        cin >> day >> bales;
        if(idx > 0){
            if((day-prevDay) > prevBales){
                eaten += prevBales;
                prevBales = 0;
            } else{
                eaten += day-prevDay;
                prevBales -= day-prevDay;
            }
        }
        prevDay = day;
        prevBales += bales;
    }

    if((t-prevDay)+1 > prevBales){
        eaten += prevBales;
    } else{
        eaten += t-prevDay +1;
        prevBales -= t-prevDay+1;
    }

    cout << eaten << '\n';
    return 0;
}