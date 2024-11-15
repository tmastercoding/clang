#include <iostream>
#include <string>
#include <set>
#include <sstream>
using namespace std;

int main(){
    int length;
    int size;
    int x;
    int y;
    int power;
    int xStart;
    int xEnd;
    int yStart;
    int yEnd;

    cin >> length >> size;
    set<pair<int, int>> waterSpaces;

    for (int idx = 0; idx < size; idx++){
        cin >> x >> y >> power;
        
        xStart = x-power;
        if (xStart < 1){
            xStart = 1;
        }
        xEnd = x+power;
        if (xEnd > length){
            xEnd = length;
        }

        yStart = y-power;
        if (yStart < 1){
            yStart = 1;
        }
        yEnd = y+power;
        if (yEnd > length){
            yEnd = length;
        }
        
        for(int idx = xStart; idx < xEnd+1; idx++){
            pair<int, int> pos;
            pos.first = idx;
            pos.second = y;
            waterSpaces.insert(pos);
        }

        for(int idx = yStart; idx < yEnd+1; idx++){
            pair<int, int> pos;
            pos.first = x;
            pos.second = idx;
            waterSpaces.insert(pos);
        }
    }
    cout << length*length - waterSpaces.size() << endl;


    return 0;
}