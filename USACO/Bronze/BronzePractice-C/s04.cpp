// Milk Measurement 15465
#include <iostream>
#include <cstdio>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    freopen("measurement.in", "r", stdin);
	freopen("measurement.out", "w", stdout);
    int size = 0;
    vector<vector<int>> entries;
    vector<int> entry;
    int day, change;
    int cnt = 0;
    string name;

    int m = 7, e = 7, b= 7;
    int maxMilk = 7;
    string most = "mbe";
    string comp;

    cin >> size;
    for(int idx = 0; idx < size; idx++){
        entry.clear();
        cin >> day >> name >> change;
        entry.push_back(day);
        entry.push_back(name[0]);
        entry.push_back(change);
        entries.push_back(entry);
    }

    sort(entries.begin(), entries.end());
    for(int idx = 0; idx < size; idx++){
        // cout << entries[idx][0] << '\n';
        if(entries[idx][1] == 'M'){
            m += entries[idx][2];
        } else if (entries[idx][1] == 'B'){
            b += entries[idx][2];
        } else{
            e += entries[idx][2];
        }

        // cout << m << ' ' << '\n';
        maxMilk = max(m, max(b, e));
        // cout << maxMilk << '\n';
        comp = "";
        if(m == maxMilk){
            comp += "m";
        }
        if(b == maxMilk){
            comp += "b";
        }
        if(e == maxMilk){
            comp += "e";
        }
        // cout << comp << ' ' << most << '\n';
        if (comp != most){
            cnt += 1;
            most = comp;
        }
    }

    cout << cnt << endl;
    return 0;
}