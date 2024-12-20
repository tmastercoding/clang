#include <iostream>
using namespace std;

int main(){
    int n;
    cin >> n;
    for(int idx = 0; idx < n; idx++){

        string path;
        int y = 0, x = 0, minY = 1000, maxX = 0, maxDir;

        cin >> path; 
        for(char dir: path){
            if(dir == 'N'){
                y++;
            } else if(dir == 'E'){
                x++;
            } else if(dir == 'S'){
                y--;
            } else{
                x--;
            }
            if(maxX <= x && minY >= y){
                minY = y;
                maxX = x;
                maxDir = dir;
            }
        }
        // cout << maxX << " " << minY << '\n';

        if(maxDir == 'S' || maxDir == 'W'){
            cout << "CW\n";
        } else{
            cout << "CCW\n";
        }
    }
    return 0;
}