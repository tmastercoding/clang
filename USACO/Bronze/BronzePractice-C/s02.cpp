// Blocked Billboard 15463
#include <iostream>
#include <string>
// #include <sstream>
#include <vector>
using namespace std;

int main(){
    vector<vector<int>> see;
    vector<int> board1;
    vector<int> board2;
    vector<int> truck;
    vector<int> row;
    string buffer;
    string temp;
    int visible = 0;
    int a, b, c, d;
    int minX = 1000, minY = 1000, maxX = -1000, maxY = -1000;

    // input
    cin >> a >> b >> c >> d;
    board1 = {a, b, c, d};
    if (minX > a) minX = a;
    if (minY > b) minY = b;
    if (maxX < c) maxX = c;
    if (maxY < d) maxY = d;

    cin >> a >> b >> c >> d;
    board2 = {a, b, c, d};
    if (minX > a) minX = a;
    if (minY > b) minY = b;
    if (maxX < c) maxX = c;
    if (maxY < d) maxY = d;
    
    cin >> a >> b >> c >> d;
    truck = {a, b, c, d};
    if (minX > a) minX = a;
    if (minY > b) minY = b;
    if (maxX < c) maxX = c;
    if (maxY < d) maxY = d;

    // cout << minX << ' '<< minY << ' ' << maxX << " " << maxY << endl;

    for(int x = minX; x <= maxX; x++){
        // cout << x << '\n';
        row.clear();
        for(int y = minY; y <= maxY; y++){
            // cout << y << ' ';
            if (((truck[0] <= x) && (x < truck[2])) && ((truck[1] <= y )&& (y < truck[3]))){
                row.push_back(0);
            } else if (((board1[0] <= x) && (x < board1[2])) && ((board1[1] <= y) && (y < board1[3]))){
                row.push_back(1);
            } else if (((board2[0] <= x) && (x < board2[2])) && ((board2[1] <= y) && (y < board2[3]))){
                row.push_back(1);
            } else{
                row.push_back(0);
            }
        }
        see.push_back(row);
        // cout << '\n';
    }

    auto print = []( const int &n ) { cout << n << ' '; };
    // cout << maxX-minX << endl;
    for(int idx = 0; idx <= (maxX-minX); idx++){
        for(int jdx = 0; jdx <= (maxY-minY); jdx++){
            if (see[idx][jdx] == 1 ){
                visible++;
            }
        }
    }
    cout << visible << '\n';
    // if (board1[0] < truck[1])
    return 0;
}