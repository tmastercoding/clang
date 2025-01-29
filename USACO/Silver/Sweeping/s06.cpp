// Lifeguards (Silver) 15589
#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

int main(){
    int n;
    vector<pair<long long, long long>> shifts;
    set<pair<long long, long long>> interval;
    long long start, end;
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> start >> end;
        shifts.push_back({start, end});
    }

    sort(shifts.begin(), shifts.end());
    for(int i = 0; i < n; i++){

    }

    return 0;
}